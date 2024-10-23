#ifndef _DATA_COLLECTION_FLOW_INFO_H_
#define _DATA_COLLECTION_FLOW_INFO_H_

/**********************************************************************************************************************************
 * FlowInfo - Public C interface to the FlowInfo object
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

/** A 3GPP FlowInfo object reference
 */
typedef struct data_collection_model_flow_info_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_flow_info_t;



/** Create a new FlowInfo
 * \public \memberof data_collection_model_flow_info_t
 * @return a new FlowInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_create();

/** Create a new copy of a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 * Creates a new copy of the given @a other object
 * @param other The FlowInfo to copy.
 * @return a new FlowInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_create_copy(const data_collection_model_flow_info_t *other);

/** Create a new reference of a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 * Creates a reference to the same underlying @a other object.
 * @param other The FlowInfo to create a new reference to.
 * @return a new FlowInfo object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_create_move(data_collection_model_flow_info_t *other);

/** Copy the value of another FlowInfo into this object
 * \public \memberof data_collection_model_flow_info_t
 * Copies the value of @a other {{classname} object into @a flow_info.
 * @param flow_info The FlowInfo object to copy @a other into.
 * @param other The FlowInfo to copy the value from.
 * @return @a flow_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_copy(data_collection_model_flow_info_t *flow_info, const data_collection_model_flow_info_t *other);

/** Move the value of another FlowInfo into this object
 * \public \memberof data_collection_model_flow_info_t
 * Discards the current value of @a flow_info and moves the value of @a other
 * into @a flow_info. This will leave @a other as an empty reference.
 *
 * @param flow_info The FlowInfo object to move @a other into.
 * @param other The FlowInfo to move the value from.
 *
 * @return @a flow_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_move(data_collection_model_flow_info_t *flow_info, data_collection_model_flow_info_t *other);

/** Delete a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 * Destroys the reference to the FlowInfo object and frees the value of FlowInfo if this is the last reference.
 *
 * @param flow_info The FlowInfo to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_flow_info_free(data_collection_model_flow_info_t *flow_info);

/** Get a cJSON tree representation of a FlowInfo
 * \public \memberof data_collection_model_flow_info_t
 *
 * Create a cJSON tree representation of the FlowInfo object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param flow_info The FlowInfo to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_flow_info_toJSON(const data_collection_model_flow_info_t *flow_info, bool as_request);

/** Parse a cJSON tree into a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * Attempts to interpret a cJSON tree as a FlowInfo API request or response (dependent on @a as_request value). If successful
 * will return a new referenced FlowInfo object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new FlowInfo object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two FlowInfo objects to see if they are equivalent
 * \public \memberof data_collection_model_flow_info_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param flow_info The first FlowInfo object to compare.
 * @param other_flow_info The second FlowInfo object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_info_is_equal_to(const data_collection_model_flow_info_t *flow_info, const data_collection_model_flow_info_t *other_flow_info);



/** Get the value of the flowId field of a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to examine.
 *
 * @return the value current set for the flowId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_flow_info_get_flow_id(const data_collection_model_flow_info_t *flow_info);

/** Set the value of the flowId field in a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to set the field in.
 * @param p_flow_id The value to copy into the FlowInfo object.
 *
 * @return @a flow_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_id(data_collection_model_flow_info_t *flow_info, const int32_t p_flow_id);

/** Move a value to the flowId field in a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to set the field in.
 * @param p_flow_id The value to move into the FlowInfo object.
 *
 * @return @a flow_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_id_move(data_collection_model_flow_info_t *flow_info, int32_t p_flow_id);

/** Check if the flowDescriptions field of a FlowInfo object is set
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to examine.
 *
 * @return `true` if the optional flowDescriptions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_info_has_flow_descriptions(const data_collection_model_flow_info_t *flow_info);


/** Get the value of the flowDescriptions field of a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to examine.
 *
 * @return the value current set for the flowDescriptions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_flow_info_get_flow_descriptions(const data_collection_model_flow_info_t *flow_info);

/** Set the value of the flowDescriptions field in a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to set the field in.
 * @param p_flow_descriptions The value to copy into the FlowInfo object.
 *
 * @return @a flow_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_descriptions(data_collection_model_flow_info_t *flow_info, const ogs_list_t* p_flow_descriptions);

/** Move a value to the flowDescriptions field in a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to set the field in.
 * @param p_flow_descriptions The value to move into the FlowInfo object.
 *
 * @return @a flow_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_flow_descriptions_move(data_collection_model_flow_info_t *flow_info, ogs_list_t* p_flow_descriptions);

/** Add a new item to the flowDescriptions array in a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to add the array item to.
 * @param flow_descriptions The value to add.
 *
 * @return @a flow_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_add_flow_descriptions(data_collection_model_flow_info_t *flow_info, char* flow_descriptions);

/** Remove an item from the flowDescriptions array in a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to remove the array value from.
 * @param flow_descriptions The value to remove.
 *
 * @return @a flow_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_remove_flow_descriptions(data_collection_model_flow_info_t *flow_info, const char* flow_descriptions);

/** Get an item from the flowDescriptions array in a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_flow_info_get_entry_flow_descriptions(const data_collection_model_flow_info_t *flow_info, size_t idx);

/** Remove all entries from the flowDescriptions array in a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to empty flowDescriptions for.
 *
 * @return @a flow_info
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_clear_flow_descriptions(data_collection_model_flow_info_t *flow_info);

/** Check if the tosTC field of a FlowInfo object is set
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to examine.
 *
 * @return `true` if the optional tosTC field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_info_has_tos_tc(const data_collection_model_flow_info_t *flow_info);


/** Get the value of the tosTC field of a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to examine.
 *
 * @return the value current set for the tosTC field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_flow_info_get_tos_tc(const data_collection_model_flow_info_t *flow_info);

/** Set the value of the tosTC field in a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to set the field in.
 * @param p_tos_tc The value to copy into the FlowInfo object.
 *
 * @return @a flow_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_tos_tc(data_collection_model_flow_info_t *flow_info, const char* p_tos_tc);

/** Move a value to the tosTC field in a FlowInfo object
 * \public \memberof data_collection_model_flow_info_t
 *
 * @param flow_info The FlowInfo object to set the field in.
 * @param p_tos_tc The value to move into the FlowInfo object.
 *
 * @return @a flow_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_info_t *data_collection_model_flow_info_set_tos_tc_move(data_collection_model_flow_info_t *flow_info, char* p_tos_tc);

/** lnode helper for generating ogs_list_t nodes's of type FlowInfo
 * \public \memberof data_collection_model_flow_info_t
 *
 * Creates a new data_collection_lnode_t object containing the @a flow_info object.
 * The @a flow_info will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param flow_info The FlowInfo object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a flow_info
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_flow_info_make_lnode(data_collection_model_flow_info_t *flow_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_FLOW_INFO_H_ */

