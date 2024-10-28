/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: Dev Audsin <dev.audsin@bbc.co.uk>
 *          David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_AGGREGATION_FUNCTION_H
#define DATA_COLLECTION_AGGREGATION_FUNCTION_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif


#include <stdint.h>

#include "sbi/openapi/external/cJSON.h"

#include "ogs-core.h"

/** \addtogroup dcsp
 * @{
 */


#ifdef __cplusplus
#ifndef OGS_CORE_INSIDE
#define OGS_CORE_INSIDE
#endif
#ifndef OGS_USE_TALLOC
#define OGS_USE_TALLOC 1
#endif
#include "ogs-list.h"

extern "C" {
#else
#include "ogs-core.h"
#endif

/***** Enumerations *****/

/** \enum data_collection_aggregate_result_type_e 
 * \brief Data Collection library Aggregation Functions return type
 * \headerfile aggregation-function.h <data-collection-sp/data-collection.h>
 *
 * Set in data_collection_aggregate_result_t by the aggregation functions (e.g. data_collection_aggregation_function_int64()) when returning the result.
 */

typedef enum {
    DATA_COLLECTION_AGGREGATE_RESULT_ARRAY, /**< Result returned by the Aggregation Function (e.g. none) is an array. */
    DATA_COLLECTION_AGGREGATE_RESULT_SIZE, /**< Result returned by the Aggregation Function (e.g. count) is size. */
    DATA_COLLECTION_AGGREGATE_RESULT_VALUE, /**< Result returned by the Aggregation Function (e.g. min, max, sum) is a value. */
    DATA_COLLECTION_AGGREGATE_RESULT_DOUBLE /**< Result returned by the Aggregation Function (e.g. mean) is a double. */
} data_collection_aggregate_result_type_e;

/** Result returned by Aggregation functions
 *
 * The OpenAPI 3.0 specification has 3 integer (integer, int32 and int64) and 3 floating point (number, float, double) numeric data types.
 * The library treats "integer" as an alias for "int64" and "number" as an alias for "double".
 * The Aggregation functions (data_collection_aggregation_function_*()) populate this data structure to provide the calculated value(s) to the AF.
 * An AF can use this to extract and use the value(s).
 */

typedef struct data_collection_aggregate_result_s {
    data_collection_aggregate_result_type_e result_type; /**< Result type as in enum data_collection_aggregate_result_type_e */
    union {
        int32_t int32; /**< Stores the value of the aggregation function result for the type int32_t */
        int64_t int64; /**< Stores the value of the aggregation function result for the type int64_t */
        float floating_pt; /**< Stores the value of the aggregation function result for the type float */
        double double_prec; /**< Stores the value of the aggregation function result for the type double */
        struct {
            union {
                int32_t *int32_array; /**< Array pointer returned by the aggregation function for the type int32_t */
                int64_t *int64_array; /**< Array pointer returned by the aggregation function for the type int64_t */
                float *float_array; /**< Array pointer returned by the aggregation function for the type float */
                double *double_array; /**< Array pointer returned by the aggregation function for the type double */
                void *array; /**< Array pointer returned by the aggregation function for the type float */
            };
            size_t array_len; /**< Size of the returned array */
        };
        size_t size; /**< Size of the aggregration result */
    };
} data_collection_aggregate_result_t;

/*! 
   \brief Sets the result field for integer \a result.
   \param result aggregated result object.
   \returns Aggregated result object with the aggregated value set on the field int64 \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INTEGER(result) ((result).int64)

/*! 
   \brief Sets the result field for int32 \a result.
   \param result aggregated result object.
   \returns Aggregated result object with the aggregated value set on the field int32 \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT32(result) ((result).int32)

/*!
   \brief Sets the result field for int64 \a result.
   \param result aggregated result object.
   \returns Aggregated result object with the aggregated value set on the field int64 \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT64(result) ((result).int64)

/*! 
   \brief Sets the result field for number \a result.
   \param result aggregated result object.
   \returns Aggregated result object with the aggregated value set on the field double_prec \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_NUMBER(result) ((result).double_prec)

/*!
   \brief Sets the result field for float data type \a result.
   \param result aggregated result object.
   \returns Aggregated result object with the aggregated value set on the field floating_pt \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_FLOAT(result) ((result).floating_pt)

/*!
   \brief Sets the result field for double data type \a result.
   \param result aggregated result object.
   \returns Aggregated result object with the aggregated value set on the field double_prec \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(result) ((result).double_prec)

/*!
   \brief Sets the result field for array pointer \a result.
   \param result aggregated result object.
   \returns Aggregated result object with array pointer \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_ARRAY_PTR(result) ((result).array)

/*!
   \brief Sets the array size in the result object \a result.
   \param result aggregated result object.
   \returns Aggregated result object with size set on the field array_len \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Sets the result field for integer \a result.
   \param result aggregated result object.
   \returns Aggregated result object with array pointer set on the field int64_array \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INTEGER_ARRAY_PTR(result) ((result).int64_array)

/*!
   \brief Sets the result field for float data type \a result.
   \param result aggregated result object.
   \returns Aggregated result object with size set on the field array_len \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INTEGER_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Sets the result field for int32 \a result.
   \param result aggregated result object.
   \returns Aggregated result object with array pointer set on the field int32_array \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT32_ARRAY_PTR(result) ((result).int32_array)

/*!
   \brief Sets the array size for int32 \a result.
   \param result aggregated result object.
   \returns Aggregated result object with size set on the field array_len \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT32_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Sets int64 array pointer  \a result.
   \param result aggregated result object.
   \returns Aggregated result object with array pointer to the field int64_array \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_PTR(result) ((result).int64_array)

/*!
   \brief Sets the size of int64 array \a result.
   \param result aggregated result object.
   \returns Aggregated result object with size set on the field array_len \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Sets array pointer for number  \a result.
   \param result aggregated result object.
   \returns Aggregated result object with array pointer to the field double_array \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_NUMBER_ARRAY_PTR(result) ((result).double_array)

/*!
   \brief Sets the size of number array \a result.
   \param result aggregated result object.
   \returns Aggregated result object with size set on the field array_len \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_NUMBER_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Sets array pointer for float  \a result.
   \param result aggregated result object.
   \returns Aggregated result object with array pointer to the field float_array \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_FLOAT_ARRAY_PTR(result) ((result).float_array)

/*!
   \brief Sets the size of float array \a result.
   \param result aggregated result object.
   \returns Aggregated result object with size set on the field array_len \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_FLOAT_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Sets array pointer for double  \a result.
   \param result aggregated result object.
   \returns Aggregated result object with array pointer to the field double_array \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE_ARRAY_PTR(result) ((result).double_array)

/*!
   \brief Sets the size of double array \a result.
   \param result aggregated result object.
   \returns Aggregated result object with size set on the field array_len \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Sets the size of the result \a result.
   \param result aggregated result object.
   \returns Aggregated result object with size set on the field size \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_SIZE(result) ((result).size)

/*!
   \brief Sets the size of the result \a result.
   \param result aggregated result object.
   \returns Aggregated result object with result_type set to types defined in enum data_collection_aggregate_result_type_e \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_TYPE(result) ((result).result_type)

/*!
   \brief Checks if a result type is value. \a result.
   \param result aggregated result object.
   \returns Returns "true" if the result type is value, "false" otherwise. \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_VALUE(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_VALUE)

/*!
   \brief Checks if a result type is size. \a result.
   \param result aggregated result object.
   \returns Returns "true" if the result type is size, "false" otherwise. \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_SIZE(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_SIZE)

/*!
   \brief Checks if a result type is array. \a result.
   \param result aggregated result object.
   \returns Returns "true" if the result type is array, "false" otherwise. \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_ARRAY(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_ARRAY)

/*!
   \brief Checks if a result type is double. \a result.
   \param result aggregated result object.
   \returns Returns "true" if the result type is double, "false" otherwise. \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_DOUBLE(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_DOUBLE)

/**
 * Performs the aggregation function on the input of type int32_t
 *
 * @param fn_name The aggregation function that needs to be calculated (e.g NONE, COUNT, MEAN, MIN, MAX, SUM).
 * @param input_array Values to which the aggregation function is applied.
 * @param input_len Size of the input array.
 *
 * @return An aggregation result object with appropriate fields populated according to the specified aggregation function.
 */


DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_int32(const char *fn_name, int32_t *input_array, size_t input_len);

/**
 * Performs the aggregation function on the input of type int64_t
 *
 * @param fn_name The aggregation function that needs to be calculated (e.g NONE, COUNT, MEAN, MIN, MAX, SUM).
 * @param input_array Values to which the aggregation function is applied.
 * @param input_len Size of the input array.
 *
 * @return An aggregation result object with appropriate fields populated according to the specified aggregation function.
 */

DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_int64(const char *fn_name, int64_t *input_array, size_t input_len);

/**
 * Performs the aggregation function for integer
 *
 * @param fn_name The aggregation function that needs to be calculated (e.g NONE, COUNT, MEAN, MIN, MAX, SUM).
 * @param input_array Values to which the aggregation function is applied.
 * @param input_len Size of the input array.
 *
 * @return An aggregation result object with appropriate fields populated according to the specified aggregation function.
 */
#define data_collection_aggregation_function_integer(fn_name, input_array, input_len) data_collection_aggregation_function_int64(fn_name, input_array, input_len)

/**
 * Performs the aggregation function on the input of type float
 *
 * @param fn_name The aggregation function that needs to be calculated (e.g NONE, COUNT, MEAN, MIN, MAX, SUM).
 * @param input_array Values to which the aggregation function is applied.
 * @param input_len Size of the input array.
 *
 * @return An aggregation result object with appropriate fields populated according to the specified aggregation function.
 */

DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_float(const char *fn_name, float *input_array, size_t input_len);

/**
 * Performs the aggregation function on the input of type double
 *
 * @param fn_name The aggregation function that needs to be calculated (e.g NONE, COUNT, MEAN, MIN, MAX, SUM).
 * @param input_array Values to which the aggregation function is applied.
 * @param input_len Size of the input array.
 *
 * @return An aggregation result object with appropriate fields populated according to the specified aggregation function.
 */


DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_double(const char *fn_name, double *input_array, size_t input_len);

/**
 * Performs the aggregation function for number data type
 *
 * @param fn_name The aggregation function that needs to be calculated (e.g NONE, COUNT, MEAN, MIN, MAX, SUM).
 * @param input_array Values to which the aggregation function is applied.
 * @param input_len Size of the input array.
 *
 * @return An aggregation result object with appropriate fields populated according to the specified aggregation function.
 */

#define data_collection_aggregation_function_number(fn_name, input_array, input_len) data_collection_aggregation_function_double(fn_name, input_array, input_len)

/**
 * Delete the Data Collection Aggregation result 
 *
 * @param result The aggregation result object that needs to be deleted.
 */

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_aggregation_function_result_free(data_collection_aggregate_result_t *result);	

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_AGGREGATION_FUNCTION_H */
