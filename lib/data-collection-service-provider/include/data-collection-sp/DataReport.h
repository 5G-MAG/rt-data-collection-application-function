#ifndef _DATA_COLLECTION_DATA_REPORT_H_
#define _DATA_COLLECTION_DATA_REPORT_H_

/**********************************************************************************************************************************
 * DataReport - Public C interface to the DataReport object
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

#include "MediaStreamingAccessRecord.h"
#include "TripPlanRecord.h"
#include "ApplicationSpecificRecord.h"
#include "ServiceExperienceRecord.h"
#include "LocationRecord.h"
#include "ANBRNetworkAssistanceInvocationRecord.h"
#include "PerformanceDataRecord.h"
#include "CommunicationRecord.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DataReport object reference
 */
typedef struct data_collection_model_data_report_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_data_report_t;



/** Create a new DataReport.
 * \public \memberof data_collection_model_data_report_t
 * @return a new DataReport object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_create();

/** Create a new DataReport reference.
 * \public \memberof data_collection_model_data_report_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The DataReport to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_create_ref(const data_collection_model_data_report_t *other);

/** Create a new copy of a DataReport object.
 * \public \memberof data_collection_model_data_report_t
 * Creates a new copy of the given @a other object
 * @param other The DataReport to copy.
 * @return a new DataReport object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_create_copy(const data_collection_model_data_report_t *other);

/** Create a new reference of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DataReport to create a new reference to.
 * @return a new DataReport object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_create_move(data_collection_model_data_report_t *other);

/** Copy the value of another DataReport into this object
 * \public \memberof data_collection_model_data_report_t
 * Copies the value of @a other {{classname} object into @a data_report.
 * @param data_report The DataReport object to copy @a other into.
 * @param other The DataReport to copy the value from.
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_copy(data_collection_model_data_report_t *data_report, const data_collection_model_data_report_t *other);

/** Move the value of another DataReport into this object
 * \public \memberof data_collection_model_data_report_t
 * Discards the current value of @a data_report and moves the value of @a other
 * into @a data_report. This will leave @a other as an empty reference.
 *
 * @param data_report The DataReport object to move @a other into.
 * @param other The DataReport to move the value from.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_move(data_collection_model_data_report_t *data_report, data_collection_model_data_report_t *other);

/** Delete a DataReport object
 * \public \memberof data_collection_model_data_report_t
 * Destroys the reference to the DataReport object and frees the value of DataReport if this is the last reference.
 *
 * @param data_report The DataReport to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_report_free(data_collection_model_data_report_t *data_report);

/** Get a cJSON tree representation of a DataReport
 * \public \memberof data_collection_model_data_report_t
 *
 * Create a cJSON tree representation of the DataReport object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param data_report The DataReport to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_report_toJSON(const data_collection_model_data_report_t *data_report, bool as_request);

/** Parse a cJSON tree into a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * Attempts to interpret a cJSON tree as a DataReport API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DataReport object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DataReport object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DataReport objects to see if they are equivalent
 * \public \memberof data_collection_model_data_report_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param data_report The first DataReport object to compare.
 * @param other_data_report The second DataReport object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_report_is_equal_to(const data_collection_model_data_report_t *data_report, const data_collection_model_data_report_t *other_data_report);



/** Get the value of the externalApplicationId field of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return the value current set for the externalApplicationId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_data_report_get_external_application_id(const data_collection_model_data_report_t *data_report);

/** Set the value of the externalApplicationId field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_external_application_id The value to copy into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_external_application_id(data_collection_model_data_report_t *data_report, const char* p_external_application_id);

/** Move a value to the externalApplicationId field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_external_application_id The value to move into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_external_application_id_move(data_collection_model_data_report_t *data_report, char* p_external_application_id);

/** Check if the expedite field of a DataReport object is set
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return `true` if the optional expedite field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_report_has_expedite(const data_collection_model_data_report_t *data_report);


/** Get the value of the expedite field of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return the value current set for the expedite field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_data_report_is_expedite(const data_collection_model_data_report_t *data_report);

/** Set the value of the expedite field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_expedite The value to copy into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_expedite(data_collection_model_data_report_t *data_report, const bool p_expedite);

/** Move a value to the expedite field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_expedite The value to move into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_expedite_move(data_collection_model_data_report_t *data_report, bool p_expedite);

/** Check if the serviceExperienceRecords field of a DataReport object is set
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return `true` if the optional serviceExperienceRecords field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_report_has_service_experience_records(const data_collection_model_data_report_t *data_report);


/** Get the value of the serviceExperienceRecords field of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return the value current set for the serviceExperienceRecords field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_report_get_service_experience_records(const data_collection_model_data_report_t *data_report);

/** Set the value of the serviceExperienceRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_service_experience_records The value to copy into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_service_experience_records(data_collection_model_data_report_t *data_report, const ogs_list_t* p_service_experience_records);

/** Move a value to the serviceExperienceRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_service_experience_records The value to move into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_service_experience_records_move(data_collection_model_data_report_t *data_report, ogs_list_t* p_service_experience_records);

/** Add a new item to the serviceExperienceRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to add the array item to.
 * @param service_experience_records The value to add.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_add_service_experience_records(data_collection_model_data_report_t *data_report, data_collection_model_service_experience_record_t* service_experience_records);

/** Remove an item from the serviceExperienceRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to remove the array value from.
 * @param service_experience_records The value to remove.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_remove_service_experience_records(data_collection_model_data_report_t *data_report, const data_collection_model_service_experience_record_t* service_experience_records);

/** Get an item from the serviceExperienceRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_service_experience_record_t* data_collection_model_data_report_get_entry_service_experience_records(const data_collection_model_data_report_t *data_report, size_t idx);

/** Remove all entries from the serviceExperienceRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to empty serviceExperienceRecords for.
 *
 * @return @a data_report
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_clear_service_experience_records(data_collection_model_data_report_t *data_report);

/** Check if the locationRecords field of a DataReport object is set
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return `true` if the optional locationRecords field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_report_has_location_records(const data_collection_model_data_report_t *data_report);


/** Get the value of the locationRecords field of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return the value current set for the locationRecords field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_report_get_location_records(const data_collection_model_data_report_t *data_report);

/** Set the value of the locationRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_location_records The value to copy into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_location_records(data_collection_model_data_report_t *data_report, const ogs_list_t* p_location_records);

/** Move a value to the locationRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_location_records The value to move into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_location_records_move(data_collection_model_data_report_t *data_report, ogs_list_t* p_location_records);

/** Add a new item to the locationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to add the array item to.
 * @param location_records The value to add.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_add_location_records(data_collection_model_data_report_t *data_report, data_collection_model_location_record_t* location_records);

/** Remove an item from the locationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to remove the array value from.
 * @param location_records The value to remove.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_remove_location_records(data_collection_model_data_report_t *data_report, const data_collection_model_location_record_t* location_records);

/** Get an item from the locationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_record_t* data_collection_model_data_report_get_entry_location_records(const data_collection_model_data_report_t *data_report, size_t idx);

/** Remove all entries from the locationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to empty locationRecords for.
 *
 * @return @a data_report
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_clear_location_records(data_collection_model_data_report_t *data_report);

/** Check if the communicationRecords field of a DataReport object is set
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return `true` if the optional communicationRecords field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_report_has_communication_records(const data_collection_model_data_report_t *data_report);


/** Get the value of the communicationRecords field of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return the value current set for the communicationRecords field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_report_get_communication_records(const data_collection_model_data_report_t *data_report);

/** Set the value of the communicationRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_communication_records The value to copy into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_communication_records(data_collection_model_data_report_t *data_report, const ogs_list_t* p_communication_records);

/** Move a value to the communicationRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_communication_records The value to move into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_communication_records_move(data_collection_model_data_report_t *data_report, ogs_list_t* p_communication_records);

/** Add a new item to the communicationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to add the array item to.
 * @param communication_records The value to add.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_add_communication_records(data_collection_model_data_report_t *data_report, data_collection_model_communication_record_t* communication_records);

/** Remove an item from the communicationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to remove the array value from.
 * @param communication_records The value to remove.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_remove_communication_records(data_collection_model_data_report_t *data_report, const data_collection_model_communication_record_t* communication_records);

/** Get an item from the communicationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_communication_record_t* data_collection_model_data_report_get_entry_communication_records(const data_collection_model_data_report_t *data_report, size_t idx);

/** Remove all entries from the communicationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to empty communicationRecords for.
 *
 * @return @a data_report
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_clear_communication_records(data_collection_model_data_report_t *data_report);

/** Check if the performanceDataRecords field of a DataReport object is set
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return `true` if the optional performanceDataRecords field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_report_has_performance_data_records(const data_collection_model_data_report_t *data_report);


/** Get the value of the performanceDataRecords field of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return the value current set for the performanceDataRecords field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_report_get_performance_data_records(const data_collection_model_data_report_t *data_report);

/** Set the value of the performanceDataRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_performance_data_records The value to copy into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_performance_data_records(data_collection_model_data_report_t *data_report, const ogs_list_t* p_performance_data_records);

/** Move a value to the performanceDataRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_performance_data_records The value to move into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_performance_data_records_move(data_collection_model_data_report_t *data_report, ogs_list_t* p_performance_data_records);

/** Add a new item to the performanceDataRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to add the array item to.
 * @param performance_data_records The value to add.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_add_performance_data_records(data_collection_model_data_report_t *data_report, data_collection_model_performance_data_record_t* performance_data_records);

/** Remove an item from the performanceDataRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to remove the array value from.
 * @param performance_data_records The value to remove.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_remove_performance_data_records(data_collection_model_data_report_t *data_report, const data_collection_model_performance_data_record_t* performance_data_records);

/** Get an item from the performanceDataRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_performance_data_record_t* data_collection_model_data_report_get_entry_performance_data_records(const data_collection_model_data_report_t *data_report, size_t idx);

/** Remove all entries from the performanceDataRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to empty performanceDataRecords for.
 *
 * @return @a data_report
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_clear_performance_data_records(data_collection_model_data_report_t *data_report);

/** Check if the applicationSpecificRecords field of a DataReport object is set
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return `true` if the optional applicationSpecificRecords field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_report_has_application_specific_records(const data_collection_model_data_report_t *data_report);


/** Get the value of the applicationSpecificRecords field of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return the value current set for the applicationSpecificRecords field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_report_get_application_specific_records(const data_collection_model_data_report_t *data_report);

/** Set the value of the applicationSpecificRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_application_specific_records The value to copy into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_application_specific_records(data_collection_model_data_report_t *data_report, const ogs_list_t* p_application_specific_records);

/** Move a value to the applicationSpecificRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_application_specific_records The value to move into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_application_specific_records_move(data_collection_model_data_report_t *data_report, ogs_list_t* p_application_specific_records);

/** Add a new item to the applicationSpecificRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to add the array item to.
 * @param application_specific_records The value to add.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_add_application_specific_records(data_collection_model_data_report_t *data_report, data_collection_model_application_specific_record_t* application_specific_records);

/** Remove an item from the applicationSpecificRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to remove the array value from.
 * @param application_specific_records The value to remove.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_remove_application_specific_records(data_collection_model_data_report_t *data_report, const data_collection_model_application_specific_record_t* application_specific_records);

/** Get an item from the applicationSpecificRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_application_specific_record_t* data_collection_model_data_report_get_entry_application_specific_records(const data_collection_model_data_report_t *data_report, size_t idx);

/** Remove all entries from the applicationSpecificRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to empty applicationSpecificRecords for.
 *
 * @return @a data_report
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_clear_application_specific_records(data_collection_model_data_report_t *data_report);

/** Check if the tripPlanRecords field of a DataReport object is set
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return `true` if the optional tripPlanRecords field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_report_has_trip_plan_records(const data_collection_model_data_report_t *data_report);


/** Get the value of the tripPlanRecords field of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return the value current set for the tripPlanRecords field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_report_get_trip_plan_records(const data_collection_model_data_report_t *data_report);

/** Set the value of the tripPlanRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_trip_plan_records The value to copy into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_trip_plan_records(data_collection_model_data_report_t *data_report, const ogs_list_t* p_trip_plan_records);

/** Move a value to the tripPlanRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_trip_plan_records The value to move into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_trip_plan_records_move(data_collection_model_data_report_t *data_report, ogs_list_t* p_trip_plan_records);

/** Add a new item to the tripPlanRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to add the array item to.
 * @param trip_plan_records The value to add.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_add_trip_plan_records(data_collection_model_data_report_t *data_report, data_collection_model_trip_plan_record_t* trip_plan_records);

/** Remove an item from the tripPlanRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to remove the array value from.
 * @param trip_plan_records The value to remove.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_remove_trip_plan_records(data_collection_model_data_report_t *data_report, const data_collection_model_trip_plan_record_t* trip_plan_records);

/** Get an item from the tripPlanRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_trip_plan_record_t* data_collection_model_data_report_get_entry_trip_plan_records(const data_collection_model_data_report_t *data_report, size_t idx);

/** Remove all entries from the tripPlanRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to empty tripPlanRecords for.
 *
 * @return @a data_report
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_clear_trip_plan_records(data_collection_model_data_report_t *data_report);

/** Check if the aNBRNetworkAssistanceInvocationRecords field of a DataReport object is set
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return `true` if the optional aNBRNetworkAssistanceInvocationRecords field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_report_has_anbr_network_assistance_invocation_records(const data_collection_model_data_report_t *data_report);


/** Get the value of the aNBRNetworkAssistanceInvocationRecords field of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return the value current set for the aNBRNetworkAssistanceInvocationRecords field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_report_get_anbr_network_assistance_invocation_records(const data_collection_model_data_report_t *data_report);

/** Set the value of the aNBRNetworkAssistanceInvocationRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_anbr_network_assistance_invocation_records The value to copy into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_anbr_network_assistance_invocation_records(data_collection_model_data_report_t *data_report, const ogs_list_t* p_anbr_network_assistance_invocation_records);

/** Move a value to the aNBRNetworkAssistanceInvocationRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_anbr_network_assistance_invocation_records The value to move into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_anbr_network_assistance_invocation_records_move(data_collection_model_data_report_t *data_report, ogs_list_t* p_anbr_network_assistance_invocation_records);

/** Add a new item to the aNBRNetworkAssistanceInvocationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to add the array item to.
 * @param anbr_network_assistance_invocation_records The value to add.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_add_anbr_network_assistance_invocation_records(data_collection_model_data_report_t *data_report, data_collection_model_anbr_network_assistance_invocation_record_t* anbr_network_assistance_invocation_records);

/** Remove an item from the aNBRNetworkAssistanceInvocationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to remove the array value from.
 * @param anbr_network_assistance_invocation_records The value to remove.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_remove_anbr_network_assistance_invocation_records(data_collection_model_data_report_t *data_report, const data_collection_model_anbr_network_assistance_invocation_record_t* anbr_network_assistance_invocation_records);

/** Get an item from the aNBRNetworkAssistanceInvocationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_anbr_network_assistance_invocation_record_t* data_collection_model_data_report_get_entry_anbr_network_assistance_invocation_records(const data_collection_model_data_report_t *data_report, size_t idx);

/** Remove all entries from the aNBRNetworkAssistanceInvocationRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to empty aNBRNetworkAssistanceInvocationRecords for.
 *
 * @return @a data_report
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_clear_anbr_network_assistance_invocation_records(data_collection_model_data_report_t *data_report);

/** Check if the mediaStreamingAccessRecords field of a DataReport object is set
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return `true` if the optional mediaStreamingAccessRecords field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_report_has_media_streaming_access_records(const data_collection_model_data_report_t *data_report);


/** Get the value of the mediaStreamingAccessRecords field of a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 *
 * @return the value current set for the mediaStreamingAccessRecords field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_data_report_get_media_streaming_access_records(const data_collection_model_data_report_t *data_report);

/** Set the value of the mediaStreamingAccessRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_media_streaming_access_records The value to copy into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_media_streaming_access_records(data_collection_model_data_report_t *data_report, const ogs_list_t* p_media_streaming_access_records);

/** Move a value to the mediaStreamingAccessRecords field in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to set the field in.
 * @param p_media_streaming_access_records The value to move into the DataReport object.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_set_media_streaming_access_records_move(data_collection_model_data_report_t *data_report, ogs_list_t* p_media_streaming_access_records);

/** Add a new item to the mediaStreamingAccessRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to add the array item to.
 * @param media_streaming_access_records The value to add.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_add_media_streaming_access_records(data_collection_model_data_report_t *data_report, data_collection_model_media_streaming_access_record_t* media_streaming_access_records);

/** Remove an item from the mediaStreamingAccessRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to remove the array value from.
 * @param media_streaming_access_records The value to remove.
 *
 * @return @a data_report.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_remove_media_streaming_access_records(data_collection_model_data_report_t *data_report, const data_collection_model_media_streaming_access_record_t* media_streaming_access_records);

/** Get an item from the mediaStreamingAccessRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_record_t* data_collection_model_data_report_get_entry_media_streaming_access_records(const data_collection_model_data_report_t *data_report, size_t idx);

/** Remove all entries from the mediaStreamingAccessRecords array in a DataReport object
 * \public \memberof data_collection_model_data_report_t
 *
 * @param data_report The DataReport object to empty mediaStreamingAccessRecords for.
 *
 * @return @a data_report
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_report_t *data_collection_model_data_report_clear_media_streaming_access_records(data_collection_model_data_report_t *data_report);

/** lnode helper for generating ogs_list_t nodes's of type DataReport
 * \public \memberof data_collection_model_data_report_t
 *
 * Creates a new data_collection_lnode_t object containing the @a data_report object.
 * The @a data_report will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param data_report The DataReport object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a data_report
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_report_make_lnode(data_collection_model_data_report_t *data_report);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_REPORT_H_ */

