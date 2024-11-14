#ifndef _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_SAMPLES_H_
#define _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_SAMPLES_H_

/**********************************************************************************************************************************
 * QoEMetricsEvent_allOf_samples - Public C interface to the QoEMetricsEvent_allOf_samples object
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

#include "QoEMetricsEvent_allOf_metrics.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP QoEMetricsEvent_allOf_samples object reference
 */
typedef struct data_collection_model_qo_e_metrics_event_all_of_samples_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_qo_e_metrics_event_all_of_samples_t;



/** Create a new QoEMetricsEvent_allOf_samples.
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 * @return a new QoEMetricsEvent_allOf_samples object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_create();

/** Create a new QoEMetricsEvent_allOf_samples reference.
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The QoEMetricsEvent_allOf_samples to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_create_ref(const data_collection_model_qo_e_metrics_event_all_of_samples_t *other);

/** Create a new copy of a QoEMetricsEvent_allOf_samples object.
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 * Creates a new copy of the given @a other object
 * @param other The QoEMetricsEvent_allOf_samples to copy.
 * @return a new QoEMetricsEvent_allOf_samples object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_create_copy(const data_collection_model_qo_e_metrics_event_all_of_samples_t *other);

/** Create a new reference of a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 * Creates a reference to the same underlying @a other object.
 * @param other The QoEMetricsEvent_allOf_samples to create a new reference to.
 * @return a new QoEMetricsEvent_allOf_samples object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_create_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *other);

/** Copy the value of another QoEMetricsEvent_allOf_samples into this object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 * Copies the value of @a other {{classname} object into @a qo_e_metrics_event_all_of_samples.
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to copy @a other into.
 * @param other The QoEMetricsEvent_allOf_samples to copy the value from.
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_copy(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const data_collection_model_qo_e_metrics_event_all_of_samples_t *other);

/** Move the value of another QoEMetricsEvent_allOf_samples into this object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 * Discards the current value of @a qo_e_metrics_event_all_of_samples and moves the value of @a other
 * into @a qo_e_metrics_event_all_of_samples. This will leave @a other as an empty reference.
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to move @a other into.
 * @param other The QoEMetricsEvent_allOf_samples to move the value from.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, data_collection_model_qo_e_metrics_event_all_of_samples_t *other);

/** Delete a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 * Destroys the reference to the QoEMetricsEvent_allOf_samples object and frees the value of QoEMetricsEvent_allOf_samples if this is the last reference.
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_qo_e_metrics_event_all_of_samples_free(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

/** Get a cJSON tree representation of a QoEMetricsEvent_allOf_samples
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * Create a cJSON tree representation of the QoEMetricsEvent_allOf_samples object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_qo_e_metrics_event_all_of_samples_toJSON(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, bool as_request);

/** Parse a cJSON tree into a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * Attempts to interpret a cJSON tree as a QoEMetricsEvent_allOf_samples API request or response (dependent on @a as_request value). If successful
 * will return a new referenced QoEMetricsEvent_allOf_samples object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new QoEMetricsEvent_allOf_samples object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two QoEMetricsEvent_allOf_samples objects to see if they are equivalent
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param qo_e_metrics_event_all_of_samples The first QoEMetricsEvent_allOf_samples object to compare.
 * @param other_qo_e_metrics_event_all_of_samples The second QoEMetricsEvent_allOf_samples object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_all_of_samples_is_equal_to(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const data_collection_model_qo_e_metrics_event_all_of_samples_t *other_qo_e_metrics_event_all_of_samples);


/** Check if the sampleTimestamp field of a QoEMetricsEvent_allOf_samples object is set
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to examine.
 *
 * @return `true` if the optional sampleTimestamp field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_all_of_samples_has_sample_timestamp(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);


/** Get the value of the sampleTimestamp field of a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to examine.
 *
 * @return the value current set for the sampleTimestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_all_of_samples_get_sample_timestamp(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

/** Set the value of the sampleTimestamp field in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to set the field in.
 * @param p_sample_timestamp The value to copy into the QoEMetricsEvent_allOf_samples object.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_timestamp(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const char* p_sample_timestamp);

/** Move a value to the sampleTimestamp field in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to set the field in.
 * @param p_sample_timestamp The value to move into the QoEMetricsEvent_allOf_samples object.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_timestamp_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, char* p_sample_timestamp);

/** Check if the sampleDuration field of a QoEMetricsEvent_allOf_samples object is set
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to examine.
 *
 * @return `true` if the optional sampleDuration field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_all_of_samples_has_sample_duration(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);


/** Get the value of the sampleDuration field of a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to examine.
 *
 * @return the value current set for the sampleDuration field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_all_of_samples_get_sample_duration(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

/** Set the value of the sampleDuration field in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to set the field in.
 * @param p_sample_duration The value to copy into the QoEMetricsEvent_allOf_samples object.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_duration(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const char* p_sample_duration);

/** Move a value to the sampleDuration field in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to set the field in.
 * @param p_sample_duration The value to move into the QoEMetricsEvent_allOf_samples object.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_sample_duration_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, char* p_sample_duration);

/** Check if the mediaTimestamp field of a QoEMetricsEvent_allOf_samples object is set
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to examine.
 *
 * @return `true` if the optional mediaTimestamp field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_all_of_samples_has_media_timestamp(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);


/** Get the value of the mediaTimestamp field of a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to examine.
 *
 * @return the value current set for the mediaTimestamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_all_of_samples_get_media_timestamp(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

/** Set the value of the mediaTimestamp field in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to set the field in.
 * @param p_media_timestamp The value to copy into the QoEMetricsEvent_allOf_samples object.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_media_timestamp(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const char* p_media_timestamp);

/** Move a value to the mediaTimestamp field in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to set the field in.
 * @param p_media_timestamp The value to move into the QoEMetricsEvent_allOf_samples object.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_media_timestamp_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, char* p_media_timestamp);


/** Get the value of the metrics field of a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to examine.
 *
 * @return the value current set for the metrics field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_qo_e_metrics_event_all_of_samples_get_metrics(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

/** Set the value of the metrics field in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to set the field in.
 * @param p_metrics The value to copy into the QoEMetricsEvent_allOf_samples object.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const ogs_list_t* p_metrics);

/** Move a value to the metrics field in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to set the field in.
 * @param p_metrics The value to move into the QoEMetricsEvent_allOf_samples object.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_set_metrics_move(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, ogs_list_t* p_metrics);

/** Add a new item to the metrics array in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to add the array item to.
 * @param metrics The value to add.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_add_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, data_collection_model_qo_e_metrics_event_all_of_metrics_t* metrics);

/** Remove an item from the metrics array in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to remove the array value from.
 * @param metrics The value to remove.
 *
 * @return @a qo_e_metrics_event_all_of_samples.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_remove_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, const data_collection_model_qo_e_metrics_event_all_of_metrics_t* metrics);

/** Get an item from the metrics array in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_qo_e_metrics_event_all_of_metrics_t* data_collection_model_qo_e_metrics_event_all_of_samples_get_entry_metrics(const data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples, size_t idx);

/** Remove all entries from the metrics array in a QoEMetricsEvent_allOf_samples object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to empty metrics for.
 *
 * @return @a qo_e_metrics_event_all_of_samples
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_samples_t *data_collection_model_qo_e_metrics_event_all_of_samples_clear_metrics(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

/** lnode helper for generating ogs_list_t nodes's of type QoEMetricsEvent_allOf_samples
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_samples_t
 *
 * Creates a new data_collection_lnode_t object containing the @a qo_e_metrics_event_all_of_samples object.
 * The @a qo_e_metrics_event_all_of_samples will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param qo_e_metrics_event_all_of_samples The QoEMetricsEvent_allOf_samples object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a qo_e_metrics_event_all_of_samples
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_qo_e_metrics_event_all_of_samples_make_lnode(data_collection_model_qo_e_metrics_event_all_of_samples_t *qo_e_metrics_event_all_of_samples);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_SAMPLES_H_ */

