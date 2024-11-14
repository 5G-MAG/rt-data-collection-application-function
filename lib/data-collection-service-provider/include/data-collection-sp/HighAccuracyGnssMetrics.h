#ifndef _DATA_COLLECTION_HIGH_ACCURACY_GNSS_METRICS_H_
#define _DATA_COLLECTION_HIGH_ACCURACY_GNSS_METRICS_H_

/**********************************************************************************************************************************
 * HighAccuracyGnssMetrics - Public C interface to the HighAccuracyGnssMetrics object
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

#include "FixType.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP HighAccuracyGnssMetrics object reference
 */
typedef struct data_collection_model_high_accuracy_gnss_metrics_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_high_accuracy_gnss_metrics_t;



/** Create a new HighAccuracyGnssMetrics.
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 * @return a new HighAccuracyGnssMetrics object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_create();

/** Create a new HighAccuracyGnssMetrics reference.
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The HighAccuracyGnssMetrics to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_create_ref(const data_collection_model_high_accuracy_gnss_metrics_t *other);

/** Create a new copy of a HighAccuracyGnssMetrics object.
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 * Creates a new copy of the given @a other object
 * @param other The HighAccuracyGnssMetrics to copy.
 * @return a new HighAccuracyGnssMetrics object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_create_copy(const data_collection_model_high_accuracy_gnss_metrics_t *other);

/** Create a new reference of a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 * Creates a reference to the same underlying @a other object.
 * @param other The HighAccuracyGnssMetrics to create a new reference to.
 * @return a new HighAccuracyGnssMetrics object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_create_move(data_collection_model_high_accuracy_gnss_metrics_t *other);

/** Copy the value of another HighAccuracyGnssMetrics into this object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 * Copies the value of @a other {{classname} object into @a high_accuracy_gnss_metrics.
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to copy @a other into.
 * @param other The HighAccuracyGnssMetrics to copy the value from.
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_copy(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const data_collection_model_high_accuracy_gnss_metrics_t *other);

/** Move the value of another HighAccuracyGnssMetrics into this object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 * Discards the current value of @a high_accuracy_gnss_metrics and moves the value of @a other
 * into @a high_accuracy_gnss_metrics. This will leave @a other as an empty reference.
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to move @a other into.
 * @param other The HighAccuracyGnssMetrics to move the value from.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, data_collection_model_high_accuracy_gnss_metrics_t *other);

/** Delete a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 * Destroys the reference to the HighAccuracyGnssMetrics object and frees the value of HighAccuracyGnssMetrics if this is the last reference.
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_high_accuracy_gnss_metrics_free(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

/** Get a cJSON tree representation of a HighAccuracyGnssMetrics
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * Create a cJSON tree representation of the HighAccuracyGnssMetrics object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_high_accuracy_gnss_metrics_toJSON(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, bool as_request);

/** Parse a cJSON tree into a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * Attempts to interpret a cJSON tree as a HighAccuracyGnssMetrics API request or response (dependent on @a as_request value). If successful
 * will return a new referenced HighAccuracyGnssMetrics object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new HighAccuracyGnssMetrics object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two HighAccuracyGnssMetrics objects to see if they are equivalent
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param high_accuracy_gnss_metrics The first HighAccuracyGnssMetrics object to compare.
 * @param other_high_accuracy_gnss_metrics The second HighAccuracyGnssMetrics object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_is_equal_to(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const data_collection_model_high_accuracy_gnss_metrics_t *other_high_accuracy_gnss_metrics);


/** Check if the nrOfUsedSatellites field of a HighAccuracyGnssMetrics object is set
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to examine.
 *
 * @return `true` if the optional nrOfUsedSatellites field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_has_nr_of_used_satellites(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);


/** Get the value of the nrOfUsedSatellites field of a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to examine.
 *
 * @return the value current set for the nrOfUsedSatellites field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_high_accuracy_gnss_metrics_get_nr_of_used_satellites(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

/** Set the value of the nrOfUsedSatellites field in a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to set the field in.
 * @param p_nr_of_used_satellites The value to copy into the HighAccuracyGnssMetrics object.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_nr_of_used_satellites(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const int32_t p_nr_of_used_satellites);

/** Move a value to the nrOfUsedSatellites field in a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to set the field in.
 * @param p_nr_of_used_satellites The value to move into the HighAccuracyGnssMetrics object.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_nr_of_used_satellites_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, int32_t p_nr_of_used_satellites);

/** Check if the hdopi field of a HighAccuracyGnssMetrics object is set
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to examine.
 *
 * @return `true` if the optional hdopi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_has_hdopi(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);


/** Get the value of the hdopi field of a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to examine.
 *
 * @return the value current set for the hdopi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_high_accuracy_gnss_metrics_get_hdopi(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

/** Set the value of the hdopi field in a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to set the field in.
 * @param p_hdopi The value to copy into the HighAccuracyGnssMetrics object.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_hdopi(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const int32_t p_hdopi);

/** Move a value to the hdopi field in a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to set the field in.
 * @param p_hdopi The value to move into the HighAccuracyGnssMetrics object.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_hdopi_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, int32_t p_hdopi);

/** Check if the pdopi field of a HighAccuracyGnssMetrics object is set
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to examine.
 *
 * @return `true` if the optional pdopi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_has_pdopi(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);


/** Get the value of the pdopi field of a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to examine.
 *
 * @return the value current set for the pdopi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_high_accuracy_gnss_metrics_get_pdopi(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

/** Set the value of the pdopi field in a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to set the field in.
 * @param p_pdopi The value to copy into the HighAccuracyGnssMetrics object.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_pdopi(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const int32_t p_pdopi);

/** Move a value to the pdopi field in a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to set the field in.
 * @param p_pdopi The value to move into the HighAccuracyGnssMetrics object.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_pdopi_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, int32_t p_pdopi);

/** Check if the age field of a HighAccuracyGnssMetrics object is set
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to examine.
 *
 * @return `true` if the optional age field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_has_age(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);


/** Get the value of the age field of a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to examine.
 *
 * @return the value current set for the age field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_high_accuracy_gnss_metrics_get_age(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

/** Set the value of the age field in a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to set the field in.
 * @param p_age The value to copy into the HighAccuracyGnssMetrics object.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_age(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const int32_t p_age);

/** Move a value to the age field in a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to set the field in.
 * @param p_age The value to move into the HighAccuracyGnssMetrics object.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_age_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, int32_t p_age);

/** Check if the fixType field of a HighAccuracyGnssMetrics object is set
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to examine.
 *
 * @return `true` if the optional fixType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_has_fix_type(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);


/** Get the value of the fixType field of a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to examine.
 *
 * @return the value current set for the fixType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_fix_type_t* data_collection_model_high_accuracy_gnss_metrics_get_fix_type(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

/** Set the value of the fixType field in a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to set the field in.
 * @param p_fix_type The value to copy into the HighAccuracyGnssMetrics object.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_fix_type(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const data_collection_model_fix_type_t* p_fix_type);

/** Move a value to the fixType field in a HighAccuracyGnssMetrics object
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to set the field in.
 * @param p_fix_type The value to move into the HighAccuracyGnssMetrics object.
 *
 * @return @a high_accuracy_gnss_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_fix_type_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, data_collection_model_fix_type_t* p_fix_type);

/** lnode helper for generating ogs_list_t nodes's of type HighAccuracyGnssMetrics
 * \public \memberof data_collection_model_high_accuracy_gnss_metrics_t
 *
 * Creates a new data_collection_lnode_t object containing the @a high_accuracy_gnss_metrics object.
 * The @a high_accuracy_gnss_metrics will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param high_accuracy_gnss_metrics The HighAccuracyGnssMetrics object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a high_accuracy_gnss_metrics
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_high_accuracy_gnss_metrics_make_lnode(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_HIGH_ACCURACY_GNSS_METRICS_H_ */

