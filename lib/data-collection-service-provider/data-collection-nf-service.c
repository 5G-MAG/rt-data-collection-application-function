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

static ogs_sbi_nf_service_t *__data_collection_nf_service(const char *name, int server_ifc, const char *api_version, const char *supported_features);
static void __add_addresses_to_nf_service(ogs_sbi_nf_service_t *nf_service, ogs_sockaddr_t *addrs);

int _data_collection_set_nf_services(void)
{
    ogs_sbi_nf_service_t *nf_service = NULL;
    size_t i;

    static const struct {
        uint64_t flag;
        const char *name;
        int server_ifc;
        const char *full_version;
        bool event_feature_flags;
    } services[] = {
      {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING_R1, "3gpp-ndcaf_data-reporting-provisioning",
       DATA_COLLECTION_SVR_PROVISIONING, NDCAF_DATAREPORTINGPROVISIONING_API_VERSION, false},
      {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_PROVISIONING, "3gpp-ndcaf_data-reporting-provisioning",
       DATA_COLLECTION_SVR_PROVISIONING, NDCAF_DATAREPORTINGPROVISIONING_API_VERSION, false},
      {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R2, "3gpp-ndcaf_data-reporting",
       DATA_COLLECTION_SVR_DIRECT_DATA_REPORTING, NDCAF_DATAREPORTING_API_VERSION, false},
      {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R3, "3gpp-ndcaf_data-reporting",
       DATA_COLLECTION_SVR_INDIRECT_DATA_REPORTING, NDCAF_DATAREPORTING_API_VERSION, false},
      {DATA_COLLECTION_FEATURE_SERVER_DATA_REPORTING_R4, "3gpp-ndcaf_data-reporting",
       DATA_COLLECTION_SVR_AS_DATA_REPORTING, NDCAF_DATAREPORTING_API_VERSION, false},
      {DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE_R5, "naf-eventexposure",
        DATA_COLLECTION_SVR_AF_EVENT_EXPOSURE, NAF_EVENTEXPOSURE_API_VERSION, true},
      {DATA_COLLECTION_FEATURE_SERVER_EVENT_EXPOSURE_R6, "naf-eventexposure",
        DATA_COLLECTION_SVR_NWDAF_EVENT_EXPOSURE, NAF_EVENTEXPOSURE_API_VERSION, true}
    };

    for (i=0; i<sizeof(services)/sizeof(services[0]); i++) {
        if (data_collection_self()->config.data_collection_configuration->disable_features & services[i].flag) {
            ogs_info("Data Collection Service [%s] disabled by controlling app", services[i].name);
        } else {
            char *supported_features = NULL;

            ogs_info("Registering Data Collection Service [%s]", services[i].name);
            if (services[i].event_feature_flags) {
                supported_features = ogs_msprintf("%" PRIx64, data_collection_self()->config.data_collection_configuration->event_exposure_supported_features);
            }
            nf_service = __data_collection_nf_service(services[i].name, services[i].server_ifc, services[i].full_version, supported_features);
            ogs_free(supported_features);
            if (!nf_service) return OGS_ERROR;
        }
    }

    return OGS_OK;
}

/***** Private functions *****/

static ogs_sbi_nf_service_t *__data_collection_nf_service(const char *name, int server_ifc, const char *api_version, const char *supported_features)
{
    int i;
    ogs_sbi_nf_service_t *nf_service = NULL;
    ogs_uuid_t uuid;
    char id[OGS_UUID_FORMATTED_LENGTH + 1];

    ogs_assert(name);

    ogs_uuid_get(&uuid);
    ogs_uuid_format(id, &uuid);

    nf_service = ogs_sbi_nf_service_add(ogs_sbi_self()->nf_instance, id, name,
                                        ogs_app()->sbi.server.no_tls == false ? OpenAPI_uri_scheme_https : OpenAPI_uri_scheme_http);
    ogs_assert(nf_service);

    for (i=0; i<data_collection_self()->config.servers[server_ifc].num_v4_server_instances; i++) {
        __add_addresses_to_nf_service(nf_service, data_collection_self()->config.servers[server_ifc].ogs_server[i].ipv4);
    }
    for (i=0; i<data_collection_self()->config.servers[server_ifc].num_v6_server_instances; i++) {
        __add_addresses_to_nf_service(nf_service, data_collection_self()->config.servers[server_ifc].ogs_server[i].ipv6);
    }

    ogs_sbi_nf_service_add_version(nf_service, OGS_SBI_API_V1, api_version, NULL);

    nf_service->supported_features = supported_features;

    ogs_debug("Data Collection Service [%s]", nf_service->name);

    return nf_service;
}

static void __add_addresses_to_nf_service(ogs_sbi_nf_service_t *nf_service, ogs_sockaddr_t *addrs)
{
    ogs_sockaddr_t *addr = NULL;

    for (ogs_copyaddrinfo(&addr, addrs); addr && nf_service->num_of_addr < OGS_SBI_MAX_NUM_OF_IP_ADDRESS;
         addr = addr->next) {
        bool is_port = true;
        int port = 0;

        if (addr->ogs_sa_family == AF_INET) {
            nf_service->addr[nf_service->num_of_addr].ipv4 = addr;
        } else if (addr->ogs_sa_family == AF_INET6) {
            nf_service->addr[nf_service->num_of_addr].ipv6 = addr;
        } else {
            continue;
        }

        port = OGS_PORT(addr);
        if (nf_service->scheme == OpenAPI_uri_scheme_https) {
            if (port == OGS_SBI_HTTPS_PORT) is_port = false;
        } else if (nf_service->scheme == OpenAPI_uri_scheme_http) {
            if (port == OGS_SBI_HTTP_PORT) is_port = false;
        }

        nf_service->addr[nf_service->num_of_addr].is_port = is_port;
        nf_service->addr[nf_service->num_of_addr].port = port;

        nf_service->num_of_addr++;
    }
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
