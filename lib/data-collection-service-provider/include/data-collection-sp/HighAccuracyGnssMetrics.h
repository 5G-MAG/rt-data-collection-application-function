#ifndef _DATA_COLLECTION_HIGH_ACCURACY_GNSS_METRICS_H_
#define _DATA_COLLECTION_HIGH_ACCURACY_GNSS_METRICS_H_

/**********************************************************************************************************************************
 * HighAccuracyGnssMetrics - Public C interface to the HighAccuracyGnssMetrics object
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

#include "FixType.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_high_accuracy_gnss_metrics_s data_collection_model_high_accuracy_gnss_metrics_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_create_copy(const data_collection_model_high_accuracy_gnss_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_create_move(data_collection_model_high_accuracy_gnss_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_copy(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const data_collection_model_high_accuracy_gnss_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, data_collection_model_high_accuracy_gnss_metrics_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_high_accuracy_gnss_metrics_free(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_high_accuracy_gnss_metrics_toJSON(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_is_equal_to(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const data_collection_model_high_accuracy_gnss_metrics_t *other_high_accuracy_gnss_metrics);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_has_nr_of_used_satellites(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_high_accuracy_gnss_metrics_get_nr_of_used_satellites(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_nr_of_used_satellites(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const int32_t p_nr_of_used_satellites);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_nr_of_used_satellites_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, int32_t p_nr_of_used_satellites);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_has_hdopi(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_high_accuracy_gnss_metrics_get_hdopi(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_hdopi(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const int32_t p_hdopi);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_hdopi_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, int32_t p_hdopi);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_has_pdopi(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_high_accuracy_gnss_metrics_get_pdopi(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_pdopi(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const int32_t p_pdopi);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_pdopi_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, int32_t p_pdopi);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_has_age(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_high_accuracy_gnss_metrics_get_age(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_age(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const int32_t p_age);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_age_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, int32_t p_age);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_high_accuracy_gnss_metrics_has_fix_type(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);


DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_fix_type_t* data_collection_model_high_accuracy_gnss_metrics_get_fix_type(const data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_fix_type(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, const data_collection_model_fix_type_t* p_fix_type);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_high_accuracy_gnss_metrics_t *data_collection_model_high_accuracy_gnss_metrics_set_fix_type_move(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics, data_collection_model_fix_type_t* p_fix_type);

/* lnode helper for generating ogs_list_t nodes's of type HighAccuracyGnssMetrics */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_high_accuracy_gnss_metrics_make_lnode(data_collection_model_high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_HIGH_ACCURACY_GNSS_METRICS_H_ */

