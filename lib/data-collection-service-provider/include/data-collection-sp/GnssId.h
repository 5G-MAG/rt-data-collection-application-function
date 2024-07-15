#ifndef _DATA_COLLECTION_GNSS_ID_H_
#define _DATA_COLLECTION_GNSS_ID_H_

/**********************************************************************************************************************************
 * GnssId - Public C interface to the GnssId object
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

#include "GnssId_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_gnss_id_s data_collection_model_gnss_id_t;

typedef enum {
    DCM_GNSS_ID_NO_VAL,
    DCM_GNSS_ID_VAL_GPS,
    DCM_GNSS_ID_VAL_GALILEO,
    DCM_GNSS_ID_VAL_SBAS,
    DCM_GNSS_ID_VAL_MODERNIZED_GPS,
    DCM_GNSS_ID_VAL_QZSS,
    DCM_GNSS_ID_VAL_GLONASS,
    DCM_GNSS_ID_VAL_BDS,
    DCM_GNSS_ID_VAL_NAVIC,
    DCM_GNSS_ID_OTHER
} data_collection_model_gnss_id_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_create_copy(const data_collection_model_gnss_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_create_move(data_collection_model_gnss_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_copy(data_collection_model_gnss_id_t *gnss_id, const data_collection_model_gnss_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_move(data_collection_model_gnss_id_t *gnss_id, data_collection_model_gnss_id_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnss_id_free(data_collection_model_gnss_id_t *gnss_id);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnss_id_toJSON(const data_collection_model_gnss_id_t *gnss_id, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_id_is_not_set(const data_collection_model_gnss_id_t *gnss_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_id_is_non_standard(const data_collection_model_gnss_id_t *gnss_id);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_e data_collection_model_gnss_id_get_enum(const data_collection_model_gnss_id_t *gnss_id);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_gnss_id_get_string(const data_collection_model_gnss_id_t *gnss_id);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_id_set_enum(data_collection_model_gnss_id_t *gnss_id, data_collection_model_gnss_id_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_id_set_string(data_collection_model_gnss_id_t *gnss_id, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type GnssId */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnss_id_make_lnode(data_collection_model_gnss_id_t *gnss_id);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GNSS_ID_H_ */

