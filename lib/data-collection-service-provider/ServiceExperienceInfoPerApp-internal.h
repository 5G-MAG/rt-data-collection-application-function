#ifndef _SERVICE_EXPERIENCE_INFO_PER_APP_INTERNAL_H_
#define _SERVICE_EXPERIENCE_INFO_PER_APP_INTERNAL_H_

/**********************************************************************************************************************************
 * ServiceExperienceInfoPerApp - C internal library interface to the ServiceExperienceInfoPerApp object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "ServiceExperienceInfoPerFlow.h"
// #include "AddrFqdn.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_service_experience_info_per_app_refcount(data_collection_model_service_experience_info_per_app_t *ServiceExperienceInfoPerApp);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _SERVICE_EXPERIENCE_INFO_PER_APP_INTERNAL_H_ */

