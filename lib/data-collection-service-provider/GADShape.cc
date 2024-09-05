/**********************************************************************************************************************************
 * GADShape - C interface to the GADShape object
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

/*#include "GADShape.h" already included by data-collection-sp/data-collection.h */
#include "GADShape-internal.h"
#include "openapi/model/GADShape.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_create(
)
{
    return reinterpret_cast<data_collection_model_gad_shape_t*>(new std::shared_ptr<GADShape>(new GADShape(
)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_create_copy(const data_collection_model_gad_shape_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<GADShape > &obj = *reinterpret_cast<const std::shared_ptr<GADShape >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_gad_shape_t*>(new std::shared_ptr<GADShape >(new GADShape(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_create_move(data_collection_model_gad_shape_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<GADShape > *obj = reinterpret_cast<std::shared_ptr<GADShape >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_copy(data_collection_model_gad_shape_t *gad_shape, const data_collection_model_gad_shape_t *other)
{
    if (gad_shape) {
        std::shared_ptr<GADShape > &obj = *reinterpret_cast<std::shared_ptr<GADShape >*>(gad_shape);
        if (obj) {
            if (other) {
                const std::shared_ptr<GADShape > &other_obj = *reinterpret_cast<const std::shared_ptr<GADShape >*>(other);
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
                const std::shared_ptr<GADShape > &other_obj = *reinterpret_cast<const std::shared_ptr<GADShape >*>(other);
                if (other_obj) {
                    obj.reset(new GADShape(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        gad_shape = data_collection_model_gad_shape_create_copy(other);
    }
    return gad_shape;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_move(data_collection_model_gad_shape_t *gad_shape, data_collection_model_gad_shape_t *other)
{
    std::shared_ptr<GADShape > *other_ptr = reinterpret_cast<std::shared_ptr<GADShape >*>(other);

    if (gad_shape) {
        std::shared_ptr<GADShape > &obj = *reinterpret_cast<std::shared_ptr<GADShape >*>(gad_shape);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                gad_shape = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return gad_shape;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gad_shape_free(data_collection_model_gad_shape_t *gad_shape)
{
    if (!gad_shape) return;
    delete reinterpret_cast<std::shared_ptr<GADShape >*>(gad_shape);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gad_shape_toJSON(const data_collection_model_gad_shape_t *gad_shape, bool as_request)
{
    if (!gad_shape) return NULL;
    const std::shared_ptr<GADShape > &obj = *reinterpret_cast<const std::shared_ptr<GADShape >*>(gad_shape);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_gad_shape_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_gad_shape_t*>(new std::shared_ptr<GADShape >(new GADShape(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gad_shape_is_equal_to(const data_collection_model_gad_shape_t *first, const data_collection_model_gad_shape_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<GADShape > &obj2 = *reinterpret_cast<const std::shared_ptr<GADShape >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<GADShape > &obj1 = *reinterpret_cast<const std::shared_ptr<GADShape >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_supported_gad_shapes_t* data_collection_model_gad_shape_get_shape(const data_collection_model_gad_shape_t *obj_gad_shape)
{
    if (!obj_gad_shape) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GADShape > &obj = *reinterpret_cast<const std::shared_ptr<GADShape >*>(obj_gad_shape);
    if (!obj) {
        const data_collection_model_supported_gad_shapes_t *result = NULL;
        return result;
    }

    typedef typename GADShape::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_set_shape(data_collection_model_gad_shape_t *obj_gad_shape, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_gad_shape) return NULL;

    std::shared_ptr<GADShape > &obj = *reinterpret_cast<std::shared_ptr<GADShape >*>(obj_gad_shape);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename GADShape::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setShape(value)) return NULL;

    return obj_gad_shape;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gad_shape_t *data_collection_model_gad_shape_set_shape_move(data_collection_model_gad_shape_t *obj_gad_shape, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (!obj_gad_shape) return NULL;

    std::shared_ptr<GADShape > &obj = *reinterpret_cast<std::shared_ptr<GADShape >*>(obj_gad_shape);
    if (!obj) return NULL;

    const auto &value_from = p_shape;
    typedef typename GADShape::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setShape(std::move(value))) return NULL;

    return obj_gad_shape;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gad_shape_make_lnode(data_collection_model_gad_shape_t *p_gad_shape)
{
    return data_collection_lnode_create(p_gad_shape, reinterpret_cast<void(*)(void*)>(data_collection_model_gad_shape_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_gad_shape_refcount(data_collection_model_gad_shape_t *obj_gad_shape)
{
    if (!obj_gad_shape) return 0l;
    std::shared_ptr<GADShape > &obj = *reinterpret_cast<std::shared_ptr<GADShape >*>(obj_gad_shape);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

