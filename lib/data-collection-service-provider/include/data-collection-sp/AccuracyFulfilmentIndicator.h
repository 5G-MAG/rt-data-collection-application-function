#ifndef _DATA_COLLECTION_ACCURACY_FULFILMENT_INDICATOR_H_
#define _DATA_COLLECTION_ACCURACY_FULFILMENT_INDICATOR_H_

/**********************************************************************************************************************************
 * AccuracyFulfilmentIndicator - Public C interface to the AccuracyFulfilmentIndicator object
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

#include "AccuracyFulfilmentIndicator_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_accuracy_fulfilment_indicator_s data_collection_model_accuracy_fulfilment_indicator_t;

typedef enum {
    DCM_ACCURACY_FULFILMENT_INDICATOR_NO_VAL,
    DCM_ACCURACY_FULFILMENT_INDICATOR_VAL_REQUESTED_ACCURACY_FULFILLED,
    DCM_ACCURACY_FULFILMENT_INDICATOR_VAL_REQUESTED_ACCURACY_NOT_FULFILLED,
    DCM_ACCURACY_FULFILMENT_INDICATOR_OTHER
} data_collection_model_accuracy_fulfilment_indicator_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_create_copy(const data_collection_model_accuracy_fulfilment_indicator_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_create_move(data_collection_model_accuracy_fulfilment_indicator_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_copy(data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator, const data_collection_model_accuracy_fulfilment_indicator_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_move(data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator, data_collection_model_accuracy_fulfilment_indicator_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_accuracy_fulfilment_indicator_free(data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_accuracy_fulfilment_indicator_toJSON(const data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_accuracy_fulfilment_indicator_is_not_set(const data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_accuracy_fulfilment_indicator_is_non_standard(const data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_e data_collection_model_accuracy_fulfilment_indicator_get_enum(const data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_accuracy_fulfilment_indicator_get_string(const data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_accuracy_fulfilment_indicator_set_enum(data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator, data_collection_model_accuracy_fulfilment_indicator_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_accuracy_fulfilment_indicator_set_string(data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type AccuracyFulfilmentIndicator */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_accuracy_fulfilment_indicator_make_lnode(data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ACCURACY_FULFILMENT_INDICATOR_H_ */

