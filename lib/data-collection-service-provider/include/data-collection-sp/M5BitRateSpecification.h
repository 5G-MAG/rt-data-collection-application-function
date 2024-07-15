#ifndef _DATA_COLLECTION_M5_BIT_RATE_SPECIFICATION_H_
#define _DATA_COLLECTION_M5_BIT_RATE_SPECIFICATION_H_

/**********************************************************************************************************************************
 * M5BitRateSpecification - Public C interface to the M5BitRateSpecification object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_m5_bit_rate_specification_s data_collection_model_m5_bit_rate_specification_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_create_copy(const data_collection_model_m5_bit_rate_specification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_create_move(data_collection_model_m5_bit_rate_specification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_copy(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, const data_collection_model_m5_bit_rate_specification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_move(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, data_collection_model_m5_bit_rate_specification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_m5_bit_rate_specification_free(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_m5_bit_rate_specification_toJSON(const data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_m5_bit_rate_specification_get_maximum_requested_bit_rate(const data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_maximum_requested_bit_rate(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, const char* p_maximum_requested_bit_rate);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_maximum_requested_bit_rate_move(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, char* p_maximum_requested_bit_rate);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_m5_bit_rate_specification_get_minimum_desired_bit_rate(const data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_minimum_desired_bit_rate(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, const char* p_minimum_desired_bit_rate);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_minimum_desired_bit_rate_move(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, char* p_minimum_desired_bit_rate);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_m5_bit_rate_specification_get_minimum_requested_bit_rate(const data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_minimum_requested_bit_rate(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, const char* p_minimum_requested_bit_rate);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_bit_rate_specification_t *data_collection_model_m5_bit_rate_specification_set_minimum_requested_bit_rate_move(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification, char* p_minimum_requested_bit_rate);

/* lnode helper for generating ogs_list_t nodes's of type M5BitRateSpecification */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_m5_bit_rate_specification_make_lnode(data_collection_model_m5_bit_rate_specification_t *m5_bit_rate_specification);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_M5_BIT_RATE_SPECIFICATION_H_ */

