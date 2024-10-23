#ifndef _DATA_COLLECTION_UE_COMMUNICATION_COLLECTION_H_
#define _DATA_COLLECTION_UE_COMMUNICATION_COLLECTION_H_

/**********************************************************************************************************************************
 * UeCommunicationCollection - Public C interface to the UeCommunicationCollection object
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

#include "CpParameterSet.h"
#include "CommunicationCollection.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP UeCommunicationCollection object reference
 */
typedef struct data_collection_model_ue_communication_collection_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ue_communication_collection_t;



/** Create a new UeCommunicationCollection
 * \public \memberof data_collection_model_ue_communication_collection_t
 * @return a new UeCommunicationCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_create();

/** Create a new copy of a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 * Creates a new copy of the given @a other object
 * @param other The UeCommunicationCollection to copy.
 * @return a new UeCommunicationCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_create_copy(const data_collection_model_ue_communication_collection_t *other);

/** Create a new reference of a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 * Creates a reference to the same underlying @a other object.
 * @param other The UeCommunicationCollection to create a new reference to.
 * @return a new UeCommunicationCollection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_create_move(data_collection_model_ue_communication_collection_t *other);

/** Copy the value of another UeCommunicationCollection into this object
 * \public \memberof data_collection_model_ue_communication_collection_t
 * Copies the value of @a other {{classname} object into @a ue_communication_collection.
 * @param ue_communication_collection The UeCommunicationCollection object to copy @a other into.
 * @param other The UeCommunicationCollection to copy the value from.
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_copy(data_collection_model_ue_communication_collection_t *ue_communication_collection, const data_collection_model_ue_communication_collection_t *other);

/** Move the value of another UeCommunicationCollection into this object
 * \public \memberof data_collection_model_ue_communication_collection_t
 * Discards the current value of @a ue_communication_collection and moves the value of @a other
 * into @a ue_communication_collection. This will leave @a other as an empty reference.
 *
 * @param ue_communication_collection The UeCommunicationCollection object to move @a other into.
 * @param other The UeCommunicationCollection to move the value from.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, data_collection_model_ue_communication_collection_t *other);

/** Delete a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 * Destroys the reference to the UeCommunicationCollection object and frees the value of UeCommunicationCollection if this is the last reference.
 *
 * @param ue_communication_collection The UeCommunicationCollection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_communication_collection_free(data_collection_model_ue_communication_collection_t *ue_communication_collection);

/** Get a cJSON tree representation of a UeCommunicationCollection
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * Create a cJSON tree representation of the UeCommunicationCollection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ue_communication_collection The UeCommunicationCollection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_communication_collection_toJSON(const data_collection_model_ue_communication_collection_t *ue_communication_collection, bool as_request);

/** Parse a cJSON tree into a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * Attempts to interpret a cJSON tree as a UeCommunicationCollection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced UeCommunicationCollection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new UeCommunicationCollection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two UeCommunicationCollection objects to see if they are equivalent
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ue_communication_collection The first UeCommunicationCollection object to compare.
 * @param other_ue_communication_collection The second UeCommunicationCollection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_is_equal_to(const data_collection_model_ue_communication_collection_t *ue_communication_collection, const data_collection_model_ue_communication_collection_t *other_ue_communication_collection);


/** Check if the gpsi field of a UeCommunicationCollection object is set
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return `true` if the optional gpsi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_gpsi(const data_collection_model_ue_communication_collection_t *ue_communication_collection);


/** Get the value of the gpsi field of a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return the value current set for the gpsi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_gpsi(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

/** Set the value of the gpsi field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_gpsi The value to copy into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_gpsi(data_collection_model_ue_communication_collection_t *ue_communication_collection, const char* p_gpsi);

/** Move a value to the gpsi field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_gpsi The value to move into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_gpsi_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, char* p_gpsi);

/** Check if the supi field of a UeCommunicationCollection object is set
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return `true` if the optional supi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_supi(const data_collection_model_ue_communication_collection_t *ue_communication_collection);


/** Get the value of the supi field of a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return the value current set for the supi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_supi(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

/** Set the value of the supi field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_supi The value to copy into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_supi(data_collection_model_ue_communication_collection_t *ue_communication_collection, const char* p_supi);

/** Move a value to the supi field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_supi The value to move into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_supi_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, char* p_supi);

/** Check if the exterGroupId field of a UeCommunicationCollection object is set
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return `true` if the optional exterGroupId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_exter_group_id(const data_collection_model_ue_communication_collection_t *ue_communication_collection);


/** Get the value of the exterGroupId field of a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return the value current set for the exterGroupId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_exter_group_id(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

/** Set the value of the exterGroupId field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_exter_group_id The value to copy into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_exter_group_id(data_collection_model_ue_communication_collection_t *ue_communication_collection, const char* p_exter_group_id);

/** Move a value to the exterGroupId field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_exter_group_id The value to move into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_exter_group_id_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, char* p_exter_group_id);

/** Check if the interGroupId field of a UeCommunicationCollection object is set
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return `true` if the optional interGroupId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_inter_group_id(const data_collection_model_ue_communication_collection_t *ue_communication_collection);


/** Get the value of the interGroupId field of a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return the value current set for the interGroupId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_inter_group_id(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

/** Set the value of the interGroupId field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_inter_group_id The value to copy into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_inter_group_id(data_collection_model_ue_communication_collection_t *ue_communication_collection, const char* p_inter_group_id);

/** Move a value to the interGroupId field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_inter_group_id The value to move into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_inter_group_id_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, char* p_inter_group_id);


/** Get the value of the appId field of a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return the value current set for the appId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_communication_collection_get_app_id(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

/** Set the value of the appId field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_app_id The value to copy into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_app_id(data_collection_model_ue_communication_collection_t *ue_communication_collection, const char* p_app_id);

/** Move a value to the appId field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_app_id The value to move into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_app_id_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, char* p_app_id);

/** Check if the expectedUeBehavePara field of a UeCommunicationCollection object is set
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return `true` if the optional expectedUeBehavePara field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_communication_collection_has_expected_ue_behave_para(const data_collection_model_ue_communication_collection_t *ue_communication_collection);


/** Get the value of the expectedUeBehavePara field of a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return the value current set for the expectedUeBehavePara field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cp_parameter_set_t* data_collection_model_ue_communication_collection_get_expected_ue_behave_para(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

/** Set the value of the expectedUeBehavePara field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_expected_ue_behave_para The value to copy into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_expected_ue_behave_para(data_collection_model_ue_communication_collection_t *ue_communication_collection, const data_collection_model_cp_parameter_set_t* p_expected_ue_behave_para);

/** Move a value to the expectedUeBehavePara field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_expected_ue_behave_para The value to move into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_expected_ue_behave_para_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, data_collection_model_cp_parameter_set_t* p_expected_ue_behave_para);


/** Get the value of the comms field of a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 *
 * @return the value current set for the comms field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ue_communication_collection_get_comms(const data_collection_model_ue_communication_collection_t *ue_communication_collection);

/** Set the value of the comms field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_comms The value to copy into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_comms(data_collection_model_ue_communication_collection_t *ue_communication_collection, const ogs_list_t* p_comms);

/** Move a value to the comms field in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to set the field in.
 * @param p_comms The value to move into the UeCommunicationCollection object.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_set_comms_move(data_collection_model_ue_communication_collection_t *ue_communication_collection, ogs_list_t* p_comms);

/** Add a new item to the comms array in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to add the array item to.
 * @param comms The value to add.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_add_comms(data_collection_model_ue_communication_collection_t *ue_communication_collection, data_collection_model_communication_collection_t* comms);

/** Remove an item from the comms array in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to remove the array value from.
 * @param comms The value to remove.
 *
 * @return @a ue_communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_remove_comms(data_collection_model_ue_communication_collection_t *ue_communication_collection, const data_collection_model_communication_collection_t* comms);

/** Get an item from the comms array in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_communication_collection_t* data_collection_model_ue_communication_collection_get_entry_comms(const data_collection_model_ue_communication_collection_t *ue_communication_collection, size_t idx);

/** Remove all entries from the comms array in a UeCommunicationCollection object
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * @param ue_communication_collection The UeCommunicationCollection object to empty comms for.
 *
 * @return @a ue_communication_collection
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_communication_collection_t *data_collection_model_ue_communication_collection_clear_comms(data_collection_model_ue_communication_collection_t *ue_communication_collection);

/** lnode helper for generating ogs_list_t nodes's of type UeCommunicationCollection
 * \public \memberof data_collection_model_ue_communication_collection_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ue_communication_collection object.
 * The @a ue_communication_collection will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ue_communication_collection The UeCommunicationCollection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ue_communication_collection
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_communication_collection_make_lnode(data_collection_model_ue_communication_collection_t *ue_communication_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UE_COMMUNICATION_COLLECTION_H_ */

