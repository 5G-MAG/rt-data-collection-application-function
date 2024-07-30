#ifndef _DATA_COLLECTION_AF_EVENT_H_
#define _DATA_COLLECTION_AF_EVENT_H_

/**********************************************************************************************************************************
 * AfEvent - Public C interface to the AfEvent object
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

#include "AfEvent_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_af_event_s data_collection_model_af_event_t;

typedef enum {
    DCM_AF_EVENT_NO_VAL,
    DCM_AF_EVENT_VAL_SVC_EXPERIENCE,
    DCM_AF_EVENT_VAL_UE_MOBILITY,
    DCM_AF_EVENT_VAL_UE_COMM,
    DCM_AF_EVENT_VAL_EXCEPTIONS,
    DCM_AF_EVENT_VAL_USER_DATA_CONGESTION,
    DCM_AF_EVENT_VAL_PERF_DATA,
    DCM_AF_EVENT_VAL_DISPERSION,
    DCM_AF_EVENT_VAL_COLLECTIVE_BEHAVIOUR,
    DCM_AF_EVENT_VAL_MS_QOE_METRICS,
    DCM_AF_EVENT_VAL_MS_CONSUMPTION,
    DCM_AF_EVENT_VAL_MS_NET_ASSIST_INVOCATION,
    DCM_AF_EVENT_VAL_MS_DYN_POLICY_INVOCATION,
    DCM_AF_EVENT_VAL_MS_ACCESS_ACTIVITY,
    DCM_AF_EVENT_VAL_GNSS_ASSISTANCE_DATA,
    DCM_AF_EVENT_VAL_DATA_VOLUME_TRANSFER_TIME,
    DCM_AF_EVENT_OTHER
} data_collection_model_af_event_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_t *data_collection_model_af_event_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_t *data_collection_model_af_event_create_copy(const data_collection_model_af_event_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_t *data_collection_model_af_event_create_move(data_collection_model_af_event_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_t *data_collection_model_af_event_copy(data_collection_model_af_event_t *af_event, const data_collection_model_af_event_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_t *data_collection_model_af_event_move(data_collection_model_af_event_t *af_event, data_collection_model_af_event_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_af_event_free(data_collection_model_af_event_t *af_event);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_af_event_toJSON(const data_collection_model_af_event_t *af_event, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_t *data_collection_model_af_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_is_equal_to(const data_collection_model_af_event_t *af_event, const data_collection_model_af_event_t *other_af_event);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_is_not_set(const data_collection_model_af_event_t *af_event);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_is_non_standard(const data_collection_model_af_event_t *af_event);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_e data_collection_model_af_event_get_enum(const data_collection_model_af_event_t *af_event);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_af_event_get_string(const data_collection_model_af_event_t *af_event);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_set_enum(data_collection_model_af_event_t *af_event, data_collection_model_af_event_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_set_string(data_collection_model_af_event_t *af_event, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type AfEvent */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_af_event_make_lnode(data_collection_model_af_event_t *af_event);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_AF_EVENT_H_ */

