#ifndef _DATA_COLLECTION_ETH_FLOW_DESCRIPTION_H_
#define _DATA_COLLECTION_ETH_FLOW_DESCRIPTION_H_

/**********************************************************************************************************************************
 * EthFlowDescription - Public C interface to the EthFlowDescription object
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

#include "FlowDirection.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP EthFlowDescription object reference
 */
typedef struct data_collection_model_eth_flow_description_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_eth_flow_description_t;



/** Create a new EthFlowDescription
 * \public \memberof data_collection_model_eth_flow_description_t
 * @return a new EthFlowDescription object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_create();

/** Create a new copy of a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 * Creates a new copy of the given @a other object
 * @param other The EthFlowDescription to copy.
 * @return a new EthFlowDescription object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_create_copy(const data_collection_model_eth_flow_description_t *other);

/** Create a new reference of a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 * Creates a reference to the same underlying @a other object.
 * @param other The EthFlowDescription to create a new reference to.
 * @return a new EthFlowDescription object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_create_move(data_collection_model_eth_flow_description_t *other);

/** Copy the value of another EthFlowDescription into this object
 * \public \memberof data_collection_model_eth_flow_description_t
 * Copies the value of @a other {{classname} object into @a eth_flow_description.
 * @param eth_flow_description The EthFlowDescription object to copy @a other into.
 * @param other The EthFlowDescription to copy the value from.
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_copy(data_collection_model_eth_flow_description_t *eth_flow_description, const data_collection_model_eth_flow_description_t *other);

/** Move the value of another EthFlowDescription into this object
 * \public \memberof data_collection_model_eth_flow_description_t
 * Discards the current value of @a eth_flow_description and moves the value of @a other
 * into @a eth_flow_description. This will leave @a other as an empty reference.
 *
 * @param eth_flow_description The EthFlowDescription object to move @a other into.
 * @param other The EthFlowDescription to move the value from.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_move(data_collection_model_eth_flow_description_t *eth_flow_description, data_collection_model_eth_flow_description_t *other);

/** Delete a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 * Destroys the reference to the EthFlowDescription object and frees the value of EthFlowDescription if this is the last reference.
 *
 * @param eth_flow_description The EthFlowDescription to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_eth_flow_description_free(data_collection_model_eth_flow_description_t *eth_flow_description);

/** Get a cJSON tree representation of a EthFlowDescription
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * Create a cJSON tree representation of the EthFlowDescription object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param eth_flow_description The EthFlowDescription to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_eth_flow_description_toJSON(const data_collection_model_eth_flow_description_t *eth_flow_description, bool as_request);

/** Parse a cJSON tree into a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * Attempts to interpret a cJSON tree as a EthFlowDescription API request or response (dependent on @a as_request value). If successful
 * will return a new referenced EthFlowDescription object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new EthFlowDescription object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two EthFlowDescription objects to see if they are equivalent
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param eth_flow_description The first EthFlowDescription object to compare.
 * @param other_eth_flow_description The second EthFlowDescription object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_eth_flow_description_is_equal_to(const data_collection_model_eth_flow_description_t *eth_flow_description, const data_collection_model_eth_flow_description_t *other_eth_flow_description);


/** Check if the destMacAddr field of a EthFlowDescription object is set
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return `true` if the optional destMacAddr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_eth_flow_description_has_dest_mac_addr(const data_collection_model_eth_flow_description_t *eth_flow_description);


/** Get the value of the destMacAddr field of a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return the value current set for the destMacAddr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_dest_mac_addr(const data_collection_model_eth_flow_description_t *eth_flow_description);

/** Set the value of the destMacAddr field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_dest_mac_addr The value to copy into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_dest_mac_addr);

/** Move a value to the destMacAddr field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_dest_mac_addr The value to move into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_dest_mac_addr);


/** Get the value of the ethType field of a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return the value current set for the ethType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_eth_type(const data_collection_model_eth_flow_description_t *eth_flow_description);

/** Set the value of the ethType field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_eth_type The value to copy into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_eth_type(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_eth_type);

/** Move a value to the ethType field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_eth_type The value to move into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_eth_type_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_eth_type);

/** Check if the fDesc field of a EthFlowDescription object is set
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return `true` if the optional fDesc field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_eth_flow_description_has_f_desc(const data_collection_model_eth_flow_description_t *eth_flow_description);


/** Get the value of the fDesc field of a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return the value current set for the fDesc field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_f_desc(const data_collection_model_eth_flow_description_t *eth_flow_description);

/** Set the value of the fDesc field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_f_desc The value to copy into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_desc(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_f_desc);

/** Move a value to the fDesc field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_f_desc The value to move into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_desc_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_f_desc);

/** Check if the fDir field of a EthFlowDescription object is set
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return `true` if the optional fDir field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_eth_flow_description_has_f_dir(const data_collection_model_eth_flow_description_t *eth_flow_description);


/** Get the value of the fDir field of a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return the value current set for the fDir field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_direction_t* data_collection_model_eth_flow_description_get_f_dir(const data_collection_model_eth_flow_description_t *eth_flow_description);

/** Set the value of the fDir field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_f_dir The value to copy into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_dir(data_collection_model_eth_flow_description_t *eth_flow_description, const data_collection_model_flow_direction_t* p_f_dir);

/** Move a value to the fDir field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_f_dir The value to move into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_f_dir_move(data_collection_model_eth_flow_description_t *eth_flow_description, data_collection_model_flow_direction_t* p_f_dir);

/** Check if the sourceMacAddr field of a EthFlowDescription object is set
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return `true` if the optional sourceMacAddr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_eth_flow_description_has_source_mac_addr(const data_collection_model_eth_flow_description_t *eth_flow_description);


/** Get the value of the sourceMacAddr field of a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return the value current set for the sourceMacAddr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_source_mac_addr(const data_collection_model_eth_flow_description_t *eth_flow_description);

/** Set the value of the sourceMacAddr field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_source_mac_addr The value to copy into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_source_mac_addr(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_source_mac_addr);

/** Move a value to the sourceMacAddr field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_source_mac_addr The value to move into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_source_mac_addr_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_source_mac_addr);

/** Check if the vlanTags field of a EthFlowDescription object is set
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return `true` if the optional vlanTags field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_eth_flow_description_has_vlan_tags(const data_collection_model_eth_flow_description_t *eth_flow_description);


/** Get the value of the vlanTags field of a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return the value current set for the vlanTags field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_eth_flow_description_get_vlan_tags(const data_collection_model_eth_flow_description_t *eth_flow_description);

/** Set the value of the vlanTags field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_vlan_tags The value to copy into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_vlan_tags(data_collection_model_eth_flow_description_t *eth_flow_description, const ogs_list_t* p_vlan_tags);

/** Move a value to the vlanTags field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_vlan_tags The value to move into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_vlan_tags_move(data_collection_model_eth_flow_description_t *eth_flow_description, ogs_list_t* p_vlan_tags);

/** Add a new item to the vlanTags array in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to add the array item to.
 * @param vlan_tags The value to add.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_add_vlan_tags(data_collection_model_eth_flow_description_t *eth_flow_description, char* vlan_tags);

/** Remove an item from the vlanTags array in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to remove the array value from.
 * @param vlan_tags The value to remove.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_remove_vlan_tags(data_collection_model_eth_flow_description_t *eth_flow_description, const char* vlan_tags);

/** Get an item from the vlanTags array in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_entry_vlan_tags(const data_collection_model_eth_flow_description_t *eth_flow_description, size_t idx);

/** Remove all entries from the vlanTags array in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to empty vlanTags for.
 *
 * @return @a eth_flow_description
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_clear_vlan_tags(data_collection_model_eth_flow_description_t *eth_flow_description);

/** Check if the srcMacAddrEnd field of a EthFlowDescription object is set
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return `true` if the optional srcMacAddrEnd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_eth_flow_description_has_src_mac_addr_end(const data_collection_model_eth_flow_description_t *eth_flow_description);


/** Get the value of the srcMacAddrEnd field of a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return the value current set for the srcMacAddrEnd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_src_mac_addr_end(const data_collection_model_eth_flow_description_t *eth_flow_description);

/** Set the value of the srcMacAddrEnd field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_src_mac_addr_end The value to copy into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_src_mac_addr_end(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_src_mac_addr_end);

/** Move a value to the srcMacAddrEnd field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_src_mac_addr_end The value to move into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_src_mac_addr_end_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_src_mac_addr_end);

/** Check if the destMacAddrEnd field of a EthFlowDescription object is set
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return `true` if the optional destMacAddrEnd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_eth_flow_description_has_dest_mac_addr_end(const data_collection_model_eth_flow_description_t *eth_flow_description);


/** Get the value of the destMacAddrEnd field of a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to examine.
 *
 * @return the value current set for the destMacAddrEnd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_eth_flow_description_get_dest_mac_addr_end(const data_collection_model_eth_flow_description_t *eth_flow_description);

/** Set the value of the destMacAddrEnd field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_dest_mac_addr_end The value to copy into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr_end(data_collection_model_eth_flow_description_t *eth_flow_description, const char* p_dest_mac_addr_end);

/** Move a value to the destMacAddrEnd field in a EthFlowDescription object
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * @param eth_flow_description The EthFlowDescription object to set the field in.
 * @param p_dest_mac_addr_end The value to move into the EthFlowDescription object.
 *
 * @return @a eth_flow_description.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_eth_flow_description_t *data_collection_model_eth_flow_description_set_dest_mac_addr_end_move(data_collection_model_eth_flow_description_t *eth_flow_description, char* p_dest_mac_addr_end);

/** lnode helper for generating ogs_list_t nodes's of type EthFlowDescription
 * \public \memberof data_collection_model_eth_flow_description_t
 *
 * Creates a new data_collection_lnode_t object containing the @a eth_flow_description object.
 * The @a eth_flow_description will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param eth_flow_description The EthFlowDescription object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a eth_flow_description
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_eth_flow_description_make_lnode(data_collection_model_eth_flow_description_t *eth_flow_description);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ETH_FLOW_DESCRIPTION_H_ */

