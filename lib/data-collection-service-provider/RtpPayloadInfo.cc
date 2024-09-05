/**********************************************************************************************************************************
 * RtpPayloadInfo - C interface to the RtpPayloadInfo object
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

/*#include "RtpPayloadInfo.h" already included by data-collection-sp/data-collection.h */
#include "RtpPayloadInfo-internal.h"
#include "openapi/model/RtpPayloadInfo.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_create(

)
{
    return reinterpret_cast<data_collection_model_rtp_payload_info_t*>(new std::shared_ptr<RtpPayloadInfo>(new RtpPayloadInfo(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_create_copy(const data_collection_model_rtp_payload_info_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadInfo >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_rtp_payload_info_t*>(new std::shared_ptr<RtpPayloadInfo >(new RtpPayloadInfo(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_create_move(data_collection_model_rtp_payload_info_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<RtpPayloadInfo > *obj = reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_copy(data_collection_model_rtp_payload_info_t *rtp_payload_info, const data_collection_model_rtp_payload_info_t *other)
{
    if (rtp_payload_info) {
        std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(rtp_payload_info);
        if (obj) {
            if (other) {
                const std::shared_ptr<RtpPayloadInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadInfo >*>(other);
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
                const std::shared_ptr<RtpPayloadInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadInfo >*>(other);
                if (other_obj) {
                    obj.reset(new RtpPayloadInfo(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        rtp_payload_info = data_collection_model_rtp_payload_info_create_copy(other);
    }
    return rtp_payload_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_move(data_collection_model_rtp_payload_info_t *rtp_payload_info, data_collection_model_rtp_payload_info_t *other)
{
    std::shared_ptr<RtpPayloadInfo > *other_ptr = reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(other);

    if (rtp_payload_info) {
        std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(rtp_payload_info);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                rtp_payload_info = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return rtp_payload_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_rtp_payload_info_free(data_collection_model_rtp_payload_info_t *rtp_payload_info)
{
    if (!rtp_payload_info) return;
    delete reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(rtp_payload_info);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_rtp_payload_info_toJSON(const data_collection_model_rtp_payload_info_t *rtp_payload_info, bool as_request)
{
    if (!rtp_payload_info) return NULL;
    const std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadInfo >*>(rtp_payload_info);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_rtp_payload_info_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_rtp_payload_info_t*>(new std::shared_ptr<RtpPayloadInfo >(new RtpPayloadInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_info_is_equal_to(const data_collection_model_rtp_payload_info_t *first, const data_collection_model_rtp_payload_info_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<RtpPayloadInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<RtpPayloadInfo >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<RtpPayloadInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<RtpPayloadInfo >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_info_has_rtp_payload_type_list(const data_collection_model_rtp_payload_info_t *obj_rtp_payload_info)
{
    if (!obj_rtp_payload_info) return false;

    const std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) return false;

    return obj->getRtpPayloadTypeList().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_rtp_payload_info_get_rtp_payload_type_list(const data_collection_model_rtp_payload_info_t *obj_rtp_payload_info)
{
    if (!obj_rtp_payload_info) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename RtpPayloadInfo::RtpPayloadTypeListType ResultFromType;
    const ResultFromType result_from = obj->getRtpPayloadTypeList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        int32_t *item_obj = reinterpret_cast<int32_t*>(item.has_value()?ogs_malloc(sizeof(*item_obj)):nullptr);
        if (item_obj) {
            *item_obj = item.value();
            node = data_collection_lnode_create(item_obj, reinterpret_cast<void(*)(void*)>(_ogs_free));
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *obj_rtp_payload_info, const ogs_list_t* p_rtp_payload_type_list)
{
    if (!obj_rtp_payload_info) return NULL;

    std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_payload_type_list;
    typedef typename RtpPayloadInfo::RtpPayloadTypeListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRtpPayloadTypeList(value)) return NULL;

    return obj_rtp_payload_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_type_list_move(data_collection_model_rtp_payload_info_t *obj_rtp_payload_info, ogs_list_t* p_rtp_payload_type_list)
{
    if (!obj_rtp_payload_info) return NULL;

    std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_payload_type_list;
    typedef typename RtpPayloadInfo::RtpPayloadTypeListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_rtp_payload_type_list);
    if (!obj->setRtpPayloadTypeList(std::move(value))) return NULL;

    return obj_rtp_payload_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_add_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *obj_rtp_payload_info, int32_t p_rtp_payload_type_list)
{
    if (!obj_rtp_payload_info) return NULL;

    std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) return NULL;

    typedef typename RtpPayloadInfo::RtpPayloadTypeListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_rtp_payload_type_list;

    ValueType value(value_from);


    if (value) obj->addRtpPayloadTypeList(value.value());
    return obj_rtp_payload_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_remove_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *obj_rtp_payload_info, const int32_t p_rtp_payload_type_list)
{
    if (!obj_rtp_payload_info) return NULL;

    std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) return NULL;

    typedef typename RtpPayloadInfo::RtpPayloadTypeListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_rtp_payload_type_list;
    ValueType value(value_from);

    obj->removeRtpPayloadTypeList(value);
    return obj_rtp_payload_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_clear_rtp_payload_type_list(data_collection_model_rtp_payload_info_t *obj_rtp_payload_info)
{
    if (!obj_rtp_payload_info) return NULL;

    std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) return NULL;

    obj->clearRtpPayloadTypeList();
    return obj_rtp_payload_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_rtp_payload_info_has_rtp_payload_format(const data_collection_model_rtp_payload_info_t *obj_rtp_payload_info)
{
    if (!obj_rtp_payload_info) return false;

    const std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) return false;

    return obj->getRtpPayloadFormat().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_rtp_payload_format_t* data_collection_model_rtp_payload_info_get_rtp_payload_format(const data_collection_model_rtp_payload_info_t *obj_rtp_payload_info)
{
    if (!obj_rtp_payload_info) {
        const data_collection_model_rtp_payload_format_t *result = NULL;
        return result;
    }

    const std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<const std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) {
        const data_collection_model_rtp_payload_format_t *result = NULL;
        return result;
    }

    typedef typename RtpPayloadInfo::RtpPayloadFormatType ResultFromType;
    const ResultFromType result_from = obj->getRtpPayloadFormat();
    const data_collection_model_rtp_payload_format_t *result = reinterpret_cast<const data_collection_model_rtp_payload_format_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_format(data_collection_model_rtp_payload_info_t *obj_rtp_payload_info, const data_collection_model_rtp_payload_format_t* p_rtp_payload_format)
{
    if (!obj_rtp_payload_info) return NULL;

    std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_payload_format;
    typedef typename RtpPayloadInfo::RtpPayloadFormatType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setRtpPayloadFormat(value)) return NULL;

    return obj_rtp_payload_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_rtp_payload_info_t *data_collection_model_rtp_payload_info_set_rtp_payload_format_move(data_collection_model_rtp_payload_info_t *obj_rtp_payload_info, data_collection_model_rtp_payload_format_t* p_rtp_payload_format)
{
    if (!obj_rtp_payload_info) return NULL;

    std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    if (!obj) return NULL;

    const auto &value_from = p_rtp_payload_format;
    typedef typename RtpPayloadInfo::RtpPayloadFormatType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setRtpPayloadFormat(std::move(value))) return NULL;

    return obj_rtp_payload_info;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_rtp_payload_info_make_lnode(data_collection_model_rtp_payload_info_t *p_rtp_payload_info)
{
    return data_collection_lnode_create(p_rtp_payload_info, reinterpret_cast<void(*)(void*)>(data_collection_model_rtp_payload_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_rtp_payload_info_refcount(data_collection_model_rtp_payload_info_t *obj_rtp_payload_info)
{
    if (!obj_rtp_payload_info) return 0l;
    std::shared_ptr<RtpPayloadInfo > &obj = *reinterpret_cast<std::shared_ptr<RtpPayloadInfo >*>(obj_rtp_payload_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

