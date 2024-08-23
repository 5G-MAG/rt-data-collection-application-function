#ifndef _DATA_COLLECTION_QUERY_PARAMETER_H_
#define _DATA_COLLECTION_QUERY_PARAMETER_H_

/**********************************************************************************************************************************
 * QueryParameter - Public C interface to the QueryParameter object
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

typedef struct data_collection_model_query_parameter_s data_collection_model_query_parameter_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_create_copy(const data_collection_model_query_parameter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_create_move(data_collection_model_query_parameter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_copy(data_collection_model_query_parameter_t *query_parameter, const data_collection_model_query_parameter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_move(data_collection_model_query_parameter_t *query_parameter, data_collection_model_query_parameter_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_query_parameter_free(data_collection_model_query_parameter_t *query_parameter);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_query_parameter_toJSON(const data_collection_model_query_parameter_t *query_parameter, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_query_parameter_is_equal_to(const data_collection_model_query_parameter_t *query_parameter, const data_collection_model_query_parameter_t *other_query_parameter);



DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_query_parameter_get_name(const data_collection_model_query_parameter_t *query_parameter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_name(data_collection_model_query_parameter_t *query_parameter, const char* p_name);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_name_move(data_collection_model_query_parameter_t *query_parameter, char* p_name);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_query_parameter_get_value(const data_collection_model_query_parameter_t *query_parameter);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_value(data_collection_model_query_parameter_t *query_parameter, const char* p_value);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_query_parameter_t *data_collection_model_query_parameter_set_value_move(data_collection_model_query_parameter_t *query_parameter, char* p_value);

/* lnode helper for generating ogs_list_t nodes's of type QueryParameter */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_query_parameter_make_lnode(data_collection_model_query_parameter_t *query_parameter);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_QUERY_PARAMETER_H_ */

