#ifndef _DATA_COLLECTION_PERFORMANCE_DATA_H_
#define _DATA_COLLECTION_PERFORMANCE_DATA_H_

/**********************************************************************************************************************************
 * PerformanceData - Public C interface to the PerformanceData object
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

typedef struct data_collection_model_performance_data_s data_collection_model_performance_data_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_create_copy(const data_collection_model_performance_data_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_create_move(data_collection_model_performance_data_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_copy(data_collection_model_performance_data_t *performance_data, const data_collection_model_performance_data_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_move(data_collection_model_performance_data_t *performance_data, data_collection_model_performance_data_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_free(data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_toJSON(const data_collection_model_performance_data_t *performance_data, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_is_equal_to(const data_collection_model_performance_data_t *performance_data, const data_collection_model_performance_data_t *other_performance_data);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_pdb(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_pdb(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb(data_collection_model_performance_data_t *performance_data, const int32_t p_pdb);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb_move(data_collection_model_performance_data_t *performance_data, int32_t p_pdb);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_pdb_dl(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_pdb_dl(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb_dl(data_collection_model_performance_data_t *performance_data, const int32_t p_pdb_dl);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb_dl_move(data_collection_model_performance_data_t *performance_data, int32_t p_pdb_dl);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_pdb_ul(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_pdb_ul(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_ul(data_collection_model_performance_data_t *performance_data, const int32_t p_max_pdb_ul);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_ul_move(data_collection_model_performance_data_t *performance_data, int32_t p_max_pdb_ul);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_pdb_dl(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_pdb_dl(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_dl(data_collection_model_performance_data_t *performance_data, const int32_t p_max_pdb_dl);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_dl_move(data_collection_model_performance_data_t *performance_data, int32_t p_max_pdb_dl);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_plr(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_plr(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr(data_collection_model_performance_data_t *performance_data, const int32_t p_plr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr_move(data_collection_model_performance_data_t *performance_data, int32_t p_plr);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_plr_dl(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_plr_dl(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr_dl(data_collection_model_performance_data_t *performance_data, const int32_t p_plr_dl);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr_dl_move(data_collection_model_performance_data_t *performance_data, int32_t p_plr_dl);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_plr_ul(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_plr_ul(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_ul(data_collection_model_performance_data_t *performance_data, const int32_t p_max_plr_ul);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_ul_move(data_collection_model_performance_data_t *performance_data, int32_t p_max_plr_ul);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_plr_dl(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_plr_dl(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_dl(data_collection_model_performance_data_t *performance_data, const int32_t p_max_plr_dl);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_dl_move(data_collection_model_performance_data_t *performance_data, int32_t p_max_plr_dl);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_thrput_ul(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_thrput_ul(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_ul(data_collection_model_performance_data_t *performance_data, const char* p_thrput_ul);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_ul_move(data_collection_model_performance_data_t *performance_data, char* p_thrput_ul);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_thrput_ul(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_max_thrput_ul(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_ul(data_collection_model_performance_data_t *performance_data, const char* p_max_thrput_ul);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_ul_move(data_collection_model_performance_data_t *performance_data, char* p_max_thrput_ul);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_min_thrput_ul(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_min_thrput_ul(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_ul(data_collection_model_performance_data_t *performance_data, const char* p_min_thrput_ul);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_ul_move(data_collection_model_performance_data_t *performance_data, char* p_min_thrput_ul);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_thrput_dl(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_thrput_dl(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_dl(data_collection_model_performance_data_t *performance_data, const char* p_thrput_dl);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_dl_move(data_collection_model_performance_data_t *performance_data, char* p_thrput_dl);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_thrput_dl(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_max_thrput_dl(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_dl(data_collection_model_performance_data_t *performance_data, const char* p_max_thrput_dl);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_dl_move(data_collection_model_performance_data_t *performance_data, char* p_max_thrput_dl);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_min_thrput_dl(const data_collection_model_performance_data_t *performance_data);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_min_thrput_dl(const data_collection_model_performance_data_t *performance_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_dl(data_collection_model_performance_data_t *performance_data, const char* p_min_thrput_dl);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_dl_move(data_collection_model_performance_data_t *performance_data, char* p_min_thrput_dl);

/* lnode helper for generating ogs_list_t nodes's of type PerformanceData */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_make_lnode(data_collection_model_performance_data_t *performance_data);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PERFORMANCE_DATA_H_ */

