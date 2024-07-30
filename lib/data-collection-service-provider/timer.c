/*
 * Copyright (C) 2019-2022 by Sukchan Lee <acetcom@gmail.com>
 * Copyright (C) 2023 British Broadcasting Corporation
 *
 * Authors: Sukchan Lee & Dev Audsin
 *
 * This file is derived from Open5GS with additions by the BBC for 5G-MAG.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "context.h"
#include "event-subscription.h"
#include "timer.h"


typedef struct data_collection_event_subscription_s data_collection_event_subscription_t;

static void timer_send_event(int timer_id, void *data);

const char *data_collection_timer_get_name(int timer_id)
{
    switch (timer_id) {
    case OGS_TIMER_NF_INSTANCE_REGISTRATION_INTERVAL:
        return OGS_TIMER_NAME_NF_INSTANCE_REGISTRATION_INTERVAL;
    case OGS_TIMER_NF_INSTANCE_HEARTBEAT_INTERVAL:
        return OGS_TIMER_NAME_NF_INSTANCE_HEARTBEAT_INTERVAL;
    case OGS_TIMER_NF_INSTANCE_NO_HEARTBEAT:
        return OGS_TIMER_NAME_NF_INSTANCE_NO_HEARTBEAT;
    case OGS_TIMER_NF_INSTANCE_VALIDITY:
        return OGS_TIMER_NAME_NF_INSTANCE_VALIDITY;
    case OGS_TIMER_SUBSCRIPTION_VALIDITY:
        return OGS_TIMER_NAME_SUBSCRIPTION_VALIDITY;
    case OGS_TIMER_SUBSCRIPTION_PATCH:
        return OGS_TIMER_NAME_SUBSCRIPTION_PATCH;
    case OGS_TIMER_SBI_CLIENT_WAIT:
        return OGS_TIMER_NAME_SBI_CLIENT_WAIT;
    case DC_TIMER_REPORTING_SESSION_CACHE:
        return "DC_TIMER_REPORTING_SESSION_CACHE";
    case DC_TIMER_DATA_REPORTS_EXPIRY:
        return "DC_TIMER_DATA_REPORTS_EXPIRY";
    case DC_TIMER_DATA_REPORTS_CLEAR:
        return "DC_TIMER_DATA_REPORTS_CLEAR";
    case DC_TIMER_EVENT_EXPOSURE_NOTIF:
        return "DC_TIMER_EVENT_EXPOSURE_NOTIF";
    default: 
       break;
    }

    ogs_error("Unknown Timer[%d]", timer_id);
    return "UNKNOWN_TIMER";
}

static void timer_send_event(int timer_id, void *data)
{
    int rv;
    ogs_event_t *e = NULL;

    switch (timer_id) {
    case DC_TIMER_REPORTING_SESSION_CACHE:
        e = (ogs_event_t *)ogs_event_new(DC_EVENT_REPORTING_SESSION_CACHE);
        ogs_assert(e);
        e->timer_id = timer_id;
        break;
    case DC_TIMER_DATA_REPORTS_EXPIRY:
        e = (ogs_event_t *)ogs_event_new(DC_EVENT_DATA_REPORTS_EXPIRY);
        ogs_assert(e);
        e->timer_id = timer_id;
        break;
    case DC_TIMER_DATA_REPORTS_CLEAR:
        e = (ogs_event_t *)ogs_event_new(DC_EVENT_DATA_REPORTS_CLEAR);
        ogs_assert(e);
        e->timer_id = timer_id;
        break;
    case DC_TIMER_EVENT_EXPOSURE_NOTIF:
        e = (ogs_event_t *)ogs_event_new(DC_LOCAL_EVENT_EXPOSURE_NOTIFICATION);
        ogs_assert(e);
        e->timer_id = timer_id;
        break;
    default:
        ogs_fatal("Unknown timer id[%d]", timer_id);
        ogs_assert_if_reached();
        break;
    }

    rv = ogs_queue_push(ogs_app()->queue, e);
    if (rv != OGS_OK) {
        ogs_error("ogs_queue_push() failed [%d] in %s",
                (int)rv, data_collection_timer_get_name(timer_id));
        ogs_event_free(e);
    }
}



void dc_timer_reporting_session_cache(void *data)
{
    timer_send_event(DC_TIMER_REPORTING_SESSION_CACHE, data);
    ogs_timer_start(data_collection_self()->reporting_sessions_cache_timer, ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age));
}

void dc_timer_data_reports_expire(void *data)
{
    timer_send_event(DC_TIMER_DATA_REPORTS_EXPIRY, data);
    ogs_timer_start(data_collection_self()->data_reports_timer, ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age));

}


void dc_timer_data_reports_clear(void *data)
{
    timer_send_event(DC_TIMER_DATA_REPORTS_CLEAR, data);
    ogs_timer_start(data_collection_self()->data_reports_clear_timer, ogs_time_from_sec(data_collection_self()->config.server_response_cache_control->data_collection_reporting_report_response_max_age));

}

void dc_timer_event_exposure_notif(void *data)
{
    data_collection_event_subscription_t *event_subscription;
   
    ogs_assert(data);
    event_subscription = (data_collection_event_subscription_t *)data;
    _event_subscription_set_send_notif(event_subscription);
    timer_send_event(DC_TIMER_EVENT_EXPOSURE_NOTIF, data);
    _event_subscription_notification_timer_activate(event_subscription);
}
