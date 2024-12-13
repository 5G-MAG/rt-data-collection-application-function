/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2022-2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include <stdlib.h>

#include "ogs-core.h"

#include "utilities.h"
#include "data-collection-sp/data-collection.h"
#include "communication-record.h"

#include "event-notification.h"

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

typedef struct communication_collection_record_s {
    ogs_lnode_t node;
    data_collection_model_communication_collection_t *communication_collection;
    char *application_id;
} communication_collection_record_t;

static void __data_bucket_mark_used(data_collection_bucketed_data_t *data_bucket, data_collection_event_subscription_t *event_subscription);
static void __af_event_notification_add_ue_communication_collections_for_data_bucket(
                                                            data_collection_model_af_event_notification_t *af_event_notification,
                                                            data_collection_bucketed_data_t *data_bucket);
/*static bool __data_bucket_any_report_expedited(data_collection_bucketed_data_t *data_bucket);*/
static bool __event_subscription_get_notification_window_for_timespec(
                                                        const data_collection_event_subscription_t *event_subscription /* [not-null] */,
                                                        const struct timespec *time /* [not-null] */,
                                                        struct timespec *notification_start /* [out, not-null] */,
                                                        struct timespec *notification_end /* [out, not-null] */);
static data_collection_model_af_event_notification_t *__af_event_notification_new(const char *event_type);
static communication_collection_record_t *__communication_collection_record_new_from_data_report(
                                                                                data_collection_data_report_record_t *data_report);
static data_collection_model_communication_collection_t *__communication_collection_create(const char *start_time,
                                                                                           const char *end_time,
                                                                                           long ul_vol, long dl_vol);
static data_collection_model_ue_communication_collection_t *__ue_communication_collection_create(
                                                                communication_collection_record_t *communication_collection_record,
                                                                const data_collection_bucket_info_t *bucket_info);
static bool __is_gpsi(const char *id);
static bool __is_supi(const char *id);
static void __ue_communication_collection_add(data_collection_model_ue_communication_collection_t *ue_comm_collection,
                                              communication_collection_record_t *communication_collection_record);
static void __communication_collection_record_free(communication_collection_record_t *communication_collection_record);
static void __ogs_free(void *ptr);

ogs_list_t *generate_af_event_notifications(ogs_list_t *data_buckets,
                                            data_collection_event_subscription_t *data_collection_event_subscription)
{
    data_collection_bucketed_data_t *data_bucket;
    ogs_hash_t *notifications_by_start_time = NULL;
    ogs_list_t *notification_start_times = NULL;
    ogs_list_t *af_event_notifications = NULL;
    data_collection_model_af_event_notification_t *no_time_af_event_notification = NULL;
    bool no_more_notifications = false;
    struct timespec now;

    clock_gettime(CLOCK_REALTIME, &now);

    ogs_list_for_each(data_buckets, data_bucket) {
        if (data_bucket->bucket_info.time) {
            /* bucket has a time axis */
            struct timespec notification_start;
            struct timespec notification_end;
            if (__event_subscription_get_notification_window_for_timespec(data_collection_event_subscription, &data_bucket->bucket_info.time->start, &notification_start, &notification_end)) {
                /* event subscription is periodic and notification window calculated */
                {
                    char *notif_start_str = timespec_to_rfc3339_str(&notification_start);
                    char *notif_end_str = timespec_to_rfc3339_str(&notification_end);
                    ogs_debug("Bucket belongs in notification window %s to %s", notif_start_str, notif_end_str);
                    ogs_free(notif_start_str);
                    ogs_free(notif_end_str);
                }
                if (timespec_cmp(&notification_end, &now) > 0) {
                    /* Notification window ends after the current time so this is for the current notification time window.
                     * We will ignore this bucket for now even if a record in it is expedited as we need to wait for the rest of
                     * the window data. */
                    /* if (!__data_bucket_any_report_expedited(data_bucket)) continue; */
                    continue;
                }
                data_collection_model_af_event_notification_t *af_event_notification;
                if (!notifications_by_start_time) {
                    notifications_by_start_time = ogs_hash_make();
                    af_event_notification = NULL;
                } else {
                    af_event_notification = (data_collection_model_af_event_notification_t*)ogs_hash_get(notifications_by_start_time, &notification_start, sizeof(notification_start));
                }
                if (!af_event_notification) {
                    if (no_more_notifications) continue;
                    af_event_notification = __af_event_notification_new("UE_COMM");
                    struct timespec *start_time = ogs_malloc(sizeof(*start_time));
                    *start_time = notification_start;
                    if (!notification_start_times) {
                        notification_start_times = (ogs_list_t*)ogs_calloc(1, sizeof(*notification_start_times));
                    }
                    ogs_list_add(notification_start_times, data_collection_lnode_create(start_time, __ogs_free));
                    ogs_hash_set(notifications_by_start_time, start_time, sizeof(*start_time), af_event_notification);
                    if (!af_event_notifications) {
                        af_event_notifications = (ogs_list_t*)ogs_calloc(1, sizeof(*af_event_notifications));
                    }
                    ogs_list_add(af_event_notifications, data_collection_model_af_event_notification_make_lnode(af_event_notification));
                    if (data_collection_event_subscription_increment_notification_count(data_collection_event_subscription)) {
                        /* maximum notifications reached */
                        no_more_notifications = true;
                    }
                }
                __af_event_notification_add_ue_communication_collections_for_data_bucket(af_event_notification, data_bucket);
                /* mark all records in the bucket as used */
                __data_bucket_mark_used(data_bucket, data_collection_event_subscription);
                continue;
            }
        }
        if (!no_time_af_event_notification) {
            if (no_more_notifications) continue; /* not allowed any more notifications for this subscription so skip this */
            no_time_af_event_notification = __af_event_notification_new("UE_COMM");
            if (!af_event_notifications) {
                af_event_notifications = (ogs_list_t*)ogs_calloc(1, sizeof(*af_event_notifications));
            }
            ogs_list_add(af_event_notifications, data_collection_model_af_event_notification_make_lnode(no_time_af_event_notification));
            if (data_collection_event_subscription_increment_notification_count(data_collection_event_subscription)) {
                /* maximum notifications reached */
                no_more_notifications = true;
            }
        }
        __af_event_notification_add_ue_communication_collections_for_data_bucket(no_time_af_event_notification, data_bucket);
        /* mark all records in the bucket as used */
        __data_bucket_mark_used(data_bucket, data_collection_event_subscription);
    }

    if (notifications_by_start_time) ogs_hash_destroy(notifications_by_start_time);
    if (notification_start_times) data_collection_list_free(notification_start_times);

    return af_event_notifications;
}

static void __data_bucket_mark_used(data_collection_bucketed_data_t *data_bucket, data_collection_event_subscription_t *event_subscription)
{
    data_collection_data_report_record_t *data_report;
    ogs_list_for_each(data_bucket->data_samples, data_report) {
        data_collection_data_report_record_mark_used(data_report, event_subscription);
    }
}

static void __af_event_notification_add_ue_communication_collections_for_data_bucket(
                                                            data_collection_model_af_event_notification_t *af_event_notification,
                                                            data_collection_bucketed_data_t *data_bucket)
{
    data_collection_data_report_record_t *data_report;
    ogs_hash_t *ue_collection_by_app_id = ogs_hash_make();
    ogs_list_for_each(data_bucket->data_samples, data_report) {
        data_collection_model_ue_communication_collection_t *ue_communication_collection;
        communication_collection_record_t *communication_collection_record =
                                                                __communication_collection_record_new_from_data_report(data_report);
        ue_communication_collection = (data_collection_model_ue_communication_collection_t*)ogs_hash_get(ue_collection_by_app_id, communication_collection_record->application_id, OGS_HASH_KEY_STRING);
        if (!ue_communication_collection) {
            data_collection_model_ue_communication_collection_t *tmp_ref;
            ue_communication_collection = __ue_communication_collection_create(communication_collection_record, &data_bucket->bucket_info);
            tmp_ref = data_collection_model_ue_communication_collection_create_ref(ue_communication_collection);
            ogs_hash_set(ue_collection_by_app_id, data_collection_model_ue_communication_collection_get_app_id(ue_communication_collection), OGS_HASH_KEY_STRING, ue_communication_collection);
            data_collection_model_af_event_notification_add_ue_comm_infos(af_event_notification, tmp_ref);
        } else {
            __ue_communication_collection_add(ue_communication_collection, communication_collection_record);
        }
        __communication_collection_record_free(communication_collection_record);
    }
    data_collection_hash_free(ue_collection_by_app_id, (void(*)(void*))data_collection_model_ue_communication_collection_free);
}

#if 0
static bool __data_bucket_any_report_expedited(data_collection_bucketed_data_t *data_bucket)
{
    data_collection_data_report_record_t *data_report;
    ogs_list_for_each(data_bucket->data_samples, data_report) {
        if (data_collection_data_report_record_get_expedite(data_report)) return true;
    }
    return false;
}
#endif

static bool __event_subscription_get_notification_window_for_timespec(
                                                    const data_collection_event_subscription_t *event_subscription /* [not-null] */,
                                                    const struct timespec *time /* [not-null] */,
                                                    struct timespec *notification_start /* [out, not-null] */,
                                                    struct timespec *notification_end /* [out, not-null] */)
{
    const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc =
                                        data_collection_event_subscription_get_af_event_exposure_subsc(event_subscription);
    const data_collection_model_reporting_information_t *rep_info =
                                        data_collection_model_af_event_exposure_subsc_get_events_rep_info(af_event_exposure_subsc);
    const data_collection_model_notification_method_t *notif_method =
                                        data_collection_model_reporting_information_get_notif_method(rep_info);
    bool retval = false;


    if (notif_method && data_collection_model_notification_method_get_enum(notif_method) == DCM_NOTIFICATION_METHOD_VAL_PERIODIC) {
        struct timespec subsc_create_time, time_after_create;
        int32_t rep_period = data_collection_model_reporting_information_get_rep_period(rep_info);

        data_collection_event_subscription_get_create_time(event_subscription, &subsc_create_time);
        timespec_sub(time, &subsc_create_time, &time_after_create);
        /* truncate to rep_period boundary */
        time_after_create.tv_sec = (time_t)(((time_t)(time_after_create.tv_sec/rep_period))*rep_period);
        if (time_after_create.tv_sec < 0) {
            time_after_create.tv_sec -= rep_period;
        }
        timespec_add(&subsc_create_time, &time_after_create, notification_start);
        notification_end->tv_sec = notification_start->tv_sec + rep_period;
        notification_end->tv_nsec = notification_start->tv_nsec;

        retval = true;
    }

    return retval;
}

static data_collection_model_af_event_notification_t *__af_event_notification_new(const char *event_type)
{
    data_collection_model_af_event_notification_t *af_event_notification = data_collection_model_af_event_notification_create();
    data_collection_model_af_event_notification_set_time_stamp(af_event_notification, get_current_time("%Y-%m-%dT%H:%M:%SZ"));

    data_collection_model_af_event_t *af_event = data_collection_model_af_event_create();
    data_collection_model_af_event_set_string(af_event, event_type);
    data_collection_model_af_event_notification_set_event_move(af_event_notification, af_event);

    return af_event_notification;
}

static communication_collection_record_t *__communication_collection_record_new_from_data_report(data_collection_data_report_record_t *data_report) {

    data_collection_model_communication_collection_t *communication_collection = NULL;
    long dl_vol = 0;
    const char *end_time = NULL;
    const char *start_time = NULL;
    long ul_vol = 0;
    const char *application_id;
    communication_collection_record_t *communication_collection_record;
    const comm_record_and_aggregation_fname_t *report =
                    (const comm_record_and_aggregation_fname_t*)data_collection_data_report_record_get_data_sample(data_report);

    if (!report) return NULL;

    const data_collection_model_communication_record_t *communication_record = report->record;

    if (!communication_record) return NULL;

    const data_collection_model_time_window_t* time_interval =
                data_collection_model_communication_record_get_time_interval(communication_record);
    if (time_interval) {
        start_time = data_collection_model_time_window_get_start_time(time_interval);
        end_time = data_collection_model_time_window_get_stop_time(time_interval);
    }

    dl_vol = data_collection_model_communication_record_get_downlink_volume(communication_record);
    ul_vol = data_collection_model_communication_record_get_uplink_volume(communication_record);

    if (!dl_vol && !ul_vol) {
        ogs_error("At least one of Uplink or Downlink volume shall be provided.");
        return NULL;
    }

    application_id = data_collection_data_report_record_get_external_application_id(data_report);

    communication_collection_record = ogs_calloc(1, sizeof(communication_collection_record_t));
    ogs_assert(communication_collection_record);

    communication_collection = __communication_collection_create(start_time, end_time, ul_vol, dl_vol);

    communication_collection_record->application_id = data_collection_strdup(application_id);
    communication_collection_record->communication_collection = communication_collection;

    return communication_collection_record;

}

static data_collection_model_communication_collection_t *__communication_collection_create(const char *start_time, const char *end_time, long ul_vol, long dl_vol) {
    data_collection_model_communication_collection_t *communication_collection;

    communication_collection = data_collection_model_communication_collection_create();
    ogs_assert(communication_collection);

    if (start_time) {
        data_collection_model_communication_collection_set_start_time(communication_collection, start_time);
    }
    if (end_time) {
        data_collection_model_communication_collection_set_end_time(communication_collection, end_time);
    }
    data_collection_model_communication_collection_set_dl_vol(communication_collection, dl_vol);
    data_collection_model_communication_collection_set_ul_vol(communication_collection, ul_vol);

    return communication_collection;
}

static data_collection_model_ue_communication_collection_t *__ue_communication_collection_create(communication_collection_record_t *communication_collection_record, const data_collection_bucket_info_t *bucket_info) {

    data_collection_model_ue_communication_collection_t *ue_comm_collection;

    ue_comm_collection = data_collection_model_ue_communication_collection_create();
    data_collection_model_ue_communication_collection_set_app_id(ue_comm_collection, communication_collection_record->application_id);

    if (bucket_info->identity) {
        if (bucket_info->identity->user_id) {
            if (__is_gpsi(bucket_info->identity->user_id)) {
                data_collection_model_ue_communication_collection_set_gpsi(ue_comm_collection, bucket_info->identity->user_id);
            } else if (__is_supi(bucket_info->identity->user_id)) {
                data_collection_model_ue_communication_collection_set_supi(ue_comm_collection, bucket_info->identity->user_id);
            }
        }
        if (bucket_info->identity->group_id) {
            /* TODO: add internal/external group id from bucket_info */
        }
    }
    
    data_collection_model_ue_communication_collection_add_comms(ue_comm_collection, communication_collection_record->communication_collection);
    communication_collection_record->communication_collection = NULL;

    return ue_comm_collection;
}

static bool __is_gpsi(const char *id)
{
    static const char * const gpsi_starts[] = {
        "msisdn-", "extid-"
    };
    size_t i;
    for (i=0; i < sizeof(gpsi_starts)/sizeof(gpsi_starts[0]); i++) {
        if (!strncmp(id, gpsi_starts[i], strlen(gpsi_starts[i]))) return true;
    }
    return false;
}

static bool __is_supi(const char *id)
{
    static const char * const supi_starts[] = {
        "imsi-", "nai-", "gci-", "gli-"
    };
    size_t i;
    for (i=0; i < sizeof(supi_starts)/sizeof(supi_starts[0]); i++) {
        if (!strncmp(id, supi_starts[i], strlen(supi_starts[i]))) return true;
    }
    return false;
}

static void __ue_communication_collection_add(data_collection_model_ue_communication_collection_t *ue_comm_collection, communication_collection_record_t *communication_collection_record)
{
    data_collection_model_ue_communication_collection_add_comms(ue_comm_collection, communication_collection_record->communication_collection);
    communication_collection_record->communication_collection = NULL;
}

static void __communication_collection_record_free(communication_collection_record_t *communication_collection_record) {

    if (!communication_collection_record) return;
    if (communication_collection_record->communication_collection) {
        data_collection_model_communication_collection_free(communication_collection_record->communication_collection);
    }
    if (communication_collection_record->application_id) ogs_free(communication_collection_record->application_id);
    ogs_free(communication_collection_record);
}

static void __ogs_free(void *ptr)
{
    ogs_free(ptr);
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
