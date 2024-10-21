/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2022-2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include <stdlib.h>

#include "event-notification.h"
#include "utilities.h"
#include "data-collection-sp/data-collection.h"

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

typedef struct communication_collection_record_s {
    ogs_lnode_t node;
    data_collection_model_communication_collection_t *communication_collection;
    char *application_id;
} communication_collection_record_t;

typedef struct application_id_node_s {
    ogs_lnode_t node;
    char *application_id;
} application_id_node_t;

static data_collection_model_communication_collection_t *__communication_collection_create(char *start_time, char *end_time, long ul_vol, long dl_vol);
static data_collection_model_ue_communication_collection_t *ue_communication_collection_create(const char *application_id, ogs_list_t *communication_collection_records);
static void data_report_application_ids(ogs_list_t *data_reports, ogs_list_t *application_ids);
static communication_collection_record_t *generate_communication_collection_from_data_report(data_collection_data_report_record_t *data_report, void *report);
static void communication_collection_records_by_application_id(ogs_list_t *communication_collection_records, const char *application_id, ogs_list_t *communication_collection_recs);
static void communication_collection_record_free(communication_collection_record_t *communication_collection_record);
//static data_collection_model_af_event_notification_t *af_event_notification_create(ogs_list_t *ue_communication_collections);
static void application_id_node_free(application_id_node_t *application_id_node);
static void application_ids_remove(ogs_list_t *application_ids);
//static void __tidy_up();

ogs_list_t *generate_af_event_notifications(ogs_list_t *data_reports, data_collection_event_subscription_t *data_collection_event_subscription) {
     
    data_collection_data_report_record_t *data_report, *data_rep = NULL, *data_report_node = NULL;
    ogs_list_t application_ids;
    application_id_node_t *application_id_node;
    ogs_list_t communication_collection_records;
    ogs_list_t communication_collection_recs;
    ogs_list_t *af_event_notifications = NULL;

    ogs_list_init(&communication_collection_records);
    ogs_list_init(&communication_collection_recs);

    ogs_list_for_each(data_reports, data_report) {
	//does_application_in_data_report_and_evex_match(data_report, data_collection_event_subscription);   
        void *report = data_collection_reporting_data_report_get(data_report);
        if(report) {
            communication_collection_record_t *communication_collection_record =
                            generate_communication_collection_from_data_report(data_report, report);
	    if(communication_collection_record) {
                ogs_list_add(&communication_collection_records, communication_collection_record);
	        data_collection_reporting_report_used(data_report, data_collection_event_subscription); 
	    }
	}
    }

    af_event_notifications = (ogs_list_t*) ogs_calloc(1,sizeof(*af_event_notifications));
    ogs_assert(af_event_notifications);
    ogs_list_init(af_event_notifications);

    ogs_list_init(&application_ids);
    data_report_application_ids(data_reports, &application_ids);
    
    ogs_list_for_each(&application_ids, application_id_node) {
        data_collection_model_ue_communication_collection_t *ue_communication_collection;
        data_collection_model_af_event_notification_t *af_event_notification
;
        communication_collection_records_by_application_id(&communication_collection_records, application_id_node->application_id, &communication_collection_recs);

        ue_communication_collection = ue_communication_collection_create(application_id_node->application_id, &communication_collection_recs);

	af_event_notification = data_collection_model_af_event_notification_create();
        data_collection_model_af_event_notification_add_ue_comm_infos(af_event_notification, ue_communication_collection);
        data_collection_model_af_event_notification_set_time_stamp(af_event_notification, get_current_time("%Y-%m-%dT%H:%M:%SZ"));

        data_collection_model_af_event_t *af_event = data_collection_model_af_event_create();
        data_collection_model_af_event_set_string(af_event, "UE_COMM");
        data_collection_model_af_event_notification_set_event(af_event_notification, af_event);

	ogs_list_add(af_event_notifications, data_collection_model_af_event_notification_make_lnode(af_event_notification));

        //add ue_communication_collection to ogs_list
        //create AfEventNotification
        //add to ogs_list
    
    }

    application_ids_remove(&application_ids);

    ogs_list_for_each_safe(data_reports, data_rep, data_report_node) {
        ogs_list_remove(data_reports, data_report_node);
        if (!data_collection_reporting_session_get(data_report_node)) {
            data_collection_report_destroy(data_report_node);
        } else {
            data_collection_data_report_record_copy_delete(data_report_node);
	}
    }

    return af_event_notifications;
    //return that list;
}

communication_collection_record_t *generate_communication_collection_from_data_report(data_collection_data_report_record_t *data_report, void *report) {
 
    data_collection_model_communication_collection_t *communication_collection = NULL;
    long dl_vol = 0;
    char *end_time = NULL;
    char *start_time = NULL;
    long ul_vol = 0;
    const char *application_id;
    communication_collection_record_t *communication_collection_record;

    data_collection_model_communication_record_t *communication_record = (data_collection_model_communication_record_t *)report;
    
    if (!communication_record) return NULL;

    dl_vol = data_collection_model_communication_record_get_downlink_volume(communication_record);

    const data_collection_model_time_window_t* time_interval =
                data_collection_model_communication_record_get_time_interval(communication_record);
    if (time_interval) {
        start_time = data_collection_model_time_window_get_start_time(time_interval);
        end_time = data_collection_model_time_window_get_stop_time(time_interval);
    }

    ul_vol = data_collection_model_communication_record_get_uplink_volume(communication_record);

    if (!dl_vol && !ul_vol) {
        ogs_error("At least one of Uplink or Downlink volume shall be provided.");
	if(start_time) ogs_free(start_time);
	if(end_time) ogs_free(end_time);
        return NULL;	
    }

    application_id = data_collection_data_report_get_application_id(data_report); 
   
    communication_collection_record = ogs_calloc(1, sizeof(communication_collection_record_t));
    ogs_assert(communication_collection_record);
    
    communication_collection = __communication_collection_create(start_time, end_time, ul_vol, dl_vol);

    communication_collection_record->application_id = data_collection_strdup(application_id);
    communication_collection_record->communication_collection = communication_collection;

    return communication_collection_record;

}

static data_collection_model_communication_collection_t *__communication_collection_create(char *start_time, char *end_time, long ul_vol, long dl_vol) {
    data_collection_model_communication_collection_t *communication_collection;

    communication_collection = data_collection_model_communication_collection_create();
    ogs_assert(communication_collection);

    if (start_time) {
        data_collection_model_communication_collection_set_start_time_move(communication_collection, start_time);
    }
    if (end_time) {
        data_collection_model_communication_collection_set_end_time_move(communication_collection, end_time);
    }
    data_collection_model_communication_collection_set_dl_vol(communication_collection, dl_vol);
    data_collection_model_communication_collection_set_ul_vol(communication_collection, ul_vol);

    return communication_collection;
}

static void data_report_application_ids(ogs_list_t *data_reports, ogs_list_t *application_ids) {
    data_collection_data_report_record_t *data_report;
    application_id_node_t *application_id_node;
    application_id_node_t *application_id_node_new;

    ogs_list_for_each(data_reports, data_report) {
        bool exists = false;
        const char *report_app_id = data_collection_data_report_get_application_id(data_report);
        ogs_list_for_each(application_ids, application_id_node) {
	    if(!strcmp(report_app_id, application_id_node->application_id)) {
                exists = true;	        
	        break;
            } 
	}
        if(!exists) {
	    application_id_node_new = ogs_calloc(1, sizeof(application_id_node_t));
            ogs_assert(application_id_node_new);
            application_id_node_new->application_id = data_collection_strdup(report_app_id);	    
	    ogs_list_add(application_ids, application_id_node_new);
	}
    }
}

static void application_ids_remove(ogs_list_t *application_ids){

    application_id_node_t *application_id_node = NULL;
    application_id_node_t *id_node = NULL;

    ogs_list_for_each_safe(application_ids, id_node, application_id_node) {
        ogs_list_remove(application_ids, application_id_node);
	application_id_node_free(application_id_node);

    }
}


static void application_id_node_free(application_id_node_t *application_id_node){

    if(!application_id_node) return;
    if(application_id_node->application_id) ogs_free(application_id_node->application_id);
    ogs_free(application_id_node);
}


static void communication_collection_records_by_application_id(ogs_list_t *communication_collection_records, const char *application_id, ogs_list_t *communication_collection_recs) {
    communication_collection_record_t *communication_collection_record = NULL;
    communication_collection_record_t *communication_collection_record_node = NULL;

    ogs_list_for_each_safe(communication_collection_records, communication_collection_record_node, communication_collection_record){
        if(communication_collection_record->application_id && !strcmp(communication_collection_record->application_id, application_id)){
            ogs_list_remove(communication_collection_records, communication_collection_record);
            ogs_list_add(communication_collection_recs, communication_collection_record);
	}		

    }
}

static data_collection_model_ue_communication_collection_t *ue_communication_collection_create(const char *application_id, ogs_list_t *communication_collection_records) {

    communication_collection_record_t *communication_collection_record = NULL;
    communication_collection_record_t *communication_collection_record_node = NULL;
    ogs_list_t *communication_collections = ogs_calloc(1, sizeof(*communication_collections));
    data_collection_model_ue_communication_collection_t *ue_comm_collection;

    ogs_list_for_each_safe(communication_collection_records, communication_collection_record_node, communication_collection_record){
        ogs_list_add(communication_collections, data_collection_model_communication_collection_make_lnode(communication_collection_record->communication_collection));
        communication_collection_record->communication_collection = NULL;
        ogs_list_remove(communication_collection_records, communication_collection_record);
	communication_collection_record_free(communication_collection_record);
    }
    
    ue_comm_collection = data_collection_model_ue_communication_collection_create();
    data_collection_model_ue_communication_collection_set_app_id(ue_comm_collection, application_id);
    data_collection_model_ue_communication_collection_set_comms_move(ue_comm_collection, communication_collections);

    return ue_comm_collection;
}

static void communication_collection_record_free(communication_collection_record_t *communication_collection_record) {

    if (!communication_collection_record) return;
    if (communication_collection_record->communication_collection) {
        data_collection_model_communication_collection_free(communication_collection_record->communication_collection);
    }
    if (communication_collection_record->application_id) ogs_free(communication_collection_record->application_id);
    ogs_free(communication_collection_record);
}
#if 0
static data_collection_model_af_event_t *__ue_comm_event_type = NULL;

static data_collection_model_af_event_notification_t *af_event_notification_create(ogs_list_t *ue_communication_collections) {
    char *time_stamp = data_collection_strdup(get_current_time("%Y-%m-%dT%H:%M:%SZ"));
    data_collection_model_af_event_notification_t *evt_notif;

    if (__ue_comm_event_type == NULL) {
        __ue_comm_event_type = data_collection_model_af_event_create();
        data_collection_model_af_event_set_enum(__ue_comm_event_type, DCM_AF_EVENT_VAL_UE_COMM);
        atexit(__tidy_up);
    }

    evt_notif = data_collection_model_af_event_notification_create();
    data_collection_model_af_event_notification_set_event(evt_notif, __ue_comm_event_type);
    data_collection_model_af_event_notification_set_time_stamp_move(evt_notif, time_stamp);
    data_collection_model_af_event_notification_set_ue_comm_infos_move(evt_notif, ue_communication_collections);

    return evt_notif;
}

static void __tidy_up() {
    if (__ue_comm_event_type) {
        data_collection_model_af_event_free(__ue_comm_event_type);
        __ue_comm_event_type = NULL;
    }
}
#endif


/* vim:ts=8:sts=4:sw=4:expandtab:
 */
