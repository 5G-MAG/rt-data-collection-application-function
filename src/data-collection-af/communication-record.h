/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2022-2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DCAF_COMM_RECORD_H 
#define DCAF_COMM_RECORD_H 

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <features.h>

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif

#include "context.h"
#include "sbi-path.h"
#include "utilities.h"
#include "hash.h"
#include "data-collection-sp/data-collection.h"
#include "openapi/model/dcaf_api_data_report.h"
#include "openapi/model/dcaf_api_communication_record.h"

/* Local functions */

typedef struct dcaf_api_communication_record_s dcaf_api_communication_record_t;

extern const data_collection_data_report_handler_t communication_record_data_report_type;

#ifdef __cplusplus
}
#endif

#endif /* DCAF_COMM_RECORD_H */


/* vim:ts=8:sts=4:sw=4:expandtab:
 */
