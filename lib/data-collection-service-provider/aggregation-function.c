/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef data_collection_aggregate_result_t *(*__aggregation_fn_t)(void *array, size_t array_len);
typedef struct fn_lookup_s {
    const char *name;
    __aggregation_fn_t fn;
} fn_lookup_t;

static data_collection_aggregate_result_t *_generic_none(void *array, size_t item_size, size_t entries);
static data_collection_aggregate_result_t *_int32_none_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_count_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_int32_min_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_int32_max_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_int32_sum_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_int32_mean_fn(void *array, size_t entries);

static data_collection_aggregate_result_t *_int64_none_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_int64_min_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_int64_max_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_int64_sum_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_int64_mean_fn(void *array, size_t entries);

static data_collection_aggregate_result_t *_float_none_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_float_min_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_float_max_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_float_sum_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_float_mean_fn(void *array, size_t entries);


static data_collection_aggregate_result_t *_double_none_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_double_min_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_double_max_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_double_sum_fn(void *array, size_t entries);
static data_collection_aggregate_result_t *_double_mean_fn(void *array, size_t entries);


static fn_lookup_t _int_32_fns[] = {
    {"NONE", _int32_none_fn},
    {"COUNT", _count_fn},
    {"MEAN", _int32_mean_fn},
    {"MIN", _int32_min_fn},
    {"MAX", _int32_max_fn},
    {"SUM", _int32_sum_fn}
};

static fn_lookup_t _int_64_fns[] = {
    {"NONE", _int64_none_fn},
    {"COUNT", _count_fn},
    {"MEAN", _int64_mean_fn},
    {"MIN", _int64_min_fn},
    {"MAX", _int64_max_fn},
    {"SUM", _int64_sum_fn}
};

static fn_lookup_t _float_fns[] = {
    {"NONE", _float_none_fn},
    {"COUNT", _count_fn},
    {"MEAN", _float_mean_fn},
    {"MIN", _float_min_fn},
    {"MAX", _float_max_fn},
    {"SUM", _float_sum_fn}
};


static fn_lookup_t _double_fns[] = {
    {"NONE", _double_none_fn},
    {"COUNT", _count_fn},
    {"MEAN", _double_mean_fn},
    {"MIN", _double_min_fn},
    {"MAX", _double_max_fn},
    {"SUM", _double_sum_fn}
};

/******** Public API ********/

DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_int32(const char *fname, int32_t *array, size_t array_len)
{
    int i;
    for(i=0; i < (sizeof(_int_32_fns)/sizeof(_int_32_fns[0])); i++) {
        if(!strcmp(_int_32_fns[i].name, fname)) {
	    return _int_32_fns[i].fn(array, array_len);
        }
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_int64(const char *fn_name, int64_t *input_array, size_t input_len) 
{
    int i;
    for(i=0; i < (sizeof(_int_64_fns)/sizeof(_int_64_fns[0])); i++) {
        if(!strcmp(_int_64_fns[i].name, fn_name)) {
            return _int_64_fns[i].fn(input_array, input_len);
        }
    }
    return NULL;

}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_float(const char *fn_name, float *input_array, size_t input_len) 
{

    int i;
    for(i=0; i < (sizeof(_float_fns)/sizeof(_float_fns[0])); i++) {
        if(!strcmp(_float_fns[i].name, fn_name)) {
            return _float_fns[i].fn(input_array, input_len);
        }
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_aggregate_result_t *data_collection_aggregation_function_double(const char *fn_name, double *input_array, size_t input_len)
{

    int i;
    for(i=0; i < (sizeof(_double_fns)/sizeof(_double_fns[0])); i++) {
        if(!strcmp(_double_fns[i].name, fn_name)) {
            return _double_fns[i].fn(input_array, input_len);
        }
    }
    return NULL;

}

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_aggregation_function_result_free(data_collection_aggregate_result_t *result)
{
    if(DATA_COLLECTION_AGGREGATION_RESULT_IS_ARRAY(*result)) {
        ogs_free(DATA_COLLECTION_AGGREGATION_RESULT_ARRAY_PTR(*result));
    }
    ogs_free(result);
}

/******** Internal library API *********/


/******** Private functions ***********/


static data_collection_aggregate_result_t *_generic_none(void *array, size_t item_size, size_t entries)
{
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret)); 
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_ARRAY;
    DATA_COLLECTION_AGGREGATION_RESULT_ARRAY_PTR(*ret) = ogs_malloc(item_size * entries);
    DATA_COLLECTION_AGGREGATION_RESULT_ARRAY_SIZE(*ret) = entries;
    memcpy(ret->array, array, item_size * entries);		    
    return ret;
}

static data_collection_aggregate_result_t *_int32_none_fn(void *array, size_t entries)
{
    return _generic_none(array, sizeof(int32_t), entries);
}

static data_collection_aggregate_result_t *_int32_min_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    int32_t *int_array = (int32_t*)array;
    size_t i;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    int32_t min = int_array[0];
    for (i=1; i<entries; i++) {
        if (int_array[i] < min) min = int_array[i];
    }
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_INT32(*ret) = min;
    return ret;   
}

static data_collection_aggregate_result_t *_int32_max_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    int32_t *int_array = (int32_t*)array;
    size_t i;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    int32_t max = int_array[0];
    for (i=1; i<entries; i++) {
        if (int_array[i] > max) max = int_array[i];
    }
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_INT32(*ret) = max;
    return ret;
}

static data_collection_aggregate_result_t *_int32_sum_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    int32_t *int_array = (int32_t*)array;
    size_t i;
    int32_t sum;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    for(i = 0; i < entries; i++) {
        sum += int_array[i];
    }
    
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_INT32(*ret) = sum;
    return ret;
}

static data_collection_aggregate_result_t *_int32_mean_fn(void *array, size_t entries)
{
    data_collection_aggregate_result_t *ret = _int32_sum_fn(array, entries);
    if (ret) {
        DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_DOUBLE;
        DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(*ret) = (double)(DATA_COLLECTION_AGGREGATION_RESULT_INT32(*ret))/(double)entries;
    }
    return ret;
}

/****int64_t functions***/

static data_collection_aggregate_result_t *_int64_none_fn(void *array, size_t entries)
{
    return _generic_none(array, sizeof(int64_t), entries);
}

static data_collection_aggregate_result_t *_int64_min_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    int64_t *int_array = (int64_t*)array;
    size_t i;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    int64_t min = int_array[0];
    for (i=1; i<entries; i++) {
        if (int_array[i] < min) min = int_array[i];
    }
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_INT64(*ret) = min;
    return ret;   
}

static data_collection_aggregate_result_t *_int64_max_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    int64_t *int_array = (int64_t*)array;
    size_t i;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    int64_t max = int_array[0];
    for (i=1; i<entries; i++) {
        if (int_array[i] > max) max = int_array[i];
    }
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_INT64(*ret) = max;
    return ret;	
}

static data_collection_aggregate_result_t *_int64_sum_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    int64_t *int_array = (int64_t*)array;
    size_t i;
    int64_t sum = 0;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    for(i = 0; i < entries; i++) {
        sum += int_array[i];
    }
    
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_INT64(*ret) = sum;
    return ret;
}

static data_collection_aggregate_result_t *_int64_mean_fn(void *array, size_t entries)
{
    data_collection_aggregate_result_t *ret = _int64_sum_fn(array, entries);
    if (ret) {
        DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_DOUBLE;
        DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(*ret) = (double)(DATA_COLLECTION_AGGREGATION_RESULT_INT64(*ret))/(double)entries;
    }
    return ret;	
}

/************/

/****float_pt functions***/

static data_collection_aggregate_result_t *_float_none_fn(void *array, size_t entries)
{
    return _generic_none(array, sizeof(float), entries);
}

static data_collection_aggregate_result_t *_float_min_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    float *float_array = (float*)array;
    size_t i;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    float min = float_array[0];
    for (i=1; i<entries; i++) {
        if (float_array[i] < min) min = float_array[i];
    }
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_FLOAT(*ret) = min;
    return ret;   
}

static data_collection_aggregate_result_t *_float_max_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    float *float_array = (float*)array;
    size_t i;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    float max = float_array[0];
    for (i=1; i<entries; i++) {
        if (float_array[i] > max) max = float_array[i];
    }
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_FLOAT(*ret) = max;
    return ret;	
}

static data_collection_aggregate_result_t *_float_sum_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    float *float_array = (float*)array;
    size_t i;
    float sum;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    for(i = 0; i < entries; i++) {
        sum += float_array[i];
    }
    
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_FLOAT(*ret) = sum;
    return ret;
}

static data_collection_aggregate_result_t *_float_mean_fn(void *array, size_t entries)
{
    data_collection_aggregate_result_t *ret = _float_sum_fn(array, entries);
    if (ret) {
        DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_DOUBLE;
        DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(*ret) = (double)(DATA_COLLECTION_AGGREGATION_RESULT_FLOAT(*ret))/(double)entries;
    }
    return ret;	
}

/************/

/****Aggregation functions to handle Double**/


static data_collection_aggregate_result_t *_double_none_fn(void *array, size_t entries)
{
    return _generic_none(array, sizeof(double), entries);
}

static data_collection_aggregate_result_t *_double_min_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    double *double_array = (double*)array;
    size_t i;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    double min = double_array[0];
    for (i=1; i<entries; i++) {
        if (double_array[i] < min) min = double_array[i];
    }
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(*ret) = min;
    return ret;   
}

static data_collection_aggregate_result_t *_double_max_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    double *double_array = (double*)array;
    size_t i;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    double max = double_array[0];
    for (i=1; i<entries; i++) {
        if (double_array[i] > max) max = double_array[i];
    }
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(*ret) = max;
    return ret;	
}

static data_collection_aggregate_result_t *_double_sum_fn(void *array, size_t entries)
{
    if (entries == 0) return NULL;
    double *double_array = (double*)array;
    size_t i;
    double sum;
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret));
    for(i = 0; i < entries; i++) {
        sum += double_array[i];
    }
    
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_VALUE;
    DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(*ret) = sum;
    return ret;
}

static data_collection_aggregate_result_t *_double_mean_fn(void *array, size_t entries)
{
    data_collection_aggregate_result_t *ret = _double_sum_fn(array, entries);
    if (ret) {
        DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_DOUBLE;
        DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(*ret) = (double)(DATA_COLLECTION_AGGREGATION_RESULT_DOUBLE(*ret))/(double)entries;
    }
    return ret;	
}

/************/

static data_collection_aggregate_result_t *_count_fn(void *array, size_t entries)
{
    data_collection_aggregate_result_t *ret = ogs_calloc(1, sizeof(*ret)); 
    DATA_COLLECTION_AGGREGATION_RESULT_TYPE(*ret) = DATA_COLLECTION_AGGREGATE_RESULT_SIZE;
    DATA_COLLECTION_AGGREGATION_RESULT_ARRAY_SIZE(*ret) = entries;
    return ret;
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
