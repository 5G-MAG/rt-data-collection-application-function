#ifndef _ML_MODEL_INTER_IND_INTERNAL_H_
#define _ML_MODEL_INTER_IND_INTERNAL_H_

/**********************************************************************************************************************************
 * MlModelInterInd - C internal library interface to the MlModelInterInd object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

// #include "NwdafEvent.h"

#include "data-collection-sp/data-collection.h"

#ifdef __cplusplus
extern "C" {
#endif

/***** Internal library protected functions *****/

extern long _model_ml_model_inter_ind_refcount(data_collection_model_ml_model_inter_ind_t *MlModelInterInd);

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _ML_MODEL_INTER_IND_INTERNAL_H_ */

