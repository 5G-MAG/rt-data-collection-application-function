#ifndef _DATA_COLLECTION_MINOR_LOCATION_QO_S_H_
#define _DATA_COLLECTION_MINOR_LOCATION_QO_S_H_

/**********************************************************************************************************************************
 * MinorLocationQoS - Public C interface to the MinorLocationQoS object
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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_minor_location_qo_s_s data_collection_model_minor_location_qo_s_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_create_copy(const data_collection_model_minor_location_qo_s_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_create_move(data_collection_model_minor_location_qo_s_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_copy(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, const data_collection_model_minor_location_qo_s_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_move(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, data_collection_model_minor_location_qo_s_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_minor_location_qo_s_free(data_collection_model_minor_location_qo_s_t *minor_location_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_minor_location_qo_s_toJSON(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_minor_location_qo_s_is_equal_to(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s, const data_collection_model_minor_location_qo_s_t *other_minor_location_qo_s);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_minor_location_qo_s_has_h_accuracy(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_minor_location_qo_s_get_h_accuracy(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_h_accuracy(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, const float p_h_accuracy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_h_accuracy_move(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, float p_h_accuracy);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_minor_location_qo_s_has_v_accuracy(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_minor_location_qo_s_get_v_accuracy(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_v_accuracy(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, const float p_v_accuracy);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_v_accuracy_move(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, float p_v_accuracy);

/* lnode helper for generating ogs_list_t nodes's of type MinorLocationQoS */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_minor_location_qo_s_make_lnode(data_collection_model_minor_location_qo_s_t *minor_location_qo_s);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MINOR_LOCATION_QO_S_H_ */

