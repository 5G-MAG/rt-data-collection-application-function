#ifndef _DATA_COLLECTION_INTEGRITY_RESULT_H_
#define _DATA_COLLECTION_INTEGRITY_RESULT_H_

/**********************************************************************************************************************************
 * IntegrityResult - Public C interface to the IntegrityResult object
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

#include "IntegrityComputingEntity.h"
#include "IntegrityProtectionLevel.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP IntegrityResult object reference
 */
typedef struct data_collection_model_integrity_result_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_integrity_result_t;



/** Create a new IntegrityResult.
 * \public \memberof data_collection_model_integrity_result_t
 * @return a new IntegrityResult object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_create();

/** Create a new IntegrityResult reference.
 * \public \memberof data_collection_model_integrity_result_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The IntegrityResult to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_create_ref(const data_collection_model_integrity_result_t *other);

/** Create a new copy of a IntegrityResult object.
 * \public \memberof data_collection_model_integrity_result_t
 * Creates a new copy of the given @a other object
 * @param other The IntegrityResult to copy.
 * @return a new IntegrityResult object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_create_copy(const data_collection_model_integrity_result_t *other);

/** Create a new reference of a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 * Creates a reference to the same underlying @a other object.
 * @param other The IntegrityResult to create a new reference to.
 * @return a new IntegrityResult object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_create_move(data_collection_model_integrity_result_t *other);

/** Copy the value of another IntegrityResult into this object
 * \public \memberof data_collection_model_integrity_result_t
 * Copies the value of @a other {{classname} object into @a integrity_result.
 * @param integrity_result The IntegrityResult object to copy @a other into.
 * @param other The IntegrityResult to copy the value from.
 * @return @a integrity_result.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_copy(data_collection_model_integrity_result_t *integrity_result, const data_collection_model_integrity_result_t *other);

/** Move the value of another IntegrityResult into this object
 * \public \memberof data_collection_model_integrity_result_t
 * Discards the current value of @a integrity_result and moves the value of @a other
 * into @a integrity_result. This will leave @a other as an empty reference.
 *
 * @param integrity_result The IntegrityResult object to move @a other into.
 * @param other The IntegrityResult to move the value from.
 *
 * @return @a integrity_result.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_move(data_collection_model_integrity_result_t *integrity_result, data_collection_model_integrity_result_t *other);

/** Delete a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 * Destroys the reference to the IntegrityResult object and frees the value of IntegrityResult if this is the last reference.
 *
 * @param integrity_result The IntegrityResult to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_integrity_result_free(data_collection_model_integrity_result_t *integrity_result);

/** Get a cJSON tree representation of a IntegrityResult
 * \public \memberof data_collection_model_integrity_result_t
 *
 * Create a cJSON tree representation of the IntegrityResult object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param integrity_result The IntegrityResult to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_integrity_result_toJSON(const data_collection_model_integrity_result_t *integrity_result, bool as_request);

/** Parse a cJSON tree into a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * Attempts to interpret a cJSON tree as a IntegrityResult API request or response (dependent on @a as_request value). If successful
 * will return a new referenced IntegrityResult object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new IntegrityResult object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two IntegrityResult objects to see if they are equivalent
 * \public \memberof data_collection_model_integrity_result_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param integrity_result The first IntegrityResult object to compare.
 * @param other_integrity_result The second IntegrityResult object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_is_equal_to(const data_collection_model_integrity_result_t *integrity_result, const data_collection_model_integrity_result_t *other_integrity_result);


/** Check if the computingEntity field of a IntegrityResult object is set
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to examine.
 *
 * @return `true` if the optional computingEntity field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_has_computing_entity(const data_collection_model_integrity_result_t *integrity_result);


/** Get the value of the computingEntity field of a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to examine.
 *
 * @return the value current set for the computingEntity field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_integrity_computing_entity_t* data_collection_model_integrity_result_get_computing_entity(const data_collection_model_integrity_result_t *integrity_result);

/** Set the value of the computingEntity field in a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to set the field in.
 * @param p_computing_entity The value to copy into the IntegrityResult object.
 *
 * @return @a integrity_result.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_computing_entity(data_collection_model_integrity_result_t *integrity_result, const data_collection_model_integrity_computing_entity_t* p_computing_entity);

/** Move a value to the computingEntity field in a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to set the field in.
 * @param p_computing_entity The value to move into the IntegrityResult object.
 *
 * @return @a integrity_result.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_computing_entity_move(data_collection_model_integrity_result_t *integrity_result, data_collection_model_integrity_computing_entity_t* p_computing_entity);

/** Check if the protectionLevel field of a IntegrityResult object is set
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to examine.
 *
 * @return `true` if the optional protectionLevel field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_has_protection_level(const data_collection_model_integrity_result_t *integrity_result);


/** Get the value of the protectionLevel field of a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to examine.
 *
 * @return the value current set for the protectionLevel field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_integrity_protection_level_t* data_collection_model_integrity_result_get_protection_level(const data_collection_model_integrity_result_t *integrity_result);

/** Set the value of the protectionLevel field in a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to set the field in.
 * @param p_protection_level The value to copy into the IntegrityResult object.
 *
 * @return @a integrity_result.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_protection_level(data_collection_model_integrity_result_t *integrity_result, const data_collection_model_integrity_protection_level_t* p_protection_level);

/** Move a value to the protectionLevel field in a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to set the field in.
 * @param p_protection_level The value to move into the IntegrityResult object.
 *
 * @return @a integrity_result.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_protection_level_move(data_collection_model_integrity_result_t *integrity_result, data_collection_model_integrity_protection_level_t* p_protection_level);

/** Check if the integrityReqMetInd field of a IntegrityResult object is set
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to examine.
 *
 * @return `true` if the optional integrityReqMetInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_has_integrity_req_met_ind(const data_collection_model_integrity_result_t *integrity_result);


/** Get the value of the integrityReqMetInd field of a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to examine.
 *
 * @return the value current set for the integrityReqMetInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_integrity_result_is_integrity_req_met_ind(const data_collection_model_integrity_result_t *integrity_result);

/** Set the value of the integrityReqMetInd field in a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to set the field in.
 * @param p_integrity_req_met_ind The value to copy into the IntegrityResult object.
 *
 * @return @a integrity_result.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_integrity_req_met_ind(data_collection_model_integrity_result_t *integrity_result, const bool p_integrity_req_met_ind);

/** Move a value to the integrityReqMetInd field in a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to set the field in.
 * @param p_integrity_req_met_ind The value to move into the IntegrityResult object.
 *
 * @return @a integrity_result.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_integrity_req_met_ind_move(data_collection_model_integrity_result_t *integrity_result, bool p_integrity_req_met_ind);

/** Check if the achievedTir field of a IntegrityResult object is set
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to examine.
 *
 * @return `true` if the optional achievedTir field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_result_has_achieved_tir(const data_collection_model_integrity_result_t *integrity_result);


/** Get the value of the achievedTir field of a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to examine.
 *
 * @return the value current set for the achievedTir field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_integrity_result_get_achieved_tir(const data_collection_model_integrity_result_t *integrity_result);

/** Set the value of the achievedTir field in a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to set the field in.
 * @param p_achieved_tir The value to copy into the IntegrityResult object.
 *
 * @return @a integrity_result.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_achieved_tir(data_collection_model_integrity_result_t *integrity_result, const int32_t p_achieved_tir);

/** Move a value to the achievedTir field in a IntegrityResult object
 * \public \memberof data_collection_model_integrity_result_t
 *
 * @param integrity_result The IntegrityResult object to set the field in.
 * @param p_achieved_tir The value to move into the IntegrityResult object.
 *
 * @return @a integrity_result.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_result_t *data_collection_model_integrity_result_set_achieved_tir_move(data_collection_model_integrity_result_t *integrity_result, int32_t p_achieved_tir);

/** lnode helper for generating ogs_list_t nodes's of type IntegrityResult
 * \public \memberof data_collection_model_integrity_result_t
 *
 * Creates a new data_collection_lnode_t object containing the @a integrity_result object.
 * The @a integrity_result will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param integrity_result The IntegrityResult object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a integrity_result
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_integrity_result_make_lnode(data_collection_model_integrity_result_t *integrity_result);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_INTEGRITY_RESULT_H_ */

