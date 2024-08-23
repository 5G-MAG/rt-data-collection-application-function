#ifndef _DATA_COLLECTION_SERVICE_EXPERIENCE_RECORD_H_
#define _DATA_COLLECTION_SERVICE_EXPERIENCE_RECORD_H_

/**********************************************************************************************************************************
 * ServiceExperienceRecord - Public C interface to the ServiceExperienceRecord object
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

#include "PerFlowServiceExperienceInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_service_experience_record_s data_collection_model_service_experience_record_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_create_copy(const data_collection_model_service_experience_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_create_move(data_collection_model_service_experience_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_copy(data_collection_model_service_experience_record_t *service_experience_record, const data_collection_model_service_experience_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_move(data_collection_model_service_experience_record_t *service_experience_record, data_collection_model_service_experience_record_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_service_experience_record_free(data_collection_model_service_experience_record_t *service_experience_record);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_service_experience_record_toJSON(const data_collection_model_service_experience_record_t *service_experience_record, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_record_is_equal_to(const data_collection_model_service_experience_record_t *service_experience_record, const data_collection_model_service_experience_record_t *other_service_experience_record);



DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_service_experience_record_get_timestamp(const data_collection_model_service_experience_record_t *service_experience_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_set_timestamp(data_collection_model_service_experience_record_t *service_experience_record, const char* p_timestamp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_set_timestamp_move(data_collection_model_service_experience_record_t *service_experience_record, char* p_timestamp);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_record_get_context_ids(const data_collection_model_service_experience_record_t *service_experience_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_set_context_ids(data_collection_model_service_experience_record_t *service_experience_record, const ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_set_context_ids_move(data_collection_model_service_experience_record_t *service_experience_record, ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_add_context_ids(data_collection_model_service_experience_record_t *service_experience_record, char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_remove_context_ids(data_collection_model_service_experience_record_t *service_experience_record, const char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_clear_context_ids(data_collection_model_service_experience_record_t *service_experience_record);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_record_get_service_experience_infos(const data_collection_model_service_experience_record_t *service_experience_record);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_set_service_experience_infos(data_collection_model_service_experience_record_t *service_experience_record, const ogs_list_t* p_service_experience_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_set_service_experience_infos_move(data_collection_model_service_experience_record_t *service_experience_record, ogs_list_t* p_service_experience_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_add_service_experience_infos(data_collection_model_service_experience_record_t *service_experience_record, data_collection_model_per_flow_service_experience_info_t* service_experience_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_remove_service_experience_infos(data_collection_model_service_experience_record_t *service_experience_record, const data_collection_model_per_flow_service_experience_info_t* service_experience_infos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_t *data_collection_model_service_experience_record_clear_service_experience_infos(data_collection_model_service_experience_record_t *service_experience_record);

/* lnode helper for generating ogs_list_t nodes's of type ServiceExperienceRecord */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_service_experience_record_make_lnode(data_collection_model_service_experience_record_t *service_experience_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SERVICE_EXPERIENCE_RECORD_H_ */

