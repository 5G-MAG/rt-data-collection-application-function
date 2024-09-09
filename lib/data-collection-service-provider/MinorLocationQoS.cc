/**********************************************************************************************************************************
 * MinorLocationQoS - C interface to the MinorLocationQoS object
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

/*#include "MinorLocationQoS.h" already included by data-collection-sp/data-collection.h */
#include "MinorLocationQoS-internal.h"
#include "openapi/model/MinorLocationQoS.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_create(

)
{
    return reinterpret_cast<data_collection_model_minor_location_qo_s_t*>(new std::shared_ptr<MinorLocationQoS>(new MinorLocationQoS(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_create_copy(const data_collection_model_minor_location_qo_s_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<const std::shared_ptr<MinorLocationQoS >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_minor_location_qo_s_t*>(new std::shared_ptr<MinorLocationQoS >(new MinorLocationQoS(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_create_move(data_collection_model_minor_location_qo_s_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MinorLocationQoS > *obj = reinterpret_cast<std::shared_ptr<MinorLocationQoS >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_copy(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, const data_collection_model_minor_location_qo_s_t *other)
{
    if (minor_location_qo_s) {
        std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<std::shared_ptr<MinorLocationQoS >*>(minor_location_qo_s);
        if (obj) {
            if (other) {
                const std::shared_ptr<MinorLocationQoS > &other_obj = *reinterpret_cast<const std::shared_ptr<MinorLocationQoS >*>(other);
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
                const std::shared_ptr<MinorLocationQoS > &other_obj = *reinterpret_cast<const std::shared_ptr<MinorLocationQoS >*>(other);
                if (other_obj) {
                    obj.reset(new MinorLocationQoS(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        minor_location_qo_s = data_collection_model_minor_location_qo_s_create_copy(other);
    }
    return minor_location_qo_s;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_move(data_collection_model_minor_location_qo_s_t *minor_location_qo_s, data_collection_model_minor_location_qo_s_t *other)
{
    std::shared_ptr<MinorLocationQoS > *other_ptr = reinterpret_cast<std::shared_ptr<MinorLocationQoS >*>(other);

    if (minor_location_qo_s) {
        std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<std::shared_ptr<MinorLocationQoS >*>(minor_location_qo_s);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                minor_location_qo_s = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return minor_location_qo_s;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_minor_location_qo_s_free(data_collection_model_minor_location_qo_s_t *minor_location_qo_s)
{
    if (!minor_location_qo_s) return;
    delete reinterpret_cast<std::shared_ptr<MinorLocationQoS >*>(minor_location_qo_s);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_minor_location_qo_s_toJSON(const data_collection_model_minor_location_qo_s_t *minor_location_qo_s, bool as_request)
{
    if (!minor_location_qo_s) return NULL;
    const std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<const std::shared_ptr<MinorLocationQoS >*>(minor_location_qo_s);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_minor_location_qo_s_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_minor_location_qo_s_t*>(new std::shared_ptr<MinorLocationQoS >(new MinorLocationQoS(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_minor_location_qo_s_is_equal_to(const data_collection_model_minor_location_qo_s_t *first, const data_collection_model_minor_location_qo_s_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MinorLocationQoS > &obj2 = *reinterpret_cast<const std::shared_ptr<MinorLocationQoS >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MinorLocationQoS > &obj1 = *reinterpret_cast<const std::shared_ptr<MinorLocationQoS >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_minor_location_qo_s_has_h_accuracy(const data_collection_model_minor_location_qo_s_t *obj_minor_location_qo_s)
{
    if (!obj_minor_location_qo_s) return false;

    const std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<const std::shared_ptr<MinorLocationQoS >*>(obj_minor_location_qo_s);
    if (!obj) return false;

    return obj->getHAccuracy().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_minor_location_qo_s_get_h_accuracy(const data_collection_model_minor_location_qo_s_t *obj_minor_location_qo_s)
{
    if (!obj_minor_location_qo_s) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<const std::shared_ptr<MinorLocationQoS >*>(obj_minor_location_qo_s);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename MinorLocationQoS::HAccuracyType ResultFromType;
    const ResultFromType &result_from = obj->getHAccuracy();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_h_accuracy(data_collection_model_minor_location_qo_s_t *obj_minor_location_qo_s, const float p_h_accuracy)
{
    if (!obj_minor_location_qo_s) return NULL;

    std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<std::shared_ptr<MinorLocationQoS >*>(obj_minor_location_qo_s);
    if (!obj) return NULL;

    const auto &value_from = p_h_accuracy;
    typedef typename MinorLocationQoS::HAccuracyType ValueType;

    ValueType value(value_from);

    if (!obj->setHAccuracy(value)) return NULL;

    return obj_minor_location_qo_s;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_h_accuracy_move(data_collection_model_minor_location_qo_s_t *obj_minor_location_qo_s, float p_h_accuracy)
{
    if (!obj_minor_location_qo_s) return NULL;

    std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<std::shared_ptr<MinorLocationQoS >*>(obj_minor_location_qo_s);
    if (!obj) return NULL;

    const auto &value_from = p_h_accuracy;
    typedef typename MinorLocationQoS::HAccuracyType ValueType;

    ValueType value(value_from);

    
    if (!obj->setHAccuracy(std::move(value))) return NULL;

    return obj_minor_location_qo_s;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_minor_location_qo_s_has_v_accuracy(const data_collection_model_minor_location_qo_s_t *obj_minor_location_qo_s)
{
    if (!obj_minor_location_qo_s) return false;

    const std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<const std::shared_ptr<MinorLocationQoS >*>(obj_minor_location_qo_s);
    if (!obj) return false;

    return obj->getVAccuracy().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_minor_location_qo_s_get_v_accuracy(const data_collection_model_minor_location_qo_s_t *obj_minor_location_qo_s)
{
    if (!obj_minor_location_qo_s) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<const std::shared_ptr<MinorLocationQoS >*>(obj_minor_location_qo_s);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename MinorLocationQoS::VAccuracyType ResultFromType;
    const ResultFromType &result_from = obj->getVAccuracy();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_v_accuracy(data_collection_model_minor_location_qo_s_t *obj_minor_location_qo_s, const float p_v_accuracy)
{
    if (!obj_minor_location_qo_s) return NULL;

    std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<std::shared_ptr<MinorLocationQoS >*>(obj_minor_location_qo_s);
    if (!obj) return NULL;

    const auto &value_from = p_v_accuracy;
    typedef typename MinorLocationQoS::VAccuracyType ValueType;

    ValueType value(value_from);

    if (!obj->setVAccuracy(value)) return NULL;

    return obj_minor_location_qo_s;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_minor_location_qo_s_t *data_collection_model_minor_location_qo_s_set_v_accuracy_move(data_collection_model_minor_location_qo_s_t *obj_minor_location_qo_s, float p_v_accuracy)
{
    if (!obj_minor_location_qo_s) return NULL;

    std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<std::shared_ptr<MinorLocationQoS >*>(obj_minor_location_qo_s);
    if (!obj) return NULL;

    const auto &value_from = p_v_accuracy;
    typedef typename MinorLocationQoS::VAccuracyType ValueType;

    ValueType value(value_from);

    
    if (!obj->setVAccuracy(std::move(value))) return NULL;

    return obj_minor_location_qo_s;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_minor_location_qo_s_make_lnode(data_collection_model_minor_location_qo_s_t *p_minor_location_qo_s)
{
    return data_collection_lnode_create(p_minor_location_qo_s, reinterpret_cast<void(*)(void*)>(data_collection_model_minor_location_qo_s_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_minor_location_qo_s_refcount(data_collection_model_minor_location_qo_s_t *obj_minor_location_qo_s)
{
    if (!obj_minor_location_qo_s) return 0l;
    std::shared_ptr<MinorLocationQoS > &obj = *reinterpret_cast<std::shared_ptr<MinorLocationQoS >*>(obj_minor_location_qo_s);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

