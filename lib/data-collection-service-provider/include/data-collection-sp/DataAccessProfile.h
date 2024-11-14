#ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_H_
#define _DATA_COLLECTION_DATA_ACCESS_PROFILE_H_

/**********************************************************************************************************************************
 * DataAccessProfile - Public C interface to the DataAccessProfile object
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

#include "DataAccessProfile_locationAccessRestrictions.h"
#include "DataAccessProfile_timeAccessRestrictions.h"
#include "DataAccessProfile_userAccessRestrictions.h"
#include "EventConsumerType.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DataAccessProfile object reference
 */
typedef struct data_collection_model_data_access_profile_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_access_profile_t;



/** Create a new DataAccessProfile.
 * \public \memberof data_collection_model_data_access_profile_t
 * @return a new DataAccessProfile object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create();

/** Create a new DataAccessProfile reference.
 * \public \memberof data_collection_model_data_access_profile_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The DataAccessProfile to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create_ref(const data_collection_model_data_access_profile_t *other);

/** Create a new copy of a DataAccessProfile object.
 * \public \memberof data_collection_model_data_access_profile_t
 * Creates a new copy of the given @a other object
 * @param other The DataAccessProfile to copy.
 * @return a new DataAccessProfile object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create_copy(const data_collection_model_data_access_profile_t *other);

/** Create a new reference of a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataAccessProfile to create a new reference to.
 * @return a new DataAccessProfile object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_create_move(data_collection_model_data_access_profile_t *other);

/** Copy the value of another DataAccessProfile into this object
 * \public \memberof data_collection_model_data_access_profile_t
 * Copies the value of @a other {{classname} object into @a data_access_profile.
 * @param data_access_profile The DataAccessProfile object to copy @a other into.
 * @param other The DataAccessProfile to copy the value from.
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_copy(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_t *other);

/** Move the value of another DataAccessProfile into this object
 * \public \memberof data_collection_model_data_access_profile_t
 * Discards the current value of @a data_access_profile and moves the value of @a other
 * into @a data_access_profile. This will leave @a other as an empty reference.
 *
 * @param data_access_profile The DataAccessProfile object to move @a other into.
 * @param other The DataAccessProfile to move the value from.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_move(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_data_access_profile_t *other);

/** Delete a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 * Destroys the reference to the DataAccessProfile object and frees the value of DataAccessProfile if this is the last reference.
 *
 * @param data_access_profile The DataAccessProfile to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_access_profile_free(data_collection_model_data_access_profile_t *data_access_profile);

/** Get a cJSON tree representation of a DataAccessProfile
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * Create a cJSON tree representation of the DataAccessProfile object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_access_profile The DataAccessProfile to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_access_profile_toJSON(const data_collection_model_data_access_profile_t *data_access_profile, bool as_request);

/** Parse a cJSON tree into a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * Attempts to interpret a cJSON tree as a DataAccessProfile API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataAccessProfile object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DataAccessProfile object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataAccessProfile objects to see if they are equivalent
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_access_profile The first DataAccessProfile object to compare.
 * @param other_data_access_profile The second DataAccessProfile object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_is_equal_to(const data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_t *other_data_access_profile);



/** Get the value of the dataAccessProfileId field of a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 *
 * @return the value current set for the dataAccessProfileId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_access_profile_get_data_access_profile_id(const data_collection_model_data_access_profile_t *data_access_profile);

/** Set the value of the dataAccessProfileId field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_data_access_profile_id The value to copy into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_data_access_profile_id(data_collection_model_data_access_profile_t *data_access_profile, const char* p_data_access_profile_id);

/** Move a value to the dataAccessProfileId field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_data_access_profile_id The value to move into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_data_access_profile_id_move(data_collection_model_data_access_profile_t *data_access_profile, char* p_data_access_profile_id);


/** Get the value of the targetEventConsumerTypes field of a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 *
 * @return the value current set for the targetEventConsumerTypes field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_access_profile_get_target_event_consumer_types(const data_collection_model_data_access_profile_t *data_access_profile);

/** Set the value of the targetEventConsumerTypes field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_target_event_consumer_types The value to copy into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_target_event_consumer_types(data_collection_model_data_access_profile_t *data_access_profile, const ogs_list_t* p_target_event_consumer_types);

/** Move a value to the targetEventConsumerTypes field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_target_event_consumer_types The value to move into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_target_event_consumer_types_move(data_collection_model_data_access_profile_t *data_access_profile, ogs_list_t* p_target_event_consumer_types);

/** Add a new item to the targetEventConsumerTypes array in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to add the array item to.
 * @param target_event_consumer_types The value to add.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_add_target_event_consumer_types(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_event_consumer_type_t* target_event_consumer_types);

/** Remove an item from the targetEventConsumerTypes array in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to remove the array value from.
 * @param target_event_consumer_types The value to remove.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_remove_target_event_consumer_types(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_event_consumer_type_t* target_event_consumer_types);

/** Get an item from the targetEventConsumerTypes array in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_consumer_type_t* data_collection_model_data_access_profile_get_entry_target_event_consumer_types(const data_collection_model_data_access_profile_t *data_access_profile, size_t idx);

/** Remove all entries from the targetEventConsumerTypes array in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to empty targetEventConsumerTypes for.
 *
 * @return @a data_access_profile
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_clear_target_event_consumer_types(data_collection_model_data_access_profile_t *data_access_profile);


/** Get the value of the parameters field of a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 *
 * @return the value current set for the parameters field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_access_profile_get_parameters(const data_collection_model_data_access_profile_t *data_access_profile);

/** Set the value of the parameters field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_parameters The value to copy into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_parameters(data_collection_model_data_access_profile_t *data_access_profile, const ogs_list_t* p_parameters);

/** Move a value to the parameters field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_parameters The value to move into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_parameters_move(data_collection_model_data_access_profile_t *data_access_profile, ogs_list_t* p_parameters);

/** Add a new item to the parameters array in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to add the array item to.
 * @param parameters The value to add.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_add_parameters(data_collection_model_data_access_profile_t *data_access_profile, char* parameters);

/** Remove an item from the parameters array in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to remove the array value from.
 * @param parameters The value to remove.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_remove_parameters(data_collection_model_data_access_profile_t *data_access_profile, const char* parameters);

/** Get an item from the parameters array in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_access_profile_get_entry_parameters(const data_collection_model_data_access_profile_t *data_access_profile, size_t idx);

/** Remove all entries from the parameters array in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to empty parameters for.
 *
 * @return @a data_access_profile
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_clear_parameters(data_collection_model_data_access_profile_t *data_access_profile);

/** Check if the timeAccessRestrictions field of a DataAccessProfile object is set
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 *
 * @return `true` if the optional timeAccessRestrictions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_has_time_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);


/** Get the value of the timeAccessRestrictions field of a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 *
 * @return the value current set for the timeAccessRestrictions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_time_access_restrictions_t* data_collection_model_data_access_profile_get_time_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);

/** Set the value of the timeAccessRestrictions field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_time_access_restrictions The value to copy into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_time_access_restrictions(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_time_access_restrictions_t* p_time_access_restrictions);

/** Move a value to the timeAccessRestrictions field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_time_access_restrictions The value to move into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_time_access_restrictions_move(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_data_access_profile_time_access_restrictions_t* p_time_access_restrictions);

/** Check if the userAccessRestrictions field of a DataAccessProfile object is set
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 *
 * @return `true` if the optional userAccessRestrictions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_has_user_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);


/** Get the value of the userAccessRestrictions field of a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 *
 * @return the value current set for the userAccessRestrictions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_user_access_restrictions_t* data_collection_model_data_access_profile_get_user_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);

/** Set the value of the userAccessRestrictions field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_user_access_restrictions The value to copy into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_user_access_restrictions(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_user_access_restrictions_t* p_user_access_restrictions);

/** Move a value to the userAccessRestrictions field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_user_access_restrictions The value to move into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_user_access_restrictions_move(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_data_access_profile_user_access_restrictions_t* p_user_access_restrictions);

/** Check if the locationAccessRestrictions field of a DataAccessProfile object is set
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 *
 * @return `true` if the optional locationAccessRestrictions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_has_location_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);


/** Get the value of the locationAccessRestrictions field of a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to examine.
 *
 * @return the value current set for the locationAccessRestrictions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_access_profile_location_access_restrictions_t* data_collection_model_data_access_profile_get_location_access_restrictions(const data_collection_model_data_access_profile_t *data_access_profile);

/** Set the value of the locationAccessRestrictions field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_location_access_restrictions The value to copy into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_location_access_restrictions(data_collection_model_data_access_profile_t *data_access_profile, const data_collection_model_data_access_profile_location_access_restrictions_t* p_location_access_restrictions);

/** Move a value to the locationAccessRestrictions field in a DataAccessProfile object
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * @param data_access_profile The DataAccessProfile object to set the field in.
 * @param p_location_access_restrictions The value to move into the DataAccessProfile object.
 *
 * @return @a data_access_profile.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_t *data_collection_model_data_access_profile_set_location_access_restrictions_move(data_collection_model_data_access_profile_t *data_access_profile, data_collection_model_data_access_profile_location_access_restrictions_t* p_location_access_restrictions);

/** lnode helper for generating ogs_list_t nodes's of type DataAccessProfile
 * \public \memberof data_collection_model_data_access_profile_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_access_profile object.
 * The @a data_access_profile will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_access_profile The DataAccessProfile object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_access_profile
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_access_profile_make_lnode(data_collection_model_data_access_profile_t *data_access_profile);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_H_ */

