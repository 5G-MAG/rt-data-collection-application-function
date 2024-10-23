#ifndef _DATA_COLLECTION_APPLICATION_SPECIFIC_RECORD_H_
#define _DATA_COLLECTION_APPLICATION_SPECIFIC_RECORD_H_

/**********************************************************************************************************************************
 * ApplicationSpecificRecord - Public C interface to the ApplicationSpecificRecord object
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

#include "AnyType.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP ApplicationSpecificRecord object reference
 */
typedef struct data_collection_model_application_specific_record_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_application_specific_record_t;



/** Create a new ApplicationSpecificRecord
 * \public \memberof data_collection_model_application_specific_record_t
 * @return a new ApplicationSpecificRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_create();

/** Create a new copy of a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 * Creates a new copy of the given @a other object
 * @param other The ApplicationSpecificRecord to copy.
 * @return a new ApplicationSpecificRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_create_copy(const data_collection_model_application_specific_record_t *other);

/** Create a new reference of a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 * Creates a reference to the same underlying @a other object.
 * @param other The ApplicationSpecificRecord to create a new reference to.
 * @return a new ApplicationSpecificRecord object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_create_move(data_collection_model_application_specific_record_t *other);

/** Copy the value of another ApplicationSpecificRecord into this object
 * \public \memberof data_collection_model_application_specific_record_t
 * Copies the value of @a other {{classname} object into @a application_specific_record.
 * @param application_specific_record The ApplicationSpecificRecord object to copy @a other into.
 * @param other The ApplicationSpecificRecord to copy the value from.
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_copy(data_collection_model_application_specific_record_t *application_specific_record, const data_collection_model_application_specific_record_t *other);

/** Move the value of another ApplicationSpecificRecord into this object
 * \public \memberof data_collection_model_application_specific_record_t
 * Discards the current value of @a application_specific_record and moves the value of @a other
 * into @a application_specific_record. This will leave @a other as an empty reference.
 *
 * @param application_specific_record The ApplicationSpecificRecord object to move @a other into.
 * @param other The ApplicationSpecificRecord to move the value from.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_move(data_collection_model_application_specific_record_t *application_specific_record, data_collection_model_application_specific_record_t *other);

/** Delete a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 * Destroys the reference to the ApplicationSpecificRecord object and frees the value of ApplicationSpecificRecord if this is the last reference.
 *
 * @param application_specific_record The ApplicationSpecificRecord to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_application_specific_record_free(data_collection_model_application_specific_record_t *application_specific_record);

/** Get a cJSON tree representation of a ApplicationSpecificRecord
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * Create a cJSON tree representation of the ApplicationSpecificRecord object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param application_specific_record The ApplicationSpecificRecord to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_application_specific_record_toJSON(const data_collection_model_application_specific_record_t *application_specific_record, bool as_request);

/** Parse a cJSON tree into a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * Attempts to interpret a cJSON tree as a ApplicationSpecificRecord API request or response (dependent on @a as_request value). If successful
 * will return a new referenced ApplicationSpecificRecord object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new ApplicationSpecificRecord object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two ApplicationSpecificRecord objects to see if they are equivalent
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param application_specific_record The first ApplicationSpecificRecord object to compare.
 * @param other_application_specific_record The second ApplicationSpecificRecord object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_application_specific_record_is_equal_to(const data_collection_model_application_specific_record_t *application_specific_record, const data_collection_model_application_specific_record_t *other_application_specific_record);



/** Get the value of the timestamp field of a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to examine.
 *
 * @return the value current set for the timestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_application_specific_record_get_timestamp(const data_collection_model_application_specific_record_t *application_specific_record);

/** Set the value of the timestamp field in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to set the field in.
 * @param p_timestamp The value to copy into the ApplicationSpecificRecord object.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_timestamp(data_collection_model_application_specific_record_t *application_specific_record, const char* p_timestamp);

/** Move a value to the timestamp field in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to set the field in.
 * @param p_timestamp The value to move into the ApplicationSpecificRecord object.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_timestamp_move(data_collection_model_application_specific_record_t *application_specific_record, char* p_timestamp);


/** Get the value of the contextIds field of a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to examine.
 *
 * @return the value current set for the contextIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_application_specific_record_get_context_ids(const data_collection_model_application_specific_record_t *application_specific_record);

/** Set the value of the contextIds field in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to set the field in.
 * @param p_context_ids The value to copy into the ApplicationSpecificRecord object.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_context_ids(data_collection_model_application_specific_record_t *application_specific_record, const ogs_list_t* p_context_ids);

/** Move a value to the contextIds field in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to set the field in.
 * @param p_context_ids The value to move into the ApplicationSpecificRecord object.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_context_ids_move(data_collection_model_application_specific_record_t *application_specific_record, ogs_list_t* p_context_ids);

/** Add a new item to the contextIds array in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to add the array item to.
 * @param context_ids The value to add.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_add_context_ids(data_collection_model_application_specific_record_t *application_specific_record, char* context_ids);

/** Remove an item from the contextIds array in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to remove the array value from.
 * @param context_ids The value to remove.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_remove_context_ids(data_collection_model_application_specific_record_t *application_specific_record, const char* context_ids);

/** Get an item from the contextIds array in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_application_specific_record_get_entry_context_ids(const data_collection_model_application_specific_record_t *application_specific_record, size_t idx);

/** Remove all entries from the contextIds array in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to empty contextIds for.
 *
 * @return @a application_specific_record
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_clear_context_ids(data_collection_model_application_specific_record_t *application_specific_record);


/** Get the value of the recordType field of a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to examine.
 *
 * @return the value current set for the recordType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_application_specific_record_get_record_type(const data_collection_model_application_specific_record_t *application_specific_record);

/** Set the value of the recordType field in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to set the field in.
 * @param p_record_type The value to copy into the ApplicationSpecificRecord object.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_record_type(data_collection_model_application_specific_record_t *application_specific_record, const char* p_record_type);

/** Move a value to the recordType field in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to set the field in.
 * @param p_record_type The value to move into the ApplicationSpecificRecord object.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_record_type_move(data_collection_model_application_specific_record_t *application_specific_record, char* p_record_type);


/** Get the value of the recordContainer field of a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to examine.
 *
 * @return the value current set for the recordContainer field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_any_type_t* data_collection_model_application_specific_record_get_record_container(const data_collection_model_application_specific_record_t *application_specific_record);

/** Set the value of the recordContainer field in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to set the field in.
 * @param p_record_container The value to copy into the ApplicationSpecificRecord object.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_record_container(data_collection_model_application_specific_record_t *application_specific_record, const data_collection_model_any_type_t* p_record_container);

/** Move a value to the recordContainer field in a ApplicationSpecificRecord object
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * @param application_specific_record The ApplicationSpecificRecord object to set the field in.
 * @param p_record_container The value to move into the ApplicationSpecificRecord object.
 *
 * @return @a application_specific_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_application_specific_record_t *data_collection_model_application_specific_record_set_record_container_move(data_collection_model_application_specific_record_t *application_specific_record, data_collection_model_any_type_t* p_record_container);

/** lnode helper for generating ogs_list_t nodes's of type ApplicationSpecificRecord
 * \public \memberof data_collection_model_application_specific_record_t
 *
 * Creates a new data_collection_lnode_t object containing the @a application_specific_record object.
 * The @a application_specific_record will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param application_specific_record The ApplicationSpecificRecord object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a application_specific_record
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_application_specific_record_make_lnode(data_collection_model_application_specific_record_t *application_specific_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_APPLICATION_SPECIFIC_RECORD_H_ */

