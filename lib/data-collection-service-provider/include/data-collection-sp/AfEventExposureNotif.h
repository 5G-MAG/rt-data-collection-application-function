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

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP AfEventExposureNotif object reference
 */
typedef struct data_collection_model_af_event_exposure_notif_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_af_event_exposure_notif_t;



/** Create a new AfEventExposureNotif
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 * @return a new AfEventExposureNotif object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_create();

/** Create a new copy of a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 * Creates a new copy of the given @a other object
 * @param other The AfEventExposureNotif to copy.
 * @return a new AfEventExposureNotif object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_create_copy(const data_collection_model_af_event_exposure_notif_t *other);

/** Create a new reference of a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 * Creates a reference to the same underlying @a other object.
 * @param other The AfEventExposureNotif to create a new reference to.
 * @return a new AfEventExposureNotif object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_create_move(data_collection_model_af_event_exposure_notif_t *other);

/** Copy the value of another AfEventExposureNotif into this object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 * Copies the value of @a other {{classname} object into @a af_event_exposure_notif.
 * @param af_event_exposure_notif The AfEventExposureNotif object to copy @a other into.
 * @param other The AfEventExposureNotif to copy the value from.
 * @return @a af_event_exposure_notif.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_copy(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const data_collection_model_af_event_exposure_notif_t *other);

/** Move the value of another AfEventExposureNotif into this object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 * Discards the current value of @a af_event_exposure_notif and moves the value of @a other
 * into @a af_event_exposure_notif. This will leave @a other as an empty reference.
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to move @a other into.
 * @param other The AfEventExposureNotif to move the value from.
 *
 * @return @a af_event_exposure_notif.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_move(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, data_collection_model_af_event_exposure_notif_t *other);

/** Delete a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 * Destroys the reference to the AfEventExposureNotif object and frees the value of AfEventExposureNotif if this is the last reference.
 *
 * @param af_event_exposure_notif The AfEventExposureNotif to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_af_event_exposure_notif_free(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif);

/** Get a cJSON tree representation of a AfEventExposureNotif
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * Create a cJSON tree representation of the AfEventExposureNotif object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param af_event_exposure_notif The AfEventExposureNotif to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_af_event_exposure_notif_toJSON(const data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, bool as_request);

/** Parse a cJSON tree into a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * Attempts to interpret a cJSON tree as a AfEventExposureNotif API request or response (dependent on @a as_request value). If successful
 * will return a new referenced AfEventExposureNotif object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new AfEventExposureNotif object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two AfEventExposureNotif objects to see if they are equivalent
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param af_event_exposure_notif The first AfEventExposureNotif object to compare.
 * @param other_af_event_exposure_notif The second AfEventExposureNotif object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_exposure_notif_is_equal_to(const data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const data_collection_model_af_event_exposure_notif_t *other_af_event_exposure_notif);



/** Get the value of the notifId field of a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to examine.
 *
 * @return the value current set for the notifId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_notif_get_notif_id(const data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif);

/** Set the value of the notifId field in a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to set the field in.
 * @param p_notif_id The value to copy into the AfEventExposureNotif object.
 *
 * @return @a af_event_exposure_notif.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_notif_id(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const char* p_notif_id);

/** Move a value to the notifId field in a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to set the field in.
 * @param p_notif_id The value to move into the AfEventExposureNotif object.
 *
 * @return @a af_event_exposure_notif.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_notif_id_move(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, char* p_notif_id);


/** Get the value of the eventNotifs field of a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to examine.
 *
 * @return the value current set for the eventNotifs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_exposure_notif_get_event_notifs(const data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif);

/** Set the value of the eventNotifs field in a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to set the field in.
 * @param p_event_notifs The value to copy into the AfEventExposureNotif object.
 *
 * @return @a af_event_exposure_notif.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_event_notifs(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const ogs_list_t* p_event_notifs);

/** Move a value to the eventNotifs field in a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to set the field in.
 * @param p_event_notifs The value to move into the AfEventExposureNotif object.
 *
 * @return @a af_event_exposure_notif.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_set_event_notifs_move(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, ogs_list_t* p_event_notifs);

/** Add a new item to the eventNotifs array in a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to add the array item to.
 * @param event_notifs The value to add.
 *
 * @return @a af_event_exposure_notif.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_add_event_notifs(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, data_collection_model_af_event_notification_t* event_notifs);

/** Remove an item from the eventNotifs array in a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to remove the array value from.
 * @param event_notifs The value to remove.
 *
 * @return @a af_event_exposure_notif.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_remove_event_notifs(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, const data_collection_model_af_event_notification_t* event_notifs);

/** Get an item from the eventNotifs array in a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_notification_t* data_collection_model_af_event_exposure_notif_get_entry_event_notifs(const data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif, size_t idx);

/** Remove all entries from the eventNotifs array in a AfEventExposureNotif object
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to empty eventNotifs for.
 *
 * @return @a af_event_exposure_notif
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_notif_t *data_collection_model_af_event_exposure_notif_clear_event_notifs(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif);

/** lnode helper for generating ogs_list_t nodes's of type AfEventExposureNotif
 * \public \memberof data_collection_model_af_event_exposure_notif_t
 *
 * Creates a new data_collection_lnode_t object containing the @a af_event_exposure_notif object.
 * The @a af_event_exposure_notif will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param af_event_exposure_notif The AfEventExposureNotif object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a af_event_exposure_notif
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_af_event_exposure_notif_make_lnode(data_collection_model_af_event_exposure_notif_t *af_event_exposure_notif);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_AF_EVENT_EXPOSURE_NOTIF_H_ */

