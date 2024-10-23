#ifndef _DATA_COLLECTION_ENDPOINT_ADDRESS_H_
#define _DATA_COLLECTION_ENDPOINT_ADDRESS_H_

/**********************************************************************************************************************************
 * EndpointAddress - Public C interface to the EndpointAddress object
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

/** A 3GPP EndpointAddress object reference
 */
typedef struct data_collection_model_endpoint_address_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_endpoint_address_t;



/** Create a new EndpointAddress
 * \public \memberof data_collection_model_endpoint_address_t
 * @return a new EndpointAddress object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_create();

/** Create a new copy of a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 * Creates a new copy of the given @a other object
 * @param other The EndpointAddress to copy.
 * @return a new EndpointAddress object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_create_copy(const data_collection_model_endpoint_address_t *other);

/** Create a new reference of a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 * Creates a reference to the same underlying @a other object.
 * @param other The EndpointAddress to create a new reference to.
 * @return a new EndpointAddress object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_create_move(data_collection_model_endpoint_address_t *other);

/** Copy the value of another EndpointAddress into this object
 * \public \memberof data_collection_model_endpoint_address_t
 * Copies the value of @a other {{classname} object into @a endpoint_address.
 * @param endpoint_address The EndpointAddress object to copy @a other into.
 * @param other The EndpointAddress to copy the value from.
 * @return @a endpoint_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_copy(data_collection_model_endpoint_address_t *endpoint_address, const data_collection_model_endpoint_address_t *other);

/** Move the value of another EndpointAddress into this object
 * \public \memberof data_collection_model_endpoint_address_t
 * Discards the current value of @a endpoint_address and moves the value of @a other
 * into @a endpoint_address. This will leave @a other as an empty reference.
 *
 * @param endpoint_address The EndpointAddress object to move @a other into.
 * @param other The EndpointAddress to move the value from.
 *
 * @return @a endpoint_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_move(data_collection_model_endpoint_address_t *endpoint_address, data_collection_model_endpoint_address_t *other);

/** Delete a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 * Destroys the reference to the EndpointAddress object and frees the value of EndpointAddress if this is the last reference.
 *
 * @param endpoint_address The EndpointAddress to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_endpoint_address_free(data_collection_model_endpoint_address_t *endpoint_address);

/** Get a cJSON tree representation of a EndpointAddress
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * Create a cJSON tree representation of the EndpointAddress object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param endpoint_address The EndpointAddress to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_endpoint_address_toJSON(const data_collection_model_endpoint_address_t *endpoint_address, bool as_request);

/** Parse a cJSON tree into a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * Attempts to interpret a cJSON tree as a EndpointAddress API request or response (dependent on @a as_request value). If successful
 * will return a new referenced EndpointAddress object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new EndpointAddress object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two EndpointAddress objects to see if they are equivalent
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param endpoint_address The first EndpointAddress object to compare.
 * @param other_endpoint_address The second EndpointAddress object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_endpoint_address_is_equal_to(const data_collection_model_endpoint_address_t *endpoint_address, const data_collection_model_endpoint_address_t *other_endpoint_address);



/** Get the value of the domainName field of a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to examine.
 *
 * @return the value current set for the domainName field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_endpoint_address_get_domain_name(const data_collection_model_endpoint_address_t *endpoint_address);

/** Set the value of the domainName field in a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to set the field in.
 * @param p_domain_name The value to copy into the EndpointAddress object.
 *
 * @return @a endpoint_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_domain_name(data_collection_model_endpoint_address_t *endpoint_address, const char* p_domain_name);

/** Move a value to the domainName field in a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to set the field in.
 * @param p_domain_name The value to move into the EndpointAddress object.
 *
 * @return @a endpoint_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_domain_name_move(data_collection_model_endpoint_address_t *endpoint_address, char* p_domain_name);

/** Check if the portNumbers field of a EndpointAddress object is set
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to examine.
 *
 * @return `true` if the optional portNumbers field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_endpoint_address_has_port_numbers(const data_collection_model_endpoint_address_t *endpoint_address);


/** Get the value of the portNumbers field of a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to examine.
 *
 * @return the value current set for the portNumbers field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_endpoint_address_get_port_numbers(const data_collection_model_endpoint_address_t *endpoint_address);

/** Set the value of the portNumbers field in a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to set the field in.
 * @param p_port_numbers The value to copy into the EndpointAddress object.
 *
 * @return @a endpoint_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_port_numbers(data_collection_model_endpoint_address_t *endpoint_address, const ogs_list_t* p_port_numbers);

/** Move a value to the portNumbers field in a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to set the field in.
 * @param p_port_numbers The value to move into the EndpointAddress object.
 *
 * @return @a endpoint_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_port_numbers_move(data_collection_model_endpoint_address_t *endpoint_address, ogs_list_t* p_port_numbers);

/** Add a new item to the portNumbers array in a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to add the array item to.
 * @param port_numbers The value to add.
 *
 * @return @a endpoint_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_add_port_numbers(data_collection_model_endpoint_address_t *endpoint_address, int32_t port_numbers);

/** Remove an item from the portNumbers array in a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to remove the array value from.
 * @param port_numbers The value to remove.
 *
 * @return @a endpoint_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_remove_port_numbers(data_collection_model_endpoint_address_t *endpoint_address, const int32_t port_numbers);

/** Get an item from the portNumbers array in a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_endpoint_address_get_entry_port_numbers(const data_collection_model_endpoint_address_t *endpoint_address, size_t idx);

/** Remove all entries from the portNumbers array in a EndpointAddress object
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * @param endpoint_address The EndpointAddress object to empty portNumbers for.
 *
 * @return @a endpoint_address
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_clear_port_numbers(data_collection_model_endpoint_address_t *endpoint_address);

/** lnode helper for generating ogs_list_t nodes's of type EndpointAddress
 * \public \memberof data_collection_model_endpoint_address_t
 *
 * Creates a new data_collection_lnode_t object containing the @a endpoint_address object.
 * The @a endpoint_address will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param endpoint_address The EndpointAddress object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a endpoint_address
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_endpoint_address_make_lnode(data_collection_model_endpoint_address_t *endpoint_address);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ENDPOINT_ADDRESS_H_ */

