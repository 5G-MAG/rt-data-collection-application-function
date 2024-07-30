#ifndef _DATA_COLLECTION_DATA_DOMAIN_H_
#define _DATA_COLLECTION_DATA_DOMAIN_H_

/**********************************************************************************************************************************
 * DataDomain - Public C interface to the DataDomain object
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

#include "DataDomain_anyOf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_data_domain_s data_collection_model_data_domain_t;

typedef enum {
    DCM_DATA_DOMAIN_NO_VAL,
    DCM_DATA_DOMAIN_VAL_SERVICE_EXPERIENCE,
    DCM_DATA_DOMAIN_VAL_LOCATION,
    DCM_DATA_DOMAIN_VAL_COMMUNICATION,
    DCM_DATA_DOMAIN_VAL_PERFORMANCE,
    DCM_DATA_DOMAIN_VAL_APPLICATION_SPECIFIC,
    DCM_DATA_DOMAIN_VAL_MS_ANBR_NETWORK_ASSISTANCE,
    DCM_DATA_DOMAIN_VAL_MS_ACCESS_ACTIVITY,
    DCM_DATA_DOMAIN_VAL_PLANNED_TRIPS,
    DCM_DATA_DOMAIN_OTHER
} data_collection_model_data_domain_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_create_copy(const data_collection_model_data_domain_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_create_move(data_collection_model_data_domain_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_copy(data_collection_model_data_domain_t *data_domain, const data_collection_model_data_domain_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_move(data_collection_model_data_domain_t *data_domain, data_collection_model_data_domain_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_data_domain_free(data_collection_model_data_domain_t *data_domain);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_data_domain_toJSON(const data_collection_model_data_domain_t *data_domain, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_t *data_collection_model_data_domain_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_is_equal_to(const data_collection_model_data_domain_t *data_domain, const data_collection_model_data_domain_t *other_data_domain);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_is_not_set(const data_collection_model_data_domain_t *data_domain);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_is_non_standard(const data_collection_model_data_domain_t *data_domain);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_data_domain_e data_collection_model_data_domain_get_enum(const data_collection_model_data_domain_t *data_domain);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_data_domain_get_string(const data_collection_model_data_domain_t *data_domain);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_set_enum(data_collection_model_data_domain_t *data_domain, data_collection_model_data_domain_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_domain_set_string(data_collection_model_data_domain_t *data_domain, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type DataDomain */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_data_domain_make_lnode(data_collection_model_data_domain_t *data_domain);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DATA_DOMAIN_H_ */

