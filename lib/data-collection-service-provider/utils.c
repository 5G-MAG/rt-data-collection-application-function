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

#include "data-collection-service-producer.h"

#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Library Internals */
char *_sockaddr_to_string(const ogs_sockaddr_t *addr)
{
    return ogs_ipstrdup((ogs_sockaddr_t*)addr); /* safe to remove const as OGS routines just use it read-only */
}


#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
