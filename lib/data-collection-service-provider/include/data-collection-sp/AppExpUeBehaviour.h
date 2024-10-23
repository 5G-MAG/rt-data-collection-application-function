#ifndef _DATA_COLLECTION_APP_EXP_UE_BEHAVIOUR_H_
#define _DATA_COLLECTION_APP_EXP_UE_BEHAVIOUR_H_

/**********************************************************************************************************************************
 * AppExpUeBehaviour - Public C interface to the AppExpUeBehaviour object
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

#include "TimeWindow.h"
#include "CpFailureCode.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP AppExpUeBehaviour object reference
 */
typedef struct data_collection_model_app_exp_ue_behaviour_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_app_exp_ue_behaviour_t;



/** Create a new AppExpUeBehaviour
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 * @return a new AppExpUeBehaviour object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create();

/** Create a new copy of a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 * Creates a new copy of the given @a other object
 * @param other The AppExpUeBehaviour to copy.
 * @return a new AppExpUeBehaviour object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create_copy(const data_collection_model_app_exp_ue_behaviour_t *other);

/** Create a new reference of a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 * Creates a reference to the same underlying @a other object.
 * @param other The AppExpUeBehaviour to create a new reference to.
 * @return a new AppExpUeBehaviour object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_create_move(data_collection_model_app_exp_ue_behaviour_t *other);

/** Copy the value of another AppExpUeBehaviour into this object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 * Copies the value of @a other {{classname} object into @a app_exp_ue_behaviour.
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to copy @a other into.
 * @param other The AppExpUeBehaviour to copy the value from.
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_copy(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const data_collection_model_app_exp_ue_behaviour_t *other);

/** Move the value of another AppExpUeBehaviour into this object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 * Discards the current value of @a app_exp_ue_behaviour and moves the value of @a other
 * into @a app_exp_ue_behaviour. This will leave @a other as an empty reference.
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to move @a other into.
 * @param other The AppExpUeBehaviour to move the value from.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, data_collection_model_app_exp_ue_behaviour_t *other);

/** Delete a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 * Destroys the reference to the AppExpUeBehaviour object and frees the value of AppExpUeBehaviour if this is the last reference.
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_app_exp_ue_behaviour_free(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/** Get a cJSON tree representation of a AppExpUeBehaviour
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * Create a cJSON tree representation of the AppExpUeBehaviour object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_app_exp_ue_behaviour_toJSON(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, bool as_request);

/** Parse a cJSON tree into a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * Attempts to interpret a cJSON tree as a AppExpUeBehaviour API request or response (dependent on @a as_request value). If successful
 * will return a new referenced AppExpUeBehaviour object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new AppExpUeBehaviour object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two AppExpUeBehaviour objects to see if they are equivalent
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param app_exp_ue_behaviour The first AppExpUeBehaviour object to compare.
 * @param other_app_exp_ue_behaviour The second AppExpUeBehaviour object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_is_equal_to(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const data_collection_model_app_exp_ue_behaviour_t *other_app_exp_ue_behaviour);


/** Check if the appId field of a AppExpUeBehaviour object is set
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return `true` if the optional appId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_app_id(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);


/** Get the value of the appId field of a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return the value current set for the appId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_app_id(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/** Set the value of the appId field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_app_id The value to copy into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_app_id(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const char* p_app_id);

/** Move a value to the appId field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_app_id The value to move into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_app_id_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, char* p_app_id);

/** Check if the expPduSesInacTm field of a AppExpUeBehaviour object is set
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return `true` if the optional expPduSesInacTm field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_exp_pdu_ses_inac_tm(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);


/** Get the value of the expPduSesInacTm field of a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return the value current set for the expPduSesInacTm field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_app_exp_ue_behaviour_get_exp_pdu_ses_inac_tm(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/** Set the value of the expPduSesInacTm field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_exp_pdu_ses_inac_tm The value to copy into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_exp_pdu_ses_inac_tm(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const data_collection_model_time_window_t* p_exp_pdu_ses_inac_tm);

/** Move a value to the expPduSesInacTm field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_exp_pdu_ses_inac_tm The value to move into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_exp_pdu_ses_inac_tm_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, data_collection_model_time_window_t* p_exp_pdu_ses_inac_tm);

/** Check if the flowDescriptions field of a AppExpUeBehaviour object is set
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return `true` if the optional flowDescriptions field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_flow_descriptions(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);


/** Get the value of the flowDescriptions field of a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return the value current set for the flowDescriptions field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_app_exp_ue_behaviour_get_flow_descriptions(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/** Set the value of the flowDescriptions field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_flow_descriptions The value to copy into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const ogs_list_t* p_flow_descriptions);

/** Move a value to the flowDescriptions field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_flow_descriptions The value to move into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_flow_descriptions_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, ogs_list_t* p_flow_descriptions);

/** Add a new item to the flowDescriptions array in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to add the array item to.
 * @param flow_descriptions The value to add.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_add_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, char* flow_descriptions);

/** Remove an item from the flowDescriptions array in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to remove the array value from.
 * @param flow_descriptions The value to remove.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_remove_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const char* flow_descriptions);

/** Get an item from the flowDescriptions array in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_entry_flow_descriptions(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, size_t idx);

/** Remove all entries from the flowDescriptions array in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to empty flowDescriptions for.
 *
 * @return @a app_exp_ue_behaviour
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_clear_flow_descriptions(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/** Check if the confidenceLevel field of a AppExpUeBehaviour object is set
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return `true` if the optional confidenceLevel field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_confidence_level(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);


/** Get the value of the confidenceLevel field of a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return the value current set for the confidenceLevel field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_confidence_level(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/** Set the value of the confidenceLevel field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_confidence_level The value to copy into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_confidence_level(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const char* p_confidence_level);

/** Move a value to the confidenceLevel field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_confidence_level The value to move into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_confidence_level_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, char* p_confidence_level);

/** Check if the accuracyLevel field of a AppExpUeBehaviour object is set
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return `true` if the optional accuracyLevel field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_accuracy_level(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);


/** Get the value of the accuracyLevel field of a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return the value current set for the accuracyLevel field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_accuracy_level(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/** Set the value of the accuracyLevel field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_accuracy_level The value to copy into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_accuracy_level(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const char* p_accuracy_level);

/** Move a value to the accuracyLevel field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_accuracy_level The value to move into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_accuracy_level_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, char* p_accuracy_level);

/** Check if the failureCode field of a AppExpUeBehaviour object is set
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return `true` if the optional failureCode field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_failure_code(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);


/** Get the value of the failureCode field of a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return the value current set for the failureCode field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cp_failure_code_t* data_collection_model_app_exp_ue_behaviour_get_failure_code(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/** Set the value of the failureCode field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_failure_code The value to copy into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_failure_code(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const data_collection_model_cp_failure_code_t* p_failure_code);

/** Move a value to the failureCode field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_failure_code The value to move into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_failure_code_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, data_collection_model_cp_failure_code_t* p_failure_code);

/** Check if the validityTime field of a AppExpUeBehaviour object is set
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return `true` if the optional validityTime field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_app_exp_ue_behaviour_has_validity_time(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);


/** Get the value of the validityTime field of a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to examine.
 *
 * @return the value current set for the validityTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_app_exp_ue_behaviour_get_validity_time(const data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/** Set the value of the validityTime field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_validity_time The value to copy into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_validity_time(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, const char* p_validity_time);

/** Move a value to the validityTime field in a AppExpUeBehaviour object
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to set the field in.
 * @param p_validity_time The value to move into the AppExpUeBehaviour object.
 *
 * @return @a app_exp_ue_behaviour.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_app_exp_ue_behaviour_t *data_collection_model_app_exp_ue_behaviour_set_validity_time_move(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour, char* p_validity_time);

/** lnode helper for generating ogs_list_t nodes's of type AppExpUeBehaviour
 * \public \memberof data_collection_model_app_exp_ue_behaviour_t
 *
 * Creates a new data_collection_lnode_t object containing the @a app_exp_ue_behaviour object.
 * The @a app_exp_ue_behaviour will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param app_exp_ue_behaviour The AppExpUeBehaviour object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a app_exp_ue_behaviour
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_app_exp_ue_behaviour_make_lnode(data_collection_model_app_exp_ue_behaviour_t *app_exp_ue_behaviour);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_APP_EXP_UE_BEHAVIOUR_H_ */

