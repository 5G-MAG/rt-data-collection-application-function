#ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_CONNECTION_METRICS_H_
#define _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_CONNECTION_METRICS_H_

/**********************************************************************************************************************************
 * MediaStreamingAccess_connectionMetrics - Public C interface to the MediaStreamingAccess_connectionMetrics object
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

/** A 3GPP MediaStreamingAccess_connectionMetrics object reference
 */
typedef struct data_collection_model_media_streaming_access_connection_metrics_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_media_streaming_access_connection_metrics_t;



/** Create a new MediaStreamingAccess_connectionMetrics.
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 * @return a new MediaStreamingAccess_connectionMetrics object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_create();

/** Create a new MediaStreamingAccess_connectionMetrics reference.
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The MediaStreamingAccess_connectionMetrics to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_create_ref(const data_collection_model_media_streaming_access_connection_metrics_t *other);

/** Create a new copy of a MediaStreamingAccess_connectionMetrics object.
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 * Creates a new copy of the given @a other object
 * @param other The MediaStreamingAccess_connectionMetrics to copy.
 * @return a new MediaStreamingAccess_connectionMetrics object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_create_copy(const data_collection_model_media_streaming_access_connection_metrics_t *other);

/** Create a new reference of a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MediaStreamingAccess_connectionMetrics to create a new reference to.
 * @return a new MediaStreamingAccess_connectionMetrics object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_create_move(data_collection_model_media_streaming_access_connection_metrics_t *other);

/** Copy the value of another MediaStreamingAccess_connectionMetrics into this object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 * Copies the value of @a other {{classname} object into @a media_streaming_access_connection_metrics.
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to copy @a other into.
 * @param other The MediaStreamingAccess_connectionMetrics to copy the value from.
 * @return @a media_streaming_access_connection_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_copy(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, const data_collection_model_media_streaming_access_connection_metrics_t *other);

/** Move the value of another MediaStreamingAccess_connectionMetrics into this object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 * Discards the current value of @a media_streaming_access_connection_metrics and moves the value of @a other
 * into @a media_streaming_access_connection_metrics. This will leave @a other as an empty reference.
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to move @a other into.
 * @param other The MediaStreamingAccess_connectionMetrics to move the value from.
 *
 * @return @a media_streaming_access_connection_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_move(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, data_collection_model_media_streaming_access_connection_metrics_t *other);

/** Delete a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 * Destroys the reference to the MediaStreamingAccess_connectionMetrics object and frees the value of MediaStreamingAccess_connectionMetrics if this is the last reference.
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_access_connection_metrics_free(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics);

/** Get a cJSON tree representation of a MediaStreamingAccess_connectionMetrics
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * Create a cJSON tree representation of the MediaStreamingAccess_connectionMetrics object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_access_connection_metrics_toJSON(const data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, bool as_request);

/** Parse a cJSON tree into a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * Attempts to interpret a cJSON tree as a MediaStreamingAccess_connectionMetrics API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MediaStreamingAccess_connectionMetrics object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new MediaStreamingAccess_connectionMetrics object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MediaStreamingAccess_connectionMetrics objects to see if they are equivalent
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param media_streaming_access_connection_metrics The first MediaStreamingAccess_connectionMetrics object to compare.
 * @param other_media_streaming_access_connection_metrics The second MediaStreamingAccess_connectionMetrics object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_access_connection_metrics_is_equal_to(const data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, const data_collection_model_media_streaming_access_connection_metrics_t *other_media_streaming_access_connection_metrics);



/** Get the value of the meanNetworkRoundTripTime field of a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to examine.
 *
 * @return the value current set for the meanNetworkRoundTripTime field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_media_streaming_access_connection_metrics_get_mean_network_round_trip_time(const data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics);

/** Set the value of the meanNetworkRoundTripTime field in a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to set the field in.
 * @param p_mean_network_round_trip_time The value to copy into the MediaStreamingAccess_connectionMetrics object.
 *
 * @return @a media_streaming_access_connection_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_mean_network_round_trip_time(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, const float p_mean_network_round_trip_time);

/** Move a value to the meanNetworkRoundTripTime field in a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to set the field in.
 * @param p_mean_network_round_trip_time The value to move into the MediaStreamingAccess_connectionMetrics object.
 *
 * @return @a media_streaming_access_connection_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_mean_network_round_trip_time_move(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, float p_mean_network_round_trip_time);


/** Get the value of the networkRoundTripTimeVariation field of a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to examine.
 *
 * @return the value current set for the networkRoundTripTimeVariation field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_media_streaming_access_connection_metrics_get_network_round_trip_time_variation(const data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics);

/** Set the value of the networkRoundTripTimeVariation field in a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to set the field in.
 * @param p_network_round_trip_time_variation The value to copy into the MediaStreamingAccess_connectionMetrics object.
 *
 * @return @a media_streaming_access_connection_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_network_round_trip_time_variation(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, const float p_network_round_trip_time_variation);

/** Move a value to the networkRoundTripTimeVariation field in a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to set the field in.
 * @param p_network_round_trip_time_variation The value to move into the MediaStreamingAccess_connectionMetrics object.
 *
 * @return @a media_streaming_access_connection_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_network_round_trip_time_variation_move(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, float p_network_round_trip_time_variation);


/** Get the value of the congestionWindowSize field of a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to examine.
 *
 * @return the value current set for the congestionWindowSize field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_media_streaming_access_connection_metrics_get_congestion_window_size(const data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics);

/** Set the value of the congestionWindowSize field in a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to set the field in.
 * @param p_congestion_window_size The value to copy into the MediaStreamingAccess_connectionMetrics object.
 *
 * @return @a media_streaming_access_connection_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_congestion_window_size(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, const int32_t p_congestion_window_size);

/** Move a value to the congestionWindowSize field in a MediaStreamingAccess_connectionMetrics object
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to set the field in.
 * @param p_congestion_window_size The value to move into the MediaStreamingAccess_connectionMetrics object.
 *
 * @return @a media_streaming_access_connection_metrics.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_access_connection_metrics_t *data_collection_model_media_streaming_access_connection_metrics_set_congestion_window_size_move(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics, int32_t p_congestion_window_size);

/** lnode helper for generating ogs_list_t nodes's of type MediaStreamingAccess_connectionMetrics
 * \public \memberof data_collection_model_media_streaming_access_connection_metrics_t
 *
 * Creates a new data_collection_lnode_t object containing the @a media_streaming_access_connection_metrics object.
 * The @a media_streaming_access_connection_metrics will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param media_streaming_access_connection_metrics The MediaStreamingAccess_connectionMetrics object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a media_streaming_access_connection_metrics
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_access_connection_metrics_make_lnode(data_collection_model_media_streaming_access_connection_metrics_t *media_streaming_access_connection_metrics);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_MEDIA_STREAMING_ACCESS_CONNECTION_METRICS_H_ */

