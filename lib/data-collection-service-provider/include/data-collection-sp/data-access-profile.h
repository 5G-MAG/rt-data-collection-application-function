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

#ifndef DATA_COLLECTION_DATA_ACCESS_PROFILE_H
#define DATA_COLLECTION_DATA_ACCESS_PROFILE_H

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/***** Enumerations *****/

/***** Opaque Types *****/

typedef struct data_collection_data_access_profile_s data_collection_data_access_profile_t;

/***** Interface callbacks *****/

/***** Interface structures *****/

/***** Library function API *****/

/** Create a new DataAccessProfile */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_data_access_profile_t* data_collection_data_access_profile_create();

/** Destroy a DataAccessProfile */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_data_access_profile_free(data_collection_data_access_profile_t*);

#ifdef __cplusplus
}
#endif

#endif /* DATA_COLLECTION_DATA_ACCESS_PROFILE_H */
