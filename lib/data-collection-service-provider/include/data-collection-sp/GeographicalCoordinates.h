#ifndef _DATA_COLLECTION_GEOGRAPHICAL_COORDINATES_H_
#define _DATA_COLLECTION_GEOGRAPHICAL_COORDINATES_H_

/**********************************************************************************************************************************
 * GeographicalCoordinates - Public C interface to the GeographicalCoordinates object
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

typedef struct data_collection_model_geographical_coordinates_s data_collection_model_geographical_coordinates_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create_copy(const data_collection_model_geographical_coordinates_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create_move(data_collection_model_geographical_coordinates_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_copy(data_collection_model_geographical_coordinates_t *geographical_coordinates, const data_collection_model_geographical_coordinates_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_move(data_collection_model_geographical_coordinates_t *geographical_coordinates, data_collection_model_geographical_coordinates_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_geographical_coordinates_free(data_collection_model_geographical_coordinates_t *geographical_coordinates);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_geographical_coordinates_toJSON(const data_collection_model_geographical_coordinates_t *geographical_coordinates, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_geographical_coordinates_is_equal_to(const data_collection_model_geographical_coordinates_t *geographical_coordinates, const data_collection_model_geographical_coordinates_t *other_geographical_coordinates);



DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_geographical_coordinates_get_lon(const data_collection_model_geographical_coordinates_t *geographical_coordinates);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lon(data_collection_model_geographical_coordinates_t *geographical_coordinates, const double p_lon);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lon_move(data_collection_model_geographical_coordinates_t *geographical_coordinates, double p_lon);


DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_geographical_coordinates_get_lat(const data_collection_model_geographical_coordinates_t *geographical_coordinates);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lat(data_collection_model_geographical_coordinates_t *geographical_coordinates, const double p_lat);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lat_move(data_collection_model_geographical_coordinates_t *geographical_coordinates, double p_lat);

/* lnode helper for generating ogs_list_t nodes's of type GeographicalCoordinates */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_geographical_coordinates_make_lnode(data_collection_model_geographical_coordinates_t *geographical_coordinates);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GEOGRAPHICAL_COORDINATES_H_ */

