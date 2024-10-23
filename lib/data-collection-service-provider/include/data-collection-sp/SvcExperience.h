#ifndef _DATA_COLLECTION_SVC_EXPERIENCE_H_
#define _DATA_COLLECTION_SVC_EXPERIENCE_H_

/**********************************************************************************************************************************
 * SvcExperience - Public C interface to the SvcExperience object
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


/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP SvcExperience object reference
 */
typedef struct data_collection_model_svc_experience_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_svc_experience_t;



/** Create a new SvcExperience
 * \public \memberof data_collection_model_svc_experience_t
 * @return a new SvcExperience object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_create();

/** Create a new copy of a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 * Creates a new copy of the given @a other object
 * @param other The SvcExperience to copy.
 * @return a new SvcExperience object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_create_copy(const data_collection_model_svc_experience_t *other);

/** Create a new reference of a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 * Creates a reference to the same underlying @a other object.
 * @param other The SvcExperience to create a new reference to.
 * @return a new SvcExperience object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_create_move(data_collection_model_svc_experience_t *other);

/** Copy the value of another SvcExperience into this object
 * \public \memberof data_collection_model_svc_experience_t
 * Copies the value of @a other {{classname} object into @a svc_experience.
 * @param svc_experience The SvcExperience object to copy @a other into.
 * @param other The SvcExperience to copy the value from.
 * @return @a svc_experience.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_copy(data_collection_model_svc_experience_t *svc_experience, const data_collection_model_svc_experience_t *other);

/** Move the value of another SvcExperience into this object
 * \public \memberof data_collection_model_svc_experience_t
 * Discards the current value of @a svc_experience and moves the value of @a other
 * into @a svc_experience. This will leave @a other as an empty reference.
 *
 * @param svc_experience The SvcExperience object to move @a other into.
 * @param other The SvcExperience to move the value from.
 *
 * @return @a svc_experience.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_move(data_collection_model_svc_experience_t *svc_experience, data_collection_model_svc_experience_t *other);

/** Delete a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 * Destroys the reference to the SvcExperience object and frees the value of SvcExperience if this is the last reference.
 *
 * @param svc_experience The SvcExperience to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_svc_experience_free(data_collection_model_svc_experience_t *svc_experience);

/** Get a cJSON tree representation of a SvcExperience
 * \public \memberof data_collection_model_svc_experience_t
 *
 * Create a cJSON tree representation of the SvcExperience object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param svc_experience The SvcExperience to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_svc_experience_toJSON(const data_collection_model_svc_experience_t *svc_experience, bool as_request);

/** Parse a cJSON tree into a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 *
 * Attempts to interpret a cJSON tree as a SvcExperience API request or response (dependent on @a as_request value). If successful
 * will return a new referenced SvcExperience object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new SvcExperience object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two SvcExperience objects to see if they are equivalent
 * \public \memberof data_collection_model_svc_experience_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param svc_experience The first SvcExperience object to compare.
 * @param other_svc_experience The second SvcExperience object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_svc_experience_is_equal_to(const data_collection_model_svc_experience_t *svc_experience, const data_collection_model_svc_experience_t *other_svc_experience);


/** Check if the mos field of a SvcExperience object is set
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to examine.
 *
 * @return `true` if the optional mos field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_svc_experience_has_mos(const data_collection_model_svc_experience_t *svc_experience);


/** Get the value of the mos field of a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to examine.
 *
 * @return the value current set for the mos field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_svc_experience_get_mos(const data_collection_model_svc_experience_t *svc_experience);

/** Set the value of the mos field in a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to set the field in.
 * @param p_mos The value to copy into the SvcExperience object.
 *
 * @return @a svc_experience.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_mos(data_collection_model_svc_experience_t *svc_experience, const float p_mos);

/** Move a value to the mos field in a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to set the field in.
 * @param p_mos The value to move into the SvcExperience object.
 *
 * @return @a svc_experience.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_mos_move(data_collection_model_svc_experience_t *svc_experience, float p_mos);

/** Check if the upperRange field of a SvcExperience object is set
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to examine.
 *
 * @return `true` if the optional upperRange field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_svc_experience_has_upper_range(const data_collection_model_svc_experience_t *svc_experience);


/** Get the value of the upperRange field of a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to examine.
 *
 * @return the value current set for the upperRange field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_svc_experience_get_upper_range(const data_collection_model_svc_experience_t *svc_experience);

/** Set the value of the upperRange field in a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to set the field in.
 * @param p_upper_range The value to copy into the SvcExperience object.
 *
 * @return @a svc_experience.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_upper_range(data_collection_model_svc_experience_t *svc_experience, const float p_upper_range);

/** Move a value to the upperRange field in a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to set the field in.
 * @param p_upper_range The value to move into the SvcExperience object.
 *
 * @return @a svc_experience.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_upper_range_move(data_collection_model_svc_experience_t *svc_experience, float p_upper_range);

/** Check if the lowerRange field of a SvcExperience object is set
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to examine.
 *
 * @return `true` if the optional lowerRange field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_svc_experience_has_lower_range(const data_collection_model_svc_experience_t *svc_experience);


/** Get the value of the lowerRange field of a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to examine.
 *
 * @return the value current set for the lowerRange field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_svc_experience_get_lower_range(const data_collection_model_svc_experience_t *svc_experience);

/** Set the value of the lowerRange field in a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to set the field in.
 * @param p_lower_range The value to copy into the SvcExperience object.
 *
 * @return @a svc_experience.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_lower_range(data_collection_model_svc_experience_t *svc_experience, const float p_lower_range);

/** Move a value to the lowerRange field in a SvcExperience object
 * \public \memberof data_collection_model_svc_experience_t
 *
 * @param svc_experience The SvcExperience object to set the field in.
 * @param p_lower_range The value to move into the SvcExperience object.
 *
 * @return @a svc_experience.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_lower_range_move(data_collection_model_svc_experience_t *svc_experience, float p_lower_range);

/** lnode helper for generating ogs_list_t nodes's of type SvcExperience
 * \public \memberof data_collection_model_svc_experience_t
 *
 * Creates a new data_collection_lnode_t object containing the @a svc_experience object.
 * The @a svc_experience will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param svc_experience The SvcExperience object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a svc_experience
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_svc_experience_make_lnode(data_collection_model_svc_experience_t *svc_experience);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SVC_EXPERIENCE_H_ */

