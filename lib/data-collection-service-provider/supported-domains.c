/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "supported-domains.h"

ogs_lnode_t *list_node_create(void *data)
{
    ogs_lnode_t *node = NULL;

    ogs_assert(data);

    node = ogs_calloc(1, sizeof(ogs_lnode_t));
    ogs_assert(node);

    if (node == NULL) {
        ogs_assert_if_reached();
        return NULL;
    }
    node->data = data;

    return node;
}

ogs_list_t *list_create(void)
{
    ogs_list_t *list;

    list = ogs_calloc(1, sizeof(ogs_list_t));
    ogs_assert(list);

    if (list == NULL) {
        ogs_assert_if_reached();
        return NULL;
    }
    ogs_list_init(list);
    return list;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
