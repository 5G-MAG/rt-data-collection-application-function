#ifndef _DATA_COLLECTION_LOCATION_DATA_H_
#define _DATA_COLLECTION_LOCATION_DATA_H_

/**********************************************************************************************************************************
 * LocationData - Public C interface to the LocationData object
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

#include "Ncgi.h"
#include "RangeDirection.h"
#include "CivicAddress.h"
#include "GeographicArea.h"
#include "VelocityEstimate.h"
#include "UeAreaIndication.h"
#include "LosNlosMeasureInd.h"
#include "HighAccuracyGnssMetrics.h"
#include "PeriodicEventInfo.h"
#include "IntegrityResult.h"
#include "r_3DRelativeLocation.h"
#include "GnssPositioningMethodAndUsage.h"
#include "AccuracyFulfilmentIndicator.h"
#include "Ecgi.h"
#include "r_2DRelativeLocation.h"
#include "IndoorOutdoorInd.h"
#include "PositioningMethodAndUsage.h"
#include "LocalArea.h"
#include "MinorLocationQoS.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP LocationData object reference
 */
typedef struct data_collection_model_location_data_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_location_data_t;



/** Create a new LocationData
 * \public \memberof data_collection_model_location_data_t
 * @return a new LocationData object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_create();

/** Create a new copy of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 * Creates a new copy of the given @a other object
 * @param other The LocationData to copy.
 * @return a new LocationData object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_create_copy(const data_collection_model_location_data_t *other);

/** Create a new reference of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 * Creates a reference to the same underlying @a other object.
 * @param other The LocationData to create a new reference to.
 * @return a new LocationData object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_create_move(data_collection_model_location_data_t *other);

/** Copy the value of another LocationData into this object
 * \public \memberof data_collection_model_location_data_t
 * Copies the value of @a other {{classname} object into @a location_data.
 * @param location_data The LocationData object to copy @a other into.
 * @param other The LocationData to copy the value from.
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_copy(data_collection_model_location_data_t *location_data, const data_collection_model_location_data_t *other);

/** Move the value of another LocationData into this object
 * \public \memberof data_collection_model_location_data_t
 * Discards the current value of @a location_data and moves the value of @a other
 * into @a location_data. This will leave @a other as an empty reference.
 *
 * @param location_data The LocationData object to move @a other into.
 * @param other The LocationData to move the value from.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_move(data_collection_model_location_data_t *location_data, data_collection_model_location_data_t *other);

/** Delete a LocationData object
 * \public \memberof data_collection_model_location_data_t
 * Destroys the reference to the LocationData object and frees the value of LocationData if this is the last reference.
 *
 * @param location_data The LocationData to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_location_data_free(data_collection_model_location_data_t *location_data);

/** Get a cJSON tree representation of a LocationData
 * \public \memberof data_collection_model_location_data_t
 *
 * Create a cJSON tree representation of the LocationData object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param location_data The LocationData to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_location_data_toJSON(const data_collection_model_location_data_t *location_data, bool as_request);

/** Parse a cJSON tree into a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * Attempts to interpret a cJSON tree as a LocationData API request or response (dependent on @a as_request value). If successful
 * will return a new referenced LocationData object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new LocationData object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two LocationData objects to see if they are equivalent
 * \public \memberof data_collection_model_location_data_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param location_data The first LocationData object to compare.
 * @param other_location_data The second LocationData object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_is_equal_to(const data_collection_model_location_data_t *location_data, const data_collection_model_location_data_t *other_location_data);



/** Get the value of the locationEstimate field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the locationEstimate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographic_area_t* data_collection_model_location_data_get_location_estimate(const data_collection_model_location_data_t *location_data);

/** Set the value of the locationEstimate field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_location_estimate The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_location_estimate(data_collection_model_location_data_t *location_data, const data_collection_model_geographic_area_t* p_location_estimate);

/** Move a value to the locationEstimate field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_location_estimate The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_location_estimate_move(data_collection_model_location_data_t *location_data, data_collection_model_geographic_area_t* p_location_estimate);

/** Check if the accuracyFulfilmentIndicator field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional accuracyFulfilmentIndicator field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_accuracy_fulfilment_indicator(const data_collection_model_location_data_t *location_data);


/** Get the value of the accuracyFulfilmentIndicator field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the accuracyFulfilmentIndicator field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_accuracy_fulfilment_indicator_t* data_collection_model_location_data_get_accuracy_fulfilment_indicator(const data_collection_model_location_data_t *location_data);

/** Set the value of the accuracyFulfilmentIndicator field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_accuracy_fulfilment_indicator The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_accuracy_fulfilment_indicator(data_collection_model_location_data_t *location_data, const data_collection_model_accuracy_fulfilment_indicator_t* p_accuracy_fulfilment_indicator);

/** Move a value to the accuracyFulfilmentIndicator field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_accuracy_fulfilment_indicator The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_accuracy_fulfilment_indicator_move(data_collection_model_location_data_t *location_data, data_collection_model_accuracy_fulfilment_indicator_t* p_accuracy_fulfilment_indicator);

/** Check if the ageOfLocationEstimate field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional ageOfLocationEstimate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_age_of_location_estimate(const data_collection_model_location_data_t *location_data);


/** Get the value of the ageOfLocationEstimate field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the ageOfLocationEstimate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_location_data_get_age_of_location_estimate(const data_collection_model_location_data_t *location_data);

/** Set the value of the ageOfLocationEstimate field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_age_of_location_estimate The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_age_of_location_estimate(data_collection_model_location_data_t *location_data, const int32_t p_age_of_location_estimate);

/** Move a value to the ageOfLocationEstimate field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_age_of_location_estimate The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_age_of_location_estimate_move(data_collection_model_location_data_t *location_data, int32_t p_age_of_location_estimate);

/** Check if the timestampOfLocationEstimate field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional timestampOfLocationEstimate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_timestamp_of_location_estimate(const data_collection_model_location_data_t *location_data);


/** Get the value of the timestampOfLocationEstimate field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the timestampOfLocationEstimate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_location_data_get_timestamp_of_location_estimate(const data_collection_model_location_data_t *location_data);

/** Set the value of the timestampOfLocationEstimate field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_timestamp_of_location_estimate The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_timestamp_of_location_estimate(data_collection_model_location_data_t *location_data, const char* p_timestamp_of_location_estimate);

/** Move a value to the timestampOfLocationEstimate field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_timestamp_of_location_estimate The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_timestamp_of_location_estimate_move(data_collection_model_location_data_t *location_data, char* p_timestamp_of_location_estimate);

/** Check if the velocityEstimate field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional velocityEstimate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_velocity_estimate(const data_collection_model_location_data_t *location_data);


/** Get the value of the velocityEstimate field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the velocityEstimate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_velocity_estimate_t* data_collection_model_location_data_get_velocity_estimate(const data_collection_model_location_data_t *location_data);

/** Set the value of the velocityEstimate field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_velocity_estimate The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_velocity_estimate(data_collection_model_location_data_t *location_data, const data_collection_model_velocity_estimate_t* p_velocity_estimate);

/** Move a value to the velocityEstimate field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_velocity_estimate The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_velocity_estimate_move(data_collection_model_location_data_t *location_data, data_collection_model_velocity_estimate_t* p_velocity_estimate);

/** Check if the civicAddress field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional civicAddress field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_civic_address(const data_collection_model_location_data_t *location_data);


/** Get the value of the civicAddress field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the civicAddress field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_civic_address_t* data_collection_model_location_data_get_civic_address(const data_collection_model_location_data_t *location_data);

/** Set the value of the civicAddress field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_civic_address The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_civic_address(data_collection_model_location_data_t *location_data, const data_collection_model_civic_address_t* p_civic_address);

/** Move a value to the civicAddress field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_civic_address The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_civic_address_move(data_collection_model_location_data_t *location_data, data_collection_model_civic_address_t* p_civic_address);

/** Check if the localLocationEstimate field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional localLocationEstimate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_local_location_estimate(const data_collection_model_location_data_t *location_data);


/** Get the value of the localLocationEstimate field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the localLocationEstimate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_local_area_t* data_collection_model_location_data_get_local_location_estimate(const data_collection_model_location_data_t *location_data);

/** Set the value of the localLocationEstimate field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_local_location_estimate The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_local_location_estimate(data_collection_model_location_data_t *location_data, const data_collection_model_local_area_t* p_local_location_estimate);

/** Move a value to the localLocationEstimate field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_local_location_estimate The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_local_location_estimate_move(data_collection_model_location_data_t *location_data, data_collection_model_local_area_t* p_local_location_estimate);

/** Check if the positioningDataList field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional positioningDataList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_positioning_data_list(const data_collection_model_location_data_t *location_data);


/** Get the value of the positioningDataList field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the positioningDataList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_location_data_get_positioning_data_list(const data_collection_model_location_data_t *location_data);

/** Set the value of the positioningDataList field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_positioning_data_list The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_positioning_data_list(data_collection_model_location_data_t *location_data, const ogs_list_t* p_positioning_data_list);

/** Move a value to the positioningDataList field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_positioning_data_list The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_positioning_data_list_move(data_collection_model_location_data_t *location_data, ogs_list_t* p_positioning_data_list);

/** Add a new item to the positioningDataList array in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to add the array item to.
 * @param positioning_data_list The value to add.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_add_positioning_data_list(data_collection_model_location_data_t *location_data, data_collection_model_positioning_method_and_usage_t* positioning_data_list);

/** Remove an item from the positioningDataList array in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to remove the array value from.
 * @param positioning_data_list The value to remove.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_remove_positioning_data_list(data_collection_model_location_data_t *location_data, const data_collection_model_positioning_method_and_usage_t* positioning_data_list);

/** Get an item from the positioningDataList array in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_positioning_method_and_usage_t* data_collection_model_location_data_get_entry_positioning_data_list(const data_collection_model_location_data_t *location_data, size_t idx);

/** Remove all entries from the positioningDataList array in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to empty positioningDataList for.
 *
 * @return @a location_data
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_clear_positioning_data_list(data_collection_model_location_data_t *location_data);

/** Check if the gnssPositioningDataList field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional gnssPositioningDataList field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_gnss_positioning_data_list(const data_collection_model_location_data_t *location_data);


/** Get the value of the gnssPositioningDataList field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the gnssPositioningDataList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_location_data_get_gnss_positioning_data_list(const data_collection_model_location_data_t *location_data);

/** Set the value of the gnssPositioningDataList field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_gnss_positioning_data_list The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_gnss_positioning_data_list(data_collection_model_location_data_t *location_data, const ogs_list_t* p_gnss_positioning_data_list);

/** Move a value to the gnssPositioningDataList field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_gnss_positioning_data_list The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_gnss_positioning_data_list_move(data_collection_model_location_data_t *location_data, ogs_list_t* p_gnss_positioning_data_list);

/** Add a new item to the gnssPositioningDataList array in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to add the array item to.
 * @param gnss_positioning_data_list The value to add.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_add_gnss_positioning_data_list(data_collection_model_location_data_t *location_data, data_collection_model_gnss_positioning_method_and_usage_t* gnss_positioning_data_list);

/** Remove an item from the gnssPositioningDataList array in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to remove the array value from.
 * @param gnss_positioning_data_list The value to remove.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_remove_gnss_positioning_data_list(data_collection_model_location_data_t *location_data, const data_collection_model_gnss_positioning_method_and_usage_t* gnss_positioning_data_list);

/** Get an item from the gnssPositioningDataList array in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_gnss_positioning_method_and_usage_t* data_collection_model_location_data_get_entry_gnss_positioning_data_list(const data_collection_model_location_data_t *location_data, size_t idx);

/** Remove all entries from the gnssPositioningDataList array in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to empty gnssPositioningDataList for.
 *
 * @return @a location_data
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_clear_gnss_positioning_data_list(data_collection_model_location_data_t *location_data);

/** Check if the ecgi field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional ecgi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_ecgi(const data_collection_model_location_data_t *location_data);


/** Get the value of the ecgi field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the ecgi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ecgi_t* data_collection_model_location_data_get_ecgi(const data_collection_model_location_data_t *location_data);

/** Set the value of the ecgi field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ecgi The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ecgi(data_collection_model_location_data_t *location_data, const data_collection_model_ecgi_t* p_ecgi);

/** Move a value to the ecgi field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ecgi The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ecgi_move(data_collection_model_location_data_t *location_data, data_collection_model_ecgi_t* p_ecgi);

/** Check if the ncgi field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional ncgi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_ncgi(const data_collection_model_location_data_t *location_data);


/** Get the value of the ncgi field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the ncgi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ncgi_t* data_collection_model_location_data_get_ncgi(const data_collection_model_location_data_t *location_data);

/** Set the value of the ncgi field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ncgi The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ncgi(data_collection_model_location_data_t *location_data, const data_collection_model_ncgi_t* p_ncgi);

/** Move a value to the ncgi field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ncgi The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ncgi_move(data_collection_model_location_data_t *location_data, data_collection_model_ncgi_t* p_ncgi);

/** Check if the remoteUeInd field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional remoteUeInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_remote_ue_ind(const data_collection_model_location_data_t *location_data);


/** Get the value of the remoteUeInd field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the remoteUeInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_location_data_is_remote_ue_ind(const data_collection_model_location_data_t *location_data);

/** Set the value of the remoteUeInd field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_remote_ue_ind The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_remote_ue_ind(data_collection_model_location_data_t *location_data, const bool p_remote_ue_ind);

/** Move a value to the remoteUeInd field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_remote_ue_ind The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_remote_ue_ind_move(data_collection_model_location_data_t *location_data, bool p_remote_ue_ind);

/** Check if the altitude field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional altitude field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_altitude(const data_collection_model_location_data_t *location_data);


/** Get the value of the altitude field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the altitude field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_location_data_get_altitude(const data_collection_model_location_data_t *location_data);

/** Set the value of the altitude field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_altitude The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_altitude(data_collection_model_location_data_t *location_data, const double p_altitude);

/** Move a value to the altitude field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_altitude The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_altitude_move(data_collection_model_location_data_t *location_data, double p_altitude);

/** Check if the barometricPressure field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional barometricPressure field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_barometric_pressure(const data_collection_model_location_data_t *location_data);


/** Get the value of the barometricPressure field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the barometricPressure field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_location_data_get_barometric_pressure(const data_collection_model_location_data_t *location_data);

/** Set the value of the barometricPressure field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_barometric_pressure The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_barometric_pressure(data_collection_model_location_data_t *location_data, const int32_t p_barometric_pressure);

/** Move a value to the barometricPressure field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_barometric_pressure The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_barometric_pressure_move(data_collection_model_location_data_t *location_data, int32_t p_barometric_pressure);

/** Check if the servingLMFIdentification field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional servingLMFIdentification field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_serving_lmf_identification(const data_collection_model_location_data_t *location_data);


/** Get the value of the servingLMFIdentification field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the servingLMFIdentification field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_location_data_get_serving_lmf_identification(const data_collection_model_location_data_t *location_data);

/** Set the value of the servingLMFIdentification field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_serving_lmf_identification The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_serving_lmf_identification(data_collection_model_location_data_t *location_data, const char* p_serving_lmf_identification);

/** Move a value to the servingLMFIdentification field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_serving_lmf_identification The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_serving_lmf_identification_move(data_collection_model_location_data_t *location_data, char* p_serving_lmf_identification);

/** Check if the uePositioningCap field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional uePositioningCap field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_ue_positioning_cap(const data_collection_model_location_data_t *location_data);


/** Get the value of the uePositioningCap field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the uePositioningCap field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const unsigned char* data_collection_model_location_data_get_ue_positioning_cap(const data_collection_model_location_data_t *location_data);

/** Set the value of the uePositioningCap field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ue_positioning_cap The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ue_positioning_cap(data_collection_model_location_data_t *location_data, const unsigned char* p_ue_positioning_cap);

/** Move a value to the uePositioningCap field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ue_positioning_cap The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ue_positioning_cap_move(data_collection_model_location_data_t *location_data, unsigned char* p_ue_positioning_cap);

/** Check if the ueAreaInd field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional ueAreaInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_ue_area_ind(const data_collection_model_location_data_t *location_data);


/** Get the value of the ueAreaInd field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the ueAreaInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ue_area_indication_t* data_collection_model_location_data_get_ue_area_ind(const data_collection_model_location_data_t *location_data);

/** Set the value of the ueAreaInd field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ue_area_ind The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ue_area_ind(data_collection_model_location_data_t *location_data, const data_collection_model_ue_area_indication_t* p_ue_area_ind);

/** Move a value to the ueAreaInd field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ue_area_ind The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ue_area_ind_move(data_collection_model_location_data_t *location_data, data_collection_model_ue_area_indication_t* p_ue_area_ind);

/** Check if the supportedFeatures field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional supportedFeatures field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_supported_features(const data_collection_model_location_data_t *location_data);


/** Get the value of the supportedFeatures field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the supportedFeatures field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_location_data_get_supported_features(const data_collection_model_location_data_t *location_data);

/** Set the value of the supportedFeatures field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_supported_features The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_supported_features(data_collection_model_location_data_t *location_data, const char* p_supported_features);

/** Move a value to the supportedFeatures field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_supported_features The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_supported_features_move(data_collection_model_location_data_t *location_data, char* p_supported_features);

/** Check if the achievedQos field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional achievedQos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_achieved_qos(const data_collection_model_location_data_t *location_data);


/** Get the value of the achievedQos field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the achievedQos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_minor_location_qo_s_t* data_collection_model_location_data_get_achieved_qos(const data_collection_model_location_data_t *location_data);

/** Set the value of the achievedQos field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_achieved_qos The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_achieved_qos(data_collection_model_location_data_t *location_data, const data_collection_model_minor_location_qo_s_t* p_achieved_qos);

/** Move a value to the achievedQos field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_achieved_qos The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_achieved_qos_move(data_collection_model_location_data_t *location_data, data_collection_model_minor_location_qo_s_t* p_achieved_qos);

/** Check if the directReportInd field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional directReportInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_direct_report_ind(const data_collection_model_location_data_t *location_data);


/** Get the value of the directReportInd field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the directReportInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_location_data_is_direct_report_ind(const data_collection_model_location_data_t *location_data);

/** Set the value of the directReportInd field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_direct_report_ind The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_direct_report_ind(data_collection_model_location_data_t *location_data, const bool p_direct_report_ind);

/** Move a value to the directReportInd field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_direct_report_ind The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_direct_report_ind_move(data_collection_model_location_data_t *location_data, bool p_direct_report_ind);

/** Check if the indoorOutdoorInd field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional indoorOutdoorInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_indoor_outdoor_ind(const data_collection_model_location_data_t *location_data);


/** Get the value of the indoorOutdoorInd field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the indoorOutdoorInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_indoor_outdoor_ind_t* data_collection_model_location_data_get_indoor_outdoor_ind(const data_collection_model_location_data_t *location_data);

/** Set the value of the indoorOutdoorInd field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_indoor_outdoor_ind The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_indoor_outdoor_ind(data_collection_model_location_data_t *location_data, const data_collection_model_indoor_outdoor_ind_t* p_indoor_outdoor_ind);

/** Move a value to the indoorOutdoorInd field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_indoor_outdoor_ind The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_indoor_outdoor_ind_move(data_collection_model_location_data_t *location_data, data_collection_model_indoor_outdoor_ind_t* p_indoor_outdoor_ind);

/** Check if the acceptedPeriodicEventInfo field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional acceptedPeriodicEventInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_accepted_periodic_event_info(const data_collection_model_location_data_t *location_data);


/** Get the value of the acceptedPeriodicEventInfo field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the acceptedPeriodicEventInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_periodic_event_info_t* data_collection_model_location_data_get_accepted_periodic_event_info(const data_collection_model_location_data_t *location_data);

/** Set the value of the acceptedPeriodicEventInfo field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_accepted_periodic_event_info The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_accepted_periodic_event_info(data_collection_model_location_data_t *location_data, const data_collection_model_periodic_event_info_t* p_accepted_periodic_event_info);

/** Move a value to the acceptedPeriodicEventInfo field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_accepted_periodic_event_info The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_accepted_periodic_event_info_move(data_collection_model_location_data_t *location_data, data_collection_model_periodic_event_info_t* p_accepted_periodic_event_info);

/** Check if the haGnssMetrics field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional haGnssMetrics field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_ha_gnss_metrics(const data_collection_model_location_data_t *location_data);


/** Get the value of the haGnssMetrics field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the haGnssMetrics field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_high_accuracy_gnss_metrics_t* data_collection_model_location_data_get_ha_gnss_metrics(const data_collection_model_location_data_t *location_data);

/** Set the value of the haGnssMetrics field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ha_gnss_metrics The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ha_gnss_metrics(data_collection_model_location_data_t *location_data, const data_collection_model_high_accuracy_gnss_metrics_t* p_ha_gnss_metrics);

/** Move a value to the haGnssMetrics field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ha_gnss_metrics The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ha_gnss_metrics_move(data_collection_model_location_data_t *location_data, data_collection_model_high_accuracy_gnss_metrics_t* p_ha_gnss_metrics);

/** Check if the losNlosMeasureInd field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional losNlosMeasureInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_los_nlos_measure_ind(const data_collection_model_location_data_t *location_data);


/** Get the value of the losNlosMeasureInd field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the losNlosMeasureInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_los_nlos_measure_ind_t* data_collection_model_location_data_get_los_nlos_measure_ind(const data_collection_model_location_data_t *location_data);

/** Set the value of the losNlosMeasureInd field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_los_nlos_measure_ind The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_los_nlos_measure_ind(data_collection_model_location_data_t *location_data, const data_collection_model_los_nlos_measure_ind_t* p_los_nlos_measure_ind);

/** Move a value to the losNlosMeasureInd field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_los_nlos_measure_ind The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_los_nlos_measure_ind_move(data_collection_model_location_data_t *location_data, data_collection_model_los_nlos_measure_ind_t* p_los_nlos_measure_ind);

/** Check if the relatedApplicationlayerId field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional relatedApplicationlayerId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_related_applicationlayer_id(const data_collection_model_location_data_t *location_data);


/** Get the value of the relatedApplicationlayerId field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the relatedApplicationlayerId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_location_data_get_related_applicationlayer_id(const data_collection_model_location_data_t *location_data);

/** Set the value of the relatedApplicationlayerId field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_related_applicationlayer_id The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_related_applicationlayer_id(data_collection_model_location_data_t *location_data, const char* p_related_applicationlayer_id);

/** Move a value to the relatedApplicationlayerId field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_related_applicationlayer_id The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_related_applicationlayer_id_move(data_collection_model_location_data_t *location_data, char* p_related_applicationlayer_id);

/** Check if the distanceDirection field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional distanceDirection field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_distance_direction(const data_collection_model_location_data_t *location_data);


/** Get the value of the distanceDirection field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the distanceDirection field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_range_direction_t* data_collection_model_location_data_get_distance_direction(const data_collection_model_location_data_t *location_data);

/** Set the value of the distanceDirection field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_distance_direction The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_distance_direction(data_collection_model_location_data_t *location_data, const data_collection_model_range_direction_t* p_distance_direction);

/** Move a value to the distanceDirection field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_distance_direction The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_distance_direction_move(data_collection_model_location_data_t *location_data, data_collection_model_range_direction_t* p_distance_direction);

/** Check if the 2dRelativeLocation field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional 2dRelativeLocation field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_r_2d_relative_location(const data_collection_model_location_data_t *location_data);


/** Get the value of the 2dRelativeLocation field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the 2dRelativeLocation field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_r_2_d_relative_location_t* data_collection_model_location_data_get_r2d_relative_location(const data_collection_model_location_data_t *location_data);

/** Set the value of the 2dRelativeLocation field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_r_2d_relative_location The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_r2d_relative_location(data_collection_model_location_data_t *location_data, const data_collection_model_r_2_d_relative_location_t* p_r_2d_relative_location);

/** Move a value to the 2dRelativeLocation field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_r_2d_relative_location The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_r2d_relative_location_move(data_collection_model_location_data_t *location_data, data_collection_model_r_2_d_relative_location_t* p_r_2d_relative_location);

/** Check if the 3dRelativeLocation field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional 3dRelativeLocation field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_r_3d_relative_location(const data_collection_model_location_data_t *location_data);


/** Get the value of the 3dRelativeLocation field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the 3dRelativeLocation field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_r_3_d_relative_location_t* data_collection_model_location_data_get_r3d_relative_location(const data_collection_model_location_data_t *location_data);

/** Set the value of the 3dRelativeLocation field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_r_3d_relative_location The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_r3d_relative_location(data_collection_model_location_data_t *location_data, const data_collection_model_r_3_d_relative_location_t* p_r_3d_relative_location);

/** Move a value to the 3dRelativeLocation field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_r_3d_relative_location The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_r3d_relative_location_move(data_collection_model_location_data_t *location_data, data_collection_model_r_3_d_relative_location_t* p_r_3d_relative_location);

/** Check if the relativeVelocity field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional relativeVelocity field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_relative_velocity(const data_collection_model_location_data_t *location_data);


/** Get the value of the relativeVelocity field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the relativeVelocity field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_velocity_estimate_t* data_collection_model_location_data_get_relative_velocity(const data_collection_model_location_data_t *location_data);

/** Set the value of the relativeVelocity field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_relative_velocity The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_relative_velocity(data_collection_model_location_data_t *location_data, const data_collection_model_velocity_estimate_t* p_relative_velocity);

/** Move a value to the relativeVelocity field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_relative_velocity The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_relative_velocity_move(data_collection_model_location_data_t *location_data, data_collection_model_velocity_estimate_t* p_relative_velocity);

/** Check if the rangingSlCapability field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional rangingSlCapability field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_ranging_sl_capability(const data_collection_model_location_data_t *location_data);


/** Get the value of the rangingSlCapability field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the rangingSlCapability field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const unsigned char* data_collection_model_location_data_get_ranging_sl_capability(const data_collection_model_location_data_t *location_data);

/** Set the value of the rangingSlCapability field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ranging_sl_capability The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ranging_sl_capability(data_collection_model_location_data_t *location_data, const unsigned char* p_ranging_sl_capability);

/** Move a value to the rangingSlCapability field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_ranging_sl_capability The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_ranging_sl_capability_move(data_collection_model_location_data_t *location_data, unsigned char* p_ranging_sl_capability);

/** Check if the integrityResult field of a LocationData object is set
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return `true` if the optional integrityResult field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_data_has_integrity_result(const data_collection_model_location_data_t *location_data);


/** Get the value of the integrityResult field of a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to examine.
 *
 * @return the value current set for the integrityResult field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_integrity_result_t* data_collection_model_location_data_get_integrity_result(const data_collection_model_location_data_t *location_data);

/** Set the value of the integrityResult field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_integrity_result The value to copy into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_integrity_result(data_collection_model_location_data_t *location_data, const data_collection_model_integrity_result_t* p_integrity_result);

/** Move a value to the integrityResult field in a LocationData object
 * \public \memberof data_collection_model_location_data_t
 *
 * @param location_data The LocationData object to set the field in.
 * @param p_integrity_result The value to move into the LocationData object.
 *
 * @return @a location_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_data_t *data_collection_model_location_data_set_integrity_result_move(data_collection_model_location_data_t *location_data, data_collection_model_integrity_result_t* p_integrity_result);

/** lnode helper for generating ogs_list_t nodes's of type LocationData
 * \public \memberof data_collection_model_location_data_t
 *
 * Creates a new data_collection_lnode_t object containing the @a location_data object.
 * The @a location_data will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param location_data The LocationData object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a location_data
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_location_data_make_lnode(data_collection_model_location_data_t *location_data);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_LOCATION_DATA_H_ */

