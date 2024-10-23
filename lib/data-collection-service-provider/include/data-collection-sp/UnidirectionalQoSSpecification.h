#ifndef _DATA_COLLECTION_UNIDIRECTIONAL_QO_S_SPECIFICATION_H_
#define _DATA_COLLECTION_UNIDIRECTIONAL_QO_S_SPECIFICATION_H_

/**********************************************************************************************************************************
 * UnidirectionalQoSSpecification - Public C interface to the UnidirectionalQoSSpecification object
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

/** A 3GPP UnidirectionalQoSSpecification object reference
 */
typedef struct data_collection_model_unidirectional_qo_s_specification_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_unidirectional_qo_s_specification_t;



/** Create a new UnidirectionalQoSSpecification
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 * @return a new UnidirectionalQoSSpecification object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_create();

/** Create a new copy of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 * Creates a new copy of the given @a other object
 * @param other The UnidirectionalQoSSpecification to copy.
 * @return a new UnidirectionalQoSSpecification object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_create_copy(const data_collection_model_unidirectional_qo_s_specification_t *other);

/** Create a new reference of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 * Creates a reference to the same underlying @a other object.
 * @param other The UnidirectionalQoSSpecification to create a new reference to.
 * @return a new UnidirectionalQoSSpecification object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_create_move(data_collection_model_unidirectional_qo_s_specification_t *other);

/** Copy the value of another UnidirectionalQoSSpecification into this object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 * Copies the value of @a other {{classname} object into @a unidirectional_qo_s_specification.
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to copy @a other into.
 * @param other The UnidirectionalQoSSpecification to copy the value from.
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_copy(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const data_collection_model_unidirectional_qo_s_specification_t *other);

/** Move the value of another UnidirectionalQoSSpecification into this object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 * Discards the current value of @a unidirectional_qo_s_specification and moves the value of @a other
 * into @a unidirectional_qo_s_specification. This will leave @a other as an empty reference.
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to move @a other into.
 * @param other The UnidirectionalQoSSpecification to move the value from.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, data_collection_model_unidirectional_qo_s_specification_t *other);

/** Delete a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 * Destroys the reference to the UnidirectionalQoSSpecification object and frees the value of UnidirectionalQoSSpecification if this is the last reference.
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_unidirectional_qo_s_specification_free(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/** Get a cJSON tree representation of a UnidirectionalQoSSpecification
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * Create a cJSON tree representation of the UnidirectionalQoSSpecification object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_unidirectional_qo_s_specification_toJSON(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, bool as_request);

/** Parse a cJSON tree into a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * Attempts to interpret a cJSON tree as a UnidirectionalQoSSpecification API request or response (dependent on @a as_request value). If successful
 * will return a new referenced UnidirectionalQoSSpecification object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new UnidirectionalQoSSpecification object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two UnidirectionalQoSSpecification objects to see if they are equivalent
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param unidirectional_qo_s_specification The first UnidirectionalQoSSpecification object to compare.
 * @param other_unidirectional_qo_s_specification The second UnidirectionalQoSSpecification object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_is_equal_to(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const data_collection_model_unidirectional_qo_s_specification_t *other_unidirectional_qo_s_specification);



/** Get the value of the maximumRequestedBitRate field of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return the value current set for the maximumRequestedBitRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_unidirectional_qo_s_specification_get_maximum_requested_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/** Set the value of the maximumRequestedBitRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_maximum_requested_bit_rate The value to copy into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_maximum_requested_bit_rate(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const char* p_maximum_requested_bit_rate);

/** Move a value to the maximumRequestedBitRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_maximum_requested_bit_rate The value to move into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_maximum_requested_bit_rate_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, char* p_maximum_requested_bit_rate);

/** Check if the minimumDesiredBitRate field of a UnidirectionalQoSSpecification object is set
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return `true` if the optional minimumDesiredBitRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_has_minimum_desired_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);


/** Get the value of the minimumDesiredBitRate field of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return the value current set for the minimumDesiredBitRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_unidirectional_qo_s_specification_get_minimum_desired_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/** Set the value of the minimumDesiredBitRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_minimum_desired_bit_rate The value to copy into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_minimum_desired_bit_rate(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const char* p_minimum_desired_bit_rate);

/** Move a value to the minimumDesiredBitRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_minimum_desired_bit_rate The value to move into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_minimum_desired_bit_rate_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, char* p_minimum_desired_bit_rate);


/** Get the value of the minimumRequestedBitRate field of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return the value current set for the minimumRequestedBitRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_unidirectional_qo_s_specification_get_minimum_requested_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/** Set the value of the minimumRequestedBitRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_minimum_requested_bit_rate The value to copy into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_minimum_requested_bit_rate(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const char* p_minimum_requested_bit_rate);

/** Move a value to the minimumRequestedBitRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_minimum_requested_bit_rate The value to move into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_minimum_requested_bit_rate_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, char* p_minimum_requested_bit_rate);

/** Check if the desiredPacketLatency field of a UnidirectionalQoSSpecification object is set
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return `true` if the optional desiredPacketLatency field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_has_desired_packet_latency(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);


/** Get the value of the desiredPacketLatency field of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return the value current set for the desiredPacketLatency field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_unidirectional_qo_s_specification_get_desired_packet_latency(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/** Set the value of the desiredPacketLatency field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_desired_packet_latency The value to copy into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_desired_packet_latency(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const int32_t p_desired_packet_latency);

/** Move a value to the desiredPacketLatency field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_desired_packet_latency The value to move into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_desired_packet_latency_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, int32_t p_desired_packet_latency);

/** Check if the desiredPacketLossRate field of a UnidirectionalQoSSpecification object is set
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return `true` if the optional desiredPacketLossRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_has_desired_packet_loss_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);


/** Get the value of the desiredPacketLossRate field of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return the value current set for the desiredPacketLossRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_unidirectional_qo_s_specification_get_desired_packet_loss_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/** Set the value of the desiredPacketLossRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_desired_packet_loss_rate The value to copy into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_desired_packet_loss_rate(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const int32_t p_desired_packet_loss_rate);

/** Move a value to the desiredPacketLossRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_desired_packet_loss_rate The value to move into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_desired_packet_loss_rate_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, int32_t p_desired_packet_loss_rate);

/** lnode helper for generating ogs_list_t nodes's of type UnidirectionalQoSSpecification
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * Creates a new data_collection_lnode_t object containing the @a unidirectional_qo_s_specification object.
 * The @a unidirectional_qo_s_specification will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a unidirectional_qo_s_specification
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_unidirectional_qo_s_specification_make_lnode(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UNIDIRECTIONAL_QO_S_SPECIFICATION_H_ */

