#ifndef _DATA_COLLECTION_SDF_METHOD_H_
#define _DATA_COLLECTION_SDF_METHOD_H_

/**********************************************************************************************************************************
 * SdfMethod - Public C interface to the SdfMethod object
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

#include "SdfMethod_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_sdf_method_s data_collection_model_sdf_method_t;

typedef enum {
    DCM_SDF_METHOD_NO_VAL,
    DCM_SDF_METHOD_VAL_5_TUPLE,
    DCM_SDF_METHOD_VAL_2_TUPLE,
    DCM_SDF_METHOD_VAL_TYPE_OF_SERVICE_MARKING,
    DCM_SDF_METHOD_VAL_FLOW_LABEL,
    DCM_SDF_METHOD_VAL_DOMAIN_NAME,
    DCM_SDF_METHOD_OTHER
} data_collection_model_sdf_method_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_create_copy(const data_collection_model_sdf_method_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_create_move(data_collection_model_sdf_method_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_copy(data_collection_model_sdf_method_t *sdf_method, const data_collection_model_sdf_method_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_move(data_collection_model_sdf_method_t *sdf_method, data_collection_model_sdf_method_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_sdf_method_free(data_collection_model_sdf_method_t *sdf_method);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_sdf_method_toJSON(const data_collection_model_sdf_method_t *sdf_method, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_is_equal_to(const data_collection_model_sdf_method_t *sdf_method, const data_collection_model_sdf_method_t *other_sdf_method);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_is_not_set(const data_collection_model_sdf_method_t *sdf_method);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_is_non_standard(const data_collection_model_sdf_method_t *sdf_method);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_e data_collection_model_sdf_method_get_enum(const data_collection_model_sdf_method_t *sdf_method);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_sdf_method_get_string(const data_collection_model_sdf_method_t *sdf_method);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_set_enum(data_collection_model_sdf_method_t *sdf_method, data_collection_model_sdf_method_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_set_string(data_collection_model_sdf_method_t *sdf_method, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type SdfMethod */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_sdf_method_make_lnode(data_collection_model_sdf_method_t *sdf_method);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SDF_METHOD_H_ */

