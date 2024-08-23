#ifndef _DATA_COLLECTION_DATA_REPORTING_SESSION_H_
#define _DATA_COLLECTION_DATA_REPORTING_SESSION_H_

/**********************************************************************************************************************************
 * DataReportingSession - Public C interface to the DataReportingSession object
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

#include "DataDomain.h"
#include "DataSamplingRule.h"
#include "DataReportingRule.h"
#include "DataReportingCondition.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_data_reporting_session_s data_collection_model_data_reporting_session_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create_copy(const data_collection_model_data_reporting_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_create_move(data_collection_model_data_reporting_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_copy(data_collection_model_data_reporting_session_t *data_reporting_session, const data_collection_model_data_reporting_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_move(data_collection_model_data_reporting_session_t *data_reporting_session, data_collection_model_data_reporting_session_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_session_free(data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_session_toJSON(const data_collection_model_data_reporting_session_t *data_reporting_session, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_is_equal_to(const data_collection_model_data_reporting_session_t *data_reporting_session, const data_collection_model_data_reporting_session_t *other_data_reporting_session);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_session_id(const data_collection_model_data_reporting_session_t *data_reporting_session);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_session_get_session_id(const data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_session_id(data_collection_model_data_reporting_session_t *data_reporting_session, const char* p_session_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_session_id_move(data_collection_model_data_reporting_session_t *data_reporting_session, char* p_session_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_valid_until(const data_collection_model_data_reporting_session_t *data_reporting_session);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_session_get_valid_until(const data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_valid_until(data_collection_model_data_reporting_session_t *data_reporting_session, const char* p_valid_until);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_valid_until_move(data_collection_model_data_reporting_session_t *data_reporting_session, char* p_valid_until);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_session_get_external_application_id(const data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_external_application_id(data_collection_model_data_reporting_session_t *data_reporting_session, const char* p_external_application_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_external_application_id_move(data_collection_model_data_reporting_session_t *data_reporting_session, char* p_external_application_id);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_session_get_supported_domains(const data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_supported_domains(data_collection_model_data_reporting_session_t *data_reporting_session, const ogs_list_t* p_supported_domains);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_supported_domains_move(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t* p_supported_domains);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_supported_domains(data_collection_model_data_reporting_session_t *data_reporting_session, data_collection_model_data_domain_t* supported_domains);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_supported_domains(data_collection_model_data_reporting_session_t *data_reporting_session, const data_collection_model_data_domain_t* supported_domains);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_supported_domains(data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_sampling_rules(const data_collection_model_data_reporting_session_t *data_reporting_session);


DATA_COLLECTION_SVC_PRODUCER_API const ogs_hash_t* data_collection_model_data_reporting_session_get_sampling_rules(const data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_sampling_rules(data_collection_model_data_reporting_session_t *data_reporting_session, const ogs_hash_t* p_sampling_rules);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_sampling_rules_move(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_hash_t* p_sampling_rules);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_sampling_rules(data_collection_model_data_reporting_session_t *data_reporting_session,  const char *key, const ogs_list_t* sampling_rules);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_sampling_rules(data_collection_model_data_reporting_session_t *data_reporting_session, const char *key);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_sampling_rules(data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_reporting_conditions(const data_collection_model_data_reporting_session_t *data_reporting_session);


DATA_COLLECTION_SVC_PRODUCER_API const ogs_hash_t* data_collection_model_data_reporting_session_get_reporting_conditions(const data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_conditions(data_collection_model_data_reporting_session_t *data_reporting_session, const ogs_hash_t* p_reporting_conditions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_conditions_move(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_hash_t* p_reporting_conditions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_reporting_conditions(data_collection_model_data_reporting_session_t *data_reporting_session,  const char *key, const ogs_list_t* reporting_conditions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_reporting_conditions(data_collection_model_data_reporting_session_t *data_reporting_session, const char *key);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_reporting_conditions(data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_session_has_reporting_rules(const data_collection_model_data_reporting_session_t *data_reporting_session);


DATA_COLLECTION_SVC_PRODUCER_API const ogs_hash_t* data_collection_model_data_reporting_session_get_reporting_rules(const data_collection_model_data_reporting_session_t *data_reporting_session);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, const ogs_hash_t* p_reporting_rules);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_set_reporting_rules_move(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_hash_t* p_reporting_rules);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_add_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session,  const char *key, const ogs_list_t* reporting_rules);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_remove_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, const char *key);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_session_t *data_collection_model_data_reporting_session_clear_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session);

/* lnode helper for generating ogs_list_t nodes's of type DataReportingSession */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_session_make_lnode(data_collection_model_data_reporting_session_t *data_reporting_session);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_SESSION_H_ */

