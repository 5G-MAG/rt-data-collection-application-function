/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DCAF_REGEX_H
#define DCAF_REGEX_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <features.h>

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif

#include <unistd.h>
#include "ogs-app.h"
#include "context.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int time_nsec_check(const char *time);


#ifdef __cplusplus
}
#endif

#endif /* DCAF_REGEX_H */
