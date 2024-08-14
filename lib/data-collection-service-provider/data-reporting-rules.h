/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef DATA_REPORTING_RULES_H
#define DATA_REPORTING_RULES_H

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/******** Internal library functions ********/
/** Adjust Reporting rules in the Data Reporting Session according to the Reporting rules in Data Reporting Configuration */

void data_collection_adjust_reporting_rules(data_collection_model_data_reporting_session_t *data_reporting_session, ogs_list_t *data_reporting_session_reporting_rules_data_domain, const char *external_application_id, const char *event_type, const char *data_domain, data_collection_reporting_client_type_e client_type);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_REPORTING_RULES_H */

