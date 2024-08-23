#ifndef _DATA_COLLECTION_UE_AREA_INDICATION_H_
#define _DATA_COLLECTION_UE_AREA_INDICATION_H_

/**********************************************************************************************************************************
 * UeAreaIndication - Public C interface to the UeAreaIndication object
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

typedef struct data_collection_model_ue_area_indication_s data_collection_model_ue_area_indication_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create_copy(const data_collection_model_ue_area_indication_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create_move(data_collection_model_ue_area_indication_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_copy(data_collection_model_ue_area_indication_t *ue_area_indication, const data_collection_model_ue_area_indication_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_move(data_collection_model_ue_area_indication_t *ue_area_indication, data_collection_model_ue_area_indication_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_area_indication_free(data_collection_model_ue_area_indication_t *ue_area_indication);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_area_indication_toJSON(const data_collection_model_ue_area_indication_t *ue_area_indication, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_area_indication_is_equal_to(const data_collection_model_ue_area_indication_t *ue_area_indication, const data_collection_model_ue_area_indication_t *other_ue_area_indication);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_area_indication_has_country(const data_collection_model_ue_area_indication_t *ue_area_indication);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_area_indication_get_country(const data_collection_model_ue_area_indication_t *ue_area_indication);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_country(data_collection_model_ue_area_indication_t *ue_area_indication, const char* p_country);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_country_move(data_collection_model_ue_area_indication_t *ue_area_indication, char* p_country);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_area_indication_has_international_area_ind(const data_collection_model_ue_area_indication_t *ue_area_indication);


DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_ue_area_indication_is_international_area_ind(const data_collection_model_ue_area_indication_t *ue_area_indication);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_international_area_ind(data_collection_model_ue_area_indication_t *ue_area_indication, const bool p_international_area_ind);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_international_area_ind_move(data_collection_model_ue_area_indication_t *ue_area_indication, bool p_international_area_ind);

/* lnode helper for generating ogs_list_t nodes's of type UeAreaIndication */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_area_indication_make_lnode(data_collection_model_ue_area_indication_t *ue_area_indication);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UE_AREA_INDICATION_H_ */

