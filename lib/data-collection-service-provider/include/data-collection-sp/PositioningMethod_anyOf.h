#ifndef _DATA_COLLECTION_POSITIONING_METHOD_ANY_OF_H_
#define _DATA_COLLECTION_POSITIONING_METHOD_ANY_OF_H_

/**********************************************************************************************************************************
 * PositioningMethod_anyOf - Public C interface to the PositioningMethod_anyOf object
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

/** A 3GPP PositioningMethod_anyOf object reference
 */
typedef struct data_collection_model_positioning_method_any_of_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_positioning_method_any_of_t;


/** PositioningMethod_anyOf enumerated values */
typedef enum {
    DCM_POSITIONING_METHOD_ANY_OF_NO_VAL, /**< No value */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_CELLID, /**< CELLID */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_ECID, /**< ECID */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_OTDOA, /**< OTDOA */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_BAROMETRIC_PRESSURE, /**< BAROMETRIC_PRESSURE */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_WLAN, /**< WLAN */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_BLUETOOTH, /**< BLUETOOTH */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_MBS, /**< MBS */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_MOTION_SENSOR, /**< MOTION_SENSOR */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_DL_TDOA, /**< DL_TDOA */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_DL_AOD, /**< DL_AOD */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_MULTI_RTT, /**< MULTI-RTT */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_NR_ECID, /**< NR_ECID */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_UL_TDOA, /**< UL_TDOA */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_UL_AOA, /**< UL_AOA */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_NETWORK_SPECIFIC, /**< NETWORK_SPECIFIC */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_TDOA, /**< SL_TDOA */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_TOA, /**< SL_TOA */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_AO_A, /**< SL_AoA */
    DCM_POSITIONING_METHOD_ANY_OF_VAL_SL_RT /**< SL_RT */
} data_collection_model_positioning_method_any_of_e;


/** Create a new PositioningMethod_anyOf.
 * \public \memberof data_collection_model_positioning_method_any_of_t
 * @return a new PositioningMethod_anyOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_create();

/** Create a new PositioningMethod_anyOf reference.
 * \public \memberof data_collection_model_positioning_method_any_of_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The PositioningMethod_anyOf to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_create_ref(const data_collection_model_positioning_method_any_of_t *other);

/** Create a new copy of a PositioningMethod_anyOf object.
 * \public \memberof data_collection_model_positioning_method_any_of_t
 * Creates a new copy of the given @a other object
 * @param other The PositioningMethod_anyOf to copy.
 * @return a new PositioningMethod_anyOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_create_copy(const data_collection_model_positioning_method_any_of_t *other);

/** Create a new reference of a PositioningMethod_anyOf object
 * \public \memberof data_collection_model_positioning_method_any_of_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PositioningMethod_anyOf to create a new reference to.
 * @return a new PositioningMethod_anyOf object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_create_move(data_collection_model_positioning_method_any_of_t *other);

/** Copy the value of another PositioningMethod_anyOf into this object
 * \public \memberof data_collection_model_positioning_method_any_of_t
 * Copies the value of @a other {{classname} object into @a positioning_method_any_of.
 * @param positioning_method_any_of The PositioningMethod_anyOf object to copy @a other into.
 * @param other The PositioningMethod_anyOf to copy the value from.
 * @return @a positioning_method_any_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_copy(data_collection_model_positioning_method_any_of_t *positioning_method_any_of, const data_collection_model_positioning_method_any_of_t *other);

/** Move the value of another PositioningMethod_anyOf into this object
 * \public \memberof data_collection_model_positioning_method_any_of_t
 * Discards the current value of @a positioning_method_any_of and moves the value of @a other
 * into @a positioning_method_any_of. This will leave @a other as an empty reference.
 *
 * @param positioning_method_any_of The PositioningMethod_anyOf object to move @a other into.
 * @param other The PositioningMethod_anyOf to move the value from.
 *
 * @return @a positioning_method_any_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_move(data_collection_model_positioning_method_any_of_t *positioning_method_any_of, data_collection_model_positioning_method_any_of_t *other);

/** Delete a PositioningMethod_anyOf object
 * \public \memberof data_collection_model_positioning_method_any_of_t
 * Destroys the reference to the PositioningMethod_anyOf object and frees the value of PositioningMethod_anyOf if this is the last reference.
 *
 * @param positioning_method_any_of The PositioningMethod_anyOf to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_positioning_method_any_of_free(data_collection_model_positioning_method_any_of_t *positioning_method_any_of);

/** Get a cJSON tree representation of a PositioningMethod_anyOf
 * \public \memberof data_collection_model_positioning_method_any_of_t
 *
 * Create a cJSON tree representation of the PositioningMethod_anyOf object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param positioning_method_any_of The PositioningMethod_anyOf to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_positioning_method_any_of_toJSON(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of, bool as_request);

/** Parse a cJSON tree into a PositioningMethod_anyOf object
 * \public \memberof data_collection_model_positioning_method_any_of_t
 *
 * Attempts to interpret a cJSON tree as a PositioningMethod_anyOf API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PositioningMethod_anyOf object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PositioningMethod_anyOf object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_t *data_collection_model_positioning_method_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PositioningMethod_anyOf objects to see if they are equivalent
 * \public \memberof data_collection_model_positioning_method_any_of_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param positioning_method_any_of The first PositioningMethod_anyOf object to compare.
 * @param other_positioning_method_any_of The second PositioningMethod_anyOf object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_is_equal_to(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of, const data_collection_model_positioning_method_any_of_t *other_positioning_method_any_of);


/** Check if the PositioningMethod_anyOf enumeration object has a value set
 * \public \memberof data_collection_model_positioning_method_any_of_t
 *
 * @param positioning_method_any_of The PositioningMethod_anyOf enumeration object to check.
 * @return `true` if the enumeration object has no value set (i.e. is equivalent to `NULL`)
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_is_not_set(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of);

/** Get the enumeration value for a PositioningMethod_anyOf object
 * \public \memberof data_collection_model_positioning_method_any_of_t
 *
 * @param positioning_method_any_of The PositioningMethod_anyOf object to extract the enumeration value from.
 *
 * @return the data_collection_model_positioning_method_any_of_e value represented by the PositioningMethod_anyOf object.
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_any_of_e data_collection_model_positioning_method_any_of_get_enum(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of);

/** Get the string representation of the enumeration value for a PositioningMethod_anyOf object
 * \public \memberof data_collection_model_positioning_method_any_of_t 
 *
 * @param positioning_method_any_of The PositioningMethod_anyOf object to extract the enumeration value from.
 *
 * @return the API string for the enumeration or `NULL` if no value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_positioning_method_any_of_get_string(const data_collection_model_positioning_method_any_of_t *positioning_method_any_of);

/** Set the enumeration value for a PositioningMethod_anyOf object
 * \public \memberof data_collection_model_positioning_method_any_of_t
 *
 * @param positioning_method_any_of The PositioningMethod_anyOf object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_set_enum(data_collection_model_positioning_method_any_of_t *positioning_method_any_of, data_collection_model_positioning_method_any_of_e value);

/** Set the enumeration value as a string for a PositioningMethod_anyOf object
 * \public \memberof data_collection_model_positioning_method_any_of_t
 *
 * @param positioning_method_any_of The PositioningMethod_anyOf object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was recognised and set or `false` if the string did not represent a known enumeration value.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_any_of_set_string(data_collection_model_positioning_method_any_of_t *positioning_method_any_of, const char *value);


/** lnode helper for generating ogs_list_t nodes's of type PositioningMethod_anyOf
 * \public \memberof data_collection_model_positioning_method_any_of_t
 *
 * Creates a new data_collection_lnode_t object containing the @a positioning_method_any_of object.
 * The @a positioning_method_any_of will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param positioning_method_any_of The PositioningMethod_anyOf object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a positioning_method_any_of
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_positioning_method_any_of_make_lnode(data_collection_model_positioning_method_any_of_t *positioning_method_any_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POSITIONING_METHOD_ANY_OF_H_ */

