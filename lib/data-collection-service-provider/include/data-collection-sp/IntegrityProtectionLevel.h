#ifndef _DATA_COLLECTION_INTEGRITY_PROTECTION_LEVEL_H_
#define _DATA_COLLECTION_INTEGRITY_PROTECTION_LEVEL_H_

/**********************************************************************************************************************************
 * IntegrityProtectionLevel - Public C interface to the IntegrityProtectionLevel object
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

typedef struct data_collection_model_integrity_protection_level_s data_collection_model_integrity_protection_level_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_create_copy(const data_collection_model_integrity_protection_level_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_create_move(data_collection_model_integrity_protection_level_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_copy(data_collection_model_integrity_protection_level_t *integrity_protection_level, const data_collection_model_integrity_protection_level_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_move(data_collection_model_integrity_protection_level_t *integrity_protection_level, data_collection_model_integrity_protection_level_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_integrity_protection_level_free(data_collection_model_integrity_protection_level_t *integrity_protection_level);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_integrity_protection_level_toJSON(const data_collection_model_integrity_protection_level_t *integrity_protection_level, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_protection_level_is_equal_to(const data_collection_model_integrity_protection_level_t *integrity_protection_level, const data_collection_model_integrity_protection_level_t *other_integrity_protection_level);


DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_integrity_protection_level_get_horizontal_protection_level(const data_collection_model_integrity_protection_level_t *integrity_protection_level);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_horizontal_protection_level(data_collection_model_integrity_protection_level_t *integrity_protection_level, const int32_t p_horizontal_protection_level);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_horizontal_protection_level_move(data_collection_model_integrity_protection_level_t *integrity_protection_level, int32_t p_horizontal_protection_level);

DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_integrity_protection_level_get_vertical_protection_level(const data_collection_model_integrity_protection_level_t *integrity_protection_level);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_vertical_protection_level(data_collection_model_integrity_protection_level_t *integrity_protection_level, const int32_t p_vertical_protection_level);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_vertical_protection_level_move(data_collection_model_integrity_protection_level_t *integrity_protection_level, int32_t p_vertical_protection_level);

/* lnode helper for generating ogs_list_t nodes's of type IntegrityProtectionLevel */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_integrity_protection_level_make_lnode(data_collection_model_integrity_protection_level_t *integrity_protection_level);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_INTEGRITY_PROTECTION_LEVEL_H_ */
