#ifndef _DATA_COLLECTION_DATA_REPORTING_PROVISIONING_SESSION_H_
#define _DATA_COLLECTION_DATA_REPORTING_PROVISIONING_SESSION_H_

/**********************************************************************************************************************************
 * DataReportingProvisioningSession - Public C interface to the DataReportingProvisioningSession object
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

#include "AfEvent.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_data_reporting_provisioning_session_s data_collection_model_data_reporting_provisioning_session_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_create_copy(const data_collection_model_data_reporting_provisioning_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_create_move(data_collection_model_data_reporting_provisioning_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_copy(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const data_collection_model_data_reporting_provisioning_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, data_collection_model_data_reporting_provisioning_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_provisioning_session_free(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_provisioning_session_toJSON(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_provisioning_session_get_provisioning_session_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_provisioning_session_id(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const char* p_provisioning_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_provisioning_session_id_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, char* p_provisioning_session_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_provisioning_session_get_asp_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_asp_id(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const char* p_asp_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_asp_id_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, char* p_asp_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_provisioning_session_get_external_application_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_external_application_id(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const char* p_external_application_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_external_application_id_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, char* p_external_application_id);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_provisioning_session_get_internal_application_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_internal_application_id(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const char* p_internal_application_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_internal_application_id_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, char* p_internal_application_id);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_t* data_collection_model_data_reporting_provisioning_session_get_event_id(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_event_id(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const data_collection_model_af_event_t* p_event_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_event_id_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, data_collection_model_af_event_t* p_event_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_provisioning_session_get_data_reporting_configuration_ids(const data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const ogs_list_t* p_data_reporting_configuration_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_set_data_reporting_configuration_ids_move(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, ogs_list_t* p_data_reporting_configuration_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_add_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, char* data_reporting_configuration_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_remove_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session, const char* data_reporting_configuration_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_provisioning_session_t *data_collection_model_data_reporting_provisioning_session_clear_data_reporting_configuration_ids(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/* lnode helper for generating ogs_list_t nodes's of type DataReportingProvisioningSession */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_provisioning_session_make_lnode(data_collection_model_data_reporting_provisioning_session_t *data_reporting_provisioning_session);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_PROVISIONING_SESSION_H_ */

