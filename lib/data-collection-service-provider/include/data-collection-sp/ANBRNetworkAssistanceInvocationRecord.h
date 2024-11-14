#ifndef _DATA_COLLECTION_ANBR_NETWORK_ASSISTANCE_INVOCATION_RECORD_H_
#define _DATA_COLLECTION_ANBR_NETWORK_ASSISTANCE_INVOCATION_RECORD_H_

/**********************************************************************************************************************************
 * ANBRNetworkAssistanceInvocationRecord - Public C interface to the ANBRNetworkAssistanceInvocationRecord object
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

#include "NetworkAssistanceInvocation_recommendedQoS.h"
#include "TypedLocation.h"
#include "UnidirectionalQoSSpecification.h"
#include "ApplicationFlowDescription.h"
#include "Snssai.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ANBRNetworkAssistanceInvocationRecord object reference
 */
typedef struct data_collection_model_anbr_network_assistance_invocation_record_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_anbr_network_assistance_invocation_record_t;



/** Create a new ANBRNetworkAssistanceInvocationRecord.
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 * @return a new ANBRNetworkAssistanceInvocationRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_create();

/** Create a new ANBRNetworkAssistanceInvocationRecord reference.
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The ANBRNetworkAssistanceInvocationRecord to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_create_ref(const data_collection_model_anbr_network_assistance_invocation_record_t *other);

/** Create a new copy of a ANBRNetworkAssistanceInvocationRecord object.
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 * Creates a new copy of the given @a other object
 * @param other The ANBRNetworkAssistanceInvocationRecord to copy.
 * @return a new ANBRNetworkAssistanceInvocationRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_create_copy(const data_collection_model_anbr_network_assistance_invocation_record_t *other);

/** Create a new reference of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ANBRNetworkAssistanceInvocationRecord to create a new reference to.
 * @return a new ANBRNetworkAssistanceInvocationRecord object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_create_move(data_collection_model_anbr_network_assistance_invocation_record_t *other);

/** Copy the value of another ANBRNetworkAssistanceInvocationRecord into this object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 * Copies the value of @a other {{classname} object into @a anbr_network_assistance_invocation_record.
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to copy @a other into.
 * @param other The ANBRNetworkAssistanceInvocationRecord to copy the value from.
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_copy(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_anbr_network_assistance_invocation_record_t *other);

/** Move the value of another ANBRNetworkAssistanceInvocationRecord into this object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 * Discards the current value of @a anbr_network_assistance_invocation_record and moves the value of @a other
 * into @a anbr_network_assistance_invocation_record. This will leave @a other as an empty reference.
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to move @a other into.
 * @param other The ANBRNetworkAssistanceInvocationRecord to move the value from.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_anbr_network_assistance_invocation_record_t *other);

/** Delete a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 * Destroys the reference to the ANBRNetworkAssistanceInvocationRecord object and frees the value of ANBRNetworkAssistanceInvocationRecord if this is the last reference.
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_anbr_network_assistance_invocation_record_free(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Get a cJSON tree representation of a ANBRNetworkAssistanceInvocationRecord
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * Create a cJSON tree representation of the ANBRNetworkAssistanceInvocationRecord object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_anbr_network_assistance_invocation_record_toJSON(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, bool as_request);

/** Parse a cJSON tree into a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * Attempts to interpret a cJSON tree as a ANBRNetworkAssistanceInvocationRecord API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ANBRNetworkAssistanceInvocationRecord object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ANBRNetworkAssistanceInvocationRecord object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ANBRNetworkAssistanceInvocationRecord objects to see if they are equivalent
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param anbr_network_assistance_invocation_record The first ANBRNetworkAssistanceInvocationRecord object to compare.
 * @param other_anbr_network_assistance_invocation_record The second ANBRNetworkAssistanceInvocationRecord object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_anbr_network_assistance_invocation_record_is_equal_to(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_anbr_network_assistance_invocation_record_t *other_anbr_network_assistance_invocation_record);



/** Get the value of the timestamp field of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return the value current set for the timestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_anbr_network_assistance_invocation_record_get_timestamp(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Set the value of the timestamp field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_timestamp The value to copy into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_timestamp(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const char* p_timestamp);

/** Move a value to the timestamp field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_timestamp The value to move into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_timestamp_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, char* p_timestamp);


/** Get the value of the contextIds field of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return the value current set for the contextIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_anbr_network_assistance_invocation_record_get_context_ids(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Set the value of the contextIds field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_context_ids The value to copy into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const ogs_list_t* p_context_ids);

/** Move a value to the contextIds field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_context_ids The value to move into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_context_ids_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, ogs_list_t* p_context_ids);

/** Add a new item to the contextIds array in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to add the array item to.
 * @param context_ids The value to add.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_add_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, char* context_ids);

/** Remove an item from the contextIds array in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to remove the array value from.
 * @param context_ids The value to remove.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_remove_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const char* context_ids);

/** Get an item from the contextIds array in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_anbr_network_assistance_invocation_record_get_entry_context_ids(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, size_t idx);

/** Remove all entries from the contextIds array in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to empty contextIds for.
 *
 * @return @a anbr_network_assistance_invocation_record
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_clear_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Check if the sliceInfo field of a ANBRNetworkAssistanceInvocationRecord object is set
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return `true` if the optional sliceInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_anbr_network_assistance_invocation_record_has_slice_info(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);


/** Get the value of the sliceInfo field of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return the value current set for the sliceInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_anbr_network_assistance_invocation_record_get_slice_info(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Set the value of the sliceInfo field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_slice_info The value to copy into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_slice_info(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_snssai_t* p_slice_info);

/** Move a value to the sliceInfo field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_slice_info The value to move into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_slice_info_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_snssai_t* p_slice_info);

/** Check if the dataNetworkName field of a ANBRNetworkAssistanceInvocationRecord object is set
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return `true` if the optional dataNetworkName field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_anbr_network_assistance_invocation_record_has_data_network_name(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);


/** Get the value of the dataNetworkName field of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return the value current set for the dataNetworkName field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_anbr_network_assistance_invocation_record_get_data_network_name(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Set the value of the dataNetworkName field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_data_network_name The value to copy into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_data_network_name(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const char* p_data_network_name);

/** Move a value to the dataNetworkName field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_data_network_name The value to move into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_data_network_name_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, char* p_data_network_name);

/** Check if the location field of a ANBRNetworkAssistanceInvocationRecord object is set
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return `true` if the optional location field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_anbr_network_assistance_invocation_record_has_location(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);


/** Get the value of the location field of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return the value current set for the location field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_typed_location_t* data_collection_model_anbr_network_assistance_invocation_record_get_location(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Set the value of the location field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_location The value to copy into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_location(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_typed_location_t* p_location);

/** Move a value to the location field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_location The value to move into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_location_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_typed_location_t* p_location);


/** Get the value of the sessionId field of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return the value current set for the sessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_anbr_network_assistance_invocation_record_get_session_id(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Set the value of the sessionId field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_session_id The value to copy into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_session_id(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const char* p_session_id);

/** Move a value to the sessionId field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_session_id The value to move into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_session_id_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, char* p_session_id);

/** Check if the policyTemplateId field of a ANBRNetworkAssistanceInvocationRecord object is set
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return `true` if the optional policyTemplateId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_anbr_network_assistance_invocation_record_has_policy_template_id(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);


/** Get the value of the policyTemplateId field of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return the value current set for the policyTemplateId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_anbr_network_assistance_invocation_record_get_policy_template_id(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Set the value of the policyTemplateId field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_policy_template_id The value to copy into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_policy_template_id(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const char* p_policy_template_id);

/** Move a value to the policyTemplateId field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_policy_template_id The value to move into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_policy_template_id_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, char* p_policy_template_id);

/** Check if the applicationFlowDescriptions field of a ANBRNetworkAssistanceInvocationRecord object is set
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return `true` if the optional applicationFlowDescriptions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_anbr_network_assistance_invocation_record_has_application_flow_descriptions(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);


/** Get the value of the applicationFlowDescriptions field of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return the value current set for the applicationFlowDescriptions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_anbr_network_assistance_invocation_record_get_application_flow_descriptions(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Set the value of the applicationFlowDescriptions field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_application_flow_descriptions The value to copy into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const ogs_list_t* p_application_flow_descriptions);

/** Move a value to the applicationFlowDescriptions field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_application_flow_descriptions The value to move into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_application_flow_descriptions_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, ogs_list_t* p_application_flow_descriptions);

/** Add a new item to the applicationFlowDescriptions array in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to add the array item to.
 * @param application_flow_descriptions The value to add.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_add_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_application_flow_description_t* application_flow_descriptions);

/** Remove an item from the applicationFlowDescriptions array in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to remove the array value from.
 * @param application_flow_descriptions The value to remove.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_remove_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_application_flow_description_t* application_flow_descriptions);

/** Get an item from the applicationFlowDescriptions array in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_application_flow_description_t* data_collection_model_anbr_network_assistance_invocation_record_get_entry_application_flow_descriptions(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, size_t idx);

/** Remove all entries from the applicationFlowDescriptions array in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to empty applicationFlowDescriptions for.
 *
 * @return @a anbr_network_assistance_invocation_record
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_clear_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Check if the requestedQoS field of a ANBRNetworkAssistanceInvocationRecord object is set
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return `true` if the optional requestedQoS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_anbr_network_assistance_invocation_record_has_requested_qo_s(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);


/** Get the value of the requestedQoS field of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return the value current set for the requestedQoS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_anbr_network_assistance_invocation_record_get_requested_qo_s(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Set the value of the requestedQoS field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_requested_qo_s The value to copy into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_requested_qo_s(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

/** Move a value to the requestedQoS field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_requested_qo_s The value to move into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_requested_qo_s_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

/** Check if the recommendedQoS field of a ANBRNetworkAssistanceInvocationRecord object is set
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return `true` if the optional recommendedQoS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_anbr_network_assistance_invocation_record_has_recommended_qo_s(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);


/** Get the value of the recommendedQoS field of a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to examine.
 *
 * @return the value current set for the recommendedQoS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_invocation_recommended_qo_s_t* data_collection_model_anbr_network_assistance_invocation_record_get_recommended_qo_s(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/** Set the value of the recommendedQoS field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_recommended_qo_s The value to copy into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_recommended_qo_s(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s);

/** Move a value to the recommendedQoS field in a ANBRNetworkAssistanceInvocationRecord object
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to set the field in.
 * @param p_recommended_qo_s The value to move into the ANBRNetworkAssistanceInvocationRecord object.
 *
 * @return @a anbr_network_assistance_invocation_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_recommended_qo_s_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s);

/** lnode helper for generating ogs_list_t nodes's of type ANBRNetworkAssistanceInvocationRecord
 * \public \memberof data_collection_model_anbr_network_assistance_invocation_record_t
 *
 * Creates a new data_collection_lnode_t object containing the @a anbr_network_assistance_invocation_record object.
 * The @a anbr_network_assistance_invocation_record will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param anbr_network_assistance_invocation_record The ANBRNetworkAssistanceInvocationRecord object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a anbr_network_assistance_invocation_record
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_anbr_network_assistance_invocation_record_make_lnode(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ANBR_NETWORK_ASSISTANCE_INVOCATION_RECORD_H_ */

