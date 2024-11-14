#ifndef _DATA_COLLECTION_EXCEPTION_INFO_H_
#define _DATA_COLLECTION_EXCEPTION_INFO_H_

/**********************************************************************************************************************************
 * ExceptionInfo - Public C interface to the ExceptionInfo object
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

#include "FlowInfo.h"
#include "EthFlowDescription.h"
#include "Exception.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ExceptionInfo object reference
 */
typedef struct data_collection_model_exception_info_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_exception_info_t;



/** Create a new ExceptionInfo.
 * \public \memberof data_collection_model_exception_info_t
 * @return a new ExceptionInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_create();

/** Create a new ExceptionInfo reference.
 * \public \memberof data_collection_model_exception_info_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The ExceptionInfo to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_create_ref(const data_collection_model_exception_info_t *other);

/** Create a new copy of a ExceptionInfo object.
 * \public \memberof data_collection_model_exception_info_t
 * Creates a new copy of the given @a other object
 * @param other The ExceptionInfo to copy.
 * @return a new ExceptionInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_create_copy(const data_collection_model_exception_info_t *other);

/** Create a new reference of a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ExceptionInfo to create a new reference to.
 * @return a new ExceptionInfo object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_create_move(data_collection_model_exception_info_t *other);

/** Copy the value of another ExceptionInfo into this object
 * \public \memberof data_collection_model_exception_info_t
 * Copies the value of @a other {{classname} object into @a exception_info.
 * @param exception_info The ExceptionInfo object to copy @a other into.
 * @param other The ExceptionInfo to copy the value from.
 * @return @a exception_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_copy(data_collection_model_exception_info_t *exception_info, const data_collection_model_exception_info_t *other);

/** Move the value of another ExceptionInfo into this object
 * \public \memberof data_collection_model_exception_info_t
 * Discards the current value of @a exception_info and moves the value of @a other
 * into @a exception_info. This will leave @a other as an empty reference.
 *
 * @param exception_info The ExceptionInfo object to move @a other into.
 * @param other The ExceptionInfo to move the value from.
 *
 * @return @a exception_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_move(data_collection_model_exception_info_t *exception_info, data_collection_model_exception_info_t *other);

/** Delete a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 * Destroys the reference to the ExceptionInfo object and frees the value of ExceptionInfo if this is the last reference.
 *
 * @param exception_info The ExceptionInfo to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_exception_info_free(data_collection_model_exception_info_t *exception_info);

/** Get a cJSON tree representation of a ExceptionInfo
 * \public \memberof data_collection_model_exception_info_t
 *
 * Create a cJSON tree representation of the ExceptionInfo object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param exception_info The ExceptionInfo to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_exception_info_toJSON(const data_collection_model_exception_info_t *exception_info, bool as_request);

/** Parse a cJSON tree into a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * Attempts to interpret a cJSON tree as a ExceptionInfo API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ExceptionInfo object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ExceptionInfo object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ExceptionInfo objects to see if they are equivalent
 * \public \memberof data_collection_model_exception_info_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param exception_info The first ExceptionInfo object to compare.
 * @param other_exception_info The second ExceptionInfo object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_info_is_equal_to(const data_collection_model_exception_info_t *exception_info, const data_collection_model_exception_info_t *other_exception_info);


/** Check if the ipTrafficFilter field of a ExceptionInfo object is set
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to examine.
 *
 * @return `true` if the optional ipTrafficFilter field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_info_has_ip_traffic_filter(const data_collection_model_exception_info_t *exception_info);


/** Get the value of the ipTrafficFilter field of a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to examine.
 *
 * @return the value current set for the ipTrafficFilter field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_info_t* data_collection_model_exception_info_get_ip_traffic_filter(const data_collection_model_exception_info_t *exception_info);

/** Set the value of the ipTrafficFilter field in a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to set the field in.
 * @param p_ip_traffic_filter The value to copy into the ExceptionInfo object.
 *
 * @return @a exception_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_ip_traffic_filter(data_collection_model_exception_info_t *exception_info, const data_collection_model_flow_info_t* p_ip_traffic_filter);

/** Move a value to the ipTrafficFilter field in a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to set the field in.
 * @param p_ip_traffic_filter The value to move into the ExceptionInfo object.
 *
 * @return @a exception_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_ip_traffic_filter_move(data_collection_model_exception_info_t *exception_info, data_collection_model_flow_info_t* p_ip_traffic_filter);

/** Check if the ethTrafficFilter field of a ExceptionInfo object is set
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to examine.
 *
 * @return `true` if the optional ethTrafficFilter field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_info_has_eth_traffic_filter(const data_collection_model_exception_info_t *exception_info);


/** Get the value of the ethTrafficFilter field of a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to examine.
 *
 * @return the value current set for the ethTrafficFilter field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_eth_flow_description_t* data_collection_model_exception_info_get_eth_traffic_filter(const data_collection_model_exception_info_t *exception_info);

/** Set the value of the ethTrafficFilter field in a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to set the field in.
 * @param p_eth_traffic_filter The value to copy into the ExceptionInfo object.
 *
 * @return @a exception_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_eth_traffic_filter(data_collection_model_exception_info_t *exception_info, const data_collection_model_eth_flow_description_t* p_eth_traffic_filter);

/** Move a value to the ethTrafficFilter field in a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to set the field in.
 * @param p_eth_traffic_filter The value to move into the ExceptionInfo object.
 *
 * @return @a exception_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_eth_traffic_filter_move(data_collection_model_exception_info_t *exception_info, data_collection_model_eth_flow_description_t* p_eth_traffic_filter);


/** Get the value of the exceps field of a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to examine.
 *
 * @return the value current set for the exceps field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_exception_info_get_exceps(const data_collection_model_exception_info_t *exception_info);

/** Set the value of the exceps field in a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to set the field in.
 * @param p_exceps The value to copy into the ExceptionInfo object.
 *
 * @return @a exception_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_exceps(data_collection_model_exception_info_t *exception_info, const ogs_list_t* p_exceps);

/** Move a value to the exceps field in a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to set the field in.
 * @param p_exceps The value to move into the ExceptionInfo object.
 *
 * @return @a exception_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_set_exceps_move(data_collection_model_exception_info_t *exception_info, ogs_list_t* p_exceps);

/** Add a new item to the exceps array in a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to add the array item to.
 * @param exceps The value to add.
 *
 * @return @a exception_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_add_exceps(data_collection_model_exception_info_t *exception_info, data_collection_model_exception_t* exceps);

/** Remove an item from the exceps array in a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to remove the array value from.
 * @param exceps The value to remove.
 *
 * @return @a exception_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_remove_exceps(data_collection_model_exception_info_t *exception_info, const data_collection_model_exception_t* exceps);

/** Get an item from the exceps array in a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_exception_t* data_collection_model_exception_info_get_entry_exceps(const data_collection_model_exception_info_t *exception_info, size_t idx);

/** Remove all entries from the exceps array in a ExceptionInfo object
 * \public \memberof data_collection_model_exception_info_t
 *
 * @param exception_info The ExceptionInfo object to empty exceps for.
 *
 * @return @a exception_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_info_t *data_collection_model_exception_info_clear_exceps(data_collection_model_exception_info_t *exception_info);

/** lnode helper for generating ogs_list_t nodes's of type ExceptionInfo
 * \public \memberof data_collection_model_exception_info_t
 *
 * Creates a new data_collection_lnode_t object containing the @a exception_info object.
 * The @a exception_info will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param exception_info The ExceptionInfo object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a exception_info
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_exception_info_make_lnode(data_collection_model_exception_info_t *exception_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_EXCEPTION_INFO_H_ */

