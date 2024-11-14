#ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_LOCATION_ACCESS_RESTRICTIONS_H_
#define _DATA_COLLECTION_DATA_ACCESS_PROFILE_LOCATION_ACCESS_RESTRICTIONS_H_

/**********************************************************************************************************************************
 * DataAccessProfile_locationAccessRestrictions - Public C interface to the DataAccessProfile_locationAccessRestrictions object
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

#include "DataAggregationFunctionType.h"
#include "LocationArea5G.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DataAccessProfile_locationAccessRestrictions object reference
 */
typedef struct data_collection_model_data_access_profile_location_access_restrictions_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_access_profile_location_access_restrictions_t;



/** Create a new DataAccessProfile_locationAccessRestrictions.
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 * @return a new DataAccessProfile_locationAccessRestrictions object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_create();

/** Create a new DataAccessProfile_locationAccessRestrictions reference.
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The DataAccessProfile_locationAccessRestrictions to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_create_ref(const data_collection_model_data_access_profile_location_access_restrictions_t *other);

/** Create a new copy of a DataAccessProfile_locationAccessRestrictions object.
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 * Creates a new copy of the given @a other object
 * @param other The DataAccessProfile_locationAccessRestrictions to copy.
 * @return a new DataAccessProfile_locationAccessRestrictions object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_create_copy(const data_collection_model_data_access_profile_location_access_restrictions_t *other);

/** Create a new reference of a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataAccessProfile_locationAccessRestrictions to create a new reference to.
 * @return a new DataAccessProfile_locationAccessRestrictions object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_create_move(data_collection_model_data_access_profile_location_access_restrictions_t *other);

/** Copy the value of another DataAccessProfile_locationAccessRestrictions into this object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 * Copies the value of @a other {{classname} object into @a data_access_profile_location_access_restrictions.
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to copy @a other into.
 * @param other The DataAccessProfile_locationAccessRestrictions to copy the value from.
 * @return @a data_access_profile_location_access_restrictions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_copy(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, const data_collection_model_data_access_profile_location_access_restrictions_t *other);

/** Move the value of another DataAccessProfile_locationAccessRestrictions into this object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 * Discards the current value of @a data_access_profile_location_access_restrictions and moves the value of @a other
 * into @a data_access_profile_location_access_restrictions. This will leave @a other as an empty reference.
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to move @a other into.
 * @param other The DataAccessProfile_locationAccessRestrictions to move the value from.
 *
 * @return @a data_access_profile_location_access_restrictions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_move(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, data_collection_model_data_access_profile_location_access_restrictions_t *other);

/** Delete a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 * Destroys the reference to the DataAccessProfile_locationAccessRestrictions object and frees the value of DataAccessProfile_locationAccessRestrictions if this is the last reference.
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_access_profile_location_access_restrictions_free(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions);

/** Get a cJSON tree representation of a DataAccessProfile_locationAccessRestrictions
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * Create a cJSON tree representation of the DataAccessProfile_locationAccessRestrictions object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_access_profile_location_access_restrictions_toJSON(const data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, bool as_request);

/** Parse a cJSON tree into a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * Attempts to interpret a cJSON tree as a DataAccessProfile_locationAccessRestrictions API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataAccessProfile_locationAccessRestrictions object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DataAccessProfile_locationAccessRestrictions object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataAccessProfile_locationAccessRestrictions objects to see if they are equivalent
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_access_profile_location_access_restrictions The first DataAccessProfile_locationAccessRestrictions object to compare.
 * @param other_data_access_profile_location_access_restrictions The second DataAccessProfile_locationAccessRestrictions object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_access_profile_location_access_restrictions_is_equal_to(const data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, const data_collection_model_data_access_profile_location_access_restrictions_t *other_data_access_profile_location_access_restrictions);



/** Get the value of the locationAreas field of a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to examine.
 *
 * @return the value current set for the locationAreas field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_access_profile_location_access_restrictions_get_location_areas(const data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions);

/** Set the value of the locationAreas field in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to set the field in.
 * @param p_location_areas The value to copy into the DataAccessProfile_locationAccessRestrictions object.
 *
 * @return @a data_access_profile_location_access_restrictions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_set_location_areas(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, const ogs_list_t* p_location_areas);

/** Move a value to the locationAreas field in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to set the field in.
 * @param p_location_areas The value to move into the DataAccessProfile_locationAccessRestrictions object.
 *
 * @return @a data_access_profile_location_access_restrictions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_set_location_areas_move(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, ogs_list_t* p_location_areas);

/** Add a new item to the locationAreas array in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to add the array item to.
 * @param location_areas The value to add.
 *
 * @return @a data_access_profile_location_access_restrictions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_add_location_areas(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, data_collection_model_location_area5_g_t* location_areas);

/** Remove an item from the locationAreas array in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to remove the array value from.
 * @param location_areas The value to remove.
 *
 * @return @a data_access_profile_location_access_restrictions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_remove_location_areas(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, const data_collection_model_location_area5_g_t* location_areas);

/** Get an item from the locationAreas array in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_data_access_profile_location_access_restrictions_get_entry_location_areas(const data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, size_t idx);

/** Remove all entries from the locationAreas array in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to empty locationAreas for.
 *
 * @return @a data_access_profile_location_access_restrictions
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_clear_location_areas(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions);


/** Get the value of the aggregationFunctions field of a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to examine.
 *
 * @return the value current set for the aggregationFunctions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_access_profile_location_access_restrictions_get_aggregation_functions(const data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions);

/** Set the value of the aggregationFunctions field in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to set the field in.
 * @param p_aggregation_functions The value to copy into the DataAccessProfile_locationAccessRestrictions object.
 *
 * @return @a data_access_profile_location_access_restrictions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_set_aggregation_functions(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, const ogs_list_t* p_aggregation_functions);

/** Move a value to the aggregationFunctions field in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to set the field in.
 * @param p_aggregation_functions The value to move into the DataAccessProfile_locationAccessRestrictions object.
 *
 * @return @a data_access_profile_location_access_restrictions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_set_aggregation_functions_move(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, ogs_list_t* p_aggregation_functions);

/** Add a new item to the aggregationFunctions array in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to add the array item to.
 * @param aggregation_functions The value to add.
 *
 * @return @a data_access_profile_location_access_restrictions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_add_aggregation_functions(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, data_collection_model_data_aggregation_function_type_t* aggregation_functions);

/** Remove an item from the aggregationFunctions array in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to remove the array value from.
 * @param aggregation_functions The value to remove.
 *
 * @return @a data_access_profile_location_access_restrictions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_remove_aggregation_functions(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, const data_collection_model_data_aggregation_function_type_t* aggregation_functions);

/** Get an item from the aggregationFunctions array in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_aggregation_function_type_t* data_collection_model_data_access_profile_location_access_restrictions_get_entry_aggregation_functions(const data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions, size_t idx);

/** Remove all entries from the aggregationFunctions array in a DataAccessProfile_locationAccessRestrictions object
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to empty aggregationFunctions for.
 *
 * @return @a data_access_profile_location_access_restrictions
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_access_profile_location_access_restrictions_t *data_collection_model_data_access_profile_location_access_restrictions_clear_aggregation_functions(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions);

/** lnode helper for generating ogs_list_t nodes's of type DataAccessProfile_locationAccessRestrictions
 * \public \memberof data_collection_model_data_access_profile_location_access_restrictions_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_access_profile_location_access_restrictions object.
 * The @a data_access_profile_location_access_restrictions will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_access_profile_location_access_restrictions The DataAccessProfile_locationAccessRestrictions object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_access_profile_location_access_restrictions
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_access_profile_location_access_restrictions_make_lnode(data_collection_model_data_access_profile_location_access_restrictions_t *data_access_profile_location_access_restrictions);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_ACCESS_PROFILE_LOCATION_ACCESS_RESTRICTIONS_H_ */

