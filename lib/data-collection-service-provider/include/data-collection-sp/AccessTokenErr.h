#ifndef _DATA_COLLECTION_ACCESS_TOKEN_ERR_H_
#define _DATA_COLLECTION_ACCESS_TOKEN_ERR_H_

/**********************************************************************************************************************************
 * AccessTokenErr - Public C interface to the AccessTokenErr object
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

typedef struct data_collection_model_access_token_err_s data_collection_model_access_token_err_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_create_copy(const data_collection_model_access_token_err_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_create_move(data_collection_model_access_token_err_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_copy(data_collection_model_access_token_err_t *access_token_err, const data_collection_model_access_token_err_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_move(data_collection_model_access_token_err_t *access_token_err, data_collection_model_access_token_err_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_access_token_err_free(data_collection_model_access_token_err_t *access_token_err);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_access_token_err_toJSON(const data_collection_model_access_token_err_t *access_token_err, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_access_token_err_is_equal_to(const data_collection_model_access_token_err_t *access_token_err, const data_collection_model_access_token_err_t *other_access_token_err);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_err_get_error(const data_collection_model_access_token_err_t *access_token_err);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error(data_collection_model_access_token_err_t *access_token_err, const char* p_error);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_move(data_collection_model_access_token_err_t *access_token_err, char* p_error);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_err_get_error_description(const data_collection_model_access_token_err_t *access_token_err);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_description(data_collection_model_access_token_err_t *access_token_err, const char* p_error_description);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_description_move(data_collection_model_access_token_err_t *access_token_err, char* p_error_description);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_access_token_err_get_error_uri(const data_collection_model_access_token_err_t *access_token_err);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_uri(data_collection_model_access_token_err_t *access_token_err, const char* p_error_uri);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_access_token_err_t *data_collection_model_access_token_err_set_error_uri_move(data_collection_model_access_token_err_t *access_token_err, char* p_error_uri);

/* lnode helper for generating ogs_list_t nodes's of type AccessTokenErr */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_access_token_err_make_lnode(data_collection_model_access_token_err_t *access_token_err);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ACCESS_TOKEN_ERR_H_ */

