#ifndef _DATA_COLLECTION_PER_FLOW_SERVICE_EXPERIENCE_INFO_H_
#define _DATA_COLLECTION_PER_FLOW_SERVICE_EXPERIENCE_INFO_H_

/**********************************************************************************************************************************
 * PerFlowServiceExperienceInfo - Public C interface to the PerFlowServiceExperienceInfo object
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

#include "SvcExperience.h"
#include "AddrFqdn.h"
#include "TimeWindow.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PerFlowServiceExperienceInfo object reference
 */
typedef struct data_collection_model_per_flow_service_experience_info_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_per_flow_service_experience_info_t;



/** Create a new PerFlowServiceExperienceInfo
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 * @return a new PerFlowServiceExperienceInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_create();

/** Create a new copy of a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 * Creates a new copy of the given @a other object
 * @param other The PerFlowServiceExperienceInfo to copy.
 * @return a new PerFlowServiceExperienceInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_create_copy(const data_collection_model_per_flow_service_experience_info_t *other);

/** Create a new reference of a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PerFlowServiceExperienceInfo to create a new reference to.
 * @return a new PerFlowServiceExperienceInfo object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_create_move(data_collection_model_per_flow_service_experience_info_t *other);

/** Copy the value of another PerFlowServiceExperienceInfo into this object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 * Copies the value of @a other {{classname} object into @a per_flow_service_experience_info.
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to copy @a other into.
 * @param other The PerFlowServiceExperienceInfo to copy the value from.
 * @return @a per_flow_service_experience_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_copy(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, const data_collection_model_per_flow_service_experience_info_t *other);

/** Move the value of another PerFlowServiceExperienceInfo into this object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 * Discards the current value of @a per_flow_service_experience_info and moves the value of @a other
 * into @a per_flow_service_experience_info. This will leave @a other as an empty reference.
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to move @a other into.
 * @param other The PerFlowServiceExperienceInfo to move the value from.
 *
 * @return @a per_flow_service_experience_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_move(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, data_collection_model_per_flow_service_experience_info_t *other);

/** Delete a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 * Destroys the reference to the PerFlowServiceExperienceInfo object and frees the value of PerFlowServiceExperienceInfo if this is the last reference.
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_per_flow_service_experience_info_free(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info);

/** Get a cJSON tree representation of a PerFlowServiceExperienceInfo
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * Create a cJSON tree representation of the PerFlowServiceExperienceInfo object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_per_flow_service_experience_info_toJSON(const data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, bool as_request);

/** Parse a cJSON tree into a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * Attempts to interpret a cJSON tree as a PerFlowServiceExperienceInfo API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PerFlowServiceExperienceInfo object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PerFlowServiceExperienceInfo object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PerFlowServiceExperienceInfo objects to see if they are equivalent
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param per_flow_service_experience_info The first PerFlowServiceExperienceInfo object to compare.
 * @param other_per_flow_service_experience_info The second PerFlowServiceExperienceInfo object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_flow_service_experience_info_is_equal_to(const data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, const data_collection_model_per_flow_service_experience_info_t *other_per_flow_service_experience_info);



/** Get the value of the serviceExperience field of a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to examine.
 *
 * @return the value current set for the serviceExperience field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_svc_experience_t* data_collection_model_per_flow_service_experience_info_get_service_experience(const data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info);

/** Set the value of the serviceExperience field in a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to set the field in.
 * @param p_service_experience The value to copy into the PerFlowServiceExperienceInfo object.
 *
 * @return @a per_flow_service_experience_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_service_experience(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, const data_collection_model_svc_experience_t* p_service_experience);

/** Move a value to the serviceExperience field in a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to set the field in.
 * @param p_service_experience The value to move into the PerFlowServiceExperienceInfo object.
 *
 * @return @a per_flow_service_experience_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_service_experience_move(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, data_collection_model_svc_experience_t* p_service_experience);


/** Get the value of the timeInterval field of a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to examine.
 *
 * @return the value current set for the timeInterval field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_per_flow_service_experience_info_get_time_interval(const data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info);

/** Set the value of the timeInterval field in a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to set the field in.
 * @param p_time_interval The value to copy into the PerFlowServiceExperienceInfo object.
 *
 * @return @a per_flow_service_experience_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_time_interval(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, const data_collection_model_time_window_t* p_time_interval);

/** Move a value to the timeInterval field in a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to set the field in.
 * @param p_time_interval The value to move into the PerFlowServiceExperienceInfo object.
 *
 * @return @a per_flow_service_experience_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_time_interval_move(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, data_collection_model_time_window_t* p_time_interval);


/** Get the value of the remoteEndpoint field of a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to examine.
 *
 * @return the value current set for the remoteEndpoint field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_per_flow_service_experience_info_get_remote_endpoint(const data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info);

/** Set the value of the remoteEndpoint field in a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to set the field in.
 * @param p_remote_endpoint The value to copy into the PerFlowServiceExperienceInfo object.
 *
 * @return @a per_flow_service_experience_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_remote_endpoint(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, const data_collection_model_addr_fqdn_t* p_remote_endpoint);

/** Move a value to the remoteEndpoint field in a PerFlowServiceExperienceInfo object
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to set the field in.
 * @param p_remote_endpoint The value to move into the PerFlowServiceExperienceInfo object.
 *
 * @return @a per_flow_service_experience_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_flow_service_experience_info_t *data_collection_model_per_flow_service_experience_info_set_remote_endpoint_move(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info, data_collection_model_addr_fqdn_t* p_remote_endpoint);

/** lnode helper for generating ogs_list_t nodes's of type PerFlowServiceExperienceInfo
 * \public \memberof data_collection_model_per_flow_service_experience_info_t
 *
 * Creates a new data_collection_lnode_t object containing the @a per_flow_service_experience_info object.
 * The @a per_flow_service_experience_info will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param per_flow_service_experience_info The PerFlowServiceExperienceInfo object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a per_flow_service_experience_info
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_per_flow_service_experience_info_make_lnode(data_collection_model_per_flow_service_experience_info_t *per_flow_service_experience_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PER_FLOW_SERVICE_EXPERIENCE_INFO_H_ */

