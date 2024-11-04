/**********************************************************************************************************************************
 * GeographicalCoordinates - C interface to the GeographicalCoordinates object
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

/*#include "GeographicalCoordinates.h" already included by data-collection-sp/data-collection.h */
#include "GeographicalCoordinates-internal.h"
#include "openapi/model/GeographicalCoordinates.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create(

)
{
    return reinterpret_cast<data_collection_model_geographical_coordinates_t*>(new std::shared_ptr<GeographicalCoordinates>(new GeographicalCoordinates(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create_copy(const data_collection_model_geographical_coordinates_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_geographical_coordinates_t*>(new std::shared_ptr<GeographicalCoordinates >(new GeographicalCoordinates(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_create_move(data_collection_model_geographical_coordinates_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<GeographicalCoordinates > *obj = reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_copy(data_collection_model_geographical_coordinates_t *geographical_coordinates, const data_collection_model_geographical_coordinates_t *other)
{
    if (geographical_coordinates) {
        std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(geographical_coordinates);
        if (obj) {
            if (other) {
                const std::shared_ptr<GeographicalCoordinates > &other_obj = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(other);
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
                const std::shared_ptr<GeographicalCoordinates > &other_obj = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(other);
                if (other_obj) {
                    obj.reset(new GeographicalCoordinates(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        geographical_coordinates = data_collection_model_geographical_coordinates_create_copy(other);
    }
    return geographical_coordinates;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_move(data_collection_model_geographical_coordinates_t *geographical_coordinates, data_collection_model_geographical_coordinates_t *other)
{
    std::shared_ptr<GeographicalCoordinates > *other_ptr = reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(other);

    if (geographical_coordinates) {
        std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(geographical_coordinates);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                geographical_coordinates = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return geographical_coordinates;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_geographical_coordinates_free(data_collection_model_geographical_coordinates_t *geographical_coordinates)
{
    if (!geographical_coordinates) return;
    delete reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(geographical_coordinates);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_geographical_coordinates_toJSON(const data_collection_model_geographical_coordinates_t *geographical_coordinates, bool as_request)
{
    if (!geographical_coordinates) return NULL;
    const std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(geographical_coordinates);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_geographical_coordinates_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_geographical_coordinates_t*>(new std::shared_ptr<GeographicalCoordinates >(new GeographicalCoordinates(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_geographical_coordinates_is_equal_to(const data_collection_model_geographical_coordinates_t *first, const data_collection_model_geographical_coordinates_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<GeographicalCoordinates > &obj2 = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<GeographicalCoordinates > &obj1 = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_geographical_coordinates_get_lon(const data_collection_model_geographical_coordinates_t *obj_geographical_coordinates)
{
    if (!obj_geographical_coordinates) {
        const double result = 0;
        return result;
    }

    const std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    if (!obj) {
        const double result = 0;
        return result;
    }

    typedef typename GeographicalCoordinates::LonType ResultFromType;
    const ResultFromType &result_from = obj->getLon();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lon(data_collection_model_geographical_coordinates_t *obj_geographical_coordinates, const double p_lon)
{
    if (!obj_geographical_coordinates) return NULL;

    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    if (!obj) return NULL;

    const auto &value_from = p_lon;
    typedef typename GeographicalCoordinates::LonType ValueType;

    ValueType value(value_from);

    if (!obj->setLon(value)) return NULL;

    return obj_geographical_coordinates;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lon_move(data_collection_model_geographical_coordinates_t *obj_geographical_coordinates, double p_lon)
{
    if (!obj_geographical_coordinates) return NULL;

    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    if (!obj) return NULL;

    const auto &value_from = p_lon;
    typedef typename GeographicalCoordinates::LonType ValueType;

    ValueType value(value_from);

    if (!obj->setLon(std::move(value))) return NULL;

    return obj_geographical_coordinates;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const double data_collection_model_geographical_coordinates_get_lat(const data_collection_model_geographical_coordinates_t *obj_geographical_coordinates)
{
    if (!obj_geographical_coordinates) {
        const double result = 0;
        return result;
    }

    const std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<const std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    if (!obj) {
        const double result = 0;
        return result;
    }

    typedef typename GeographicalCoordinates::LatType ResultFromType;
    const ResultFromType &result_from = obj->getLat();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lat(data_collection_model_geographical_coordinates_t *obj_geographical_coordinates, const double p_lat)
{
    if (!obj_geographical_coordinates) return NULL;

    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    if (!obj) return NULL;

    const auto &value_from = p_lat;
    typedef typename GeographicalCoordinates::LatType ValueType;

    ValueType value(value_from);

    if (!obj->setLat(value)) return NULL;

    return obj_geographical_coordinates;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_geographical_coordinates_t *data_collection_model_geographical_coordinates_set_lat_move(data_collection_model_geographical_coordinates_t *obj_geographical_coordinates, double p_lat)
{
    if (!obj_geographical_coordinates) return NULL;

    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    if (!obj) return NULL;

    const auto &value_from = p_lat;
    typedef typename GeographicalCoordinates::LatType ValueType;

    ValueType value(value_from);

    if (!obj->setLat(std::move(value))) return NULL;

    return obj_geographical_coordinates;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_geographical_coordinates_make_lnode(data_collection_model_geographical_coordinates_t *p_geographical_coordinates)
{
    return data_collection_lnode_create(p_geographical_coordinates, reinterpret_cast<void(*)(void*)>(data_collection_model_geographical_coordinates_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_geographical_coordinates_refcount(data_collection_model_geographical_coordinates_t *obj_geographical_coordinates)
{
    if (!obj_geographical_coordinates) return 0l;
    std::shared_ptr<GeographicalCoordinates > &obj = *reinterpret_cast<std::shared_ptr<GeographicalCoordinates >*>(obj_geographical_coordinates);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

