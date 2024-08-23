#ifndef _DATA_COLLECTION_EXCEPTION_H_
#define _DATA_COLLECTION_EXCEPTION_H_

/**********************************************************************************************************************************
 * Exception - Public C interface to the Exception object
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

#include "ExceptionTrend.h"
#include "ExceptionId.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_exception_s data_collection_model_exception_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_create_copy(const data_collection_model_exception_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_create_move(data_collection_model_exception_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_copy(data_collection_model_exception_t *exception, const data_collection_model_exception_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_move(data_collection_model_exception_t *exception, data_collection_model_exception_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_exception_free(data_collection_model_exception_t *exception);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_exception_toJSON(const data_collection_model_exception_t *exception, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_is_equal_to(const data_collection_model_exception_t *exception, const data_collection_model_exception_t *other_exception);



DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_exception_id_t* data_collection_model_exception_get_excep_id(const data_collection_model_exception_t *exception);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_id(data_collection_model_exception_t *exception, const data_collection_model_exception_id_t* p_excep_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_id_move(data_collection_model_exception_t *exception, data_collection_model_exception_id_t* p_excep_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_has_excep_level(const data_collection_model_exception_t *exception);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_exception_get_excep_level(const data_collection_model_exception_t *exception);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_level(data_collection_model_exception_t *exception, const int32_t p_excep_level);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_level_move(data_collection_model_exception_t *exception, int32_t p_excep_level);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_has_excep_trend(const data_collection_model_exception_t *exception);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_exception_trend_t* data_collection_model_exception_get_excep_trend(const data_collection_model_exception_t *exception);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_trend(data_collection_model_exception_t *exception, const data_collection_model_exception_trend_t* p_excep_trend);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_t *data_collection_model_exception_set_excep_trend_move(data_collection_model_exception_t *exception, data_collection_model_exception_trend_t* p_excep_trend);

/* lnode helper for generating ogs_list_t nodes's of type Exception */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_exception_make_lnode(data_collection_model_exception_t *exception);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_EXCEPTION_H_ */

