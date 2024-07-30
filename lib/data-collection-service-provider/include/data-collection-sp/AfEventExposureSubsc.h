#ifndef _DATA_COLLECTION_AF_EVENT_EXPOSURE_SUBSC_H_
#define _DATA_COLLECTION_AF_EVENT_EXPOSURE_SUBSC_H_

/**********************************************************************************************************************************
 * AfEventExposureSubsc - Public C interface to the AfEventExposureSubsc object
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

#include "ReportingInformation.h"
#include "AfEventNotification.h"
#include "EventsSubs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_af_event_exposure_subsc_s data_collection_model_af_event_exposure_subsc_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_create_copy(const data_collection_model_af_event_exposure_subsc_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_create_move(data_collection_model_af_event_exposure_subsc_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_copy(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_af_event_exposure_subsc_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, data_collection_model_af_event_exposure_subsc_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_af_event_exposure_subsc_free(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_af_event_exposure_subsc_toJSON(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_exposure_subsc_is_equal_to(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_af_event_exposure_subsc_t *other_af_event_exposure_subsc);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_data_acc_prof_id(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_data_acc_prof_id(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const char* p_data_acc_prof_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_data_acc_prof_id_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, char* p_data_acc_prof_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_exposure_subsc_get_events_subs(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_subs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const ogs_list_t* p_events_subs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_subs_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, ogs_list_t* p_events_subs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_add_events_subs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, data_collection_model_events_subs_t* events_subs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_remove_events_subs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_events_subs_t* events_subs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_clear_events_subs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_reporting_information_t* data_collection_model_af_event_exposure_subsc_get_events_rep_info(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_rep_info(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_reporting_information_t* p_events_rep_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_rep_info_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, data_collection_model_reporting_information_t* p_events_rep_info);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_notif_uri(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_uri(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const char* p_notif_uri);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_uri_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, char* p_notif_uri);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_notif_id(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_id(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const char* p_notif_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_id_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, char* p_notif_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_exposure_subsc_get_event_notifs(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_event_notifs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const ogs_list_t* p_event_notifs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_event_notifs_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, ogs_list_t* p_event_notifs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_add_event_notifs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, data_collection_model_af_event_notification_t* event_notifs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_remove_event_notifs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_af_event_notification_t* event_notifs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_clear_event_notifs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_supp_feat(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_supp_feat(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const char* p_supp_feat);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_supp_feat_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, char* p_supp_feat);

/* lnode helper for generating ogs_list_t nodes's of type AfEventExposureSubsc */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_af_event_exposure_subsc_make_lnode(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_AF_EVENT_EXPOSURE_SUBSC_H_ */

