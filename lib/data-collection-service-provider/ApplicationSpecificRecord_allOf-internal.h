#ifndef _APPLICATION_SPECIFIC_RECORD_ALL_OF_INTERNAL_H_
#define _APPLICATION_SPECIFIC_RECORD_ALL_OF_INTERNAL_H_

/**********************************************************************************************************************************
 * ApplicationSpecificRecord_allOf - C internal library interface to the ApplicationSpecificRecord_allOf object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "AnyType.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_application_specific_record_all_of_refcount(data_collection_model_application_specific_record_all_of_t *ApplicationSpecificRecord_allOf);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _APPLICATION_SPECIFIC_RECORD_ALL_OF_INTERNAL_H_ */

