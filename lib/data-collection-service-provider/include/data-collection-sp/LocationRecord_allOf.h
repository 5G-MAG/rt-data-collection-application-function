#ifndef _DATA_COLLECTION_LOCATION_RECORD_ALL_OF_H_
#define _DATA_COLLECTION_LOCATION_RECORD_ALL_OF_H_

/**********************************************************************************************************************************
 * LocationRecord_allOf - Public C interface to the LocationRecord_allOf object
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

#include "LocationData.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_location_record_all_of_s data_collection_model_location_record_all_of_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_create_copy(const data_collection_model_location_record_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_create_move(data_collection_model_location_record_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_copy(data_collection_model_location_record_all_of_t *location_record_all_of, const data_collection_model_location_record_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_move(data_collection_model_location_record_all_of_t *location_record_all_of, data_collection_model_location_record_all_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_location_record_all_of_free(data_collection_model_location_record_all_of_t *location_record_all_of);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_location_record_all_of_toJSON(const data_collection_model_location_record_all_of_t *location_record_all_of, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_location_record_all_of_is_equal_to(const data_collection_model_location_record_all_of_t *location_record_all_of, const data_collection_model_location_record_all_of_t *other_location_record_all_of);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_data_t* data_collection_model_location_record_all_of_get_location(const data_collection_model_location_record_all_of_t *location_record_all_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_set_location(data_collection_model_location_record_all_of_t *location_record_all_of, const data_collection_model_location_data_t* p_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_set_location_move(data_collection_model_location_record_all_of_t *location_record_all_of, data_collection_model_location_data_t* p_location);

/* lnode helper for generating ogs_list_t nodes's of type LocationRecord_allOf */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_location_record_all_of_make_lnode(data_collection_model_location_record_all_of_t *location_record_all_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_LOCATION_RECORD_ALL_OF_H_ */

