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

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP AfEventExposureSubsc object reference
 */
typedef struct data_collection_model_af_event_exposure_subsc_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_af_event_exposure_subsc_t;



/** Create a new AfEventExposureSubsc.
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 * @return a new AfEventExposureSubsc object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_create();

/** Create a new AfEventExposureSubsc reference.
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The AfEventExposureSubsc to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_create_ref(const data_collection_model_af_event_exposure_subsc_t *other);

/** Create a new copy of a AfEventExposureSubsc object.
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 * Creates a new copy of the given @a other object
 * @param other The AfEventExposureSubsc to copy.
 * @return a new AfEventExposureSubsc object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_create_copy(const data_collection_model_af_event_exposure_subsc_t *other);

/** Create a new reference of a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 * Creates a reference to the same underlying @a other object.
 * @param other The AfEventExposureSubsc to create a new reference to.
 * @return a new AfEventExposureSubsc object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_create_move(data_collection_model_af_event_exposure_subsc_t *other);

/** Copy the value of another AfEventExposureSubsc into this object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 * Copies the value of @a other {{classname} object into @a af_event_exposure_subsc.
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to copy @a other into.
 * @param other The AfEventExposureSubsc to copy the value from.
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_copy(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_af_event_exposure_subsc_t *other);

/** Move the value of another AfEventExposureSubsc into this object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 * Discards the current value of @a af_event_exposure_subsc and moves the value of @a other
 * into @a af_event_exposure_subsc. This will leave @a other as an empty reference.
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to move @a other into.
 * @param other The AfEventExposureSubsc to move the value from.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, data_collection_model_af_event_exposure_subsc_t *other);

/** Delete a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 * Destroys the reference to the AfEventExposureSubsc object and frees the value of AfEventExposureSubsc if this is the last reference.
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_af_event_exposure_subsc_free(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/** Get a cJSON tree representation of a AfEventExposureSubsc
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * Create a cJSON tree representation of the AfEventExposureSubsc object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_af_event_exposure_subsc_toJSON(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, bool as_request);

/** Parse a cJSON tree into a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * Attempts to interpret a cJSON tree as a AfEventExposureSubsc API request or response (dependent on @a as_request value). If successful
 * will return a new referenced AfEventExposureSubsc object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new AfEventExposureSubsc object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two AfEventExposureSubsc objects to see if they are equivalent
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param af_event_exposure_subsc The first AfEventExposureSubsc object to compare.
 * @param other_af_event_exposure_subsc The second AfEventExposureSubsc object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_exposure_subsc_is_equal_to(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_af_event_exposure_subsc_t *other_af_event_exposure_subsc);


/** Check if the dataAccProfId field of a AfEventExposureSubsc object is set
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 *
 * @return `true` if the optional dataAccProfId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_exposure_subsc_has_data_acc_prof_id(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);


/** Get the value of the dataAccProfId field of a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 *
 * @return the value current set for the dataAccProfId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_data_acc_prof_id(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/** Set the value of the dataAccProfId field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_data_acc_prof_id The value to copy into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_data_acc_prof_id(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const char* p_data_acc_prof_id);

/** Move a value to the dataAccProfId field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_data_acc_prof_id The value to move into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_data_acc_prof_id_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, char* p_data_acc_prof_id);


/** Get the value of the eventsSubs field of a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 *
 * @return the value current set for the eventsSubs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_exposure_subsc_get_events_subs(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/** Set the value of the eventsSubs field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_events_subs The value to copy into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_subs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const ogs_list_t* p_events_subs);

/** Move a value to the eventsSubs field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_events_subs The value to move into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_subs_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, ogs_list_t* p_events_subs);

/** Add a new item to the eventsSubs array in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to add the array item to.
 * @param events_subs The value to add.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_add_events_subs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, data_collection_model_events_subs_t* events_subs);

/** Remove an item from the eventsSubs array in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to remove the array value from.
 * @param events_subs The value to remove.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_remove_events_subs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_events_subs_t* events_subs);

/** Get an item from the eventsSubs array in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_events_subs_t* data_collection_model_af_event_exposure_subsc_get_entry_events_subs(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, size_t idx);

/** Remove all entries from the eventsSubs array in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to empty eventsSubs for.
 *
 * @return @a af_event_exposure_subsc
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_clear_events_subs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);


/** Get the value of the eventsRepInfo field of a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 *
 * @return the value current set for the eventsRepInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_reporting_information_t* data_collection_model_af_event_exposure_subsc_get_events_rep_info(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/** Set the value of the eventsRepInfo field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_events_rep_info The value to copy into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_rep_info(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_reporting_information_t* p_events_rep_info);

/** Move a value to the eventsRepInfo field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_events_rep_info The value to move into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_events_rep_info_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, data_collection_model_reporting_information_t* p_events_rep_info);


/** Get the value of the notifUri field of a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 *
 * @return the value current set for the notifUri field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_notif_uri(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/** Set the value of the notifUri field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_notif_uri The value to copy into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_uri(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const char* p_notif_uri);

/** Move a value to the notifUri field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_notif_uri The value to move into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_uri_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, char* p_notif_uri);


/** Get the value of the notifId field of a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 *
 * @return the value current set for the notifId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_notif_id(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/** Set the value of the notifId field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_notif_id The value to copy into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_id(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const char* p_notif_id);

/** Move a value to the notifId field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_notif_id The value to move into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_notif_id_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, char* p_notif_id);

/** Check if the eventNotifs field of a AfEventExposureSubsc object is set
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 *
 * @return `true` if the optional eventNotifs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_exposure_subsc_has_event_notifs(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);


/** Get the value of the eventNotifs field of a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 *
 * @return the value current set for the eventNotifs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_exposure_subsc_get_event_notifs(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/** Set the value of the eventNotifs field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_event_notifs The value to copy into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_event_notifs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const ogs_list_t* p_event_notifs);

/** Move a value to the eventNotifs field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_event_notifs The value to move into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_event_notifs_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, ogs_list_t* p_event_notifs);

/** Add a new item to the eventNotifs array in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to add the array item to.
 * @param event_notifs The value to add.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_add_event_notifs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, data_collection_model_af_event_notification_t* event_notifs);

/** Remove an item from the eventNotifs array in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to remove the array value from.
 * @param event_notifs The value to remove.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_remove_event_notifs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const data_collection_model_af_event_notification_t* event_notifs);

/** Get an item from the eventNotifs array in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_notification_t* data_collection_model_af_event_exposure_subsc_get_entry_event_notifs(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, size_t idx);

/** Remove all entries from the eventNotifs array in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to empty eventNotifs for.
 *
 * @return @a af_event_exposure_subsc
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_clear_event_notifs(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/** Check if the suppFeat field of a AfEventExposureSubsc object is set
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 *
 * @return `true` if the optional suppFeat field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_exposure_subsc_has_supp_feat(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);


/** Get the value of the suppFeat field of a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to examine.
 *
 * @return the value current set for the suppFeat field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_exposure_subsc_get_supp_feat(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/** Set the value of the suppFeat field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_supp_feat The value to copy into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_supp_feat(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, const char* p_supp_feat);

/** Move a value to the suppFeat field in a AfEventExposureSubsc object
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to set the field in.
 * @param p_supp_feat The value to move into the AfEventExposureSubsc object.
 *
 * @return @a af_event_exposure_subsc.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_exposure_subsc_t *data_collection_model_af_event_exposure_subsc_set_supp_feat_move(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, char* p_supp_feat);

/** lnode helper for generating ogs_list_t nodes's of type AfEventExposureSubsc
 * \public \memberof data_collection_model_af_event_exposure_subsc_t
 *
 * Creates a new data_collection_lnode_t object containing the @a af_event_exposure_subsc object.
 * The @a af_event_exposure_subsc will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param af_event_exposure_subsc The AfEventExposureSubsc object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a af_event_exposure_subsc
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_af_event_exposure_subsc_make_lnode(data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_AF_EVENT_EXPOSURE_SUBSC_H_ */

