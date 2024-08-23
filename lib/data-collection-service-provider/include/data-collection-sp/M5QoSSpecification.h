#ifndef _DATA_COLLECTION_M5_QO_S_SPECIFICATION_H_
#define _DATA_COLLECTION_M5_QO_S_SPECIFICATION_H_

/**********************************************************************************************************************************
 * M5QoSSpecification - Public C interface to the M5QoSSpecification object
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

#include "M5BitRateSpecification.h"
#include "PduSetQosPara.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_m5_qo_s_specification_s data_collection_model_m5_qo_s_specification_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_create_copy(const data_collection_model_m5_qo_s_specification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_create_move(data_collection_model_m5_qo_s_specification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_copy(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, const data_collection_model_m5_qo_s_specification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_move(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, data_collection_model_m5_qo_s_specification_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_m5_qo_s_specification_free(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_m5_qo_s_specification_toJSON(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_m5_qo_s_specification_is_equal_to(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, const data_collection_model_m5_qo_s_specification_t *other_m5_qo_s_specification);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_m5_bit_rate_specification_t* data_collection_model_m5_qo_s_specification_get_downlink_bit_rates(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_downlink_bit_rates(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, const data_collection_model_m5_bit_rate_specification_t* p_downlink_bit_rates);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_downlink_bit_rates_move(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, data_collection_model_m5_bit_rate_specification_t* p_downlink_bit_rates);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_m5_bit_rate_specification_t* data_collection_model_m5_qo_s_specification_get_uplink_bit_rates(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_uplink_bit_rates(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, const data_collection_model_m5_bit_rate_specification_t* p_uplink_bit_rates);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_uplink_bit_rates_move(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, data_collection_model_m5_bit_rate_specification_t* p_uplink_bit_rates);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_m5_qo_s_specification_has_desired_packet_latency(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_m5_qo_s_specification_get_desired_packet_latency(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_latency(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, const int32_t p_desired_packet_latency);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_latency_move(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, int32_t p_desired_packet_latency);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_m5_qo_s_specification_has_desired_packet_loss_rate(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_m5_qo_s_specification_get_desired_packet_loss_rate(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_loss_rate(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, const int32_t p_desired_packet_loss_rate);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_packet_loss_rate_move(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, int32_t p_desired_packet_loss_rate);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_m5_qo_s_specification_has_desired_downlink_pdu_set_qos_parameters(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_qos_para_t* data_collection_model_m5_qo_s_specification_get_desired_downlink_pdu_set_qos_parameters(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_downlink_pdu_set_qos_parameters(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, const data_collection_model_pdu_set_qos_para_t* p_desired_downlink_pdu_set_qos_parameters);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_downlink_pdu_set_qos_parameters_move(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, data_collection_model_pdu_set_qos_para_t* p_desired_downlink_pdu_set_qos_parameters);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_m5_qo_s_specification_has_desired_uplink_pdu_set_qos_parameters(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_pdu_set_qos_para_t* data_collection_model_m5_qo_s_specification_get_desired_uplink_pdu_set_qos_parameters(const data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_uplink_pdu_set_qos_parameters(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, const data_collection_model_pdu_set_qos_para_t* p_desired_uplink_pdu_set_qos_parameters);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_m5_qo_s_specification_t *data_collection_model_m5_qo_s_specification_set_desired_uplink_pdu_set_qos_parameters_move(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification, data_collection_model_pdu_set_qos_para_t* p_desired_uplink_pdu_set_qos_parameters);

/* lnode helper for generating ogs_list_t nodes's of type M5QoSSpecification */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_m5_qo_s_specification_make_lnode(data_collection_model_m5_qo_s_specification_t *m5_qo_s_specification);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_M5_QO_S_SPECIFICATION_H_ */

