/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include <inttypes.h>
#include "context.h"
#include "utilities.h"
#include "data-collection-nf-service.h"
#include "openapi/api/TS26532_Ndcaf_DataReportingProvisioningAPI-info.h"
#include "openapi/api/TS26532_Ndcaf_DataReportingAPI-info.h"
#include "openapi/api/ApplicationEventSubscriptionCollectionAPI-info.h"
#include "openapi/api/IndividualApplicationEventSubscriptionDocumentAPI-info.h"

static ogs_sbi_nf_service_t *data_collection_nf_service(char *name, int server_ifc, char *api_version, char *supported_features);
static int check_service_addresses(ogs_sbi_server_t *server, ogs_sockaddr_t *sockaddr_v4, ogs_sockaddr_t *sockaddr_v6);

int _data_collection_set_nf_services(void)
{
    bool event_exposure_disable;
    bool data_reporting_disable;
    bool data_reporting_provisioning_disable;
    ogs_sbi_nf_service_t *nf_service = NULL;

    event_exposure_disable = (data_collection_self()->config.data_collection_configuration->disable_features & DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE);
    data_reporting_disable = (data_collection_self()->config.data_collection_configuration->disable_features & DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING);
    data_reporting_provisioning_disable = (data_collection_self()->config.data_collection_configuration->disable_features & 
		    DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING);
   
    ogs_debug("event_exposure_disable:[%d], data_reporting_disable[%d], data_reporting_provisioning_disable [%d]",event_exposure_disable, data_reporting_disable, data_reporting_provisioning_disable);

    if(!data_reporting_provisioning_disable){
	nf_service = data_collection_nf_service("3gpp-ndcaf_data-reporting-provisioning", DATA_COLLECTION_SVR_PROVISIONING, NDCAF_DATAREPORTINGPROVISIONING_API_VERSION, NULL);
	if(!nf_service) return OGS_ERROR;
    }
    if(!data_reporting_disable){
	nf_service = data_collection_nf_service("3gpp-ndcaf_data-reporting", DATA_COLLECTION_SVR_DATA_REPORTING, NDCAF_DATAREPORTING_API_VERSION, NULL);
	if(!nf_service) return OGS_ERROR;
    }
    if(!event_exposure_disable){
	 char *supported_features = NULL;

	 if(data_collection_self()->config.data_collection_configuration->event_exposure_supported_features)
             supported_features =  ogs_msprintf("%" PRIx64, data_collection_self()->config.data_collection_configuration->event_exposure_supported_features);		 

	 nf_service = data_collection_nf_service("naf-eventexposure", DATA_COLLECTION_SVR_EVENT, NAF_EVENTEXPOSURE_API_VERSION, supported_features);
	 ogs_free(supported_features);
	 if(!nf_service) return OGS_ERROR;
    }

    return OGS_OK;	
}

/***** Private functions *****/

static ogs_sbi_nf_service_t *data_collection_nf_service(char *name, int server_ifc, char *api_version, char *supported_features)
{
    ogs_sbi_server_t *server = NULL;
    ogs_sbi_nf_service_t *nf_service = NULL;
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];
    char *hostname = NULL;

    ogs_assert(name);

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    nf_service = ogs_sbi_nf_service_add(ogs_sbi_self()->nf_instance, id, name, ogs_app()->sbi.server.no_tls == false ? OpenAPI_uri_scheme_https : OpenAPI_uri_scheme_http);
    ogs_assert(nf_service);

    hostname = NULL;
    ogs_list_for_each(&ogs_sbi_self()->server_list, server) {
        if(check_service_addresses(server, data_collection_self()->config.servers[server_ifc].ipv4, data_collection_self()->config.servers[server_ifc].ipv6))
	    break;
    }
    if(server)
    {
        ogs_sockaddr_t *advertise = NULL;

        advertise = server->advertise;
        if (!advertise)
            advertise = server->node.addr;
        ogs_assert(advertise);

        if (!hostname) {
            hostname = ogs_gethostname(advertise);
        }

        if (nf_service->num_of_addr < OGS_SBI_MAX_NUM_OF_IP_ADDRESS) {
            bool is_port = true;
            int port = 0;
            ogs_sockaddr_t *addr = NULL;
            ogs_assert(OGS_OK == ogs_copyaddrinfo(&addr, advertise));
            ogs_assert(addr);

            port = OGS_PORT(addr);
            if (nf_service->scheme == OpenAPI_uri_scheme_https) {
                if (port == OGS_SBI_HTTPS_PORT) is_port = false;
            } else if (nf_service->scheme == OpenAPI_uri_scheme_http) {
                if (port == OGS_SBI_HTTP_PORT) is_port = false;
            }

            nf_service->addr[nf_service->num_of_addr].is_port = is_port;
            nf_service->addr[nf_service->num_of_addr].port = port;
            if (addr->ogs_sa_family == AF_INET) {
                nf_service->addr[nf_service->num_of_addr].ipv4 = addr;
            } else if (addr->ogs_sa_family == AF_INET6) {
                nf_service->addr[nf_service->num_of_addr].ipv6 = addr;
            } else
                ogs_assert_if_reached();

            nf_service->num_of_addr++;
	}
    }

    if (hostname) {
        nf_service->fqdn = data_collection_strdup(hostname);
        ogs_assert(nf_service->fqdn);
    }

    ogs_assert(nf_service);

    ogs_sbi_nf_service_add_version(nf_service, OGS_SBI_API_V1, api_version, NULL);

     if(supported_features)
        nf_service->supported_features = data_collection_strdup(supported_features);

    ogs_info("Data Collection Service [%s]", nf_service->name);

    return nf_service;
}

static int check_service_addresses(ogs_sbi_server_t *server, ogs_sockaddr_t *sockaddr_v4, ogs_sockaddr_t *sockaddr_v6)
{
    if (server) {

        if ((sockaddr_v4 && ogs_sockaddr_is_equal(server->node.addr, sockaddr_v4)) ||
            (sockaddr_v6 && ogs_sockaddr_is_equal(server->node.addr, sockaddr_v6))
           ) {
            return 1;
        }
    }

    return 0;
}



