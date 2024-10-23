#ifndef _DATA_COLLECTION_CP_PARAMETER_SET_H_
#define _DATA_COLLECTION_CP_PARAMETER_SET_H_

/**********************************************************************************************************************************
 * CpParameterSet - Public C interface to the CpParameterSet object
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

#include "BatteryIndication.h"
#include "CommunicationIndicator.h"
#include "ScheduledCommunicationType.h"
#include "TrafficProfile.h"
#include "AppExpUeBehaviour.h"
#include "ScheduledCommunicationTime.h"
#include "UmtLocationArea5G.h"
#include "StationaryIndication.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP CpParameterSet object reference
 */
typedef struct data_collection_model_cp_parameter_set_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_cp_parameter_set_t;



/** Create a new CpParameterSet
 * \public \memberof data_collection_model_cp_parameter_set_t
 * @return a new CpParameterSet object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_create();

/** Create a new copy of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 * Creates a new copy of the given @a other object
 * @param other The CpParameterSet to copy.
 * @return a new CpParameterSet object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_create_copy(const data_collection_model_cp_parameter_set_t *other);

/** Create a new reference of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 * Creates a reference to the same underlying @a other object.
 * @param other The CpParameterSet to create a new reference to.
 * @return a new CpParameterSet object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_create_move(data_collection_model_cp_parameter_set_t *other);

/** Copy the value of another CpParameterSet into this object
 * \public \memberof data_collection_model_cp_parameter_set_t
 * Copies the value of @a other {{classname} object into @a cp_parameter_set.
 * @param cp_parameter_set The CpParameterSet object to copy @a other into.
 * @param other The CpParameterSet to copy the value from.
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_copy(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_cp_parameter_set_t *other);

/** Move the value of another CpParameterSet into this object
 * \public \memberof data_collection_model_cp_parameter_set_t
 * Discards the current value of @a cp_parameter_set and moves the value of @a other
 * into @a cp_parameter_set. This will leave @a other as an empty reference.
 *
 * @param cp_parameter_set The CpParameterSet object to move @a other into.
 * @param other The CpParameterSet to move the value from.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_cp_parameter_set_t *other);

/** Delete a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 * Destroys the reference to the CpParameterSet object and frees the value of CpParameterSet if this is the last reference.
 *
 * @param cp_parameter_set The CpParameterSet to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_cp_parameter_set_free(data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Get a cJSON tree representation of a CpParameterSet
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * Create a cJSON tree representation of the CpParameterSet object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param cp_parameter_set The CpParameterSet to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_cp_parameter_set_toJSON(const data_collection_model_cp_parameter_set_t *cp_parameter_set, bool as_request);

/** Parse a cJSON tree into a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * Attempts to interpret a cJSON tree as a CpParameterSet API request or response (dependent on @a as_request value). If successful
 * will return a new referenced CpParameterSet object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new CpParameterSet object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two CpParameterSet objects to see if they are equivalent
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param cp_parameter_set The first CpParameterSet object to compare.
 * @param other_cp_parameter_set The second CpParameterSet object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_is_equal_to(const data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_cp_parameter_set_t *other_cp_parameter_set);



/** Get the value of the setId field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the setId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_cp_parameter_set_get_set_id(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the setId field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_set_id The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_set_id(data_collection_model_cp_parameter_set_t *cp_parameter_set, const char* p_set_id);

/** Move a value to the setId field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_set_id The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_set_id_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, char* p_set_id);

/** Check if the self field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional self field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_self(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the self field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the self field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_cp_parameter_set_get_self(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the self field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_self The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_self(data_collection_model_cp_parameter_set_t *cp_parameter_set, const char* p_self);

/** Move a value to the self field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_self The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_self_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, char* p_self);

/** Check if the validityTime field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional validityTime field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_validity_time(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the validityTime field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the validityTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_cp_parameter_set_get_validity_time(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the validityTime field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_validity_time The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_validity_time(data_collection_model_cp_parameter_set_t *cp_parameter_set, const char* p_validity_time);

/** Move a value to the validityTime field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_validity_time The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_validity_time_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, char* p_validity_time);

/** Check if the periodicCommunicationIndicator field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional periodicCommunicationIndicator field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_periodic_communication_indicator(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the periodicCommunicationIndicator field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the periodicCommunicationIndicator field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_communication_indicator_t* data_collection_model_cp_parameter_set_get_periodic_communication_indicator(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the periodicCommunicationIndicator field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_periodic_communication_indicator The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_communication_indicator(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_communication_indicator_t* p_periodic_communication_indicator);

/** Move a value to the periodicCommunicationIndicator field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_periodic_communication_indicator The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_communication_indicator_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_communication_indicator_t* p_periodic_communication_indicator);

/** Check if the communicationDurationTime field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional communicationDurationTime field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_communication_duration_time(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the communicationDurationTime field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the communicationDurationTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_cp_parameter_set_get_communication_duration_time(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the communicationDurationTime field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_communication_duration_time The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_communication_duration_time(data_collection_model_cp_parameter_set_t *cp_parameter_set, const int32_t p_communication_duration_time);

/** Move a value to the communicationDurationTime field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_communication_duration_time The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_communication_duration_time_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, int32_t p_communication_duration_time);

/** Check if the periodicTime field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional periodicTime field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_periodic_time(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the periodicTime field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the periodicTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_cp_parameter_set_get_periodic_time(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the periodicTime field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_periodic_time The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_time(data_collection_model_cp_parameter_set_t *cp_parameter_set, const int32_t p_periodic_time);

/** Move a value to the periodicTime field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_periodic_time The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_time_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, int32_t p_periodic_time);

/** Check if the scheduledCommunicationTime field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional scheduledCommunicationTime field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_scheduled_communication_time(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the scheduledCommunicationTime field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the scheduledCommunicationTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_scheduled_communication_time_t* data_collection_model_cp_parameter_set_get_scheduled_communication_time(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the scheduledCommunicationTime field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_scheduled_communication_time The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_time(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_scheduled_communication_time_t* p_scheduled_communication_time);

/** Move a value to the scheduledCommunicationTime field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_scheduled_communication_time The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_time_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_scheduled_communication_time_t* p_scheduled_communication_time);

/** Check if the scheduledCommunicationType field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional scheduledCommunicationType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_scheduled_communication_type(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the scheduledCommunicationType field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the scheduledCommunicationType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_scheduled_communication_type_t* data_collection_model_cp_parameter_set_get_scheduled_communication_type(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the scheduledCommunicationType field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_scheduled_communication_type The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_type(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_scheduled_communication_type_t* p_scheduled_communication_type);

/** Move a value to the scheduledCommunicationType field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_scheduled_communication_type The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_type_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_scheduled_communication_type_t* p_scheduled_communication_type);

/** Check if the stationaryIndication field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional stationaryIndication field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_stationary_indication(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the stationaryIndication field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the stationaryIndication field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_stationary_indication_t* data_collection_model_cp_parameter_set_get_stationary_indication(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the stationaryIndication field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_stationary_indication The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_stationary_indication(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_stationary_indication_t* p_stationary_indication);

/** Move a value to the stationaryIndication field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_stationary_indication The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_stationary_indication_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_stationary_indication_t* p_stationary_indication);

/** Check if the batteryInds field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional batteryInds field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_battery_inds(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the batteryInds field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the batteryInds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_cp_parameter_set_get_battery_inds(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the batteryInds field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_battery_inds The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_battery_inds(data_collection_model_cp_parameter_set_t *cp_parameter_set, const ogs_list_t* p_battery_inds);

/** Move a value to the batteryInds field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_battery_inds The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_battery_inds_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, ogs_list_t* p_battery_inds);

/** Add a new item to the batteryInds array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to add the array item to.
 * @param battery_inds The value to add.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_add_battery_inds(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_battery_indication_t* battery_inds);

/** Remove an item from the batteryInds array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to remove the array value from.
 * @param battery_inds The value to remove.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_remove_battery_inds(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_battery_indication_t* battery_inds);

/** Get an item from the batteryInds array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_battery_indication_t* data_collection_model_cp_parameter_set_get_entry_battery_inds(const data_collection_model_cp_parameter_set_t *cp_parameter_set, size_t idx);

/** Remove all entries from the batteryInds array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to empty batteryInds for.
 *
 * @return @a cp_parameter_set
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_clear_battery_inds(data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Check if the trafficProfile field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional trafficProfile field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_traffic_profile(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the trafficProfile field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the trafficProfile field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_traffic_profile_t* data_collection_model_cp_parameter_set_get_traffic_profile(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the trafficProfile field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_traffic_profile The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_traffic_profile(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_traffic_profile_t* p_traffic_profile);

/** Move a value to the trafficProfile field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_traffic_profile The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_traffic_profile_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_traffic_profile_t* p_traffic_profile);

/** Check if the expectedUmts field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional expectedUmts field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_expected_umts(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the expectedUmts field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the expectedUmts field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_cp_parameter_set_get_expected_umts(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the expectedUmts field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_expected_umts The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umts(data_collection_model_cp_parameter_set_t *cp_parameter_set, const ogs_list_t* p_expected_umts);

/** Move a value to the expectedUmts field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_expected_umts The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umts_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, ogs_list_t* p_expected_umts);

/** Add a new item to the expectedUmts array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to add the array item to.
 * @param expected_umts The value to add.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_add_expected_umts(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_umt_location_area5_g_t* expected_umts);

/** Remove an item from the expectedUmts array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to remove the array value from.
 * @param expected_umts The value to remove.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_remove_expected_umts(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_umt_location_area5_g_t* expected_umts);

/** Get an item from the expectedUmts array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_umt_location_area5_g_t* data_collection_model_cp_parameter_set_get_entry_expected_umts(const data_collection_model_cp_parameter_set_t *cp_parameter_set, size_t idx);

/** Remove all entries from the expectedUmts array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to empty expectedUmts for.
 *
 * @return @a cp_parameter_set
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_clear_expected_umts(data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Check if the expectedUmtDays field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional expectedUmtDays field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_expected_umt_days(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the expectedUmtDays field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the expectedUmtDays field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_cp_parameter_set_get_expected_umt_days(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the expectedUmtDays field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_expected_umt_days The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days(data_collection_model_cp_parameter_set_t *cp_parameter_set, const int32_t p_expected_umt_days);

/** Move a value to the expectedUmtDays field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_expected_umt_days The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, int32_t p_expected_umt_days);

/** Check if the expectedUmtDaysAdd field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional expectedUmtDaysAdd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_expected_umt_days_add(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the expectedUmtDaysAdd field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the expectedUmtDaysAdd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_cp_parameter_set_get_expected_umt_days_add(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the expectedUmtDaysAdd field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_expected_umt_days_add The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days_add(data_collection_model_cp_parameter_set_t *cp_parameter_set, const ogs_list_t* p_expected_umt_days_add);

/** Move a value to the expectedUmtDaysAdd field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_expected_umt_days_add The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days_add_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, ogs_list_t* p_expected_umt_days_add);

/** Add a new item to the expectedUmtDaysAdd array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to add the array item to.
 * @param expected_umt_days_add The value to add.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_add_expected_umt_days_add(data_collection_model_cp_parameter_set_t *cp_parameter_set, int32_t expected_umt_days_add);

/** Remove an item from the expectedUmtDaysAdd array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to remove the array value from.
 * @param expected_umt_days_add The value to remove.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_remove_expected_umt_days_add(data_collection_model_cp_parameter_set_t *cp_parameter_set, const int32_t expected_umt_days_add);

/** Get an item from the expectedUmtDaysAdd array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_cp_parameter_set_get_entry_expected_umt_days_add(const data_collection_model_cp_parameter_set_t *cp_parameter_set, size_t idx);

/** Remove all entries from the expectedUmtDaysAdd array in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to empty expectedUmtDaysAdd for.
 *
 * @return @a cp_parameter_set
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_clear_expected_umt_days_add(data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Check if the appExpUeBehv field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional appExpUeBehv field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_app_exp_ue_behv(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the appExpUeBehv field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the appExpUeBehv field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_app_exp_ue_behaviour_t* data_collection_model_cp_parameter_set_get_app_exp_ue_behv(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the appExpUeBehv field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_app_exp_ue_behv The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_app_exp_ue_behv(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_app_exp_ue_behaviour_t* p_app_exp_ue_behv);

/** Move a value to the appExpUeBehv field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_app_exp_ue_behv The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_app_exp_ue_behv_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_app_exp_ue_behaviour_t* p_app_exp_ue_behv);

/** Check if the confidenceLevel field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional confidenceLevel field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_confidence_level(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the confidenceLevel field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the confidenceLevel field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_cp_parameter_set_get_confidence_level(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the confidenceLevel field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_confidence_level The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_confidence_level(data_collection_model_cp_parameter_set_t *cp_parameter_set, const char* p_confidence_level);

/** Move a value to the confidenceLevel field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_confidence_level The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_confidence_level_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, char* p_confidence_level);

/** Check if the accuracyLevel field of a CpParameterSet object is set
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return `true` if the optional accuracyLevel field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_accuracy_level(const data_collection_model_cp_parameter_set_t *cp_parameter_set);


/** Get the value of the accuracyLevel field of a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to examine.
 *
 * @return the value current set for the accuracyLevel field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_cp_parameter_set_get_accuracy_level(const data_collection_model_cp_parameter_set_t *cp_parameter_set);

/** Set the value of the accuracyLevel field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_accuracy_level The value to copy into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_accuracy_level(data_collection_model_cp_parameter_set_t *cp_parameter_set, const char* p_accuracy_level);

/** Move a value to the accuracyLevel field in a CpParameterSet object
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * @param cp_parameter_set The CpParameterSet object to set the field in.
 * @param p_accuracy_level The value to move into the CpParameterSet object.
 *
 * @return @a cp_parameter_set.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_accuracy_level_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, char* p_accuracy_level);

/** lnode helper for generating ogs_list_t nodes's of type CpParameterSet
 * \public \memberof data_collection_model_cp_parameter_set_t
 *
 * Creates a new data_collection_lnode_t object containing the @a cp_parameter_set object.
 * The @a cp_parameter_set will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param cp_parameter_set The CpParameterSet object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a cp_parameter_set
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_cp_parameter_set_make_lnode(data_collection_model_cp_parameter_set_t *cp_parameter_set);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_CP_PARAMETER_SET_H_ */

