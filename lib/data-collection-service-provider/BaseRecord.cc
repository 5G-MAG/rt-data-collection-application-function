/**********************************************************************************************************************************
 * BaseRecord - C interface to the BaseRecord object
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

/*#include "BaseRecord.h" already included by data-collection-sp/data-collection.h */
#include "BaseRecord-internal.h"
#include "openapi/model/BaseRecord.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_create(

)
{
    return reinterpret_cast<data_collection_model_base_record_t*>(new std::shared_ptr<BaseRecord>(new BaseRecord(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_create_ref(const data_collection_model_base_record_t *other)
{
    return reinterpret_cast<data_collection_model_base_record_t*>(new std::shared_ptr<BaseRecord>(*reinterpret_cast<const std::shared_ptr<BaseRecord >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_create_copy(const data_collection_model_base_record_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_base_record_t*>(new std::shared_ptr<BaseRecord >(new BaseRecord(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_create_move(data_collection_model_base_record_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<BaseRecord > *obj = reinterpret_cast<std::shared_ptr<BaseRecord >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_copy(data_collection_model_base_record_t *base_record, const data_collection_model_base_record_t *other)
{
    if (base_record) {
        std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(base_record);
        if (obj) {
            if (other) {
                const std::shared_ptr<BaseRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(other);
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
                const std::shared_ptr<BaseRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(other);
                if (other_obj) {
                    obj.reset(new BaseRecord(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        base_record = data_collection_model_base_record_create_copy(other);
    }
    return base_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_move(data_collection_model_base_record_t *base_record, data_collection_model_base_record_t *other)
{
    std::shared_ptr<BaseRecord > *other_ptr = reinterpret_cast<std::shared_ptr<BaseRecord >*>(other);

    if (base_record) {
        std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(base_record);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                base_record = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return base_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_base_record_free(data_collection_model_base_record_t *base_record)
{
    if (!base_record) return;
    delete reinterpret_cast<std::shared_ptr<BaseRecord >*>(base_record);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_base_record_toJSON(const data_collection_model_base_record_t *base_record, bool as_request)
{
    if (!base_record) return NULL;
    const std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(base_record);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_base_record_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_base_record_t*>(new std::shared_ptr<BaseRecord >(new BaseRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_base_record_is_equal_to(const data_collection_model_base_record_t *first, const data_collection_model_base_record_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<BaseRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<BaseRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_record_get_timestamp(const data_collection_model_base_record_t *obj_base_record)
{
    if (!obj_base_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(obj_base_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename BaseRecord::TimestampType ResultFromType;
    const ResultFromType &result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_timestamp(data_collection_model_base_record_t *obj_base_record, const char* p_timestamp)
{
    if (!obj_base_record) return NULL;

    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename BaseRecord::TimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setTimestamp(value)) return NULL;

    return obj_base_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_timestamp_move(data_collection_model_base_record_t *obj_base_record, char* p_timestamp)
{
    if (!obj_base_record) return NULL;

    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    if (!obj) return NULL;

    const auto &value_from = p_timestamp;
    typedef typename BaseRecord::TimestampType ValueType;

    ValueType value(value_from);

    if (!obj->setTimestamp(std::move(value))) return NULL;
    ogs_free
(p_timestamp);

    return obj_base_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_base_record_get_context_ids(const data_collection_model_base_record_t *obj_base_record)
{
    if (!obj_base_record) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(obj_base_record);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename BaseRecord::ContextIdsType ResultFromType;
    const ResultFromType &result_from = obj->getContextIds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_context_ids(data_collection_model_base_record_t *obj_base_record, const ogs_list_t* p_context_ids)
{
    if (!obj_base_record) return NULL;

    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename BaseRecord::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setContextIds(value)) return NULL;

    return obj_base_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_set_context_ids_move(data_collection_model_base_record_t *obj_base_record, ogs_list_t* p_context_ids)
{
    if (!obj_base_record) return NULL;

    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    if (!obj) return NULL;

    const auto &value_from = p_context_ids;
    typedef typename BaseRecord::ContextIdsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setContextIds(std::move(value))) return NULL;
    data_collection_list_free
(p_context_ids);

    return obj_base_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_add_context_ids(data_collection_model_base_record_t *obj_base_record, char* p_context_ids)
{
    if (!obj_base_record) return NULL;

    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    if (!obj) return NULL;

    typedef typename BaseRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_context_ids;

    ValueType value(value_from);

    ogs_free
(p_context_ids);
    obj->addContextIds(value);
    return obj_base_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_remove_context_ids(data_collection_model_base_record_t *obj_base_record, const char* p_context_ids)
{
    if (!obj_base_record) return NULL;

    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    if (!obj) return NULL;

    typedef typename BaseRecord::ContextIdsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_context_ids;
    ValueType value(value_from);

    obj->removeContextIds(value);
    return obj_base_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_base_record_get_entry_context_ids(const data_collection_model_base_record_t *obj_base_record, size_t idx)
{
    if (!obj_base_record) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(obj_base_record);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    const BaseRecord::ContextIdsType &container = obj->getContextIds();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const char *result = NULL;

        return result;
    }
    typedef typename BaseRecord::ContextIdsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_base_record_t *data_collection_model_base_record_clear_context_ids(data_collection_model_base_record_t *obj_base_record)
{
    if (!obj_base_record) return NULL;

    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    if (!obj) return NULL;

    obj->clearContextIds();
    return obj_base_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_base_record_make_lnode(data_collection_model_base_record_t *p_base_record)
{
    return data_collection_lnode_create(p_base_record, reinterpret_cast<void(*)(void*)>(data_collection_model_base_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_base_record_refcount(data_collection_model_base_record_t *obj_base_record)
{
    if (!obj_base_record) return 0l;
    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

