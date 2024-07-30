/**********************************************************************************************************************************
 * TrafficProfile - C interface to the TrafficProfile object
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

/*#include "TrafficProfile.h" already included by data-collection-sp/data-collection.h */
#include "TrafficProfile-internal.h"
#include "openapi/model/TrafficProfile.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_create()
{
    return reinterpret_cast<data_collection_model_traffic_profile_t*>(new std::shared_ptr<TrafficProfile>(new TrafficProfile()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_create_copy(const data_collection_model_traffic_profile_t *other)
{
    return reinterpret_cast<data_collection_model_traffic_profile_t*>(new std::shared_ptr<TrafficProfile >(new TrafficProfile(**reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_create_move(data_collection_model_traffic_profile_t *other)
{
    return reinterpret_cast<data_collection_model_traffic_profile_t*>(new std::shared_ptr<TrafficProfile >(std::move(*reinterpret_cast<std::shared_ptr<TrafficProfile >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_copy(data_collection_model_traffic_profile_t *traffic_profile, const data_collection_model_traffic_profile_t *other)
{
    std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<std::shared_ptr<TrafficProfile >*>(traffic_profile);
    *obj = **reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(other);
    return traffic_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_move(data_collection_model_traffic_profile_t *traffic_profile, data_collection_model_traffic_profile_t *other)
{
    std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<std::shared_ptr<TrafficProfile >*>(traffic_profile);
    obj = std::move(*reinterpret_cast<std::shared_ptr<TrafficProfile >*>(other));
    return traffic_profile;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_traffic_profile_free(data_collection_model_traffic_profile_t *traffic_profile)
{
    delete reinterpret_cast<std::shared_ptr<TrafficProfile >*>(traffic_profile);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_traffic_profile_toJSON(const data_collection_model_traffic_profile_t *traffic_profile, bool as_request)
{
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(traffic_profile);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_traffic_profile_t *data_collection_model_traffic_profile_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_traffic_profile_t*>(new std::shared_ptr<TrafficProfile >(new TrafficProfile(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_traffic_profile_is_equal_to(const data_collection_model_traffic_profile_t *first, const data_collection_model_traffic_profile_t *second)
{
    const std::shared_ptr<TrafficProfile > &obj1 = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(first);
    const std::shared_ptr<TrafficProfile > &obj2 = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_is_not_set(const data_collection_model_traffic_profile_t *obj_traffic_profile)
{
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    return obj->getValue() == TrafficProfile::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_is_non_standard(const data_collection_model_traffic_profile_t *obj_traffic_profile)
{
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    return obj->getValue() == TrafficProfile::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_traffic_profile_e data_collection_model_traffic_profile_get_enum(const data_collection_model_traffic_profile_t *obj_traffic_profile)
{
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    switch (obj->getValue()) {
    case TrafficProfile::Enum::NO_VAL:
        return DCM_TRAFFIC_PROFILE_NO_VAL;
    case TrafficProfile::Enum::VAL_SINGLE_TRANS_UL:
        return DCM_TRAFFIC_PROFILE_VAL_SINGLE_TRANS_UL;
    case TrafficProfile::Enum::VAL_SINGLE_TRANS_DL:
        return DCM_TRAFFIC_PROFILE_VAL_SINGLE_TRANS_DL;
    case TrafficProfile::Enum::VAL_DUAL_TRANS_UL_FIRST:
        return DCM_TRAFFIC_PROFILE_VAL_DUAL_TRANS_UL_FIRST;
    case TrafficProfile::Enum::VAL_DUAL_TRANS_DL_FIRST:
        return DCM_TRAFFIC_PROFILE_VAL_DUAL_TRANS_DL_FIRST;
    case TrafficProfile::Enum::VAL_MULTI_TRANS:
        return DCM_TRAFFIC_PROFILE_VAL_MULTI_TRANS;
    default:
        break;
    }
    return DCM_TRAFFIC_PROFILE_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_traffic_profile_get_string(const data_collection_model_traffic_profile_t *obj_traffic_profile)
{
    const std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<const std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_set_enum(data_collection_model_traffic_profile_t *obj_traffic_profile, data_collection_model_traffic_profile_e p_value)
{
    std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    switch (p_value) {
    case DCM_TRAFFIC_PROFILE_NO_VAL:
        *obj = TrafficProfile::Enum::NO_VAL;
        return true;
    case DCM_TRAFFIC_PROFILE_VAL_SINGLE_TRANS_UL:
        *obj = TrafficProfile::Enum::VAL_SINGLE_TRANS_UL;
        return true;
    case DCM_TRAFFIC_PROFILE_VAL_SINGLE_TRANS_DL:
        *obj = TrafficProfile::Enum::VAL_SINGLE_TRANS_DL;
        return true;
    case DCM_TRAFFIC_PROFILE_VAL_DUAL_TRANS_UL_FIRST:
        *obj = TrafficProfile::Enum::VAL_DUAL_TRANS_UL_FIRST;
        return true;
    case DCM_TRAFFIC_PROFILE_VAL_DUAL_TRANS_DL_FIRST:
        *obj = TrafficProfile::Enum::VAL_DUAL_TRANS_DL_FIRST;
        return true;
    case DCM_TRAFFIC_PROFILE_VAL_MULTI_TRANS:
        *obj = TrafficProfile::Enum::VAL_MULTI_TRANS;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_traffic_profile_set_string(data_collection_model_traffic_profile_t *obj_traffic_profile, const char *p_value)
{
    std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = TrafficProfile::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_traffic_profile_make_lnode(data_collection_model_traffic_profile_t *p_traffic_profile)
{
    return data_collection_lnode_create(p_traffic_profile, reinterpret_cast<void(*)(void*)>(data_collection_model_traffic_profile_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_traffic_profile_refcount(data_collection_model_traffic_profile_t *obj_traffic_profile)
{
    std::shared_ptr<TrafficProfile > &obj = *reinterpret_cast<std::shared_ptr<TrafficProfile >*>(obj_traffic_profile);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

