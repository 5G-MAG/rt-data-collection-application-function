/**********************************************************************************************************************************
 * RelativeCartesianLocation - C interface to the RelativeCartesianLocation object
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

/*#include "RelativeCartesianLocation.h" already included by data-collection-sp/data-collection.h */
#include "RelativeCartesianLocation-internal.h"
#include "openapi/model/RelativeCartesianLocation.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create(


)
{
    return reinterpret_cast<data_collection_model_relative_cartesian_location_t*>(new std::shared_ptr<RelativeCartesianLocation>(new RelativeCartesianLocation(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create_ref(const data_collection_model_relative_cartesian_location_t *other)
{
    return reinterpret_cast<data_collection_model_relative_cartesian_location_t*>(new std::shared_ptr<RelativeCartesianLocation>(*reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create_copy(const data_collection_model_relative_cartesian_location_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_relative_cartesian_location_t*>(new std::shared_ptr<RelativeCartesianLocation >(new RelativeCartesianLocation(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_create_move(data_collection_model_relative_cartesian_location_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<RelativeCartesianLocation > *obj = reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_copy(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, const data_collection_model_relative_cartesian_location_t *other)
{
    if (relative_cartesian_location) {
        std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(relative_cartesian_location);
        if (obj) {
            if (other) {
                const std::shared_ptr<RelativeCartesianLocation > &other_obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(other);
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
                const std::shared_ptr<RelativeCartesianLocation > &other_obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(other);
                if (other_obj) {
                    obj.reset(new RelativeCartesianLocation(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        relative_cartesian_location = data_collection_model_relative_cartesian_location_create_copy(other);
    }
    return relative_cartesian_location;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_move(data_collection_model_relative_cartesian_location_t *relative_cartesian_location, data_collection_model_relative_cartesian_location_t *other)
{
    std::shared_ptr<RelativeCartesianLocation > *other_ptr = reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(other);

    if (relative_cartesian_location) {
        std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(relative_cartesian_location);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                relative_cartesian_location = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return relative_cartesian_location;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_relative_cartesian_location_free(data_collection_model_relative_cartesian_location_t *relative_cartesian_location)
{
    if (!relative_cartesian_location) return;
    delete reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(relative_cartesian_location);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_relative_cartesian_location_toJSON(const data_collection_model_relative_cartesian_location_t *relative_cartesian_location, bool as_request)
{
    if (!relative_cartesian_location) return NULL;
    const std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(relative_cartesian_location);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_relative_cartesian_location_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_relative_cartesian_location_t*>(new std::shared_ptr<RelativeCartesianLocation >(new RelativeCartesianLocation(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_cartesian_location_is_equal_to(const data_collection_model_relative_cartesian_location_t *first, const data_collection_model_relative_cartesian_location_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<RelativeCartesianLocation > &obj2 = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<RelativeCartesianLocation > &obj1 = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_relative_cartesian_location_get_x(const data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location)
{
    if (!obj_relative_cartesian_location) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename RelativeCartesianLocation::xType ResultFromType;
    const ResultFromType &result_from = obj->getX();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_x(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, const float p_x)
{
    if (!obj_relative_cartesian_location) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    if (!obj) return NULL;

    const auto &value_from = p_x;
    typedef typename RelativeCartesianLocation::xType ValueType;

    ValueType value(value_from);

    if (!obj->setX(value)) return NULL;

    return obj_relative_cartesian_location;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_x_move(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, float p_x)
{
    if (!obj_relative_cartesian_location) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    if (!obj) return NULL;

    const auto &value_from = p_x;
    typedef typename RelativeCartesianLocation::xType ValueType;

    ValueType value(value_from);

    if (!obj->setX(std::move(value))) return NULL;

    return obj_relative_cartesian_location;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_relative_cartesian_location_get_y(const data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location)
{
    if (!obj_relative_cartesian_location) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename RelativeCartesianLocation::yType ResultFromType;
    const ResultFromType &result_from = obj->getY();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_y(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, const float p_y)
{
    if (!obj_relative_cartesian_location) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    if (!obj) return NULL;

    const auto &value_from = p_y;
    typedef typename RelativeCartesianLocation::yType ValueType;

    ValueType value(value_from);

    if (!obj->setY(value)) return NULL;

    return obj_relative_cartesian_location;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_y_move(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, float p_y)
{
    if (!obj_relative_cartesian_location) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    if (!obj) return NULL;

    const auto &value_from = p_y;
    typedef typename RelativeCartesianLocation::yType ValueType;

    ValueType value(value_from);

    if (!obj->setY(std::move(value))) return NULL;

    return obj_relative_cartesian_location;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_relative_cartesian_location_has_z(const data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location)
{
    if (!obj_relative_cartesian_location) return false;

    const std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    if (!obj) return false;

    return obj->getZ().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_relative_cartesian_location_get_z(const data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location)
{
    if (!obj_relative_cartesian_location) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<const std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename RelativeCartesianLocation::zType ResultFromType;
    const ResultFromType &result_from = obj->getZ();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_z(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, const float p_z)
{
    if (!obj_relative_cartesian_location) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    if (!obj) return NULL;

    const auto &value_from = p_z;
    typedef typename RelativeCartesianLocation::zType ValueType;

    ValueType value(value_from);

    if (!obj->setZ(value)) return NULL;

    return obj_relative_cartesian_location;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_relative_cartesian_location_t *data_collection_model_relative_cartesian_location_set_z_move(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location, float p_z)
{
    if (!obj_relative_cartesian_location) return NULL;

    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    if (!obj) return NULL;

    const auto &value_from = p_z;
    typedef typename RelativeCartesianLocation::zType ValueType;

    ValueType value(value_from);

    if (!obj->setZ(std::move(value))) return NULL;

    return obj_relative_cartesian_location;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_relative_cartesian_location_make_lnode(data_collection_model_relative_cartesian_location_t *p_relative_cartesian_location)
{
    return data_collection_lnode_create(p_relative_cartesian_location, reinterpret_cast<void(*)(void*)>(data_collection_model_relative_cartesian_location_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_relative_cartesian_location_refcount(data_collection_model_relative_cartesian_location_t *obj_relative_cartesian_location)
{
    if (!obj_relative_cartesian_location) return 0l;
    std::shared_ptr<RelativeCartesianLocation > &obj = *reinterpret_cast<std::shared_ptr<RelativeCartesianLocation >*>(obj_relative_cartesian_location);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

