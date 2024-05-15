/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_NETWORK_AREA_INFO_H
#define DATA_COLLECTION_NETWORK_AREA_INFO_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "ogs-core.h"

#include "e-utra-cell-id.h"
#include "nr-cell-id.h"
#include "global-ran-node-id.h"
#include "tracking-area-id.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Constants *****/

/***** Enumerations *****/

/***** Opaque Types *****/

typedef struct data_collection_network_area_info_s data_collection_network_area_info_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new NetworkAreaInfo */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_network_area_info_t* data_collection_network_area_info_create(
                    ogs_list_t *e_utra_cell_ids,
                    ogs_list_t *nr_cell_ids,
                    ogs_list_t *global_ran_node_ids,
                    ogs_list_t *tracking_area_ids);

/** Destroy a NetworkAreaInfo */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_network_area_info_free(data_collection_network_area_info_t*);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* DATA_COLLECTION_DATA_NETWORK_AREA_INFO_H */
