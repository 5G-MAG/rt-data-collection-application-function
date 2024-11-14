/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: Dev Audsin <dev.audsin@bbc.co.uk>
 *          David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_EVENT_EXPOSURE_H
#define DATA_COLLECTION_EVENT_EXPOSURE_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "sbi/openapi/external/cJSON.h"

/** \addtogroup dcsp
 * @{
 */

#ifdef __cplusplus

typedef struct ogs_list_s ogs_list_t;

#ifndef OGS_CORE_INSIDE
#define OGS_CORE_INSIDE
#endif
#ifndef OGS_USE_TALLOC
#define OGS_USE_TALLOC 1
#endif
#include "ogs-macros.h"
#include "ogs-list.h"
#include "ogs-time.h"

#undef OGS_CORE_INSIDE

extern "C" {
#else
#include "ogs-core.h"
#endif

/***** Enumerations *****/

/** Event Exposure supported feature bit masks
 *
 * The feature numbers come from TS 29.517 v18.4.0 Table 5.8-1
 */

/** Event Exposure supported feature bit masks. The feature numbers come from TS 29.517 v18.4.0 Table 5.8-1.
 * \headerfile event-exposure.h <data-collection-sp/data-collection.h>
 */
typedef enum {
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_SERVICE_EXPERIENCE=DATA_COLLECTION_FEATURE_BIT(1),      /**< Bit mask to support Service Experience event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_MOBILITY=DATA_COLLECTION_FEATURE_BIT(2),             /**< Bit mask to support UE Mobility event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_COMMUNICATION=DATA_COLLECTION_FEATURE_BIT(3),        /**< Bit mask to support UE Communication event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_EXCEPTIONS=DATA_COLLECTION_FEATURE_BIT(4),              /**< Bit mask to support Exceptions event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ES3XX=DATA_COLLECTION_FEATURE_BIT(5),                   /**< Bit mask to support ES3XX event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ENHANCED_NA=DATA_COLLECTION_FEATURE_BIT(6),             /**< Bit mask to support Enhanced NA event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_USER_DATA_CONGESTION=DATA_COLLECTION_FEATURE_BIT(7),    /**< Bit mask to support User Data Congestion. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_PERFORMANCE_DATA=DATA_COLLECTION_FEATURE_BIT(8),        /**< Bit mask to support Performance Data. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_DISPERSION=DATA_COLLECTION_FEATURE_BIT(9),              /**< Bit mask to support Dispersion event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_COLLECTIVE_BEHAVIOUR=DATA_COLLECTION_FEATURE_BIT(10),   /**< Bit mask to support Collective Behaviour event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_SERVICE_EXPERIENCE_EXT=DATA_COLLECTION_FEATURE_BIT(11), /**< Bit mask to support Service Experience Ext event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_QOE_METRICS=DATA_COLLECTION_FEATURE_BIT(12),         /**< Bit mask to support Media Streaming QoE Metrics. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_CONSUMPTION=DATA_COLLECTION_FEATURE_BIT(13),         /**< Bit mask to support Media Streaming Consumption. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_NET_ASSIST_INVOCN=DATA_COLLECTION_FEATURE_BIT(14),   /**< Bit mask to support Media Streaming Network Assistance Invocation. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_DYN_POLICY_INVOCN=DATA_COLLECTION_FEATURE_BIT(15),   /**< Bit mask to support Media Streaming Dynamic Policy Invocation. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_ACCESS_ACTIVITY=DATA_COLLECTION_FEATURE_BIT(16),     /**< Bit mask to support Media Streaming Access Activity. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_DATA_ACCESS_PROFILE_ID=DATA_COLLECTION_FEATURE_BIT(17), /**< Bit mask to support Data Access Profile event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ALL_APPLICATIONS=DATA_COLLECTION_FEATURE_BIT(18),       /**< Bit mask to support All Applications event. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_GNSS_ASSIST_DATA=DATA_COLLECTION_FEATURE_BIT(19),       /**< Bit mask to support GNSS Assistance Data. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_PERFORMANCE_DATA_AIML=DATA_COLLECTION_FEATURE_BIT(20),  /**< Bit mask to support Performance Data for AIML. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_MOBILITY_AIML=DATA_COLLECTION_FEATURE_BIT(21),       /**< Bit mask to support UE Mobility for AIML. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ENH_PERFORMANCE_DATA=DATA_COLLECTION_FEATURE_BIT(22),   /**< Bit mask to support ENH Performance Data. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_UE_COMMUNICATION_ENA=DATA_COLLECTION_FEATURE_BIT(23),   /**< Bit mask to support UE Communication ENA. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_SERVICE_EXPERIENCE_ENA=DATA_COLLECTION_FEATURE_BIT(24), /**< Bit mask to support Service Experience ENA. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_ENH_DATA_MANAGEMENT=DATA_COLLECTION_FEATURE_BIT(25),    /**< Bit mask to support ENH Data Management. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_EXTENDED_EVENT_FILTERS=DATA_COLLECTION_FEATURE_BIT(26), /**< Bit mask to support Extended Event Filters. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_DATA_VOL_TRANSFER_TIME=DATA_COLLECTION_FEATURE_BIT(27), /**< Bit mask to support Data Volume Transfer time. */
    DATA_COLLECTION_SUPPORTED_FEATURE_EVENT_MS_EVENT_EXPOSURE=DATA_COLLECTION_FEATURE_BIT(28)       /**< Bit mask to support Media Streaming Event Exposure. */
} data_collection_supported_features_event_e;

/***** Opaque Types *****/

/** Event Subscription
 *
 * Use data_collection_event_subscription_*() functions to access this type.
 */
typedef struct data_collection_event_subscription_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private */
}
#endif
data_collection_event_subscription_t;

/** \cond FORWARD_DECL */
/** 3GPP Event Subscription object.
 * Use data_collection_model_events_subs_*() functions to access this type.
 *
 * \see lib/data-collection-service-provider/include/data-collection-sp/EventsSubs.h
 */
typedef struct data_collection_model_events_subs_s data_collection_model_events_subs_t;

/** 3GPP AfEventExposureSubsc object.
 * Use data_collection_model_af_event_exposure_subsc_*() functions to access this type.
 * \see lib/data-collection-service-provider/include/data-collection-sp/AfEventExposureSubsc.h
 */
typedef struct data_collection_model_af_event_exposure_subsc_s data_collection_model_af_event_exposure_subsc_t;

/** 3GPP EventFilter object.
 * Use data_collection_model_event_filter_*() functions to access this type.
 * \see lib/data-collection-service-provider/include/data-collection-sp/EventFilter.h
 */
typedef struct data_collection_model_event_filter_s data_collection_model_event_filter_t;

/** \endcond */

/***** Interface callbacks *****/

/** Callback to generate events using the given subscription as a filter.
 *
 * @param event_subscription The event subscription to generate AfEventNotifications for.
 *
 * @return A list of data_collection_lnode_t where the `object` field points to a data_collection_model_af_event_notification_t.
 */
typedef ogs_list_t* (*data_collection_event_generation_cb)(data_collection_event_subscription_t *event_subscription);

/***** Interface structures *****/

/** Event
 *
 * Event to be exposed to a client which has subscribed via the EventExposure API
 */
typedef struct data_collection_data_event_s {
    const char *event_type;            /**< See TS 29.517 Table 5.6.3.3-1 for standard event types */
    struct timespec timestamp;         /**< nano-second accurate UTC time when the event was observed */
    const char *event_attribute_name;  /**< Attribute name to report the event data with */
    cJSON *event_data;                 /**< event data as a JSON object/array */
} data_collection_data_event_t;

/***** Library function API *****/

/** Subscribe to event exposure session */

/** Subscribe to an event subscription
 *
 * Subscribe to event notifications for a client of type \a client_type. The standard \a client_type strings are "NWDAF",
 * "EVENT_CONSUMER_AF" and "NEF", but custom values are allowed.
 *
 * @param subscription AfEvent Subscription.
 * @param client_type The EventConsumerType enumeration string (custom values allowed).
 * @param[out] error_return Filled in on error with a human readable error string.
 * @param[out] error_classname Filled in on error with the classname of the class that generated the parsing error.
 * @param[out] error_parameter Filled in on error with the parameter name of the parameter that caused the parsing error.
 * @return a new event subscription object or `NULL` on error.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_event_subscription_t *data_collection_event_subscription_subscribe(data_collection_model_af_event_exposure_subsc_t *subscription, const char *client_type, char **error_return /* output */, char **error_classname /* output */, char **error_parameter /* output */);

/** Unsubscribe an event exposure session 
 * @param event_subscription AfEvent Subscription.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_event_subscription_unsubscribe(data_collection_event_subscription_t *event_subscription);

/** Return the client type string.
 * Returns the client type string, for the client that requested the event exposure subscription, that was registed when creating
 * the subscription. This will normally be either "NWDAF", "EVENT_CONSUMER_AF" or "NEF".
 *
 * @param event_subscription AfEvent Subscription.
 * @return The client type string.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_event_subscription_get_client_type(const data_collection_event_subscription_t *event_subscription /* not-null */);

/** Find an event subscription by the {subscriptionId}
 * @param subscription_id Identifier of the Subscription to find.
 * @return Either an event subscription object or NULL if an event subscription cannot be found for the id provided.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_event_subscription_t *data_collection_event_subscription_find_by_id(const char *subscription_id /* not-null */);

/** Get the AF Event Exposure Subscription for the event subscription context
 * @param event_subscription event Subscription.
 * @return AfEventSubsc object.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_af_event_exposure_subsc_t *data_collection_event_subscription_get_af_event_exposure_subsc(const data_collection_event_subscription_t *event_subscription /* not-null */);

/** Set the AF Event Exposure Subscription for the event subscription context 
 * @param event_subscription event Subscription.
 * @param af_event_exposure_subscription AfEventExposureSubsc object.
 * @return returns "true" if the AfEventExposureSubsc object is set successfully, if not returns "false".
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_event_subscription_set_af_event_exposure_subsc(data_collection_event_subscription_t *event_subscription /* not-null */, data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subscription /* not-null, transfer */);

/** Get the event subscription id
 * @param event_subscription event Subscription for which the id needs to be obtained.
 * @return returns subscription id if the event subscription is found, otherwise returns NULL.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_event_subscription_get_id(const data_collection_event_subscription_t *event_subscription);

/** Get the Event Exposure Subscription last modified date-time (for HTTP) 
 * @param event_subscription event Subscription for which the last modified time needs to be obtained.
 * @return last modified time.
*/
DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t data_collection_event_subscription_get_last_modified(const data_collection_event_subscription_t *event_subscription);

/** Get the Event Exposure Subscription last used date-time (for idle session expiry).
 * @param event_subscription event Subscription for which the last used time needs to be obtained.
 * @return last used time.
*/
DATA_COLLECTION_SVC_PRODUCER_API ogs_time_t data_collection_event_subscription_get_last_used(const data_collection_event_subscription_t *event_subscription);

/** Get the Event Exposure Subscription entity instance tag.
 * @param event_subscription event Subscription for which etag needs to be obtained.
 * @return returns etag (for HTTP).
*/
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_event_subscription_get_etag(const data_collection_event_subscription_t *event_subscription);

/** Get the immediate reports flag.
 * @param event_subscription event subscription.
 * @return returns "true" if immediate reply flag is set in the reporting information of the AfEventExposureSubsc JSON Object, "false" otherwise.
*/
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_event_subscription_get_imm_rep_flag(const data_collection_event_subscription_t *event_subscription);

/** Get the creation time of this subscription.
 *
 * @param event_subscription The event subscription to get the creation time for in \a create_time.
 * @param[out] create_time The timespec to fill in with the wallclock creation time.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_event_subscription_get_create_time(const data_collection_event_subscription_t *event_subscription, struct timespec *create_time);

/** Increment the number of notifications generated for this event subscription.
 *
 * Increments the counter for generated notifications. This may be taken into account when calling
 * data_collection_event_subscription_check_expired(). This will return a boolean to indicate if the allowed maximum number of
 * notifications for this subscription has been reached.
 *
 * @param event_subscription The event subscription to increment the counter for.
 *
 * @return `true` if the counter has reached the subscribed limit, otherwise `false`.
 *
 * @see data_collection_event_subscription_check_expired()
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_event_subscription_increment_notification_count(data_collection_event_subscription_t *event_subscription);

/** Check if this event subscription has reached its reporting limits.
 *
 * This will check the notifications count against the maximum number of notifications allowed and will check the maximum period of
 * time for the subscription against the subscription age.
 *
 * @param event_subscription The event subscription to check for expiry.
 *
 * @return `true` if the event subscription has reached its notifications or time limits.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_event_subscription_check_expired(const data_collection_event_subscription_t *event_subscription);

/** Generate AfEventExposureSubsc response for the event subscription
 * @param data_collection_event_subscription Event subscription for which the AfEventExposureSubsc response needs to be generated.
 * @return AfEventExposureSubsc JSON Object.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_event_subscription_generate_af_event_exposure_subsc(data_collection_event_subscription_t *data_collection_event_subscription);

/** Generate AfEventExposureNotif request for the event subscription
 * @param data_collection_event_subscription Event subscription for notification.
 * @return AfEventExposureNotif JSON Object.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_event_subscription_generate_af_event_exposure_notif(data_collection_event_subscription_t *data_collection_event_subscription);

/** Reference to original event subscription 
 * @param event_subscription Copied event Subscription to which the original event subscription is referenced.
 * @param event_subscription_original Original event Subscription.
 * @return Copied event subscription object.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_event_subscription_t *data_collection_event_subscription_set_original_event_subscription(data_collection_event_subscription_t *event_subscription, const data_collection_event_subscription_t *event_subscription_original /* not-null */);


/** Get original event subscription
 * @param event_subscription Event Subscription to which the orignal is linked to.
 * @return Original event subscription object.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_event_subscription_t *data_collection_event_subscription_get_original_event_subscription(const data_collection_event_subscription_t *event_subscription /* not-null */);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_EVENT_EXPOSURE_H */
