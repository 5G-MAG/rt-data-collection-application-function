/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef MSAF_HASH_H
#define MSAF_HASH_H

#include <gnutls/gnutls.h>
#include <gnutls/crypto.h>
#include "ogs-app.h"
#include "context.h"

#ifdef __cplusplus
extern "C" {
#endif

extern char *calculate_hash(const char *buf);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* MSAF_HASH_H */
