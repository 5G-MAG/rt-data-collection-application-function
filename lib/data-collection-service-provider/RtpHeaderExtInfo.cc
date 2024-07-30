/**********************************************************************************************************************************
 * RtpHeaderExtInfo - C interface to the RtpHeaderExtInfo object
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

/*#include "RtpHeaderExtInfo.h" already included by data-collection-sp/data-collection.h */
#include "RtpHeaderExtInfo-internal.h"
#include "openapi/model/RtpHeaderExtInfo.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create(



)
{
    return reinterpret_cast<data_collection_model_rtp_header_ext_info_t*>(new std::shared_ptr<RtpHeaderExtInfo>(new RtpHeaderExtInfo(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create_copy(const data_collection_model_rtp_header_ext_info_t *other)
{
    return reinterpret_cast<data_collection_model_rtp_header_ext_info_t*>(new std::shared_ptr<RtpHeaderExtInfo >(new RtpHeaderExtInfo(**reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create_move(data_collection_model_rtp_header_ext_info_t *other)
{
    return reinterpret_cast<data_collection_model_rtp_header_ext_info_t*>(new std::shared_ptr<RtpHeaderExtInfo >(std::move(*reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_copy(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const data_collection_model_rtp_header_ext_info_t *other)
{
    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(rtp_header_ext_info);
    *obj = **reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(other);
    return rtp_header_ext_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, data_collection_model_rtp_header_ext_info_t *other)
{
    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(rtp_header_ext_info);
    obj = std::move(*reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(other));
    return rtp_header_ext_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_rtp_header_ext_info_free(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info)
{
    delete reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(rtp_header_ext_info);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_rtp_header_ext_info_toJSON(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, bool as_request)
{
    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(rtp_header_ext_info);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_rtp_header_ext_info_t*>(new std::shared_ptr<RtpHeaderExtInfo >(new RtpHeaderExtInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_rtp_header_ext_info_is_equal_to(const data_collection_model_rtp_header_ext_info_t *first, const data_collection_model_rtp_header_ext_info_t *second)
{
    const std::shared_ptr<RtpHeaderExtInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(first);
    const std::shared_ptr<RtpHeaderExtInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_rtp_header_ext_type_t* data_collection_model_rtp_header_ext_info_get_rtp_header_ext_type(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    typedef typename RtpHeaderExtInfo::RtpHeaderExtTypeType ResultFromType;
    const ResultFromType result_from = obj->getRtpHeaderExtType();
    const data_collection_model_rtp_header_ext_type_t *result = reinterpret_cast<const data_collection_model_rtp_header_ext_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_type(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, const data_collection_model_rtp_header_ext_type_t* p_rtp_header_ext_type)
{
    if (obj_rtp_header_ext_info == NULL) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    const auto &value_from = p_rtp_header_ext_type;
    typedef typename RtpHeaderExtInfo::RtpHeaderExtTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRtpHeaderExtType(value)) return NULL;
    return obj_rtp_header_ext_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_type_move(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, data_collection_model_rtp_header_ext_type_t* p_rtp_header_ext_type)
{
    if (obj_rtp_header_ext_info == NULL) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    const auto &value_from = p_rtp_header_ext_type;
    typedef typename RtpHeaderExtInfo::RtpHeaderExtTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRtpHeaderExtType(std::move(value))) return NULL;
    return obj_rtp_header_ext_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_rtp_header_ext_info_get_rtp_header_ext_id(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    typedef typename RtpHeaderExtInfo::RtpHeaderExtIdType ResultFromType;
    const ResultFromType result_from = obj->getRtpHeaderExtId();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_id(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, const int32_t p_rtp_header_ext_id)
{
    if (obj_rtp_header_ext_info == NULL) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    const auto &value_from = p_rtp_header_ext_id;
    typedef typename RtpHeaderExtInfo::RtpHeaderExtIdType ValueType;

    ValueType value = value_from;
    if (!obj->setRtpHeaderExtId(value)) return NULL;
    return obj_rtp_header_ext_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_id_move(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, int32_t p_rtp_header_ext_id)
{
    if (obj_rtp_header_ext_info == NULL) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    const auto &value_from = p_rtp_header_ext_id;
    typedef typename RtpHeaderExtInfo::RtpHeaderExtIdType ValueType;

    ValueType value = value_from;
    
    if (!obj->setRtpHeaderExtId(std::move(value))) return NULL;
    return obj_rtp_header_ext_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_rtp_header_ext_info_is_long_format(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    typedef typename RtpHeaderExtInfo::LongFormatType ResultFromType;
    const ResultFromType result_from = obj->isLongFormat();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_long_format(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, const bool p_long_format)
{
    if (obj_rtp_header_ext_info == NULL) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    const auto &value_from = p_long_format;
    typedef typename RtpHeaderExtInfo::LongFormatType ValueType;

    ValueType value = value_from;
    if (!obj->setLongFormat(value)) return NULL;
    return obj_rtp_header_ext_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_long_format_move(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, bool p_long_format)
{
    if (obj_rtp_header_ext_info == NULL) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    const auto &value_from = p_long_format;
    typedef typename RtpHeaderExtInfo::LongFormatType ValueType;

    ValueType value = value_from;
    
    if (!obj->setLongFormat(std::move(value))) return NULL;
    return obj_rtp_header_ext_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_rtp_header_ext_info_is_pdu_set_size_active(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    typedef typename RtpHeaderExtInfo::PduSetSizeActiveType ResultFromType;
    const ResultFromType result_from = obj->isPduSetSizeActive();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_pdu_set_size_active(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, const bool p_pdu_set_size_active)
{
    if (obj_rtp_header_ext_info == NULL) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    const auto &value_from = p_pdu_set_size_active;
    typedef typename RtpHeaderExtInfo::PduSetSizeActiveType ValueType;

    ValueType value = value_from;
    if (!obj->setPduSetSizeActive(value)) return NULL;
    return obj_rtp_header_ext_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_pdu_set_size_active_move(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, bool p_pdu_set_size_active)
{
    if (obj_rtp_header_ext_info == NULL) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    const auto &value_from = p_pdu_set_size_active;
    typedef typename RtpHeaderExtInfo::PduSetSizeActiveType ValueType;

    ValueType value = value_from;
    
    if (!obj->setPduSetSizeActive(std::move(value))) return NULL;
    return obj_rtp_header_ext_info;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_rtp_header_ext_info_make_lnode(data_collection_model_rtp_header_ext_info_t *p_rtp_header_ext_info)
{
    return data_collection_lnode_create(p_rtp_header_ext_info, reinterpret_cast<void(*)(void*)>(data_collection_model_rtp_header_ext_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_rtp_header_ext_info_refcount(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

