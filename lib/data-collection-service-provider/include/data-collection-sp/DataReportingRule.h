#ifndef _DATA_COLLECTION_DATA_REPORTING_RULE_H_
#define _DATA_COLLECTION_DATA_REPORTING_RULE_H_

/**********************************************************************************************************************************
 * DataReportingRule - Public C interface to the DataReportingRule object
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

typedef struct data_collection_model_data_reporting_rule_s data_collection_model_data_reporting_rule_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create_copy(const data_collection_model_data_reporting_rule_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_create_move(data_collection_model_data_reporting_rule_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_copy(data_collection_model_data_reporting_rule_t *data_reporting_rule, const data_collection_model_data_reporting_rule_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, data_collection_model_data_reporting_rule_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_rule_free(data_collection_model_data_reporting_rule_t *data_reporting_rule);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_rule_toJSON(const data_collection_model_data_reporting_rule_t *data_reporting_rule, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_is_equal_to(const data_collection_model_data_reporting_rule_t *data_reporting_rule, const data_collection_model_data_reporting_rule_t *other_data_reporting_rule);


DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_reporting_rule_get_context_ids(const data_collection_model_data_reporting_rule_t *data_reporting_rule);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_context_ids(data_collection_model_data_reporting_rule_t *data_reporting_rule, const ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_context_ids_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, ogs_list_t* p_context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_add_context_ids(data_collection_model_data_reporting_rule_t *data_reporting_rule, char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_remove_context_ids(data_collection_model_data_reporting_rule_t *data_reporting_rule, const char* context_ids);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_clear_context_ids(data_collection_model_data_reporting_rule_t *data_reporting_rule);

DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_data_reporting_rule_get_reporting_probability(const data_collection_model_data_reporting_rule_t *data_reporting_rule);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_probability(data_collection_model_data_reporting_rule_t *data_reporting_rule, const double p_reporting_probability);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_probability_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, double p_reporting_probability);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_rule_get_reporting_format(const data_collection_model_data_reporting_rule_t *data_reporting_rule);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_format(data_collection_model_data_reporting_rule_t *data_reporting_rule, const char* p_reporting_format);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_reporting_format_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, char* p_reporting_format);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_reporting_rule_get_data_packaging_strategy(const data_collection_model_data_reporting_rule_t *data_reporting_rule);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_data_packaging_strategy(data_collection_model_data_reporting_rule_t *data_reporting_rule, const char* p_data_packaging_strategy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_rule_t *data_collection_model_data_reporting_rule_set_data_packaging_strategy_move(data_collection_model_data_reporting_rule_t *data_reporting_rule, char* p_data_packaging_strategy);

/* lnode helper for generating ogs_list_t nodes's of type DataReportingRule */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_rule_make_lnode(data_collection_model_data_reporting_rule_t *data_reporting_rule);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_RULE_H_ */

