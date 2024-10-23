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

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP MutingExceptionInstructions object reference
 */
typedef struct data_collection_model_muting_exception_instructions_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_muting_exception_instructions_t;



/** Create a new MutingExceptionInstructions
 * \public \memberof data_collection_model_muting_exception_instructions_t
 * @return a new MutingExceptionInstructions object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_create();

/** Create a new copy of a MutingExceptionInstructions object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 * Creates a new copy of the given @a other object
 * @param other The MutingExceptionInstructions to copy.
 * @return a new MutingExceptionInstructions object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_create_copy(const data_collection_model_muting_exception_instructions_t *other);

/** Create a new reference of a MutingExceptionInstructions object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MutingExceptionInstructions to create a new reference to.
 * @return a new MutingExceptionInstructions object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_create_move(data_collection_model_muting_exception_instructions_t *other);

/** Copy the value of another MutingExceptionInstructions into this object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 * Copies the value of @a other {{classname} object into @a muting_exception_instructions.
 * @param muting_exception_instructions The MutingExceptionInstructions object to copy @a other into.
 * @param other The MutingExceptionInstructions to copy the value from.
 * @return @a muting_exception_instructions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_copy(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, const data_collection_model_muting_exception_instructions_t *other);

/** Move the value of another MutingExceptionInstructions into this object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 * Discards the current value of @a muting_exception_instructions and moves the value of @a other
 * into @a muting_exception_instructions. This will leave @a other as an empty reference.
 *
 * @param muting_exception_instructions The MutingExceptionInstructions object to move @a other into.
 * @param other The MutingExceptionInstructions to move the value from.
 *
 * @return @a muting_exception_instructions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_move(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, data_collection_model_muting_exception_instructions_t *other);

/** Delete a MutingExceptionInstructions object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 * Destroys the reference to the MutingExceptionInstructions object and frees the value of MutingExceptionInstructions if this is the last reference.
 *
 * @param muting_exception_instructions The MutingExceptionInstructions to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_muting_exception_instructions_free(data_collection_model_muting_exception_instructions_t *muting_exception_instructions);

/** Get a cJSON tree representation of a MutingExceptionInstructions
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * Create a cJSON tree representation of the MutingExceptionInstructions object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param muting_exception_instructions The MutingExceptionInstructions to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_muting_exception_instructions_toJSON(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions, bool as_request);

/** Parse a cJSON tree into a MutingExceptionInstructions object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * Attempts to interpret a cJSON tree as a MutingExceptionInstructions API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MutingExceptionInstructions object containing the value represented by the cJSON tree. On failure will return
 * `NULL` and will set @a error_reason, @a error_class and @a error_parameter output parameters to indicate the reason for the
 * failure. The @a error_reason, @a error_class and @a error_parameter strings must be freed using ogs_free().
 *
 * @param json The cJSON tree object to interpret.
 * @param as_request `true` to interpret the @a json as an API request or `false` for interpretation as an API response.
 * @param[out] error_reason On failure will be set to a new nul terminated string indicating the reason for the failure.
 * @param[out] error_class On failure will be set to the class name of the object where the failure happened if available or `NULL`.
 * @param[out] error_parameter On failure will be set to the JSON path of the field where the failure happened if available or
                               `NULL`.
 *
 * @return a new MutingExceptionInstructions object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MutingExceptionInstructions objects to see if they are equivalent
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param muting_exception_instructions The first MutingExceptionInstructions object to compare.
 * @param other_muting_exception_instructions The second MutingExceptionInstructions object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_muting_exception_instructions_is_equal_to(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions, const data_collection_model_muting_exception_instructions_t *other_muting_exception_instructions);


/** Check if the bufferedNotifs field of a MutingExceptionInstructions object is set
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * @param muting_exception_instructions The MutingExceptionInstructions object to examine.
 *
 * @return `true` if the optional bufferedNotifs field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_muting_exception_instructions_has_buffered_notifs(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions);


/** Get the value of the bufferedNotifs field of a MutingExceptionInstructions object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * @param muting_exception_instructions The MutingExceptionInstructions object to examine.
 *
 * @return the value current set for the bufferedNotifs field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_buffered_notifications_action_t* data_collection_model_muting_exception_instructions_get_buffered_notifs(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions);

/** Set the value of the bufferedNotifs field in a MutingExceptionInstructions object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * @param muting_exception_instructions The MutingExceptionInstructions object to set the field in.
 * @param p_buffered_notifs The value to copy into the MutingExceptionInstructions object.
 *
 * @return @a muting_exception_instructions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_buffered_notifs(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, const data_collection_model_buffered_notifications_action_t* p_buffered_notifs);

/** Move a value to the bufferedNotifs field in a MutingExceptionInstructions object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * @param muting_exception_instructions The MutingExceptionInstructions object to set the field in.
 * @param p_buffered_notifs The value to move into the MutingExceptionInstructions object.
 *
 * @return @a muting_exception_instructions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_buffered_notifs_move(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, data_collection_model_buffered_notifications_action_t* p_buffered_notifs);

/** Check if the subscription field of a MutingExceptionInstructions object is set
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * @param muting_exception_instructions The MutingExceptionInstructions object to examine.
 *
 * @return `true` if the optional subscription field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_muting_exception_instructions_has_subscription(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions);


/** Get the value of the subscription field of a MutingExceptionInstructions object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * @param muting_exception_instructions The MutingExceptionInstructions object to examine.
 *
 * @return the value current set for the subscription field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_subscription_action_t* data_collection_model_muting_exception_instructions_get_subscription(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions);

/** Set the value of the subscription field in a MutingExceptionInstructions object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * @param muting_exception_instructions The MutingExceptionInstructions object to set the field in.
 * @param p_subscription The value to copy into the MutingExceptionInstructions object.
 *
 * @return @a muting_exception_instructions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_subscription(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, const data_collection_model_subscription_action_t* p_subscription);

/** Move a value to the subscription field in a MutingExceptionInstructions object
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * @param muting_exception_instructions The MutingExceptionInstructions object to set the field in.
 * @param p_subscription The value to move into the MutingExceptionInstructions object.
 *
 * @return @a muting_exception_instructions.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_subscription_move(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, data_collection_model_subscription_action_t* p_subscription);

/** lnode helper for generating ogs_list_t nodes's of type MutingExceptionInstructions
 * \public \memberof data_collection_model_muting_exception_instructions_t
 *
 * Creates a new data_collection_lnode_t object containing the @a muting_exception_instructions object.
 * The @a muting_exception_instructions will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param muting_exception_instructions The MutingExceptionInstructions object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a muting_exception_instructions
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_muting_exception_instructions_make_lnode(data_collection_model_muting_exception_instructions_t *muting_exception_instructions);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MUTING_EXCEPTION_INSTRUCTIONS_H_ */

