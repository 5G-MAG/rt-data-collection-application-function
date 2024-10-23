#ifndef _DATA_COLLECTION_USAGE_THRESHOLD_H_
#define _DATA_COLLECTION_USAGE_THRESHOLD_H_

/**********************************************************************************************************************************
 * UsageThreshold - Public C interface to the UsageThreshold object
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

/** A 3GPP UsageThreshold object reference
 */
typedef struct data_collection_model_usage_threshold_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_usage_threshold_t;



/** Create a new UsageThreshold
 * \public \memberof data_collection_model_usage_threshold_t
 * @return a new UsageThreshold object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_create();

/** Create a new copy of a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 * Creates a new copy of the given @a other object
 * @param other The UsageThreshold to copy.
 * @return a new UsageThreshold object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_create_copy(const data_collection_model_usage_threshold_t *other);

/** Create a new reference of a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 * Creates a reference to the same underlying @a other object.
 * @param other The UsageThreshold to create a new reference to.
 * @return a new UsageThreshold object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_create_move(data_collection_model_usage_threshold_t *other);

/** Copy the value of another UsageThreshold into this object
 * \public \memberof data_collection_model_usage_threshold_t
 * Copies the value of @a other {{classname} object into @a usage_threshold.
 * @param usage_threshold The UsageThreshold object to copy @a other into.
 * @param other The UsageThreshold to copy the value from.
 * @return @a usage_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_copy(data_collection_model_usage_threshold_t *usage_threshold, const data_collection_model_usage_threshold_t *other);

/** Move the value of another UsageThreshold into this object
 * \public \memberof data_collection_model_usage_threshold_t
 * Discards the current value of @a usage_threshold and moves the value of @a other
 * into @a usage_threshold. This will leave @a other as an empty reference.
 *
 * @param usage_threshold The UsageThreshold object to move @a other into.
 * @param other The UsageThreshold to move the value from.
 *
 * @return @a usage_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_move(data_collection_model_usage_threshold_t *usage_threshold, data_collection_model_usage_threshold_t *other);

/** Delete a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 * Destroys the reference to the UsageThreshold object and frees the value of UsageThreshold if this is the last reference.
 *
 * @param usage_threshold The UsageThreshold to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_usage_threshold_free(data_collection_model_usage_threshold_t *usage_threshold);

/** Get a cJSON tree representation of a UsageThreshold
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * Create a cJSON tree representation of the UsageThreshold object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param usage_threshold The UsageThreshold to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_usage_threshold_toJSON(const data_collection_model_usage_threshold_t *usage_threshold, bool as_request);

/** Parse a cJSON tree into a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * Attempts to interpret a cJSON tree as a UsageThreshold API request or response (dependent on @a as_request value). If successful
 * will return a new referenced UsageThreshold object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new UsageThreshold object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two UsageThreshold objects to see if they are equivalent
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param usage_threshold The first UsageThreshold object to compare.
 * @param other_usage_threshold The second UsageThreshold object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_threshold_is_equal_to(const data_collection_model_usage_threshold_t *usage_threshold, const data_collection_model_usage_threshold_t *other_usage_threshold);


/** Check if the duration field of a UsageThreshold object is set
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to examine.
 *
 * @return `true` if the optional duration field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_threshold_has_duration(const data_collection_model_usage_threshold_t *usage_threshold);


/** Get the value of the duration field of a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to examine.
 *
 * @return the value current set for the duration field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_usage_threshold_get_duration(const data_collection_model_usage_threshold_t *usage_threshold);

/** Set the value of the duration field in a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to set the field in.
 * @param p_duration The value to copy into the UsageThreshold object.
 *
 * @return @a usage_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_duration(data_collection_model_usage_threshold_t *usage_threshold, const int32_t p_duration);

/** Move a value to the duration field in a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to set the field in.
 * @param p_duration The value to move into the UsageThreshold object.
 *
 * @return @a usage_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_duration_move(data_collection_model_usage_threshold_t *usage_threshold, int32_t p_duration);

/** Check if the totalVolume field of a UsageThreshold object is set
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to examine.
 *
 * @return `true` if the optional totalVolume field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_threshold_has_total_volume(const data_collection_model_usage_threshold_t *usage_threshold);


/** Get the value of the totalVolume field of a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to examine.
 *
 * @return the value current set for the totalVolume field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_usage_threshold_get_total_volume(const data_collection_model_usage_threshold_t *usage_threshold);

/** Set the value of the totalVolume field in a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to set the field in.
 * @param p_total_volume The value to copy into the UsageThreshold object.
 *
 * @return @a usage_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_total_volume(data_collection_model_usage_threshold_t *usage_threshold, const int64_t p_total_volume);

/** Move a value to the totalVolume field in a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to set the field in.
 * @param p_total_volume The value to move into the UsageThreshold object.
 *
 * @return @a usage_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_total_volume_move(data_collection_model_usage_threshold_t *usage_threshold, int64_t p_total_volume);

/** Check if the downlinkVolume field of a UsageThreshold object is set
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to examine.
 *
 * @return `true` if the optional downlinkVolume field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_threshold_has_downlink_volume(const data_collection_model_usage_threshold_t *usage_threshold);


/** Get the value of the downlinkVolume field of a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to examine.
 *
 * @return the value current set for the downlinkVolume field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_usage_threshold_get_downlink_volume(const data_collection_model_usage_threshold_t *usage_threshold);

/** Set the value of the downlinkVolume field in a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to set the field in.
 * @param p_downlink_volume The value to copy into the UsageThreshold object.
 *
 * @return @a usage_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_downlink_volume(data_collection_model_usage_threshold_t *usage_threshold, const int64_t p_downlink_volume);

/** Move a value to the downlinkVolume field in a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to set the field in.
 * @param p_downlink_volume The value to move into the UsageThreshold object.
 *
 * @return @a usage_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_downlink_volume_move(data_collection_model_usage_threshold_t *usage_threshold, int64_t p_downlink_volume);

/** Check if the uplinkVolume field of a UsageThreshold object is set
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to examine.
 *
 * @return `true` if the optional uplinkVolume field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_threshold_has_uplink_volume(const data_collection_model_usage_threshold_t *usage_threshold);


/** Get the value of the uplinkVolume field of a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to examine.
 *
 * @return the value current set for the uplinkVolume field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_usage_threshold_get_uplink_volume(const data_collection_model_usage_threshold_t *usage_threshold);

/** Set the value of the uplinkVolume field in a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to set the field in.
 * @param p_uplink_volume The value to copy into the UsageThreshold object.
 *
 * @return @a usage_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_uplink_volume(data_collection_model_usage_threshold_t *usage_threshold, const int64_t p_uplink_volume);

/** Move a value to the uplinkVolume field in a UsageThreshold object
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * @param usage_threshold The UsageThreshold object to set the field in.
 * @param p_uplink_volume The value to move into the UsageThreshold object.
 *
 * @return @a usage_threshold.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_threshold_t *data_collection_model_usage_threshold_set_uplink_volume_move(data_collection_model_usage_threshold_t *usage_threshold, int64_t p_uplink_volume);

/** lnode helper for generating ogs_list_t nodes's of type UsageThreshold
 * \public \memberof data_collection_model_usage_threshold_t
 *
 * Creates a new data_collection_lnode_t object containing the @a usage_threshold object.
 * The @a usage_threshold will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param usage_threshold The UsageThreshold object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a usage_threshold
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_usage_threshold_make_lnode(data_collection_model_usage_threshold_t *usage_threshold);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_USAGE_THRESHOLD_H_ */

