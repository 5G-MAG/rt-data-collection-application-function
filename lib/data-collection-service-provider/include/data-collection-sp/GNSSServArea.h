#ifndef _DATA_COLLECTION_GNSS_SERV_AREA_H_
#define _DATA_COLLECTION_GNSS_SERV_AREA_H_

/**********************************************************************************************************************************
 * GNSSServArea - Public C interface to the GNSSServArea object
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

#include "Tai.h"
#include "GeographicArea.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_gnss_serv_area_s data_collection_model_gnss_serv_area_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_create_copy(const data_collection_model_gnss_serv_area_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_create_move(data_collection_model_gnss_serv_area_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_copy(data_collection_model_gnss_serv_area_t *gnss_serv_area, const data_collection_model_gnss_serv_area_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_move(data_collection_model_gnss_serv_area_t *gnss_serv_area, data_collection_model_gnss_serv_area_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnss_serv_area_free(data_collection_model_gnss_serv_area_t *gnss_serv_area);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnss_serv_area_toJSON(const data_collection_model_gnss_serv_area_t *gnss_serv_area, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographic_area_t* data_collection_model_gnss_serv_area_get_geographical_area(const data_collection_model_gnss_serv_area_t *gnss_serv_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_geographical_area(data_collection_model_gnss_serv_area_t *gnss_serv_area, const data_collection_model_geographic_area_t* p_geographical_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_geographical_area_move(data_collection_model_gnss_serv_area_t *gnss_serv_area, data_collection_model_geographic_area_t* p_geographical_area);

DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_gnss_serv_area_get_tai_list(const data_collection_model_gnss_serv_area_t *gnss_serv_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_tai_list(data_collection_model_gnss_serv_area_t *gnss_serv_area, const ogs_list_t* p_tai_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_tai_list_move(data_collection_model_gnss_serv_area_t *gnss_serv_area, ogs_list_t* p_tai_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_add_tai_list(data_collection_model_gnss_serv_area_t *gnss_serv_area, data_collection_model_tai_t* tai_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_remove_tai_list(data_collection_model_gnss_serv_area_t *gnss_serv_area, const data_collection_model_tai_t* tai_list);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_clear_tai_list(data_collection_model_gnss_serv_area_t *gnss_serv_area);

/* lnode helper for generating ogs_list_t nodes's of type GNSSServArea */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnss_serv_area_make_lnode(data_collection_model_gnss_serv_area_t *gnss_serv_area);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GNSS_SERV_AREA_H_ */

