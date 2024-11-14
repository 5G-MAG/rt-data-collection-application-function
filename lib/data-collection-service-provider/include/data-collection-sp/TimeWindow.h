#ifndef _DATA_COLLECTION_TIME_WINDOW_H_
#define _DATA_COLLECTION_TIME_WINDOW_H_

/**********************************************************************************************************************************
 * TimeWindow - Public C interface to the TimeWindow object
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

/** A 3GPP TimeWindow object reference
 */
typedef struct data_collection_model_time_window_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_time_window_t;



/** Create a new TimeWindow.
 * \public \memberof data_collection_model_time_window_t
 * @return a new TimeWindow object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_create();

/** Create a new TimeWindow reference.
 * \public \memberof data_collection_model_time_window_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The TimeWindow to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_create_ref(const data_collection_model_time_window_t *other);

/** Create a new copy of a TimeWindow object.
 * \public \memberof data_collection_model_time_window_t
 * Creates a new copy of the given @a other object
 * @param other The TimeWindow to copy.
 * @return a new TimeWindow object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_create_copy(const data_collection_model_time_window_t *other);

/** Create a new reference of a TimeWindow object
 * \public \memberof data_collection_model_time_window_t
 * Creates a reference to the same underlying @a other object.
 * @param other The TimeWindow to create a new reference to.
 * @return a new TimeWindow object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_create_move(data_collection_model_time_window_t *other);

/** Copy the value of another TimeWindow into this object
 * \public \memberof data_collection_model_time_window_t
 * Copies the value of @a other {{classname} object into @a time_window.
 * @param time_window The TimeWindow object to copy @a other into.
 * @param other The TimeWindow to copy the value from.
 * @return @a time_window.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_copy(data_collection_model_time_window_t *time_window, const data_collection_model_time_window_t *other);

/** Move the value of another TimeWindow into this object
 * \public \memberof data_collection_model_time_window_t
 * Discards the current value of @a time_window and moves the value of @a other
 * into @a time_window. This will leave @a other as an empty reference.
 *
 * @param time_window The TimeWindow object to move @a other into.
 * @param other The TimeWindow to move the value from.
 *
 * @return @a time_window.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_move(data_collection_model_time_window_t *time_window, data_collection_model_time_window_t *other);

/** Delete a TimeWindow object
 * \public \memberof data_collection_model_time_window_t
 * Destroys the reference to the TimeWindow object and frees the value of TimeWindow if this is the last reference.
 *
 * @param time_window The TimeWindow to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_time_window_free(data_collection_model_time_window_t *time_window);

/** Get a cJSON tree representation of a TimeWindow
 * \public \memberof data_collection_model_time_window_t
 *
 * Create a cJSON tree representation of the TimeWindow object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param time_window The TimeWindow to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_time_window_toJSON(const data_collection_model_time_window_t *time_window, bool as_request);

/** Parse a cJSON tree into a TimeWindow object
 * \public \memberof data_collection_model_time_window_t
 *
 * Attempts to interpret a cJSON tree as a TimeWindow API request or response (dependent on @a as_request value). If successful
 * will return a new referenced TimeWindow object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new TimeWindow object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two TimeWindow objects to see if they are equivalent
 * \public \memberof data_collection_model_time_window_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param time_window The first TimeWindow object to compare.
 * @param other_time_window The second TimeWindow object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_time_window_is_equal_to(const data_collection_model_time_window_t *time_window, const data_collection_model_time_window_t *other_time_window);



/** Get the value of the startTime field of a TimeWindow object
 * \public \memberof data_collection_model_time_window_t
 *
 * @param time_window The TimeWindow object to examine.
 *
 * @return the value current set for the startTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_time_window_get_start_time(const data_collection_model_time_window_t *time_window);

/** Set the value of the startTime field in a TimeWindow object
 * \public \memberof data_collection_model_time_window_t
 *
 * @param time_window The TimeWindow object to set the field in.
 * @param p_start_time The value to copy into the TimeWindow object.
 *
 * @return @a time_window.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_set_start_time(data_collection_model_time_window_t *time_window, const char* p_start_time);

/** Move a value to the startTime field in a TimeWindow object
 * \public \memberof data_collection_model_time_window_t
 *
 * @param time_window The TimeWindow object to set the field in.
 * @param p_start_time The value to move into the TimeWindow object.
 *
 * @return @a time_window.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_set_start_time_move(data_collection_model_time_window_t *time_window, char* p_start_time);


/** Get the value of the stopTime field of a TimeWindow object
 * \public \memberof data_collection_model_time_window_t
 *
 * @param time_window The TimeWindow object to examine.
 *
 * @return the value current set for the stopTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_time_window_get_stop_time(const data_collection_model_time_window_t *time_window);

/** Set the value of the stopTime field in a TimeWindow object
 * \public \memberof data_collection_model_time_window_t
 *
 * @param time_window The TimeWindow object to set the field in.
 * @param p_stop_time The value to copy into the TimeWindow object.
 *
 * @return @a time_window.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_set_stop_time(data_collection_model_time_window_t *time_window, const char* p_stop_time);

/** Move a value to the stopTime field in a TimeWindow object
 * \public \memberof data_collection_model_time_window_t
 *
 * @param time_window The TimeWindow object to set the field in.
 * @param p_stop_time The value to move into the TimeWindow object.
 *
 * @return @a time_window.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_time_window_t *data_collection_model_time_window_set_stop_time_move(data_collection_model_time_window_t *time_window, char* p_stop_time);

/** lnode helper for generating ogs_list_t nodes's of type TimeWindow
 * \public \memberof data_collection_model_time_window_t
 *
 * Creates a new data_collection_lnode_t object containing the @a time_window object.
 * The @a time_window will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param time_window The TimeWindow object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a time_window
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_time_window_make_lnode(data_collection_model_time_window_t *time_window);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_TIME_WINDOW_H_ */

