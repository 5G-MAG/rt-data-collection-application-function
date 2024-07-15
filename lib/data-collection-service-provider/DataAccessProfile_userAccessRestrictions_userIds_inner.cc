/**********************************************************************************************************************************
 * DataAccessProfile_userAccessRestrictions_userIds_inner - C interface to the DataAccessProfile_userAccessRestrictions_userIds_inner object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "DataAccessProfile_userAccessRestrictions_userIds_inner.h" already included by data-collection-sp/data-collection.h */
#include "DataAccessProfile_userAccessRestrictions_userIds_inner-internal.h"
#include "openapi/model/DataAccessProfile_userAccessRestrictions_userIds_inner.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_create()
{
    return reinterpret_cast<data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t*>(new std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner>(new DataAccessProfile_userAccessRestrictions_userIds_inner()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_create_copy(const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other)
{
    return reinterpret_cast<data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t*>(new std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >(new DataAccessProfile_userAccessRestrictions_userIds_inner(**reinterpret_cast<const std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_create_move(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other)
{
    return reinterpret_cast<data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t*>(new std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >(std::move(*reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_copy(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner, const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >*>(data_access_profile_user_access_restrictions_user_ids_inner);
    *obj = **reinterpret_cast<const std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >*>(other);
    return data_access_profile_user_access_restrictions_user_ids_inner;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_move(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner, data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *other)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >*>(data_access_profile_user_access_restrictions_user_ids_inner);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >*>(other));
    return data_access_profile_user_access_restrictions_user_ids_inner;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_free(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner)
{
    delete reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >*>(data_access_profile_user_access_restrictions_user_ids_inner);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_toJSON(const data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_access_profile_user_access_restrictions_user_ids_inner, bool as_request)
{
    const std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner > &obj = *reinterpret_cast<const std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >*>(data_access_profile_user_access_restrictions_user_ids_inner);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t*>(new std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >(new DataAccessProfile_userAccessRestrictions_userIds_inner(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_make_lnode(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *p_data_access_profile_user_access_restrictions_user_ids_inner)
{
    return data_collection_lnode_create(p_data_access_profile_user_access_restrictions_user_ids_inner, reinterpret_cast<void(*)(void*)>(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_data_access_profile_user_access_restrictions_user_ids_inner_refcount(data_collection_model_data_access_profile_user_access_restrictions_user_ids_inner_t *obj_data_access_profile_user_access_restrictions_user_ids_inner)
{
    std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner > &obj = *reinterpret_cast<std::shared_ptr<DataAccessProfile_userAccessRestrictions_userIds_inner >*>(obj_data_access_profile_user_access_restrictions_user_ids_inner);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

