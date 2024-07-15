/**********************************************************************************************************************************
 * SdfMethod - C interface to the SdfMethod object
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

/*#include "SdfMethod.h" already included by data-collection-sp/data-collection.h */
#include "SdfMethod-internal.h"
#include "openapi/model/SdfMethod.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_sdf_method_t *data_collection_model_sdf_method_create()
{
    return reinterpret_cast<data_collection_model_sdf_method_t*>(new std::shared_ptr<SdfMethod>(new SdfMethod()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_sdf_method_t *data_collection_model_sdf_method_create_copy(const data_collection_model_sdf_method_t *other)
{
    return reinterpret_cast<data_collection_model_sdf_method_t*>(new std::shared_ptr<SdfMethod >(new SdfMethod(**reinterpret_cast<const std::shared_ptr<SdfMethod >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_sdf_method_t *data_collection_model_sdf_method_create_move(data_collection_model_sdf_method_t *other)
{
    return reinterpret_cast<data_collection_model_sdf_method_t*>(new std::shared_ptr<SdfMethod >(std::move(*reinterpret_cast<std::shared_ptr<SdfMethod >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_sdf_method_t *data_collection_model_sdf_method_copy(data_collection_model_sdf_method_t *sdf_method, const data_collection_model_sdf_method_t *other)
{
    std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<std::shared_ptr<SdfMethod >*>(sdf_method);
    *obj = **reinterpret_cast<const std::shared_ptr<SdfMethod >*>(other);
    return sdf_method;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_sdf_method_t *data_collection_model_sdf_method_move(data_collection_model_sdf_method_t *sdf_method, data_collection_model_sdf_method_t *other)
{
    std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<std::shared_ptr<SdfMethod >*>(sdf_method);
    obj = std::move(*reinterpret_cast<std::shared_ptr<SdfMethod >*>(other));
    return sdf_method;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_sdf_method_free(data_collection_model_sdf_method_t *sdf_method)
{
    delete reinterpret_cast<std::shared_ptr<SdfMethod >*>(sdf_method);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_sdf_method_toJSON(const data_collection_model_sdf_method_t *sdf_method, bool as_request)
{
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(sdf_method);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_sdf_method_t *data_collection_model_sdf_method_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_sdf_method_t*>(new std::shared_ptr<SdfMethod >(new SdfMethod(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_is_not_set(const data_collection_model_sdf_method_t *obj_sdf_method)
{
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    return obj->getValue() == SdfMethod::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_is_non_standard(const data_collection_model_sdf_method_t *obj_sdf_method)
{
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    return obj->getValue() == SdfMethod::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_e data_collection_model_sdf_method_get_enum(const data_collection_model_sdf_method_t *obj_sdf_method)
{
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    switch (obj->getValue()) {
    case SdfMethod::Enum::NO_VAL:
        return DCM_SDF_METHOD_NO_VAL;
    case SdfMethod::Enum::VAL_5_TUPLE:
        return DCM_SDF_METHOD_VAL_5_TUPLE;
    case SdfMethod::Enum::VAL_2_TUPLE:
        return DCM_SDF_METHOD_VAL_2_TUPLE;
    case SdfMethod::Enum::VAL_TYPE_OF_SERVICE_MARKING:
        return DCM_SDF_METHOD_VAL_TYPE_OF_SERVICE_MARKING;
    case SdfMethod::Enum::VAL_FLOW_LABEL:
        return DCM_SDF_METHOD_VAL_FLOW_LABEL;
    case SdfMethod::Enum::VAL_DOMAIN_NAME:
        return DCM_SDF_METHOD_VAL_DOMAIN_NAME;
    default:
        break;
    }
    return DCM_SDF_METHOD_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_sdf_method_get_string(const data_collection_model_sdf_method_t *obj_sdf_method)
{
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_set_enum(data_collection_model_sdf_method_t *obj_sdf_method, data_collection_model_sdf_method_e p_value)
{
    std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    switch (p_value) {
    case DCM_SDF_METHOD_NO_VAL:
        *obj = SdfMethod::Enum::NO_VAL;
        return true;
    case DCM_SDF_METHOD_VAL_5_TUPLE:
        *obj = SdfMethod::Enum::VAL_5_TUPLE;
        return true;
    case DCM_SDF_METHOD_VAL_2_TUPLE:
        *obj = SdfMethod::Enum::VAL_2_TUPLE;
        return true;
    case DCM_SDF_METHOD_VAL_TYPE_OF_SERVICE_MARKING:
        *obj = SdfMethod::Enum::VAL_TYPE_OF_SERVICE_MARKING;
        return true;
    case DCM_SDF_METHOD_VAL_FLOW_LABEL:
        *obj = SdfMethod::Enum::VAL_FLOW_LABEL;
        return true;
    case DCM_SDF_METHOD_VAL_DOMAIN_NAME:
        *obj = SdfMethod::Enum::VAL_DOMAIN_NAME;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_set_string(data_collection_model_sdf_method_t *obj_sdf_method, const char *p_value)
{
    std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = SdfMethod::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_sdf_method_make_lnode(data_collection_model_sdf_method_t *p_sdf_method)
{
    return data_collection_lnode_create(p_sdf_method, reinterpret_cast<void(*)(void*)>(data_collection_model_sdf_method_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_sdf_method_refcount(data_collection_model_sdf_method_t *obj_sdf_method)
{
    std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

