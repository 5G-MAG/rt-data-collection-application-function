#ifndef _DATA_COLLECTION_NOTIFICATION_FLAG_H_
#define _DATA_COLLECTION_NOTIFICATION_FLAG_H_

/**********************************************************************************************************************************
 * NotificationFlag - Public C interface to the NotificationFlag object
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

#include "NotificationFlag_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_notification_flag_s data_collection_model_notification_flag_t;

typedef enum {
    DCM_NOTIFICATION_FLAG_NO_VAL,
    DCM_NOTIFICATION_FLAG_VAL_ACTIVATE,
    DCM_NOTIFICATION_FLAG_VAL_DEACTIVATE,
    DCM_NOTIFICATION_FLAG_VAL_RETRIEVAL,
    DCM_NOTIFICATION_FLAG_OTHER
} data_collection_model_notification_flag_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_create_copy(const data_collection_model_notification_flag_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_create_move(data_collection_model_notification_flag_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_copy(data_collection_model_notification_flag_t *notification_flag, const data_collection_model_notification_flag_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_move(data_collection_model_notification_flag_t *notification_flag, data_collection_model_notification_flag_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_notification_flag_free(data_collection_model_notification_flag_t *notification_flag);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_notification_flag_toJSON(const data_collection_model_notification_flag_t *notification_flag, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_t *data_collection_model_notification_flag_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_is_equal_to(const data_collection_model_notification_flag_t *notification_flag, const data_collection_model_notification_flag_t *other_notification_flag);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_is_not_set(const data_collection_model_notification_flag_t *notification_flag);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_is_non_standard(const data_collection_model_notification_flag_t *notification_flag);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_flag_e data_collection_model_notification_flag_get_enum(const data_collection_model_notification_flag_t *notification_flag);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_notification_flag_get_string(const data_collection_model_notification_flag_t *notification_flag);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_set_enum(data_collection_model_notification_flag_t *notification_flag, data_collection_model_notification_flag_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_flag_set_string(data_collection_model_notification_flag_t *notification_flag, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type NotificationFlag */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_notification_flag_make_lnode(data_collection_model_notification_flag_t *notification_flag);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NOTIFICATION_FLAG_H_ */

