#ifndef _DATA_COLLECTION_CONSUMPTION_REPORTING_EVENT_H_
#define _DATA_COLLECTION_CONSUMPTION_REPORTING_EVENT_H_

/**********************************************************************************************************************************
 * ConsumptionReportingEvent - Public C interface to the ConsumptionReportingEvent object
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

#include "EventRecordType.h"
#include "LocationArea5G.h"
#include "Snssai.h"
#include "EndpointAddress.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ConsumptionReportingEvent object reference
 */
typedef struct data_collection_model_consumption_reporting_event_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_consumption_reporting_event_t;



/** Create a new ConsumptionReportingEvent
 * \public \memberof data_collection_model_consumption_reporting_event_t
 * @return a new ConsumptionReportingEvent object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_create();

/** Create a new copy of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 * Creates a new copy of the given @a other object
 * @param other The ConsumptionReportingEvent to copy.
 * @return a new ConsumptionReportingEvent object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_create_copy(const data_collection_model_consumption_reporting_event_t *other);

/** Create a new reference of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ConsumptionReportingEvent to create a new reference to.
 * @return a new ConsumptionReportingEvent object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_create_move(data_collection_model_consumption_reporting_event_t *other);

/** Copy the value of another ConsumptionReportingEvent into this object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 * Copies the value of @a other {{classname} object into @a consumption_reporting_event.
 * @param consumption_reporting_event The ConsumptionReportingEvent object to copy @a other into.
 * @param other The ConsumptionReportingEvent to copy the value from.
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_copy(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const data_collection_model_consumption_reporting_event_t *other);

/** Move the value of another ConsumptionReportingEvent into this object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 * Discards the current value of @a consumption_reporting_event and moves the value of @a other
 * into @a consumption_reporting_event. This will leave @a other as an empty reference.
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to move @a other into.
 * @param other The ConsumptionReportingEvent to move the value from.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, data_collection_model_consumption_reporting_event_t *other);

/** Delete a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 * Destroys the reference to the ConsumptionReportingEvent object and frees the value of ConsumptionReportingEvent if this is the last reference.
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_consumption_reporting_event_free(data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Get a cJSON tree representation of a ConsumptionReportingEvent
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * Create a cJSON tree representation of the ConsumptionReportingEvent object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_consumption_reporting_event_toJSON(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event, bool as_request);

/** Parse a cJSON tree into a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * Attempts to interpret a cJSON tree as a ConsumptionReportingEvent API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ConsumptionReportingEvent object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ConsumptionReportingEvent object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ConsumptionReportingEvent objects to see if they are equivalent
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param consumption_reporting_event The first ConsumptionReportingEvent object to compare.
 * @param other_consumption_reporting_event The second ConsumptionReportingEvent object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_is_equal_to(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const data_collection_model_consumption_reporting_event_t *other_consumption_reporting_event);



/** Get the value of the recordType field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the recordType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_event_record_type_t* data_collection_model_consumption_reporting_event_get_record_type(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the recordType field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_record_type The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_record_type(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const data_collection_model_event_record_type_t* p_record_type);

/** Move a value to the recordType field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_record_type The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_record_type_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, data_collection_model_event_record_type_t* p_record_type);


/** Get the value of the recordTimestamp field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the recordTimestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_record_timestamp(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the recordTimestamp field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_record_timestamp The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_record_timestamp(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const char* p_record_timestamp);

/** Move a value to the recordTimestamp field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_record_timestamp The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_record_timestamp_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, char* p_record_timestamp);


/** Get the value of the appId field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the appId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_app_id(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the appId field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_app_id The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_app_id(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const char* p_app_id);

/** Move a value to the appId field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_app_id The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_app_id_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, char* p_app_id);

/** Check if the provisioningSessionId field of a ConsumptionReportingEvent object is set
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return `true` if the optional provisioningSessionId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_provisioning_session_id(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);


/** Get the value of the provisioningSessionId field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the provisioningSessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_provisioning_session_id(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the provisioningSessionId field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_provisioning_session_id The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_provisioning_session_id(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const char* p_provisioning_session_id);

/** Move a value to the provisioningSessionId field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_provisioning_session_id The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_provisioning_session_id_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, char* p_provisioning_session_id);

/** Check if the sessionId field of a ConsumptionReportingEvent object is set
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return `true` if the optional sessionId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_session_id(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);


/** Get the value of the sessionId field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the sessionId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_session_id(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the sessionId field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_session_id The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_session_id(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const char* p_session_id);

/** Move a value to the sessionId field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_session_id The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_session_id_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, char* p_session_id);

/** Check if the ueIdentification field of a ConsumptionReportingEvent object is set
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return `true` if the optional ueIdentification field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_ue_identification(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);


/** Get the value of the ueIdentification field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the ueIdentification field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_ue_identification(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the ueIdentification field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_ue_identification The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_ue_identification(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const char* p_ue_identification);

/** Move a value to the ueIdentification field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_ue_identification The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_ue_identification_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, char* p_ue_identification);

/** Check if the dataNetworkName field of a ConsumptionReportingEvent object is set
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return `true` if the optional dataNetworkName field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_data_network_name(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);


/** Get the value of the dataNetworkName field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the dataNetworkName field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_data_network_name(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the dataNetworkName field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_data_network_name The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_data_network_name(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const char* p_data_network_name);

/** Move a value to the dataNetworkName field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_data_network_name The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_data_network_name_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, char* p_data_network_name);

/** Check if the sliceId field of a ConsumptionReportingEvent object is set
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return `true` if the optional sliceId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_slice_id(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);


/** Get the value of the sliceId field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the sliceId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_consumption_reporting_event_get_slice_id(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the sliceId field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_slice_id The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_slice_id(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const data_collection_model_snssai_t* p_slice_id);

/** Move a value to the sliceId field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_slice_id The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_slice_id_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, data_collection_model_snssai_t* p_slice_id);

/** Check if the ueLocations field of a ConsumptionReportingEvent object is set
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return `true` if the optional ueLocations field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_ue_locations(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);


/** Get the value of the ueLocations field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the ueLocations field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_consumption_reporting_event_get_ue_locations(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the ueLocations field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_ue_locations The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_ue_locations(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const ogs_list_t* p_ue_locations);

/** Move a value to the ueLocations field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_ue_locations The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_ue_locations_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, ogs_list_t* p_ue_locations);

/** Add a new item to the ueLocations array in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to add the array item to.
 * @param ue_locations The value to add.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_add_ue_locations(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, data_collection_model_location_area5_g_t* ue_locations);

/** Remove an item from the ueLocations array in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to remove the array value from.
 * @param ue_locations The value to remove.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_remove_ue_locations(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const data_collection_model_location_area5_g_t* ue_locations);

/** Get an item from the ueLocations array in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_consumption_reporting_event_get_entry_ue_locations(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event, size_t idx);

/** Remove all entries from the ueLocations array in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to empty ueLocations for.
 *
 * @return @a consumption_reporting_event
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_clear_ue_locations(data_collection_model_consumption_reporting_event_t *consumption_reporting_event);


/** Get the value of the unitDuration field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the unitDuration field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_unit_duration(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the unitDuration field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_unit_duration The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_unit_duration(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const char* p_unit_duration);

/** Move a value to the unitDuration field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_unit_duration The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_unit_duration_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, char* p_unit_duration);

/** Check if the clientEndpointAddress field of a ConsumptionReportingEvent object is set
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return `true` if the optional clientEndpointAddress field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_client_endpoint_address(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);


/** Get the value of the clientEndpointAddress field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the clientEndpointAddress field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_consumption_reporting_event_get_client_endpoint_address(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the clientEndpointAddress field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_client_endpoint_address The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_client_endpoint_address(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const data_collection_model_endpoint_address_t* p_client_endpoint_address);

/** Move a value to the clientEndpointAddress field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_client_endpoint_address The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_client_endpoint_address_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, data_collection_model_endpoint_address_t* p_client_endpoint_address);

/** Check if the serverEndpointAddress field of a ConsumptionReportingEvent object is set
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return `true` if the optional serverEndpointAddress field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_has_server_endpoint_address(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);


/** Get the value of the serverEndpointAddress field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the serverEndpointAddress field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_consumption_reporting_event_get_server_endpoint_address(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the serverEndpointAddress field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_server_endpoint_address The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_server_endpoint_address(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const data_collection_model_endpoint_address_t* p_server_endpoint_address);

/** Move a value to the serverEndpointAddress field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_server_endpoint_address The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_server_endpoint_address_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, data_collection_model_endpoint_address_t* p_server_endpoint_address);


/** Get the value of the mediaPlayerEntryUrl field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the mediaPlayerEntryUrl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_media_player_entry_url(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the mediaPlayerEntryUrl field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_media_player_entry_url The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_media_player_entry_url(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const char* p_media_player_entry_url);

/** Move a value to the mediaPlayerEntryUrl field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_media_player_entry_url The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_media_player_entry_url_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, char* p_media_player_entry_url);


/** Get the value of the mediaComponentIdentifier field of a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to examine.
 *
 * @return the value current set for the mediaComponentIdentifier field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_get_media_component_identifier(const data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/** Set the value of the mediaComponentIdentifier field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_media_component_identifier The value to copy into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_media_component_identifier(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, const char* p_media_component_identifier);

/** Move a value to the mediaComponentIdentifier field in a ConsumptionReportingEvent object
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to set the field in.
 * @param p_media_component_identifier The value to move into the ConsumptionReportingEvent object.
 *
 * @return @a consumption_reporting_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_t *data_collection_model_consumption_reporting_event_set_media_component_identifier_move(data_collection_model_consumption_reporting_event_t *consumption_reporting_event, char* p_media_component_identifier);

/** lnode helper for generating ogs_list_t nodes's of type ConsumptionReportingEvent
 * \public \memberof data_collection_model_consumption_reporting_event_t
 *
 * Creates a new data_collection_lnode_t object containing the @a consumption_reporting_event object.
 * The @a consumption_reporting_event will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param consumption_reporting_event The ConsumptionReportingEvent object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a consumption_reporting_event
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_consumption_reporting_event_make_lnode(data_collection_model_consumption_reporting_event_t *consumption_reporting_event);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_CONSUMPTION_REPORTING_EVENT_H_ */

