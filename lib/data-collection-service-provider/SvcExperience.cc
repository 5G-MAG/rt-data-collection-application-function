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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_create(


)
{
    return reinterpret_cast<data_collection_model_svc_experience_t*>(new std::shared_ptr<SvcExperience>(new SvcExperience(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_create_copy(const data_collection_model_svc_experience_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_svc_experience_t*>(new std::shared_ptr<SvcExperience >(new SvcExperience(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_create_move(data_collection_model_svc_experience_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<SvcExperience > *obj = reinterpret_cast<std::shared_ptr<SvcExperience >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_copy(data_collection_model_svc_experience_t *svc_experience, const data_collection_model_svc_experience_t *other)
{
    if (svc_experience) {
        std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(svc_experience);
        if (obj) {
            if (other) {
                const std::shared_ptr<SvcExperience > &other_obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(other);
                if (other_obj) {
                    *obj = *other_obj;
                } else {
                    obj.reset();
                }
            } else {
                obj.reset();
            }
        } else {
            if (other) {
                const std::shared_ptr<SvcExperience > &other_obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(other);
                if (other_obj) {
                    obj.reset(new SvcExperience(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        svc_experience = data_collection_model_svc_experience_create_copy(other);
    }
    return svc_experience;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_move(data_collection_model_svc_experience_t *svc_experience, data_collection_model_svc_experience_t *other)
{
    std::shared_ptr<SvcExperience > *other_ptr = reinterpret_cast<std::shared_ptr<SvcExperience >*>(other);

    if (svc_experience) {
        std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(svc_experience);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                svc_experience = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return svc_experience;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_svc_experience_free(data_collection_model_svc_experience_t *svc_experience)
{
    if (!svc_experience) return;
    delete reinterpret_cast<std::shared_ptr<SvcExperience >*>(svc_experience);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_svc_experience_toJSON(const data_collection_model_svc_experience_t *svc_experience, bool as_request)
{
    if (!svc_experience) return NULL;
    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(svc_experience);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_svc_experience_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_svc_experience_is_equal_to(const data_collection_model_svc_experience_t *first, const data_collection_model_svc_experience_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<SvcExperience > &obj2 = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<SvcExperience > &obj1 = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(first);
    if (!second) {
        if (!obj1) return true;
        return false;
    }
    
    /* check what std::shared_ptr objects are pointing to */
    if (obj1 == obj2) return true;
    if (!obj1) return false;
    if (!obj2) return false;

    /* different shared_ptr objects pointing to different instances, so compare instances */
    return (*obj1 == *obj2);
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_svc_experience_has_mos(const data_collection_model_svc_experience_t *obj_svc_experience)
{
    if (!obj_svc_experience) return false;

    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) return false;

    return obj->getMos().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_svc_experience_get_mos(const data_collection_model_svc_experience_t *obj_svc_experience)
{
    if (!obj_svc_experience) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename SvcExperience::MosType ResultFromType;
    const ResultFromType result_from = obj->getMos();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_mos(data_collection_model_svc_experience_t *obj_svc_experience, const float p_mos)
{
    if (!obj_svc_experience) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) return NULL;

    const auto &value_from = p_mos;
    typedef typename SvcExperience::MosType ValueType;

    ValueType value(value_from);

    if (!obj->setMos(value)) return NULL;

    return obj_svc_experience;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_mos_move(data_collection_model_svc_experience_t *obj_svc_experience, float p_mos)
{
    if (!obj_svc_experience) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) return NULL;

    const auto &value_from = p_mos;
    typedef typename SvcExperience::MosType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMos(std::move(value))) return NULL;

    return obj_svc_experience;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_svc_experience_has_upper_range(const data_collection_model_svc_experience_t *obj_svc_experience)
{
    if (!obj_svc_experience) return false;

    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) return false;

    return obj->getUpperRange().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_svc_experience_get_upper_range(const data_collection_model_svc_experience_t *obj_svc_experience)
{
    if (!obj_svc_experience) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename SvcExperience::UpperRangeType ResultFromType;
    const ResultFromType result_from = obj->getUpperRange();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_upper_range(data_collection_model_svc_experience_t *obj_svc_experience, const float p_upper_range)
{
    if (!obj_svc_experience) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) return NULL;

    const auto &value_from = p_upper_range;
    typedef typename SvcExperience::UpperRangeType ValueType;

    ValueType value(value_from);

    if (!obj->setUpperRange(value)) return NULL;

    return obj_svc_experience;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_upper_range_move(data_collection_model_svc_experience_t *obj_svc_experience, float p_upper_range)
{
    if (!obj_svc_experience) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) return NULL;

    const auto &value_from = p_upper_range;
    typedef typename SvcExperience::UpperRangeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setUpperRange(std::move(value))) return NULL;

    return obj_svc_experience;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_svc_experience_has_lower_range(const data_collection_model_svc_experience_t *obj_svc_experience)
{
    if (!obj_svc_experience) return false;

    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) return false;

    return obj->getLowerRange().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_svc_experience_get_lower_range(const data_collection_model_svc_experience_t *obj_svc_experience)
{
    if (!obj_svc_experience) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<const std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename SvcExperience::LowerRangeType ResultFromType;
    const ResultFromType result_from = obj->getLowerRange();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_lower_range(data_collection_model_svc_experience_t *obj_svc_experience, const float p_lower_range)
{
    if (!obj_svc_experience) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) return NULL;

    const auto &value_from = p_lower_range;
    typedef typename SvcExperience::LowerRangeType ValueType;

    ValueType value(value_from);

    if (!obj->setLowerRange(value)) return NULL;

    return obj_svc_experience;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_svc_experience_t *data_collection_model_svc_experience_set_lower_range_move(data_collection_model_svc_experience_t *obj_svc_experience, float p_lower_range)
{
    if (!obj_svc_experience) return NULL;

    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    if (!obj) return NULL;

    const auto &value_from = p_lower_range;
    typedef typename SvcExperience::LowerRangeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setLowerRange(std::move(value))) return NULL;

    return obj_svc_experience;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_svc_experience_make_lnode(data_collection_model_svc_experience_t *p_svc_experience)
{
    return data_collection_lnode_create(p_svc_experience, reinterpret_cast<void(*)(void*)>(data_collection_model_svc_experience_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_svc_experience_refcount(data_collection_model_svc_experience_t *obj_svc_experience)
{
    if (!obj_svc_experience) return 0l;
    std::shared_ptr<SvcExperience > &obj = *reinterpret_cast<std::shared_ptr<SvcExperience >*>(obj_svc_experience);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

