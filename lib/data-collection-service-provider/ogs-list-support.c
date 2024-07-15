/*
 * License: 5G-MAG Public License (v1.0)
 * Author: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include "data-collection-sp/data-collection.h"

typedef struct _hash_free_context_s {
    ogs_hash_t *hash;
    void (*value_free)(void*);
} _hash_free_context_t;

static int __free_hash_callback(void *rec, const void *key, int klen, const void *value);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_create(void *object, void (*free_fn)(void *object))
{
    data_collection_lnode_t *node;

    node = ogs_calloc(1, sizeof(*node));
    ogs_assert(node);

    node->object = object;
    node->free = free_fn;

    return node;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_create_ref(const void *object)
{
    return data_collection_lnode_create((void*)object, NULL);
}

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_list_free(ogs_list_t *list)
{
    data_collection_lnode_t *node, *next;
    
    if (!list) return;

    ogs_list_for_each_safe(list, next, node) {
        ogs_list_remove(list, node);
        data_collection_lnode_free(node);
    }
    ogs_free(list);
}

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_lnode_free(data_collection_lnode_t *node)
{
    if (!node) return;
    if (node->free) node->free(node->object);
    ogs_free(node);
}

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_hash_free(ogs_hash_t *hash, void (*value_free)(void*))
{
    if (!hash) return;
    _hash_free_context_t ctx = {hash, value_free};
    ogs_hash_do(__free_hash_callback, &ctx, hash);
    ogs_hash_destroy(hash);
}

static int __free_hash_callback(void *rec, const void *key, int klen, const void *value)
{
    _hash_free_context_t *ctx = (_hash_free_context_t*)rec;
    ogs_hash_set(ctx->hash, key, klen, NULL);
    if (ctx->value_free) ctx->value_free((void*)value);
    return 1;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
