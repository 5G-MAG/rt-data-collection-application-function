/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_LIB_METADATA_H
#define DATA_COLLECTION_LIB_METADATA_H

#include "ogs-core.h"
#include "ogs-sbi.h"
#include "server.h"

#ifdef __cplusplus
extern "C" {
#endif


const nf_server_app_metadata_t *data_collection_lib_metadata();
void data_collection_free_agent_name();

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_LIB_METADATA_H */
