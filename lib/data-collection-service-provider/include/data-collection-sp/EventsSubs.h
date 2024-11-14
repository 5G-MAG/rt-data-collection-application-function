#ifndef _DATA_COLLECTION_EVENTS_SUBS_H_
#define _DATA_COLLECTION_EVENTS_SUBS_H_

/**********************************************************************************************************************************
 * EventsSubs - Public C interface to the EventsSubs object
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

#include "EventFilter.h"
#include "ReportingInformation.h"
#include "AfEvent.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP EventsSubs object reference
 */
typedef struct data_collection_model_events_subs_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_events_subs_t;



/** Create a new EventsSubs.
 * \public \memberof data_collection_model_events_subs_t
 * @return a new EventsSubs object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_create();

/** Create a new EventsSubs reference.
 * \public \memberof data_collection_model_events_subs_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The EventsSubs to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_create_ref(const data_collection_model_events_subs_t *other);

/** Create a new copy of a EventsSubs object.
 * \public \memberof data_collection_model_events_subs_t
 * Creates a new copy of the given @a other object
 * @param other The EventsSubs to copy.
 * @return a new EventsSubs object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_create_copy(const data_collection_model_events_subs_t *other);

/** Create a new reference of a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 * Creates a reference to the same underlying @a other object.
 * @param other The EventsSubs to create a new reference to.
 * @return a new EventsSubs object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_create_move(data_collection_model_events_subs_t *other);

/** Copy the value of another EventsSubs into this object
 * \public \memberof data_collection_model_events_subs_t
 * Copies the value of @a other {{classname} object into @a events_subs.
 * @param events_subs The EventsSubs object to copy @a other into.
 * @param other The EventsSubs to copy the value from.
 * @return @a events_subs.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_copy(data_collection_model_events_subs_t *events_subs, const data_collection_model_events_subs_t *other);

/** Move the value of another EventsSubs into this object
 * \public \memberof data_collection_model_events_subs_t
 * Discards the current value of @a events_subs and moves the value of @a other
 * into @a events_subs. This will leave @a other as an empty reference.
 *
 * @param events_subs The EventsSubs object to move @a other into.
 * @param other The EventsSubs to move the value from.
 *
 * @return @a events_subs.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_move(data_collection_model_events_subs_t *events_subs, data_collection_model_events_subs_t *other);

/** Delete a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 * Destroys the reference to the EventsSubs object and frees the value of EventsSubs if this is the last reference.
 *
 * @param events_subs The EventsSubs to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_events_subs_free(data_collection_model_events_subs_t *events_subs);

/** Get a cJSON tree representation of a EventsSubs
 * \public \memberof data_collection_model_events_subs_t
 *
 * Create a cJSON tree representation of the EventsSubs object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param events_subs The EventsSubs to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_events_subs_toJSON(const data_collection_model_events_subs_t *events_subs, bool as_request);

/** Parse a cJSON tree into a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 *
 * Attempts to interpret a cJSON tree as a EventsSubs API request or response (dependent on @a as_request value). If successful
 * will return a new referenced EventsSubs object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new EventsSubs object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two EventsSubs objects to see if they are equivalent
 * \public \memberof data_collection_model_events_subs_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param events_subs The first EventsSubs object to compare.
 * @param other_events_subs The second EventsSubs object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_events_subs_is_equal_to(const data_collection_model_events_subs_t *events_subs, const data_collection_model_events_subs_t *other_events_subs);



/** Get the value of the event field of a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 *
 * @param events_subs The EventsSubs object to examine.
 *
 * @return the value current set for the event field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_t* data_collection_model_events_subs_get_event(const data_collection_model_events_subs_t *events_subs);

/** Set the value of the event field in a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 *
 * @param events_subs The EventsSubs object to set the field in.
 * @param p_event The value to copy into the EventsSubs object.
 *
 * @return @a events_subs.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event(data_collection_model_events_subs_t *events_subs, const data_collection_model_af_event_t* p_event);

/** Move a value to the event field in a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 *
 * @param events_subs The EventsSubs object to set the field in.
 * @param p_event The value to move into the EventsSubs object.
 *
 * @return @a events_subs.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_move(data_collection_model_events_subs_t *events_subs, data_collection_model_af_event_t* p_event);


/** Get the value of the eventFilter field of a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 *
 * @param events_subs The EventsSubs object to examine.
 *
 * @return the value current set for the eventFilter field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_filter_t* data_collection_model_events_subs_get_event_filter(const data_collection_model_events_subs_t *events_subs);

/** Set the value of the eventFilter field in a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 *
 * @param events_subs The EventsSubs object to set the field in.
 * @param p_event_filter The value to copy into the EventsSubs object.
 *
 * @return @a events_subs.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_filter(data_collection_model_events_subs_t *events_subs, const data_collection_model_event_filter_t* p_event_filter);

/** Move a value to the eventFilter field in a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 *
 * @param events_subs The EventsSubs object to set the field in.
 * @param p_event_filter The value to move into the EventsSubs object.
 *
 * @return @a events_subs.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_filter_move(data_collection_model_events_subs_t *events_subs, data_collection_model_event_filter_t* p_event_filter);

/** Check if the eventRepInfo field of a EventsSubs object is set
 * \public \memberof data_collection_model_events_subs_t
 *
 * @param events_subs The EventsSubs object to examine.
 *
 * @return `true` if the optional eventRepInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_events_subs_has_event_rep_info(const data_collection_model_events_subs_t *events_subs);


/** Get the value of the eventRepInfo field of a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 *
 * @param events_subs The EventsSubs object to examine.
 *
 * @return the value current set for the eventRepInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_reporting_information_t* data_collection_model_events_subs_get_event_rep_info(const data_collection_model_events_subs_t *events_subs);

/** Set the value of the eventRepInfo field in a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 *
 * @param events_subs The EventsSubs object to set the field in.
 * @param p_event_rep_info The value to copy into the EventsSubs object.
 *
 * @return @a events_subs.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_rep_info(data_collection_model_events_subs_t *events_subs, const data_collection_model_reporting_information_t* p_event_rep_info);

/** Move a value to the eventRepInfo field in a EventsSubs object
 * \public \memberof data_collection_model_events_subs_t
 *
 * @param events_subs The EventsSubs object to set the field in.
 * @param p_event_rep_info The value to move into the EventsSubs object.
 *
 * @return @a events_subs.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_events_subs_t *data_collection_model_events_subs_set_event_rep_info_move(data_collection_model_events_subs_t *events_subs, data_collection_model_reporting_information_t* p_event_rep_info);

/** lnode helper for generating ogs_list_t nodes's of type EventsSubs
 * \public \memberof data_collection_model_events_subs_t
 *
 * Creates a new data_collection_lnode_t object containing the @a events_subs object.
 * The @a events_subs will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param events_subs The EventsSubs object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a events_subs
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_events_subs_make_lnode(data_collection_model_events_subs_t *events_subs);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_EVENTS_SUBS_H_ */

