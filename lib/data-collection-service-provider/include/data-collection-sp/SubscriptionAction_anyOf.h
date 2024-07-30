#ifndef _DATA_COLLECTION_SUBSCRIPTION_ACTION_ANY_OF_H_
#define _DATA_COLLECTION_SUBSCRIPTION_ACTION_ANY_OF_H_

/**********************************************************************************************************************************
 * SubscriptionAction_anyOf - Public C interface to the SubscriptionAction_anyOf object
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

typedef struct data_collection_model_subscription_action_any_of_s data_collection_model_subscription_action_any_of_t;

typedef enum {
    DCM_SUBSCRIPTION_ACTION_ANY_OF_NO_VAL,
    DCM_SUBSCRIPTION_ACTION_ANY_OF_VAL_CLOSE,
    DCM_SUBSCRIPTION_ACTION_ANY_OF_VAL_CONTINUE_WITH_MUTING,
    DCM_SUBSCRIPTION_ACTION_ANY_OF_VAL_CONTINUE_WITHOUT_MUTING
} data_collection_model_subscription_action_any_of_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_any_of_t *data_collection_model_subscription_action_any_of_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_any_of_t *data_collection_model_subscription_action_any_of_create_copy(const data_collection_model_subscription_action_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_any_of_t *data_collection_model_subscription_action_any_of_create_move(data_collection_model_subscription_action_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_any_of_t *data_collection_model_subscription_action_any_of_copy(data_collection_model_subscription_action_any_of_t *subscription_action_any_of, const data_collection_model_subscription_action_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_any_of_t *data_collection_model_subscription_action_any_of_move(data_collection_model_subscription_action_any_of_t *subscription_action_any_of, data_collection_model_subscription_action_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_subscription_action_any_of_free(data_collection_model_subscription_action_any_of_t *subscription_action_any_of);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_subscription_action_any_of_toJSON(const data_collection_model_subscription_action_any_of_t *subscription_action_any_of, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_any_of_t *data_collection_model_subscription_action_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_any_of_is_equal_to(const data_collection_model_subscription_action_any_of_t *subscription_action_any_of, const data_collection_model_subscription_action_any_of_t *other_subscription_action_any_of);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_any_of_is_not_set(const data_collection_model_subscription_action_any_of_t *subscription_action_any_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_subscription_action_any_of_e data_collection_model_subscription_action_any_of_get_enum(const data_collection_model_subscription_action_any_of_t *subscription_action_any_of);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_subscription_action_any_of_get_string(const data_collection_model_subscription_action_any_of_t *subscription_action_any_of);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_any_of_set_enum(data_collection_model_subscription_action_any_of_t *subscription_action_any_of, data_collection_model_subscription_action_any_of_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_subscription_action_any_of_set_string(data_collection_model_subscription_action_any_of_t *subscription_action_any_of, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type SubscriptionAction_anyOf */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_subscription_action_any_of_make_lnode(data_collection_model_subscription_action_any_of_t *subscription_action_any_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_SUBSCRIPTION_ACTION_ANY_OF_H_ */

