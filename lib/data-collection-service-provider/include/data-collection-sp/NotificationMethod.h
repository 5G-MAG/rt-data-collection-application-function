#ifndef _DATA_COLLECTION_NOTIFICATION_METHOD_H_
#define _DATA_COLLECTION_NOTIFICATION_METHOD_H_

/**********************************************************************************************************************************
 * NotificationMethod - Public C interface to the NotificationMethod object
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

#include "NotificationMethod_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_notification_method_s data_collection_model_notification_method_t;

typedef enum {
    DCM_NOTIFICATION_METHOD_NO_VAL,
    DCM_NOTIFICATION_METHOD_VAL_PERIODIC,
    DCM_NOTIFICATION_METHOD_VAL_ONE_TIME,
    DCM_NOTIFICATION_METHOD_VAL_ON_EVENT_DETECTION,
    DCM_NOTIFICATION_METHOD_OTHER
} data_collection_model_notification_method_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_create_copy(const data_collection_model_notification_method_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_create_move(data_collection_model_notification_method_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_copy(data_collection_model_notification_method_t *notification_method, const data_collection_model_notification_method_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_move(data_collection_model_notification_method_t *notification_method, data_collection_model_notification_method_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_notification_method_free(data_collection_model_notification_method_t *notification_method);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_notification_method_toJSON(const data_collection_model_notification_method_t *notification_method, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_t *data_collection_model_notification_method_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_method_is_equal_to(const data_collection_model_notification_method_t *notification_method, const data_collection_model_notification_method_t *other_notification_method);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_method_is_not_set(const data_collection_model_notification_method_t *notification_method);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_method_is_non_standard(const data_collection_model_notification_method_t *notification_method);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_notification_method_e data_collection_model_notification_method_get_enum(const data_collection_model_notification_method_t *notification_method);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_notification_method_get_string(const data_collection_model_notification_method_t *notification_method);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_method_set_enum(data_collection_model_notification_method_t *notification_method, data_collection_model_notification_method_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_notification_method_set_string(data_collection_model_notification_method_t *notification_method, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type NotificationMethod */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_notification_method_make_lnode(data_collection_model_notification_method_t *notification_method);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NOTIFICATION_METHOD_H_ */

