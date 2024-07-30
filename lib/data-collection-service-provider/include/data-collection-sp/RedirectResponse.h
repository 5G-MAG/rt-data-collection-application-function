#ifndef _DATA_COLLECTION_REDIRECT_RESPONSE_H_
#define _DATA_COLLECTION_REDIRECT_RESPONSE_H_

/**********************************************************************************************************************************
 * RedirectResponse - Public C interface to the RedirectResponse object
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

typedef struct data_collection_model_redirect_response_s data_collection_model_redirect_response_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_create_copy(const data_collection_model_redirect_response_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_create_move(data_collection_model_redirect_response_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_copy(data_collection_model_redirect_response_t *redirect_response, const data_collection_model_redirect_response_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_move(data_collection_model_redirect_response_t *redirect_response, data_collection_model_redirect_response_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_redirect_response_free(data_collection_model_redirect_response_t *redirect_response);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_redirect_response_toJSON(const data_collection_model_redirect_response_t *redirect_response, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_redirect_response_is_equal_to(const data_collection_model_redirect_response_t *redirect_response, const data_collection_model_redirect_response_t *other_redirect_response);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_redirect_response_get_cause(const data_collection_model_redirect_response_t *redirect_response);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_cause(data_collection_model_redirect_response_t *redirect_response, const char* p_cause);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_cause_move(data_collection_model_redirect_response_t *redirect_response, char* p_cause);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_redirect_response_get_target_scp(const data_collection_model_redirect_response_t *redirect_response);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_scp(data_collection_model_redirect_response_t *redirect_response, const char* p_target_scp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_scp_move(data_collection_model_redirect_response_t *redirect_response, char* p_target_scp);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_redirect_response_get_target_sepp(const data_collection_model_redirect_response_t *redirect_response);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_sepp(data_collection_model_redirect_response_t *redirect_response, const char* p_target_sepp);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_redirect_response_t *data_collection_model_redirect_response_set_target_sepp_move(data_collection_model_redirect_response_t *redirect_response, char* p_target_sepp);

/* lnode helper for generating ogs_list_t nodes's of type RedirectResponse */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_redirect_response_make_lnode(data_collection_model_redirect_response_t *redirect_response);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_REDIRECT_RESPONSE_H_ */

