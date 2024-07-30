#ifndef _DATA_COLLECTION_PARTITIONING_CRITERIA_H_
#define _DATA_COLLECTION_PARTITIONING_CRITERIA_H_

/**********************************************************************************************************************************
 * PartitioningCriteria - Public C interface to the PartitioningCriteria object
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

#include "PartitioningCriteria_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_partitioning_criteria_s data_collection_model_partitioning_criteria_t;

typedef enum {
    DCM_PARTITIONING_CRITERIA_NO_VAL,
    DCM_PARTITIONING_CRITERIA_VAL_TAC,
    DCM_PARTITIONING_CRITERIA_VAL_SUBPLMN,
    DCM_PARTITIONING_CRITERIA_VAL_GEOAREA,
    DCM_PARTITIONING_CRITERIA_VAL_SNSSAI,
    DCM_PARTITIONING_CRITERIA_VAL_DNN,
    DCM_PARTITIONING_CRITERIA_OTHER
} data_collection_model_partitioning_criteria_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_create_copy(const data_collection_model_partitioning_criteria_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_create_move(data_collection_model_partitioning_criteria_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_copy(data_collection_model_partitioning_criteria_t *partitioning_criteria, const data_collection_model_partitioning_criteria_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_move(data_collection_model_partitioning_criteria_t *partitioning_criteria, data_collection_model_partitioning_criteria_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_partitioning_criteria_free(data_collection_model_partitioning_criteria_t *partitioning_criteria);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_partitioning_criteria_toJSON(const data_collection_model_partitioning_criteria_t *partitioning_criteria, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_t *data_collection_model_partitioning_criteria_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_is_equal_to(const data_collection_model_partitioning_criteria_t *partitioning_criteria, const data_collection_model_partitioning_criteria_t *other_partitioning_criteria);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_is_not_set(const data_collection_model_partitioning_criteria_t *partitioning_criteria);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_is_non_standard(const data_collection_model_partitioning_criteria_t *partitioning_criteria);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_partitioning_criteria_e data_collection_model_partitioning_criteria_get_enum(const data_collection_model_partitioning_criteria_t *partitioning_criteria);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_partitioning_criteria_get_string(const data_collection_model_partitioning_criteria_t *partitioning_criteria);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_set_enum(data_collection_model_partitioning_criteria_t *partitioning_criteria, data_collection_model_partitioning_criteria_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_partitioning_criteria_set_string(data_collection_model_partitioning_criteria_t *partitioning_criteria, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type PartitioningCriteria */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_partitioning_criteria_make_lnode(data_collection_model_partitioning_criteria_t *partitioning_criteria);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PARTITIONING_CRITERIA_H_ */

