#ifndef _DATA_COLLECTION_CLIENT_QOS_SPECIFICATION_H_
#define _DATA_COLLECTION_CLIENT_QOS_SPECIFICATION_H_

/**********************************************************************************************************************************
 * ClientQosSpecification - Public C interface to the ClientQosSpecification object
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

#include "UnidirectionalBitRateSpecification.h"
#include "PduSetQosPara.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ClientQosSpecification object reference
 */
typedef struct data_collection_model_client_qos_specification_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_client_qos_specification_t;



/** Create a new ClientQosSpecification.
 * \public \memberof data_collection_model_client_qos_specification_t
 * @return a new ClientQosSpecification object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_create();

/** Create a new ClientQosSpecification reference.
 * \public \memberof data_collection_model_client_qos_specification_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The ClientQosSpecification to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_create_ref(const data_collection_model_client_qos_specification_t *other);

/** Create a new copy of a ClientQosSpecification object.
 * \public \memberof data_collection_model_client_qos_specification_t
 * Creates a new copy of the given @a other object
 * @param other The ClientQosSpecification to copy.
 * @return a new ClientQosSpecification object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_create_copy(const data_collection_model_client_qos_specification_t *other);

/** Create a new reference of a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ClientQosSpecification to create a new reference to.
 * @return a new ClientQosSpecification object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_create_move(data_collection_model_client_qos_specification_t *other);

/** Copy the value of another ClientQosSpecification into this object
 * \public \memberof data_collection_model_client_qos_specification_t
 * Copies the value of @a other {{classname} object into @a client_qos_specification.
 * @param client_qos_specification The ClientQosSpecification object to copy @a other into.
 * @param other The ClientQosSpecification to copy the value from.
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_copy(data_collection_model_client_qos_specification_t *client_qos_specification, const data_collection_model_client_qos_specification_t *other);

/** Move the value of another ClientQosSpecification into this object
 * \public \memberof data_collection_model_client_qos_specification_t
 * Discards the current value of @a client_qos_specification and moves the value of @a other
 * into @a client_qos_specification. This will leave @a other as an empty reference.
 *
 * @param client_qos_specification The ClientQosSpecification object to move @a other into.
 * @param other The ClientQosSpecification to move the value from.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_move(data_collection_model_client_qos_specification_t *client_qos_specification, data_collection_model_client_qos_specification_t *other);

/** Delete a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 * Destroys the reference to the ClientQosSpecification object and frees the value of ClientQosSpecification if this is the last reference.
 *
 * @param client_qos_specification The ClientQosSpecification to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_client_qos_specification_free(data_collection_model_client_qos_specification_t *client_qos_specification);

/** Get a cJSON tree representation of a ClientQosSpecification
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * Create a cJSON tree representation of the ClientQosSpecification object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param client_qos_specification The ClientQosSpecification to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_client_qos_specification_toJSON(const data_collection_model_client_qos_specification_t *client_qos_specification, bool as_request);

/** Parse a cJSON tree into a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * Attempts to interpret a cJSON tree as a ClientQosSpecification API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ClientQosSpecification object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ClientQosSpecification object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ClientQosSpecification objects to see if they are equivalent
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param client_qos_specification The first ClientQosSpecification object to compare.
 * @param other_client_qos_specification The second ClientQosSpecification object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_client_qos_specification_is_equal_to(const data_collection_model_client_qos_specification_t *client_qos_specification, const data_collection_model_client_qos_specification_t *other_client_qos_specification);



/** Get the value of the downlinkBitRates field of a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to examine.
 *
 * @return the value current set for the downlinkBitRates field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_bit_rate_specification_t* data_collection_model_client_qos_specification_get_downlink_bit_rates(const data_collection_model_client_qos_specification_t *client_qos_specification);

/** Set the value of the downlinkBitRates field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_downlink_bit_rates The value to copy into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_downlink_bit_rates(data_collection_model_client_qos_specification_t *client_qos_specification, const data_collection_model_unidirectional_bit_rate_specification_t* p_downlink_bit_rates);

/** Move a value to the downlinkBitRates field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_downlink_bit_rates The value to move into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_downlink_bit_rates_move(data_collection_model_client_qos_specification_t *client_qos_specification, data_collection_model_unidirectional_bit_rate_specification_t* p_downlink_bit_rates);


/** Get the value of the uplinkBitRates field of a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to examine.
 *
 * @return the value current set for the uplinkBitRates field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_unidirectional_bit_rate_specification_t* data_collection_model_client_qos_specification_get_uplink_bit_rates(const data_collection_model_client_qos_specification_t *client_qos_specification);

/** Set the value of the uplinkBitRates field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_uplink_bit_rates The value to copy into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_uplink_bit_rates(data_collection_model_client_qos_specification_t *client_qos_specification, const data_collection_model_unidirectional_bit_rate_specification_t* p_uplink_bit_rates);

/** Move a value to the uplinkBitRates field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_uplink_bit_rates The value to move into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_uplink_bit_rates_move(data_collection_model_client_qos_specification_t *client_qos_specification, data_collection_model_unidirectional_bit_rate_specification_t* p_uplink_bit_rates);

/** Check if the desiredPacketLatency field of a ClientQosSpecification object is set
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to examine.
 *
 * @return `true` if the optional desiredPacketLatency field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_client_qos_specification_has_desired_packet_latency(const data_collection_model_client_qos_specification_t *client_qos_specification);


/** Get the value of the desiredPacketLatency field of a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to examine.
 *
 * @return the value current set for the desiredPacketLatency field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_client_qos_specification_get_desired_packet_latency(const data_collection_model_client_qos_specification_t *client_qos_specification);

/** Set the value of the desiredPacketLatency field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_desired_packet_latency The value to copy into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_packet_latency(data_collection_model_client_qos_specification_t *client_qos_specification, const int32_t p_desired_packet_latency);

/** Move a value to the desiredPacketLatency field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_desired_packet_latency The value to move into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_packet_latency_move(data_collection_model_client_qos_specification_t *client_qos_specification, int32_t p_desired_packet_latency);

/** Check if the desiredPacketLossRate field of a ClientQosSpecification object is set
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to examine.
 *
 * @return `true` if the optional desiredPacketLossRate field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_client_qos_specification_has_desired_packet_loss_rate(const data_collection_model_client_qos_specification_t *client_qos_specification);


/** Get the value of the desiredPacketLossRate field of a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to examine.
 *
 * @return the value current set for the desiredPacketLossRate field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_client_qos_specification_get_desired_packet_loss_rate(const data_collection_model_client_qos_specification_t *client_qos_specification);

/** Set the value of the desiredPacketLossRate field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_desired_packet_loss_rate The value to copy into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_packet_loss_rate(data_collection_model_client_qos_specification_t *client_qos_specification, const int32_t p_desired_packet_loss_rate);

/** Move a value to the desiredPacketLossRate field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_desired_packet_loss_rate The value to move into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_packet_loss_rate_move(data_collection_model_client_qos_specification_t *client_qos_specification, int32_t p_desired_packet_loss_rate);

/** Check if the desiredDownlinkPduSetQosParameters field of a ClientQosSpecification object is set
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to examine.
 *
 * @return `true` if the optional desiredDownlinkPduSetQosParameters field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_client_qos_specification_has_desired_downlink_pdu_set_qos_parameters(const data_collection_model_client_qos_specification_t *client_qos_specification);


/** Get the value of the desiredDownlinkPduSetQosParameters field of a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to examine.
 *
 * @return the value current set for the desiredDownlinkPduSetQosParameters field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_qos_para_t* data_collection_model_client_qos_specification_get_desired_downlink_pdu_set_qos_parameters(const data_collection_model_client_qos_specification_t *client_qos_specification);

/** Set the value of the desiredDownlinkPduSetQosParameters field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_desired_downlink_pdu_set_qos_parameters The value to copy into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_downlink_pdu_set_qos_parameters(data_collection_model_client_qos_specification_t *client_qos_specification, const data_collection_model_pdu_set_qos_para_t* p_desired_downlink_pdu_set_qos_parameters);

/** Move a value to the desiredDownlinkPduSetQosParameters field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_desired_downlink_pdu_set_qos_parameters The value to move into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_downlink_pdu_set_qos_parameters_move(data_collection_model_client_qos_specification_t *client_qos_specification, data_collection_model_pdu_set_qos_para_t* p_desired_downlink_pdu_set_qos_parameters);

/** Check if the desiredUplinkPduSetQosParameters field of a ClientQosSpecification object is set
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to examine.
 *
 * @return `true` if the optional desiredUplinkPduSetQosParameters field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_client_qos_specification_has_desired_uplink_pdu_set_qos_parameters(const data_collection_model_client_qos_specification_t *client_qos_specification);


/** Get the value of the desiredUplinkPduSetQosParameters field of a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to examine.
 *
 * @return the value current set for the desiredUplinkPduSetQosParameters field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_qos_para_t* data_collection_model_client_qos_specification_get_desired_uplink_pdu_set_qos_parameters(const data_collection_model_client_qos_specification_t *client_qos_specification);

/** Set the value of the desiredUplinkPduSetQosParameters field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_desired_uplink_pdu_set_qos_parameters The value to copy into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_uplink_pdu_set_qos_parameters(data_collection_model_client_qos_specification_t *client_qos_specification, const data_collection_model_pdu_set_qos_para_t* p_desired_uplink_pdu_set_qos_parameters);

/** Move a value to the desiredUplinkPduSetQosParameters field in a ClientQosSpecification object
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * @param client_qos_specification The ClientQosSpecification object to set the field in.
 * @param p_desired_uplink_pdu_set_qos_parameters The value to move into the ClientQosSpecification object.
 *
 * @return @a client_qos_specification.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_client_qos_specification_t *data_collection_model_client_qos_specification_set_desired_uplink_pdu_set_qos_parameters_move(data_collection_model_client_qos_specification_t *client_qos_specification, data_collection_model_pdu_set_qos_para_t* p_desired_uplink_pdu_set_qos_parameters);

/** lnode helper for generating ogs_list_t nodes's of type ClientQosSpecification
 * \public \memberof data_collection_model_client_qos_specification_t
 *
 * Creates a new data_collection_lnode_t object containing the @a client_qos_specification object.
 * The @a client_qos_specification will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param client_qos_specification The ClientQosSpecification object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a client_qos_specification
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_client_qos_specification_make_lnode(data_collection_model_client_qos_specification_t *client_qos_specification);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_CLIENT_QOS_SPECIFICATION_H_ */

