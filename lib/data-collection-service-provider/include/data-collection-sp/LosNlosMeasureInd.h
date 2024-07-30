#ifndef _DATA_COLLECTION_LOS_NLOS_MEASURE_IND_H_
#define _DATA_COLLECTION_LOS_NLOS_MEASURE_IND_H_

/**********************************************************************************************************************************
 * LosNlosMeasureInd - Public C interface to the LosNlosMeasureInd object
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

#include "LosNlosMeasureInd_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_los_nlos_measure_ind_s data_collection_model_los_nlos_measure_ind_t;

typedef enum {
    DCM_LOS_NLOS_MEASURE_IND_NO_VAL,
    DCM_LOS_NLOS_MEASURE_IND_VAL_LOS,
    DCM_LOS_NLOS_MEASURE_IND_VAL_NLOS,
    DCM_LOS_NLOS_MEASURE_IND_OTHER
} data_collection_model_los_nlos_measure_ind_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_create_copy(const data_collection_model_los_nlos_measure_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_create_move(data_collection_model_los_nlos_measure_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_copy(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, const data_collection_model_los_nlos_measure_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_move(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, data_collection_model_los_nlos_measure_ind_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_los_nlos_measure_ind_free(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_los_nlos_measure_ind_toJSON(const data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_is_equal_to(const data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, const data_collection_model_los_nlos_measure_ind_t *other_los_nlos_measure_ind);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_is_not_set(const data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_is_non_standard(const data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_e data_collection_model_los_nlos_measure_ind_get_enum(const data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_los_nlos_measure_ind_get_string(const data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_set_enum(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, data_collection_model_los_nlos_measure_ind_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_set_string(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type LosNlosMeasureInd */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_los_nlos_measure_ind_make_lnode(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_LOS_NLOS_MEASURE_IND_H_ */

