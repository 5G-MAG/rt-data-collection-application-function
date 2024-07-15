#ifndef _DATA_COLLECTION_SVC_EXPERIENCE_H_
#define _DATA_COLLECTION_SVC_EXPERIENCE_H_

/**********************************************************************************************************************************
 * SvcExperience - Public C interface to the SvcExperience object
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

typedef struct data_collection_model_svc_experience_s data_collection_model_svc_experience_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_create_copy(const data_collection_model_svc_experience_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_create_move(data_collection_model_svc_experience_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_copy(data_collection_model_svc_experience_t *svc_experience, const data_collection_model_svc_experience_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_move(data_collection_model_svc_experience_t *svc_experience, data_collection_model_svc_experience_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_svc_experience_free(data_collection_model_svc_experience_t *svc_experience);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_svc_experience_toJSON(const data_collection_model_svc_experience_t *svc_experience, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_svc_experience_get_mos(const data_collection_model_svc_experience_t *svc_experience);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_mos(data_collection_model_svc_experience_t *svc_experience, const float p_mos);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_mos_move(data_collection_model_svc_experience_t *svc_experience, float p_mos);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_svc_experience_get_upper_range(const data_collection_model_svc_experience_t *svc_experience);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_upper_range(data_collection_model_svc_experience_t *svc_experience, const float p_upper_range);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_upper_range_move(data_collection_model_svc_experience_t *svc_experience, float p_upper_range);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_svc_experience_get_lower_range(const data_collection_model_svc_experience_t *svc_experience);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_lower_range(data_collection_model_svc_experience_t *svc_experience, const float p_lower_range);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_lower_range_move(data_collection_model_svc_experience_t *svc_experience, float p_lower_range);

/* lnode helper for generating ogs_list_t nodes's of type SvcExperience */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_svc_experience_make_lnode(data_collection_model_svc_experience_t *svc_experience);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SVC_EXPERIENCE_H_ */

