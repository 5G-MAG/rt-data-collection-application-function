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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "CpFailureCode.h" already included by data-collection-sp/data-collection.h */
#include "CpFailureCode-internal.h"
#include "openapi/model/CpFailureCode.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_create()
{
    return reinterpret_cast<data_collection_model_cp_failure_code_t*>(new std::shared_ptr<CpFailureCode>(new CpFailureCode()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_create_copy(const data_collection_model_cp_failure_code_t *other)
{
    return reinterpret_cast<data_collection_model_cp_failure_code_t*>(new std::shared_ptr<CpFailureCode >(new CpFailureCode(**reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_create_move(data_collection_model_cp_failure_code_t *other)
{
    return reinterpret_cast<data_collection_model_cp_failure_code_t*>(new std::shared_ptr<CpFailureCode >(std::move(*reinterpret_cast<std::shared_ptr<CpFailureCode >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_copy(data_collection_model_cp_failure_code_t *cp_failure_code, const data_collection_model_cp_failure_code_t *other)
{
    std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<std::shared_ptr<CpFailureCode >*>(cp_failure_code);
    *obj = **reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(other);
    return cp_failure_code;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_move(data_collection_model_cp_failure_code_t *cp_failure_code, data_collection_model_cp_failure_code_t *other)
{
    std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<std::shared_ptr<CpFailureCode >*>(cp_failure_code);
    obj = std::move(*reinterpret_cast<std::shared_ptr<CpFailureCode >*>(other));
    return cp_failure_code;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_cp_failure_code_free(data_collection_model_cp_failure_code_t *cp_failure_code)
{
    delete reinterpret_cast<std::shared_ptr<CpFailureCode >*>(cp_failure_code);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_cp_failure_code_toJSON(const data_collection_model_cp_failure_code_t *cp_failure_code, bool as_request)
{
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(cp_failure_code);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cp_failure_code_t *data_collection_model_cp_failure_code_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_cp_failure_code_is_equal_to(const data_collection_model_cp_failure_code_t *first, const data_collection_model_cp_failure_code_t *second)
{
    const std::shared_ptr<CpFailureCode > &obj1 = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(first);
    const std::shared_ptr<CpFailureCode > &obj2 = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_is_not_set(const data_collection_model_cp_failure_code_t *obj_cp_failure_code)
{
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    return obj->getValue() == CpFailureCode::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_is_non_standard(const data_collection_model_cp_failure_code_t *obj_cp_failure_code)
{
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    return obj->getValue() == CpFailureCode::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_failure_code_e data_collection_model_cp_failure_code_get_enum(const data_collection_model_cp_failure_code_t *obj_cp_failure_code)
{
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
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

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_cp_failure_code_get_string(const data_collection_model_cp_failure_code_t *obj_cp_failure_code)
{
    const std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<const std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_set_enum(data_collection_model_cp_failure_code_t *obj_cp_failure_code, data_collection_model_cp_failure_code_e p_value)
{
    std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
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

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_failure_code_set_string(data_collection_model_cp_failure_code_t *obj_cp_failure_code, const char *p_value)
{
    std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = CpFailureCode::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_cp_failure_code_make_lnode(data_collection_model_cp_failure_code_t *p_cp_failure_code)
{
    return data_collection_lnode_create(p_cp_failure_code, reinterpret_cast<void(*)(void*)>(data_collection_model_cp_failure_code_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_cp_failure_code_refcount(data_collection_model_cp_failure_code_t *obj_cp_failure_code)
{
    std::shared_ptr<CpFailureCode > &obj = *reinterpret_cast<std::shared_ptr<CpFailureCode >*>(obj_cp_failure_code);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

