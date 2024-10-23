#ifndef _DATA_COLLECTION_COMMUNICATION_COLLECTION_H_
#define _DATA_COLLECTION_COMMUNICATION_COLLECTION_H_

/**********************************************************************************************************************************
 * CommunicationCollection - Public C interface to the CommunicationCollection object
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

/** A 3GPP CommunicationCollection object reference
 */
typedef struct data_collection_model_communication_collection_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_communication_collection_t;



/** Create a new CommunicationCollection
 * \public \memberof data_collection_model_communication_collection_t
 * @return a new CommunicationCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_create();

/** Create a new copy of a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 * Creates a new copy of the given @a other object
 * @param other The CommunicationCollection to copy.
 * @return a new CommunicationCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_create_copy(const data_collection_model_communication_collection_t *other);

/** Create a new reference of a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 * Creates a reference to the same underlying @a other object.
 * @param other The CommunicationCollection to create a new reference to.
 * @return a new CommunicationCollection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_create_move(data_collection_model_communication_collection_t *other);

/** Copy the value of another CommunicationCollection into this object
 * \public \memberof data_collection_model_communication_collection_t
 * Copies the value of @a other {{classname} object into @a communication_collection.
 * @param communication_collection The CommunicationCollection object to copy @a other into.
 * @param other The CommunicationCollection to copy the value from.
 * @return @a communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_copy(data_collection_model_communication_collection_t *communication_collection, const data_collection_model_communication_collection_t *other);

/** Move the value of another CommunicationCollection into this object
 * \public \memberof data_collection_model_communication_collection_t
 * Discards the current value of @a communication_collection and moves the value of @a other
 * into @a communication_collection. This will leave @a other as an empty reference.
 *
 * @param communication_collection The CommunicationCollection object to move @a other into.
 * @param other The CommunicationCollection to move the value from.
 *
 * @return @a communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_move(data_collection_model_communication_collection_t *communication_collection, data_collection_model_communication_collection_t *other);

/** Delete a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 * Destroys the reference to the CommunicationCollection object and frees the value of CommunicationCollection if this is the last reference.
 *
 * @param communication_collection The CommunicationCollection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_communication_collection_free(data_collection_model_communication_collection_t *communication_collection);

/** Get a cJSON tree representation of a CommunicationCollection
 * \public \memberof data_collection_model_communication_collection_t
 *
 * Create a cJSON tree representation of the CommunicationCollection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param communication_collection The CommunicationCollection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_communication_collection_toJSON(const data_collection_model_communication_collection_t *communication_collection, bool as_request);

/** Parse a cJSON tree into a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * Attempts to interpret a cJSON tree as a CommunicationCollection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced CommunicationCollection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new CommunicationCollection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two CommunicationCollection objects to see if they are equivalent
 * \public \memberof data_collection_model_communication_collection_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param communication_collection The first CommunicationCollection object to compare.
 * @param other_communication_collection The second CommunicationCollection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_collection_is_equal_to(const data_collection_model_communication_collection_t *communication_collection, const data_collection_model_communication_collection_t *other_communication_collection);



/** Get the value of the startTime field of a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to examine.
 *
 * @return the value current set for the startTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_collection_get_start_time(const data_collection_model_communication_collection_t *communication_collection);

/** Set the value of the startTime field in a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to set the field in.
 * @param p_start_time The value to copy into the CommunicationCollection object.
 *
 * @return @a communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_start_time(data_collection_model_communication_collection_t *communication_collection, const char* p_start_time);

/** Move a value to the startTime field in a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to set the field in.
 * @param p_start_time The value to move into the CommunicationCollection object.
 *
 * @return @a communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_start_time_move(data_collection_model_communication_collection_t *communication_collection, char* p_start_time);


/** Get the value of the endTime field of a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to examine.
 *
 * @return the value current set for the endTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_communication_collection_get_end_time(const data_collection_model_communication_collection_t *communication_collection);

/** Set the value of the endTime field in a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to set the field in.
 * @param p_end_time The value to copy into the CommunicationCollection object.
 *
 * @return @a communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_end_time(data_collection_model_communication_collection_t *communication_collection, const char* p_end_time);

/** Move a value to the endTime field in a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to set the field in.
 * @param p_end_time The value to move into the CommunicationCollection object.
 *
 * @return @a communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_end_time_move(data_collection_model_communication_collection_t *communication_collection, char* p_end_time);


/** Get the value of the ulVol field of a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to examine.
 *
 * @return the value current set for the ulVol field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_collection_get_ul_vol(const data_collection_model_communication_collection_t *communication_collection);

/** Set the value of the ulVol field in a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to set the field in.
 * @param p_ul_vol The value to copy into the CommunicationCollection object.
 *
 * @return @a communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_ul_vol(data_collection_model_communication_collection_t *communication_collection, const int64_t p_ul_vol);

/** Move a value to the ulVol field in a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to set the field in.
 * @param p_ul_vol The value to move into the CommunicationCollection object.
 *
 * @return @a communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_ul_vol_move(data_collection_model_communication_collection_t *communication_collection, int64_t p_ul_vol);


/** Get the value of the dlVol field of a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to examine.
 *
 * @return the value current set for the dlVol field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_communication_collection_get_dl_vol(const data_collection_model_communication_collection_t *communication_collection);

/** Set the value of the dlVol field in a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to set the field in.
 * @param p_dl_vol The value to copy into the CommunicationCollection object.
 *
 * @return @a communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_dl_vol(data_collection_model_communication_collection_t *communication_collection, const int64_t p_dl_vol);

/** Move a value to the dlVol field in a CommunicationCollection object
 * \public \memberof data_collection_model_communication_collection_t
 *
 * @param communication_collection The CommunicationCollection object to set the field in.
 * @param p_dl_vol The value to move into the CommunicationCollection object.
 *
 * @return @a communication_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_dl_vol_move(data_collection_model_communication_collection_t *communication_collection, int64_t p_dl_vol);

/** lnode helper for generating ogs_list_t nodes's of type CommunicationCollection
 * \public \memberof data_collection_model_communication_collection_t
 *
 * Creates a new data_collection_lnode_t object containing the @a communication_collection object.
 * The @a communication_collection will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param communication_collection The CommunicationCollection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a communication_collection
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_communication_collection_make_lnode(data_collection_model_communication_collection_t *communication_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_COMMUNICATION_COLLECTION_H_ */

