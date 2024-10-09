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

typedef enum {
    DATA_COLLECTION_AGGREGATE_RESULT_ARRAY,
    DATA_COLLECTION_AGGREGATE_RESULT_SIZE,
    DATA_COLLECTION_AGGREGATE_RESULT_VALUE,
    DATA_COLLECTION_AGGREGATE_RESULT_DOUBLE
} data_collection_aggregate_result_type_e;

typedef struct data_collection_aggregate_result_s {
    data_collection_aggregate_result_type_e result_type;
    union {
        int32_t int32;
        int64_t int64;
        float floating_pt;
        double double_prec;
        struct {
            union {
                int32_t *int32_array;
                int64_t *int64_array;
                float *float_array;
                double *double_array;
                void *array;
            };
            size_t array_len;
        };
        size_t size;
    };
} data_collection_aggregate_result_t;

#define DATA_COLLECTION_AGGREGATION_RESULT_INTEGER(result) ((result).int64)
#define DATA_COLLECTION_AGGREGATION_RESULT_INT32(result) ((result).int32)
#define DATA_COLLECTION_AGGREGATION_RESULT_INT64(result) ((result).int64)
#define DATA_COLLECTION_AGGREGATION_RESULT_NUMBER(result) ((result).double_prec)
#define DATA_COLLECTION_AGGREGATION_RESULT_FLOAT(result) ((result).floating_pt)
#define DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(result) ((result).double_prec)
#define DATA_COLLECTION_AGGREGATION_RESULT_ARRAY_PTR(result) ((result).array)
#define DATA_COLLECTION_AGGREGATION_RESULT_ARRAY_SIZE(result) ((result).array_len)
#define DATA_COLLECTION_AGGREGATION_RESULT_INTEGER_ARRAY_PTR(result) ((result).int64_array)
#define DATA_COLLECTION_AGGREGATION_RESULT_INTEGER_ARRAY_SIZE(result) ((result).array_len)
#define DATA_COLLECTION_AGGREGATION_RESULT_INT32_ARRAY_PTR(result) ((result).int32_array)
#define DATA_COLLECTION_AGGREGATION_RESULT_INT32_ARRAY_SIZE(result) ((result).array_len)
#define DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_PTR(result) ((result).int64_array)
#define DATA_COLLECTION_AGGREGATION_RESULT_INT64_ARRAY_SIZE(result) ((result).array_len)
#define DATA_COLLECTION_AGGREGATION_RESULT_NUMBER_ARRAY_PTR(result) ((result).double_array)
#define DATA_COLLECTION_AGGREGATION_RESULT_NUMBER_ARRAY_SIZE(result) ((result).array_len)
#define DATA_COLLECTION_AGGREGATION_RESULT_FLOAT_ARRAY_PTR(result) ((result).float_array)
#define DATA_COLLECTION_AGGREGATION_RESULT_FLOAT_ARRAY_SIZE(result) ((result).array_len)
#define DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE_ARRAY_PTR(result) ((result).double_array)
#define DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE_ARRAY_SIZE(result) ((result).array_len)
#define DATA_COLLECTION_AGGREGATION_RESULT_SIZE(result) ((result).size)
#define DATA_COLLECTION_AGGREGATION_RESULT_TYPE(result) ((result).result_type)
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_VALUE(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_VALUE)
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_SIZE(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_SIZE)
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_ARRAY(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_ARRAY)
#define DATA_COLLECTION_AGGREGATION_RESULT_IS_DOUBLE(result) ((result).result_type == DATA_COLLECTION_AGGREGATE_RESULT_DOUBLE)

DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_int32(const char *fn_name, int32_t *input_array, size_t input_len);
DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_int64(const char *fn_name, int64_t *input_array, size_t input_len);
#define data_collection_aggregation_function_integer(fn_name, input_array, input_len) data_collection_aggregation_function_int64(fn_name, input_array, input_len)
DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_float(const char *fn_name, float *input_array, size_t input_len);
DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_double(const char *fn_name, double *input_array, size_t input_len);
#define data_collection_aggregation_function_number(fn_name, input_array, input_len) data_collection_aggregation_function_double(fn_name, input_array, input_len)
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_aggregation_function_result_free(data_collection_aggregate_result_t *result);	

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_AGGREGATION_FUNCTION_H */
