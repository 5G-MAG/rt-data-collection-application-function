#ifndef _DATA_COLLECTION_GNSS_ASSIST_DATA_INFO_H_
#define _DATA_COLLECTION_GNSS_ASSIST_DATA_INFO_H_

/**********************************************************************************************************************************
 * GNSSAssistDataInfo - Public C interface to the GNSSAssistDataInfo object
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

#include "GeographicalCoordinates.h"
#include "GNSSServArea.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_gnss_assist_data_info_s data_collection_model_gnss_assist_data_info_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create_copy(const data_collection_model_gnss_assist_data_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create_move(data_collection_model_gnss_assist_data_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_copy(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const data_collection_model_gnss_assist_data_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_move(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, data_collection_model_gnss_assist_data_info_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnss_assist_data_info_free(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnss_assist_data_info_toJSON(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_assist_data_info_is_equal_to(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const data_collection_model_gnss_assist_data_info_t *other_gnss_assist_data_info);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_gnss_assist_data_info_get_gnss_assist_data(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_gnss_assist_data(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const char* p_gnss_assist_data);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_gnss_assist_data_move(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, char* p_gnss_assist_data);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_gnss_serv_area_t* data_collection_model_gnss_assist_data_info_get_serv_area(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_serv_area(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const data_collection_model_gnss_serv_area_t* p_serv_area);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_serv_area_move(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, data_collection_model_gnss_serv_area_t* p_serv_area);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_gnss_assist_data_info_get_source_info(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_source_info(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const data_collection_model_geographical_coordinates_t* p_source_info);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_source_info_move(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, data_collection_model_geographical_coordinates_t* p_source_info);

/* lnode helper for generating ogs_list_t nodes's of type GNSSAssistDataInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnss_assist_data_info_make_lnode(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GNSS_ASSIST_DATA_INFO_H_ */

