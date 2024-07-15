#ifndef _DATA_COLLECTION_UNCERTAINTY_ELLIPSOID_H_
#define _DATA_COLLECTION_UNCERTAINTY_ELLIPSOID_H_

/**********************************************************************************************************************************
 * UncertaintyEllipsoid - Public C interface to the UncertaintyEllipsoid object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_uncertainty_ellipsoid_s data_collection_model_uncertainty_ellipsoid_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_create_copy(const data_collection_model_uncertainty_ellipsoid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_create_move(data_collection_model_uncertainty_ellipsoid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_copy(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, const data_collection_model_uncertainty_ellipsoid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_move(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, data_collection_model_uncertainty_ellipsoid_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_uncertainty_ellipsoid_free(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_uncertainty_ellipsoid_toJSON(const data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_uncertainty_ellipsoid_get_semi_major(const data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_semi_major(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, const float p_semi_major);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_semi_major_move(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, float p_semi_major);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_uncertainty_ellipsoid_get_semi_minor(const data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_semi_minor(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, const float p_semi_minor);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_semi_minor_move(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, float p_semi_minor);

DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_uncertainty_ellipsoid_get_vertical(const data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_vertical(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, const float p_vertical);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_vertical_move(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, float p_vertical);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_uncertainty_ellipsoid_get_orientation_major(const data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_orientation_major(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, const int32_t p_orientation_major);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipsoid_t *data_collection_model_uncertainty_ellipsoid_set_orientation_major_move(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid, int32_t p_orientation_major);

/* lnode helper for generating ogs_list_t nodes's of type UncertaintyEllipsoid */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_uncertainty_ellipsoid_make_lnode(data_collection_model_uncertainty_ellipsoid_t *uncertainty_ellipsoid);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_UNCERTAINTY_ELLIPSOID_H_ */

