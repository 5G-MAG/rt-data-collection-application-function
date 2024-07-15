/**********************************************************************************************************************************
 * RtpPayloadFormat - C interface to the RtpPayloadFormat object
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

/*#include "RtpPayloadFormat.h" already included by data-collection-sp/data-collection.h */
#include "RtpPayloadFormat-internal.h"
#include "openapi/model/RtpPayloadFormat.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_create()
{
    return reinterpret_cast<data_collection_model_rtp_payload_format_t*>(new std::shared_ptr<RtpPayloadFormat>(new RtpPayloadFormat()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_create_copy(const data_collection_model_rtp_payload_format_t *other)
{
    return reinterpret_cast<data_collection_model_rtp_payload_format_t*>(new std::shared_ptr<RtpPayloadFormat >(new RtpPayloadFormat(**reinterpret_cast<const std::shared_ptr<RtpPayloadFormat >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_create_move(data_collection_model_rtp_payload_format_t *other)
{
    return reinterpret_cast<data_collection_model_rtp_payload_format_t*>(new std::shared_ptr<RtpPayloadFormat >(std::move(*reinterpret_cast<std::shared_ptr<RtpPayloadFormat >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_copy(data_collection_model_rtp_payload_format_t *rtp_payload_format, const data_collection_model_rtp_payload_format_t *other)
{
    std::shared_ptr<RtpPayloadFormat > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadFormat >*>(rtp_payload_format);
    *obj = **reinterpret_cast<const std::shared_ptr<RtpPayloadFormat >*>(other);
    return rtp_payload_format;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_move(data_collection_model_rtp_payload_format_t *rtp_payload_format, data_collection_model_rtp_payload_format_t *other)
{
    std::shared_ptr<RtpPayloadFormat > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadFormat >*>(rtp_payload_format);
    obj = std::move(*reinterpret_cast<std::shared_ptr<RtpPayloadFormat >*>(other));
    return rtp_payload_format;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_rtp_payload_format_free(data_collection_model_rtp_payload_format_t *rtp_payload_format)
{
    delete reinterpret_cast<std::shared_ptr<RtpPayloadFormat >*>(rtp_payload_format);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_rtp_payload_format_toJSON(const data_collection_model_rtp_payload_format_t *rtp_payload_format, bool as_request)
{
    const std::shared_ptr<RtpPayloadFormat > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadFormat >*>(rtp_payload_format);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_payload_format_t *data_collection_model_rtp_payload_format_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_rtp_payload_format_t*>(new std::shared_ptr<RtpPayloadFormat >(new RtpPayloadFormat(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_format_is_not_set(const data_collection_model_rtp_payload_format_t *obj_rtp_payload_format)
{
    const std::shared_ptr<RtpPayloadFormat > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadFormat >*>(obj_rtp_payload_format);
    return obj->getValue() == RtpPayloadFormat::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_format_is_non_standard(const data_collection_model_rtp_payload_format_t *obj_rtp_payload_format)
{
    const std::shared_ptr<RtpPayloadFormat > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadFormat >*>(obj_rtp_payload_format);
    return obj->getValue() == RtpPayloadFormat::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_format_e data_collection_model_rtp_payload_format_get_enum(const data_collection_model_rtp_payload_format_t *obj_rtp_payload_format)
{
    const std::shared_ptr<RtpPayloadFormat > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadFormat >*>(obj_rtp_payload_format);
    switch (obj->getValue()) {
    case RtpPayloadFormat::Enum::NO_VAL:
        return DCM_RTP_PAYLOAD_FORMAT_NO_VAL;
    case RtpPayloadFormat::Enum::VAL_H264:
        return DCM_RTP_PAYLOAD_FORMAT_VAL_H264;
    case RtpPayloadFormat::Enum::VAL_H265:
        return DCM_RTP_PAYLOAD_FORMAT_VAL_H265;
    default:
        break;
    }
    return DCM_RTP_PAYLOAD_FORMAT_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_rtp_payload_format_get_string(const data_collection_model_rtp_payload_format_t *obj_rtp_payload_format)
{
    const std::shared_ptr<RtpPayloadFormat > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadFormat >*>(obj_rtp_payload_format);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_format_set_enum(data_collection_model_rtp_payload_format_t *obj_rtp_payload_format, data_collection_model_rtp_payload_format_e p_value)
{
    std::shared_ptr<RtpPayloadFormat > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadFormat >*>(obj_rtp_payload_format);
    switch (p_value) {
    case DCM_RTP_PAYLOAD_FORMAT_NO_VAL:
        *obj = RtpPayloadFormat::Enum::NO_VAL;
        return true;
    case DCM_RTP_PAYLOAD_FORMAT_VAL_H264:
        *obj = RtpPayloadFormat::Enum::VAL_H264;
        return true;
    case DCM_RTP_PAYLOAD_FORMAT_VAL_H265:
        *obj = RtpPayloadFormat::Enum::VAL_H265;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_format_set_string(data_collection_model_rtp_payload_format_t *obj_rtp_payload_format, const char *p_value)
{
    std::shared_ptr<RtpPayloadFormat > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadFormat >*>(obj_rtp_payload_format);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = RtpPayloadFormat::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_rtp_payload_format_make_lnode(data_collection_model_rtp_payload_format_t *p_rtp_payload_format)
{
    return data_collection_lnode_create(p_rtp_payload_format, reinterpret_cast<void(*)(void*)>(data_collection_model_rtp_payload_format_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_rtp_payload_format_refcount(data_collection_model_rtp_payload_format_t *obj_rtp_payload_format)
{
    std::shared_ptr<RtpPayloadFormat > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadFormat >*>(obj_rtp_payload_format);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

