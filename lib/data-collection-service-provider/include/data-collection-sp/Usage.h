#ifndef _DATA_COLLECTION_USAGE_H_
#define _DATA_COLLECTION_USAGE_H_

/**********************************************************************************************************************************
 * Usage - Public C interface to the Usage object
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

#include "Usage_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_usage_s data_collection_model_usage_t;

typedef enum {
    DCM_USAGE_NO_VAL,
    DCM_USAGE_VAL_UNSUCCESS,
    DCM_USAGE_VAL_SUCCESS_RESULTS_NOT_USED,
    DCM_USAGE_VAL_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION,
    DCM_USAGE_VAL_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION,
    DCM_USAGE_VAL_SUCCESS_METHOD_NOT_DETERMINED,
    DCM_USAGE_OTHER
} data_collection_model_usage_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_create_copy(const data_collection_model_usage_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_create_move(data_collection_model_usage_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_copy(data_collection_model_usage_t *usage, const data_collection_model_usage_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_move(data_collection_model_usage_t *usage, data_collection_model_usage_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_usage_free(data_collection_model_usage_t *usage);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_usage_toJSON(const data_collection_model_usage_t *usage, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_t *data_collection_model_usage_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_is_equal_to(const data_collection_model_usage_t *usage, const data_collection_model_usage_t *other_usage);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_is_not_set(const data_collection_model_usage_t *usage);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_is_non_standard(const data_collection_model_usage_t *usage);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_usage_e data_collection_model_usage_get_enum(const data_collection_model_usage_t *usage);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_usage_get_string(const data_collection_model_usage_t *usage);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_set_enum(data_collection_model_usage_t *usage, data_collection_model_usage_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_usage_set_string(data_collection_model_usage_t *usage, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type Usage */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_usage_make_lnode(data_collection_model_usage_t *usage);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_USAGE_H_ */

