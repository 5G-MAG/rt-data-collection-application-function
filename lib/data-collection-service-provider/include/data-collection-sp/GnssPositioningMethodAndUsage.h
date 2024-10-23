#ifndef _DATA_COLLECTION_GNSS_POSITIONING_METHOD_AND_USAGE_H_
#define _DATA_COLLECTION_GNSS_POSITIONING_METHOD_AND_USAGE_H_

/**********************************************************************************************************************************
 * GnssPositioningMethodAndUsage - Public C interface to the GnssPositioningMethodAndUsage object
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

#include "Usage.h"
#include "GnssId.h"
#include "PositioningMode.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP GnssPositioningMethodAndUsage object reference
 */
typedef struct data_collection_model_gnss_positioning_method_and_usage_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_gnss_positioning_method_and_usage_t;



/** Create a new GnssPositioningMethodAndUsage
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 * @return a new GnssPositioningMethodAndUsage object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_create();

/** Create a new copy of a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 * Creates a new copy of the given @a other object
 * @param other The GnssPositioningMethodAndUsage to copy.
 * @return a new GnssPositioningMethodAndUsage object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_create_copy(const data_collection_model_gnss_positioning_method_and_usage_t *other);

/** Create a new reference of a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 * Creates a reference to the same underlying @a other object.
 * @param other The GnssPositioningMethodAndUsage to create a new reference to.
 * @return a new GnssPositioningMethodAndUsage object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_create_move(data_collection_model_gnss_positioning_method_and_usage_t *other);

/** Copy the value of another GnssPositioningMethodAndUsage into this object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 * Copies the value of @a other {{classname} object into @a gnss_positioning_method_and_usage.
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to copy @a other into.
 * @param other The GnssPositioningMethodAndUsage to copy the value from.
 * @return @a gnss_positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_copy(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, const data_collection_model_gnss_positioning_method_and_usage_t *other);

/** Move the value of another GnssPositioningMethodAndUsage into this object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 * Discards the current value of @a gnss_positioning_method_and_usage and moves the value of @a other
 * into @a gnss_positioning_method_and_usage. This will leave @a other as an empty reference.
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to move @a other into.
 * @param other The GnssPositioningMethodAndUsage to move the value from.
 *
 * @return @a gnss_positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_move(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, data_collection_model_gnss_positioning_method_and_usage_t *other);

/** Delete a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 * Destroys the reference to the GnssPositioningMethodAndUsage object and frees the value of GnssPositioningMethodAndUsage if this is the last reference.
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnss_positioning_method_and_usage_free(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage);

/** Get a cJSON tree representation of a GnssPositioningMethodAndUsage
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * Create a cJSON tree representation of the GnssPositioningMethodAndUsage object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnss_positioning_method_and_usage_toJSON(const data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, bool as_request);

/** Parse a cJSON tree into a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * Attempts to interpret a cJSON tree as a GnssPositioningMethodAndUsage API request or response (dependent on @a as_request value). If successful
 * will return a new referenced GnssPositioningMethodAndUsage object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new GnssPositioningMethodAndUsage object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two GnssPositioningMethodAndUsage objects to see if they are equivalent
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param gnss_positioning_method_and_usage The first GnssPositioningMethodAndUsage object to compare.
 * @param other_gnss_positioning_method_and_usage The second GnssPositioningMethodAndUsage object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_positioning_method_and_usage_is_equal_to(const data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, const data_collection_model_gnss_positioning_method_and_usage_t *other_gnss_positioning_method_and_usage);



/** Get the value of the mode field of a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to examine.
 *
 * @return the value current set for the mode field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_positioning_mode_t* data_collection_model_gnss_positioning_method_and_usage_get_mode(const data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage);

/** Set the value of the mode field in a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to set the field in.
 * @param p_mode The value to copy into the GnssPositioningMethodAndUsage object.
 *
 * @return @a gnss_positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_mode(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, const data_collection_model_positioning_mode_t* p_mode);

/** Move a value to the mode field in a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to set the field in.
 * @param p_mode The value to move into the GnssPositioningMethodAndUsage object.
 *
 * @return @a gnss_positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_mode_move(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, data_collection_model_positioning_mode_t* p_mode);


/** Get the value of the gnss field of a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to examine.
 *
 * @return the value current set for the gnss field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_gnss_id_t* data_collection_model_gnss_positioning_method_and_usage_get_gnss(const data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage);

/** Set the value of the gnss field in a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to set the field in.
 * @param p_gnss The value to copy into the GnssPositioningMethodAndUsage object.
 *
 * @return @a gnss_positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_gnss(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, const data_collection_model_gnss_id_t* p_gnss);

/** Move a value to the gnss field in a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to set the field in.
 * @param p_gnss The value to move into the GnssPositioningMethodAndUsage object.
 *
 * @return @a gnss_positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_gnss_move(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, data_collection_model_gnss_id_t* p_gnss);


/** Get the value of the usage field of a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to examine.
 *
 * @return the value current set for the usage field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_usage_t* data_collection_model_gnss_positioning_method_and_usage_get_usage(const data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage);

/** Set the value of the usage field in a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to set the field in.
 * @param p_usage The value to copy into the GnssPositioningMethodAndUsage object.
 *
 * @return @a gnss_positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_usage(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, const data_collection_model_usage_t* p_usage);

/** Move a value to the usage field in a GnssPositioningMethodAndUsage object
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to set the field in.
 * @param p_usage The value to move into the GnssPositioningMethodAndUsage object.
 *
 * @return @a gnss_positioning_method_and_usage.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_usage_move(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, data_collection_model_usage_t* p_usage);

/** lnode helper for generating ogs_list_t nodes's of type GnssPositioningMethodAndUsage
 * \public \memberof data_collection_model_gnss_positioning_method_and_usage_t
 *
 * Creates a new data_collection_lnode_t object containing the @a gnss_positioning_method_and_usage object.
 * The @a gnss_positioning_method_and_usage will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param gnss_positioning_method_and_usage The GnssPositioningMethodAndUsage object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a gnss_positioning_method_and_usage
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnss_positioning_method_and_usage_make_lnode(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_GNSS_POSITIONING_METHOD_AND_USAGE_H_ */

