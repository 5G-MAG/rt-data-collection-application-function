/**********************************************************************************************************************************
 * LocalOrigin - C interface to the LocalOrigin object
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

/*#include "LocalOrigin.h" already included by data-collection-sp/data-collection.h */
#include "LocalOrigin-internal.h"
#include "openapi/model/LocalOrigin.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_create(



)
{
    return reinterpret_cast<data_collection_model_local_origin_t*>(new std::shared_ptr<LocalOrigin>(new LocalOrigin(



)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_create_copy(const data_collection_model_local_origin_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_local_origin_t*>(new std::shared_ptr<LocalOrigin >(new LocalOrigin(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_create_move(data_collection_model_local_origin_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<LocalOrigin > *obj = reinterpret_cast<std::shared_ptr<LocalOrigin >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_copy(data_collection_model_local_origin_t *local_origin, const data_collection_model_local_origin_t *other)
{
    if (local_origin) {
        std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(local_origin);
        if (obj) {
            if (other) {
                const std::shared_ptr<LocalOrigin > &other_obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(other);
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
                const std::shared_ptr<LocalOrigin > &other_obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(other);
                if (other_obj) {
                    obj.reset(new LocalOrigin(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        local_origin = data_collection_model_local_origin_create_copy(other);
    }
    return local_origin;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_move(data_collection_model_local_origin_t *local_origin, data_collection_model_local_origin_t *other)
{
    std::shared_ptr<LocalOrigin > *other_ptr = reinterpret_cast<std::shared_ptr<LocalOrigin >*>(other);

    if (local_origin) {
        std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(local_origin);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                local_origin = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return local_origin;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_local_origin_free(data_collection_model_local_origin_t *local_origin)
{
    if (!local_origin) return;
    delete reinterpret_cast<std::shared_ptr<LocalOrigin >*>(local_origin);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_local_origin_toJSON(const data_collection_model_local_origin_t *local_origin, bool as_request)
{
    if (!local_origin) return NULL;
    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(local_origin);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_local_origin_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_local_origin_t*>(new std::shared_ptr<LocalOrigin >(new LocalOrigin(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local_origin_is_equal_to(const data_collection_model_local_origin_t *first, const data_collection_model_local_origin_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<LocalOrigin > &obj2 = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<LocalOrigin > &obj1 = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_local_origin_get_coordinate_id(const data_collection_model_local_origin_t *obj_local_origin)
{
    if (!obj_local_origin) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename LocalOrigin::CoordinateIdType ResultFromType;
    const ResultFromType &result_from = obj->getCoordinateId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_coordinate_id(data_collection_model_local_origin_t *obj_local_origin, const char* p_coordinate_id)
{
    if (!obj_local_origin) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return NULL;

    const auto &value_from = p_coordinate_id;
    typedef typename LocalOrigin::CoordinateIdType ValueType;

    ValueType value(value_from);

    if (!obj->setCoordinateId(value)) return NULL;

    return obj_local_origin;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_coordinate_id_move(data_collection_model_local_origin_t *obj_local_origin, char* p_coordinate_id)
{
    if (!obj_local_origin) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return NULL;

    const auto &value_from = p_coordinate_id;
    typedef typename LocalOrigin::CoordinateIdType ValueType;

    ValueType value(value_from);

    if (!obj->setCoordinateId(std::move(value))) return NULL;
    ogs_free
(p_coordinate_id);

    return obj_local_origin;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local_origin_has_point(const data_collection_model_local_origin_t *obj_local_origin)
{
    if (!obj_local_origin) return false;

    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return false;

    return obj->getPoint().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_local_origin_get_point(const data_collection_model_local_origin_t *obj_local_origin)
{
    if (!obj_local_origin) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    typedef typename LocalOrigin::PointType ResultFromType;
    const ResultFromType &result_from = obj->getPoint();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_point(data_collection_model_local_origin_t *obj_local_origin, const data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_local_origin) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename LocalOrigin::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setPoint(value)) return NULL;

    return obj_local_origin;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_point_move(data_collection_model_local_origin_t *obj_local_origin, data_collection_model_geographical_coordinates_t* p_point)
{
    if (!obj_local_origin) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return NULL;

    const auto &value_from = p_point;
    typedef typename LocalOrigin::PointType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setPoint(std::move(value))) return NULL;
    data_collection_model_geographical_coordinates_free
(p_point);

    return obj_local_origin;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local_origin_has_area(const data_collection_model_local_origin_t *obj_local_origin)
{
    if (!obj_local_origin) return false;

    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return false;

    return obj->getArea().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographic_area_t* data_collection_model_local_origin_get_area(const data_collection_model_local_origin_t *obj_local_origin)
{
    if (!obj_local_origin) {
        const data_collection_model_geographic_area_t *result = NULL;
        return result;
    }

    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) {
        const data_collection_model_geographic_area_t *result = NULL;
        return result;
    }

    typedef typename LocalOrigin::AreaType ResultFromType;
    const ResultFromType &result_from = obj->getArea();
    const data_collection_model_geographic_area_t *result = reinterpret_cast<const data_collection_model_geographic_area_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_area(data_collection_model_local_origin_t *obj_local_origin, const data_collection_model_geographic_area_t* p_area)
{
    if (!obj_local_origin) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return NULL;

    const auto &value_from = p_area;
    typedef typename LocalOrigin::AreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setArea(value)) return NULL;

    return obj_local_origin;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_area_move(data_collection_model_local_origin_t *obj_local_origin, data_collection_model_geographic_area_t* p_area)
{
    if (!obj_local_origin) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return NULL;

    const auto &value_from = p_area;
    typedef typename LocalOrigin::AreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setArea(std::move(value))) return NULL;
    data_collection_model_geographic_area_free
(p_area);

    return obj_local_origin;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_local_origin_has_horiz_axes_orientation(const data_collection_model_local_origin_t *obj_local_origin)
{
    if (!obj_local_origin) return false;

    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return false;

    return obj->getHorizAxesOrientation().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_local_origin_get_horiz_axes_orientation(const data_collection_model_local_origin_t *obj_local_origin)
{
    if (!obj_local_origin) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<const std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename LocalOrigin::HorizAxesOrientationType ResultFromType;
    const ResultFromType &result_from = obj->getHorizAxesOrientation();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_horiz_axes_orientation(data_collection_model_local_origin_t *obj_local_origin, const int32_t p_horiz_axes_orientation)
{
    if (!obj_local_origin) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return NULL;

    const auto &value_from = p_horiz_axes_orientation;
    typedef typename LocalOrigin::HorizAxesOrientationType ValueType;

    ValueType value(value_from);

    if (!obj->setHorizAxesOrientation(value)) return NULL;

    return obj_local_origin;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_local_origin_t *data_collection_model_local_origin_set_horiz_axes_orientation_move(data_collection_model_local_origin_t *obj_local_origin, int32_t p_horiz_axes_orientation)
{
    if (!obj_local_origin) return NULL;

    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    if (!obj) return NULL;

    const auto &value_from = p_horiz_axes_orientation;
    typedef typename LocalOrigin::HorizAxesOrientationType ValueType;

    ValueType value(value_from);

    if (!obj->setHorizAxesOrientation(std::move(value))) return NULL;

    return obj_local_origin;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_local_origin_make_lnode(data_collection_model_local_origin_t *p_local_origin)
{
    return data_collection_lnode_create(p_local_origin, reinterpret_cast<void(*)(void*)>(data_collection_model_local_origin_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_local_origin_refcount(data_collection_model_local_origin_t *obj_local_origin)
{
    if (!obj_local_origin) return 0l;
    std::shared_ptr<LocalOrigin > &obj = *reinterpret_cast<std::shared_ptr<LocalOrigin >*>(obj_local_origin);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

