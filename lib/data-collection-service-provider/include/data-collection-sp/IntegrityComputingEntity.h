#ifndef _DATA_COLLECTION_INTEGRITY_COMPUTING_ENTITY_H_
#define _DATA_COLLECTION_INTEGRITY_COMPUTING_ENTITY_H_

/**********************************************************************************************************************************
 * IntegrityComputingEntity - Public C interface to the IntegrityComputingEntity object
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

#include "IntegrityComputingEntity_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_integrity_computing_entity_s data_collection_model_integrity_computing_entity_t;

typedef enum {
    DCM_INTEGRITY_COMPUTING_ENTITY_NO_VAL,
    DCM_INTEGRITY_COMPUTING_ENTITY_VAL_UE,
    DCM_INTEGRITY_COMPUTING_ENTITY_VAL_LMF,
    DCM_INTEGRITY_COMPUTING_ENTITY_VAL_BOTH,
    DCM_INTEGRITY_COMPUTING_ENTITY_OTHER
} data_collection_model_integrity_computing_entity_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_create_copy(const data_collection_model_integrity_computing_entity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_create_move(data_collection_model_integrity_computing_entity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_copy(data_collection_model_integrity_computing_entity_t *integrity_computing_entity, const data_collection_model_integrity_computing_entity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_move(data_collection_model_integrity_computing_entity_t *integrity_computing_entity, data_collection_model_integrity_computing_entity_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_integrity_computing_entity_free(data_collection_model_integrity_computing_entity_t *integrity_computing_entity);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_integrity_computing_entity_toJSON(const data_collection_model_integrity_computing_entity_t *integrity_computing_entity, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_t *data_collection_model_integrity_computing_entity_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_is_equal_to(const data_collection_model_integrity_computing_entity_t *integrity_computing_entity, const data_collection_model_integrity_computing_entity_t *other_integrity_computing_entity);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_is_not_set(const data_collection_model_integrity_computing_entity_t *integrity_computing_entity);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_is_non_standard(const data_collection_model_integrity_computing_entity_t *integrity_computing_entity);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_computing_entity_e data_collection_model_integrity_computing_entity_get_enum(const data_collection_model_integrity_computing_entity_t *integrity_computing_entity);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_integrity_computing_entity_get_string(const data_collection_model_integrity_computing_entity_t *integrity_computing_entity);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_set_enum(data_collection_model_integrity_computing_entity_t *integrity_computing_entity, data_collection_model_integrity_computing_entity_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_computing_entity_set_string(data_collection_model_integrity_computing_entity_t *integrity_computing_entity, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type IntegrityComputingEntity */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_integrity_computing_entity_make_lnode(data_collection_model_integrity_computing_entity_t *integrity_computing_entity);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_INTEGRITY_COMPUTING_ENTITY_H_ */

