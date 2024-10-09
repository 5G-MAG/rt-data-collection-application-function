#ifndef _DATA_COLLECTION_OGS_LIST_SUPPORT_H_
#define _DATA_COLLECTION_OGS_LIST_SUPPORT_H_
/*
 * License: 5G-MAG Public License (v1.0)
 * Author: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#ifdef __cplusplus
#define OGS_CORE_INSIDE
#ifndef OGS_USE_TALLOC
#define OGS_USE_TALLOC 1
#endif
#include "core/ogs-list.h"
#undef OGS_CORE_INSIDE

extern "C" {
#else
#include "core/ogs-core.h"
#endif

typedef struct data_collection_lnode_s {
    ogs_lnode_t lnode;
    void *object;
    void (*free)(void*);
} data_collection_lnode_t;

DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_create(void *object, void (*free)(void*));
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_create_ref(const void *object);
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_copy(const data_collection_lnode_t *other);
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_copy_move(data_collection_lnode_t *other);
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_list_free(ogs_list_t *list);
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_lnode_free(data_collection_lnode_t *node);
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_hash_free(ogs_hash_t *hash, void (*value_free)(void*));

#ifdef __cplusplus
}
#endif



/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* _DATA_COLLECTION_OGS_LIST_SUPPORT_H_ */
