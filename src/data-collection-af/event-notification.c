/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2022-2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "event-notification.h"
#include "regexpr.h"
#include "utilities.h"
#include "data-collection-sp/data-collection.h"

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif

typedef struct communication_collection_record_s {
    ogs_lnode_t node;
    dcaf_api_communication_collection_t *communication_collection;
    char *application_id;
} communication_collection_record_t;

typedef struct application_id_node_s {
    ogs_lnode_t node;
    char *application_id;
}application_id_node_t;

typedef struct dcaf_api_communication_record_s dcaf_api_communication_record_t;
typedef struct dcaf_api_ue_communication_record_s dcaf_api_ue_communication_record_t;

static dcaf_api_communication_collection_t *data_collection_communication_collection_create(char *start_time, char *end_time, long ul_vol, long dl_vol);
static dcaf_api_ue_communication_collection_t *ue_communication_collection_create(char *application_id, ogs_list_t *communication_collection_records);
static void data_report_application_ids(ogs_list_t *data_reports, ogs_list_t *application_ids);
static communication_collection_record_t *generate_communication_collection_from_data_report(data_collection_data_report_record_t *data_report, void *report);
static void communication_collection_records_by_application_id(ogs_list_t *communication_collection_records, char *application_id, ogs_list_t *communication_collection_recs);
static void communication_collection_record_free(communication_collection_record_t *communication_collection_record);
static dcaf_api_af_event_notification_t *af_event_notification_create(OpenAPI_list_t *ue_communication_collections);
static void application_id_node_free(application_id_node_t *application_id_node);
static void application_ids_remove(ogs_list_t *application_ids);

ogs_list_t *generate_af_event_notifications(ogs_list_t *data_reports, data_collection_event_subscription_t *data_collection_event_subscription) {
     
    data_collection_data_report_record_t *data_report;
    void *report = NULL;
    communication_collection_record_t *communication_collection_record;
    dcaf_api_communication_collection_t *communication_collection = NULL;
    dcaf_api_ue_communication_collection_t *ue_communication_collection = NULL;
    ogs_list_t application_ids;
    application_id_node_t *application_id_node;
    ogs_list_t communication_collection_records;
    ogs_list_t communication_collection_recs;
    ogs_list_t *af_event_notifications = NULL;
    OpenAPI_list_t *ue_communication_collections = NULL;
    dcaf_api_af_event_notification_t *af_event_notification = NULL;

    ogs_list_init(&communication_collection_records);

    ogs_list_init(&communication_collection_recs);

    ogs_list_for_each(data_reports, data_report) {
	//does_application_in_data_report_and_evex_match(data_report, data_collection_event_subscription);   
        report = data_collection_reporting_data_report_get(data_report);
        if(report) {
            communication_collection_record = generate_communication_collection_from_data_report(data_report, report);
	    if(communication_collection_record) {
                ogs_list_add(&communication_collection_records, communication_collection_record);
		//OpenAPI_list_add(communication_collections, communication_collection);
	        data_collection_reporting_report_used(data_report, data_collection_event_subscription); 
	    }
	}
    }

    ue_communication_collections = OpenAPI_list_create();
    
    af_event_notifications = (ogs_list_t*) ogs_calloc(1,sizeof(*af_event_notifications));
    ogs_assert(af_event_notifications);
    ogs_list_init(af_event_notifications);

    ogs_list_init(&application_ids);
    data_report_application_ids(data_reports, &application_ids);
    
    ogs_list_for_each(&application_ids, application_id_node) {
        
        communication_collection_records_by_application_id(&communication_collection_records, application_id_node->application_id, &communication_collection_recs);

        ue_communication_collection = ue_communication_collection_create(application_id_node->application_id, &communication_collection_recs);
	OpenAPI_list_add(ue_communication_collections, ue_communication_collection);
	af_event_notification = af_event_notification_create(ue_communication_collections);
	ogs_list_add(af_event_notifications, af_event_notification);


        //add ue_communication_collection to ogs_list
        //create AfEventNotification
        //add to ogs_list
    
    }

    application_ids_remove(&application_ids);

    return af_event_notifications;
    //return that list;
}

communication_collection_record_t *generate_communication_collection_from_data_report(data_collection_data_report_record_t *data_report, void *report) {
 
    dcaf_api_communication_collection_t *communication_collection = NULL;
    long dl_vol = 0;
    char *end_time = NULL;
    char *start_time = NULL;
    long ul_vol = 0;
    char *application_id;
    communication_collection_record_t *communication_collection_record;

    dcaf_api_communication_record_t *communication_record = (dcaf_api_communication_record_t *)report;
    
    if(!communication_record) return NULL;

    if(communication_record->is_downlink_volume)
        dl_vol = communication_record->downlink_volume;

    if(communication_record->time_interval) {
        if(communication_record->time_interval->start_time)	    
            start_time = data_collection_strdup(communication_record->time_interval->start_time);
        	
        if(communication_record->time_interval->stop_time)
            end_time = data_collection_strdup(communication_record->time_interval->stop_time);		
    }

    if(communication_record->is_uplink_volume)
        ul_vol = communication_record->uplink_volume;

    if(!dl_vol && !ul_vol) {
        ogs_error("At least one of Uplink or Downlink volume shall be provided.");
	if(start_time) ogs_free(start_time);
	if(end_time) ogs_free(end_time);
        return NULL;	
    }

    application_id = data_collection_data_report_get_application_id(data_report); 
   
    communication_collection_record = ogs_calloc(1, sizeof(communication_collection_record_t));
    ogs_assert(communication_collection_record);
    
    communication_collection = ogs_calloc(1, sizeof(dcaf_api_communication_record_t));    
    ogs_assert(communication_collection_record);
    communication_collection = data_collection_communication_collection_create(start_time, end_time, ul_vol, dl_vol);
    ogs_assert(communication_collection);
    
    //communication_collection = data_collection_communication_collection_create(dl_vol, end_time, start_time, ul_vol);
    communication_collection_record->application_id = data_collection_strdup(application_id);
    communication_collection_record->communication_collection = communication_collection;

    return communication_collection_record;

}

static dcaf_api_communication_collection_t *data_collection_communication_collection_create(char *start_time, char *end_time, long ul_vol, long dl_vol) {
    return dcaf_api_communication_collection_create(dl_vol, end_time, start_time, ul_vol);
}

static void data_report_application_ids(ogs_list_t *data_reports, ogs_list_t *application_ids) {
    data_collection_data_report_record_t *data_report;
    application_id_node_t *application_id_node;
    application_id_node_t *application_id_node_new;
    bool exists = 0;

    ogs_list_for_each(data_reports, data_report) {
        ogs_list_for_each(application_ids, application_id_node) {
	    if(!strcmp(data_collection_data_report_get_application_id(data_report), application_id_node->application_id)) {
                exists = 1;	        
	        break;
            } 
	}
        if(!exists) {
	    application_id_node_new = ogs_calloc(1, sizeof(application_id_node_t));
            ogs_assert(application_id_node_new);
            application_id_node_new->application_id = data_collection_strdup(data_collection_data_report_get_application_id(data_report));	    
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


static void communication_collection_records_by_application_id(ogs_list_t *communication_collection_records, char *application_id, ogs_list_t *communication_collection_recs) {
    communication_collection_record_t *communication_collection_record = NULL;
    communication_collection_record_t *communication_collection_record_node = NULL;

    ogs_list_for_each_safe(communication_collection_records, communication_collection_record_node, communication_collection_record){
        if(communication_collection_record->application_id && !strcmp(communication_collection_record->application_id, application_id)){
            ogs_list_remove(communication_collection_records, communication_collection_record);
            ogs_list_add(communication_collection_recs, communication_collection_record);
	}		

    }
}

static dcaf_api_ue_communication_collection_t *ue_communication_collection_create(char *application_id, ogs_list_t *communication_collection_records) {

    communication_collection_record_t *communication_collection_record = NULL;
    communication_collection_record_t *communication_collection_record_node = NULL;
    dcaf_api_communication_collection_t *comm_collection;
    OpenAPI_list_t *communication_collections;

    communication_collections = OpenAPI_list_create();

    ogs_list_for_each_safe(communication_collection_records, communication_collection_record_node, communication_collection_record){
	comm_collection = dcaf_api_communication_collection_copy(NULL, communication_collection_record->communication_collection, false);    
        OpenAPI_list_add(communication_collections, comm_collection);	    
        ogs_list_remove(communication_collection_records, communication_collection_record);
	communication_collection_record_free(communication_collection_record); 
    }
    return dcaf_api_ue_communication_collection_create(data_collection_strdup(application_id), communication_collections, NULL, NULL, NULL, NULL, NULL);
}

static void communication_collection_record_free(communication_collection_record_t *communication_collection_record) {

    if(!communication_collection_record) return;
    if(communication_collection_record->communication_collection) dcaf_api_communication_collection_free(communication_collection_record->communication_collection);
    if(communication_collection_record->application_id) ogs_free(communication_collection_record->application_id);
    ogs_free(communication_collection_record);
}

static dcaf_api_af_event_notification_t *af_event_notification_create(OpenAPI_list_t *ue_communication_collections) {

    char *time_stamp = data_collection_strdup(get_current_time("%Y-%m-%dT%H:%M:%SZ"));

    return dcaf_api_af_event_notification_create(NULL, NULL, NULL, NULL, dcaf_api_af_event_VAL_UE_COMM, NULL, NULL, NULL, NULL,
		    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, time_stamp, ue_communication_collections, NULL);

}


/* vim:ts=8:sts=4:sw=4:expandtab:
 */
