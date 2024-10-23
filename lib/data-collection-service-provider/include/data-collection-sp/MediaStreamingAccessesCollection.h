#ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESSES_COLLECTION_H_
#define _DATA_COLLECTION_MEDIA_STREAMING_ACCESSES_COLLECTION_H_

/**********************************************************************************************************************************
 * MediaStreamingAccessesCollection - Public C interface to the MediaStreamingAccessesCollection object
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

#include "DataAggregationFunctionType.h"
#include "ProvisioningSessionType.h"
#include "MediaStreamingAccessEvent.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP MediaStreamingAccessesCollection object reference
 */
typedef struct data_collection_model_media_streaming_accesses_collection_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_media_streaming_accesses_collection_t;



/** Create a new MediaStreamingAccessesCollection
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 * @return a new MediaStreamingAccessesCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_create();

/** Create a new copy of a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 * Creates a new copy of the given @a other object
 * @param other The MediaStreamingAccessesCollection to copy.
 * @return a new MediaStreamingAccessesCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_create_copy(const data_collection_model_media_streaming_accesses_collection_t *other);

/** Create a new reference of a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MediaStreamingAccessesCollection to create a new reference to.
 * @return a new MediaStreamingAccessesCollection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_create_move(data_collection_model_media_streaming_accesses_collection_t *other);

/** Copy the value of another MediaStreamingAccessesCollection into this object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 * Copies the value of @a other {{classname} object into @a media_streaming_accesses_collection.
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to copy @a other into.
 * @param other The MediaStreamingAccessesCollection to copy the value from.
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_copy(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const data_collection_model_media_streaming_accesses_collection_t *other);

/** Move the value of another MediaStreamingAccessesCollection into this object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 * Discards the current value of @a media_streaming_accesses_collection and moves the value of @a other
 * into @a media_streaming_accesses_collection. This will leave @a other as an empty reference.
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to move @a other into.
 * @param other The MediaStreamingAccessesCollection to move the value from.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_move(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, data_collection_model_media_streaming_accesses_collection_t *other);

/** Delete a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 * Destroys the reference to the MediaStreamingAccessesCollection object and frees the value of MediaStreamingAccessesCollection if this is the last reference.
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_accesses_collection_free(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);

/** Get a cJSON tree representation of a MediaStreamingAccessesCollection
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * Create a cJSON tree representation of the MediaStreamingAccessesCollection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_accesses_collection_toJSON(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, bool as_request);

/** Parse a cJSON tree into a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * Attempts to interpret a cJSON tree as a MediaStreamingAccessesCollection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MediaStreamingAccessesCollection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new MediaStreamingAccessesCollection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MediaStreamingAccessesCollection objects to see if they are equivalent
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param media_streaming_accesses_collection The first MediaStreamingAccessesCollection object to compare.
 * @param other_media_streaming_accesses_collection The second MediaStreamingAccessesCollection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_accesses_collection_is_equal_to(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const data_collection_model_media_streaming_accesses_collection_t *other_media_streaming_accesses_collection);



/** Get the value of the collectionTimestamp field of a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to examine.
 *
 * @return the value current set for the collectionTimestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_accesses_collection_get_collection_timestamp(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);

/** Set the value of the collectionTimestamp field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_collection_timestamp The value to copy into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_collection_timestamp(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const char* p_collection_timestamp);

/** Move a value to the collectionTimestamp field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_collection_timestamp The value to move into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_collection_timestamp_move(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, char* p_collection_timestamp);


/** Get the value of the startTimestamp field of a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to examine.
 *
 * @return the value current set for the startTimestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_accesses_collection_get_start_timestamp(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);

/** Set the value of the startTimestamp field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_start_timestamp The value to copy into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_start_timestamp(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const char* p_start_timestamp);

/** Move a value to the startTimestamp field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_start_timestamp The value to move into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_start_timestamp_move(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, char* p_start_timestamp);


/** Get the value of the endTimestamp field of a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to examine.
 *
 * @return the value current set for the endTimestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_accesses_collection_get_end_timestamp(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);

/** Set the value of the endTimestamp field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_end_timestamp The value to copy into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_end_timestamp(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const char* p_end_timestamp);

/** Move a value to the endTimestamp field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_end_timestamp The value to move into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_end_timestamp_move(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, char* p_end_timestamp);


/** Get the value of the sampleCount field of a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to examine.
 *
 * @return the value current set for the sampleCount field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_accesses_collection_get_sample_count(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);

/** Set the value of the sampleCount field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_sample_count The value to copy into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_sample_count(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const int32_t p_sample_count);

/** Move a value to the sampleCount field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_sample_count The value to move into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_sample_count_move(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, int32_t p_sample_count);


/** Get the value of the streamingDirection field of a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to examine.
 *
 * @return the value current set for the streamingDirection field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_provisioning_session_type_t* data_collection_model_media_streaming_accesses_collection_get_streaming_direction(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);

/** Set the value of the streamingDirection field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_streaming_direction The value to copy into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_streaming_direction(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const data_collection_model_provisioning_session_type_t* p_streaming_direction);

/** Move a value to the streamingDirection field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_streaming_direction The value to move into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_streaming_direction_move(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, data_collection_model_provisioning_session_type_t* p_streaming_direction);


/** Get the value of the summarisations field of a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to examine.
 *
 * @return the value current set for the summarisations field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_media_streaming_accesses_collection_get_summarisations(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);

/** Set the value of the summarisations field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_summarisations The value to copy into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_summarisations(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const ogs_list_t* p_summarisations);

/** Move a value to the summarisations field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_summarisations The value to move into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_summarisations_move(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, ogs_list_t* p_summarisations);

/** Add a new item to the summarisations array in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to add the array item to.
 * @param summarisations The value to add.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_add_summarisations(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, data_collection_model_data_aggregation_function_type_t* summarisations);

/** Remove an item from the summarisations array in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to remove the array value from.
 * @param summarisations The value to remove.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_remove_summarisations(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const data_collection_model_data_aggregation_function_type_t* summarisations);

/** Get an item from the summarisations array in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_aggregation_function_type_t* data_collection_model_media_streaming_accesses_collection_get_entry_summarisations(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, size_t idx);

/** Remove all entries from the summarisations array in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to empty summarisations for.
 *
 * @return @a media_streaming_accesses_collection
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_clear_summarisations(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);


/** Get the value of the records field of a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to examine.
 *
 * @return the value current set for the records field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_media_streaming_accesses_collection_get_records(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);

/** Set the value of the records field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_records The value to copy into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_records(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const ogs_list_t* p_records);

/** Move a value to the records field in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to set the field in.
 * @param p_records The value to move into the MediaStreamingAccessesCollection object.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_set_records_move(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, ogs_list_t* p_records);

/** Add a new item to the records array in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to add the array item to.
 * @param records The value to add.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_add_records(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, data_collection_model_media_streaming_access_event_t* records);

/** Remove an item from the records array in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to remove the array value from.
 * @param records The value to remove.
 *
 * @return @a media_streaming_accesses_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_remove_records(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, const data_collection_model_media_streaming_access_event_t* records);

/** Get an item from the records array in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_media_streaming_access_event_t* data_collection_model_media_streaming_accesses_collection_get_entry_records(const data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection, size_t idx);

/** Remove all entries from the records array in a MediaStreamingAccessesCollection object
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to empty records for.
 *
 * @return @a media_streaming_accesses_collection
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_accesses_collection_t *data_collection_model_media_streaming_accesses_collection_clear_records(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);

/** lnode helper for generating ogs_list_t nodes's of type MediaStreamingAccessesCollection
 * \public \memberof data_collection_model_media_streaming_accesses_collection_t
 *
 * Creates a new data_collection_lnode_t object containing the @a media_streaming_accesses_collection object.
 * The @a media_streaming_accesses_collection will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param media_streaming_accesses_collection The MediaStreamingAccessesCollection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a media_streaming_accesses_collection
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_accesses_collection_make_lnode(data_collection_model_media_streaming_accesses_collection_t *media_streaming_accesses_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESSES_COLLECTION_H_ */

