#ifndef _DATA_COLLECTION_NWDAF_EVENT_H_
#define _DATA_COLLECTION_NWDAF_EVENT_H_

/**********************************************************************************************************************************
 * NwdafEvent - Public C interface to the NwdafEvent object
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

#include "NwdafEvent_anyOf.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP NwdafEvent object reference
 */
typedef struct data_collection_model_nwdaf_event_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_nwdaf_event_t;


/** NwdafEvent enumerated values */
typedef enum {
    DCM_NWDAF_EVENT_NO_VAL, /**< No value */
    DCM_NWDAF_EVENT_VAL_SLICE_LOAD_LEVEL, /**< SLICE_LOAD_LEVEL */
    DCM_NWDAF_EVENT_VAL_NETWORK_PERFORMANCE, /**< NETWORK_PERFORMANCE */
    DCM_NWDAF_EVENT_VAL_NF_LOAD, /**< NF_LOAD */
    DCM_NWDAF_EVENT_VAL_SERVICE_EXPERIENCE, /**< SERVICE_EXPERIENCE */
    DCM_NWDAF_EVENT_VAL_UE_MOBILITY, /**< UE_MOBILITY */
    DCM_NWDAF_EVENT_VAL_UE_COMMUNICATION, /**< UE_COMMUNICATION */
    DCM_NWDAF_EVENT_VAL_QOS_SUSTAINABILITY, /**< QOS_SUSTAINABILITY */
    DCM_NWDAF_EVENT_VAL_ABNORMAL_BEHAVIOUR, /**< ABNORMAL_BEHAVIOUR */
    DCM_NWDAF_EVENT_VAL_USER_DATA_CONGESTION, /**< USER_DATA_CONGESTION */
    DCM_NWDAF_EVENT_VAL_NSI_LOAD_LEVEL, /**< NSI_LOAD_LEVEL */
    DCM_NWDAF_EVENT_VAL_DN_PERFORMANCE, /**< DN_PERFORMANCE */
    DCM_NWDAF_EVENT_VAL_DISPERSION, /**< DISPERSION */
    DCM_NWDAF_EVENT_VAL_RED_TRANS_EXP, /**< RED_TRANS_EXP */
    DCM_NWDAF_EVENT_VAL_WLAN_PERFORMANCE, /**< WLAN_PERFORMANCE */
    DCM_NWDAF_EVENT_VAL_SM_CONGESTION, /**< SM_CONGESTION */
    DCM_NWDAF_EVENT_VAL_PFD_DETERMINATION, /**< PFD_DETERMINATION */
    DCM_NWDAF_EVENT_VAL_PDU_SESSION_TRAFFIC, /**< PDU_SESSION_TRAFFIC */
    DCM_NWDAF_EVENT_VAL_E2_E_DATA_VOL_TRANS_TIME, /**< E2E_DATA_VOL_TRANS_TIME */
    DCM_NWDAF_EVENT_VAL_MOVEMENT_BEHAVIOUR, /**< MOVEMENT_BEHAVIOUR */
    DCM_NWDAF_EVENT_VAL_NUM_OF_UE, /**< NUM_OF_UE */
    DCM_NWDAF_EVENT_VAL_MOV_UE_RATIO, /**< MOV_UE_RATIO */
    DCM_NWDAF_EVENT_VAL_AVR_SPEED, /**< AVR_SPEED */
    DCM_NWDAF_EVENT_VAL_SPEED_THRESHOLD, /**< SPEED_THRESHOLD */
    DCM_NWDAF_EVENT_VAL_MOV_UE_DIRECTION, /**< MOV_UE_DIRECTION */
    DCM_NWDAF_EVENT_VAL_LOC_ACCURACY, /**< LOC_ACCURACY */
    DCM_NWDAF_EVENT_VAL_RELATIVE_PROXIMITY, /**< RELATIVE_PROXIMITY */
    DCM_NWDAF_EVENT_OTHER  /**< Custom value (future expansion) */
} data_collection_model_nwdaf_event_e;


/** Create a new NwdafEvent
 * \public \memberof data_collection_model_nwdaf_event_t
 * @return a new NwdafEvent object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_create();

/** Create a new copy of a NwdafEvent object
 * \public \memberof data_collection_model_nwdaf_event_t
 * Creates a new copy of the given @a other object
 * @param other The NwdafEvent to copy.
 * @return a new NwdafEvent object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_create_copy(const data_collection_model_nwdaf_event_t *other);

/** Create a new reference of a NwdafEvent object
 * \public \memberof data_collection_model_nwdaf_event_t
 * Creates a reference to the same underlying @a other object.
 * @param other The NwdafEvent to create a new reference to.
 * @return a new NwdafEvent object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_create_move(data_collection_model_nwdaf_event_t *other);

/** Copy the value of another NwdafEvent into this object
 * \public \memberof data_collection_model_nwdaf_event_t
 * Copies the value of @a other {{classname} object into @a nwdaf_event.
 * @param nwdaf_event The NwdafEvent object to copy @a other into.
 * @param other The NwdafEvent to copy the value from.
 * @return @a nwdaf_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_copy(data_collection_model_nwdaf_event_t *nwdaf_event, const data_collection_model_nwdaf_event_t *other);

/** Move the value of another NwdafEvent into this object
 * \public \memberof data_collection_model_nwdaf_event_t
 * Discards the current value of @a nwdaf_event and moves the value of @a other
 * into @a nwdaf_event. This will leave @a other as an empty reference.
 *
 * @param nwdaf_event The NwdafEvent object to move @a other into.
 * @param other The NwdafEvent to move the value from.
 *
 * @return @a nwdaf_event.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_move(data_collection_model_nwdaf_event_t *nwdaf_event, data_collection_model_nwdaf_event_t *other);

/** Delete a NwdafEvent object
 * \public \memberof data_collection_model_nwdaf_event_t
 * Destroys the reference to the NwdafEvent object and frees the value of NwdafEvent if this is the last reference.
 *
 * @param nwdaf_event The NwdafEvent to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_nwdaf_event_free(data_collection_model_nwdaf_event_t *nwdaf_event);

/** Get a cJSON tree representation of a NwdafEvent
 * \public \memberof data_collection_model_nwdaf_event_t
 *
 * Create a cJSON tree representation of the NwdafEvent object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param nwdaf_event The NwdafEvent to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_nwdaf_event_toJSON(const data_collection_model_nwdaf_event_t *nwdaf_event, bool as_request);

/** Parse a cJSON tree into a NwdafEvent object
 * \public \memberof data_collection_model_nwdaf_event_t
 *
 * Attempts to interpret a cJSON tree as a NwdafEvent API request or response (dependent on @a as_request value). If successful
 * will return a new referenced NwdafEvent object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new NwdafEvent object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nwdaf_event_t *data_collection_model_nwdaf_event_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two NwdafEvent objects to see if they are equivalent
 * \public \memberof data_collection_model_nwdaf_event_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param nwdaf_event The first NwdafEvent object to compare.
 * @param other_nwdaf_event The second NwdafEvent object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_is_equal_to(const data_collection_model_nwdaf_event_t *nwdaf_event, const data_collection_model_nwdaf_event_t *other_nwdaf_event);


/** Check if the NwdafEvent enumeration object has a value set
 * \public \memberof data_collection_model_nwdaf_event_t
 *
 * @param nwdaf_event The NwdafEvent enumeration object to check.
 * @return `true` if the enumeration object has no value set (i.e. is equivalent to `NULL`)
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_is_not_set(const data_collection_model_nwdaf_event_t *nwdaf_event);

/** Check if the NwdafEvent enumeration object has a custom value set
 * \public \memberof data_collection_model_nwdaf_event_t
 *
 * @param nwdaf_event The NwdafEvent enumeration object to check.
 * @return `true` if the enumeration object has an unknown string value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_is_non_standard(const data_collection_model_nwdaf_event_t *nwdaf_event);

/** Get the enumeration value for a NwdafEvent object
 * \public \memberof data_collection_model_nwdaf_event_t
 *
 * @param nwdaf_event The NwdafEvent object to extract the enumeration value from.
 *
 * @return the data_collection_model_nwdaf_event_e value represented by the NwdafEvent object.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nwdaf_event_e data_collection_model_nwdaf_event_get_enum(const data_collection_model_nwdaf_event_t *nwdaf_event);

/** Get the string representation of the enumeration value for a NwdafEvent object
 * \public \memberof data_collection_model_nwdaf_event_t
 *
 * @param nwdaf_event The NwdafEvent object to extract the enumeration value from.
 *
 * @return the API string for the enumeration or `NULL` if no value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_nwdaf_event_get_string(const data_collection_model_nwdaf_event_t *nwdaf_event);

/** Set the enumeration value for a NwdafEvent object
 * \public \memberof data_collection_model_nwdaf_event_t
 *
 * @param nwdaf_event The NwdafEvent object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_set_enum(data_collection_model_nwdaf_event_t *nwdaf_event, data_collection_model_nwdaf_event_e value);

/** Set the enumeration value as a string for a NwdafEvent object
 * \public \memberof data_collection_model_nwdaf_event_t
 *
 * Sets the enumeration value from the string given. If the string is a non-standard, custom value then the
 * data_collection_model_nwdaf_event_get_enum
 * function will return DCM_NWDAF_EVENT_OTHER
 * while this value is set to indicate that this is a custom value.
 *
 * @param nwdaf_event The NwdafEvent object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` to indicate that the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nwdaf_event_set_string(data_collection_model_nwdaf_event_t *nwdaf_event, const char *value);


/** lnode helper for generating ogs_list_t nodes's of type NwdafEvent
 * \public \memberof data_collection_model_nwdaf_event_t
 *
 * Creates a new data_collection_lnode_t object containing the @a nwdaf_event object.
 * The @a nwdaf_event will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param nwdaf_event The NwdafEvent object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a nwdaf_event
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_nwdaf_event_make_lnode(data_collection_model_nwdaf_event_t *nwdaf_event);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NWDAF_EVENT_H_ */

