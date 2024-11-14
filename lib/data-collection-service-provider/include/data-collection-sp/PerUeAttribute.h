#ifndef _DATA_COLLECTION_PER_UE_ATTRIBUTE_H_
#define _DATA_COLLECTION_PER_UE_ATTRIBUTE_H_

/**********************************************************************************************************************************
 * PerUeAttribute - Public C interface to the PerUeAttribute object
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

#include "LocationArea5G.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PerUeAttribute object reference
 */
typedef struct data_collection_model_per_ue_attribute_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_per_ue_attribute_t;



/** Create a new PerUeAttribute.
 * \public \memberof data_collection_model_per_ue_attribute_t
 * @return a new PerUeAttribute object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create();

/** Create a new PerUeAttribute reference.
 * \public \memberof data_collection_model_per_ue_attribute_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The PerUeAttribute to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create_ref(const data_collection_model_per_ue_attribute_t *other);

/** Create a new copy of a PerUeAttribute object.
 * \public \memberof data_collection_model_per_ue_attribute_t
 * Creates a new copy of the given @a other object
 * @param other The PerUeAttribute to copy.
 * @return a new PerUeAttribute object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create_copy(const data_collection_model_per_ue_attribute_t *other);

/** Create a new reference of a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PerUeAttribute to create a new reference to.
 * @return a new PerUeAttribute object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create_move(data_collection_model_per_ue_attribute_t *other);

/** Copy the value of another PerUeAttribute into this object
 * \public \memberof data_collection_model_per_ue_attribute_t
 * Copies the value of @a other {{classname} object into @a per_ue_attribute.
 * @param per_ue_attribute The PerUeAttribute object to copy @a other into.
 * @param other The PerUeAttribute to copy the value from.
 * @return @a per_ue_attribute.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_copy(data_collection_model_per_ue_attribute_t *per_ue_attribute, const data_collection_model_per_ue_attribute_t *other);

/** Move the value of another PerUeAttribute into this object
 * \public \memberof data_collection_model_per_ue_attribute_t
 * Discards the current value of @a per_ue_attribute and moves the value of @a other
 * into @a per_ue_attribute. This will leave @a other as an empty reference.
 *
 * @param per_ue_attribute The PerUeAttribute object to move @a other into.
 * @param other The PerUeAttribute to move the value from.
 *
 * @return @a per_ue_attribute.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, data_collection_model_per_ue_attribute_t *other);

/** Delete a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 * Destroys the reference to the PerUeAttribute object and frees the value of PerUeAttribute if this is the last reference.
 *
 * @param per_ue_attribute The PerUeAttribute to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_per_ue_attribute_free(data_collection_model_per_ue_attribute_t *per_ue_attribute);

/** Get a cJSON tree representation of a PerUeAttribute
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * Create a cJSON tree representation of the PerUeAttribute object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param per_ue_attribute The PerUeAttribute to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_per_ue_attribute_toJSON(const data_collection_model_per_ue_attribute_t *per_ue_attribute, bool as_request);

/** Parse a cJSON tree into a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * Attempts to interpret a cJSON tree as a PerUeAttribute API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PerUeAttribute object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PerUeAttribute object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PerUeAttribute objects to see if they are equivalent
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param per_ue_attribute The first PerUeAttribute object to compare.
 * @param other_per_ue_attribute The second PerUeAttribute object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_is_equal_to(const data_collection_model_per_ue_attribute_t *per_ue_attribute, const data_collection_model_per_ue_attribute_t *other_per_ue_attribute);


/** Check if the ueDest field of a PerUeAttribute object is set
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to examine.
 *
 * @return `true` if the optional ueDest field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_ue_dest(const data_collection_model_per_ue_attribute_t *per_ue_attribute);


/** Get the value of the ueDest field of a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to examine.
 *
 * @return the value current set for the ueDest field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_per_ue_attribute_get_ue_dest(const data_collection_model_per_ue_attribute_t *per_ue_attribute);

/** Set the value of the ueDest field in a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to set the field in.
 * @param p_ue_dest The value to copy into the PerUeAttribute object.
 *
 * @return @a per_ue_attribute.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_ue_dest(data_collection_model_per_ue_attribute_t *per_ue_attribute, const data_collection_model_location_area5_g_t* p_ue_dest);

/** Move a value to the ueDest field in a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to set the field in.
 * @param p_ue_dest The value to move into the PerUeAttribute object.
 *
 * @return @a per_ue_attribute.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_ue_dest_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, data_collection_model_location_area5_g_t* p_ue_dest);

/** Check if the route field of a PerUeAttribute object is set
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to examine.
 *
 * @return `true` if the optional route field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_route(const data_collection_model_per_ue_attribute_t *per_ue_attribute);


/** Get the value of the route field of a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to examine.
 *
 * @return the value current set for the route field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_per_ue_attribute_get_route(const data_collection_model_per_ue_attribute_t *per_ue_attribute);

/** Set the value of the route field in a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to set the field in.
 * @param p_route The value to copy into the PerUeAttribute object.
 *
 * @return @a per_ue_attribute.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_route(data_collection_model_per_ue_attribute_t *per_ue_attribute, const char* p_route);

/** Move a value to the route field in a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to set the field in.
 * @param p_route The value to move into the PerUeAttribute object.
 *
 * @return @a per_ue_attribute.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_route_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, char* p_route);

/** Check if the avgSpeed field of a PerUeAttribute object is set
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to examine.
 *
 * @return `true` if the optional avgSpeed field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_avg_speed(const data_collection_model_per_ue_attribute_t *per_ue_attribute);


/** Get the value of the avgSpeed field of a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to examine.
 *
 * @return the value current set for the avgSpeed field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_per_ue_attribute_get_avg_speed(const data_collection_model_per_ue_attribute_t *per_ue_attribute);

/** Set the value of the avgSpeed field in a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to set the field in.
 * @param p_avg_speed The value to copy into the PerUeAttribute object.
 *
 * @return @a per_ue_attribute.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_avg_speed(data_collection_model_per_ue_attribute_t *per_ue_attribute, const char* p_avg_speed);

/** Move a value to the avgSpeed field in a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to set the field in.
 * @param p_avg_speed The value to move into the PerUeAttribute object.
 *
 * @return @a per_ue_attribute.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_avg_speed_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, char* p_avg_speed);

/** Check if the timeOfArrival field of a PerUeAttribute object is set
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to examine.
 *
 * @return `true` if the optional timeOfArrival field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_time_of_arrival(const data_collection_model_per_ue_attribute_t *per_ue_attribute);


/** Get the value of the timeOfArrival field of a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to examine.
 *
 * @return the value current set for the timeOfArrival field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_per_ue_attribute_get_time_of_arrival(const data_collection_model_per_ue_attribute_t *per_ue_attribute);

/** Set the value of the timeOfArrival field in a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to set the field in.
 * @param p_time_of_arrival The value to copy into the PerUeAttribute object.
 *
 * @return @a per_ue_attribute.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_time_of_arrival(data_collection_model_per_ue_attribute_t *per_ue_attribute, const char* p_time_of_arrival);

/** Move a value to the timeOfArrival field in a PerUeAttribute object
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * @param per_ue_attribute The PerUeAttribute object to set the field in.
 * @param p_time_of_arrival The value to move into the PerUeAttribute object.
 *
 * @return @a per_ue_attribute.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_time_of_arrival_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, char* p_time_of_arrival);

/** lnode helper for generating ogs_list_t nodes's of type PerUeAttribute
 * \public \memberof data_collection_model_per_ue_attribute_t
 *
 * Creates a new data_collection_lnode_t object containing the @a per_ue_attribute object.
 * The @a per_ue_attribute will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param per_ue_attribute The PerUeAttribute object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a per_ue_attribute
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_per_ue_attribute_make_lnode(data_collection_model_per_ue_attribute_t *per_ue_attribute);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PER_UE_ATTRIBUTE_H_ */

