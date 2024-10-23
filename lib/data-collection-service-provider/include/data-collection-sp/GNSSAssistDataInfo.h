#ifndef _DATA_COLLECTION_GNSS_ASSIST_DATA_INFO_H_
#define _DATA_COLLECTION_GNSS_ASSIST_DATA_INFO_H_

/**********************************************************************************************************************************
 * GNSSAssistDataInfo - Public C interface to the GNSSAssistDataInfo object
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

#include "GeographicalCoordinates.h"
#include "GNSSServArea.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP GNSSAssistDataInfo object reference
 */
typedef struct data_collection_model_gnss_assist_data_info_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_gnss_assist_data_info_t;



/** Create a new GNSSAssistDataInfo
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 * @return a new GNSSAssistDataInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create();

/** Create a new copy of a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 * Creates a new copy of the given @a other object
 * @param other The GNSSAssistDataInfo to copy.
 * @return a new GNSSAssistDataInfo object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create_copy(const data_collection_model_gnss_assist_data_info_t *other);

/** Create a new reference of a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 * Creates a reference to the same underlying @a other object.
 * @param other The GNSSAssistDataInfo to create a new reference to.
 * @return a new GNSSAssistDataInfo object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create_move(data_collection_model_gnss_assist_data_info_t *other);

/** Copy the value of another GNSSAssistDataInfo into this object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 * Copies the value of @a other {{classname} object into @a gnss_assist_data_info.
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to copy @a other into.
 * @param other The GNSSAssistDataInfo to copy the value from.
 * @return @a gnss_assist_data_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_copy(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const data_collection_model_gnss_assist_data_info_t *other);

/** Move the value of another GNSSAssistDataInfo into this object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 * Discards the current value of @a gnss_assist_data_info and moves the value of @a other
 * into @a gnss_assist_data_info. This will leave @a other as an empty reference.
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to move @a other into.
 * @param other The GNSSAssistDataInfo to move the value from.
 *
 * @return @a gnss_assist_data_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_move(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, data_collection_model_gnss_assist_data_info_t *other);

/** Delete a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 * Destroys the reference to the GNSSAssistDataInfo object and frees the value of GNSSAssistDataInfo if this is the last reference.
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnss_assist_data_info_free(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);

/** Get a cJSON tree representation of a GNSSAssistDataInfo
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * Create a cJSON tree representation of the GNSSAssistDataInfo object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnss_assist_data_info_toJSON(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, bool as_request);

/** Parse a cJSON tree into a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * Attempts to interpret a cJSON tree as a GNSSAssistDataInfo API request or response (dependent on @a as_request value). If successful
 * will return a new referenced GNSSAssistDataInfo object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new GNSSAssistDataInfo object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two GNSSAssistDataInfo objects to see if they are equivalent
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param gnss_assist_data_info The first GNSSAssistDataInfo object to compare.
 * @param other_gnss_assist_data_info The second GNSSAssistDataInfo object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_assist_data_info_is_equal_to(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const data_collection_model_gnss_assist_data_info_t *other_gnss_assist_data_info);



/** Get the value of the gnssAssistData field of a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to examine.
 *
 * @return the value current set for the gnssAssistData field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_gnss_assist_data_info_get_gnss_assist_data(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);

/** Set the value of the gnssAssistData field in a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to set the field in.
 * @param p_gnss_assist_data The value to copy into the GNSSAssistDataInfo object.
 *
 * @return @a gnss_assist_data_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_gnss_assist_data(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const char* p_gnss_assist_data);

/** Move a value to the gnssAssistData field in a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to set the field in.
 * @param p_gnss_assist_data The value to move into the GNSSAssistDataInfo object.
 *
 * @return @a gnss_assist_data_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_gnss_assist_data_move(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, char* p_gnss_assist_data);


/** Get the value of the servArea field of a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to examine.
 *
 * @return the value current set for the servArea field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_gnss_serv_area_t* data_collection_model_gnss_assist_data_info_get_serv_area(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);

/** Set the value of the servArea field in a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to set the field in.
 * @param p_serv_area The value to copy into the GNSSAssistDataInfo object.
 *
 * @return @a gnss_assist_data_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_serv_area(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const data_collection_model_gnss_serv_area_t* p_serv_area);

/** Move a value to the servArea field in a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to set the field in.
 * @param p_serv_area The value to move into the GNSSAssistDataInfo object.
 *
 * @return @a gnss_assist_data_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_serv_area_move(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, data_collection_model_gnss_serv_area_t* p_serv_area);

/** Check if the sourceInfo field of a GNSSAssistDataInfo object is set
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to examine.
 *
 * @return `true` if the optional sourceInfo field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_assist_data_info_has_source_info(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);


/** Get the value of the sourceInfo field of a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to examine.
 *
 * @return the value current set for the sourceInfo field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_gnss_assist_data_info_get_source_info(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);

/** Set the value of the sourceInfo field in a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to set the field in.
 * @param p_source_info The value to copy into the GNSSAssistDataInfo object.
 *
 * @return @a gnss_assist_data_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_source_info(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const data_collection_model_geographical_coordinates_t* p_source_info);

/** Move a value to the sourceInfo field in a GNSSAssistDataInfo object
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to set the field in.
 * @param p_source_info The value to move into the GNSSAssistDataInfo object.
 *
 * @return @a gnss_assist_data_info.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_source_info_move(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, data_collection_model_geographical_coordinates_t* p_source_info);

/** lnode helper for generating ogs_list_t nodes's of type GNSSAssistDataInfo
 * \public \memberof data_collection_model_gnss_assist_data_info_t
 *
 * Creates a new data_collection_lnode_t object containing the @a gnss_assist_data_info object.
 * The @a gnss_assist_data_info will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param gnss_assist_data_info The GNSSAssistDataInfo object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a gnss_assist_data_info
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnss_assist_data_info_make_lnode(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GNSS_ASSIST_DATA_INFO_H_ */

