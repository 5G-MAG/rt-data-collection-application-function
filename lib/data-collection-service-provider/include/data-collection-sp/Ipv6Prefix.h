#ifndef _DATA_COLLECTION_IPV6_PREFIX_H_
#define _DATA_COLLECTION_IPV6_PREFIX_H_

/**********************************************************************************************************************************
 * Ipv6Prefix - Public C interface to the Ipv6Prefix object
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

/** A 3GPP Ipv6Prefix object reference
 */
typedef struct data_collection_model_ipv6_prefix_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ipv6_prefix_t;



/** Create a new Ipv6Prefix.
 * \public \memberof data_collection_model_ipv6_prefix_t
 * @return a new Ipv6Prefix object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create();

/** Create a new Ipv6Prefix reference.
 * \public \memberof data_collection_model_ipv6_prefix_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The Ipv6Prefix to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create_ref(const data_collection_model_ipv6_prefix_t *other);

/** Create a new copy of a Ipv6Prefix object.
 * \public \memberof data_collection_model_ipv6_prefix_t
 * Creates a new copy of the given @a other object
 * @param other The Ipv6Prefix to copy.
 * @return a new Ipv6Prefix object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create_copy(const data_collection_model_ipv6_prefix_t *other);

/** Create a new reference of a Ipv6Prefix object
 * \public \memberof data_collection_model_ipv6_prefix_t
 * Creates a reference to the same underlying @a other object.
 * @param other The Ipv6Prefix to create a new reference to.
 * @return a new Ipv6Prefix object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create_move(data_collection_model_ipv6_prefix_t *other);

/** Copy the value of another Ipv6Prefix into this object
 * \public \memberof data_collection_model_ipv6_prefix_t
 * Copies the value of @a other {{classname} object into @a ipv6_prefix.
 * @param ipv6_prefix The Ipv6Prefix object to copy @a other into.
 * @param other The Ipv6Prefix to copy the value from.
 * @return @a ipv6_prefix.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_copy(data_collection_model_ipv6_prefix_t *ipv6_prefix, const data_collection_model_ipv6_prefix_t *other);

/** Move the value of another Ipv6Prefix into this object
 * \public \memberof data_collection_model_ipv6_prefix_t
 * Discards the current value of @a ipv6_prefix and moves the value of @a other
 * into @a ipv6_prefix. This will leave @a other as an empty reference.
 *
 * @param ipv6_prefix The Ipv6Prefix object to move @a other into.
 * @param other The Ipv6Prefix to move the value from.
 *
 * @return @a ipv6_prefix.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_move(data_collection_model_ipv6_prefix_t *ipv6_prefix, data_collection_model_ipv6_prefix_t *other);

/** Delete a Ipv6Prefix object
 * \public \memberof data_collection_model_ipv6_prefix_t
 * Destroys the reference to the Ipv6Prefix object and frees the value of Ipv6Prefix if this is the last reference.
 *
 * @param ipv6_prefix The Ipv6Prefix to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ipv6_prefix_free(data_collection_model_ipv6_prefix_t *ipv6_prefix);

/** Get a cJSON tree representation of a Ipv6Prefix
 * \public \memberof data_collection_model_ipv6_prefix_t
 *
 * Create a cJSON tree representation of the Ipv6Prefix object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ipv6_prefix The Ipv6Prefix to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ipv6_prefix_toJSON(const data_collection_model_ipv6_prefix_t *ipv6_prefix, bool as_request);

/** Parse a cJSON tree into a Ipv6Prefix object
 * \public \memberof data_collection_model_ipv6_prefix_t
 *
 * Attempts to interpret a cJSON tree as a Ipv6Prefix API request or response (dependent on @a as_request value). If successful
 * will return a new referenced Ipv6Prefix object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new Ipv6Prefix object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two Ipv6Prefix objects to see if they are equivalent
 * \public \memberof data_collection_model_ipv6_prefix_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ipv6_prefix The first Ipv6Prefix object to compare.
 * @param other_ipv6_prefix The second Ipv6Prefix object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ipv6_prefix_is_equal_to(const data_collection_model_ipv6_prefix_t *ipv6_prefix, const data_collection_model_ipv6_prefix_t *other_ipv6_prefix);


/** lnode helper for generating ogs_list_t nodes's of type Ipv6Prefix
 * \public \memberof data_collection_model_ipv6_prefix_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ipv6_prefix object.
 * The @a ipv6_prefix will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ipv6_prefix The Ipv6Prefix object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ipv6_prefix
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ipv6_prefix_make_lnode(data_collection_model_ipv6_prefix_t *ipv6_prefix);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_IPV6_PREFIX_H_ */

