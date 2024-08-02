/**********************************************************************************************************************************
 * ExceptionId - C interface to the ExceptionId object
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

/*#include "ExceptionId.h" already included by data-collection-sp/data-collection.h */
#include "ExceptionId-internal.h"
#include "openapi/model/ExceptionId.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_id_t *data_collection_model_exception_id_create()
{
    return reinterpret_cast<data_collection_model_exception_id_t*>(new std::shared_ptr<ExceptionId>(new ExceptionId()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_id_t *data_collection_model_exception_id_create_copy(const data_collection_model_exception_id_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionId >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_exception_id_t*>(new std::shared_ptr<ExceptionId >(new ExceptionId(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_id_t *data_collection_model_exception_id_create_move(data_collection_model_exception_id_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ExceptionId > *obj = reinterpret_cast<std::shared_ptr<ExceptionId >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_id_t *data_collection_model_exception_id_copy(data_collection_model_exception_id_t *exception_id, const data_collection_model_exception_id_t *other)
{
    if (exception_id) {
        std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<std::shared_ptr<ExceptionId >*>(exception_id);
        if (obj) {
            if (other) {
                const std::shared_ptr<ExceptionId > &other_obj = *reinterpret_cast<const std::shared_ptr<ExceptionId >*>(other);
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
                const std::shared_ptr<ExceptionId > &other_obj = *reinterpret_cast<const std::shared_ptr<ExceptionId >*>(other);
                if (other_obj) {
                    obj.reset(new ExceptionId(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        exception_id = data_collection_model_exception_id_create_copy(other);
    }
    return exception_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_id_t *data_collection_model_exception_id_move(data_collection_model_exception_id_t *exception_id, data_collection_model_exception_id_t *other)
{
    std::shared_ptr<ExceptionId > *other_ptr = reinterpret_cast<std::shared_ptr<ExceptionId >*>(other);

    if (exception_id) {
        std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<std::shared_ptr<ExceptionId >*>(exception_id);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                exception_id = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return exception_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_exception_id_free(data_collection_model_exception_id_t *exception_id)
{
    if (!exception_id) return;
    delete reinterpret_cast<std::shared_ptr<ExceptionId >*>(exception_id);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_exception_id_toJSON(const data_collection_model_exception_id_t *exception_id, bool as_request)
{
    if (!exception_id) return NULL;
    const std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionId >*>(exception_id);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_exception_id_t *data_collection_model_exception_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_exception_id_t*>(new std::shared_ptr<ExceptionId >(new ExceptionId(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_exception_id_is_equal_to(const data_collection_model_exception_id_t *first, const data_collection_model_exception_id_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ExceptionId > &obj2 = *reinterpret_cast<const std::shared_ptr<ExceptionId >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ExceptionId > &obj1 = *reinterpret_cast<const std::shared_ptr<ExceptionId >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_id_is_not_set(const data_collection_model_exception_id_t *obj_exception_id)
{
    if (!obj_exception_id) return true;
    const std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionId >*>(obj_exception_id);
    if (!obj) return true;
    return obj->getValue() == ExceptionId::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_id_is_non_standard(const data_collection_model_exception_id_t *obj_exception_id)
{
    if (!obj_exception_id) return false;
    const std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionId >*>(obj_exception_id);
    if (!obj) return false;
    return obj->getValue() == ExceptionId::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_exception_id_e data_collection_model_exception_id_get_enum(const data_collection_model_exception_id_t *obj_exception_id)
{
    if (!obj_exception_id)
        return DCM_EXCEPTION_ID_NO_VAL;
    const std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionId >*>(obj_exception_id);
    if (!obj) return DCM_EXCEPTION_ID_NO_VAL;
    switch (obj->getValue()) {
    case ExceptionId::Enum::NO_VAL:
        return DCM_EXCEPTION_ID_NO_VAL;
    case ExceptionId::Enum::VAL_UNEXPECTED_UE_LOCATION:
        return DCM_EXCEPTION_ID_VAL_UNEXPECTED_UE_LOCATION;
    case ExceptionId::Enum::VAL_UNEXPECTED_LONG_LIVE_FLOW:
        return DCM_EXCEPTION_ID_VAL_UNEXPECTED_LONG_LIVE_FLOW;
    case ExceptionId::Enum::VAL_UNEXPECTED_LARGE_RATE_FLOW:
        return DCM_EXCEPTION_ID_VAL_UNEXPECTED_LARGE_RATE_FLOW;
    case ExceptionId::Enum::VAL_UNEXPECTED_WAKEUP:
        return DCM_EXCEPTION_ID_VAL_UNEXPECTED_WAKEUP;
    case ExceptionId::Enum::VAL_SUSPICION_OF_DDOS_ATTACK:
        return DCM_EXCEPTION_ID_VAL_SUSPICION_OF_DDOS_ATTACK;
    case ExceptionId::Enum::VAL_WRONG_DESTINATION_ADDRESS:
        return DCM_EXCEPTION_ID_VAL_WRONG_DESTINATION_ADDRESS;
    case ExceptionId::Enum::VAL_TOO_FREQUENT_SERVICE_ACCESS:
        return DCM_EXCEPTION_ID_VAL_TOO_FREQUENT_SERVICE_ACCESS;
    case ExceptionId::Enum::VAL_UNEXPECTED_RADIO_LINK_FAILURES:
        return DCM_EXCEPTION_ID_VAL_UNEXPECTED_RADIO_LINK_FAILURES;
    case ExceptionId::Enum::VAL_PING_PONG_ACROSS_CELLS:
        return DCM_EXCEPTION_ID_VAL_PING_PONG_ACROSS_CELLS;
    default:
        break;
    }
    return DCM_EXCEPTION_ID_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_exception_id_get_string(const data_collection_model_exception_id_t *obj_exception_id)
{
    if (!obj_exception_id) return NULL;
    const std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<const std::shared_ptr<ExceptionId >*>(obj_exception_id);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_id_set_enum(data_collection_model_exception_id_t *obj_exception_id, data_collection_model_exception_id_e p_value)
{
    if (!obj_exception_id) return false;
    std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<std::shared_ptr<ExceptionId >*>(obj_exception_id);
    if (!obj) return false;
    switch (p_value) {
    case DCM_EXCEPTION_ID_NO_VAL:
        *obj = ExceptionId::Enum::NO_VAL;
        return true;
    case DCM_EXCEPTION_ID_VAL_UNEXPECTED_UE_LOCATION:
        *obj = ExceptionId::Enum::VAL_UNEXPECTED_UE_LOCATION;
        return true;
    case DCM_EXCEPTION_ID_VAL_UNEXPECTED_LONG_LIVE_FLOW:
        *obj = ExceptionId::Enum::VAL_UNEXPECTED_LONG_LIVE_FLOW;
        return true;
    case DCM_EXCEPTION_ID_VAL_UNEXPECTED_LARGE_RATE_FLOW:
        *obj = ExceptionId::Enum::VAL_UNEXPECTED_LARGE_RATE_FLOW;
        return true;
    case DCM_EXCEPTION_ID_VAL_UNEXPECTED_WAKEUP:
        *obj = ExceptionId::Enum::VAL_UNEXPECTED_WAKEUP;
        return true;
    case DCM_EXCEPTION_ID_VAL_SUSPICION_OF_DDOS_ATTACK:
        *obj = ExceptionId::Enum::VAL_SUSPICION_OF_DDOS_ATTACK;
        return true;
    case DCM_EXCEPTION_ID_VAL_WRONG_DESTINATION_ADDRESS:
        *obj = ExceptionId::Enum::VAL_WRONG_DESTINATION_ADDRESS;
        return true;
    case DCM_EXCEPTION_ID_VAL_TOO_FREQUENT_SERVICE_ACCESS:
        *obj = ExceptionId::Enum::VAL_TOO_FREQUENT_SERVICE_ACCESS;
        return true;
    case DCM_EXCEPTION_ID_VAL_UNEXPECTED_RADIO_LINK_FAILURES:
        *obj = ExceptionId::Enum::VAL_UNEXPECTED_RADIO_LINK_FAILURES;
        return true;
    case DCM_EXCEPTION_ID_VAL_PING_PONG_ACROSS_CELLS:
        *obj = ExceptionId::Enum::VAL_PING_PONG_ACROSS_CELLS;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_exception_id_set_string(data_collection_model_exception_id_t *obj_exception_id, const char *p_value)
{
    if (!obj_exception_id) return false;
    std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<std::shared_ptr<ExceptionId >*>(obj_exception_id);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = ExceptionId::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_exception_id_make_lnode(data_collection_model_exception_id_t *p_exception_id)
{
    return data_collection_lnode_create(p_exception_id, reinterpret_cast<void(*)(void*)>(data_collection_model_exception_id_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_exception_id_refcount(data_collection_model_exception_id_t *obj_exception_id)
{
    if (!obj_exception_id) return 0l;
    std::shared_ptr<ExceptionId > &obj = *reinterpret_cast<std::shared_ptr<ExceptionId >*>(obj_exception_id);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

