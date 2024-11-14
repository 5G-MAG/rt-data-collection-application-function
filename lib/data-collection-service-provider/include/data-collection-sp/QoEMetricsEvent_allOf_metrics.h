#ifndef _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_METRICS_H_
#define _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_METRICS_H_

/**********************************************************************************************************************************
 * QoEMetricsEvent_allOf_metrics - Public C interface to the QoEMetricsEvent_allOf_metrics object
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

/** A 3GPP QoEMetricsEvent_allOf_metrics object reference
 */
typedef struct data_collection_model_qo_e_metrics_event_all_of_metrics_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_qo_e_metrics_event_all_of_metrics_t;



/** Create a new QoEMetricsEvent_allOf_metrics.
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 * @return a new QoEMetricsEvent_allOf_metrics object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create();

/** Create a new QoEMetricsEvent_allOf_metrics reference.
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The QoEMetricsEvent_allOf_metrics to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create_ref(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *other);

/** Create a new copy of a QoEMetricsEvent_allOf_metrics object.
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 * Creates a new copy of the given @a other object
 * @param other The QoEMetricsEvent_allOf_metrics to copy.
 * @return a new QoEMetricsEvent_allOf_metrics object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create_copy(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *other);

/** Create a new reference of a QoEMetricsEvent_allOf_metrics object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 * Creates a reference to the same underlying @a other object.
 * @param other The QoEMetricsEvent_allOf_metrics to create a new reference to.
 * @return a new QoEMetricsEvent_allOf_metrics object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_create_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *other);

/** Copy the value of another QoEMetricsEvent_allOf_metrics into this object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 * Copies the value of @a other {{classname} object into @a qo_e_metrics_event_all_of_metrics.
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics object to copy @a other into.
 * @param other The QoEMetricsEvent_allOf_metrics to copy the value from.
 * @return @a qo_e_metrics_event_all_of_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_copy(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, const data_collection_model_qo_e_metrics_event_all_of_metrics_t *other);

/** Move the value of another QoEMetricsEvent_allOf_metrics into this object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 * Discards the current value of @a qo_e_metrics_event_all_of_metrics and moves the value of @a other
 * into @a qo_e_metrics_event_all_of_metrics. This will leave @a other as an empty reference.
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics object to move @a other into.
 * @param other The QoEMetricsEvent_allOf_metrics to move the value from.
 *
 * @return @a qo_e_metrics_event_all_of_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, data_collection_model_qo_e_metrics_event_all_of_metrics_t *other);

/** Delete a QoEMetricsEvent_allOf_metrics object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 * Destroys the reference to the QoEMetricsEvent_allOf_metrics object and frees the value of QoEMetricsEvent_allOf_metrics if this is the last reference.
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_qo_e_metrics_event_all_of_metrics_free(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics);

/** Get a cJSON tree representation of a QoEMetricsEvent_allOf_metrics
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * Create a cJSON tree representation of the QoEMetricsEvent_allOf_metrics object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_qo_e_metrics_event_all_of_metrics_toJSON(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, bool as_request);

/** Parse a cJSON tree into a QoEMetricsEvent_allOf_metrics object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * Attempts to interpret a cJSON tree as a QoEMetricsEvent_allOf_metrics API request or response (dependent on @a as_request value). If successful
 * will return a new referenced QoEMetricsEvent_allOf_metrics object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new QoEMetricsEvent_allOf_metrics object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two QoEMetricsEvent_allOf_metrics objects to see if they are equivalent
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param qo_e_metrics_event_all_of_metrics The first QoEMetricsEvent_allOf_metrics object to compare.
 * @param other_qo_e_metrics_event_all_of_metrics The second QoEMetricsEvent_allOf_metrics object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_all_of_metrics_is_equal_to(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, const data_collection_model_qo_e_metrics_event_all_of_metrics_t *other_qo_e_metrics_event_all_of_metrics);



/** Get the value of the key field of a QoEMetricsEvent_allOf_metrics object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics object to examine.
 *
 * @return the value current set for the key field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_qo_e_metrics_event_all_of_metrics_get_key(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics);

/** Set the value of the key field in a QoEMetricsEvent_allOf_metrics object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics object to set the field in.
 * @param p_key The value to copy into the QoEMetricsEvent_allOf_metrics object.
 *
 * @return @a qo_e_metrics_event_all_of_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_key(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, const char* p_key);

/** Move a value to the key field in a QoEMetricsEvent_allOf_metrics object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics object to set the field in.
 * @param p_key The value to move into the QoEMetricsEvent_allOf_metrics object.
 *
 * @return @a qo_e_metrics_event_all_of_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_key_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, char* p_key);

/** Check if the value field of a QoEMetricsEvent_allOf_metrics object is set
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics object to examine.
 *
 * @return `true` if the optional value field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_qo_e_metrics_event_all_of_metrics_has_value(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics);


/** Get the value of the value field of a QoEMetricsEvent_allOf_metrics object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics object to examine.
 *
 * @return the value current set for the value field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_any_type_t* data_collection_model_qo_e_metrics_event_all_of_metrics_get_value(const data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics);

/** Set the value of the value field in a QoEMetricsEvent_allOf_metrics object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics object to set the field in.
 * @param p_value The value to copy into the QoEMetricsEvent_allOf_metrics object.
 *
 * @return @a qo_e_metrics_event_all_of_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_value(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, const data_collection_model_any_type_t* p_value);

/** Move a value to the value field in a QoEMetricsEvent_allOf_metrics object
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics object to set the field in.
 * @param p_value The value to move into the QoEMetricsEvent_allOf_metrics object.
 *
 * @return @a qo_e_metrics_event_all_of_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_qo_e_metrics_event_all_of_metrics_t *data_collection_model_qo_e_metrics_event_all_of_metrics_set_value_move(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics, data_collection_model_any_type_t* p_value);

/** lnode helper for generating ogs_list_t nodes's of type QoEMetricsEvent_allOf_metrics
 * \public \memberof data_collection_model_qo_e_metrics_event_all_of_metrics_t
 *
 * Creates a new data_collection_lnode_t object containing the @a qo_e_metrics_event_all_of_metrics object.
 * The @a qo_e_metrics_event_all_of_metrics will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param qo_e_metrics_event_all_of_metrics The QoEMetricsEvent_allOf_metrics object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a qo_e_metrics_event_all_of_metrics
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_qo_e_metrics_event_all_of_metrics_make_lnode(data_collection_model_qo_e_metrics_event_all_of_metrics_t *qo_e_metrics_event_all_of_metrics);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_QO_E_METRICS_EVENT_ALL_OF_METRICS_H_ */

