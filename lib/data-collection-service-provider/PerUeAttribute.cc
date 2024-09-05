/**********************************************************************************************************************************
 * PerUeAttribute - C interface to the PerUeAttribute object
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

/*#include "PerUeAttribute.h" already included by data-collection-sp/data-collection.h */
#include "PerUeAttribute-internal.h"
#include "openapi/model/PerUeAttribute.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create(



)
{
    return reinterpret_cast<data_collection_model_per_ue_attribute_t*>(new std::shared_ptr<PerUeAttribute>(new PerUeAttribute(



)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create_copy(const data_collection_model_per_ue_attribute_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_per_ue_attribute_t*>(new std::shared_ptr<PerUeAttribute >(new PerUeAttribute(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_create_move(data_collection_model_per_ue_attribute_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PerUeAttribute > *obj = reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_copy(data_collection_model_per_ue_attribute_t *per_ue_attribute, const data_collection_model_per_ue_attribute_t *other)
{
    if (per_ue_attribute) {
        std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(per_ue_attribute);
        if (obj) {
            if (other) {
                const std::shared_ptr<PerUeAttribute > &other_obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(other);
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
                const std::shared_ptr<PerUeAttribute > &other_obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(other);
                if (other_obj) {
                    obj.reset(new PerUeAttribute(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        per_ue_attribute = data_collection_model_per_ue_attribute_create_copy(other);
    }
    return per_ue_attribute;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_move(data_collection_model_per_ue_attribute_t *per_ue_attribute, data_collection_model_per_ue_attribute_t *other)
{
    std::shared_ptr<PerUeAttribute > *other_ptr = reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(other);

    if (per_ue_attribute) {
        std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(per_ue_attribute);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                per_ue_attribute = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return per_ue_attribute;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_per_ue_attribute_free(data_collection_model_per_ue_attribute_t *per_ue_attribute)
{
    if (!per_ue_attribute) return;
    delete reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(per_ue_attribute);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_per_ue_attribute_toJSON(const data_collection_model_per_ue_attribute_t *per_ue_attribute, bool as_request)
{
    if (!per_ue_attribute) return NULL;
    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(per_ue_attribute);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_per_ue_attribute_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_per_ue_attribute_t*>(new std::shared_ptr<PerUeAttribute >(new PerUeAttribute(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_is_equal_to(const data_collection_model_per_ue_attribute_t *first, const data_collection_model_per_ue_attribute_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PerUeAttribute > &obj2 = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PerUeAttribute > &obj1 = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_ue_dest(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    if (!obj_per_ue_attribute) return false;

    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return false;

    return obj->getUeDest().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_per_ue_attribute_get_ue_dest(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    if (!obj_per_ue_attribute) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    typedef typename PerUeAttribute::UeDestType ResultFromType;
    const ResultFromType result_from = obj->getUeDest();
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_ue_dest(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, const data_collection_model_location_area5_g_t* p_ue_dest)
{
    if (!obj_per_ue_attribute) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return NULL;

    const auto &value_from = p_ue_dest;
    typedef typename PerUeAttribute::UeDestType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setUeDest(value)) return NULL;

    return obj_per_ue_attribute;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_ue_dest_move(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, data_collection_model_location_area5_g_t* p_ue_dest)
{
    if (!obj_per_ue_attribute) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return NULL;

    const auto &value_from = p_ue_dest;
    typedef typename PerUeAttribute::UeDestType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setUeDest(std::move(value))) return NULL;

    return obj_per_ue_attribute;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_route(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    if (!obj_per_ue_attribute) return false;

    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return false;

    return obj->getRoute().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_per_ue_attribute_get_route(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    if (!obj_per_ue_attribute) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerUeAttribute::RouteType ResultFromType;
    const ResultFromType result_from = obj->getRoute();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_route(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, const char* p_route)
{
    if (!obj_per_ue_attribute) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return NULL;

    const auto &value_from = p_route;
    typedef typename PerUeAttribute::RouteType ValueType;

    ValueType value(value_from);

    if (!obj->setRoute(value)) return NULL;

    return obj_per_ue_attribute;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_route_move(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, char* p_route)
{
    if (!obj_per_ue_attribute) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return NULL;

    const auto &value_from = p_route;
    typedef typename PerUeAttribute::RouteType ValueType;

    ValueType value(value_from);

    
    if (!obj->setRoute(std::move(value))) return NULL;

    return obj_per_ue_attribute;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_avg_speed(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    if (!obj_per_ue_attribute) return false;

    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return false;

    return obj->getAvgSpeed().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_per_ue_attribute_get_avg_speed(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    if (!obj_per_ue_attribute) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerUeAttribute::AvgSpeedType ResultFromType;
    const ResultFromType result_from = obj->getAvgSpeed();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_avg_speed(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, const char* p_avg_speed)
{
    if (!obj_per_ue_attribute) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return NULL;

    const auto &value_from = p_avg_speed;
    typedef typename PerUeAttribute::AvgSpeedType ValueType;

    ValueType value(value_from);

    if (!obj->setAvgSpeed(value)) return NULL;

    return obj_per_ue_attribute;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_avg_speed_move(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, char* p_avg_speed)
{
    if (!obj_per_ue_attribute) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return NULL;

    const auto &value_from = p_avg_speed;
    typedef typename PerUeAttribute::AvgSpeedType ValueType;

    ValueType value(value_from);

    
    if (!obj->setAvgSpeed(std::move(value))) return NULL;

    return obj_per_ue_attribute;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_per_ue_attribute_has_time_of_arrival(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    if (!obj_per_ue_attribute) return false;

    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return false;

    return obj->getTimeOfArrival().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_per_ue_attribute_get_time_of_arrival(const data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    if (!obj_per_ue_attribute) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<const std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerUeAttribute::TimeOfArrivalType ResultFromType;
    const ResultFromType result_from = obj->getTimeOfArrival();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_time_of_arrival(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, const char* p_time_of_arrival)
{
    if (!obj_per_ue_attribute) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return NULL;

    const auto &value_from = p_time_of_arrival;
    typedef typename PerUeAttribute::TimeOfArrivalType ValueType;

    ValueType value(value_from);

    if (!obj->setTimeOfArrival(value)) return NULL;

    return obj_per_ue_attribute;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_per_ue_attribute_t *data_collection_model_per_ue_attribute_set_time_of_arrival_move(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute, char* p_time_of_arrival)
{
    if (!obj_per_ue_attribute) return NULL;

    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    if (!obj) return NULL;

    const auto &value_from = p_time_of_arrival;
    typedef typename PerUeAttribute::TimeOfArrivalType ValueType;

    ValueType value(value_from);

    
    if (!obj->setTimeOfArrival(std::move(value))) return NULL;

    return obj_per_ue_attribute;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_per_ue_attribute_make_lnode(data_collection_model_per_ue_attribute_t *p_per_ue_attribute)
{
    return data_collection_lnode_create(p_per_ue_attribute, reinterpret_cast<void(*)(void*)>(data_collection_model_per_ue_attribute_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_per_ue_attribute_refcount(data_collection_model_per_ue_attribute_t *obj_per_ue_attribute)
{
    if (!obj_per_ue_attribute) return 0l;
    std::shared_ptr<PerUeAttribute > &obj = *reinterpret_cast<std::shared_ptr<PerUeAttribute >*>(obj_per_ue_attribute);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

