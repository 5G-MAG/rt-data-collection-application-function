#ifndef _DATA_COLLECTION_SERVICE_EXPERIENCE_INFO_PER_APP_H_
#define _DATA_COLLECTION_SERVICE_EXPERIENCE_INFO_PER_APP_H_

/**********************************************************************************************************************************
 * ServiceExperienceInfoPerApp - Public C interface to the ServiceExperienceInfoPerApp object
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

#include "ServiceExperienceInfoPerFlow.h"
#include "AddrFqdn.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ServiceExperienceInfoPerApp object reference
 */
typedef struct data_collection_model_service_experience_info_per_app_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_service_experience_info_per_app_t;



/** Create a new ServiceExperienceInfoPerApp
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 * @return a new ServiceExperienceInfoPerApp object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_create();

/** Create a new copy of a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 * Creates a new copy of the given @a other object
 * @param other The ServiceExperienceInfoPerApp to copy.
 * @return a new ServiceExperienceInfoPerApp object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_create_copy(const data_collection_model_service_experience_info_per_app_t *other);

/** Create a new reference of a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ServiceExperienceInfoPerApp to create a new reference to.
 * @return a new ServiceExperienceInfoPerApp object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_create_move(data_collection_model_service_experience_info_per_app_t *other);

/** Copy the value of another ServiceExperienceInfoPerApp into this object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 * Copies the value of @a other {{classname} object into @a service_experience_info_per_app.
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to copy @a other into.
 * @param other The ServiceExperienceInfoPerApp to copy the value from.
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_copy(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const data_collection_model_service_experience_info_per_app_t *other);

/** Move the value of another ServiceExperienceInfoPerApp into this object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 * Discards the current value of @a service_experience_info_per_app and moves the value of @a other
 * into @a service_experience_info_per_app. This will leave @a other as an empty reference.
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to move @a other into.
 * @param other The ServiceExperienceInfoPerApp to move the value from.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_move(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, data_collection_model_service_experience_info_per_app_t *other);

/** Delete a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 * Destroys the reference to the ServiceExperienceInfoPerApp object and frees the value of ServiceExperienceInfoPerApp if this is the last reference.
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_service_experience_info_per_app_free(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** Get a cJSON tree representation of a ServiceExperienceInfoPerApp
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * Create a cJSON tree representation of the ServiceExperienceInfoPerApp object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_service_experience_info_per_app_toJSON(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, bool as_request);

/** Parse a cJSON tree into a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * Attempts to interpret a cJSON tree as a ServiceExperienceInfoPerApp API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ServiceExperienceInfoPerApp object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ServiceExperienceInfoPerApp object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ServiceExperienceInfoPerApp objects to see if they are equivalent
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param service_experience_info_per_app The first ServiceExperienceInfoPerApp object to compare.
 * @param other_service_experience_info_per_app The second ServiceExperienceInfoPerApp object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_is_equal_to(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const data_collection_model_service_experience_info_per_app_t *other_service_experience_info_per_app);


/** Check if the appId field of a ServiceExperienceInfoPerApp object is set
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return `true` if the optional appId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_has_app_id(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);


/** Get the value of the appId field of a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return the value current set for the appId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_service_experience_info_per_app_get_app_id(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** Set the value of the appId field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_app_id The value to copy into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_id(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const char* p_app_id);

/** Move a value to the appId field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_app_id The value to move into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_id_move(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, char* p_app_id);

/** Check if the appServerIns field of a ServiceExperienceInfoPerApp object is set
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return `true` if the optional appServerIns field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_has_app_server_ins(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);


/** Get the value of the appServerIns field of a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return the value current set for the appServerIns field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_service_experience_info_per_app_get_app_server_ins(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** Set the value of the appServerIns field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_app_server_ins The value to copy into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_server_ins(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const data_collection_model_addr_fqdn_t* p_app_server_ins);

/** Move a value to the appServerIns field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_app_server_ins The value to move into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_server_ins_move(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, data_collection_model_addr_fqdn_t* p_app_server_ins);


/** Get the value of the svcExpPerFlows field of a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return the value current set for the svcExpPerFlows field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_info_per_app_get_svc_exp_per_flows(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** Set the value of the svcExpPerFlows field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_svc_exp_per_flows The value to copy into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const ogs_list_t* p_svc_exp_per_flows);

/** Move a value to the svcExpPerFlows field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_svc_exp_per_flows The value to move into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_svc_exp_per_flows_move(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, ogs_list_t* p_svc_exp_per_flows);

/** Add a new item to the svcExpPerFlows array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to add the array item to.
 * @param svc_exp_per_flows The value to add.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, data_collection_model_service_experience_info_per_flow_t* svc_exp_per_flows);

/** Remove an item from the svcExpPerFlows array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to remove the array value from.
 * @param svc_exp_per_flows The value to remove.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const data_collection_model_service_experience_info_per_flow_t* svc_exp_per_flows);

/** Get an item from the svcExpPerFlows array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_service_experience_info_per_flow_t* data_collection_model_service_experience_info_per_app_get_entry_svc_exp_per_flows(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, size_t idx);

/** Remove all entries from the svcExpPerFlows array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to empty svcExpPerFlows for.
 *
 * @return @a service_experience_info_per_app
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** Check if the gpsis field of a ServiceExperienceInfoPerApp object is set
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return `true` if the optional gpsis field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_has_gpsis(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);


/** Get the value of the gpsis field of a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return the value current set for the gpsis field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_info_per_app_get_gpsis(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** Set the value of the gpsis field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_gpsis The value to copy into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_gpsis(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const ogs_list_t* p_gpsis);

/** Move a value to the gpsis field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_gpsis The value to move into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_gpsis_move(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, ogs_list_t* p_gpsis);

/** Add a new item to the gpsis array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to add the array item to.
 * @param gpsis The value to add.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_gpsis(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, char* gpsis);

/** Remove an item from the gpsis array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to remove the array value from.
 * @param gpsis The value to remove.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_gpsis(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const char* gpsis);

/** Get an item from the gpsis array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_service_experience_info_per_app_get_entry_gpsis(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, size_t idx);

/** Remove all entries from the gpsis array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to empty gpsis for.
 *
 * @return @a service_experience_info_per_app
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_gpsis(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** Check if the supis field of a ServiceExperienceInfoPerApp object is set
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return `true` if the optional supis field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_has_supis(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);


/** Get the value of the supis field of a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return the value current set for the supis field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_info_per_app_get_supis(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** Set the value of the supis field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_supis The value to copy into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_supis(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const ogs_list_t* p_supis);

/** Move a value to the supis field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_supis The value to move into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_supis_move(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, ogs_list_t* p_supis);

/** Add a new item to the supis array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to add the array item to.
 * @param supis The value to add.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_supis(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, char* supis);

/** Remove an item from the supis array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to remove the array value from.
 * @param supis The value to remove.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_supis(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const char* supis);

/** Get an item from the supis array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_service_experience_info_per_app_get_entry_supis(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, size_t idx);

/** Remove all entries from the supis array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to empty supis for.
 *
 * @return @a service_experience_info_per_app
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_supis(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** Check if the contrWeights field of a ServiceExperienceInfoPerApp object is set
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return `true` if the optional contrWeights field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_has_contr_weights(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);


/** Get the value of the contrWeights field of a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 *
 * @return the value current set for the contrWeights field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_info_per_app_get_contr_weights(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** Set the value of the contrWeights field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_contr_weights The value to copy into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_contr_weights(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const ogs_list_t* p_contr_weights);

/** Move a value to the contrWeights field in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to set the field in.
 * @param p_contr_weights The value to move into the ServiceExperienceInfoPerApp object.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_contr_weights_move(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, ogs_list_t* p_contr_weights);

/** Add a new item to the contrWeights array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to add the array item to.
 * @param contr_weights The value to add.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_contr_weights(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, int32_t contr_weights);

/** Remove an item from the contrWeights array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to remove the array value from.
 * @param contr_weights The value to remove.
 *
 * @return @a service_experience_info_per_app.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_contr_weights(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const int32_t contr_weights);

/** Get an item from the contrWeights array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_service_experience_info_per_app_get_entry_contr_weights(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, size_t idx);

/** Remove all entries from the contrWeights array in a ServiceExperienceInfoPerApp object
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to empty contrWeights for.
 *
 * @return @a service_experience_info_per_app
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_contr_weights(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/** lnode helper for generating ogs_list_t nodes's of type ServiceExperienceInfoPerApp
 * \public \memberof data_collection_model_service_experience_info_per_app_t
 *
 * Creates a new data_collection_lnode_t object containing the @a service_experience_info_per_app object.
 * The @a service_experience_info_per_app will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param service_experience_info_per_app The ServiceExperienceInfoPerApp object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a service_experience_info_per_app
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_service_experience_info_per_app_make_lnode(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SERVICE_EXPERIENCE_INFO_PER_APP_H_ */

