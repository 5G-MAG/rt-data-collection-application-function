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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "PduSetHandlingInfo.h" already included by data-collection-sp/data-collection.h */
#include "PduSetHandlingInfo-internal.h"
#include "openapi/model/PduSetHandlingInfo.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_create()
{
    return reinterpret_cast<data_collection_model_pdu_set_handling_info_t*>(new std::shared_ptr<PduSetHandlingInfo>(new PduSetHandlingInfo()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_create_copy(const data_collection_model_pdu_set_handling_info_t *other)
{
    return reinterpret_cast<data_collection_model_pdu_set_handling_info_t*>(new std::shared_ptr<PduSetHandlingInfo >(new PduSetHandlingInfo(**reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_create_move(data_collection_model_pdu_set_handling_info_t *other)
{
    return reinterpret_cast<data_collection_model_pdu_set_handling_info_t*>(new std::shared_ptr<PduSetHandlingInfo >(std::move(*reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_copy(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, const data_collection_model_pdu_set_handling_info_t *other)
{
    std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(pdu_set_handling_info);
    *obj = **reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(other);
    return pdu_set_handling_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_move(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, data_collection_model_pdu_set_handling_info_t *other)
{
    std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(pdu_set_handling_info);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(other));
    return pdu_set_handling_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_pdu_set_handling_info_free(data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info)
{
    delete reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(pdu_set_handling_info);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_pdu_set_handling_info_toJSON(const data_collection_model_pdu_set_handling_info_t *pdu_set_handling_info, bool as_request)
{
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(pdu_set_handling_info);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_pdu_set_handling_info_t *data_collection_model_pdu_set_handling_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_is_not_set(const data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info)
{
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    return obj->getValue() == PduSetHandlingInfo::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_is_non_standard(const data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info)
{
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    return obj->getValue() == PduSetHandlingInfo::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_pdu_set_handling_info_e data_collection_model_pdu_set_handling_info_get_enum(const data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info)
{
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
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

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_pdu_set_handling_info_get_string(const data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info)
{
    const std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<const std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_set_enum(data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info, data_collection_model_pdu_set_handling_info_e p_value)
{
    std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
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

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_pdu_set_handling_info_set_string(data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info, const char *p_value)
{
    std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = PduSetHandlingInfo::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_pdu_set_handling_info_make_lnode(data_collection_model_pdu_set_handling_info_t *p_pdu_set_handling_info)
{
    return data_collection_lnode_create(p_pdu_set_handling_info, reinterpret_cast<void(*)(void*)>(data_collection_model_pdu_set_handling_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_pdu_set_handling_info_refcount(data_collection_model_pdu_set_handling_info_t *obj_pdu_set_handling_info)
{
    std::shared_ptr<PduSetHandlingInfo > &obj = *reinterpret_cast<std::shared_ptr<PduSetHandlingInfo >*>(obj_pdu_set_handling_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

