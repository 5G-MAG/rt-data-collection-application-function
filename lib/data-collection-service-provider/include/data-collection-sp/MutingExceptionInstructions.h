#ifndef _DATA_COLLECTION_MUTING_EXCEPTION_INSTRUCTIONS_H_
#define _DATA_COLLECTION_MUTING_EXCEPTION_INSTRUCTIONS_H_

/**********************************************************************************************************************************
 * MutingExceptionInstructions - Public C interface to the MutingExceptionInstructions object
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

#include "SubscriptionAction.h"
#include "BufferedNotificationsAction.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_muting_exception_instructions_s data_collection_model_muting_exception_instructions_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_create_copy(const data_collection_model_muting_exception_instructions_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_create_move(data_collection_model_muting_exception_instructions_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_copy(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, const data_collection_model_muting_exception_instructions_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_move(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, data_collection_model_muting_exception_instructions_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_muting_exception_instructions_free(data_collection_model_muting_exception_instructions_t *muting_exception_instructions);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_muting_exception_instructions_toJSON(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_muting_exception_instructions_is_equal_to(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions, const data_collection_model_muting_exception_instructions_t *other_muting_exception_instructions);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_buffered_notifications_action_t* data_collection_model_muting_exception_instructions_get_buffered_notifs(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_buffered_notifs(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, const data_collection_model_buffered_notifications_action_t* p_buffered_notifs);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_buffered_notifs_move(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, data_collection_model_buffered_notifications_action_t* p_buffered_notifs);

DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_subscription_action_t* data_collection_model_muting_exception_instructions_get_subscription(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_subscription(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, const data_collection_model_subscription_action_t* p_subscription);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_subscription_move(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, data_collection_model_subscription_action_t* p_subscription);

/* lnode helper for generating ogs_list_t nodes's of type MutingExceptionInstructions */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_muting_exception_instructions_make_lnode(data_collection_model_muting_exception_instructions_t *muting_exception_instructions);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MUTING_EXCEPTION_INSTRUCTIONS_H_ */

