#ifndef _DATA_COLLECTION_DATA_REPORTING_EVENT_TRIGGER_H_
#define _DATA_COLLECTION_DATA_REPORTING_EVENT_TRIGGER_H_

/**********************************************************************************************************************************
 * DataReportingEventTrigger - Public C interface to the DataReportingEventTrigger object
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

#include "DataReportingEventTrigger_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_data_reporting_event_trigger_s data_collection_model_data_reporting_event_trigger_t;

typedef enum {
    DCM_DATA_REPORTING_EVENT_TRIGGER_NO_VAL,
    DCM_DATA_REPORTING_EVENT_TRIGGER_VAL_LOCATION,
    DCM_DATA_REPORTING_EVENT_TRIGGER_VAL_DESTINATION,
    DCM_DATA_REPORTING_EVENT_TRIGGER_OTHER
} data_collection_model_data_reporting_event_trigger_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_create_copy(const data_collection_model_data_reporting_event_trigger_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_create_move(data_collection_model_data_reporting_event_trigger_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_copy(data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger, const data_collection_model_data_reporting_event_trigger_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_move(data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger, data_collection_model_data_reporting_event_trigger_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_reporting_event_trigger_free(data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_reporting_event_trigger_toJSON(const data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_event_trigger_t *data_collection_model_data_reporting_event_trigger_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_event_trigger_is_not_set(const data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_event_trigger_is_non_standard(const data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_reporting_event_trigger_e data_collection_model_data_reporting_event_trigger_get_enum(const data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_data_reporting_event_trigger_get_string(const data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_event_trigger_set_enum(data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger, data_collection_model_data_reporting_event_trigger_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_event_trigger_set_string(data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type DataReportingEventTrigger */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_reporting_event_trigger_make_lnode(data_collection_model_data_reporting_event_trigger_t *data_reporting_event_trigger);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORTING_EVENT_TRIGGER_H_ */

