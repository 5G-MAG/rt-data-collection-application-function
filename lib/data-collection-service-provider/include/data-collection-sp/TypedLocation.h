#ifndef _DATA_COLLECTION_TYPED_LOCATION_H_
#define _DATA_COLLECTION_TYPED_LOCATION_H_

/**********************************************************************************************************************************
 * TypedLocation - Public C interface to the TypedLocation object
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

#include "CellIdentifierType.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP TypedLocation object reference
 */
typedef struct data_collection_model_typed_location_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_typed_location_t;



/** Create a new TypedLocation
 * \public \memberof data_collection_model_typed_location_t
 * @return a new TypedLocation object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_create();

/** Create a new copy of a TypedLocation object
 * \public \memberof data_collection_model_typed_location_t
 * Creates a new copy of the given @a other object
 * @param other The TypedLocation to copy.
 * @return a new TypedLocation object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_create_copy(const data_collection_model_typed_location_t *other);

/** Create a new reference of a TypedLocation object
 * \public \memberof data_collection_model_typed_location_t
 * Creates a reference to the same underlying @a other object.
 * @param other The TypedLocation to create a new reference to.
 * @return a new TypedLocation object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_create_move(data_collection_model_typed_location_t *other);

/** Copy the value of another TypedLocation into this object
 * \public \memberof data_collection_model_typed_location_t
 * Copies the value of @a other {{classname} object into @a typed_location.
 * @param typed_location The TypedLocation object to copy @a other into.
 * @param other The TypedLocation to copy the value from.
 * @return @a typed_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_copy(data_collection_model_typed_location_t *typed_location, const data_collection_model_typed_location_t *other);

/** Move the value of another TypedLocation into this object
 * \public \memberof data_collection_model_typed_location_t
 * Discards the current value of @a typed_location and moves the value of @a other
 * into @a typed_location. This will leave @a other as an empty reference.
 *
 * @param typed_location The TypedLocation object to move @a other into.
 * @param other The TypedLocation to move the value from.
 *
 * @return @a typed_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_move(data_collection_model_typed_location_t *typed_location, data_collection_model_typed_location_t *other);

/** Delete a TypedLocation object
 * \public \memberof data_collection_model_typed_location_t
 * Destroys the reference to the TypedLocation object and frees the value of TypedLocation if this is the last reference.
 *
 * @param typed_location The TypedLocation to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_typed_location_free(data_collection_model_typed_location_t *typed_location);

/** Get a cJSON tree representation of a TypedLocation
 * \public \memberof data_collection_model_typed_location_t
 *
 * Create a cJSON tree representation of the TypedLocation object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param typed_location The TypedLocation to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_typed_location_toJSON(const data_collection_model_typed_location_t *typed_location, bool as_request);

/** Parse a cJSON tree into a TypedLocation object
 * \public \memberof data_collection_model_typed_location_t
 *
 * Attempts to interpret a cJSON tree as a TypedLocation API request or response (dependent on @a as_request value). If successful
 * will return a new referenced TypedLocation object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new TypedLocation object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two TypedLocation objects to see if they are equivalent
 * \public \memberof data_collection_model_typed_location_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param typed_location The first TypedLocation object to compare.
 * @param other_typed_location The second TypedLocation object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_typed_location_is_equal_to(const data_collection_model_typed_location_t *typed_location, const data_collection_model_typed_location_t *other_typed_location);



/** Get the value of the locationIdentifierType field of a TypedLocation object
 * \public \memberof data_collection_model_typed_location_t
 *
 * @param typed_location The TypedLocation object to examine.
 *
 * @return the value current set for the locationIdentifierType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cell_identifier_type_t* data_collection_model_typed_location_get_location_identifier_type(const data_collection_model_typed_location_t *typed_location);

/** Set the value of the locationIdentifierType field in a TypedLocation object
 * \public \memberof data_collection_model_typed_location_t
 *
 * @param typed_location The TypedLocation object to set the field in.
 * @param p_location_identifier_type The value to copy into the TypedLocation object.
 *
 * @return @a typed_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location_identifier_type(data_collection_model_typed_location_t *typed_location, const data_collection_model_cell_identifier_type_t* p_location_identifier_type);

/** Move a value to the locationIdentifierType field in a TypedLocation object
 * \public \memberof data_collection_model_typed_location_t
 *
 * @param typed_location The TypedLocation object to set the field in.
 * @param p_location_identifier_type The value to move into the TypedLocation object.
 *
 * @return @a typed_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location_identifier_type_move(data_collection_model_typed_location_t *typed_location, data_collection_model_cell_identifier_type_t* p_location_identifier_type);


/** Get the value of the location field of a TypedLocation object
 * \public \memberof data_collection_model_typed_location_t
 *
 * @param typed_location The TypedLocation object to examine.
 *
 * @return the value current set for the location field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_typed_location_get_location(const data_collection_model_typed_location_t *typed_location);

/** Set the value of the location field in a TypedLocation object
 * \public \memberof data_collection_model_typed_location_t
 *
 * @param typed_location The TypedLocation object to set the field in.
 * @param p_location The value to copy into the TypedLocation object.
 *
 * @return @a typed_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location(data_collection_model_typed_location_t *typed_location, const char* p_location);

/** Move a value to the location field in a TypedLocation object
 * \public \memberof data_collection_model_typed_location_t
 *
 * @param typed_location The TypedLocation object to set the field in.
 * @param p_location The value to move into the TypedLocation object.
 *
 * @return @a typed_location.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location_move(data_collection_model_typed_location_t *typed_location, char* p_location);

/** lnode helper for generating ogs_list_t nodes's of type TypedLocation
 * \public \memberof data_collection_model_typed_location_t
 *
 * Creates a new data_collection_lnode_t object containing the @a typed_location object.
 * The @a typed_location will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param typed_location The TypedLocation object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a typed_location
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_typed_location_make_lnode(data_collection_model_typed_location_t *typed_location);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_TYPED_LOCATION_H_ */

