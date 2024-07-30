#ifndef _DATA_COLLECTION_AF_EVENT_EXPOSURE_NOTIF_H_
#define _DATA_COLLECTION_AF_EVENT_EXPOSURE_NOTIF_H_

/**********************************************************************************************************************************
 * AfEventExposureNotif - Public C interface to the AfEventExposureNotif object
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

#include "AfEventNotification.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_af_event_exposure_notif_s data_collection_model_af_event_exposure_notif_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_create_copy(const data_collection_model_af_event_exposure_notif_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_create_move(data_collection_model_af_event_exposure_notif_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_copy(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const data_collection_model_af_event_exposure_notif_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_move(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, data_collection_model_af_event_exposure_notif_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_af_event_exposure_notif_free(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_af_event_exposure_notif_toJSON(const data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_exposure_notif_is_equal_to(const data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const data_collection_model_af_event_exposure_notif_t *other_af_event_exposure_notif);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_notif_get_notif_id(const data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_notif_id(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const char* p_notif_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_notif_id_move(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, char* p_notif_id);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_exposure_notif_get_event_notifs(const data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_event_notifs(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const ogs_list_t* p_event_notifs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_event_notifs_move(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, ogs_list_t* p_event_notifs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_add_event_notifs(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, data_collection_model_af_event_notification_t* event_notifs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_remove_event_notifs(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const data_collection_model_af_event_notification_t* event_notifs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_clear_event_notifs(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif);

/* lnode helper for generating ogs_list_t nodes's of type AfEventExposureNotif */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_af_event_exposure_notif_make_lnode(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_AF_EVENT_EXPOSURE_NOTIF_H_ */

