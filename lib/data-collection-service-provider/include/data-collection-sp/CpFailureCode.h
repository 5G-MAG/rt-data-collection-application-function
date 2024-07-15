#ifndef _DATA_COLLECTION_CP_FAILURE_CODE_H_
#define _DATA_COLLECTION_CP_FAILURE_CODE_H_

/**********************************************************************************************************************************
 * CpFailureCode - Public C interface to the CpFailureCode object
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

#include "CpFailureCode_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_cp_failure_code_s data_collection_model_cp_failure_code_t;

typedef enum {
    DCM_CP_FAILURE_CODE_NO_VAL,
    DCM_CP_FAILURE_CODE_VAL_MALFUNCTION,
    DCM_CP_FAILURE_CODE_VAL_SET_ID_DUPLICATED,
    DCM_CP_FAILURE_CODE_VAL_OTHER_REASON,
    DCM_CP_FAILURE_CODE_VAL_CONFIDENCE_LEVEL_NOT_SUFFICIENT,
    DCM_CP_FAILURE_CODE_VAL_ACCURACY_LEVEL_NOT_SUFFICIENT,
    DCM_CP_FAILURE_CODE_OTHER
} data_collection_model_cp_failure_code_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_create_copy(const data_collection_model_cp_failure_code_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_create_move(data_collection_model_cp_failure_code_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_copy(data_collection_model_cp_failure_code_t *cp_failure_code, const data_collection_model_cp_failure_code_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_move(data_collection_model_cp_failure_code_t *cp_failure_code, data_collection_model_cp_failure_code_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_cp_failure_code_free(data_collection_model_cp_failure_code_t *cp_failure_code);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_cp_failure_code_toJSON(const data_collection_model_cp_failure_code_t *cp_failure_code, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_is_not_set(const data_collection_model_cp_failure_code_t *cp_failure_code);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_is_non_standard(const data_collection_model_cp_failure_code_t *cp_failure_code);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_e data_collection_model_cp_failure_code_get_enum(const data_collection_model_cp_failure_code_t *cp_failure_code);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_cp_failure_code_get_string(const data_collection_model_cp_failure_code_t *cp_failure_code);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_set_enum(data_collection_model_cp_failure_code_t *cp_failure_code, data_collection_model_cp_failure_code_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_set_string(data_collection_model_cp_failure_code_t *cp_failure_code, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type CpFailureCode */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_cp_failure_code_make_lnode(data_collection_model_cp_failure_code_t *cp_failure_code);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_CP_FAILURE_CODE_H_ */

