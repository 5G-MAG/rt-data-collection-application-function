/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "ogs-core.h"
#include "ogs-proto.h"

#include "data-collection-sp/data-collection.h"

#include "context.h"
//#include "hash.h"
#include "event-subscription.h"
#include "timer.h"
#include "utilities.h"
//#include "data-reporting.h"
//#include "data-report.h"
#include "data-report-store.h"
//#include "data-reporting-provisioning.h"

#include "data-report-record.h"

#ifdef __cplusplus
extern "C" {
#endif

/********* Private data types *********/

typedef struct data_report_s {
    ogs_lnode_t node;
    cJSON *data_report;
} data_report_t;

typedef struct ue_user_id_s {
    ogs_lnode_t node;
    char *user_id;
} ue_user_id_t;

typedef struct data_report_hash_record_s{
    const data_collection_data_report_handler_t *handler;
    ogs_list_t list;
} data_report_hash_record_t;

/********* Private function prototypes *********/

static data_collection_data_report_record_t *__data_collection_report_create(data_collection_reporting_session_t *session, const data_collection_data_report_handler_t *handler, void *data_report, const char *external_application_id);
static void __data_reports_timer_activate(void);
static bool __cmp_ptrs(const void *a, const void *b);

/******** Public API ********/

/* data_collection_data_report_record_new */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_data_report_record_new(data_collection_reporting_session_t *session, const data_collection_data_report_handler_t *data_handler, void *data_sample, const char *external_application_id, bool expedite)
{
    data_collection_data_report_record_t *report = __data_collection_report_create(session, data_handler, data_sample, external_application_id);

    if(expedite) data_collection_data_report_record_set_expedite(report);
    ogs_debug("Data Report record expedite: %d", report->expedite);

    /* Add the new report to the database */

    data_report_hash_record_t *data_reports = (data_report_hash_record_t *)ogs_hash_get(data_collection_self()->data_reports, &report->data_report_handler, sizeof(data_collection_data_report_handler_t*));

    if(!data_reports) {
        data_reports = (data_report_hash_record_t *) ogs_calloc(1,sizeof(*data_reports));
        ogs_assert(data_reports);
	data_reports->handler = report->data_report_handler;
        ogs_list_init(&data_reports->list);
    }

    ogs_list_add(&data_reports->list, report);

    ogs_hash_set(data_collection_self()->data_reports, &data_reports->handler, sizeof(data_collection_data_report_handler_t*), data_reports);
    __data_reports_timer_activate();

    cJSON *data_report_json = data_handler->json_for_report_data(data_sample);
    
    //dump to disk report data_collection_data_report_t stored to disk

    char *report_time = dc_strdup(get_current_time("%Y-%m-%dT%H:%M:%SZ"));
    char *body = cJSON_Print(data_report_json);
    cJSON_Delete(data_report_json);

    data_collection_report_store(data_collection_reporting_session_get_id(session), data_handler->data_domain, report_time, "json", body);
    cJSON_free(body);
    ogs_free(report_time);

    return report;
}

/*data_collection_data_report_record_copy */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_data_report_record_copy(data_collection_data_report_record_t *data_report_record)
{

    data_collection_data_report_record_t *report;

    report = ogs_calloc(1, sizeof(data_collection_data_report_record_t));
    ogs_assert(report);

    report->data_report_handler = data_report_record->data_report_handler; 
    report->generated = data_report_record->generated;
    report->last_used = data_report_record->last_used;
    report->hash = data_collection_strdup(data_report_record->hash);
    report->session = data_collection_reporting_session_ref(data_report_record->session);
    report->data_report_record = data_report_record->data_report_record;
    report->original_records = ogs_malloc(sizeof(data_report_record));
    report->original_records[0] = data_report_record;
    report->number_of_original_records = 1;
    /* report->context_ids is handled by original record */
    report->external_application_id = data_collection_strdup(data_report_record->external_application_id);
    /* report->usage is handled by original record */
    report->expired = data_report_record->expired;
    report->data_report_record_owner = false;
    report->expedite = data_report_record->expedite;
    ogs_debug("Expedite on Data Report record copy: %d, origin: %d", report->expedite, data_report_record->expedite);
    return report;

}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_data_report_record_copy_new_result(data_collection_data_report_record_t *record, void *sample)
{
    data_collection_data_report_record_t *report = __data_collection_report_create(record->session, record->data_report_handler, sample, record->external_application_id);
    report->original_records = ogs_malloc(sizeof(record));
    report->original_records[0] = record;
    report->number_of_original_records = 1;
    return report;
}

/* data_collection_data_report_record_create_aggregated */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_report_record_t *data_collection_data_report_record_create_aggregated(void *data_sample, const ogs_list_t *origin_data_report_records)
{
    data_collection_data_report_record_t *report;

    report = ogs_calloc(1, sizeof(data_collection_data_report_record_t));
    ogs_assert(report);

    report->generated = ogs_time_now();
    report->last_used = report->generated;

    report->data_report_record = data_sample;
    report->data_report_record_owner = true;

    data_collection_data_report_record_t *node;
    bool first = true;
    size_t i = 0;

    report->number_of_original_records = ogs_list_count(origin_data_report_records);
    report->original_records = ogs_malloc(sizeof(*report->original_records) * report->number_of_original_records);

    ogs_list_for_each(origin_data_report_records, node) {
        if (first) {
            report->data_report_handler = node->data_report_handler;
            report->session = data_collection_reporting_session_ref(node->session);
            report->external_application_id = data_collection_strdup(node->external_application_id);
            first = false;
        } else {
            if (report->data_report_handler != node->data_report_handler) {
                ogs_error("Attempt to aggregate records of multiple different data types");
                data_collection_data_report_record_destroy(report);
                report = NULL;
                break;
            }
            if (report->session != node->session) {
                data_collection_reporting_session_free(report->session);
                report->session = NULL;
            }
            if (report->external_application_id && strcmp(report->external_application_id, node->external_application_id)) {
                ogs_free(report->external_application_id);
                report->external_application_id = NULL;
            }
        }
	if(!report->expedite && node->expedite) data_collection_data_report_record_set_expedite(report);
	ogs_debug("Expedite on Data Report record aggregate: %d, node: %d", report->expedite, node->expedite);
        report->original_records[i++] = node;
    }

    return report;

}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_data_report_record_set_expedite(data_collection_data_report_record_t *data_report) {
 if(!data_report) return false;
 data_report->expedite = true;
 return data_report->expedite;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_data_report_record_get_expedite(const data_collection_data_report_record_t *data_report) {
 if(!data_report) return false;
 return data_report->expedite;
}

/* data_collection_data_report_record_destroy */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_report_record_destroy(data_collection_data_report_record_t *report)
{
    ogs_assert(report);

    if (report->hash) {
        ogs_free(report->hash);
        report->hash = NULL;
    }
    if (report->data_report_record_owner) {
        if (report->data_report_record) {
            report->data_report_handler->free_report_data(report->data_report_record);
            report->data_report_record = NULL;
        }
    }
    if (report->external_application_id) ogs_free(report->external_application_id);

    if (report->original_records) ogs_free(report->original_records);

    if (report->usage) {
        data_collection_lnode_t *node;
        ogs_list_for_each(report->usage, node) {
            data_collection_event_subscription_t *evt_subsc = node->object;
            _event_subscription_remove_data_report_used(evt_subsc, report);
        }
	data_collection_list_free(report->usage);
	report->usage = NULL;
    }
    if(report->context_ids) {
        data_collection_list_free(report->context_ids);
	report->context_ids = NULL;
    }

    data_collection_reporting_session_free(report->session);

    ogs_free(report);
}

/* data_collection_data_report_record_get_data_sample */
DATA_COLLECTION_SVC_PRODUCER_API void *data_collection_data_report_record_get_data_sample(const data_collection_data_report_record_t *data_report_record) {
    
    if(!data_report_record) return NULL;
    return data_report_record->data_report_record;
}

/* data_collection_data_report_record_get_external_application_id */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_data_report_record_get_external_application_id(const data_collection_data_report_record_t *data_report_record) {

    if(!data_report_record || !data_report_record->external_application_id) return NULL;
    return data_report_record->external_application_id;
}

/* data_collection_data_report_record_get_session */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_reporting_session_t *data_collection_data_report_record_get_session(const data_collection_data_report_record_t *report_record)
{
    if (!report_record) return NULL;
    return report_record->session;
}

/* data_collection_data_report_record_get_number_of_original_records */
DATA_COLLECTION_SVC_PRODUCER_API size_t data_collection_data_report_record_get_number_of_original_records(const data_collection_data_report_record_t *data_report_record)
{
   if(!data_report_record) return 0;
   return data_report_record->number_of_original_records; 
}

/* data_collection_data_report_record_get_context_ids */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t *data_collection_data_report_record_get_context_ids(const data_collection_data_report_record_t *report_record)
{
    if (!report_record) return NULL;
    return report_record->data_report_handler->context_ids(report_record->data_report_record);
}

/*data_collection_data_report_record_get_data_report_handler */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_data_report_handler_t *data_collection_data_report_record_get_data_report_handler(const data_collection_data_report_record_t *report_record)
{
    if (!report_record) return NULL;
    return report_record->data_report_handler;
}

/* data_collection_data_report_record_mark_used */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_data_report_record_mark_used(data_collection_data_report_record_t *report_record, data_collection_event_subscription_t *event_subscription) {

    int ret = 0;

    if (event_subscription) {
        if (report_record->number_of_original_records > 0) {
            size_t i;
            for (i=0; i<report_record->number_of_original_records; i++) {
                ret += data_collection_data_report_record_mark_used(report_record->original_records[i], event_subscription);
            }
        } else {
            data_collection_lnode_t *event_subscription_node = data_collection_lnode_create_ref(event_subscription);
            if (!report_record->usage) report_record->usage = ogs_calloc(1, sizeof(*report_record->usage));
            if (event_subscription_node == data_collection_set_add_lnode(report_record->usage, event_subscription_node, __cmp_ptrs)) {
                _event_subscription_add_data_report_used(event_subscription, report_record);
            }
            ret = 1;
        }
    }

    return ret;
}

/* data_collection_data_report_record_mark_expire */
DATA_COLLECTION_SVC_PRODUCER_API int data_collection_data_report_record_mark_expire(data_collection_data_report_record_t *data_collection_report_record) {

    if(!data_collection_report_record) return 0;
    data_collection_report_record->expired = true;
    return 1;
}

/* data_collection_data_report_record_used_by */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_data_report_record_used_by(const data_collection_data_report_record_t *data_report, const data_collection_event_subscription_t *event_subscription)
{
    if (!data_report || !event_subscription || !data_report->usage) return false;

    data_collection_lnode_t *node;

    ogs_list_for_each(data_report->usage, node) {
        if ((void*)event_subscription == node->object) return true;
    }

    return false;
}

/******** Internal library API *********/

bool _data_report_record_is_event_subscription_used(const data_collection_data_report_record_t *data_report, const data_collection_event_subscription_t *event_subscription)
{
    if (data_report->usage) {
         data_collection_lnode_t *event_subsc_node;
         ogs_list_for_each(data_report->usage, event_subsc_node) {
             data_collection_event_subscription_t *event_subsc = event_subsc_node->object;
             if (event_subsc == event_subscription)
                 return 1;
         }
    }
    return 0;
}

void _data_report_record_unmark_used(data_collection_data_report_record_t *data_report, data_collection_event_subscription_t *event_subscription)
{
    if (data_report->usage) {
        data_collection_lnode_t *next, *node;
        ogs_list_for_each_safe(data_report->usage, next, node) {
            data_collection_event_subscription_t *event_subsc = node->object;
            if (event_subsc == event_subscription) {
                ogs_list_remove(data_report->usage, node);
                data_collection_lnode_free(node);
                break;
            }
        }
    }
}

/******** Private functions ***********/

static data_collection_data_report_record_t *__data_collection_report_create(data_collection_reporting_session_t *session, const data_collection_data_report_handler_t *handler, void *data_report_record, const char *external_application_id) {
    data_collection_data_report_record_t *report;

    report = ogs_calloc(1, sizeof(data_collection_data_report_record_t));
    ogs_assert(report);

    report->data_report_handler = handler; //pointer to handler;
    report->generated = get_time_from_timespec(handler->timestamp_for_report_data(data_report_record)); // this function returns timespec so change to ogs_time_t;
    report->last_used = ogs_time_now();
    report->session = data_collection_reporting_session_ref(session);
    report->hash = handler->tag_for_report_data(data_report_record);
    report->data_report_record = data_report_record;
    report->context_ids = handler->context_ids(data_report_record);
    report->external_application_id = data_collection_strdup(external_application_id);
    report->data_report_record_owner = true;
    report->expedite = false;
    report->file_path = data_collection_self()->config.data_collection_dir;
    
    return report;
}

static void __data_reports_timer_activate(void) {

    if (!data_collection_self()->data_reports_timer) data_collection_self()->data_reports_timer = ogs_timer_add(ogs_app()->timer_mgr, dc_timer_data_reports_expire, NULL);
    if (data_collection_self()->data_reports_timer) {
         ogs_timer_start(data_collection_self()->data_reports_timer, ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age));
    }
    if (!data_collection_self()->data_reports_clear_timer) data_collection_self()->data_reports_clear_timer = ogs_timer_add(ogs_app()->timer_mgr, dc_timer_data_reports_clear, NULL);     
    if (data_collection_self()->data_reports_clear_timer) {
         ogs_timer_start(data_collection_self()->data_reports_clear_timer, ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age));
    }
}

static bool __cmp_ptrs(const void *a, const void *b)
{
    return a == b;
}

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
