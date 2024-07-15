#ifndef _DATA_COLLECTION_ANY_TYPE_H_
#define _DATA_COLLECTION_ANY_TYPE_H_

/**********************************************************************************************************************************
 * IpAddr - Public C interface to the IpAddr object
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

#include "Ipv6Prefix.h"
#include "Ipv6Addr.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_any_type_s data_collection_model_any_type_t;

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_any_type_t *data_collection_model_any_type_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_any_type_t *data_collection_model_any_type_create_copy(const data_collection_model_any_type_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_any_type_t *data_collection_model_any_type_create_move(const data_collection_model_any_type_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_any_type_t *data_collection_model_any_type_copy(data_collection_model_any_type_t *any_type, const data_collection_model_any_type_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_any_type_t *data_collection_model_any_type_move(data_collection_model_any_type_t *any_type, const data_collection_model_any_type_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_any_type_free(data_collection_model_any_type_t *any_type);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_any_type_toJSON(const data_collection_model_any_type_t *any_type, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_any_type_t *data_collection_model_any_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ANY_TYPE_H_ */

