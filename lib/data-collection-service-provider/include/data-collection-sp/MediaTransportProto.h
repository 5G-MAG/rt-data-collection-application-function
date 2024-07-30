#ifndef _DATA_COLLECTION_MEDIA_TRANSPORT_PROTO_H_
#define _DATA_COLLECTION_MEDIA_TRANSPORT_PROTO_H_

/**********************************************************************************************************************************
 * MediaTransportProto - Public C interface to the MediaTransportProto object
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

#include "MediaTransportProto_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_media_transport_proto_s data_collection_model_media_transport_proto_t;

typedef enum {
    DCM_MEDIA_TRANSPORT_PROTO_NO_VAL,
    DCM_MEDIA_TRANSPORT_PROTO_VAL_RTP,
    DCM_MEDIA_TRANSPORT_PROTO_VAL_SRTP,
    DCM_MEDIA_TRANSPORT_PROTO_OTHER
} data_collection_model_media_transport_proto_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_create_copy(const data_collection_model_media_transport_proto_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_create_move(data_collection_model_media_transport_proto_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_copy(data_collection_model_media_transport_proto_t *media_transport_proto, const data_collection_model_media_transport_proto_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_move(data_collection_model_media_transport_proto_t *media_transport_proto, data_collection_model_media_transport_proto_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_transport_proto_free(data_collection_model_media_transport_proto_t *media_transport_proto);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_transport_proto_toJSON(const data_collection_model_media_transport_proto_t *media_transport_proto, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_t *data_collection_model_media_transport_proto_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_is_equal_to(const data_collection_model_media_transport_proto_t *media_transport_proto, const data_collection_model_media_transport_proto_t *other_media_transport_proto);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_is_not_set(const data_collection_model_media_transport_proto_t *media_transport_proto);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_is_non_standard(const data_collection_model_media_transport_proto_t *media_transport_proto);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_transport_proto_e data_collection_model_media_transport_proto_get_enum(const data_collection_model_media_transport_proto_t *media_transport_proto);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_media_transport_proto_get_string(const data_collection_model_media_transport_proto_t *media_transport_proto);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_set_enum(data_collection_model_media_transport_proto_t *media_transport_proto, data_collection_model_media_transport_proto_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_transport_proto_set_string(data_collection_model_media_transport_proto_t *media_transport_proto, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type MediaTransportProto */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_transport_proto_make_lnode(data_collection_model_media_transport_proto_t *media_transport_proto);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_TRANSPORT_PROTO_H_ */

