#ifndef _DATA_COLLECTION_INDOOR_OUTDOOR_IND_H_
#define _DATA_COLLECTION_INDOOR_OUTDOOR_IND_H_

/**********************************************************************************************************************************
 * IndoorOutdoorInd - Public C interface to the IndoorOutdoorInd object
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

#include "IndoorOutdoorInd_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_indoor_outdoor_ind_s data_collection_model_indoor_outdoor_ind_t;

typedef enum {
    DCM_INDOOR_OUTDOOR_IND_NO_VAL,
    DCM_INDOOR_OUTDOOR_IND_VAL_INDOOR,
    DCM_INDOOR_OUTDOOR_IND_VAL_OUTDOOR,
    DCM_INDOOR_OUTDOOR_IND_OTHER
} data_collection_model_indoor_outdoor_ind_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_create_copy(const data_collection_model_indoor_outdoor_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_create_move(data_collection_model_indoor_outdoor_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_copy(data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind, const data_collection_model_indoor_outdoor_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_move(data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind, data_collection_model_indoor_outdoor_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_indoor_outdoor_ind_free(data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_indoor_outdoor_ind_toJSON(const data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_indoor_outdoor_ind_is_equal_to(const data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind, const data_collection_model_indoor_outdoor_ind_t *other_indoor_outdoor_ind);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_indoor_outdoor_ind_is_not_set(const data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_indoor_outdoor_ind_is_non_standard(const data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_indoor_outdoor_ind_e data_collection_model_indoor_outdoor_ind_get_enum(const data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_indoor_outdoor_ind_get_string(const data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_indoor_outdoor_ind_set_enum(data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind, data_collection_model_indoor_outdoor_ind_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_indoor_outdoor_ind_set_string(data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type IndoorOutdoorInd */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_indoor_outdoor_ind_make_lnode(data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_INDOOR_OUTDOOR_IND_H_ */

