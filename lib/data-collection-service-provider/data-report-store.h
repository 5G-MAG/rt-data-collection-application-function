/*
License: 5G-MAG Public License (v1.0)
Author: David Waring
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_REPORT_STORE_H
#define DATA_REPORT_STORE_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Store a Data Collection report
 *
 * @param[in] data_reporting_session_id The Data reporting session id to record the report under.
 * @param[in] data_domain: The data domain of this report, e.g. "COMMUNICATION".
 * @param[in] report_time The report date-time in RFC3339 format.
 * @param[in] format The file format for the body (i.e. the file extension "json" or "xml").
 * @param[in] report_body The body of the report to store.
 *
 * @return @c true is the report was successfully stored or \c false if storage failed.
 */
bool data_collection_report_store(const char *data_reporting_session_id, const char *data_domain, const char *report_time, 
		const char *format, const char *report_body);	

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef DATA_REPORT_STORE_H */
