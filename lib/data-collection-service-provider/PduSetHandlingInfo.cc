/**********************************************************************************************************************************
 * PduSetHandlingInfo - C interface to the PduSetHandlingInfo object
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

/*#include "PduSetHandlingInfo.h" already included by data-collection-sp/data-collection.h */
#include "PduSetHandlingInfo-internal.h"
#include "openapi/model/PduSetHandlingInfo.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_create()
{
    return reinterpret_cast<data_collection_model_pdu_set_handling_info_t*>(new std::shared_ptr<PduSetHandlingInfo>(new PduSetHandlingInfo()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_create_copy(const data_collection_model_pdu_set_handling_info_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_pdu_set_handling_info_t*>(new std::shared_ptr<PduSetHandlingInfo >(new PduSetHandlingInfo(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_create_move(data_collection_model_pdu_set_handling_info_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PduSetHandlingInfo > *obj = reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_copy(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, const data_collection_model_pdu_set_handling_info_t *other)
{
    if (pdu_set_handling_info) {
        std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(pdu_set_handling_info);
        if (obj) {
            if (other) {
                const std::shared_ptr<PduSetHandlingInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(other);
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
                const std::shared_ptr<PduSetHandlingInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(other);
                if (other_obj) {
                    obj.reset(new PduSetHandlingInfo(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        pdu_set_handling_info = data_collection_model_pdu_set_handling_info_create_copy(other);
    }
    return pdu_set_handling_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_move(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, data_collection_model_pdu_set_handling_info_t *other)
{
    std::shared_ptr<PduSetHandlingInfo > *other_ptr = reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(other);

    if (pdu_set_handling_info) {
        std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(pdu_set_handling_info);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                pdu_set_handling_info = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return pdu_set_handling_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_pdu_set_handling_info_free(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info)
{
    if (!pdu_set_handling_info) return;
    delete reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(pdu_set_handling_info);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_pdu_set_handling_info_toJSON(const data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, bool as_request)
{
    if (!pdu_set_handling_info) return NULL;
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(pdu_set_handling_info);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_pdu_set_handling_info_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_pdu_set_handling_info_t*>(new std::shared_ptr<PduSetHandlingInfo >(new PduSetHandlingInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_is_equal_to(const data_collection_model_pdu_set_handling_info_t *first, const data_collection_model_pdu_set_handling_info_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PduSetHandlingInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PduSetHandlingInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_is_not_set(const data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info)
{
    if (!obj_pdu_set_handling_info) return true;
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    if (!obj) return true;
    return obj->getValue() == PduSetHandlingInfo::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_is_non_standard(const data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info)
{
    if (!obj_pdu_set_handling_info) return false;
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    if (!obj) return false;
    return obj->getValue() == PduSetHandlingInfo::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_e data_collection_model_pdu_set_handling_info_get_enum(const data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info)
{
    if (!obj_pdu_set_handling_info)
        return DCM_PDU_SET_HANDLING_INFO_NO_VAL;
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    if (!obj) return DCM_PDU_SET_HANDLING_INFO_NO_VAL;
    switch (obj->getValue()) {
    case PduSetHandlingInfo::Enum::NO_VAL:
        return DCM_PDU_SET_HANDLING_INFO_NO_VAL;
    case PduSetHandlingInfo::Enum::VAL_ALL_PDUS_NEEDED:
        return DCM_PDU_SET_HANDLING_INFO_VAL_ALL_PDUS_NEEDED;
    case PduSetHandlingInfo::Enum::VAL_ALL_PDUS_NOT_NEEDED:
        return DCM_PDU_SET_HANDLING_INFO_VAL_ALL_PDUS_NOT_NEEDED;
    default:
        break;
    }
    return DCM_PDU_SET_HANDLING_INFO_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_pdu_set_handling_info_get_string(const data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info)
{
    if (!obj_pdu_set_handling_info) return NULL;
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_set_enum(data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info, data_collection_model_pdu_set_handling_info_e p_value)
{
    if (!obj_pdu_set_handling_info) return false;
    std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    if (!obj) return false;
    switch (p_value) {
    case DCM_PDU_SET_HANDLING_INFO_NO_VAL:
        *obj = PduSetHandlingInfo::Enum::NO_VAL;
        return true;
    case DCM_PDU_SET_HANDLING_INFO_VAL_ALL_PDUS_NEEDED:
        *obj = PduSetHandlingInfo::Enum::VAL_ALL_PDUS_NEEDED;
        return true;
    case DCM_PDU_SET_HANDLING_INFO_VAL_ALL_PDUS_NOT_NEEDED:
        *obj = PduSetHandlingInfo::Enum::VAL_ALL_PDUS_NOT_NEEDED;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_set_string(data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info, const char *p_value)
{
    if (!obj_pdu_set_handling_info) return false;
    std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = PduSetHandlingInfo::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_pdu_set_handling_info_make_lnode(data_collection_model_pdu_set_handling_info_t *p_pdu_set_handling_info)
{
    return data_collection_lnode_create(p_pdu_set_handling_info, reinterpret_cast<void(*)(void*)>(data_collection_model_pdu_set_handling_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_pdu_set_handling_info_refcount(data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info)
{
    if (!obj_pdu_set_handling_info) return 0l;
    std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

