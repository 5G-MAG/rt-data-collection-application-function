#ifndef _DATA_COLLECTION_MS_ACCESS_ACTIVITY_COLLECTION_H_
#define _DATA_COLLECTION_MS_ACCESS_ACTIVITY_COLLECTION_H_

/**********************************************************************************************************************************
 * MSAccessActivityCollection - Public C interface to the MSAccessActivityCollection object
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

#include "MediaStreamingAccessRecord.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_ms_access_activity_collection_s data_collection_model_ms_access_activity_collection_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_create_copy(const data_collection_model_ms_access_activity_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_create_move(data_collection_model_ms_access_activity_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_copy(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection, const data_collection_model_ms_access_activity_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_move(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection, data_collection_model_ms_access_activity_collection_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ms_access_activity_collection_free(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ms_access_activity_collection_toJSON(const data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ms_access_activity_collection_get_ms_acc_acts(const data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_set_ms_acc_acts(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection, const ogs_list_t* p_ms_acc_acts);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_set_ms_acc_acts_move(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection, ogs_list_t* p_ms_acc_acts);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_add_ms_acc_acts(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection, data_collection_model_media_streaming_access_record_t* ms_acc_acts);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_remove_ms_acc_acts(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection, const data_collection_model_media_streaming_access_record_t* ms_acc_acts);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ms_access_activity_collection_t *data_collection_model_ms_access_activity_collection_clear_ms_acc_acts(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection);

/* lnode helper for generating ogs_list_t nodes's of type MSAccessActivityCollection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ms_access_activity_collection_make_lnode(data_collection_model_ms_access_activity_collection_t *ms_access_activity_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MS_ACCESS_ACTIVITY_COLLECTION_H_ */

