/**********************************************************************************************************************************
 * TypedLocation - C interface to the TypedLocation object
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

/*#include "TypedLocation.h" already included by data-collection-sp/data-collection.h */
#include "TypedLocation-internal.h"
#include "openapi/model/TypedLocation.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_create(

)
{
    return reinterpret_cast<data_collection_model_typed_location_t*>(new std::shared_ptr<TypedLocation>(new TypedLocation(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_create_copy(const data_collection_model_typed_location_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<const std::shared_ptr<TypedLocation >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_typed_location_t*>(new std::shared_ptr<TypedLocation >(new TypedLocation(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_create_move(data_collection_model_typed_location_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<TypedLocation > *obj = reinterpret_cast<std::shared_ptr<TypedLocation >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_copy(data_collection_model_typed_location_t *typed_location, const data_collection_model_typed_location_t *other)
{
    if (typed_location) {
        std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<std::shared_ptr<TypedLocation >*>(typed_location);
        if (obj) {
            if (other) {
                const std::shared_ptr<TypedLocation > &other_obj = *reinterpret_cast<const std::shared_ptr<TypedLocation >*>(other);
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
                const std::shared_ptr<TypedLocation > &other_obj = *reinterpret_cast<const std::shared_ptr<TypedLocation >*>(other);
                if (other_obj) {
                    obj.reset(new TypedLocation(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        typed_location = data_collection_model_typed_location_create_copy(other);
    }
    return typed_location;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_move(data_collection_model_typed_location_t *typed_location, data_collection_model_typed_location_t *other)
{
    std::shared_ptr<TypedLocation > *other_ptr = reinterpret_cast<std::shared_ptr<TypedLocation >*>(other);

    if (typed_location) {
        std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<std::shared_ptr<TypedLocation >*>(typed_location);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                typed_location = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return typed_location;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_typed_location_free(data_collection_model_typed_location_t *typed_location)
{
    if (!typed_location) return;
    delete reinterpret_cast<std::shared_ptr<TypedLocation >*>(typed_location);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_typed_location_toJSON(const data_collection_model_typed_location_t *typed_location, bool as_request)
{
    if (!typed_location) return NULL;
    const std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<const std::shared_ptr<TypedLocation >*>(typed_location);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_typed_location_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_typed_location_t*>(new std::shared_ptr<TypedLocation >(new TypedLocation(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_typed_location_is_equal_to(const data_collection_model_typed_location_t *first, const data_collection_model_typed_location_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<TypedLocation > &obj2 = *reinterpret_cast<const std::shared_ptr<TypedLocation >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<TypedLocation > &obj1 = *reinterpret_cast<const std::shared_ptr<TypedLocation >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_cell_identifier_type_t* data_collection_model_typed_location_get_location_identifier_type(const data_collection_model_typed_location_t *obj_typed_location)
{
    if (!obj_typed_location) {
        const data_collection_model_cell_identifier_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<const std::shared_ptr<TypedLocation >*>(obj_typed_location);
    if (!obj) {
        const data_collection_model_cell_identifier_type_t *result = NULL;
        return result;
    }

    typedef typename TypedLocation::LocationIdentifierTypeType ResultFromType;
    const ResultFromType result_from = obj->getLocationIdentifierType();
    const data_collection_model_cell_identifier_type_t *result = reinterpret_cast<const data_collection_model_cell_identifier_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location_identifier_type(data_collection_model_typed_location_t *obj_typed_location, const data_collection_model_cell_identifier_type_t* p_location_identifier_type)
{
    if (!obj_typed_location) return NULL;

    std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<std::shared_ptr<TypedLocation >*>(obj_typed_location);
    if (!obj) return NULL;

    const auto &value_from = p_location_identifier_type;
    typedef typename TypedLocation::LocationIdentifierTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setLocationIdentifierType(value)) return NULL;

    return obj_typed_location;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location_identifier_type_move(data_collection_model_typed_location_t *obj_typed_location, data_collection_model_cell_identifier_type_t* p_location_identifier_type)
{
    if (!obj_typed_location) return NULL;

    std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<std::shared_ptr<TypedLocation >*>(obj_typed_location);
    if (!obj) return NULL;

    const auto &value_from = p_location_identifier_type;
    typedef typename TypedLocation::LocationIdentifierTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setLocationIdentifierType(std::move(value))) return NULL;

    return obj_typed_location;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_typed_location_get_location(const data_collection_model_typed_location_t *obj_typed_location)
{
    if (!obj_typed_location) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<const std::shared_ptr<TypedLocation >*>(obj_typed_location);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename TypedLocation::LocationType ResultFromType;
    const ResultFromType result_from = obj->getLocation();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location(data_collection_model_typed_location_t *obj_typed_location, const char* p_location)
{
    if (!obj_typed_location) return NULL;

    std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<std::shared_ptr<TypedLocation >*>(obj_typed_location);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename TypedLocation::LocationType ValueType;

    ValueType value(value_from);

    if (!obj->setLocation(value)) return NULL;

    return obj_typed_location;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_typed_location_t *data_collection_model_typed_location_set_location_move(data_collection_model_typed_location_t *obj_typed_location, char* p_location)
{
    if (!obj_typed_location) return NULL;

    std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<std::shared_ptr<TypedLocation >*>(obj_typed_location);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename TypedLocation::LocationType ValueType;

    ValueType value(value_from);

    
    if (!obj->setLocation(std::move(value))) return NULL;

    return obj_typed_location;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_typed_location_make_lnode(data_collection_model_typed_location_t *p_typed_location)
{
    return data_collection_lnode_create(p_typed_location, reinterpret_cast<void(*)(void*)>(data_collection_model_typed_location_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_typed_location_refcount(data_collection_model_typed_location_t *obj_typed_location)
{
    if (!obj_typed_location) return 0l;
    std::shared_ptr<TypedLocation > &obj = *reinterpret_cast<std::shared_ptr<TypedLocation >*>(obj_typed_location);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

