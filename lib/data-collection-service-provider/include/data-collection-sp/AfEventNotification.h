#ifndef _DATA_COLLECTION_AF_EVENT_NOTIFICATION_H_
#define _DATA_COLLECTION_AF_EVENT_NOTIFICATION_H_

/**********************************************************************************************************************************
 * AfEventNotification - Public C interface to the AfEventNotification object
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

#include "CollectiveBehaviourInfo.h"
#include "ServiceExperienceInfoPerApp.h"
#include "MsConsumptionCollection.h"
#include "QoEMetricsCollection.h"
#include "AfEvent.h"
#include "ConsumptionReportingUnitsCollection.h"
#include "PerformanceDataCollection.h"
#include "NetworkAssistanceInvocationsCollection.h"
#include "UeCommunicationCollection.h"
#include "DynamicPolicyInvocationsCollection.h"
#include "DispersionCollection.h"
#include "ExceptionInfo.h"
#include "MsQoeMetricsCollection.h"
#include "UserDataCongestionCollection.h"
#include "UeMobilityCollection.h"
#include "GNSSAssistDataInfo.h"
#include "MediaStreamingAccessesCollection.h"
#include "MsDynPolicyInvocationCollection.h"
#include "MsNetAssInvocationCollection.h"
#include "DatVolTransTimeCollection.h"
#include "MSAccessActivityCollection.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP AfEventNotification object reference
 */
typedef struct data_collection_model_af_event_notification_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_af_event_notification_t;



/** Create a new AfEventNotification
 * \public \memberof data_collection_model_af_event_notification_t
 * @return a new AfEventNotification object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_create();

/** Create a new copy of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 * Creates a new copy of the given @a other object
 * @param other The AfEventNotification to copy.
 * @return a new AfEventNotification object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_create_copy(const data_collection_model_af_event_notification_t *other);

/** Create a new reference of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 * Creates a reference to the same underlying @a other object.
 * @param other The AfEventNotification to create a new reference to.
 * @return a new AfEventNotification object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_create_move(data_collection_model_af_event_notification_t *other);

/** Copy the value of another AfEventNotification into this object
 * \public \memberof data_collection_model_af_event_notification_t
 * Copies the value of @a other {{classname} object into @a af_event_notification.
 * @param af_event_notification The AfEventNotification object to copy @a other into.
 * @param other The AfEventNotification to copy the value from.
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_copy(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_af_event_notification_t *other);

/** Move the value of another AfEventNotification into this object
 * \public \memberof data_collection_model_af_event_notification_t
 * Discards the current value of @a af_event_notification and moves the value of @a other
 * into @a af_event_notification. This will leave @a other as an empty reference.
 *
 * @param af_event_notification The AfEventNotification object to move @a other into.
 * @param other The AfEventNotification to move the value from.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_move(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_af_event_notification_t *other);

/** Delete a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 * Destroys the reference to the AfEventNotification object and frees the value of AfEventNotification if this is the last reference.
 *
 * @param af_event_notification The AfEventNotification to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_af_event_notification_free(data_collection_model_af_event_notification_t *af_event_notification);

/** Get a cJSON tree representation of a AfEventNotification
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * Create a cJSON tree representation of the AfEventNotification object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param af_event_notification The AfEventNotification to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_af_event_notification_toJSON(const data_collection_model_af_event_notification_t *af_event_notification, bool as_request);

/** Parse a cJSON tree into a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * Attempts to interpret a cJSON tree as a AfEventNotification API request or response (dependent on @a as_request value). If successful
 * will return a new referenced AfEventNotification object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new AfEventNotification object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two AfEventNotification objects to see if they are equivalent
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param af_event_notification The first AfEventNotification object to compare.
 * @param other_af_event_notification The second AfEventNotification object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_is_equal_to(const data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_af_event_notification_t *other_af_event_notification);



/** Get the value of the event field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the event field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_t* data_collection_model_af_event_notification_get_event(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the event field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_event The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_event(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_af_event_t* p_event);

/** Move a value to the event field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_event The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_event_move(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_af_event_t* p_event);


/** Get the value of the timeStamp field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the timeStamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_af_event_notification_get_time_stamp(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the timeStamp field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_time_stamp The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_time_stamp(data_collection_model_af_event_notification_t *af_event_notification, const char* p_time_stamp);

/** Move a value to the timeStamp field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_time_stamp The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_time_stamp_move(data_collection_model_af_event_notification_t *af_event_notification, char* p_time_stamp);

/** Check if the svcExprcInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional svcExprcInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_svc_exprc_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the svcExprcInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the svcExprcInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_svc_exprc_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the svcExprcInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_svc_exprc_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_svc_exprc_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_svc_exprc_infos);

/** Move a value to the svcExprcInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_svc_exprc_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_svc_exprc_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_svc_exprc_infos);

/** Add a new item to the svcExprcInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param svc_exprc_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_svc_exprc_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_service_experience_info_per_app_t* svc_exprc_infos);

/** Remove an item from the svcExprcInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param svc_exprc_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_svc_exprc_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_service_experience_info_per_app_t* svc_exprc_infos);

/** Get an item from the svcExprcInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_service_experience_info_per_app_t* data_collection_model_af_event_notification_get_entry_svc_exprc_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the svcExprcInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty svcExprcInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_svc_exprc_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the ueMobilityInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional ueMobilityInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ue_mobility_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the ueMobilityInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the ueMobilityInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ue_mobility_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the ueMobilityInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ue_mobility_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_mobility_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ue_mobility_infos);

/** Move a value to the ueMobilityInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ue_mobility_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_mobility_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ue_mobility_infos);

/** Add a new item to the ueMobilityInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ue_mobility_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ue_mobility_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ue_mobility_collection_t* ue_mobility_infos);

/** Remove an item from the ueMobilityInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ue_mobility_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ue_mobility_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ue_mobility_collection_t* ue_mobility_infos);

/** Get an item from the ueMobilityInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ue_mobility_collection_t* data_collection_model_af_event_notification_get_entry_ue_mobility_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the ueMobilityInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty ueMobilityInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ue_mobility_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the ueCommInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional ueCommInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ue_comm_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the ueCommInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the ueCommInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ue_comm_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the ueCommInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ue_comm_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_comm_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ue_comm_infos);

/** Move a value to the ueCommInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ue_comm_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ue_comm_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ue_comm_infos);

/** Add a new item to the ueCommInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ue_comm_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ue_comm_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ue_communication_collection_t* ue_comm_infos);

/** Remove an item from the ueCommInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ue_comm_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ue_comm_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ue_communication_collection_t* ue_comm_infos);

/** Get an item from the ueCommInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ue_communication_collection_t* data_collection_model_af_event_notification_get_entry_ue_comm_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the ueCommInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty ueCommInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ue_comm_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the excepInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional excepInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_excep_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the excepInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the excepInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_excep_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the excepInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_excep_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_excep_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_excep_infos);

/** Move a value to the excepInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_excep_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_excep_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_excep_infos);

/** Add a new item to the excepInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param excep_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_excep_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_exception_info_t* excep_infos);

/** Remove an item from the excepInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param excep_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_excep_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_exception_info_t* excep_infos);

/** Get an item from the excepInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_exception_info_t* data_collection_model_af_event_notification_get_entry_excep_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the excepInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty excepInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_excep_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the congestionInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional congestionInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_congestion_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the congestionInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the congestionInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_congestion_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the congestionInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_congestion_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_congestion_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_congestion_infos);

/** Move a value to the congestionInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_congestion_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_congestion_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_congestion_infos);

/** Add a new item to the congestionInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param congestion_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_congestion_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_user_data_congestion_collection_t* congestion_infos);

/** Remove an item from the congestionInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param congestion_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_congestion_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_user_data_congestion_collection_t* congestion_infos);

/** Get an item from the congestionInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_user_data_congestion_collection_t* data_collection_model_af_event_notification_get_entry_congestion_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the congestionInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty congestionInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_congestion_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the perfDataInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional perfDataInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_perf_data_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the perfDataInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the perfDataInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_perf_data_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the perfDataInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_perf_data_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_perf_data_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_perf_data_infos);

/** Move a value to the perfDataInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_perf_data_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_perf_data_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_perf_data_infos);

/** Add a new item to the perfDataInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param perf_data_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_perf_data_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_performance_data_collection_t* perf_data_infos);

/** Remove an item from the perfDataInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param perf_data_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_perf_data_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_performance_data_collection_t* perf_data_infos);

/** Get an item from the perfDataInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_performance_data_collection_t* data_collection_model_af_event_notification_get_entry_perf_data_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the perfDataInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty perfDataInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_perf_data_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the dispersionInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional dispersionInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_dispersion_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the dispersionInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the dispersionInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_dispersion_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the dispersionInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_dispersion_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dispersion_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_dispersion_infos);

/** Move a value to the dispersionInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_dispersion_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dispersion_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_dispersion_infos);

/** Add a new item to the dispersionInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param dispersion_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_dispersion_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_dispersion_collection_t* dispersion_infos);

/** Remove an item from the dispersionInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param dispersion_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_dispersion_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_dispersion_collection_t* dispersion_infos);

/** Get an item from the dispersionInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_dispersion_collection_t* data_collection_model_af_event_notification_get_entry_dispersion_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the dispersionInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty dispersionInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_dispersion_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the collBhvrInfs field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional collBhvrInfs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_coll_bhvr_infs(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the collBhvrInfs field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the collBhvrInfs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_coll_bhvr_infs(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the collBhvrInfs field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_coll_bhvr_infs The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_coll_bhvr_infs(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_coll_bhvr_infs);

/** Move a value to the collBhvrInfs field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_coll_bhvr_infs The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_coll_bhvr_infs_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_coll_bhvr_infs);

/** Add a new item to the collBhvrInfs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param coll_bhvr_infs The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_coll_bhvr_infs(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_collective_behaviour_info_t* coll_bhvr_infs);

/** Remove an item from the collBhvrInfs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param coll_bhvr_infs The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_coll_bhvr_infs(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_collective_behaviour_info_t* coll_bhvr_infs);

/** Get an item from the collBhvrInfs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_collective_behaviour_info_t* data_collection_model_af_event_notification_get_entry_coll_bhvr_infs(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the collBhvrInfs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty collBhvrInfs for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_coll_bhvr_infs(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the msQoeMetrInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional msQoeMetrInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ms_qoe_metr_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the msQoeMetrInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the msQoeMetrInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_qoe_metr_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the msQoeMetrInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_qoe_metr_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_qoe_metr_infos);

/** Move a value to the msQoeMetrInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_qoe_metr_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metr_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_qoe_metr_infos);

/** Add a new item to the msQoeMetrInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ms_qoe_metr_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ms_qoe_metrics_collection_t* ms_qoe_metr_infos);

/** Remove an item from the msQoeMetrInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ms_qoe_metr_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ms_qoe_metrics_collection_t* ms_qoe_metr_infos);

/** Get an item from the msQoeMetrInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ms_qoe_metrics_collection_t* data_collection_model_af_event_notification_get_entry_ms_qoe_metr_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the msQoeMetrInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty msQoeMetrInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_qoe_metr_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the msQoeMetrics field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional msQoeMetrics field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ms_qoe_metrics(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the msQoeMetrics field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the msQoeMetrics field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_qoe_metrics(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the msQoeMetrics field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_qoe_metrics The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metrics(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_qoe_metrics);

/** Move a value to the msQoeMetrics field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_qoe_metrics The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_qoe_metrics_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_qoe_metrics);

/** Add a new item to the msQoeMetrics array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ms_qoe_metrics The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_qoe_metrics(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_qo_e_metrics_collection_t* ms_qoe_metrics);

/** Remove an item from the msQoeMetrics array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ms_qoe_metrics The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_qoe_metrics(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_qo_e_metrics_collection_t* ms_qoe_metrics);

/** Get an item from the msQoeMetrics array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_qo_e_metrics_collection_t* data_collection_model_af_event_notification_get_entry_ms_qoe_metrics(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the msQoeMetrics array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty msQoeMetrics for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_qoe_metrics(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the msConsumpInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional msConsumpInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ms_consump_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the msConsumpInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the msConsumpInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_consump_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the msConsumpInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_consump_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_consump_infos);

/** Move a value to the msConsumpInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_consump_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_consump_infos);

/** Add a new item to the msConsumpInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ms_consump_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_consump_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ms_consumption_collection_t* ms_consump_infos);

/** Remove an item from the msConsumpInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ms_consump_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_consump_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ms_consumption_collection_t* ms_consump_infos);

/** Get an item from the msConsumpInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ms_consumption_collection_t* data_collection_model_af_event_notification_get_entry_ms_consump_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the msConsumpInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty msConsumpInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_consump_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the msConsumpRpts field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional msConsumpRpts field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ms_consump_rpts(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the msConsumpRpts field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the msConsumpRpts field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_consump_rpts(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the msConsumpRpts field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_consump_rpts The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_rpts(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_consump_rpts);

/** Move a value to the msConsumpRpts field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_consump_rpts The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_consump_rpts_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_consump_rpts);

/** Add a new item to the msConsumpRpts array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ms_consump_rpts The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_consump_rpts(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_consumption_reporting_units_collection_t* ms_consump_rpts);

/** Remove an item from the msConsumpRpts array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ms_consump_rpts The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_consump_rpts(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_consumption_reporting_units_collection_t* ms_consump_rpts);

/** Get an item from the msConsumpRpts array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_consumption_reporting_units_collection_t* data_collection_model_af_event_notification_get_entry_ms_consump_rpts(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the msConsumpRpts array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty msConsumpRpts for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_consump_rpts(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the msNetAssInvInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional msNetAssInvInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ms_net_ass_inv_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the msNetAssInvInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the msNetAssInvInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_net_ass_inv_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the msNetAssInvInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_net_ass_inv_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_net_ass_inv_infos);

/** Move a value to the msNetAssInvInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_net_ass_inv_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_ass_inv_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_net_ass_inv_infos);

/** Add a new item to the msNetAssInvInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ms_net_ass_inv_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ms_net_ass_invocation_collection_t* ms_net_ass_inv_infos);

/** Remove an item from the msNetAssInvInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ms_net_ass_inv_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ms_net_ass_invocation_collection_t* ms_net_ass_inv_infos);

/** Get an item from the msNetAssInvInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ms_net_ass_invocation_collection_t* data_collection_model_af_event_notification_get_entry_ms_net_ass_inv_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the msNetAssInvInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty msNetAssInvInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_net_ass_inv_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the msNetAssistInvs field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional msNetAssistInvs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ms_net_assist_invs(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the msNetAssistInvs field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the msNetAssistInvs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_net_assist_invs(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the msNetAssistInvs field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_net_assist_invs The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_assist_invs(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_net_assist_invs);

/** Move a value to the msNetAssistInvs field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_net_assist_invs The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_net_assist_invs_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_net_assist_invs);

/** Add a new item to the msNetAssistInvs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ms_net_assist_invs The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_net_assist_invs(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_network_assistance_invocations_collection_t* ms_net_assist_invs);

/** Remove an item from the msNetAssistInvs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ms_net_assist_invs The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_net_assist_invs(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_network_assistance_invocations_collection_t* ms_net_assist_invs);

/** Get an item from the msNetAssistInvs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_invocations_collection_t* data_collection_model_af_event_notification_get_entry_ms_net_assist_invs(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the msNetAssistInvs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty msNetAssistInvs for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_net_assist_invs(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the msDynPlyInvInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional msDynPlyInvInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ms_dyn_ply_inv_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the msDynPlyInvInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the msDynPlyInvInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_dyn_ply_inv_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the msDynPlyInvInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_dyn_ply_inv_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_dyn_ply_inv_infos);

/** Move a value to the msDynPlyInvInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_dyn_ply_inv_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_inv_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_dyn_ply_inv_infos);

/** Add a new item to the msDynPlyInvInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ms_dyn_ply_inv_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ms_dyn_policy_invocation_collection_t* ms_dyn_ply_inv_infos);

/** Remove an item from the msDynPlyInvInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ms_dyn_ply_inv_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ms_dyn_policy_invocation_collection_t* ms_dyn_ply_inv_infos);

/** Get an item from the msDynPlyInvInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ms_dyn_policy_invocation_collection_t* data_collection_model_af_event_notification_get_entry_ms_dyn_ply_inv_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the msDynPlyInvInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty msDynPlyInvInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_dyn_ply_inv_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the msDynPlyInvs field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional msDynPlyInvs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ms_dyn_ply_invs(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the msDynPlyInvs field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the msDynPlyInvs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_dyn_ply_invs(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the msDynPlyInvs field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_dyn_ply_invs The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_dyn_ply_invs);

/** Move a value to the msDynPlyInvs field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_dyn_ply_invs The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_dyn_ply_invs_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_dyn_ply_invs);

/** Add a new item to the msDynPlyInvs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ms_dyn_ply_invs The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_dynamic_policy_invocations_collection_t* ms_dyn_ply_invs);

/** Remove an item from the msDynPlyInvs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ms_dyn_ply_invs The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_dynamic_policy_invocations_collection_t* ms_dyn_ply_invs);

/** Get an item from the msDynPlyInvs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_dynamic_policy_invocations_collection_t* data_collection_model_af_event_notification_get_entry_ms_dyn_ply_invs(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the msDynPlyInvs array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty msDynPlyInvs for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_dyn_ply_invs(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the msAccActInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional msAccActInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ms_acc_act_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the msAccActInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the msAccActInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_acc_act_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the msAccActInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_acc_act_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_acc_act_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_acc_act_infos);

/** Move a value to the msAccActInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_acc_act_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_acc_act_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_acc_act_infos);

/** Add a new item to the msAccActInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ms_acc_act_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_acc_act_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_ms_access_activity_collection_t* ms_acc_act_infos);

/** Remove an item from the msAccActInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ms_acc_act_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_acc_act_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_ms_access_activity_collection_t* ms_acc_act_infos);

/** Get an item from the msAccActInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ms_access_activity_collection_t* data_collection_model_af_event_notification_get_entry_ms_acc_act_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the msAccActInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty msAccActInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_acc_act_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the msAccesses field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional msAccesses field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_ms_accesses(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the msAccesses field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the msAccesses field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_ms_accesses(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the msAccesses field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_accesses The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_accesses(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_ms_accesses);

/** Move a value to the msAccesses field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_ms_accesses The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_ms_accesses_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_ms_accesses);

/** Add a new item to the msAccesses array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param ms_accesses The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_ms_accesses(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_media_streaming_accesses_collection_t* ms_accesses);

/** Remove an item from the msAccesses array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param ms_accesses The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_ms_accesses(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_media_streaming_accesses_collection_t* ms_accesses);

/** Get an item from the msAccesses array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_accesses_collection_t* data_collection_model_af_event_notification_get_entry_ms_accesses(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the msAccesses array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty msAccesses for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_ms_accesses(data_collection_model_af_event_notification_t *af_event_notification);

/** Check if the gnssAssistDataInfo field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional gnssAssistDataInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_gnss_assist_data_info(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the gnssAssistDataInfo field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the gnssAssistDataInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_gnss_assist_data_info_t* data_collection_model_af_event_notification_get_gnss_assist_data_info(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the gnssAssistDataInfo field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_gnss_assist_data_info The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_gnss_assist_data_info(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_gnss_assist_data_info_t* p_gnss_assist_data_info);

/** Move a value to the gnssAssistDataInfo field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_gnss_assist_data_info The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_gnss_assist_data_info_move(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_gnss_assist_data_info_t* p_gnss_assist_data_info);

/** Check if the datVolTransTimeInfos field of a AfEventNotification object is set
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return `true` if the optional datVolTransTimeInfos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_af_event_notification_has_dat_vol_trans_time_infos(const data_collection_model_af_event_notification_t *af_event_notification);


/** Get the value of the datVolTransTimeInfos field of a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 *
 * @return the value current set for the datVolTransTimeInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_af_event_notification_get_dat_vol_trans_time_infos(const data_collection_model_af_event_notification_t *af_event_notification);

/** Set the value of the datVolTransTimeInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_dat_vol_trans_time_infos The value to copy into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *af_event_notification, const ogs_list_t* p_dat_vol_trans_time_infos);

/** Move a value to the datVolTransTimeInfos field in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to set the field in.
 * @param p_dat_vol_trans_time_infos The value to move into the AfEventNotification object.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_set_dat_vol_trans_time_infos_move(data_collection_model_af_event_notification_t *af_event_notification, ogs_list_t* p_dat_vol_trans_time_infos);

/** Add a new item to the datVolTransTimeInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to add the array item to.
 * @param dat_vol_trans_time_infos The value to add.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_add_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *af_event_notification, data_collection_model_dat_vol_trans_time_collection_t* dat_vol_trans_time_infos);

/** Remove an item from the datVolTransTimeInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to remove the array value from.
 * @param dat_vol_trans_time_infos The value to remove.
 *
 * @return @a af_event_notification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_remove_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *af_event_notification, const data_collection_model_dat_vol_trans_time_collection_t* dat_vol_trans_time_infos);

/** Get an item from the datVolTransTimeInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_dat_vol_trans_time_collection_t* data_collection_model_af_event_notification_get_entry_dat_vol_trans_time_infos(const data_collection_model_af_event_notification_t *af_event_notification, size_t idx);

/** Remove all entries from the datVolTransTimeInfos array in a AfEventNotification object
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * @param af_event_notification The AfEventNotification object to empty datVolTransTimeInfos for.
 *
 * @return @a af_event_notification
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_af_event_notification_t *data_collection_model_af_event_notification_clear_dat_vol_trans_time_infos(data_collection_model_af_event_notification_t *af_event_notification);

/** lnode helper for generating ogs_list_t nodes's of type AfEventNotification
 * \public \memberof data_collection_model_af_event_notification_t
 *
 * Creates a new data_collection_lnode_t object containing the @a af_event_notification object.
 * The @a af_event_notification will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param af_event_notification The AfEventNotification object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a af_event_notification
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_af_event_notification_make_lnode(data_collection_model_af_event_notification_t *af_event_notification);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_AF_EVENT_NOTIFICATION_H_ */

