#ifndef _DATA_COLLECTION_UE_AREA_INDICATION_H_
#define _DATA_COLLECTION_UE_AREA_INDICATION_H_

/**********************************************************************************************************************************
 * UeAreaIndication - Public C interface to the UeAreaIndication object
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

/** A 3GPP UeAreaIndication object reference
 */
typedef struct data_collection_model_ue_area_indication_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ue_area_indication_t;



/** Create a new UeAreaIndication.
 * \public \memberof data_collection_model_ue_area_indication_t
 * @return a new UeAreaIndication object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create();

/** Create a new UeAreaIndication reference.
 * \public \memberof data_collection_model_ue_area_indication_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The UeAreaIndication to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create_ref(const data_collection_model_ue_area_indication_t *other);

/** Create a new copy of a UeAreaIndication object.
 * \public \memberof data_collection_model_ue_area_indication_t
 * Creates a new copy of the given @a other object
 * @param other The UeAreaIndication to copy.
 * @return a new UeAreaIndication object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create_copy(const data_collection_model_ue_area_indication_t *other);

/** Create a new reference of a UeAreaIndication object
 * \public \memberof data_collection_model_ue_area_indication_t
 * Creates a reference to the same underlying @a other object.
 * @param other The UeAreaIndication to create a new reference to.
 * @return a new UeAreaIndication object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create_move(data_collection_model_ue_area_indication_t *other);

/** Copy the value of another UeAreaIndication into this object
 * \public \memberof data_collection_model_ue_area_indication_t
 * Copies the value of @a other {{classname} object into @a ue_area_indication.
 * @param ue_area_indication The UeAreaIndication object to copy @a other into.
 * @param other The UeAreaIndication to copy the value from.
 * @return @a ue_area_indication.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_copy(data_collection_model_ue_area_indication_t *ue_area_indication, const data_collection_model_ue_area_indication_t *other);

/** Move the value of another UeAreaIndication into this object
 * \public \memberof data_collection_model_ue_area_indication_t
 * Discards the current value of @a ue_area_indication and moves the value of @a other
 * into @a ue_area_indication. This will leave @a other as an empty reference.
 *
 * @param ue_area_indication The UeAreaIndication object to move @a other into.
 * @param other The UeAreaIndication to move the value from.
 *
 * @return @a ue_area_indication.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_move(data_collection_model_ue_area_indication_t *ue_area_indication, data_collection_model_ue_area_indication_t *other);

/** Delete a UeAreaIndication object
 * \public \memberof data_collection_model_ue_area_indication_t
 * Destroys the reference to the UeAreaIndication object and frees the value of UeAreaIndication if this is the last reference.
 *
 * @param ue_area_indication The UeAreaIndication to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_area_indication_free(data_collection_model_ue_area_indication_t *ue_area_indication);

/** Get a cJSON tree representation of a UeAreaIndication
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * Create a cJSON tree representation of the UeAreaIndication object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ue_area_indication The UeAreaIndication to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_area_indication_toJSON(const data_collection_model_ue_area_indication_t *ue_area_indication, bool as_request);

/** Parse a cJSON tree into a UeAreaIndication object
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * Attempts to interpret a cJSON tree as a UeAreaIndication API request or response (dependent on @a as_request value). If successful
 * will return a new referenced UeAreaIndication object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new UeAreaIndication object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two UeAreaIndication objects to see if they are equivalent
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ue_area_indication The first UeAreaIndication object to compare.
 * @param other_ue_area_indication The second UeAreaIndication object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_area_indication_is_equal_to(const data_collection_model_ue_area_indication_t *ue_area_indication, const data_collection_model_ue_area_indication_t *other_ue_area_indication);


/** Check if the country field of a UeAreaIndication object is set
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * @param ue_area_indication The UeAreaIndication object to examine.
 *
 * @return `true` if the optional country field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_area_indication_has_country(const data_collection_model_ue_area_indication_t *ue_area_indication);


/** Get the value of the country field of a UeAreaIndication object
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * @param ue_area_indication The UeAreaIndication object to examine.
 *
 * @return the value current set for the country field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_area_indication_get_country(const data_collection_model_ue_area_indication_t *ue_area_indication);

/** Set the value of the country field in a UeAreaIndication object
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * @param ue_area_indication The UeAreaIndication object to set the field in.
 * @param p_country The value to copy into the UeAreaIndication object.
 *
 * @return @a ue_area_indication.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_country(data_collection_model_ue_area_indication_t *ue_area_indication, const char* p_country);

/** Move a value to the country field in a UeAreaIndication object
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * @param ue_area_indication The UeAreaIndication object to set the field in.
 * @param p_country The value to move into the UeAreaIndication object.
 *
 * @return @a ue_area_indication.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_country_move(data_collection_model_ue_area_indication_t *ue_area_indication, char* p_country);

/** Check if the internationalAreaInd field of a UeAreaIndication object is set
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * @param ue_area_indication The UeAreaIndication object to examine.
 *
 * @return `true` if the optional internationalAreaInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_area_indication_has_international_area_ind(const data_collection_model_ue_area_indication_t *ue_area_indication);


/** Get the value of the internationalAreaInd field of a UeAreaIndication object
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * @param ue_area_indication The UeAreaIndication object to examine.
 *
 * @return the value current set for the internationalAreaInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_ue_area_indication_is_international_area_ind(const data_collection_model_ue_area_indication_t *ue_area_indication);

/** Set the value of the internationalAreaInd field in a UeAreaIndication object
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * @param ue_area_indication The UeAreaIndication object to set the field in.
 * @param p_international_area_ind The value to copy into the UeAreaIndication object.
 *
 * @return @a ue_area_indication.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_international_area_ind(data_collection_model_ue_area_indication_t *ue_area_indication, const bool p_international_area_ind);

/** Move a value to the internationalAreaInd field in a UeAreaIndication object
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * @param ue_area_indication The UeAreaIndication object to set the field in.
 * @param p_international_area_ind The value to move into the UeAreaIndication object.
 *
 * @return @a ue_area_indication.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_international_area_ind_move(data_collection_model_ue_area_indication_t *ue_area_indication, bool p_international_area_ind);

/** lnode helper for generating ogs_list_t nodes's of type UeAreaIndication
 * \public \memberof data_collection_model_ue_area_indication_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ue_area_indication object.
 * The @a ue_area_indication will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ue_area_indication The UeAreaIndication object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ue_area_indication
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_area_indication_make_lnode(data_collection_model_ue_area_indication_t *ue_area_indication);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UE_AREA_INDICATION_H_ */

