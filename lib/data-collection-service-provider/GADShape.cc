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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gad_shape_t *data_collection_model_gad_shape_create(
)
{
    return reinterpret_cast<data_collection_model_gad_shape_t*>(new std::shared_ptr<GADShape>(new GADShape(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gad_shape_t *data_collection_model_gad_shape_create_copy(const data_collection_model_gad_shape_t *other)
{
    return reinterpret_cast<data_collection_model_gad_shape_t*>(new std::shared_ptr<GADShape >(new GADShape(**reinterpret_cast<const std::shared_ptr<GADShape >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gad_shape_t *data_collection_model_gad_shape_create_move(data_collection_model_gad_shape_t *other)
{
    return reinterpret_cast<data_collection_model_gad_shape_t*>(new std::shared_ptr<GADShape >(std::move(*reinterpret_cast<std::shared_ptr<GADShape >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gad_shape_t *data_collection_model_gad_shape_copy(data_collection_model_gad_shape_t *gad_shape, const data_collection_model_gad_shape_t *other)
{
    std::shared_ptr<GADShape > &obj = *reinterpret_cast<std::shared_ptr<GADShape >*>(gad_shape);
    *obj = **reinterpret_cast<const std::shared_ptr<GADShape >*>(other);
    return gad_shape;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gad_shape_t *data_collection_model_gad_shape_move(data_collection_model_gad_shape_t *gad_shape, data_collection_model_gad_shape_t *other)
{
    std::shared_ptr<GADShape > &obj = *reinterpret_cast<std::shared_ptr<GADShape >*>(gad_shape);
    obj = std::move(*reinterpret_cast<std::shared_ptr<GADShape >*>(other));
    return gad_shape;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_gad_shape_free(data_collection_model_gad_shape_t *gad_shape)
{
    delete reinterpret_cast<std::shared_ptr<GADShape >*>(gad_shape);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_gad_shape_toJSON(const data_collection_model_gad_shape_t *gad_shape, bool as_request)
{
    const std::shared_ptr<GADShape > &obj = *reinterpret_cast<const std::shared_ptr<GADShape >*>(gad_shape);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gad_shape_t *data_collection_model_gad_shape_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_supported_gad_shapes_t* data_collection_model_gad_shape_get_shape(const data_collection_model_gad_shape_t *obj_gad_shape)
{
    const std::shared_ptr<GADShape > &obj = *reinterpret_cast<const std::shared_ptr<GADShape >*>(obj_gad_shape);
    typedef typename GADShape::ShapeType ResultFromType;
    const ResultFromType result_from = obj->getShape();
    const data_collection_model_supported_gad_shapes_t *result = reinterpret_cast<const data_collection_model_supported_gad_shapes_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gad_shape_t *data_collection_model_gad_shape_set_shape(data_collection_model_gad_shape_t *obj_gad_shape, const data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_gad_shape == NULL) return NULL;

    std::shared_ptr<GADShape > &obj = *reinterpret_cast<std::shared_ptr<GADShape >*>(obj_gad_shape);
    const auto &value_from = p_shape;
    typedef typename GADShape::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setShape(value)) return NULL;
    return obj_gad_shape;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gad_shape_t *data_collection_model_gad_shape_set_shape_move(data_collection_model_gad_shape_t *obj_gad_shape, data_collection_model_supported_gad_shapes_t* p_shape)
{
    if (obj_gad_shape == NULL) return NULL;

    std::shared_ptr<GADShape > &obj = *reinterpret_cast<std::shared_ptr<GADShape >*>(obj_gad_shape);
    const auto &value_from = p_shape;
    typedef typename GADShape::ShapeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setShape(std::move(value))) return NULL;
    return obj_gad_shape;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_gad_shape_make_lnode(data_collection_model_gad_shape_t *p_gad_shape)
{
    return data_collection_lnode_create(p_gad_shape, reinterpret_cast<void(*)(void*)>(data_collection_model_gad_shape_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_gad_shape_refcount(data_collection_model_gad_shape_t *obj_gad_shape)
{
    std::shared_ptr<GADShape > &obj = *reinterpret_cast<std::shared_ptr<GADShape >*>(obj_gad_shape);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

