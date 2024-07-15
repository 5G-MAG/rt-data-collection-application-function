#ifndef _DATA_COLLECTION_POSITIONING_MODE_H_
#define _DATA_COLLECTION_POSITIONING_MODE_H_

/**********************************************************************************************************************************
 * PositioningMode - Public C interface to the PositioningMode object
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

#include "PositioningMode_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_positioning_mode_s data_collection_model_positioning_mode_t;

typedef enum {
    DCM_POSITIONING_MODE_NO_VAL,
    DCM_POSITIONING_MODE_VAL_UE_BASED,
    DCM_POSITIONING_MODE_VAL_UE_ASSISTED,
    DCM_POSITIONING_MODE_VAL_CONVENTIONAL,
    DCM_POSITIONING_MODE_OTHER
} data_collection_model_positioning_mode_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create_copy(const data_collection_model_positioning_mode_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create_move(data_collection_model_positioning_mode_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_copy(data_collection_model_positioning_mode_t *positioning_mode, const data_collection_model_positioning_mode_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_move(data_collection_model_positioning_mode_t *positioning_mode, data_collection_model_positioning_mode_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_positioning_mode_free(data_collection_model_positioning_mode_t *positioning_mode);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_positioning_mode_toJSON(const data_collection_model_positioning_mode_t *positioning_mode, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_is_not_set(const data_collection_model_positioning_mode_t *positioning_mode);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_is_non_standard(const data_collection_model_positioning_mode_t *positioning_mode);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_e data_collection_model_positioning_mode_get_enum(const data_collection_model_positioning_mode_t *positioning_mode);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_positioning_mode_get_string(const data_collection_model_positioning_mode_t *positioning_mode);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_set_enum(data_collection_model_positioning_mode_t *positioning_mode, data_collection_model_positioning_mode_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_set_string(data_collection_model_positioning_mode_t *positioning_mode, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type PositioningMode */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_positioning_mode_make_lnode(data_collection_model_positioning_mode_t *positioning_mode);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_POSITIONING_MODE_H_ */

