#ifndef _DATA_COLLECTION_TYPED_LOCATION_H_
#define _DATA_COLLECTION_TYPED_LOCATION_H_

/**********************************************************************************************************************************
 * TypedLocation - Public C interface to the TypedLocation object
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

#include "CellIdentifierType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_typed_location_s data_collection_model_typed_location_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_create_copy(const data_collection_model_typed_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_create_move(data_collection_model_typed_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_copy(data_collection_model_typed_location_t *typed_location, const data_collection_model_typed_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_move(data_collection_model_typed_location_t *typed_location, data_collection_model_typed_location_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_typed_location_free(data_collection_model_typed_location_t *typed_location);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_typed_location_toJSON(const data_collection_model_typed_location_t *typed_location, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_typed_location_is_equal_to(const data_collection_model_typed_location_t *typed_location, const data_collection_model_typed_location_t *other_typed_location);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cell_identifier_type_t* data_collection_model_typed_location_get_location_identifier_type(const data_collection_model_typed_location_t *typed_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location_identifier_type(data_collection_model_typed_location_t *typed_location, const data_collection_model_cell_identifier_type_t* p_location_identifier_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location_identifier_type_move(data_collection_model_typed_location_t *typed_location, data_collection_model_cell_identifier_type_t* p_location_identifier_type);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_typed_location_get_location(const data_collection_model_typed_location_t *typed_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location(data_collection_model_typed_location_t *typed_location, const char* p_location);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location_move(data_collection_model_typed_location_t *typed_location, char* p_location);

/* lnode helper for generating ogs_list_t nodes's of type TypedLocation */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_typed_location_make_lnode(data_collection_model_typed_location_t *typed_location);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_TYPED_LOCATION_H_ */

