#ifndef _DATA_COLLECTION_SERVICE_EXPERIENCE_INFO_PER_FLOW_H_
#define _DATA_COLLECTION_SERVICE_EXPERIENCE_INFO_PER_FLOW_H_

/**********************************************************************************************************************************
 * ServiceExperienceInfoPerFlow - Public C interface to the ServiceExperienceInfoPerFlow object
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

#include "FlowInfo.h"
#include "SvcExperience.h"
#include "EthFlowDescription.h"
#include "TimeWindow.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ServiceExperienceInfoPerFlow object reference
 */
typedef struct data_collection_model_service_experience_info_per_flow_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_service_experience_info_per_flow_t;



/** Create a new ServiceExperienceInfoPerFlow.
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 * @return a new ServiceExperienceInfoPerFlow object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_create();

/** Create a new ServiceExperienceInfoPerFlow reference.
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The ServiceExperienceInfoPerFlow to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_create_ref(const data_collection_model_service_experience_info_per_flow_t *other);

/** Create a new copy of a ServiceExperienceInfoPerFlow object.
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 * Creates a new copy of the given @a other object
 * @param other The ServiceExperienceInfoPerFlow to copy.
 * @return a new ServiceExperienceInfoPerFlow object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_create_copy(const data_collection_model_service_experience_info_per_flow_t *other);

/** Create a new reference of a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ServiceExperienceInfoPerFlow to create a new reference to.
 * @return a new ServiceExperienceInfoPerFlow object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_create_move(data_collection_model_service_experience_info_per_flow_t *other);

/** Copy the value of another ServiceExperienceInfoPerFlow into this object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 * Copies the value of @a other {{classname} object into @a service_experience_info_per_flow.
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to copy @a other into.
 * @param other The ServiceExperienceInfoPerFlow to copy the value from.
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_copy(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_service_experience_info_per_flow_t *other);

/** Move the value of another ServiceExperienceInfoPerFlow into this object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 * Discards the current value of @a service_experience_info_per_flow and moves the value of @a other
 * into @a service_experience_info_per_flow. This will leave @a other as an empty reference.
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to move @a other into.
 * @param other The ServiceExperienceInfoPerFlow to move the value from.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_service_experience_info_per_flow_t *other);

/** Delete a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 * Destroys the reference to the ServiceExperienceInfoPerFlow object and frees the value of ServiceExperienceInfoPerFlow if this is the last reference.
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_service_experience_info_per_flow_free(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

/** Get a cJSON tree representation of a ServiceExperienceInfoPerFlow
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * Create a cJSON tree representation of the ServiceExperienceInfoPerFlow object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_service_experience_info_per_flow_toJSON(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, bool as_request);

/** Parse a cJSON tree into a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * Attempts to interpret a cJSON tree as a ServiceExperienceInfoPerFlow API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ServiceExperienceInfoPerFlow object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ServiceExperienceInfoPerFlow object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ServiceExperienceInfoPerFlow objects to see if they are equivalent
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param service_experience_info_per_flow The first ServiceExperienceInfoPerFlow object to compare.
 * @param other_service_experience_info_per_flow The second ServiceExperienceInfoPerFlow object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_is_equal_to(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_service_experience_info_per_flow_t *other_service_experience_info_per_flow);


/** Check if the svcExprc field of a ServiceExperienceInfoPerFlow object is set
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to examine.
 *
 * @return `true` if the optional svcExprc field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_has_svc_exprc(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);


/** Get the value of the svcExprc field of a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to examine.
 *
 * @return the value current set for the svcExprc field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_svc_experience_t* data_collection_model_service_experience_info_per_flow_get_svc_exprc(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

/** Set the value of the svcExprc field in a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to set the field in.
 * @param p_svc_exprc The value to copy into the ServiceExperienceInfoPerFlow object.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_svc_exprc(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_svc_experience_t* p_svc_exprc);

/** Move a value to the svcExprc field in a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to set the field in.
 * @param p_svc_exprc The value to move into the ServiceExperienceInfoPerFlow object.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_svc_exprc_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_svc_experience_t* p_svc_exprc);

/** Check if the timeIntev field of a ServiceExperienceInfoPerFlow object is set
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to examine.
 *
 * @return `true` if the optional timeIntev field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_has_time_intev(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);


/** Get the value of the timeIntev field of a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to examine.
 *
 * @return the value current set for the timeIntev field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_service_experience_info_per_flow_get_time_intev(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

/** Set the value of the timeIntev field in a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to set the field in.
 * @param p_time_intev The value to copy into the ServiceExperienceInfoPerFlow object.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_time_intev(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_time_window_t* p_time_intev);

/** Move a value to the timeIntev field in a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to set the field in.
 * @param p_time_intev The value to move into the ServiceExperienceInfoPerFlow object.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_time_intev_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_time_window_t* p_time_intev);

/** Check if the dnai field of a ServiceExperienceInfoPerFlow object is set
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to examine.
 *
 * @return `true` if the optional dnai field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_has_dnai(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);


/** Get the value of the dnai field of a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to examine.
 *
 * @return the value current set for the dnai field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_service_experience_info_per_flow_get_dnai(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

/** Set the value of the dnai field in a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to set the field in.
 * @param p_dnai The value to copy into the ServiceExperienceInfoPerFlow object.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_dnai(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const char* p_dnai);

/** Move a value to the dnai field in a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to set the field in.
 * @param p_dnai The value to move into the ServiceExperienceInfoPerFlow object.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_dnai_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, char* p_dnai);

/** Check if the ipTrafficFilter field of a ServiceExperienceInfoPerFlow object is set
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to examine.
 *
 * @return `true` if the optional ipTrafficFilter field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_has_ip_traffic_filter(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);


/** Get the value of the ipTrafficFilter field of a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to examine.
 *
 * @return the value current set for the ipTrafficFilter field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_info_t* data_collection_model_service_experience_info_per_flow_get_ip_traffic_filter(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

/** Set the value of the ipTrafficFilter field in a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to set the field in.
 * @param p_ip_traffic_filter The value to copy into the ServiceExperienceInfoPerFlow object.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_ip_traffic_filter(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_flow_info_t* p_ip_traffic_filter);

/** Move a value to the ipTrafficFilter field in a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to set the field in.
 * @param p_ip_traffic_filter The value to move into the ServiceExperienceInfoPerFlow object.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_ip_traffic_filter_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_flow_info_t* p_ip_traffic_filter);

/** Check if the ethTrafficFilter field of a ServiceExperienceInfoPerFlow object is set
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to examine.
 *
 * @return `true` if the optional ethTrafficFilter field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_flow_has_eth_traffic_filter(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);


/** Get the value of the ethTrafficFilter field of a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to examine.
 *
 * @return the value current set for the ethTrafficFilter field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_eth_flow_description_t* data_collection_model_service_experience_info_per_flow_get_eth_traffic_filter(const data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

/** Set the value of the ethTrafficFilter field in a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to set the field in.
 * @param p_eth_traffic_filter The value to copy into the ServiceExperienceInfoPerFlow object.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_eth_traffic_filter(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, const data_collection_model_eth_flow_description_t* p_eth_traffic_filter);

/** Move a value to the ethTrafficFilter field in a ServiceExperienceInfoPerFlow object
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to set the field in.
 * @param p_eth_traffic_filter The value to move into the ServiceExperienceInfoPerFlow object.
 *
 * @return @a service_experience_info_per_flow.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_flow_t *data_collection_model_service_experience_info_per_flow_set_eth_traffic_filter_move(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow, data_collection_model_eth_flow_description_t* p_eth_traffic_filter);

/** lnode helper for generating ogs_list_t nodes's of type ServiceExperienceInfoPerFlow
 * \public \memberof data_collection_model_service_experience_info_per_flow_t
 *
 * Creates a new data_collection_lnode_t object containing the @a service_experience_info_per_flow object.
 * The @a service_experience_info_per_flow will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param service_experience_info_per_flow The ServiceExperienceInfoPerFlow object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a service_experience_info_per_flow
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_service_experience_info_per_flow_make_lnode(data_collection_model_service_experience_info_per_flow_t *service_experience_info_per_flow);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SERVICE_EXPERIENCE_INFO_PER_FLOW_H_ */

