#ifndef _DATA_COLLECTION_PERIODIC_EVENT_INFO_H_
#define _DATA_COLLECTION_PERIODIC_EVENT_INFO_H_

/**********************************************************************************************************************************
 * PeriodicEventInfo - Public C interface to the PeriodicEventInfo object
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

/** A 3GPP PeriodicEventInfo object reference
 */
typedef struct data_collection_model_periodic_event_info_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_periodic_event_info_t;



/** Create a new PeriodicEventInfo.
 * \public \memberof data_collection_model_periodic_event_info_t
 * @return a new PeriodicEventInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create();

/** Create a new PeriodicEventInfo reference.
 * \public \memberof data_collection_model_periodic_event_info_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The PeriodicEventInfo to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create_ref(const data_collection_model_periodic_event_info_t *other);

/** Create a new copy of a PeriodicEventInfo object.
 * \public \memberof data_collection_model_periodic_event_info_t
 * Creates a new copy of the given @a other object
 * @param other The PeriodicEventInfo to copy.
 * @return a new PeriodicEventInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create_copy(const data_collection_model_periodic_event_info_t *other);

/** Create a new reference of a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PeriodicEventInfo to create a new reference to.
 * @return a new PeriodicEventInfo object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_create_move(data_collection_model_periodic_event_info_t *other);

/** Copy the value of another PeriodicEventInfo into this object
 * \public \memberof data_collection_model_periodic_event_info_t
 * Copies the value of @a other {{classname} object into @a periodic_event_info.
 * @param periodic_event_info The PeriodicEventInfo object to copy @a other into.
 * @param other The PeriodicEventInfo to copy the value from.
 * @return @a periodic_event_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_copy(data_collection_model_periodic_event_info_t *periodic_event_info, const data_collection_model_periodic_event_info_t *other);

/** Move the value of another PeriodicEventInfo into this object
 * \public \memberof data_collection_model_periodic_event_info_t
 * Discards the current value of @a periodic_event_info and moves the value of @a other
 * into @a periodic_event_info. This will leave @a other as an empty reference.
 *
 * @param periodic_event_info The PeriodicEventInfo object to move @a other into.
 * @param other The PeriodicEventInfo to move the value from.
 *
 * @return @a periodic_event_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_move(data_collection_model_periodic_event_info_t *periodic_event_info, data_collection_model_periodic_event_info_t *other);

/** Delete a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 * Destroys the reference to the PeriodicEventInfo object and frees the value of PeriodicEventInfo if this is the last reference.
 *
 * @param periodic_event_info The PeriodicEventInfo to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_periodic_event_info_free(data_collection_model_periodic_event_info_t *periodic_event_info);

/** Get a cJSON tree representation of a PeriodicEventInfo
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * Create a cJSON tree representation of the PeriodicEventInfo object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param periodic_event_info The PeriodicEventInfo to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_periodic_event_info_toJSON(const data_collection_model_periodic_event_info_t *periodic_event_info, bool as_request);

/** Parse a cJSON tree into a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * Attempts to interpret a cJSON tree as a PeriodicEventInfo API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PeriodicEventInfo object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PeriodicEventInfo object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PeriodicEventInfo objects to see if they are equivalent
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param periodic_event_info The first PeriodicEventInfo object to compare.
 * @param other_periodic_event_info The second PeriodicEventInfo object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_periodic_event_info_is_equal_to(const data_collection_model_periodic_event_info_t *periodic_event_info, const data_collection_model_periodic_event_info_t *other_periodic_event_info);



/** Get the value of the reportingAmount field of a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to examine.
 *
 * @return the value current set for the reportingAmount field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_periodic_event_info_get_reporting_amount(const data_collection_model_periodic_event_info_t *periodic_event_info);

/** Set the value of the reportingAmount field in a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to set the field in.
 * @param p_reporting_amount The value to copy into the PeriodicEventInfo object.
 *
 * @return @a periodic_event_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_amount(data_collection_model_periodic_event_info_t *periodic_event_info, const int32_t p_reporting_amount);

/** Move a value to the reportingAmount field in a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to set the field in.
 * @param p_reporting_amount The value to move into the PeriodicEventInfo object.
 *
 * @return @a periodic_event_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_amount_move(data_collection_model_periodic_event_info_t *periodic_event_info, int32_t p_reporting_amount);


/** Get the value of the reportingInterval field of a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to examine.
 *
 * @return the value current set for the reportingInterval field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_periodic_event_info_get_reporting_interval(const data_collection_model_periodic_event_info_t *periodic_event_info);

/** Set the value of the reportingInterval field in a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to set the field in.
 * @param p_reporting_interval The value to copy into the PeriodicEventInfo object.
 *
 * @return @a periodic_event_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval(data_collection_model_periodic_event_info_t *periodic_event_info, const int32_t p_reporting_interval);

/** Move a value to the reportingInterval field in a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to set the field in.
 * @param p_reporting_interval The value to move into the PeriodicEventInfo object.
 *
 * @return @a periodic_event_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_move(data_collection_model_periodic_event_info_t *periodic_event_info, int32_t p_reporting_interval);

/** Check if the reportingInfiniteInd field of a PeriodicEventInfo object is set
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to examine.
 *
 * @return `true` if the optional reportingInfiniteInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_periodic_event_info_has_reporting_infinite_ind(const data_collection_model_periodic_event_info_t *periodic_event_info);


/** Get the value of the reportingInfiniteInd field of a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to examine.
 *
 * @return the value current set for the reportingInfiniteInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_periodic_event_info_is_reporting_infinite_ind(const data_collection_model_periodic_event_info_t *periodic_event_info);

/** Set the value of the reportingInfiniteInd field in a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to set the field in.
 * @param p_reporting_infinite_ind The value to copy into the PeriodicEventInfo object.
 *
 * @return @a periodic_event_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_infinite_ind(data_collection_model_periodic_event_info_t *periodic_event_info, const bool p_reporting_infinite_ind);

/** Move a value to the reportingInfiniteInd field in a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to set the field in.
 * @param p_reporting_infinite_ind The value to move into the PeriodicEventInfo object.
 *
 * @return @a periodic_event_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_infinite_ind_move(data_collection_model_periodic_event_info_t *periodic_event_info, bool p_reporting_infinite_ind);

/** Check if the reportingIntervalMs field of a PeriodicEventInfo object is set
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to examine.
 *
 * @return `true` if the optional reportingIntervalMs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_periodic_event_info_has_reporting_interval_ms(const data_collection_model_periodic_event_info_t *periodic_event_info);


/** Get the value of the reportingIntervalMs field of a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to examine.
 *
 * @return the value current set for the reportingIntervalMs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_periodic_event_info_get_reporting_interval_ms(const data_collection_model_periodic_event_info_t *periodic_event_info);

/** Set the value of the reportingIntervalMs field in a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to set the field in.
 * @param p_reporting_interval_ms The value to copy into the PeriodicEventInfo object.
 *
 * @return @a periodic_event_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_ms(data_collection_model_periodic_event_info_t *periodic_event_info, const int32_t p_reporting_interval_ms);

/** Move a value to the reportingIntervalMs field in a PeriodicEventInfo object
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * @param periodic_event_info The PeriodicEventInfo object to set the field in.
 * @param p_reporting_interval_ms The value to move into the PeriodicEventInfo object.
 *
 * @return @a periodic_event_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_periodic_event_info_t *data_collection_model_periodic_event_info_set_reporting_interval_ms_move(data_collection_model_periodic_event_info_t *periodic_event_info, int32_t p_reporting_interval_ms);

/** lnode helper for generating ogs_list_t nodes's of type PeriodicEventInfo
 * \public \memberof data_collection_model_periodic_event_info_t
 *
 * Creates a new data_collection_lnode_t object containing the @a periodic_event_info object.
 * The @a periodic_event_info will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param periodic_event_info The PeriodicEventInfo object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a periodic_event_info
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_periodic_event_info_make_lnode(data_collection_model_periodic_event_info_t *periodic_event_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PERIODIC_EVENT_INFO_H_ */

