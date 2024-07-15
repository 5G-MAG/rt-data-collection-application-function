#ifndef _DATA_COLLECTION_MUTING_NOTIFICATIONS_SETTINGS_H_
#define _DATA_COLLECTION_MUTING_NOTIFICATIONS_SETTINGS_H_

/**********************************************************************************************************************************
 * MutingNotificationsSettings - Public C interface to the MutingNotificationsSettings object
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

typedef struct data_collection_model_muting_notifications_settings_s data_collection_model_muting_notifications_settings_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create_copy(const data_collection_model_muting_notifications_settings_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create_move(data_collection_model_muting_notifications_settings_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_copy(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, const data_collection_model_muting_notifications_settings_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_move(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, data_collection_model_muting_notifications_settings_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_muting_notifications_settings_free(data_collection_model_muting_notifications_settings_t *muting_notifications_settings);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_muting_notifications_settings_toJSON(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_muting_notifications_settings_get_max_no_of_notif(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_max_no_of_notif(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, const int32_t p_max_no_of_notif);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_max_no_of_notif_move(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, int32_t p_max_no_of_notif);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_muting_notifications_settings_get_duration_buffered_notif(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_duration_buffered_notif(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, const int32_t p_duration_buffered_notif);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_duration_buffered_notif_move(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, int32_t p_duration_buffered_notif);

/* lnode helper for generating ogs_list_t nodes's of type MutingNotificationsSettings */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_muting_notifications_settings_make_lnode(data_collection_model_muting_notifications_settings_t *muting_notifications_settings);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MUTING_NOTIFICATIONS_SETTINGS_H_ */

