/**********************************************************************************************************************************
 * GnssPositioningMethodAndUsage - C interface to the GnssPositioningMethodAndUsage object
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

/*#include "GnssPositioningMethodAndUsage.h" already included by data-collection-sp/data-collection.h */
#include "GnssPositioningMethodAndUsage-internal.h"
#include "openapi/model/GnssPositioningMethodAndUsage.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_create(


)
{
    return reinterpret_cast<data_collection_model_gnss_positioning_method_and_usage_t*>(new std::shared_ptr<GnssPositioningMethodAndUsage>(new GnssPositioningMethodAndUsage(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_create_copy(const data_collection_model_gnss_positioning_method_and_usage_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_gnss_positioning_method_and_usage_t*>(new std::shared_ptr<GnssPositioningMethodAndUsage >(new GnssPositioningMethodAndUsage(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_create_move(data_collection_model_gnss_positioning_method_and_usage_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > *obj = reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_copy(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, const data_collection_model_gnss_positioning_method_and_usage_t *other)
{
    if (gnss_positioning_method_and_usage) {
        std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(gnss_positioning_method_and_usage);
        if (obj) {
            if (other) {
                const std::shared_ptr<GnssPositioningMethodAndUsage > &other_obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(other);
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
                const std::shared_ptr<GnssPositioningMethodAndUsage > &other_obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(other);
                if (other_obj) {
                    obj.reset(new GnssPositioningMethodAndUsage(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        gnss_positioning_method_and_usage = data_collection_model_gnss_positioning_method_and_usage_create_copy(other);
    }
    return gnss_positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_move(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, data_collection_model_gnss_positioning_method_and_usage_t *other)
{
    std::shared_ptr<GnssPositioningMethodAndUsage > *other_ptr = reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(other);

    if (gnss_positioning_method_and_usage) {
        std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(gnss_positioning_method_and_usage);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                gnss_positioning_method_and_usage = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return gnss_positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnss_positioning_method_and_usage_free(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage)
{
    if (!gnss_positioning_method_and_usage) return;
    delete reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(gnss_positioning_method_and_usage);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnss_positioning_method_and_usage_toJSON(const data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, bool as_request)
{
    if (!gnss_positioning_method_and_usage) return NULL;
    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(gnss_positioning_method_and_usage);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_gnss_positioning_method_and_usage_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_gnss_positioning_method_and_usage_t*>(new std::shared_ptr<GnssPositioningMethodAndUsage >(new GnssPositioningMethodAndUsage(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_positioning_method_and_usage_is_equal_to(const data_collection_model_gnss_positioning_method_and_usage_t *first, const data_collection_model_gnss_positioning_method_and_usage_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj2 = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj1 = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_positioning_mode_t* data_collection_model_gnss_positioning_method_and_usage_get_mode(const data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage)
{
    if (!obj_gnss_positioning_method_and_usage) {
        const data_collection_model_positioning_mode_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    if (!obj) {
        const data_collection_model_positioning_mode_t *result = NULL;
        return result;
    }

    typedef typename GnssPositioningMethodAndUsage::ModeType ResultFromType;
    const ResultFromType result_from = obj->getMode();
    const data_collection_model_positioning_mode_t *result = reinterpret_cast<const data_collection_model_positioning_mode_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_mode(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, const data_collection_model_positioning_mode_t* p_mode)
{
    if (!obj_gnss_positioning_method_and_usage) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_mode;
    typedef typename GnssPositioningMethodAndUsage::ModeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setMode(value)) return NULL;

    return obj_gnss_positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_mode_move(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, data_collection_model_positioning_mode_t* p_mode)
{
    if (!obj_gnss_positioning_method_and_usage) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_mode;
    typedef typename GnssPositioningMethodAndUsage::ModeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setMode(std::move(value))) return NULL;

    return obj_gnss_positioning_method_and_usage;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_gnss_id_t* data_collection_model_gnss_positioning_method_and_usage_get_gnss(const data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage)
{
    if (!obj_gnss_positioning_method_and_usage) {
        const data_collection_model_gnss_id_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    if (!obj) {
        const data_collection_model_gnss_id_t *result = NULL;
        return result;
    }

    typedef typename GnssPositioningMethodAndUsage::GnssType ResultFromType;
    const ResultFromType result_from = obj->getGnss();
    const data_collection_model_gnss_id_t *result = reinterpret_cast<const data_collection_model_gnss_id_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_gnss(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, const data_collection_model_gnss_id_t* p_gnss)
{
    if (!obj_gnss_positioning_method_and_usage) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_gnss;
    typedef typename GnssPositioningMethodAndUsage::GnssType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setGnss(value)) return NULL;

    return obj_gnss_positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_gnss_move(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, data_collection_model_gnss_id_t* p_gnss)
{
    if (!obj_gnss_positioning_method_and_usage) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_gnss;
    typedef typename GnssPositioningMethodAndUsage::GnssType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setGnss(std::move(value))) return NULL;

    return obj_gnss_positioning_method_and_usage;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_usage_t* data_collection_model_gnss_positioning_method_and_usage_get_usage(const data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage)
{
    if (!obj_gnss_positioning_method_and_usage) {
        const data_collection_model_usage_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    if (!obj) {
        const data_collection_model_usage_t *result = NULL;
        return result;
    }

    typedef typename GnssPositioningMethodAndUsage::UsageType ResultFromType;
    const ResultFromType result_from = obj->getUsage();
    const data_collection_model_usage_t *result = reinterpret_cast<const data_collection_model_usage_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_usage(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, const data_collection_model_usage_t* p_usage)
{
    if (!obj_gnss_positioning_method_and_usage) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_usage;
    typedef typename GnssPositioningMethodAndUsage::UsageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setUsage(value)) return NULL;

    return obj_gnss_positioning_method_and_usage;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_usage_move(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, data_collection_model_usage_t* p_usage)
{
    if (!obj_gnss_positioning_method_and_usage) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    if (!obj) return NULL;

    const auto &value_from = p_usage;
    typedef typename GnssPositioningMethodAndUsage::UsageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setUsage(std::move(value))) return NULL;

    return obj_gnss_positioning_method_and_usage;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnss_positioning_method_and_usage_make_lnode(data_collection_model_gnss_positioning_method_and_usage_t *p_gnss_positioning_method_and_usage)
{
    return data_collection_lnode_create(p_gnss_positioning_method_and_usage, reinterpret_cast<void(*)(void*)>(data_collection_model_gnss_positioning_method_and_usage_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_gnss_positioning_method_and_usage_refcount(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage)
{
    if (!obj_gnss_positioning_method_and_usage) return 0l;
    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

