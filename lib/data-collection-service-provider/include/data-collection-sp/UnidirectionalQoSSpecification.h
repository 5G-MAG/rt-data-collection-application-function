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

#include "PduSetQosPara.h"

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



/** Create a new UnidirectionalQoSSpecification.
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 * @return a new UnidirectionalQoSSpecification object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_create();

/** Create a new UnidirectionalQoSSpecification reference.
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The UnidirectionalQoSSpecification to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_create_ref(const data_collection_model_unidirectional_qo_s_specification_t *other);

/** Create a new copy of a UnidirectionalQoSSpecification object.
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


/** Check if the maximumBitRate field of a UnidirectionalQoSSpecification object is set
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return `true` if the optional maximumBitRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_has_maximum_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);


/** Get the value of the maximumBitRate field of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return the value current set for the maximumBitRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_unidirectional_qo_s_specification_get_maximum_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/** Set the value of the maximumBitRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_maximum_bit_rate The value to copy into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_maximum_bit_rate(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const char* p_maximum_bit_rate);

/** Move a value to the maximumBitRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_maximum_bit_rate The value to move into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_maximum_bit_rate_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, char* p_maximum_bit_rate);

/** Check if the maximumAuthorisedBitRate field of a UnidirectionalQoSSpecification object is set
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return `true` if the optional maximumAuthorisedBitRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_has_maximum_authorised_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);


/** Get the value of the maximumAuthorisedBitRate field of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return the value current set for the maximumAuthorisedBitRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_unidirectional_qo_s_specification_get_maximum_authorised_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/** Set the value of the maximumAuthorisedBitRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_maximum_authorised_bit_rate The value to copy into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_maximum_authorised_bit_rate(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const char* p_maximum_authorised_bit_rate);

/** Move a value to the maximumAuthorisedBitRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_maximum_authorised_bit_rate The value to move into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_maximum_authorised_bit_rate_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, char* p_maximum_authorised_bit_rate);

/** Check if the minimumPacketLossRate field of a UnidirectionalQoSSpecification object is set
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return `true` if the optional minimumPacketLossRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_has_minimum_packet_loss_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);


/** Get the value of the minimumPacketLossRate field of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return the value current set for the minimumPacketLossRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_unidirectional_qo_s_specification_get_minimum_packet_loss_rate(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/** Set the value of the minimumPacketLossRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_minimum_packet_loss_rate The value to copy into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_minimum_packet_loss_rate(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const int32_t p_minimum_packet_loss_rate);

/** Move a value to the minimumPacketLossRate field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_minimum_packet_loss_rate The value to move into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_minimum_packet_loss_rate_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, int32_t p_minimum_packet_loss_rate);

/** Check if the pduSetQosLimits field of a UnidirectionalQoSSpecification object is set
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return `true` if the optional pduSetQosLimits field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_has_pdu_set_qos_limits(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);


/** Get the value of the pduSetQosLimits field of a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to examine.
 *
 * @return the value current set for the pduSetQosLimits field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_qos_para_t* data_collection_model_unidirectional_qo_s_specification_get_pdu_set_qos_limits(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification);

/** Set the value of the pduSetQosLimits field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_pdu_set_qos_limits The value to copy into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_pdu_set_qos_limits(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const data_collection_model_pdu_set_qos_para_t* p_pdu_set_qos_limits);

/** Move a value to the pduSetQosLimits field in a UnidirectionalQoSSpecification object
 * \public \memberof data_collection_model_unidirectional_qo_s_specification_t
 *
 * @param unidirectional_qo_s_specification The UnidirectionalQoSSpecification object to set the field in.
 * @param p_pdu_set_qos_limits The value to move into the UnidirectionalQoSSpecification object.
 *
 * @return @a unidirectional_qo_s_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_pdu_set_qos_limits_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, data_collection_model_pdu_set_qos_para_t* p_pdu_set_qos_limits);

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

