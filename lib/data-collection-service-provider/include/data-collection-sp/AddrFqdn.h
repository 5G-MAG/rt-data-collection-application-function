#ifndef _DATA_COLLECTION_ADDR_FQDN_H_
#define _DATA_COLLECTION_ADDR_FQDN_H_

/**********************************************************************************************************************************
 * AddrFqdn - Public C interface to the AddrFqdn object
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

#include "IpAddr.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP AddrFqdn object reference
 */
typedef struct data_collection_model_addr_fqdn_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_addr_fqdn_t;



/** Create a new AddrFqdn.
 * \public \memberof data_collection_model_addr_fqdn_t
 * @return a new AddrFqdn object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create();

/** Create a new AddrFqdn reference.
 * \public \memberof data_collection_model_addr_fqdn_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The AddrFqdn to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create_ref(const data_collection_model_addr_fqdn_t *other);

/** Create a new copy of a AddrFqdn object.
 * \public \memberof data_collection_model_addr_fqdn_t
 * Creates a new copy of the given @a other object
 * @param other The AddrFqdn to copy.
 * @return a new AddrFqdn object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create_copy(const data_collection_model_addr_fqdn_t *other);

/** Create a new reference of a AddrFqdn object
 * \public \memberof data_collection_model_addr_fqdn_t
 * Creates a reference to the same underlying @a other object.
 * @param other The AddrFqdn to create a new reference to.
 * @return a new AddrFqdn object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create_move(data_collection_model_addr_fqdn_t *other);

/** Copy the value of another AddrFqdn into this object
 * \public \memberof data_collection_model_addr_fqdn_t
 * Copies the value of @a other {{classname} object into @a addr_fqdn.
 * @param addr_fqdn The AddrFqdn object to copy @a other into.
 * @param other The AddrFqdn to copy the value from.
 * @return @a addr_fqdn.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_copy(data_collection_model_addr_fqdn_t *addr_fqdn, const data_collection_model_addr_fqdn_t *other);

/** Move the value of another AddrFqdn into this object
 * \public \memberof data_collection_model_addr_fqdn_t
 * Discards the current value of @a addr_fqdn and moves the value of @a other
 * into @a addr_fqdn. This will leave @a other as an empty reference.
 *
 * @param addr_fqdn The AddrFqdn object to move @a other into.
 * @param other The AddrFqdn to move the value from.
 *
 * @return @a addr_fqdn.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_move(data_collection_model_addr_fqdn_t *addr_fqdn, data_collection_model_addr_fqdn_t *other);

/** Delete a AddrFqdn object
 * \public \memberof data_collection_model_addr_fqdn_t
 * Destroys the reference to the AddrFqdn object and frees the value of AddrFqdn if this is the last reference.
 *
 * @param addr_fqdn The AddrFqdn to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_addr_fqdn_free(data_collection_model_addr_fqdn_t *addr_fqdn);

/** Get a cJSON tree representation of a AddrFqdn
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * Create a cJSON tree representation of the AddrFqdn object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param addr_fqdn The AddrFqdn to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_addr_fqdn_toJSON(const data_collection_model_addr_fqdn_t *addr_fqdn, bool as_request);

/** Parse a cJSON tree into a AddrFqdn object
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * Attempts to interpret a cJSON tree as a AddrFqdn API request or response (dependent on @a as_request value). If successful
 * will return a new referenced AddrFqdn object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new AddrFqdn object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two AddrFqdn objects to see if they are equivalent
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param addr_fqdn The first AddrFqdn object to compare.
 * @param other_addr_fqdn The second AddrFqdn object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_addr_fqdn_is_equal_to(const data_collection_model_addr_fqdn_t *addr_fqdn, const data_collection_model_addr_fqdn_t *other_addr_fqdn);


/** Check if the ipAddr field of a AddrFqdn object is set
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * @param addr_fqdn The AddrFqdn object to examine.
 *
 * @return `true` if the optional ipAddr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_addr_fqdn_has_ip_addr(const data_collection_model_addr_fqdn_t *addr_fqdn);


/** Get the value of the ipAddr field of a AddrFqdn object
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * @param addr_fqdn The AddrFqdn object to examine.
 *
 * @return the value current set for the ipAddr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_addr_fqdn_get_ip_addr(const data_collection_model_addr_fqdn_t *addr_fqdn);

/** Set the value of the ipAddr field in a AddrFqdn object
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * @param addr_fqdn The AddrFqdn object to set the field in.
 * @param p_ip_addr The value to copy into the AddrFqdn object.
 *
 * @return @a addr_fqdn.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_ip_addr(data_collection_model_addr_fqdn_t *addr_fqdn, const data_collection_model_ip_addr_t* p_ip_addr);

/** Move a value to the ipAddr field in a AddrFqdn object
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * @param addr_fqdn The AddrFqdn object to set the field in.
 * @param p_ip_addr The value to move into the AddrFqdn object.
 *
 * @return @a addr_fqdn.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_ip_addr_move(data_collection_model_addr_fqdn_t *addr_fqdn, data_collection_model_ip_addr_t* p_ip_addr);

/** Check if the fqdn field of a AddrFqdn object is set
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * @param addr_fqdn The AddrFqdn object to examine.
 *
 * @return `true` if the optional fqdn field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_addr_fqdn_has_fqdn(const data_collection_model_addr_fqdn_t *addr_fqdn);


/** Get the value of the fqdn field of a AddrFqdn object
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * @param addr_fqdn The AddrFqdn object to examine.
 *
 * @return the value current set for the fqdn field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_addr_fqdn_get_fqdn(const data_collection_model_addr_fqdn_t *addr_fqdn);

/** Set the value of the fqdn field in a AddrFqdn object
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * @param addr_fqdn The AddrFqdn object to set the field in.
 * @param p_fqdn The value to copy into the AddrFqdn object.
 *
 * @return @a addr_fqdn.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_fqdn(data_collection_model_addr_fqdn_t *addr_fqdn, const char* p_fqdn);

/** Move a value to the fqdn field in a AddrFqdn object
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * @param addr_fqdn The AddrFqdn object to set the field in.
 * @param p_fqdn The value to move into the AddrFqdn object.
 *
 * @return @a addr_fqdn.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_fqdn_move(data_collection_model_addr_fqdn_t *addr_fqdn, char* p_fqdn);

/** lnode helper for generating ogs_list_t nodes's of type AddrFqdn
 * \public \memberof data_collection_model_addr_fqdn_t
 *
 * Creates a new data_collection_lnode_t object containing the @a addr_fqdn object.
 * The @a addr_fqdn will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param addr_fqdn The AddrFqdn object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a addr_fqdn
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_addr_fqdn_make_lnode(data_collection_model_addr_fqdn_t *addr_fqdn);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ADDR_FQDN_H_ */

