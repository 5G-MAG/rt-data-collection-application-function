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

/** Copy the lnode but leave ownership with the original */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_copy(const data_collection_lnode_t *other)
{
    return data_collection_lnode_create_ref(other->object);
}

/** Copy the lnode, transferring ownership if the original had it */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_copy_move(data_collection_lnode_t *other)
{
    data_collection_lnode_t *ret;

    ret = data_collection_lnode_create_ref(other->object);
    if (other->free) {
        ret->free = other->free;
        other->free = NULL;
    }
    return ret;
}

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_list_free(ogs_list_t *list)
{
    if (!list) return;
    data_collection_list_clear(list);
    ogs_free(list);
}

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_list_clear(ogs_list_t *list)
{
    data_collection_lnode_t *node, *next;

    if (!list) return;

    ogs_list_for_each_safe(list, next, node) {
        ogs_list_remove(list, node);
        data_collection_lnode_free(node);
    }
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

DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_set_add_lnode(ogs_list_t *set /* [not-null] */,
                                                                    data_collection_lnode_t *new_val /* [not-null, transfer] */,
                                                                    bool(*cmp_fn)(const void *a, const void *b))
{
    bool found = false;
    data_collection_lnode_t *node;
    ogs_list_for_each(set, node) {
        if (cmp_fn(node->object, new_val->object)) {
            found = true;
            break;
        }
    }
    if (!found) {
        ogs_list_add(set, new_val);
        node = new_val;
    } else {
        data_collection_lnode_free(new_val);
    }
    return node;
}

/********* private functions ********/

static int __free_hash_callback(void *rec, const void *key, int klen, const void *value)
{
    _hash_free_context_t *ctx = (_hash_free_context_t*)rec;
    ogs_hash_set(ctx->hash, key, klen, NULL);
    if (ctx->value_free) ctx->value_free((void*)value);
    return 1;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
