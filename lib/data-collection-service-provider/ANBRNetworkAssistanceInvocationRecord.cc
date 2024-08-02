/**********************************************************************************************************************************
 * ANBRNetworkAssistanceInvocationRecord - C interface to the ANBRNetworkAssistanceInvocationRecord object
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

/*#include "ANBRNetworkAssistanceInvocationRecord.h" already included by data-collection-sp/data-collection.h */
#include "ANBRNetworkAssistanceInvocationRecord-internal.h"
#include "openapi/model/ANBRNetworkAssistanceInvocationRecord.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_create(









)
{
    return reinterpret_cast<data_collection_model_anbr_network_assistance_invocation_record_t*>(new std::shared_ptr<ANBRNetworkAssistanceInvocationRecord>(new ANBRNetworkAssistanceInvocationRecord(









)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_create_copy(const data_collection_model_anbr_network_assistance_invocation_record_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_anbr_network_assistance_invocation_record_t*>(new std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >(new ANBRNetworkAssistanceInvocationRecord(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_create_move(data_collection_model_anbr_network_assistance_invocation_record_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > *obj = reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_copy(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, const data_collection_model_anbr_network_assistance_invocation_record_t *other)
{
    if (anbr_network_assistance_invocation_record) {
        std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(anbr_network_assistance_invocation_record);
        if (obj) {
            if (other) {
                const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(other);
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
                const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(other);
                if (other_obj) {
                    obj.reset(new ANBRNetworkAssistanceInvocationRecord(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        anbr_network_assistance_invocation_record = data_collection_model_anbr_network_assistance_invocation_record_create_copy(other);
    }
    return anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_move(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, data_collection_model_anbr_network_assistance_invocation_record_t *other)
{
    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > *other_ptr = reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(other);

    if (anbr_network_assistance_invocation_record) {
        std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(anbr_network_assistance_invocation_record);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                anbr_network_assistance_invocation_record = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_anbr_network_assistance_invocation_record_free(data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record)
{
    if (!anbr_network_assistance_invocation_record) return;
    delete reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(anbr_network_assistance_invocation_record);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_anbr_network_assistance_invocation_record_toJSON(const data_collection_model_anbr_network_assistance_invocation_record_t *anbr_network_assistance_invocation_record, bool as_request)
{
    if (!anbr_network_assistance_invocation_record) return NULL;
    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(anbr_network_assistance_invocation_record);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_anbr_network_assistance_invocation_record_t*>(new std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >(new ANBRNetworkAssistanceInvocationRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_anbr_network_assistance_invocation_record_is_equal_to(const data_collection_model_anbr_network_assistance_invocation_record_t *first, const data_collection_model_anbr_network_assistance_invocation_record_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_anbr_network_assistance_invocation_record_get_timestamp(const data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ANBRNetworkAssistanceInvocationRecord::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_timestamp(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const char* p_timestamp)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename ANBRNetworkAssistanceInvocationRecord::TimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimestamp(value)) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_timestamp_move(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, char* p_timestamp)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename ANBRNetworkAssistanceInvocationRecord::TimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimestamp(std::move(value))) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_anbr_network_assistance_invocation_record_get_context_ids(const data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ANBRNetworkAssistanceInvocationRecord::ContextIdsType ResultFromType;
    const ResultFromType result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const ogs_list_t* p_context_ids)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename ANBRNetworkAssistanceInvocationRecord::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setContextIds(value)) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_context_ids_move(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, ogs_list_t* p_context_ids)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename ANBRNetworkAssistanceInvocationRecord::ContextIdsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_context_ids);
    if (!obj->setContextIds(std::move(value))) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_add_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, char* p_context_ids)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    typedef typename ANBRNetworkAssistanceInvocationRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    obj->addContextIds(value);
    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_remove_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const char* p_context_ids)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    typedef typename ANBRNetworkAssistanceInvocationRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);
    obj->removeContextIds(value);
    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_clear_context_ids(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    obj->clearContextIds();
    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_snssai_t* data_collection_model_anbr_network_assistance_invocation_record_get_slice_info(const data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    typedef typename ANBRNetworkAssistanceInvocationRecord::SliceInfoType ResultFromType;
    const ResultFromType result_from = obj->getSliceInfo();
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_slice_info(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const data_collection_model_snssai_t* p_slice_info)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_slice_info;
    typedef typename ANBRNetworkAssistanceInvocationRecord::SliceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setSliceInfo(value)) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_slice_info_move(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, data_collection_model_snssai_t* p_slice_info)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_slice_info;
    typedef typename ANBRNetworkAssistanceInvocationRecord::SliceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setSliceInfo(std::move(value))) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_anbr_network_assistance_invocation_record_get_data_network_name(const data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ANBRNetworkAssistanceInvocationRecord::DataNetworkNameType ResultFromType;
    const ResultFromType result_from = obj->getDataNetworkName();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_data_network_name(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const char* p_data_network_name)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename ANBRNetworkAssistanceInvocationRecord::DataNetworkNameType ValueType;

    ValueType value(value_from);
    if (!obj->setDataNetworkName(value)) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_data_network_name_move(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, char* p_data_network_name)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename ANBRNetworkAssistanceInvocationRecord::DataNetworkNameType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDataNetworkName(std::move(value))) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_typed_location_t* data_collection_model_anbr_network_assistance_invocation_record_get_location(const data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) {
        const data_collection_model_typed_location_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) {
        const data_collection_model_typed_location_t *result = NULL;
        return result;
    }

    typedef typename ANBRNetworkAssistanceInvocationRecord::LocationType ResultFromType;
    const ResultFromType result_from = obj->getLocation();
    const data_collection_model_typed_location_t *result = reinterpret_cast<const data_collection_model_typed_location_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_location(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const data_collection_model_typed_location_t* p_location)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename ANBRNetworkAssistanceInvocationRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocation(value)) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_location_move(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, data_collection_model_typed_location_t* p_location)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename ANBRNetworkAssistanceInvocationRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocation(std::move(value))) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_anbr_network_assistance_invocation_record_get_session_id(const data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ANBRNetworkAssistanceInvocationRecord::SessionIdType ResultFromType;
    const ResultFromType result_from = obj->getSessionId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_session_id(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const char* p_session_id)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename ANBRNetworkAssistanceInvocationRecord::SessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setSessionId(value)) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_session_id_move(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, char* p_session_id)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_session_id;
    typedef typename ANBRNetworkAssistanceInvocationRecord::SessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSessionId(std::move(value))) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_anbr_network_assistance_invocation_record_get_policy_template_id(const data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ANBRNetworkAssistanceInvocationRecord::PolicyTemplateIdType ResultFromType;
    const ResultFromType result_from = obj->getPolicyTemplateId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_policy_template_id(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const char* p_policy_template_id)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_policy_template_id;
    typedef typename ANBRNetworkAssistanceInvocationRecord::PolicyTemplateIdType ValueType;

    ValueType value(value_from);
    if (!obj->setPolicyTemplateId(value)) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_policy_template_id_move(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, char* p_policy_template_id)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_policy_template_id;
    typedef typename ANBRNetworkAssistanceInvocationRecord::PolicyTemplateIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setPolicyTemplateId(std::move(value))) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_anbr_network_assistance_invocation_record_get_application_flow_descriptions(const data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ANBRNetworkAssistanceInvocationRecord::ApplicationFlowDescriptionsType ResultFromType;
    const ResultFromType result_from = obj->getApplicationFlowDescriptions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_application_flow_description_t *item_obj = reinterpret_cast<data_collection_model_application_flow_description_t*>(new std::shared_ptr<ApplicationFlowDescription >(item));
        node = data_collection_model_application_flow_description_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const ogs_list_t* p_application_flow_descriptions)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_application_flow_descriptions;
    typedef typename ANBRNetworkAssistanceInvocationRecord::ApplicationFlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setApplicationFlowDescriptions(value)) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_application_flow_descriptions_move(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, ogs_list_t* p_application_flow_descriptions)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_application_flow_descriptions;
    typedef typename ANBRNetworkAssistanceInvocationRecord::ApplicationFlowDescriptionsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_application_flow_descriptions);
    if (!obj->setApplicationFlowDescriptions(std::move(value))) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_add_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    typedef typename ANBRNetworkAssistanceInvocationRecord::ApplicationFlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_application_flow_descriptions;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addApplicationFlowDescriptions(value);
    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_remove_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const data_collection_model_application_flow_description_t* p_application_flow_descriptions)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    typedef typename ANBRNetworkAssistanceInvocationRecord::ApplicationFlowDescriptionsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_application_flow_descriptions;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeApplicationFlowDescriptions(value);
    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_clear_application_flow_descriptions(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    obj->clearApplicationFlowDescriptions();
    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_unidirectional_qo_s_specification_t* data_collection_model_anbr_network_assistance_invocation_record_get_requested_qo_s(const data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) {
        const data_collection_model_unidirectional_qo_s_specification_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) {
        const data_collection_model_unidirectional_qo_s_specification_t *result = NULL;
        return result;
    }

    typedef typename ANBRNetworkAssistanceInvocationRecord::RequestedQoSType ResultFromType;
    const ResultFromType result_from = obj->getRequestedQoS();
    const data_collection_model_unidirectional_qo_s_specification_t *result = reinterpret_cast<const data_collection_model_unidirectional_qo_s_specification_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_requested_qo_s(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_requested_qo_s;
    typedef typename ANBRNetworkAssistanceInvocationRecord::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRequestedQoS(value)) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_requested_qo_s_move(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, data_collection_model_unidirectional_qo_s_specification_t* p_requested_qo_s)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_requested_qo_s;
    typedef typename ANBRNetworkAssistanceInvocationRecord::RequestedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRequestedQoS(std::move(value))) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_network_assistance_invocation_recommended_qo_s_t* data_collection_model_anbr_network_assistance_invocation_record_get_recommended_qo_s(const data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) {
        const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<const std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) {
        const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = NULL;
        return result;
    }

    typedef typename ANBRNetworkAssistanceInvocationRecord::RecommendedQoSType ResultFromType;
    const ResultFromType result_from = obj->getRecommendedQoS();
    const data_collection_model_network_assistance_invocation_recommended_qo_s_t *result = reinterpret_cast<const data_collection_model_network_assistance_invocation_recommended_qo_s_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_recommended_qo_s(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, const data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_recommended_qo_s;
    typedef typename ANBRNetworkAssistanceInvocationRecord::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setRecommendedQoS(value)) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_anbr_network_assistance_invocation_record_t *data_collection_model_anbr_network_assistance_invocation_record_set_recommended_qo_s_move(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record, data_collection_model_network_assistance_invocation_recommended_qo_s_t* p_recommended_qo_s)
{
    if (!obj_anbr_network_assistance_invocation_record) return NULL;

    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    if (!obj) return NULL;

    const auto &value_from = p_recommended_qo_s;
    typedef typename ANBRNetworkAssistanceInvocationRecord::RecommendedQoSType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setRecommendedQoS(std::move(value))) return NULL;

    return obj_anbr_network_assistance_invocation_record;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_anbr_network_assistance_invocation_record_make_lnode(data_collection_model_anbr_network_assistance_invocation_record_t *p_anbr_network_assistance_invocation_record)
{
    return data_collection_lnode_create(p_anbr_network_assistance_invocation_record, reinterpret_cast<void(*)(void*)>(data_collection_model_anbr_network_assistance_invocation_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_anbr_network_assistance_invocation_record_refcount(data_collection_model_anbr_network_assistance_invocation_record_t *obj_anbr_network_assistance_invocation_record)
{
    if (!obj_anbr_network_assistance_invocation_record) return 0l;
    std::shared_ptr<ANBRNetworkAssistanceInvocationRecord > &obj = *reinterpret_cast<std::shared_ptr<ANBRNetworkAssistanceInvocationRecord >*>(obj_anbr_network_assistance_invocation_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

