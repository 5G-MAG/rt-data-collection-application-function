#ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_EVENT_H_
#define _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_EVENT_H_

/**********************************************************************************************************************************
 * NetworkAssistanceInvocationEvent - Public C interface to the NetworkAssistanceInvocationEvent object
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
#include "EventRecordType.h"
#include "UnidirectionalQoSSpecification.h"
#include "NetworkAssistanceType.h"
#include "ApplicationFlowDescription.h"
#include "LocationArea5G.h"
#include "Snssai.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP NetworkAssistanceInvocationEvent object reference
 */
typedef struct data_collection_model_network_assistance_invocation_event_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_network_assistance_invocation_event_t;



/** Create a new NetworkAssistanceInvocationEvent.
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 * @return a new NetworkAssistanceInvocationEvent object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_create();

/** Create a new NetworkAssistanceInvocationEvent reference.
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The NetworkAssistanceInvocationEvent to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_create_ref(const data_collection_model_network_assistance_invocation_event_t *other);

/** Create a new copy of a NetworkAssistanceInvocationEvent object.
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 * Creates a new copy of the given @a other object
 * @param other The NetworkAssistanceInvocationEvent to copy.
 * @return a new NetworkAssistanceInvocationEvent object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_create_copy(const data_collection_model_network_assistance_invocation_event_t *other);

/** Create a new reference of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 * Creates a reference to the same underlying @a other object.
 * @param other The NetworkAssistanceInvocationEvent to create a new reference to.
 * @return a new NetworkAssistanceInvocationEvent object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_create_move(data_collection_model_network_assistance_invocation_event_t *other);

/** Copy the value of another NetworkAssistanceInvocationEvent into this object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 * Copies the value of @a other {{classname} object into @a network_assistance_invocation_event.
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to copy @a other into.
 * @param other The NetworkAssistanceInvocationEvent to copy the value from.
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_copy(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_network_assistance_invocation_event_t *other);

/** Move the value of another NetworkAssistanceInvocationEvent into this object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 * Discards the current value of @a network_assistance_invocation_event and moves the value of @a other
 * into @a network_assistance_invocation_event. This will leave @a other as an empty reference.
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to move @a other into.
 * @param other The NetworkAssistanceInvocationEvent to move the value from.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, data_collection_model_network_assistance_invocation_event_t *other);

/** Delete a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 * Destroys the reference to the NetworkAssistanceInvocationEvent object and frees the value of NetworkAssistanceInvocationEvent if this is the last reference.
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_invocation_event_free(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Get a cJSON tree representation of a NetworkAssistanceInvocationEvent
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * Create a cJSON tree representation of the NetworkAssistanceInvocationEvent object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_invocation_event_toJSON(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, bool as_request);

/** Parse a cJSON tree into a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * Attempts to interpret a cJSON tree as a NetworkAssistanceInvocationEvent API request or response (dependent on @a as_request value). If successful
 * will return a new referenced NetworkAssistanceInvocationEvent object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new NetworkAssistanceInvocationEvent object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two NetworkAssistanceInvocationEvent objects to see if they are equivalent
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param network_assistance_invocation_event The first NetworkAssistanceInvocationEvent object to compare.
 * @param other_network_assistance_invocation_event The second NetworkAssistanceInvocationEvent object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_is_equal_to(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_network_assistance_invocation_event_t *other_network_assistance_invocation_event);



/** Get the value of the recordType field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the recordType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_record_type_t* data_collection_model_network_assistance_invocation_event_get_record_type(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the recordType field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_record_type The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_type(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_event_record_type_t* p_record_type);

/** Move a value to the recordType field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_record_type The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_type_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, data_collection_model_event_record_type_t* p_record_type);


/** Get the value of the recordTimestamp field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the recordTimestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_record_timestamp(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the recordTimestamp field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_record_timestamp The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_timestamp(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const char* p_record_timestamp);

/** Move a value to the recordTimestamp field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_record_timestamp The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_record_timestamp_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, char* p_record_timestamp);


/** Get the value of the appId field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the appId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_app_id(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the appId field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_app_id The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_app_id(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const char* p_app_id);

/** Move a value to the appId field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_app_id The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_app_id_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, char* p_app_id);

/** Check if the provisioningSessionId field of a NetworkAssistanceInvocationEvent object is set
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return `true` if the optional provisioningSessionId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_provisioning_session_id(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the provisioningSessionId field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the provisioningSessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_provisioning_session_id(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the provisioningSessionId field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_provisioning_session_id The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_provisioning_session_id(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const char* p_provisioning_session_id);

/** Move a value to the provisioningSessionId field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_provisioning_session_id The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_provisioning_session_id_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, char* p_provisioning_session_id);

/** Check if the sessionId field of a NetworkAssistanceInvocationEvent object is set
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return `true` if the optional sessionId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_session_id(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the sessionId field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the sessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_session_id(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the sessionId field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_session_id The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_session_id(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const char* p_session_id);

/** Move a value to the sessionId field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_session_id The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_session_id_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, char* p_session_id);

/** Check if the ueIdentification field of a NetworkAssistanceInvocationEvent object is set
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return `true` if the optional ueIdentification field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_ue_identification(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the ueIdentification field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the ueIdentification field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_ue_identification(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the ueIdentification field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_ue_identification The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_identification(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const char* p_ue_identification);

/** Move a value to the ueIdentification field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_ue_identification The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_identification_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, char* p_ue_identification);

/** Check if the dataNetworkName field of a NetworkAssistanceInvocationEvent object is set
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return `true` if the optional dataNetworkName field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_data_network_name(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the dataNetworkName field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the dataNetworkName field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_data_network_name(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the dataNetworkName field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_data_network_name The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_data_network_name(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const char* p_data_network_name);

/** Move a value to the dataNetworkName field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_data_network_name The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_data_network_name_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, char* p_data_network_name);

/** Check if the sliceId field of a NetworkAssistanceInvocationEvent object is set
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return `true` if the optional sliceId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_slice_id(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the sliceId field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the sliceId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_network_assistance_invocation_event_get_slice_id(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the sliceId field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_slice_id The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_slice_id(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_snssai_t* p_slice_id);

/** Move a value to the sliceId field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_slice_id The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_slice_id_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, data_collection_model_snssai_t* p_slice_id);

/** Check if the ueLocations field of a NetworkAssistanceInvocationEvent object is set
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return `true` if the optional ueLocations field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_ue_locations(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the ueLocations field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the ueLocations field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_assistance_invocation_event_get_ue_locations(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the ueLocations field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_ue_locations The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_locations(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const ogs_list_t* p_ue_locations);

/** Move a value to the ueLocations field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_ue_locations The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_ue_locations_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, ogs_list_t* p_ue_locations);

/** Add a new item to the ueLocations array in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to add the array item to.
 * @param ue_locations The value to add.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_add_ue_locations(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, data_collection_model_location_area5_g_t* ue_locations);

/** Remove an item from the ueLocations array in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to remove the array value from.
 * @param ue_locations The value to remove.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_remove_ue_locations(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_location_area5_g_t* ue_locations);

/** Get an item from the ueLocations array in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_network_assistance_invocation_event_get_entry_ue_locations(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, size_t idx);

/** Remove all entries from the ueLocations array in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to empty ueLocations for.
 *
 * @return @a network_assistance_invocation_event
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_clear_ue_locations(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the networkAssistanceType field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the networkAssistanceType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_type_t* data_collection_model_network_assistance_invocation_event_get_network_assistance_type(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the networkAssistanceType field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_network_assistance_type The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_network_assistance_type(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_network_assistance_type_t* p_network_assistance_type);

/** Move a value to the networkAssistanceType field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_network_assistance_type The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_network_assistance_type_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, data_collection_model_network_assistance_type_t* p_network_assistance_type);

/** Check if the policyTemplateId field of a NetworkAssistanceInvocationEvent object is set
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return `true` if the optional policyTemplateId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_policy_template_id(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the policyTemplateId field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the policyTemplateId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_event_get_policy_template_id(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the policyTemplateId field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_policy_template_id The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_policy_template_id(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const char* p_policy_template_id);

/** Move a value to the policyTemplateId field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_policy_template_id The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_policy_template_id_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, char* p_policy_template_id);

/** Check if the applicationFlowDescriptions field of a NetworkAssistanceInvocationEvent object is set
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return `true` if the optional applicationFlowDescriptions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_application_flow_descriptions(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the applicationFlowDescriptions field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the applicationFlowDescriptions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_assistance_invocation_event_get_application_flow_descriptions(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the applicationFlowDescriptions field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_application_flow_descriptions The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const ogs_list_t* p_application_flow_descriptions);

/** Move a value to the applicationFlowDescriptions field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_application_flow_descriptions The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_application_flow_descriptions_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, ogs_list_t* p_application_flow_descriptions);

/** Add a new item to the applicationFlowDescriptions array in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to add the array item to.
 * @param application_flow_descriptions The value to add.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_add_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, data_collection_model_application_flow_description_t* application_flow_descriptions);

/** Remove an item from the applicationFlowDescriptions array in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to remove the array value from.
 * @param application_flow_descriptions The value to remove.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_remove_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_application_flow_description_t* application_flow_descriptions);

/** Get an item from the applicationFlowDescriptions array in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_application_flow_description_t* data_collection_model_network_assistance_invocation_event_get_entry_application_flow_descriptions(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, size_t idx);

/** Remove all entries from the applicationFlowDescriptions array in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to empty applicationFlowDescriptions for.
 *
 * @return @a network_assistance_invocation_event
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_clear_application_flow_descriptions(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Check if the requestedQoS field of a NetworkAssistanceInvocationEvent object is set
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return `true` if the optional requestedQoS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_requested_qo_s(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the requestedQoS field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the requestedQoS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_network_assistance_invocation_event_get_requested_qo_s(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the requestedQoS field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_requested_qo_s The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_requested_qo_s(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

/** Move a value to the requestedQoS field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_requested_qo_s The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_requested_qo_s_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s);

/** Check if the recommendedQoS field of a NetworkAssistanceInvocationEvent object is set
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return `true` if the optional recommendedQoS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_has_recommended_qo_s(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);


/** Get the value of the recommendedQoS field of a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to examine.
 *
 * @return the value current set for the recommendedQoS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_invocation_recommended_qo_s_t* data_collection_model_network_assistance_invocation_event_get_recommended_qo_s(const data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/** Set the value of the recommendedQoS field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_recommended_qo_s The value to copy into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_recommended_qo_s(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, const data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s);

/** Move a value to the recommendedQoS field in a NetworkAssistanceInvocationEvent object
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to set the field in.
 * @param p_recommended_qo_s The value to move into the NetworkAssistanceInvocationEvent object.
 *
 * @return @a network_assistance_invocation_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_t *data_collection_model_network_assistance_invocation_event_set_recommended_qo_s_move(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event, data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s);

/** lnode helper for generating ogs_list_t nodes's of type NetworkAssistanceInvocationEvent
 * \public \memberof data_collection_model_network_assistance_invocation_event_t
 *
 * Creates a new data_collection_lnode_t object containing the @a network_assistance_invocation_event object.
 * The @a network_assistance_invocation_event will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param network_assistance_invocation_event The NetworkAssistanceInvocationEvent object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a network_assistance_invocation_event
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_invocation_event_make_lnode(data_collection_model_network_assistance_invocation_event_t *network_assistance_invocation_event);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NETWORK_ASSISTANCE_INVOCATION_EVENT_H_ */

