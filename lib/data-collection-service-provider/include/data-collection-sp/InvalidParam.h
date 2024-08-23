#ifndef _DATA_COLLECTION_INVALID_PARAM_H_
#define _DATA_COLLECTION_INVALID_PARAM_H_

/**********************************************************************************************************************************
 * InvalidParam - Public C interface to the InvalidParam object
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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_invalid_param_s data_collection_model_invalid_param_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_create_copy(const data_collection_model_invalid_param_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_create_move(data_collection_model_invalid_param_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_copy(data_collection_model_invalid_param_t *invalid_param, const data_collection_model_invalid_param_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_move(data_collection_model_invalid_param_t *invalid_param, data_collection_model_invalid_param_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_invalid_param_free(data_collection_model_invalid_param_t *invalid_param);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_invalid_param_toJSON(const data_collection_model_invalid_param_t *invalid_param, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_invalid_param_is_equal_to(const data_collection_model_invalid_param_t *invalid_param, const data_collection_model_invalid_param_t *other_invalid_param);



DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_invalid_param_get_param(const data_collection_model_invalid_param_t *invalid_param);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_param(data_collection_model_invalid_param_t *invalid_param, const char* p_param);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_param_move(data_collection_model_invalid_param_t *invalid_param, char* p_param);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_invalid_param_has_reason(const data_collection_model_invalid_param_t *invalid_param);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_invalid_param_get_reason(const data_collection_model_invalid_param_t *invalid_param);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_reason(data_collection_model_invalid_param_t *invalid_param, const char* p_reason);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_invalid_param_t *data_collection_model_invalid_param_set_reason_move(data_collection_model_invalid_param_t *invalid_param, char* p_reason);

/* lnode helper for generating ogs_list_t nodes's of type InvalidParam */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_invalid_param_make_lnode(data_collection_model_invalid_param_t *invalid_param);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_INVALID_PARAM_H_ */

