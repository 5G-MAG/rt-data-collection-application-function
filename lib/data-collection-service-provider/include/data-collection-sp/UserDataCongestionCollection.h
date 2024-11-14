#ifndef _DATA_COLLECTION_USER_DATA_CONGESTION_COLLECTION_H_
#define _DATA_COLLECTION_USER_DATA_CONGESTION_COLLECTION_H_

/**********************************************************************************************************************************
 * UserDataCongestionCollection - Public C interface to the UserDataCongestionCollection object
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

#include "FlowInfo.h"
#include "TimeWindow.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP UserDataCongestionCollection object reference
 */
typedef struct data_collection_model_user_data_congestion_collection_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_user_data_congestion_collection_t;



/** Create a new UserDataCongestionCollection.
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 * @return a new UserDataCongestionCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_create();

/** Create a new UserDataCongestionCollection reference.
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The UserDataCongestionCollection to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_create_ref(const data_collection_model_user_data_congestion_collection_t *other);

/** Create a new copy of a UserDataCongestionCollection object.
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 * Creates a new copy of the given @a other object
 * @param other The UserDataCongestionCollection to copy.
 * @return a new UserDataCongestionCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_create_copy(const data_collection_model_user_data_congestion_collection_t *other);

/** Create a new reference of a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 * Creates a reference to the same underlying @a other object.
 * @param other The UserDataCongestionCollection to create a new reference to.
 * @return a new UserDataCongestionCollection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_create_move(data_collection_model_user_data_congestion_collection_t *other);

/** Copy the value of another UserDataCongestionCollection into this object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 * Copies the value of @a other {{classname} object into @a user_data_congestion_collection.
 * @param user_data_congestion_collection The UserDataCongestionCollection object to copy @a other into.
 * @param other The UserDataCongestionCollection to copy the value from.
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_copy(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const data_collection_model_user_data_congestion_collection_t *other);

/** Move the value of another UserDataCongestionCollection into this object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 * Discards the current value of @a user_data_congestion_collection and moves the value of @a other
 * into @a user_data_congestion_collection. This will leave @a other as an empty reference.
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to move @a other into.
 * @param other The UserDataCongestionCollection to move the value from.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, data_collection_model_user_data_congestion_collection_t *other);

/** Delete a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 * Destroys the reference to the UserDataCongestionCollection object and frees the value of UserDataCongestionCollection if this is the last reference.
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_user_data_congestion_collection_free(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

/** Get a cJSON tree representation of a UserDataCongestionCollection
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * Create a cJSON tree representation of the UserDataCongestionCollection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_user_data_congestion_collection_toJSON(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, bool as_request);

/** Parse a cJSON tree into a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * Attempts to interpret a cJSON tree as a UserDataCongestionCollection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced UserDataCongestionCollection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new UserDataCongestionCollection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two UserDataCongestionCollection objects to see if they are equivalent
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param user_data_congestion_collection The first UserDataCongestionCollection object to compare.
 * @param other_user_data_congestion_collection The second UserDataCongestionCollection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_user_data_congestion_collection_is_equal_to(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const data_collection_model_user_data_congestion_collection_t *other_user_data_congestion_collection);


/** Check if the appId field of a UserDataCongestionCollection object is set
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return `true` if the optional appId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_user_data_congestion_collection_has_app_id(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);


/** Get the value of the appId field of a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return the value current set for the appId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_user_data_congestion_collection_get_app_id(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

/** Set the value of the appId field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_app_id The value to copy into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_app_id(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const char* p_app_id);

/** Move a value to the appId field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_app_id The value to move into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_app_id_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, char* p_app_id);

/** Check if the ipTrafficFilter field of a UserDataCongestionCollection object is set
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return `true` if the optional ipTrafficFilter field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_user_data_congestion_collection_has_ip_traffic_filter(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);


/** Get the value of the ipTrafficFilter field of a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return the value current set for the ipTrafficFilter field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_flow_info_t* data_collection_model_user_data_congestion_collection_get_ip_traffic_filter(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

/** Set the value of the ipTrafficFilter field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_ip_traffic_filter The value to copy into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_ip_traffic_filter(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const data_collection_model_flow_info_t* p_ip_traffic_filter);

/** Move a value to the ipTrafficFilter field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_ip_traffic_filter The value to move into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_ip_traffic_filter_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, data_collection_model_flow_info_t* p_ip_traffic_filter);

/** Check if the timeInterv field of a UserDataCongestionCollection object is set
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return `true` if the optional timeInterv field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_user_data_congestion_collection_has_time_interv(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);


/** Get the value of the timeInterv field of a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return the value current set for the timeInterv field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_user_data_congestion_collection_get_time_interv(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

/** Set the value of the timeInterv field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_time_interv The value to copy into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_time_interv(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const data_collection_model_time_window_t* p_time_interv);

/** Move a value to the timeInterv field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_time_interv The value to move into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_time_interv_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, data_collection_model_time_window_t* p_time_interv);

/** Check if the thrputUl field of a UserDataCongestionCollection object is set
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return `true` if the optional thrputUl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_user_data_congestion_collection_has_thrput_ul(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);


/** Get the value of the thrputUl field of a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return the value current set for the thrputUl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_user_data_congestion_collection_get_thrput_ul(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

/** Set the value of the thrputUl field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_thrput_ul The value to copy into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_ul(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const char* p_thrput_ul);

/** Move a value to the thrputUl field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_thrput_ul The value to move into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_ul_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, char* p_thrput_ul);

/** Check if the thrputDl field of a UserDataCongestionCollection object is set
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return `true` if the optional thrputDl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_user_data_congestion_collection_has_thrput_dl(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);


/** Get the value of the thrputDl field of a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return the value current set for the thrputDl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_user_data_congestion_collection_get_thrput_dl(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

/** Set the value of the thrputDl field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_thrput_dl The value to copy into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_dl(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const char* p_thrput_dl);

/** Move a value to the thrputDl field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_thrput_dl The value to move into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_dl_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, char* p_thrput_dl);

/** Check if the thrputPkUl field of a UserDataCongestionCollection object is set
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return `true` if the optional thrputPkUl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_user_data_congestion_collection_has_thrput_pk_ul(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);


/** Get the value of the thrputPkUl field of a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return the value current set for the thrputPkUl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_user_data_congestion_collection_get_thrput_pk_ul(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

/** Set the value of the thrputPkUl field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_thrput_pk_ul The value to copy into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_ul(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const char* p_thrput_pk_ul);

/** Move a value to the thrputPkUl field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_thrput_pk_ul The value to move into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_ul_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, char* p_thrput_pk_ul);

/** Check if the thrputPkDl field of a UserDataCongestionCollection object is set
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return `true` if the optional thrputPkDl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_user_data_congestion_collection_has_thrput_pk_dl(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);


/** Get the value of the thrputPkDl field of a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to examine.
 *
 * @return the value current set for the thrputPkDl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_user_data_congestion_collection_get_thrput_pk_dl(const data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

/** Set the value of the thrputPkDl field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_thrput_pk_dl The value to copy into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_dl(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, const char* p_thrput_pk_dl);

/** Move a value to the thrputPkDl field in a UserDataCongestionCollection object
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to set the field in.
 * @param p_thrput_pk_dl The value to move into the UserDataCongestionCollection object.
 *
 * @return @a user_data_congestion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_user_data_congestion_collection_t *data_collection_model_user_data_congestion_collection_set_thrput_pk_dl_move(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection, char* p_thrput_pk_dl);

/** lnode helper for generating ogs_list_t nodes's of type UserDataCongestionCollection
 * \public \memberof data_collection_model_user_data_congestion_collection_t
 *
 * Creates a new data_collection_lnode_t object containing the @a user_data_congestion_collection object.
 * The @a user_data_congestion_collection will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param user_data_congestion_collection The UserDataCongestionCollection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a user_data_congestion_collection
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_user_data_congestion_collection_make_lnode(data_collection_model_user_data_congestion_collection_t *user_data_congestion_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_USER_DATA_CONGESTION_COLLECTION_H_ */

