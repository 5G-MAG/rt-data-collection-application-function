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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_create()
{
    return reinterpret_cast<data_collection_model_sdf_method_t*>(new std::shared_ptr<SdfMethod>(new SdfMethod()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_create_copy(const data_collection_model_sdf_method_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_sdf_method_t*>(new std::shared_ptr<SdfMethod >(new SdfMethod(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_create_move(data_collection_model_sdf_method_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<SdfMethod > *obj = reinterpret_cast<std::shared_ptr<SdfMethod >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_copy(data_collection_model_sdf_method_t *sdf_method, const data_collection_model_sdf_method_t *other)
{
    if (sdf_method) {
        std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<std::shared_ptr<SdfMethod >*>(sdf_method);
        if (obj) {
            if (other) {
                const std::shared_ptr<SdfMethod > &other_obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(other);
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
                const std::shared_ptr<SdfMethod > &other_obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(other);
                if (other_obj) {
                    obj.reset(new SdfMethod(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        sdf_method = data_collection_model_sdf_method_create_copy(other);
    }
    return sdf_method;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_move(data_collection_model_sdf_method_t *sdf_method, data_collection_model_sdf_method_t *other)
{
    std::shared_ptr<SdfMethod > *other_ptr = reinterpret_cast<std::shared_ptr<SdfMethod >*>(other);

    if (sdf_method) {
        std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<std::shared_ptr<SdfMethod >*>(sdf_method);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                sdf_method = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return sdf_method;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_sdf_method_free(data_collection_model_sdf_method_t *sdf_method)
{
    if (!sdf_method) return;
    delete reinterpret_cast<std::shared_ptr<SdfMethod >*>(sdf_method);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_sdf_method_toJSON(const data_collection_model_sdf_method_t *sdf_method, bool as_request)
{
    if (!sdf_method) return NULL;
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(sdf_method);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_sdf_method_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_t *data_collection_model_sdf_method_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_is_equal_to(const data_collection_model_sdf_method_t *first, const data_collection_model_sdf_method_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<SdfMethod > &obj2 = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<SdfMethod > &obj1 = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_is_not_set(const data_collection_model_sdf_method_t *obj_sdf_method)
{
    if (!obj_sdf_method) return true;
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    if (!obj) return true;
    return obj->getValue() == SdfMethod::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_is_non_standard(const data_collection_model_sdf_method_t *obj_sdf_method)
{
    if (!obj_sdf_method) return false;
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    if (!obj) return false;
    return obj->getValue() == SdfMethod::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_sdf_method_e data_collection_model_sdf_method_get_enum(const data_collection_model_sdf_method_t *obj_sdf_method)
{
    if (!obj_sdf_method)
        return DCM_SDF_METHOD_NO_VAL;
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    if (!obj) return DCM_SDF_METHOD_NO_VAL;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_sdf_method_get_string(const data_collection_model_sdf_method_t *obj_sdf_method)
{
    if (!obj_sdf_method) return NULL;
    const std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<const std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_set_enum(data_collection_model_sdf_method_t *obj_sdf_method, data_collection_model_sdf_method_e p_value)
{
    if (!obj_sdf_method) return false;
    std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    if (!obj) return false;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_sdf_method_set_string(data_collection_model_sdf_method_t *obj_sdf_method, const char *p_value)
{
    if (!obj_sdf_method) return false;
    std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = SdfMethod::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_sdf_method_make_lnode(data_collection_model_sdf_method_t *p_sdf_method)
{
    return data_collection_lnode_create(p_sdf_method, reinterpret_cast<void(*)(void*)>(data_collection_model_sdf_method_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_sdf_method_refcount(data_collection_model_sdf_method_t *obj_sdf_method)
{
    if (!obj_sdf_method) return 0l;
    std::shared_ptr<SdfMethod > &obj = *reinterpret_cast<std::shared_ptr<SdfMethod >*>(obj_sdf_method);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

