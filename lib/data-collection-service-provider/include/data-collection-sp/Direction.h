#ifndef _DATA_COLLECTION_DIRECTION_H_
#define _DATA_COLLECTION_DIRECTION_H_

/**********************************************************************************************************************************
 * Direction - Public C interface to the Direction object
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

#include "Direction_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_direction_s data_collection_model_direction_t;

typedef enum {
    DCM_DIRECTION_NO_VAL,
    DCM_DIRECTION_VAL_NORTH,
    DCM_DIRECTION_VAL_SOUTH,
    DCM_DIRECTION_VAL_EAST,
    DCM_DIRECTION_VAL_WEST,
    DCM_DIRECTION_VAL_NORTHWEST,
    DCM_DIRECTION_VAL_NORTHEAST,
    DCM_DIRECTION_VAL_SOUTHWEST,
    DCM_DIRECTION_VAL_SOUTHEAST,
    DCM_DIRECTION_OTHER
} data_collection_model_direction_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_create_copy(const data_collection_model_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_create_move(data_collection_model_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_copy(data_collection_model_direction_t *direction, const data_collection_model_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_move(data_collection_model_direction_t *direction, data_collection_model_direction_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_direction_free(data_collection_model_direction_t *direction);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_direction_toJSON(const data_collection_model_direction_t *direction, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_t *data_collection_model_direction_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_is_equal_to(const data_collection_model_direction_t *direction, const data_collection_model_direction_t *other_direction);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_is_not_set(const data_collection_model_direction_t *direction);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_is_non_standard(const data_collection_model_direction_t *direction);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_direction_e data_collection_model_direction_get_enum(const data_collection_model_direction_t *direction);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_direction_get_string(const data_collection_model_direction_t *direction);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_set_enum(data_collection_model_direction_t *direction, data_collection_model_direction_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_direction_set_string(data_collection_model_direction_t *direction, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type Direction */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_direction_make_lnode(data_collection_model_direction_t *direction);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DIRECTION_H_ */

