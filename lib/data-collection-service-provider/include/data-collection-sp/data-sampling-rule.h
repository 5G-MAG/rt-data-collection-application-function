/*
 * License: 5G-MAG Public License (v1.0)
 * Authors: Dev Audsin <dev.audsin@bbc.co.uk>
 *          David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_DATA_SAMPLING_RULE_H
#define DATA_COLLECTION_DATA_SAMPLING_RULE_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "location-area-5g.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Constants *****/
#define DATA_COLLECTION_SAMPLING_PERIOD_NONE (-1)

/***** Enumerations *****/

/***** Opaque Types *****/

typedef struct data_collection_data_sampling_rule_s data_collection_data_sampling_rule_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new DataSamplingRule */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_sampling_rule_t*
data_collection_data_sampling_rule_create(data_collection_location_area_5g_t *location_filter /*transfer*/, double sampling_period);

/** Destroy a DataSamplingRule */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_sampling_rule_free(data_collection_data_sampling_rule_t*);

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_DATA_SAMPLING_RULE_H */
