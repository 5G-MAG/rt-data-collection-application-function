/**********************************************************************************************************************************
 * RtpHeaderExtType - C interface to the RtpHeaderExtType object
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

/*#include "RtpHeaderExtType.h" already included by data-collection-sp/data-collection.h */
#include "RtpHeaderExtType-internal.h"
#include "openapi/model/RtpHeaderExtType.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_type_t *data_collection_model_rtp_header_ext_type_create()
{
    return reinterpret_cast<data_collection_model_rtp_header_ext_type_t*>(new std::shared_ptr<RtpHeaderExtType>(new RtpHeaderExtType()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_type_t *data_collection_model_rtp_header_ext_type_create_copy(const data_collection_model_rtp_header_ext_type_t *other)
{
    return reinterpret_cast<data_collection_model_rtp_header_ext_type_t*>(new std::shared_ptr<RtpHeaderExtType >(new RtpHeaderExtType(**reinterpret_cast<const std::shared_ptr<RtpHeaderExtType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_type_t *data_collection_model_rtp_header_ext_type_create_move(data_collection_model_rtp_header_ext_type_t *other)
{
    return reinterpret_cast<data_collection_model_rtp_header_ext_type_t*>(new std::shared_ptr<RtpHeaderExtType >(std::move(*reinterpret_cast<std::shared_ptr<RtpHeaderExtType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_type_t *data_collection_model_rtp_header_ext_type_copy(data_collection_model_rtp_header_ext_type_t *rtp_header_ext_type, const data_collection_model_rtp_header_ext_type_t *other)
{
    std::shared_ptr<RtpHeaderExtType > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtType >*>(rtp_header_ext_type);
    *obj = **reinterpret_cast<const std::shared_ptr<RtpHeaderExtType >*>(other);
    return rtp_header_ext_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_type_t *data_collection_model_rtp_header_ext_type_move(data_collection_model_rtp_header_ext_type_t *rtp_header_ext_type, data_collection_model_rtp_header_ext_type_t *other)
{
    std::shared_ptr<RtpHeaderExtType > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtType >*>(rtp_header_ext_type);
    obj = std::move(*reinterpret_cast<std::shared_ptr<RtpHeaderExtType >*>(other));
    return rtp_header_ext_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_rtp_header_ext_type_free(data_collection_model_rtp_header_ext_type_t *rtp_header_ext_type)
{
    delete reinterpret_cast<std::shared_ptr<RtpHeaderExtType >*>(rtp_header_ext_type);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_rtp_header_ext_type_toJSON(const data_collection_model_rtp_header_ext_type_t *rtp_header_ext_type, bool as_request)
{
    const std::shared_ptr<RtpHeaderExtType > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtType >*>(rtp_header_ext_type);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_type_t *data_collection_model_rtp_header_ext_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_rtp_header_ext_type_t*>(new std::shared_ptr<RtpHeaderExtType >(new RtpHeaderExtType(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_type_is_not_set(const data_collection_model_rtp_header_ext_type_t *obj_rtp_header_ext_type)
{
    const std::shared_ptr<RtpHeaderExtType > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtType >*>(obj_rtp_header_ext_type);
    return obj->getValue() == RtpHeaderExtType::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_type_is_non_standard(const data_collection_model_rtp_header_ext_type_t *obj_rtp_header_ext_type)
{
    const std::shared_ptr<RtpHeaderExtType > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtType >*>(obj_rtp_header_ext_type);
    return obj->getValue() == RtpHeaderExtType::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_type_e data_collection_model_rtp_header_ext_type_get_enum(const data_collection_model_rtp_header_ext_type_t *obj_rtp_header_ext_type)
{
    const std::shared_ptr<RtpHeaderExtType > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtType >*>(obj_rtp_header_ext_type);
    switch (obj->getValue()) {
    case RtpHeaderExtType::Enum::NO_VAL:
        return DCM_RTP_HEADER_EXT_TYPE_NO_VAL;
    case RtpHeaderExtType::Enum::VAL_PDU_SET_MARKING:
        return DCM_RTP_HEADER_EXT_TYPE_VAL_PDU_SET_MARKING;
    default:
        break;
    }
    return DCM_RTP_HEADER_EXT_TYPE_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_rtp_header_ext_type_get_string(const data_collection_model_rtp_header_ext_type_t *obj_rtp_header_ext_type)
{
    const std::shared_ptr<RtpHeaderExtType > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtType >*>(obj_rtp_header_ext_type);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_type_set_enum(data_collection_model_rtp_header_ext_type_t *obj_rtp_header_ext_type, data_collection_model_rtp_header_ext_type_e p_value)
{
    std::shared_ptr<RtpHeaderExtType > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtType >*>(obj_rtp_header_ext_type);
    switch (p_value) {
    case DCM_RTP_HEADER_EXT_TYPE_NO_VAL:
        *obj = RtpHeaderExtType::Enum::NO_VAL;
        return true;
    case DCM_RTP_HEADER_EXT_TYPE_VAL_PDU_SET_MARKING:
        *obj = RtpHeaderExtType::Enum::VAL_PDU_SET_MARKING;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_type_set_string(data_collection_model_rtp_header_ext_type_t *obj_rtp_header_ext_type, const char *p_value)
{
    std::shared_ptr<RtpHeaderExtType > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtType >*>(obj_rtp_header_ext_type);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = RtpHeaderExtType::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_rtp_header_ext_type_make_lnode(data_collection_model_rtp_header_ext_type_t *p_rtp_header_ext_type)
{
    return data_collection_lnode_create(p_rtp_header_ext_type, reinterpret_cast<void(*)(void*)>(data_collection_model_rtp_header_ext_type_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_rtp_header_ext_type_refcount(data_collection_model_rtp_header_ext_type_t *obj_rtp_header_ext_type)
{
    std::shared_ptr<RtpHeaderExtType > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtType >*>(obj_rtp_header_ext_type);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

