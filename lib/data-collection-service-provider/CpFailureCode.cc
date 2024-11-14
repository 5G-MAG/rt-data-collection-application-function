/**********************************************************************************************************************************
 * CpFailureCode - C interface to the CpFailureCode object
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

/*#include "CpFailureCode.h" already included by data-collection-sp/data-collection.h */
#include "CpFailureCode-internal.h"
#include "openapi/model/CpFailureCode.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_create()
{
    return reinterpret_cast<data_collection_model_cp_failure_code_t*>(new std::shared_ptr<CpFailureCode>(new CpFailureCode()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_create_ref(const data_collection_model_cp_failure_code_t *other)
{
    return reinterpret_cast<data_collection_model_cp_failure_code_t*>(new std::shared_ptr<CpFailureCode>(*reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_create_copy(const data_collection_model_cp_failure_code_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_cp_failure_code_t*>(new std::shared_ptr<CpFailureCode >(new CpFailureCode(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_create_move(data_collection_model_cp_failure_code_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<CpFailureCode > *obj = reinterpret_cast<std::shared_ptr<CpFailureCode >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_copy(data_collection_model_cp_failure_code_t *cp_failure_code, const data_collection_model_cp_failure_code_t *other)
{
    if (cp_failure_code) {
        std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<std::shared_ptr<CpFailureCode >*>(cp_failure_code);
        if (obj) {
            if (other) {
                const std::shared_ptr<CpFailureCode > &other_obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(other);
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
                const std::shared_ptr<CpFailureCode > &other_obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(other);
                if (other_obj) {
                    obj.reset(new CpFailureCode(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        cp_failure_code = data_collection_model_cp_failure_code_create_copy(other);
    }
    return cp_failure_code;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_move(data_collection_model_cp_failure_code_t *cp_failure_code, data_collection_model_cp_failure_code_t *other)
{
    std::shared_ptr<CpFailureCode > *other_ptr = reinterpret_cast<std::shared_ptr<CpFailureCode >*>(other);

    if (cp_failure_code) {
        std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<std::shared_ptr<CpFailureCode >*>(cp_failure_code);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                cp_failure_code = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return cp_failure_code;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_cp_failure_code_free(data_collection_model_cp_failure_code_t *cp_failure_code)
{
    if (!cp_failure_code) return;
    delete reinterpret_cast<std::shared_ptr<CpFailureCode >*>(cp_failure_code);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_cp_failure_code_toJSON(const data_collection_model_cp_failure_code_t *cp_failure_code, bool as_request)
{
    if (!cp_failure_code) return NULL;
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(cp_failure_code);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_cp_failure_code_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_cp_failure_code_t*>(new std::shared_ptr<CpFailureCode >(new CpFailureCode(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_is_equal_to(const data_collection_model_cp_failure_code_t *first, const data_collection_model_cp_failure_code_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<CpFailureCode > &obj2 = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<CpFailureCode > &obj1 = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_is_not_set(const data_collection_model_cp_failure_code_t *obj_cp_failure_code)
{
    if (!obj_cp_failure_code) return true;
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    if (!obj) return true;
    return obj->getValue() == CpFailureCode::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_is_non_standard(const data_collection_model_cp_failure_code_t *obj_cp_failure_code)
{
    if (!obj_cp_failure_code) return false;
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    if (!obj) return false;
    return obj->getValue() == CpFailureCode::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_e data_collection_model_cp_failure_code_get_enum(const data_collection_model_cp_failure_code_t *obj_cp_failure_code)
{
    if (!obj_cp_failure_code)
        return DCM_CP_FAILURE_CODE_NO_VAL;
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    if (!obj) return DCM_CP_FAILURE_CODE_NO_VAL;
    switch (obj->getValue()) {
    case CpFailureCode::Enum::NO_VAL:
        return DCM_CP_FAILURE_CODE_NO_VAL;
    case CpFailureCode::Enum::VAL_MALFUNCTION:
        return DCM_CP_FAILURE_CODE_VAL_MALFUNCTION;
    case CpFailureCode::Enum::VAL_SET_ID_DUPLICATED:
        return DCM_CP_FAILURE_CODE_VAL_SET_ID_DUPLICATED;
    case CpFailureCode::Enum::VAL_OTHER_REASON:
        return DCM_CP_FAILURE_CODE_VAL_OTHER_REASON;
    case CpFailureCode::Enum::VAL_CONFIDENCE_LEVEL_NOT_SUFFICIENT:
        return DCM_CP_FAILURE_CODE_VAL_CONFIDENCE_LEVEL_NOT_SUFFICIENT;
    case CpFailureCode::Enum::VAL_ACCURACY_LEVEL_NOT_SUFFICIENT:
        return DCM_CP_FAILURE_CODE_VAL_ACCURACY_LEVEL_NOT_SUFFICIENT;
    default:
        break;
    }
    return DCM_CP_FAILURE_CODE_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_cp_failure_code_get_string(const data_collection_model_cp_failure_code_t *obj_cp_failure_code)
{
    if (!obj_cp_failure_code) return NULL;
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_set_enum(data_collection_model_cp_failure_code_t *obj_cp_failure_code, data_collection_model_cp_failure_code_e p_value)
{
    if (!obj_cp_failure_code) return false;
    std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    if (!obj) return false;
    switch (p_value) {
    case DCM_CP_FAILURE_CODE_NO_VAL:
        *obj = CpFailureCode::Enum::NO_VAL;
        return true;
    case DCM_CP_FAILURE_CODE_VAL_MALFUNCTION:
        *obj = CpFailureCode::Enum::VAL_MALFUNCTION;
        return true;
    case DCM_CP_FAILURE_CODE_VAL_SET_ID_DUPLICATED:
        *obj = CpFailureCode::Enum::VAL_SET_ID_DUPLICATED;
        return true;
    case DCM_CP_FAILURE_CODE_VAL_OTHER_REASON:
        *obj = CpFailureCode::Enum::VAL_OTHER_REASON;
        return true;
    case DCM_CP_FAILURE_CODE_VAL_CONFIDENCE_LEVEL_NOT_SUFFICIENT:
        *obj = CpFailureCode::Enum::VAL_CONFIDENCE_LEVEL_NOT_SUFFICIENT;
        return true;
    case DCM_CP_FAILURE_CODE_VAL_ACCURACY_LEVEL_NOT_SUFFICIENT:
        *obj = CpFailureCode::Enum::VAL_ACCURACY_LEVEL_NOT_SUFFICIENT;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_set_string(data_collection_model_cp_failure_code_t *obj_cp_failure_code, const char *p_value)
{
    if (!obj_cp_failure_code) return false;
    std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = CpFailureCode::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_cp_failure_code_make_lnode(data_collection_model_cp_failure_code_t *p_cp_failure_code)
{
    return data_collection_lnode_create(p_cp_failure_code, reinterpret_cast<void(*)(void*)>(data_collection_model_cp_failure_code_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_cp_failure_code_refcount(data_collection_model_cp_failure_code_t *obj_cp_failure_code)
{
    if (!obj_cp_failure_code) return 0l;
    std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

