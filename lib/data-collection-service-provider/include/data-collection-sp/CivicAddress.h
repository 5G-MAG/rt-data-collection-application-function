#ifndef _DATA_COLLECTION_CIVIC_ADDRESS_H_
#define _DATA_COLLECTION_CIVIC_ADDRESS_H_

/**********************************************************************************************************************************
 * CivicAddress - Public C interface to the CivicAddress object
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

/** A 3GPP CivicAddress object reference
 */
typedef struct data_collection_model_civic_address_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_civic_address_t;



/** Create a new CivicAddress.
 * \public \memberof data_collection_model_civic_address_t
 * @return a new CivicAddress object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_create();

/** Create a new CivicAddress reference.
 * \public \memberof data_collection_model_civic_address_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The CivicAddress to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_create_ref(const data_collection_model_civic_address_t *other);

/** Create a new copy of a CivicAddress object.
 * \public \memberof data_collection_model_civic_address_t
 * Creates a new copy of the given @a other object
 * @param other The CivicAddress to copy.
 * @return a new CivicAddress object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_create_copy(const data_collection_model_civic_address_t *other);

/** Create a new reference of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 * Creates a reference to the same underlying @a other object.
 * @param other The CivicAddress to create a new reference to.
 * @return a new CivicAddress object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_create_move(data_collection_model_civic_address_t *other);

/** Copy the value of another CivicAddress into this object
 * \public \memberof data_collection_model_civic_address_t
 * Copies the value of @a other {{classname} object into @a civic_address.
 * @param civic_address The CivicAddress object to copy @a other into.
 * @param other The CivicAddress to copy the value from.
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_copy(data_collection_model_civic_address_t *civic_address, const data_collection_model_civic_address_t *other);

/** Move the value of another CivicAddress into this object
 * \public \memberof data_collection_model_civic_address_t
 * Discards the current value of @a civic_address and moves the value of @a other
 * into @a civic_address. This will leave @a other as an empty reference.
 *
 * @param civic_address The CivicAddress object to move @a other into.
 * @param other The CivicAddress to move the value from.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_move(data_collection_model_civic_address_t *civic_address, data_collection_model_civic_address_t *other);

/** Delete a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 * Destroys the reference to the CivicAddress object and frees the value of CivicAddress if this is the last reference.
 *
 * @param civic_address The CivicAddress to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_civic_address_free(data_collection_model_civic_address_t *civic_address);

/** Get a cJSON tree representation of a CivicAddress
 * \public \memberof data_collection_model_civic_address_t
 *
 * Create a cJSON tree representation of the CivicAddress object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param civic_address The CivicAddress to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_civic_address_toJSON(const data_collection_model_civic_address_t *civic_address, bool as_request);

/** Parse a cJSON tree into a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * Attempts to interpret a cJSON tree as a CivicAddress API request or response (dependent on @a as_request value). If successful
 * will return a new referenced CivicAddress object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new CivicAddress object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two CivicAddress objects to see if they are equivalent
 * \public \memberof data_collection_model_civic_address_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param civic_address The first CivicAddress object to compare.
 * @param other_civic_address The second CivicAddress object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_is_equal_to(const data_collection_model_civic_address_t *civic_address, const data_collection_model_civic_address_t *other_civic_address);


/** Check if the country field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional country field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_country(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the country field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the country field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_country(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the country field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_country The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_country(data_collection_model_civic_address_t *civic_address, const char* p_country);

/** Move a value to the country field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_country The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_country_move(data_collection_model_civic_address_t *civic_address, char* p_country);

/** Check if the A1 field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional A1 field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a1(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the A1 field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the A1 field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a1(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the A1 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a1 The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a1(data_collection_model_civic_address_t *civic_address, const char* p_a1);

/** Move a value to the A1 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a1 The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a1_move(data_collection_model_civic_address_t *civic_address, char* p_a1);

/** Check if the A2 field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional A2 field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a2(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the A2 field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the A2 field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a2(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the A2 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a2 The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a2(data_collection_model_civic_address_t *civic_address, const char* p_a2);

/** Move a value to the A2 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a2 The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a2_move(data_collection_model_civic_address_t *civic_address, char* p_a2);

/** Check if the A3 field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional A3 field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a3(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the A3 field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the A3 field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a3(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the A3 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a3 The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a3(data_collection_model_civic_address_t *civic_address, const char* p_a3);

/** Move a value to the A3 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a3 The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a3_move(data_collection_model_civic_address_t *civic_address, char* p_a3);

/** Check if the A4 field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional A4 field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a4(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the A4 field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the A4 field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a4(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the A4 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a4 The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a4(data_collection_model_civic_address_t *civic_address, const char* p_a4);

/** Move a value to the A4 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a4 The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a4_move(data_collection_model_civic_address_t *civic_address, char* p_a4);

/** Check if the A5 field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional A5 field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a5(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the A5 field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the A5 field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a5(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the A5 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a5 The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a5(data_collection_model_civic_address_t *civic_address, const char* p_a5);

/** Move a value to the A5 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a5 The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a5_move(data_collection_model_civic_address_t *civic_address, char* p_a5);

/** Check if the A6 field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional A6 field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a6(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the A6 field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the A6 field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a6(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the A6 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a6 The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a6(data_collection_model_civic_address_t *civic_address, const char* p_a6);

/** Move a value to the A6 field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_a6 The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a6_move(data_collection_model_civic_address_t *civic_address, char* p_a6);

/** Check if the PRD field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional PRD field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_prd(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the PRD field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the PRD field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_prd(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the PRD field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_prd The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prd(data_collection_model_civic_address_t *civic_address, const char* p_prd);

/** Move a value to the PRD field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_prd The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prd_move(data_collection_model_civic_address_t *civic_address, char* p_prd);

/** Check if the POD field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional POD field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_pod(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the POD field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the POD field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pod(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the POD field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_pod The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pod(data_collection_model_civic_address_t *civic_address, const char* p_pod);

/** Move a value to the POD field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_pod The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pod_move(data_collection_model_civic_address_t *civic_address, char* p_pod);

/** Check if the STS field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional STS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_sts(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the STS field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the STS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_sts(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the STS field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_sts The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_sts(data_collection_model_civic_address_t *civic_address, const char* p_sts);

/** Move a value to the STS field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_sts The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_sts_move(data_collection_model_civic_address_t *civic_address, char* p_sts);

/** Check if the HNO field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional HNO field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_hno(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the HNO field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the HNO field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_hno(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the HNO field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_hno The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hno(data_collection_model_civic_address_t *civic_address, const char* p_hno);

/** Move a value to the HNO field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_hno The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hno_move(data_collection_model_civic_address_t *civic_address, char* p_hno);

/** Check if the HNS field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional HNS field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_hns(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the HNS field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the HNS field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_hns(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the HNS field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_hns The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hns(data_collection_model_civic_address_t *civic_address, const char* p_hns);

/** Move a value to the HNS field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_hns The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hns_move(data_collection_model_civic_address_t *civic_address, char* p_hns);

/** Check if the LMK field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional LMK field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_lmk(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the LMK field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the LMK field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_lmk(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the LMK field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_lmk The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_lmk(data_collection_model_civic_address_t *civic_address, const char* p_lmk);

/** Move a value to the LMK field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_lmk The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_lmk_move(data_collection_model_civic_address_t *civic_address, char* p_lmk);

/** Check if the LOC field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional LOC field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_loc(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the LOC field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the LOC field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_loc(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the LOC field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_loc The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_loc(data_collection_model_civic_address_t *civic_address, const char* p_loc);

/** Move a value to the LOC field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_loc The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_loc_move(data_collection_model_civic_address_t *civic_address, char* p_loc);

/** Check if the NAM field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional NAM field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_nam(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the NAM field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the NAM field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_nam(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the NAM field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_nam The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_nam(data_collection_model_civic_address_t *civic_address, const char* p_nam);

/** Move a value to the NAM field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_nam The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_nam_move(data_collection_model_civic_address_t *civic_address, char* p_nam);

/** Check if the PC field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional PC field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_pc(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the PC field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the PC field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pc(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the PC field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_pc The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pc(data_collection_model_civic_address_t *civic_address, const char* p_pc);

/** Move a value to the PC field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_pc The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pc_move(data_collection_model_civic_address_t *civic_address, char* p_pc);

/** Check if the BLD field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional BLD field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_bld(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the BLD field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the BLD field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_bld(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the BLD field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_bld The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_bld(data_collection_model_civic_address_t *civic_address, const char* p_bld);

/** Move a value to the BLD field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_bld The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_bld_move(data_collection_model_civic_address_t *civic_address, char* p_bld);

/** Check if the UNIT field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional UNIT field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_unit(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the UNIT field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the UNIT field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_unit(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the UNIT field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_unit The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_unit(data_collection_model_civic_address_t *civic_address, const char* p_unit);

/** Move a value to the UNIT field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_unit The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_unit_move(data_collection_model_civic_address_t *civic_address, char* p_unit);

/** Check if the FLR field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional FLR field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_flr(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the FLR field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the FLR field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_flr(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the FLR field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_flr The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_flr(data_collection_model_civic_address_t *civic_address, const char* p_flr);

/** Move a value to the FLR field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_flr The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_flr_move(data_collection_model_civic_address_t *civic_address, char* p_flr);

/** Check if the ROOM field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional ROOM field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_room(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the ROOM field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the ROOM field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_room(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the ROOM field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_room The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_room(data_collection_model_civic_address_t *civic_address, const char* p_room);

/** Move a value to the ROOM field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_room The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_room_move(data_collection_model_civic_address_t *civic_address, char* p_room);

/** Check if the PLC field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional PLC field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_plc(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the PLC field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the PLC field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_plc(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the PLC field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_plc The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_plc(data_collection_model_civic_address_t *civic_address, const char* p_plc);

/** Move a value to the PLC field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_plc The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_plc_move(data_collection_model_civic_address_t *civic_address, char* p_plc);

/** Check if the PCN field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional PCN field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_pcn(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the PCN field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the PCN field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pcn(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the PCN field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_pcn The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pcn(data_collection_model_civic_address_t *civic_address, const char* p_pcn);

/** Move a value to the PCN field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_pcn The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pcn_move(data_collection_model_civic_address_t *civic_address, char* p_pcn);

/** Check if the POBOX field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional POBOX field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_pobox(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the POBOX field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the POBOX field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pobox(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the POBOX field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_pobox The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pobox(data_collection_model_civic_address_t *civic_address, const char* p_pobox);

/** Move a value to the POBOX field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_pobox The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pobox_move(data_collection_model_civic_address_t *civic_address, char* p_pobox);

/** Check if the ADDCODE field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional ADDCODE field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_addcode(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the ADDCODE field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the ADDCODE field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_addcode(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the ADDCODE field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_addcode The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_addcode(data_collection_model_civic_address_t *civic_address, const char* p_addcode);

/** Move a value to the ADDCODE field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_addcode The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_addcode_move(data_collection_model_civic_address_t *civic_address, char* p_addcode);

/** Check if the SEAT field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional SEAT field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_seat(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the SEAT field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the SEAT field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_seat(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the SEAT field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_seat The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_seat(data_collection_model_civic_address_t *civic_address, const char* p_seat);

/** Move a value to the SEAT field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_seat The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_seat_move(data_collection_model_civic_address_t *civic_address, char* p_seat);

/** Check if the RD field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional RD field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_rd(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the RD field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the RD field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rd(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the RD field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_rd The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rd(data_collection_model_civic_address_t *civic_address, const char* p_rd);

/** Move a value to the RD field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_rd The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rd_move(data_collection_model_civic_address_t *civic_address, char* p_rd);

/** Check if the RDSEC field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional RDSEC field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_rdsec(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the RDSEC field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the RDSEC field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rdsec(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the RDSEC field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_rdsec The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsec(data_collection_model_civic_address_t *civic_address, const char* p_rdsec);

/** Move a value to the RDSEC field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_rdsec The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsec_move(data_collection_model_civic_address_t *civic_address, char* p_rdsec);

/** Check if the RDBR field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional RDBR field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_rdbr(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the RDBR field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the RDBR field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rdbr(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the RDBR field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_rdbr The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdbr(data_collection_model_civic_address_t *civic_address, const char* p_rdbr);

/** Move a value to the RDBR field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_rdbr The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdbr_move(data_collection_model_civic_address_t *civic_address, char* p_rdbr);

/** Check if the RDSUBBR field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional RDSUBBR field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_rdsubbr(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the RDSUBBR field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the RDSUBBR field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rdsubbr(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the RDSUBBR field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_rdsubbr The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsubbr(data_collection_model_civic_address_t *civic_address, const char* p_rdsubbr);

/** Move a value to the RDSUBBR field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_rdsubbr The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsubbr_move(data_collection_model_civic_address_t *civic_address, char* p_rdsubbr);

/** Check if the PRM field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional PRM field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_prm(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the PRM field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the PRM field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_prm(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the PRM field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_prm The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prm(data_collection_model_civic_address_t *civic_address, const char* p_prm);

/** Move a value to the PRM field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_prm The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prm_move(data_collection_model_civic_address_t *civic_address, char* p_prm);

/** Check if the POM field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional POM field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_pom(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the POM field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the POM field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pom(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the POM field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_pom The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pom(data_collection_model_civic_address_t *civic_address, const char* p_pom);

/** Move a value to the POM field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_pom The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pom_move(data_collection_model_civic_address_t *civic_address, char* p_pom);

/** Check if the usageRules field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional usageRules field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_usage_rules(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the usageRules field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the usageRules field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_usage_rules(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the usageRules field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_usage_rules The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_usage_rules(data_collection_model_civic_address_t *civic_address, const char* p_usage_rules);

/** Move a value to the usageRules field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_usage_rules The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_usage_rules_move(data_collection_model_civic_address_t *civic_address, char* p_usage_rules);

/** Check if the method field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional method field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_method(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the method field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the method field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_method(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the method field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_method The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_method(data_collection_model_civic_address_t *civic_address, const char* p_method);

/** Move a value to the method field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_method The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_method_move(data_collection_model_civic_address_t *civic_address, char* p_method);

/** Check if the providedBy field of a CivicAddress object is set
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return `true` if the optional providedBy field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_provided_by(const data_collection_model_civic_address_t *civic_address);


/** Get the value of the providedBy field of a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to examine.
 *
 * @return the value current set for the providedBy field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_provided_by(const data_collection_model_civic_address_t *civic_address);

/** Set the value of the providedBy field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_provided_by The value to copy into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_provided_by(data_collection_model_civic_address_t *civic_address, const char* p_provided_by);

/** Move a value to the providedBy field in a CivicAddress object
 * \public \memberof data_collection_model_civic_address_t
 *
 * @param civic_address The CivicAddress object to set the field in.
 * @param p_provided_by The value to move into the CivicAddress object.
 *
 * @return @a civic_address.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_provided_by_move(data_collection_model_civic_address_t *civic_address, char* p_provided_by);

/** lnode helper for generating ogs_list_t nodes's of type CivicAddress
 * \public \memberof data_collection_model_civic_address_t
 *
 * Creates a new data_collection_lnode_t object containing the @a civic_address object.
 * The @a civic_address will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param civic_address The CivicAddress object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a civic_address
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_civic_address_make_lnode(data_collection_model_civic_address_t *civic_address);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_CIVIC_ADDRESS_H_ */

