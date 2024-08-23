#ifndef _DATA_COLLECTION_PLMN_ID_H_
#define _DATA_COLLECTION_PLMN_ID_H_

/**********************************************************************************************************************************
 * PlmnId - Public C interface to the PlmnId object
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

typedef struct data_collection_model_plmn_id_s data_collection_model_plmn_id_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_create_copy(const data_collection_model_plmn_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_create_move(data_collection_model_plmn_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_copy(data_collection_model_plmn_id_t *plmn_id, const data_collection_model_plmn_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_move(data_collection_model_plmn_id_t *plmn_id, data_collection_model_plmn_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_plmn_id_free(data_collection_model_plmn_id_t *plmn_id);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_plmn_id_toJSON(const data_collection_model_plmn_id_t *plmn_id, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_plmn_id_is_equal_to(const data_collection_model_plmn_id_t *plmn_id, const data_collection_model_plmn_id_t *other_plmn_id);



DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_get_mcc(const data_collection_model_plmn_id_t *plmn_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mcc(data_collection_model_plmn_id_t *plmn_id, const char* p_mcc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mcc_move(data_collection_model_plmn_id_t *plmn_id, char* p_mcc);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_get_mnc(const data_collection_model_plmn_id_t *plmn_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mnc(data_collection_model_plmn_id_t *plmn_id, const char* p_mnc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mnc_move(data_collection_model_plmn_id_t *plmn_id, char* p_mnc);

/* lnode helper for generating ogs_list_t nodes's of type PlmnId */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_plmn_id_make_lnode(data_collection_model_plmn_id_t *plmn_id);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PLMN_ID_H_ */

