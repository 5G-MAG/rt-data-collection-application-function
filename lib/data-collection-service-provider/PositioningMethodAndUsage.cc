/**********************************************************************************************************************************
 * PositioningMethodAndUsage - C interface to the PositioningMethodAndUsage object
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

/*#include "PositioningMethodAndUsage.h" already included by data-collection-sp/data-collection.h */
#include "PositioningMethodAndUsage-internal.h"
#include "openapi/model/PositioningMethodAndUsage.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create(



)
{
    return reinterpret_cast<data_collection_model_positioning_method_and_usage_t*>(new std::shared_ptr<PositioningMethodAndUsage>(new PositioningMethodAndUsage(



)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create_copy(const data_collection_model_positioning_method_and_usage_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_positioning_method_and_usage_t*>(new std::shared_ptr<PositioningMethodAndUsage >(new PositioningMethodAndUsage(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_create_move(data_collection_model_positioning_method_and_usage_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > *obj = reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_copy(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, const data_collection_model_positioning_method_and_usage_t *other)
{
    if (positioning_method_and_usage) {
        std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(positioning_method_and_usage);
        if (obj) {
            if (other) {
                const std::shared_ptr<PositioningMethodAndUsage > &other_obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(other);
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
                const std::shared_ptr<PositioningMethodAndUsage > &other_obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(other);
                if (other_obj) {
                    obj.reset(new PositioningMethodAndUsage(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        positioning_method_and_usage = data_collection_model_positioning_method_and_usage_create_copy(other);
    }
    return positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_move(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, data_collection_model_positioning_method_and_usage_t *other)
{
    std::shared_ptr<PositioningMethodAndUsage > *other_ptr = reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(other);

    if (positioning_method_and_usage) {
        std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(positioning_method_and_usage);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                positioning_method_and_usage = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_positioning_method_and_usage_free(data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage)
{
    if (!positioning_method_and_usage) return;
    delete reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(positioning_method_and_usage);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_positioning_method_and_usage_toJSON(const data_collection_model_positioning_method_and_usage_t *positioning_method_and_usage, bool as_request)
{
    if (!positioning_method_and_usage) return NULL;
    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(positioning_method_and_usage);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_positioning_method_and_usage_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_positioning_method_and_usage_t*>(new std::shared_ptr<PositioningMethodAndUsage >(new PositioningMethodAndUsage(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_and_usage_is_equal_to(const data_collection_model_positioning_method_and_usage_t *first, const data_collection_model_positioning_method_and_usage_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PositioningMethodAndUsage > &obj2 = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PositioningMethodAndUsage > &obj1 = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_positioning_method_t* data_collection_model_positioning_method_and_usage_get_method(const data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    if (!obj_positioning_method_and_usage) {
        const data_collection_model_positioning_method_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) {
        const data_collection_model_positioning_method_t *result = NULL;
        return result;
    }

    typedef typename PositioningMethodAndUsage::MethodType ResultFromType;
    const ResultFromType &result_from = obj->getMethod();
    const data_collection_model_positioning_method_t *result = reinterpret_cast<const data_collection_model_positioning_method_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, const data_collection_model_positioning_method_t* p_method)
{
    if (!obj_positioning_method_and_usage) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_method;
    typedef typename PositioningMethodAndUsage::MethodType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setMethod(value)) return NULL;

    return obj_positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_move(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, data_collection_model_positioning_method_t* p_method)
{
    if (!obj_positioning_method_and_usage) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_method;
    typedef typename PositioningMethodAndUsage::MethodType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setMethod(std::move(value))) return NULL;
    data_collection_model_positioning_method_free
(p_method);

    return obj_positioning_method_and_usage;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_positioning_mode_t* data_collection_model_positioning_method_and_usage_get_mode(const data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    if (!obj_positioning_method_and_usage) {
        const data_collection_model_positioning_mode_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) {
        const data_collection_model_positioning_mode_t *result = NULL;
        return result;
    }

    typedef typename PositioningMethodAndUsage::ModeType ResultFromType;
    const ResultFromType &result_from = obj->getMode();
    const data_collection_model_positioning_mode_t *result = reinterpret_cast<const data_collection_model_positioning_mode_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_mode(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, const data_collection_model_positioning_mode_t* p_mode)
{
    if (!obj_positioning_method_and_usage) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_mode;
    typedef typename PositioningMethodAndUsage::ModeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setMode(value)) return NULL;

    return obj_positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_mode_move(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, data_collection_model_positioning_mode_t* p_mode)
{
    if (!obj_positioning_method_and_usage) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_mode;
    typedef typename PositioningMethodAndUsage::ModeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setMode(std::move(value))) return NULL;
    data_collection_model_positioning_mode_free
(p_mode);

    return obj_positioning_method_and_usage;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_usage_t* data_collection_model_positioning_method_and_usage_get_usage(const data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    if (!obj_positioning_method_and_usage) {
        const data_collection_model_usage_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) {
        const data_collection_model_usage_t *result = NULL;
        return result;
    }

    typedef typename PositioningMethodAndUsage::UsageType ResultFromType;
    const ResultFromType &result_from = obj->getUsage();
    const data_collection_model_usage_t *result = reinterpret_cast<const data_collection_model_usage_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_usage(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, const data_collection_model_usage_t* p_usage)
{
    if (!obj_positioning_method_and_usage) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_usage;
    typedef typename PositioningMethodAndUsage::UsageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUsage(value)) return NULL;

    return obj_positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_usage_move(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, data_collection_model_usage_t* p_usage)
{
    if (!obj_positioning_method_and_usage) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_usage;
    typedef typename PositioningMethodAndUsage::UsageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUsage(std::move(value))) return NULL;
    data_collection_model_usage_free
(p_usage);

    return obj_positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_method_and_usage_has_method_code(const data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    if (!obj_positioning_method_and_usage) return false;

    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) return false;

    return obj->getMethodCode().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_positioning_method_and_usage_get_method_code(const data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    if (!obj_positioning_method_and_usage) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PositioningMethodAndUsage::MethodCodeType ResultFromType;
    const ResultFromType &result_from = obj->getMethodCode();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_code(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, const int32_t p_method_code)
{
    if (!obj_positioning_method_and_usage) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_method_code;
    typedef typename PositioningMethodAndUsage::MethodCodeType ValueType;

    ValueType value(value_from);

    if (!obj->setMethodCode(value)) return NULL;

    return obj_positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_method_and_usage_t *data_collection_model_positioning_method_and_usage_set_method_code_move(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage, int32_t p_method_code)
{
    if (!obj_positioning_method_and_usage) return NULL;

    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_method_code;
    typedef typename PositioningMethodAndUsage::MethodCodeType ValueType;

    ValueType value(value_from);

    if (!obj->setMethodCode(std::move(value))) return NULL;

    return obj_positioning_method_and_usage;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_positioning_method_and_usage_make_lnode(data_collection_model_positioning_method_and_usage_t *p_positioning_method_and_usage)
{
    return data_collection_lnode_create(p_positioning_method_and_usage, reinterpret_cast<void(*)(void*)>(data_collection_model_positioning_method_and_usage_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_positioning_method_and_usage_refcount(data_collection_model_positioning_method_and_usage_t *obj_positioning_method_and_usage)
{
    if (!obj_positioning_method_and_usage) return 0l;
    std::shared_ptr<PositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<PositioningMethodAndUsage >*>(obj_positioning_method_and_usage);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

