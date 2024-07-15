/**********************************************************************************************************************************
 * SvcExperience - C interface to the SvcExperience object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "SvcExperience.h" already included by data-collection-sp/data-collection.h */
#include "SvcExperience-internal.h"
#include "openapi/model/SvcExperience.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_create(


)
{
    return reinterpret_cast<data_collection_model_svc_experience_t*>(new std::shared_ptr<SvcExperience>(new SvcExperience(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_create_copy(const data_collection_model_svc_experience_t *other)
{
    return reinterpret_cast<data_collection_model_svc_experience_t*>(new std::shared_ptr<SvcExperience >(new SvcExperience(**reinterpret_cast<const std::shared_ptr<SvcExperience >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_create_move(data_collection_model_svc_experience_t *other)
{
    return reinterpret_cast<data_collection_model_svc_experience_t*>(new std::shared_ptr<SvcExperience >(std::move(*reinterpret_cast<std::shared_ptr<SvcExperience >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_copy(data_collection_model_svc_experience_t *svc_experience, const data_collection_model_svc_experience_t *other)
{
    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(svc_experience);
    *obj = **reinterpret_cast<const std::shared_ptr<SvcExperience >*>(other);
    return svc_experience;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_move(data_collection_model_svc_experience_t *svc_experience, data_collection_model_svc_experience_t *other)
{
    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(svc_experience);
    obj = std::move(*reinterpret_cast<std::shared_ptr<SvcExperience >*>(other));
    return svc_experience;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_svc_experience_free(data_collection_model_svc_experience_t *svc_experience)
{
    delete reinterpret_cast<std::shared_ptr<SvcExperience >*>(svc_experience);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_svc_experience_toJSON(const data_collection_model_svc_experience_t *svc_experience, bool as_request)
{
    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(svc_experience);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_svc_experience_t*>(new std::shared_ptr<SvcExperience >(new SvcExperience(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_svc_experience_get_mos(const data_collection_model_svc_experience_t *obj_svc_experience)
{
    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    typedef typename SvcExperience::MosType ResultFromType;
    const ResultFromType result_from = obj->getMos();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_mos(data_collection_model_svc_experience_t *obj_svc_experience, const float p_mos)
{
    if (obj_svc_experience == NULL) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    const auto &value_from = p_mos;
    typedef typename SvcExperience::MosType ValueType;

    ValueType value = value_from;
    if (!obj->setMos(value)) return NULL;
    return obj_svc_experience;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_mos_move(data_collection_model_svc_experience_t *obj_svc_experience, float p_mos)
{
    if (obj_svc_experience == NULL) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    const auto &value_from = p_mos;
    typedef typename SvcExperience::MosType ValueType;

    ValueType value = value_from;
    
    if (!obj->setMos(std::move(value))) return NULL;
    return obj_svc_experience;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_svc_experience_get_upper_range(const data_collection_model_svc_experience_t *obj_svc_experience)
{
    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    typedef typename SvcExperience::UpperRangeType ResultFromType;
    const ResultFromType result_from = obj->getUpperRange();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_upper_range(data_collection_model_svc_experience_t *obj_svc_experience, const float p_upper_range)
{
    if (obj_svc_experience == NULL) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    const auto &value_from = p_upper_range;
    typedef typename SvcExperience::UpperRangeType ValueType;

    ValueType value = value_from;
    if (!obj->setUpperRange(value)) return NULL;
    return obj_svc_experience;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_upper_range_move(data_collection_model_svc_experience_t *obj_svc_experience, float p_upper_range)
{
    if (obj_svc_experience == NULL) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    const auto &value_from = p_upper_range;
    typedef typename SvcExperience::UpperRangeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUpperRange(std::move(value))) return NULL;
    return obj_svc_experience;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const float data_collection_model_svc_experience_get_lower_range(const data_collection_model_svc_experience_t *obj_svc_experience)
{
    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    typedef typename SvcExperience::LowerRangeType ResultFromType;
    const ResultFromType result_from = obj->getLowerRange();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_lower_range(data_collection_model_svc_experience_t *obj_svc_experience, const float p_lower_range)
{
    if (obj_svc_experience == NULL) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    const auto &value_from = p_lower_range;
    typedef typename SvcExperience::LowerRangeType ValueType;

    ValueType value = value_from;
    if (!obj->setLowerRange(value)) return NULL;
    return obj_svc_experience;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_lower_range_move(data_collection_model_svc_experience_t *obj_svc_experience, float p_lower_range)
{
    if (obj_svc_experience == NULL) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    const auto &value_from = p_lower_range;
    typedef typename SvcExperience::LowerRangeType ValueType;

    ValueType value = value_from;
    
    if (!obj->setLowerRange(std::move(value))) return NULL;
    return obj_svc_experience;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_svc_experience_make_lnode(data_collection_model_svc_experience_t *p_svc_experience)
{
    return data_collection_lnode_create(p_svc_experience, reinterpret_cast<void(*)(void*)>(data_collection_model_svc_experience_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_svc_experience_refcount(data_collection_model_svc_experience_t *obj_svc_experience)
{
    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

