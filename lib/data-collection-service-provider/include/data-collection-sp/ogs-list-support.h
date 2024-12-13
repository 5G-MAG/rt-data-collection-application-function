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

/** \addtogroup dcsp
 * @{
 */

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

/** Generic list node object for data collection
 *
 * Used to create a node object that can be added to ogs_list_t .
 */

typedef struct data_collection_lnode_s {
    ogs_lnode_t lnode;   /**< The Open5GS list node type */ 
    void *object;        /**< Data object that needs to be added to the list */
    void (*free)(void*); /**< Routine to free the object */
} data_collection_lnode_t;

/**
 * Creates a Data Collection list node object
 *
 * @param object Data object that needs to be added to the list.
 * @param free Function to free the data object.
 *
 * @return Returns a new list node object with data that needs to be added to be list.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_create(void *object, void (*free)(void*));

/**
 * Creates a Data Collection list node object
 *
 * @param object Data object that needs to be added to the list.
 *
 * @return Returns a new list node object with data that needs to be added to be list.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_create_ref(const void *object);

/** Creates a new Data Collection list node object that refers to the same object as \a other.
 *
 * Creates a copy of \a other, referring to the same object but leaving the ownership of the object with \a other.
 *
 * @param other Data object to be copied.
 *
 * @return A copy of the provided list node object without ownership.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_copy(const data_collection_lnode_t *other);

/** Create a new Data Collection list node object, moving the referenced object from another list node.
 *
 * Creates a copy of \a other and transfers ownership of the object referenced by \a other to the new list node.
 *
 * @param other Data Collection list node to be copied.
 *
 * @return A copy of the provided lnode with ownership of resources transferred to the new copy.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_lnode_copy_move(data_collection_lnode_t *other);

/** Free the list.
 * @param list List that needs to be freed.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_list_free(ogs_list_t *list);

/** Clear a list.
 *
 * This will free all nodes currently in the list and leave the list empty.
 *
 * @param list List to be cleared.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_list_clear(ogs_list_t *list);

/**
 * Free the list node
 * @param node The list node that needs to be freed.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_lnode_free(data_collection_lnode_t *node);

/**
 * Free the hash map
 * @param hash The hash map that needs to be freed.
 * @param value_free Routine to free the values in the hash.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_hash_free(ogs_hash_t *hash, void (*value_free)(void*));

/**
 * Add an lnode to a set.
 *
 * This will use the @a cmp_fn to check if @a new_val is a new unique value in @a set. If a value already exists with compares as
 * the same as @a new_val then the existing value is returned and @a new_val is freed. If no existing match is found then
 * @a new_val is added to the set @a set and also returned.
 *
 * @param set The set to add the element to.
 * @param new_val The value to add if not already in the set.
 * @param cmp_fn A function that can compare the objects held in the lnodes of the set.
 * @return @a new_val if the value was not already present in @a set, or the existing value that matches.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_set_add_lnode(ogs_list_t *set /* [not-null] */,
                                                                    data_collection_lnode_t *new_val /* [not-null, transfer] */,
                                                                    bool(*cmp_fn)(const void *a, const void *b));

/** @} */

#ifdef __cplusplus
}
#endif



/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* _DATA_COLLECTION_OGS_LIST_SUPPORT_H_ */
