#ifndef _DATA_COLLECTION_REPORTING_INFORMATION_H_
#define _DATA_COLLECTION_REPORTING_INFORMATION_H_

/**********************************************************************************************************************************
 * ReportingInformation - Public C interface to the ReportingInformation object
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

#include "NotificationFlag.h"
#include "MutingExceptionInstructions.h"
#include "PartitioningCriteria.h"
#include "NotificationMethod.h"
#include "MutingNotificationsSettings.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ReportingInformation object reference
 */
typedef struct data_collection_model_reporting_information_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_reporting_information_t;



/** Create a new ReportingInformation.
 * \public \memberof data_collection_model_reporting_information_t
 * @return a new ReportingInformation object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_create();

/** Create a new ReportingInformation reference.
 * \public \memberof data_collection_model_reporting_information_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The ReportingInformation to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_create_ref(const data_collection_model_reporting_information_t *other);

/** Create a new copy of a ReportingInformation object.
 * \public \memberof data_collection_model_reporting_information_t
 * Creates a new copy of the given @a other object
 * @param other The ReportingInformation to copy.
 * @return a new ReportingInformation object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_create_copy(const data_collection_model_reporting_information_t *other);

/** Create a new reference of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ReportingInformation to create a new reference to.
 * @return a new ReportingInformation object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_create_move(data_collection_model_reporting_information_t *other);

/** Copy the value of another ReportingInformation into this object
 * \public \memberof data_collection_model_reporting_information_t
 * Copies the value of @a other {{classname} object into @a reporting_information.
 * @param reporting_information The ReportingInformation object to copy @a other into.
 * @param other The ReportingInformation to copy the value from.
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_copy(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_reporting_information_t *other);

/** Move the value of another ReportingInformation into this object
 * \public \memberof data_collection_model_reporting_information_t
 * Discards the current value of @a reporting_information and moves the value of @a other
 * into @a reporting_information. This will leave @a other as an empty reference.
 *
 * @param reporting_information The ReportingInformation object to move @a other into.
 * @param other The ReportingInformation to move the value from.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_reporting_information_t *other);

/** Delete a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 * Destroys the reference to the ReportingInformation object and frees the value of ReportingInformation if this is the last reference.
 *
 * @param reporting_information The ReportingInformation to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_reporting_information_free(data_collection_model_reporting_information_t *reporting_information);

/** Get a cJSON tree representation of a ReportingInformation
 * \public \memberof data_collection_model_reporting_information_t
 *
 * Create a cJSON tree representation of the ReportingInformation object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param reporting_information The ReportingInformation to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_reporting_information_toJSON(const data_collection_model_reporting_information_t *reporting_information, bool as_request);

/** Parse a cJSON tree into a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * Attempts to interpret a cJSON tree as a ReportingInformation API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ReportingInformation object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ReportingInformation object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ReportingInformation objects to see if they are equivalent
 * \public \memberof data_collection_model_reporting_information_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param reporting_information The first ReportingInformation object to compare.
 * @param other_reporting_information The second ReportingInformation object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_is_equal_to(const data_collection_model_reporting_information_t *reporting_information, const data_collection_model_reporting_information_t *other_reporting_information);


/** Check if the immRep field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional immRep field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_imm_rep(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the immRep field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the immRep field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_reporting_information_is_imm_rep(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the immRep field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_imm_rep The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_imm_rep(data_collection_model_reporting_information_t *reporting_information, const bool p_imm_rep);

/** Move a value to the immRep field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_imm_rep The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_imm_rep_move(data_collection_model_reporting_information_t *reporting_information, bool p_imm_rep);

/** Check if the notifMethod field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional notifMethod field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_notif_method(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the notifMethod field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the notifMethod field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_notification_method_t* data_collection_model_reporting_information_get_notif_method(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the notifMethod field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_notif_method The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_method(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_notification_method_t* p_notif_method);

/** Move a value to the notifMethod field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_notif_method The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_method_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_notification_method_t* p_notif_method);

/** Check if the maxReportNbr field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional maxReportNbr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_max_report_nbr(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the maxReportNbr field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the maxReportNbr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_reporting_information_get_max_report_nbr(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the maxReportNbr field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_max_report_nbr The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_max_report_nbr(data_collection_model_reporting_information_t *reporting_information, const int32_t p_max_report_nbr);

/** Move a value to the maxReportNbr field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_max_report_nbr The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_max_report_nbr_move(data_collection_model_reporting_information_t *reporting_information, int32_t p_max_report_nbr);

/** Check if the monDur field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional monDur field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_mon_dur(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the monDur field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the monDur field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_reporting_information_get_mon_dur(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the monDur field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_mon_dur The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_mon_dur(data_collection_model_reporting_information_t *reporting_information, const char* p_mon_dur);

/** Move a value to the monDur field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_mon_dur The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_mon_dur_move(data_collection_model_reporting_information_t *reporting_information, char* p_mon_dur);

/** Check if the repPeriod field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional repPeriod field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_rep_period(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the repPeriod field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the repPeriod field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_reporting_information_get_rep_period(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the repPeriod field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_rep_period The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_rep_period(data_collection_model_reporting_information_t *reporting_information, const int32_t p_rep_period);

/** Move a value to the repPeriod field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_rep_period The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_rep_period_move(data_collection_model_reporting_information_t *reporting_information, int32_t p_rep_period);

/** Check if the sampRatio field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional sampRatio field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_samp_ratio(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the sampRatio field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the sampRatio field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_reporting_information_get_samp_ratio(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the sampRatio field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_samp_ratio The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_samp_ratio(data_collection_model_reporting_information_t *reporting_information, const int32_t p_samp_ratio);

/** Move a value to the sampRatio field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_samp_ratio The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_samp_ratio_move(data_collection_model_reporting_information_t *reporting_information, int32_t p_samp_ratio);

/** Check if the partitionCriteria field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional partitionCriteria field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_partition_criteria(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the partitionCriteria field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the partitionCriteria field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_reporting_information_get_partition_criteria(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the partitionCriteria field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_partition_criteria The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_partition_criteria(data_collection_model_reporting_information_t *reporting_information, const ogs_list_t* p_partition_criteria);

/** Move a value to the partitionCriteria field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_partition_criteria The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_partition_criteria_move(data_collection_model_reporting_information_t *reporting_information, ogs_list_t* p_partition_criteria);

/** Add a new item to the partitionCriteria array in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to add the array item to.
 * @param partition_criteria The value to add.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_add_partition_criteria(data_collection_model_reporting_information_t *reporting_information, data_collection_model_partitioning_criteria_t* partition_criteria);

/** Remove an item from the partitionCriteria array in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to remove the array value from.
 * @param partition_criteria The value to remove.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_remove_partition_criteria(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_partitioning_criteria_t* partition_criteria);

/** Get an item from the partitionCriteria array in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_partitioning_criteria_t* data_collection_model_reporting_information_get_entry_partition_criteria(const data_collection_model_reporting_information_t *reporting_information, size_t idx);

/** Remove all entries from the partitionCriteria array in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to empty partitionCriteria for.
 *
 * @return @a reporting_information
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_clear_partition_criteria(data_collection_model_reporting_information_t *reporting_information);

/** Check if the grpRepTime field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional grpRepTime field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_grp_rep_time(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the grpRepTime field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the grpRepTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_reporting_information_get_grp_rep_time(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the grpRepTime field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_grp_rep_time The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_grp_rep_time(data_collection_model_reporting_information_t *reporting_information, const int32_t p_grp_rep_time);

/** Move a value to the grpRepTime field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_grp_rep_time The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_grp_rep_time_move(data_collection_model_reporting_information_t *reporting_information, int32_t p_grp_rep_time);

/** Check if the notifFlag field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional notifFlag field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_notif_flag(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the notifFlag field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the notifFlag field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_notification_flag_t* data_collection_model_reporting_information_get_notif_flag(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the notifFlag field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_notif_flag The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_notification_flag_t* p_notif_flag);

/** Move a value to the notifFlag field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_notif_flag The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_notification_flag_t* p_notif_flag);

/** Check if the notifFlagInstruct field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional notifFlagInstruct field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_notif_flag_instruct(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the notifFlagInstruct field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the notifFlagInstruct field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_muting_exception_instructions_t* data_collection_model_reporting_information_get_notif_flag_instruct(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the notifFlagInstruct field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_notif_flag_instruct The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag_instruct(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_muting_exception_instructions_t* p_notif_flag_instruct);

/** Move a value to the notifFlagInstruct field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_notif_flag_instruct The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_notif_flag_instruct_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_muting_exception_instructions_t* p_notif_flag_instruct);

/** Check if the mutingSetting field of a ReportingInformation object is set
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return `true` if the optional mutingSetting field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_reporting_information_has_muting_setting(const data_collection_model_reporting_information_t *reporting_information);


/** Get the value of the mutingSetting field of a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to examine.
 *
 * @return the value current set for the mutingSetting field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_muting_notifications_settings_t* data_collection_model_reporting_information_get_muting_setting(const data_collection_model_reporting_information_t *reporting_information);

/** Set the value of the mutingSetting field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_muting_setting The value to copy into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_muting_setting(data_collection_model_reporting_information_t *reporting_information, const data_collection_model_muting_notifications_settings_t* p_muting_setting);

/** Move a value to the mutingSetting field in a ReportingInformation object
 * \public \memberof data_collection_model_reporting_information_t
 *
 * @param reporting_information The ReportingInformation object to set the field in.
 * @param p_muting_setting The value to move into the ReportingInformation object.
 *
 * @return @a reporting_information.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_reporting_information_t *data_collection_model_reporting_information_set_muting_setting_move(data_collection_model_reporting_information_t *reporting_information, data_collection_model_muting_notifications_settings_t* p_muting_setting);

/** lnode helper for generating ogs_list_t nodes's of type ReportingInformation
 * \public \memberof data_collection_model_reporting_information_t
 *
 * Creates a new data_collection_lnode_t object containing the @a reporting_information object.
 * The @a reporting_information will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param reporting_information The ReportingInformation object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a reporting_information
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_reporting_information_make_lnode(data_collection_model_reporting_information_t *reporting_information);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_REPORTING_INFORMATION_H_ */

