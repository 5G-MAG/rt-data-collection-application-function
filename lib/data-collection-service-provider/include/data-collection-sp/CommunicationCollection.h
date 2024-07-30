#ifndef _DATA_COLLECTION_COMMUNICATION_COLLECTION_H_
#define _DATA_COLLECTION_COMMUNICATION_COLLECTION_H_

/**********************************************************************************************************************************
 * CommunicationCollection - Public C interface to the CommunicationCollection object
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

typedef struct data_collection_model_communication_collection_s data_collection_model_communication_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_create_copy(const data_collection_model_communication_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_create_move(data_collection_model_communication_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_copy(data_collection_model_communication_collection_t *communication_collection, const data_collection_model_communication_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_move(data_collection_model_communication_collection_t *communication_collection, data_collection_model_communication_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_communication_collection_free(data_collection_model_communication_collection_t *communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_communication_collection_toJSON(const data_collection_model_communication_collection_t *communication_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_collection_is_equal_to(const data_collection_model_communication_collection_t *communication_collection, const data_collection_model_communication_collection_t *other_communication_collection);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_collection_get_start_time(const data_collection_model_communication_collection_t *communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_start_time(data_collection_model_communication_collection_t *communication_collection, const char* p_start_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_start_time_move(data_collection_model_communication_collection_t *communication_collection, char* p_start_time);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_collection_get_end_time(const data_collection_model_communication_collection_t *communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_end_time(data_collection_model_communication_collection_t *communication_collection, const char* p_end_time);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_end_time_move(data_collection_model_communication_collection_t *communication_collection, char* p_end_time);

DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_collection_get_ul_vol(const data_collection_model_communication_collection_t *communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_ul_vol(data_collection_model_communication_collection_t *communication_collection, const int64_t p_ul_vol);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_ul_vol_move(data_collection_model_communication_collection_t *communication_collection, int64_t p_ul_vol);

DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_collection_get_dl_vol(const data_collection_model_communication_collection_t *communication_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_dl_vol(data_collection_model_communication_collection_t *communication_collection, const int64_t p_dl_vol);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_dl_vol_move(data_collection_model_communication_collection_t *communication_collection, int64_t p_dl_vol);

/* lnode helper for generating ogs_list_t nodes's of type CommunicationCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_communication_collection_make_lnode(data_collection_model_communication_collection_t *communication_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_COMMUNICATION_COLLECTION_H_ */

