/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "ogs-core.h"
#include "ogs-sbi.h"

#include "context.h"
#include "server.h"
#include "data-collection-sp/data-collection-version.h"
#include "utilities.h"

#ifdef __cplusplus
extern "C" {
#endif

static char *nf_name = NULL;
static nf_server_app_metadata_t app_metadata = { DATA_COLLECTION_NAME, DATA_COLLECTION_VERSION, NULL };

const nf_server_app_metadata_t *data_collection_lib_metadata()
{
    if (!nf_name) {
        if (!data_collection_self()->server_name[0]) data_collection_context_server_name_set();
        nf_name = ogs_msprintf("5G Data Collection Library - %s", data_collection_self()->server_name);
        ogs_assert(nf_name);
        app_metadata.server_name = nf_name;
    }

    return &app_metadata;
}

void data_collection_free_agent_name()
{
    if (nf_name) ogs_free(nf_name);
}


#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

