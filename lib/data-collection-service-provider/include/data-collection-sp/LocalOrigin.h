#ifndef _DATA_COLLECTION_LOCAL_ORIGIN_H_
#define _DATA_COLLECTION_LOCAL_ORIGIN_H_

/**********************************************************************************************************************************
 * LocalOrigin - Public C interface to the LocalOrigin object
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

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_local_origin_s data_collection_model_local_origin_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_create_copy(const data_collection_model_local_origin_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_create_move(data_collection_model_local_origin_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_copy(data_collection_model_local_origin_t *local_origin, const data_collection_model_local_origin_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_move(data_collection_model_local_origin_t *local_origin, data_collection_model_local_origin_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_local_origin_free(data_collection_model_local_origin_t *local_origin);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_local_origin_toJSON(const data_collection_model_local_origin_t *local_origin, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_local_origin_get_coordinate_id(const data_collection_model_local_origin_t *local_origin);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_coordinate_id(data_collection_model_local_origin_t *local_origin, const char* p_coordinate_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_coordinate_id_move(data_collection_model_local_origin_t *local_origin, char* p_coordinate_id);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_local_origin_get_point(const data_collection_model_local_origin_t *local_origin);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_point(data_collection_model_local_origin_t *local_origin, const data_collection_model_geographical_coordinates_t* p_point);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_point_move(data_collection_model_local_origin_t *local_origin, data_collection_model_geographical_coordinates_t* p_point);

/* lnode helper for generating ogs_list_t nodes's of type LocalOrigin */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_local_origin_make_lnode(data_collection_model_local_origin_t *local_origin);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_LOCAL_ORIGIN_H_ */

