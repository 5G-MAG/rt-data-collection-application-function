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
extern "C" {
#endif

/***** Enumerations *****/

/** @{ */
/** Data Collection library Aggregation Functions return type.
 * \noop \public \memberof data_collection_aggregate_result_t
 * \headerfile aggregation-function.h <data-collection-sp/data-collection.h>
 *
 * Set in data_collection_aggregate_result_t by the aggregation functions (e.g. data_collection_aggregation_function_int64()) when
 * returning the result.
 */
typedef enum {
    DATA_COLLECTION_AGGREGATE_RESULT_ARRAY, /**< Result returned by the Aggregation Function (e.g. none) is an array. */
    DATA_COLLECTION_AGGREGATE_RESULT_SIZE,  /**< Result returned by the Aggregation Function (e.g. count) is size. */
    DATA_COLLECTION_AGGREGATE_RESULT_VALUE, /**< Result returned by the Aggregation Function (e.g. min, max, sum) is a value. */
    DATA_COLLECTION_AGGREGATE_RESULT_DOUBLE /**< Result returned by the Aggregation Function (e.g. mean) is a double. */
} data_collection_aggregate_result_type_e;
/** @} */

/** Result returned by Aggregation functions.
 * \headerfile aggregation-function.h <data-collection-sp/data-collection.h>
 *
 * `#include <data-collection-sp/data-collection.h>`
 *
 * The OpenAPI 3.0 specification has 3 integer (integer, int32 and int64) and 3 floating point (number, float, double) numeric data types.
 * The library treats "integer" as an alias for "int64" and "number" as an alias for "double".
 *
 * The Aggregation functions (data_collection_aggregation_function_*()) populate this data structure to provide the calculated
 * value(s) to the AF.
 *
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

/** Access the result field for an integer within \a result.
 * \public \memberof data_collection_aggregate_result_t
 * \hideinitializer
 * \hideinlinesource
 * \param result aggregated result object.
 * \returns The integer field within the aggregated result object.
 */
#define DATA_COLLECTION_AGGREGATION_RESULT_INTEGER(result) ((result).int64)

/** Access the result field for an int32 within \a result.
 * \public \memberof data_collection_aggregate_result_t
 * \param result aggregated result object.
 * \returns The int32 field within the aggregated result object.
 */
#define DATA_COLLECTION_AGGREGATION_RESULT_INT32(result) ((result).int32)

/*!
   \brief Access the result field for an int64 within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The int64 field within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT64(result) ((result).int64)

/*! 
   \brief Access the result field for a number within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The number field within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_NUMBER(result) ((result).double_prec)

/*!
   \brief Access the result field for a float data type within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The float field within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_FLOAT(result) ((result).floating_pt)

/*!
   \brief Access the result field for a double data type within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The double field within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(result) ((result).double_prec)

/*!
   \brief Access the result field for a start of generic array pointer within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The start of generic array pointer within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_ARRAY_PTR(result) ((result).array)

/*!
   \brief Access the generic array size field in the result object \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The array size field with the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Access the result field for an integer array within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The start of array pointer for an integer array within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INTEGER_ARRAY_PTR(result) ((result).int64_array)

/*!
   \brief Access the integer array size field in the result object \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The array size field with the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INTEGER_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Access the result field for an int32 array within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The start of array pointer for an int32 array within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT32_ARRAY_PTR(result) ((result).int32_array)

/*!
   \brief Access the int32 array size field in the result object \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The array size field with the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT32_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief access the result field for an int64 array within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The start of array pointer for an int64 array within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_PTR(result) ((result).int64_array)

/*!
   \brief Access the int64 array size field in the result object \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The array size field with the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Access the result field for a number array within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The start of array pointer for a number array within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_NUMBER_ARRAY_PTR(result) ((result).double_array)

/*!
   \brief Access the number array size field in the result object \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The array size field with the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_NUMBER_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Access the result field for a float array within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The start of array pointer for a float array within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_FLOAT_ARRAY_PTR(result) ((result).float_array)

/*!
   \brief Access the float array size field in the result object \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The array size field with the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_FLOAT_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Access the rsult field for a double array within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The start of array pointer for a double array within the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE_ARRAY_PTR(result) ((result).double_array)

/*!
   \brief Access the double array size field in the result object \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The array size field with the aggregated result object.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE_ARRAY_SIZE(result) ((result).array_len)

/*!
   \brief Access the result field for the size of the result within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The field for size of the result object within \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_SIZE(result) ((result).size)

/*!
   \brief Access the result type field within \a result.
   \public \memberof data_collection_aggregate_result_t
   \param result aggregated result object.
   \returns The result object type field within \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_TYPE(result) ((result).result_type)

/*!
   \brief Checks if \a result type is a single value of the same type used as input.
   \public \memberof data_collection_aggregate_result_t

   The result of the aggregation is represented as a single value of the same type as the input. This will happen for aggregation
   functions that select a value from the input, such as "MINIMUM" or "MAXIMUM", or where the function does not involve division,
   such as "SUM".

   \param result aggregated result object.
   \returns Returns "true" if the result type is a single value of the same type as the input array, "false" otherwise.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_VALUE(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_VALUE)

/*!
   \brief Checks if \a result is a size type.
   \public \memberof data_collection_aggregate_result_t

   The result of the aggregation is represented as a size value. This will happen for aggregation functions that count values in
   the input, such as "COUNT".

   \param result aggregated result object.
   \returns Returns "true" if the result type is size, "false" otherwise. \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_SIZE(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_SIZE)

/*!
   \brief Checks if \a result is an array type.
   \public \memberof data_collection_aggregate_result_t

   The result of the aggregation is an array of values. This will happen for aggregation functions that may filter the input values,
   such as "NONE" (the identity function).

   \param result aggregated result object.
   \returns Returns "true" if the result type is array, "false" otherwise. \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_ARRAY(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_ARRAY)

/*!
   \brief Checks if \a result is a double type.
   \public \memberof data_collection_aggregate_result_t

   The result of the aggregation is represented as a double type. This will happen for aggregation functions such as "MEAN" which
   involve an operation such as a division in the calculation and therefore only make sense if the result is a double precision
   number.

   \param result aggregated result object.
   \returns Returns "true" if the result type is double, "false" otherwise. \a result.
*/
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_DOUBLE(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_DOUBLE)

/**
 * Performs the aggregation function on the input of type int32_t
 * \public \memberof data_collection_aggregate_result_t
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
 * \public \memberof data_collection_aggregate_result_t
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
 * \public \memberof data_collection_aggregate_result_t
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
 * \public \memberof data_collection_aggregate_result_t
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
 * \public \memberof data_collection_aggregate_result_t
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
 * \public \memberof data_collection_aggregate_result_t
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
 * \public \memberof data_collection_aggregate_result_t
 *
 * @param result The aggregation result object that needs to be deleted.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_aggregation_function_result_free(data_collection_aggregate_result_t *result);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_AGGREGATION_FUNCTION_H */
