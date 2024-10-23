#ifndef _DATA_COLLECTION_BASE_RECORD_H_
#define _DATA_COLLECTION_BASE_RECORD_H_

/**********************************************************************************************************************************
 * BaseRecord - Public C interface to the BaseRecord object
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


/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP BaseRecord object reference
 */
typedef struct data_collection_model_base_record_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_base_record_t;



/** Create a new BaseRecord
 * \public \memberof data_collection_model_base_record_t
 * @return a new BaseRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_create();

/** Create a new copy of a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 * Creates a new copy of the given @a other object
 * @param other The BaseRecord to copy.
 * @return a new BaseRecord object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_create_copy(const data_collection_model_base_record_t *other);

/** Create a new reference of a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 * Creates a reference to the same underlying @a other object.
 * @param other The BaseRecord to create a new reference to.
 * @return a new BaseRecord object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_create_move(data_collection_model_base_record_t *other);

/** Copy the value of another BaseRecord into this object
 * \public \memberof data_collection_model_base_record_t
 * Copies the value of @a other {{classname} object into @a base_record.
 * @param base_record The BaseRecord object to copy @a other into.
 * @param other The BaseRecord to copy the value from.
 * @return @a base_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_copy(data_collection_model_base_record_t *base_record, const data_collection_model_base_record_t *other);

/** Move the value of another BaseRecord into this object
 * \public \memberof data_collection_model_base_record_t
 * Discards the current value of @a base_record and moves the value of @a other
 * into @a base_record. This will leave @a other as an empty reference.
 *
 * @param base_record The BaseRecord object to move @a other into.
 * @param other The BaseRecord to move the value from.
 *
 * @return @a base_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_move(data_collection_model_base_record_t *base_record, data_collection_model_base_record_t *other);

/** Delete a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 * Destroys the reference to the BaseRecord object and frees the value of BaseRecord if this is the last reference.
 *
 * @param base_record The BaseRecord to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_base_record_free(data_collection_model_base_record_t *base_record);

/** Get a cJSON tree representation of a BaseRecord
 * \public \memberof data_collection_model_base_record_t
 *
 * Create a cJSON tree representation of the BaseRecord object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param base_record The BaseRecord to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_base_record_toJSON(const data_collection_model_base_record_t *base_record, bool as_request);

/** Parse a cJSON tree into a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * Attempts to interpret a cJSON tree as a BaseRecord API request or response (dependent on @a as_request value). If successful
 * will return a new referenced BaseRecord object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new BaseRecord object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two BaseRecord objects to see if they are equivalent
 * \public \memberof data_collection_model_base_record_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param base_record The first BaseRecord object to compare.
 * @param other_base_record The second BaseRecord object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_record_is_equal_to(const data_collection_model_base_record_t *base_record, const data_collection_model_base_record_t *other_base_record);



/** Get the value of the timestamp field of a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * @param base_record The BaseRecord object to examine.
 *
 * @return the value current set for the timestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_record_get_timestamp(const data_collection_model_base_record_t *base_record);

/** Set the value of the timestamp field in a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * @param base_record The BaseRecord object to set the field in.
 * @param p_timestamp The value to copy into the BaseRecord object.
 *
 * @return @a base_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_timestamp(data_collection_model_base_record_t *base_record, const char* p_timestamp);

/** Move a value to the timestamp field in a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * @param base_record The BaseRecord object to set the field in.
 * @param p_timestamp The value to move into the BaseRecord object.
 *
 * @return @a base_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_timestamp_move(data_collection_model_base_record_t *base_record, char* p_timestamp);


/** Get the value of the contextIds field of a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * @param base_record The BaseRecord object to examine.
 *
 * @return the value current set for the contextIds field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_base_record_get_context_ids(const data_collection_model_base_record_t *base_record);

/** Set the value of the contextIds field in a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * @param base_record The BaseRecord object to set the field in.
 * @param p_context_ids The value to copy into the BaseRecord object.
 *
 * @return @a base_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_context_ids(data_collection_model_base_record_t *base_record, const ogs_list_t* p_context_ids);

/** Move a value to the contextIds field in a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * @param base_record The BaseRecord object to set the field in.
 * @param p_context_ids The value to move into the BaseRecord object.
 *
 * @return @a base_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_context_ids_move(data_collection_model_base_record_t *base_record, ogs_list_t* p_context_ids);

/** Add a new item to the contextIds array in a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * @param base_record The BaseRecord object to add the array item to.
 * @param context_ids The value to add.
 *
 * @return @a base_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_add_context_ids(data_collection_model_base_record_t *base_record, char* context_ids);

/** Remove an item from the contextIds array in a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * @param base_record The BaseRecord object to remove the array value from.
 * @param context_ids The value to remove.
 *
 * @return @a base_record.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_remove_context_ids(data_collection_model_base_record_t *base_record, const char* context_ids);

/** Get an item from the contextIds array in a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * @param base_record The BaseRecord object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_record_get_entry_context_ids(const data_collection_model_base_record_t *base_record, size_t idx);

/** Remove all entries from the contextIds array in a BaseRecord object
 * \public \memberof data_collection_model_base_record_t
 *
 * @param base_record The BaseRecord object to empty contextIds for.
 *
 * @return @a base_record
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_clear_context_ids(data_collection_model_base_record_t *base_record);

/** lnode helper for generating ogs_list_t nodes's of type BaseRecord
 * \public \memberof data_collection_model_base_record_t
 *
 * Creates a new data_collection_lnode_t object containing the @a base_record object.
 * The @a base_record will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param base_record The BaseRecord object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a base_record
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_base_record_make_lnode(data_collection_model_base_record_t *base_record);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_BASE_RECORD_H_ */

