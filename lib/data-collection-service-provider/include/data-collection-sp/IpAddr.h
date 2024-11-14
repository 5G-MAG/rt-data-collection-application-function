#ifndef _DATA_COLLECTION_IP_ADDR_H_
#define _DATA_COLLECTION_IP_ADDR_H_

/**********************************************************************************************************************************
 * IpAddr - Public C interface to the IpAddr object
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

#include "Ipv6Prefix.h"
#include "Ipv6Addr.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP IpAddr object reference
 */
typedef struct data_collection_model_ip_addr_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ip_addr_t;



/** Create a new IpAddr.
 * \public \memberof data_collection_model_ip_addr_t
 * @return a new IpAddr object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_create();

/** Create a new IpAddr reference.
 * \public \memberof data_collection_model_ip_addr_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The IpAddr to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_create_ref(const data_collection_model_ip_addr_t *other);

/** Create a new copy of a IpAddr object.
 * \public \memberof data_collection_model_ip_addr_t
 * Creates a new copy of the given @a other object
 * @param other The IpAddr to copy.
 * @return a new IpAddr object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_create_copy(const data_collection_model_ip_addr_t *other);

/** Create a new reference of a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 * Creates a reference to the same underlying @a other object.
 * @param other The IpAddr to create a new reference to.
 * @return a new IpAddr object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_create_move(data_collection_model_ip_addr_t *other);

/** Copy the value of another IpAddr into this object
 * \public \memberof data_collection_model_ip_addr_t
 * Copies the value of @a other {{classname} object into @a ip_addr.
 * @param ip_addr The IpAddr object to copy @a other into.
 * @param other The IpAddr to copy the value from.
 * @return @a ip_addr.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_copy(data_collection_model_ip_addr_t *ip_addr, const data_collection_model_ip_addr_t *other);

/** Move the value of another IpAddr into this object
 * \public \memberof data_collection_model_ip_addr_t
 * Discards the current value of @a ip_addr and moves the value of @a other
 * into @a ip_addr. This will leave @a other as an empty reference.
 *
 * @param ip_addr The IpAddr object to move @a other into.
 * @param other The IpAddr to move the value from.
 *
 * @return @a ip_addr.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_move(data_collection_model_ip_addr_t *ip_addr, data_collection_model_ip_addr_t *other);

/** Delete a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 * Destroys the reference to the IpAddr object and frees the value of IpAddr if this is the last reference.
 *
 * @param ip_addr The IpAddr to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ip_addr_free(data_collection_model_ip_addr_t *ip_addr);

/** Get a cJSON tree representation of a IpAddr
 * \public \memberof data_collection_model_ip_addr_t
 *
 * Create a cJSON tree representation of the IpAddr object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ip_addr The IpAddr to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ip_addr_toJSON(const data_collection_model_ip_addr_t *ip_addr, bool as_request);

/** Parse a cJSON tree into a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 *
 * Attempts to interpret a cJSON tree as a IpAddr API request or response (dependent on @a as_request value). If successful
 * will return a new referenced IpAddr object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new IpAddr object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two IpAddr objects to see if they are equivalent
 * \public \memberof data_collection_model_ip_addr_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ip_addr The first IpAddr object to compare.
 * @param other_ip_addr The second IpAddr object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_addr_is_equal_to(const data_collection_model_ip_addr_t *ip_addr, const data_collection_model_ip_addr_t *other_ip_addr);


/** Check if the ipv4Addr field of a IpAddr object is set
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to examine.
 *
 * @return `true` if the optional ipv4Addr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_addr_has_ipv4_addr(const data_collection_model_ip_addr_t *ip_addr);


/** Get the value of the ipv4Addr field of a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to examine.
 *
 * @return the value current set for the ipv4Addr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ip_addr_get_ipv4_addr(const data_collection_model_ip_addr_t *ip_addr);

/** Set the value of the ipv4Addr field in a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to set the field in.
 * @param p_ipv4_addr The value to copy into the IpAddr object.
 *
 * @return @a ip_addr.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv4_addr(data_collection_model_ip_addr_t *ip_addr, const char* p_ipv4_addr);

/** Move a value to the ipv4Addr field in a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to set the field in.
 * @param p_ipv4_addr The value to move into the IpAddr object.
 *
 * @return @a ip_addr.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv4_addr_move(data_collection_model_ip_addr_t *ip_addr, char* p_ipv4_addr);

/** Check if the ipv6Addr field of a IpAddr object is set
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to examine.
 *
 * @return `true` if the optional ipv6Addr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_addr_has_ipv6_addr(const data_collection_model_ip_addr_t *ip_addr);


/** Get the value of the ipv6Addr field of a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to examine.
 *
 * @return the value current set for the ipv6Addr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ipv6_addr_t* data_collection_model_ip_addr_get_ipv6_addr(const data_collection_model_ip_addr_t *ip_addr);

/** Set the value of the ipv6Addr field in a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to set the field in.
 * @param p_ipv6_addr The value to copy into the IpAddr object.
 *
 * @return @a ip_addr.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_addr(data_collection_model_ip_addr_t *ip_addr, const data_collection_model_ipv6_addr_t* p_ipv6_addr);

/** Move a value to the ipv6Addr field in a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to set the field in.
 * @param p_ipv6_addr The value to move into the IpAddr object.
 *
 * @return @a ip_addr.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_addr_move(data_collection_model_ip_addr_t *ip_addr, data_collection_model_ipv6_addr_t* p_ipv6_addr);

/** Check if the ipv6Prefix field of a IpAddr object is set
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to examine.
 *
 * @return `true` if the optional ipv6Prefix field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_addr_has_ipv6_prefix(const data_collection_model_ip_addr_t *ip_addr);


/** Get the value of the ipv6Prefix field of a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to examine.
 *
 * @return the value current set for the ipv6Prefix field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ipv6_prefix_t* data_collection_model_ip_addr_get_ipv6_prefix(const data_collection_model_ip_addr_t *ip_addr);

/** Set the value of the ipv6Prefix field in a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to set the field in.
 * @param p_ipv6_prefix The value to copy into the IpAddr object.
 *
 * @return @a ip_addr.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_prefix(data_collection_model_ip_addr_t *ip_addr, const data_collection_model_ipv6_prefix_t* p_ipv6_prefix);

/** Move a value to the ipv6Prefix field in a IpAddr object
 * \public \memberof data_collection_model_ip_addr_t
 *
 * @param ip_addr The IpAddr object to set the field in.
 * @param p_ipv6_prefix The value to move into the IpAddr object.
 *
 * @return @a ip_addr.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_prefix_move(data_collection_model_ip_addr_t *ip_addr, data_collection_model_ipv6_prefix_t* p_ipv6_prefix);

/** lnode helper for generating ogs_list_t nodes's of type IpAddr
 * \public \memberof data_collection_model_ip_addr_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ip_addr object.
 * The @a ip_addr will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ip_addr The IpAddr object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ip_addr
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ip_addr_make_lnode(data_collection_model_ip_addr_t *ip_addr);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_IP_ADDR_H_ */

