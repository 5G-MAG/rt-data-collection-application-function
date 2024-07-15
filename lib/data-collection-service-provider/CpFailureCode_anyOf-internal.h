#ifndef _CP_FAILURE_CODE_ANY_OF_INTERNAL_H_
#define _CP_FAILURE_CODE_ANY_OF_INTERNAL_H_

/**********************************************************************************************************************************
 * CpFailureCode_anyOf - C internal library interface to the CpFailureCode_anyOf object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/


#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_cp_failure_code_any_of_refcount(data_collection_model_cp_failure_code_any_of_t *CpFailureCode_anyOf);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _CP_FAILURE_CODE_ANY_OF_INTERNAL_H_ */

