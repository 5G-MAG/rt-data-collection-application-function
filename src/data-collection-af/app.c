/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "ogs-app.h"

#include "init.h"

int app_initialize(const char *const argv[])
{
    int rv;

    rv = dcaf_initialize();
    if (rv != OGS_OK) {
        ogs_warn("Failed to intialize 5G Data Collection AF");
        return rv;
    }
    ogs_info("5G Data Collection AF initialize...done");

    return OGS_OK;
}

void app_terminate(void)
{
    dcaf_terminate();
    ogs_info("5G Data Collection AF terminate...done");
}

