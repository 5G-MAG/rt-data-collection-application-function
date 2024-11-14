#ifndef _DATA_COLLECTION_SERVICE_EXPERIENCE_RECORD_ALL_OF_H_
#define _DATA_COLLECTION_SERVICE_EXPERIENCE_RECORD_ALL_OF_H_

/**********************************************************************************************************************************
 * ServiceExperienceRecord_allOf - Public C interface to the ServiceExperienceRecord_allOf object
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

#include "PerFlowServiceExperienceInfo.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ServiceExperienceRecord_allOf object reference
 */
typedef struct data_collection_model_service_experience_record_all_of_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_service_experience_record_all_of_t;



/** Create a new ServiceExperienceRecord_allOf.
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 * @return a new ServiceExperienceRecord_allOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_create();

/** Create a new ServiceExperienceRecord_allOf reference.
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The ServiceExperienceRecord_allOf to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_create_ref(const data_collection_model_service_experience_record_all_of_t *other);

/** Create a new copy of a ServiceExperienceRecord_allOf object.
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 * Creates a new copy of the given @a other object
 * @param other The ServiceExperienceRecord_allOf to copy.
 * @return a new ServiceExperienceRecord_allOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_create_copy(const data_collection_model_service_experience_record_all_of_t *other);

/** Create a new reference of a ServiceExperienceRecord_allOf object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ServiceExperienceRecord_allOf to create a new reference to.
 * @return a new ServiceExperienceRecord_allOf object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_create_move(data_collection_model_service_experience_record_all_of_t *other);

/** Copy the value of another ServiceExperienceRecord_allOf into this object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 * Copies the value of @a other {{classname} object into @a service_experience_record_all_of.
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf object to copy @a other into.
 * @param other The ServiceExperienceRecord_allOf to copy the value from.
 * @return @a service_experience_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_copy(data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of, const data_collection_model_service_experience_record_all_of_t *other);

/** Move the value of another ServiceExperienceRecord_allOf into this object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 * Discards the current value of @a service_experience_record_all_of and moves the value of @a other
 * into @a service_experience_record_all_of. This will leave @a other as an empty reference.
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf object to move @a other into.
 * @param other The ServiceExperienceRecord_allOf to move the value from.
 *
 * @return @a service_experience_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_move(data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of, data_collection_model_service_experience_record_all_of_t *other);

/** Delete a ServiceExperienceRecord_allOf object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 * Destroys the reference to the ServiceExperienceRecord_allOf object and frees the value of ServiceExperienceRecord_allOf if this is the last reference.
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_service_experience_record_all_of_free(data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of);

/** Get a cJSON tree representation of a ServiceExperienceRecord_allOf
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * Create a cJSON tree representation of the ServiceExperienceRecord_allOf object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_service_experience_record_all_of_toJSON(const data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of, bool as_request);

/** Parse a cJSON tree into a ServiceExperienceRecord_allOf object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * Attempts to interpret a cJSON tree as a ServiceExperienceRecord_allOf API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ServiceExperienceRecord_allOf object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ServiceExperienceRecord_allOf object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ServiceExperienceRecord_allOf objects to see if they are equivalent
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param service_experience_record_all_of The first ServiceExperienceRecord_allOf object to compare.
 * @param other_service_experience_record_all_of The second ServiceExperienceRecord_allOf object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_record_all_of_is_equal_to(const data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of, const data_collection_model_service_experience_record_all_of_t *other_service_experience_record_all_of);



/** Get the value of the serviceExperienceInfos field of a ServiceExperienceRecord_allOf object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf object to examine.
 *
 * @return the value current set for the serviceExperienceInfos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_record_all_of_get_service_experience_infos(const data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of);

/** Set the value of the serviceExperienceInfos field in a ServiceExperienceRecord_allOf object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf object to set the field in.
 * @param p_service_experience_infos The value to copy into the ServiceExperienceRecord_allOf object.
 *
 * @return @a service_experience_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_set_service_experience_infos(data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of, const ogs_list_t* p_service_experience_infos);

/** Move a value to the serviceExperienceInfos field in a ServiceExperienceRecord_allOf object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf object to set the field in.
 * @param p_service_experience_infos The value to move into the ServiceExperienceRecord_allOf object.
 *
 * @return @a service_experience_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_set_service_experience_infos_move(data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of, ogs_list_t* p_service_experience_infos);

/** Add a new item to the serviceExperienceInfos array in a ServiceExperienceRecord_allOf object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf object to add the array item to.
 * @param service_experience_infos The value to add.
 *
 * @return @a service_experience_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_add_service_experience_infos(data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of, data_collection_model_per_flow_service_experience_info_t* service_experience_infos);

/** Remove an item from the serviceExperienceInfos array in a ServiceExperienceRecord_allOf object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf object to remove the array value from.
 * @param service_experience_infos The value to remove.
 *
 * @return @a service_experience_record_all_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_remove_service_experience_infos(data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of, const data_collection_model_per_flow_service_experience_info_t* service_experience_infos);

/** Get an item from the serviceExperienceInfos array in a ServiceExperienceRecord_allOf object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_per_flow_service_experience_info_t* data_collection_model_service_experience_record_all_of_get_entry_service_experience_infos(const data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of, size_t idx);

/** Remove all entries from the serviceExperienceInfos array in a ServiceExperienceRecord_allOf object
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf object to empty serviceExperienceInfos for.
 *
 * @return @a service_experience_record_all_of
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_record_all_of_t *data_collection_model_service_experience_record_all_of_clear_service_experience_infos(data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of);

/** lnode helper for generating ogs_list_t nodes's of type ServiceExperienceRecord_allOf
 * \public \memberof data_collection_model_service_experience_record_all_of_t
 *
 * Creates a new data_collection_lnode_t object containing the @a service_experience_record_all_of object.
 * The @a service_experience_record_all_of will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param service_experience_record_all_of The ServiceExperienceRecord_allOf object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a service_experience_record_all_of
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_service_experience_record_all_of_make_lnode(data_collection_model_service_experience_record_all_of_t *service_experience_record_all_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SERVICE_EXPERIENCE_RECORD_ALL_OF_H_ */

