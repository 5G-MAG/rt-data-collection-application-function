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


/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP MutingNotificationsSettings object reference
 */
typedef struct data_collection_model_muting_notifications_settings_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_muting_notifications_settings_t;



/** Create a new MutingNotificationsSettings
 * \public \memberof data_collection_model_muting_notifications_settings_t
 * @return a new MutingNotificationsSettings object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create();

/** Create a new copy of a MutingNotificationsSettings object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 * Creates a new copy of the given @a other object
 * @param other The MutingNotificationsSettings to copy.
 * @return a new MutingNotificationsSettings object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create_copy(const data_collection_model_muting_notifications_settings_t *other);

/** Create a new reference of a MutingNotificationsSettings object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MutingNotificationsSettings to create a new reference to.
 * @return a new MutingNotificationsSettings object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_create_move(data_collection_model_muting_notifications_settings_t *other);

/** Copy the value of another MutingNotificationsSettings into this object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 * Copies the value of @a other {{classname} object into @a muting_notifications_settings.
 * @param muting_notifications_settings The MutingNotificationsSettings object to copy @a other into.
 * @param other The MutingNotificationsSettings to copy the value from.
 * @return @a muting_notifications_settings.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_copy(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, const data_collection_model_muting_notifications_settings_t *other);

/** Move the value of another MutingNotificationsSettings into this object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 * Discards the current value of @a muting_notifications_settings and moves the value of @a other
 * into @a muting_notifications_settings. This will leave @a other as an empty reference.
 *
 * @param muting_notifications_settings The MutingNotificationsSettings object to move @a other into.
 * @param other The MutingNotificationsSettings to move the value from.
 *
 * @return @a muting_notifications_settings.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_move(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, data_collection_model_muting_notifications_settings_t *other);

/** Delete a MutingNotificationsSettings object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 * Destroys the reference to the MutingNotificationsSettings object and frees the value of MutingNotificationsSettings if this is the last reference.
 *
 * @param muting_notifications_settings The MutingNotificationsSettings to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_muting_notifications_settings_free(data_collection_model_muting_notifications_settings_t *muting_notifications_settings);

/** Get a cJSON tree representation of a MutingNotificationsSettings
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * Create a cJSON tree representation of the MutingNotificationsSettings object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param muting_notifications_settings The MutingNotificationsSettings to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_muting_notifications_settings_toJSON(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings, bool as_request);

/** Parse a cJSON tree into a MutingNotificationsSettings object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * Attempts to interpret a cJSON tree as a MutingNotificationsSettings API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MutingNotificationsSettings object containing the value represented by the cJSON tree. On failure will return
 * `NULL` and will set @a error_reason, @a error_class and @a error_parameter output parameters to indicate the reason for the
 * failure. The @a error_reason, @a error_class and @a error_parameter strings must be freed using ogs_free().
 *
 * @param json The cJSON tree object to interpret.
 * @param as_request `true` to interpret the @a json as an API request or `false` for interpretation as an API response.
 * @param[out] error_reason On failure will be set to a new nul terminated string indicating the reason for the failure.
 * @param[out] error_class On failure will be set to the class name of the object where the failure happened if available or `NULL`.
 * @param[out] error_parameter On failure will be set to the JSON path of the field where the failure happened if available or
                               `NULL`.
 *
 * @return a new MutingNotificationsSettings object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MutingNotificationsSettings objects to see if they are equivalent
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param muting_notifications_settings The first MutingNotificationsSettings object to compare.
 * @param other_muting_notifications_settings The second MutingNotificationsSettings object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_muting_notifications_settings_is_equal_to(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings, const data_collection_model_muting_notifications_settings_t *other_muting_notifications_settings);


/** Check if the maxNoOfNotif field of a MutingNotificationsSettings object is set
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * @param muting_notifications_settings The MutingNotificationsSettings object to examine.
 *
 * @return `true` if the optional maxNoOfNotif field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_muting_notifications_settings_has_max_no_of_notif(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings);


/** Get the value of the maxNoOfNotif field of a MutingNotificationsSettings object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * @param muting_notifications_settings The MutingNotificationsSettings object to examine.
 *
 * @return the value current set for the maxNoOfNotif field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_muting_notifications_settings_get_max_no_of_notif(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings);

/** Set the value of the maxNoOfNotif field in a MutingNotificationsSettings object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * @param muting_notifications_settings The MutingNotificationsSettings object to set the field in.
 * @param p_max_no_of_notif The value to copy into the MutingNotificationsSettings object.
 *
 * @return @a muting_notifications_settings.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_max_no_of_notif(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, const int32_t p_max_no_of_notif);

/** Move a value to the maxNoOfNotif field in a MutingNotificationsSettings object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * @param muting_notifications_settings The MutingNotificationsSettings object to set the field in.
 * @param p_max_no_of_notif The value to move into the MutingNotificationsSettings object.
 *
 * @return @a muting_notifications_settings.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_max_no_of_notif_move(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, int32_t p_max_no_of_notif);

/** Check if the durationBufferedNotif field of a MutingNotificationsSettings object is set
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * @param muting_notifications_settings The MutingNotificationsSettings object to examine.
 *
 * @return `true` if the optional durationBufferedNotif field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_muting_notifications_settings_has_duration_buffered_notif(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings);


/** Get the value of the durationBufferedNotif field of a MutingNotificationsSettings object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * @param muting_notifications_settings The MutingNotificationsSettings object to examine.
 *
 * @return the value current set for the durationBufferedNotif field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_muting_notifications_settings_get_duration_buffered_notif(const data_collection_model_muting_notifications_settings_t *muting_notifications_settings);

/** Set the value of the durationBufferedNotif field in a MutingNotificationsSettings object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * @param muting_notifications_settings The MutingNotificationsSettings object to set the field in.
 * @param p_duration_buffered_notif The value to copy into the MutingNotificationsSettings object.
 *
 * @return @a muting_notifications_settings.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_duration_buffered_notif(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, const int32_t p_duration_buffered_notif);

/** Move a value to the durationBufferedNotif field in a MutingNotificationsSettings object
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * @param muting_notifications_settings The MutingNotificationsSettings object to set the field in.
 * @param p_duration_buffered_notif The value to move into the MutingNotificationsSettings object.
 *
 * @return @a muting_notifications_settings.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_notifications_settings_t *data_collection_model_muting_notifications_settings_set_duration_buffered_notif_move(data_collection_model_muting_notifications_settings_t *muting_notifications_settings, int32_t p_duration_buffered_notif);

/** lnode helper for generating ogs_list_t nodes's of type MutingNotificationsSettings
 * \public \memberof data_collection_model_muting_notifications_settings_t
 *
 * Creates a new data_collection_lnode_t object containing the @a muting_notifications_settings object.
 * The @a muting_notifications_settings will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param muting_notifications_settings The MutingNotificationsSettings object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a muting_notifications_settings
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_muting_notifications_settings_make_lnode(data_collection_model_muting_notifications_settings_t *muting_notifications_settings);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MUTING_NOTIFICATIONS_SETTINGS_H_ */

