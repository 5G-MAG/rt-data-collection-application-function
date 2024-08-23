#ifndef _DATA_COLLECTION_POSITIONING_METHOD_AND_USAGE_H_
#define _DATA_COLLECTION_POSITIONING_METHOD_AND_USAGE_H_

/**********************************************************************************************************************************
 * PositioningMethodAndUsage - Public C interface to the PositioningMethodAndUsage object
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

#include "Usage.h"
#include "PositioningMethod.h"
#include "PositioningMode.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_positioning_method_and_usage_s data_collection_model_positioning_method_and_usage_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create_copy(const data_collection_model_positioning_method_and_usage_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create_move(data_collection_model_positioning_method_and_usage_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_copy(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_positioning_method_and_usage_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, data_collection_model_positioning_method_and_usage_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_positioning_method_and_usage_free(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_positioning_method_and_usage_toJSON(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_and_usage_is_equal_to(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_positioning_method_and_usage_t *other_positioning_method_and_usage);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_positioning_method_t* data_collection_model_positioning_method_and_usage_get_method(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_positioning_method_t* p_method);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, data_collection_model_positioning_method_t* p_method);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_positioning_mode_t* data_collection_model_positioning_method_and_usage_get_mode(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_mode(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_positioning_mode_t* p_mode);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_mode_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, data_collection_model_positioning_mode_t* p_mode);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_usage_t* data_collection_model_positioning_method_and_usage_get_usage(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_usage(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_usage_t* p_usage);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_usage_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, data_collection_model_usage_t* p_usage);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_and_usage_has_method_code(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_positioning_method_and_usage_get_method_code(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_code(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const int32_t p_method_code);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_code_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, int32_t p_method_code);

/* lnode helper for generating ogs_list_t nodes's of type PositioningMethodAndUsage */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_positioning_method_and_usage_make_lnode(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POSITIONING_METHOD_AND_USAGE_H_ */

