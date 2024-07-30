#ifndef _DATA_COLLECTION_FLOW_DIRECTION_H_
#define _DATA_COLLECTION_FLOW_DIRECTION_H_

/**********************************************************************************************************************************
 * FlowDirection - Public C interface to the FlowDirection object
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

#include "FlowDirection_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_flow_direction_s data_collection_model_flow_direction_t;

typedef enum {
    DCM_FLOW_DIRECTION_NO_VAL,
    DCM_FLOW_DIRECTION_VAL_DOWNLINK,
    DCM_FLOW_DIRECTION_VAL_UPLINK,
    DCM_FLOW_DIRECTION_VAL_BIDIRECTIONAL,
    DCM_FLOW_DIRECTION_VAL_UNSPECIFIED,
    DCM_FLOW_DIRECTION_OTHER
} data_collection_model_flow_direction_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_direction_t *data_collection_model_flow_direction_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_direction_t *data_collection_model_flow_direction_create_copy(const data_collection_model_flow_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_direction_t *data_collection_model_flow_direction_create_move(data_collection_model_flow_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_direction_t *data_collection_model_flow_direction_copy(data_collection_model_flow_direction_t *flow_direction, const data_collection_model_flow_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_direction_t *data_collection_model_flow_direction_move(data_collection_model_flow_direction_t *flow_direction, data_collection_model_flow_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_flow_direction_free(data_collection_model_flow_direction_t *flow_direction);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_flow_direction_toJSON(const data_collection_model_flow_direction_t *flow_direction, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_direction_t *data_collection_model_flow_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_direction_is_equal_to(const data_collection_model_flow_direction_t *flow_direction, const data_collection_model_flow_direction_t *other_flow_direction);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_direction_is_not_set(const data_collection_model_flow_direction_t *flow_direction);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_direction_is_non_standard(const data_collection_model_flow_direction_t *flow_direction);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_flow_direction_e data_collection_model_flow_direction_get_enum(const data_collection_model_flow_direction_t *flow_direction);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_flow_direction_get_string(const data_collection_model_flow_direction_t *flow_direction);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_direction_set_enum(data_collection_model_flow_direction_t *flow_direction, data_collection_model_flow_direction_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_flow_direction_set_string(data_collection_model_flow_direction_t *flow_direction, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type FlowDirection */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_flow_direction_make_lnode(data_collection_model_flow_direction_t *flow_direction);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_FLOW_DIRECTION_H_ */

