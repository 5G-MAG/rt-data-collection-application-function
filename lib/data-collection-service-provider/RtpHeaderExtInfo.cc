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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create(



)
{
    return reinterpret_cast<data_collection_model_rtp_header_ext_info_t*>(new std::shared_ptr<RtpHeaderExtInfo>(new RtpHeaderExtInfo(



)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create_copy(const data_collection_model_rtp_header_ext_info_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_rtp_header_ext_info_t*>(new std::shared_ptr<RtpHeaderExtInfo >(new RtpHeaderExtInfo(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_create_move(data_collection_model_rtp_header_ext_info_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > *obj = reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_copy(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, const data_collection_model_rtp_header_ext_info_t *other)
{
    if (rtp_header_ext_info) {
        std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(rtp_header_ext_info);
        if (obj) {
            if (other) {
                const std::shared_ptr<RtpHeaderExtInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(other);
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
                const std::shared_ptr<RtpHeaderExtInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(other);
                if (other_obj) {
                    obj.reset(new RtpHeaderExtInfo(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        rtp_header_ext_info = data_collection_model_rtp_header_ext_info_create_copy(other);
    }
    return rtp_header_ext_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_move(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, data_collection_model_rtp_header_ext_info_t *other)
{
    std::shared_ptr<RtpHeaderExtInfo > *other_ptr = reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(other);

    if (rtp_header_ext_info) {
        std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(rtp_header_ext_info);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                rtp_header_ext_info = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return rtp_header_ext_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_rtp_header_ext_info_free(data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info)
{
    if (!rtp_header_ext_info) return;
    delete reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(rtp_header_ext_info);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_rtp_header_ext_info_toJSON(const data_collection_model_rtp_header_ext_info_t *rtp_header_ext_info, bool as_request)
{
    if (!rtp_header_ext_info) return NULL;
    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(rtp_header_ext_info);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_is_equal_to(const data_collection_model_rtp_header_ext_info_t *first, const data_collection_model_rtp_header_ext_info_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<RtpHeaderExtInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<RtpHeaderExtInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_has_rtp_header_ext_type(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    if (!obj_rtp_header_ext_info) return false;

    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return false;

    return obj->getRtpHeaderExtType().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_rtp_header_ext_type_t* data_collection_model_rtp_header_ext_info_get_rtp_header_ext_type(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    if (!obj_rtp_header_ext_info) {
        const data_collection_model_rtp_header_ext_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) {
        const data_collection_model_rtp_header_ext_type_t *result = NULL;
        return result;
    }

    typedef typename RtpHeaderExtInfo::RtpHeaderExtTypeType ResultFromType;
    const ResultFromType result_from = obj->getRtpHeaderExtType();
    const data_collection_model_rtp_header_ext_type_t *result = reinterpret_cast<const data_collection_model_rtp_header_ext_type_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_type(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, const data_collection_model_rtp_header_ext_type_t* p_rtp_header_ext_type)
{
    if (!obj_rtp_header_ext_info) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_header_ext_type;
    typedef typename RtpHeaderExtInfo::RtpHeaderExtTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRtpHeaderExtType(value)) return NULL;

    return obj_rtp_header_ext_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_type_move(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, data_collection_model_rtp_header_ext_type_t* p_rtp_header_ext_type)
{
    if (!obj_rtp_header_ext_info) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_header_ext_type;
    typedef typename RtpHeaderExtInfo::RtpHeaderExtTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setRtpHeaderExtType(std::move(value))) return NULL;

    return obj_rtp_header_ext_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_has_rtp_header_ext_id(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    if (!obj_rtp_header_ext_info) return false;

    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return false;

    return obj->getRtpHeaderExtId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_rtp_header_ext_info_get_rtp_header_ext_id(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    if (!obj_rtp_header_ext_info) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename RtpHeaderExtInfo::RtpHeaderExtIdType ResultFromType;
    const ResultFromType result_from = obj->getRtpHeaderExtId();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_id(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, const int32_t p_rtp_header_ext_id)
{
    if (!obj_rtp_header_ext_info) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_header_ext_id;
    typedef typename RtpHeaderExtInfo::RtpHeaderExtIdType ValueType;

    ValueType value(value_from);

    if (!obj->setRtpHeaderExtId(value)) return NULL;

    return obj_rtp_header_ext_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_rtp_header_ext_id_move(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, int32_t p_rtp_header_ext_id)
{
    if (!obj_rtp_header_ext_info) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_header_ext_id;
    typedef typename RtpHeaderExtInfo::RtpHeaderExtIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setRtpHeaderExtId(std::move(value))) return NULL;

    return obj_rtp_header_ext_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_has_long_format(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    if (!obj_rtp_header_ext_info) return false;

    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return false;

    return obj->isLongFormat().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_rtp_header_ext_info_is_long_format(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    if (!obj_rtp_header_ext_info) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename RtpHeaderExtInfo::LongFormatType ResultFromType;
    const ResultFromType result_from = obj->isLongFormat();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_long_format(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, const bool p_long_format)
{
    if (!obj_rtp_header_ext_info) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return NULL;

    const auto &value_from = p_long_format;
    typedef typename RtpHeaderExtInfo::LongFormatType ValueType;

    ValueType value(value_from);

    if (!obj->setLongFormat(value)) return NULL;

    return obj_rtp_header_ext_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_long_format_move(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, bool p_long_format)
{
    if (!obj_rtp_header_ext_info) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return NULL;

    const auto &value_from = p_long_format;
    typedef typename RtpHeaderExtInfo::LongFormatType ValueType;

    ValueType value(value_from);

    
    if (!obj->setLongFormat(std::move(value))) return NULL;

    return obj_rtp_header_ext_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_header_ext_info_has_pdu_set_size_active(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    if (!obj_rtp_header_ext_info) return false;

    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return false;

    return obj->isPduSetSizeActive().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_rtp_header_ext_info_is_pdu_set_size_active(const data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    if (!obj_rtp_header_ext_info) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename RtpHeaderExtInfo::PduSetSizeActiveType ResultFromType;
    const ResultFromType result_from = obj->isPduSetSizeActive();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_pdu_set_size_active(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, const bool p_pdu_set_size_active)
{
    if (!obj_rtp_header_ext_info) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return NULL;

    const auto &value_from = p_pdu_set_size_active;
    typedef typename RtpHeaderExtInfo::PduSetSizeActiveType ValueType;

    ValueType value(value_from);

    if (!obj->setPduSetSizeActive(value)) return NULL;

    return obj_rtp_header_ext_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_header_ext_info_t *data_collection_model_rtp_header_ext_info_set_pdu_set_size_active_move(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info, bool p_pdu_set_size_active)
{
    if (!obj_rtp_header_ext_info) return NULL;

    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    if (!obj) return NULL;

    const auto &value_from = p_pdu_set_size_active;
    typedef typename RtpHeaderExtInfo::PduSetSizeActiveType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPduSetSizeActive(std::move(value))) return NULL;

    return obj_rtp_header_ext_info;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_rtp_header_ext_info_make_lnode(data_collection_model_rtp_header_ext_info_t *p_rtp_header_ext_info)
{
    return data_collection_lnode_create(p_rtp_header_ext_info, reinterpret_cast<void(*)(void*)>(data_collection_model_rtp_header_ext_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_rtp_header_ext_info_refcount(data_collection_model_rtp_header_ext_info_t *obj_rtp_header_ext_info)
{
    if (!obj_rtp_header_ext_info) return 0l;
    std::shared_ptr<RtpHeaderExtInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpHeaderExtInfo >*>(obj_rtp_header_ext_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

