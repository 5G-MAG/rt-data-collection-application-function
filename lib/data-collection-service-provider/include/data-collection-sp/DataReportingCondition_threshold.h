#ifndef _DATA_COLLECTION_DATA_REPORTING_CONDITION_THRESHOLD_H_
#define _DATA_COLLECTION_DATA_REPORTING_CONDITION_THRESHOLD_H_

/**********************************************************************************************************************************
 * DataReportingCondition_threshold - Public C interface to the DataReportingCondition_threshold object
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

typedef struct data_collection_model_data_reporting_condition_threshold_s data_collection_model_data_reporting_condition_threshold_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_create_copy(const data_collection_model_data_reporting_condition_threshold_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_create_move(data_collection_model_data_reporting_condition_threshold_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_copy(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, const data_collection_model_data_reporting_condition_threshold_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_move(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, data_collection_model_data_reporting_condition_threshold_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_condition_threshold_free(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_condition_threshold_toJSON(const data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_condition_threshold_t *data_collection_model_data_reporting_condition_threshold_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_threshold_is_equal_to(const data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold, const data_collection_model_data_reporting_condition_threshold_t *other_data_reporting_condition_threshold);


/* lnode helper for generating ogs_list_t nodes's of type DataReportingCondition_threshold */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_condition_threshold_make_lnode(data_collection_model_data_reporting_condition_threshold_t *data_reporting_condition_threshold);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_CONDITION_THRESHOLD_H_ */

