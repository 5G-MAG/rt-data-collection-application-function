/**********************************************************************************************************************************
 * CollectiveBehaviourFilter - C interface to the CollectiveBehaviourFilter object
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

/*#include "CollectiveBehaviourFilter.h" already included by data-collection-sp/data-collection.h */
#include "CollectiveBehaviourFilter-internal.h"
#include "openapi/model/CollectiveBehaviourFilter.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_create(




)
{
    return reinterpret_cast<data_collection_model_collective_behaviour_filter_t*>(new std::shared_ptr<CollectiveBehaviourFilter>(new CollectiveBehaviourFilter(




)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_create_copy(const data_collection_model_collective_behaviour_filter_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_collective_behaviour_filter_t*>(new std::shared_ptr<CollectiveBehaviourFilter >(new CollectiveBehaviourFilter(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_create_move(data_collection_model_collective_behaviour_filter_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > *obj = reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_copy(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_collective_behaviour_filter_t *other)
{
    if (collective_behaviour_filter) {
        std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(collective_behaviour_filter);
        if (obj) {
            if (other) {
                const std::shared_ptr<CollectiveBehaviourFilter > &other_obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(other);
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
                const std::shared_ptr<CollectiveBehaviourFilter > &other_obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(other);
                if (other_obj) {
                    obj.reset(new CollectiveBehaviourFilter(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        collective_behaviour_filter = data_collection_model_collective_behaviour_filter_create_copy(other);
    }
    return collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, data_collection_model_collective_behaviour_filter_t *other)
{
    std::shared_ptr<CollectiveBehaviourFilter > *other_ptr = reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(other);

    if (collective_behaviour_filter) {
        std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(collective_behaviour_filter);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                collective_behaviour_filter = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_collective_behaviour_filter_free(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter)
{
    if (!collective_behaviour_filter) return;
    delete reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(collective_behaviour_filter);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_collective_behaviour_filter_toJSON(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, bool as_request)
{
    if (!collective_behaviour_filter) return NULL;
    const std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(collective_behaviour_filter);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_collective_behaviour_filter_t*>(new std::shared_ptr<CollectiveBehaviourFilter >(new CollectiveBehaviourFilter(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_is_equal_to(const data_collection_model_collective_behaviour_filter_t *first, const data_collection_model_collective_behaviour_filter_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<CollectiveBehaviourFilter > &obj2 = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<CollectiveBehaviourFilter > &obj1 = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_collective_behaviour_filter_type_t* data_collection_model_collective_behaviour_filter_get_type(const data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter)
{
    if (!obj_collective_behaviour_filter) {
        const data_collection_model_collective_behaviour_filter_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) {
        const data_collection_model_collective_behaviour_filter_type_t *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourFilter::TypeType ResultFromType;
    const ResultFromType result_from = obj->getType();
    const data_collection_model_collective_behaviour_filter_type_t *result = reinterpret_cast<const data_collection_model_collective_behaviour_filter_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_type(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, const data_collection_model_collective_behaviour_filter_type_t* p_type)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    const auto &value_from = p_type;
    typedef typename CollectiveBehaviourFilter::TypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setType(value)) return NULL;

    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_type_move(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, data_collection_model_collective_behaviour_filter_type_t* p_type)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    const auto &value_from = p_type;
    typedef typename CollectiveBehaviourFilter::TypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setType(std::move(value))) return NULL;

    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_collective_behaviour_filter_get_value(const data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter)
{
    if (!obj_collective_behaviour_filter) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourFilter::ValueType ResultFromType;
    const ResultFromType result_from = obj->getValue();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_value(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, const char* p_value)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    const auto &value_from = p_value;
    typedef typename CollectiveBehaviourFilter::ValueType ValueType;

    ValueType value(value_from);
    if (!obj->setValue(value)) return NULL;

    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_value_move(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, char* p_value)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    const auto &value_from = p_value;
    typedef typename CollectiveBehaviourFilter::ValueType ValueType;

    ValueType value(value_from);
    
    if (!obj->setValue(std::move(value))) return NULL;

    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_filter_get_coll_beh_attr(const data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter)
{
    if (!obj_collective_behaviour_filter) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourFilter::CollBehAttrType ResultFromType;
    const ResultFromType result_from = obj->getCollBehAttr();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_per_ue_attribute_t *item_obj = reinterpret_cast<data_collection_model_per_ue_attribute_t*>(new std::shared_ptr<PerUeAttribute >(item));
        node = data_collection_model_per_ue_attribute_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, const ogs_list_t* p_coll_beh_attr)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    const auto &value_from = p_coll_beh_attr;
    typedef typename CollectiveBehaviourFilter::CollBehAttrType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setCollBehAttr(value)) return NULL;

    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_coll_beh_attr_move(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, ogs_list_t* p_coll_beh_attr)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    const auto &value_from = p_coll_beh_attr;
    typedef typename CollectiveBehaviourFilter::CollBehAttrType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_coll_beh_attr);
    if (!obj->setCollBehAttr(std::move(value))) return NULL;

    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_add_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, data_collection_model_per_ue_attribute_t* p_coll_beh_attr)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourFilter::CollBehAttrType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_coll_beh_attr;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addCollBehAttr(value);
    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_remove_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, const data_collection_model_per_ue_attribute_t* p_coll_beh_attr)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    typedef typename CollectiveBehaviourFilter::CollBehAttrType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_coll_beh_attr;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeCollBehAttr(value);
    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_clear_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    obj->clearCollBehAttr();
    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_processing_type_t* data_collection_model_collective_behaviour_filter_get_data_proc_type(const data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter)
{
    if (!obj_collective_behaviour_filter) {
        const data_collection_model_data_processing_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) {
        const data_collection_model_data_processing_type_t *result = NULL;
        return result;
    }

    typedef typename CollectiveBehaviourFilter::DataProcTypeType ResultFromType;
    const ResultFromType result_from = obj->getDataProcType();
    const data_collection_model_data_processing_type_t *result = reinterpret_cast<const data_collection_model_data_processing_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_data_proc_type(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, const data_collection_model_data_processing_type_t* p_data_proc_type)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    const auto &value_from = p_data_proc_type;
    typedef typename CollectiveBehaviourFilter::DataProcTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDataProcType(value)) return NULL;

    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_data_proc_type_move(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, data_collection_model_data_processing_type_t* p_data_proc_type)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    const auto &value_from = p_data_proc_type;
    typedef typename CollectiveBehaviourFilter::DataProcTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDataProcType(std::move(value))) return NULL;

    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_collective_behaviour_filter_is_list_of_ue_ind(const data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter)
{
    if (!obj_collective_behaviour_filter) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<const std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename CollectiveBehaviourFilter::ListOfUeIndType ResultFromType;
    const ResultFromType result_from = obj->isListOfUeInd();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_list_of_ue_ind(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, const bool p_list_of_ue_ind)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    const auto &value_from = p_list_of_ue_ind;
    typedef typename CollectiveBehaviourFilter::ListOfUeIndType ValueType;

    ValueType value = value_from;
    if (!obj->setListOfUeInd(value)) return NULL;

    return obj_collective_behaviour_filter;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_list_of_ue_ind_move(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter, bool p_list_of_ue_ind)
{
    if (!obj_collective_behaviour_filter) return NULL;

    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    if (!obj) return NULL;

    const auto &value_from = p_list_of_ue_ind;
    typedef typename CollectiveBehaviourFilter::ListOfUeIndType ValueType;

    ValueType value = value_from;
    
    if (!obj->setListOfUeInd(std::move(value))) return NULL;

    return obj_collective_behaviour_filter;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_collective_behaviour_filter_make_lnode(data_collection_model_collective_behaviour_filter_t *p_collective_behaviour_filter)
{
    return data_collection_lnode_create(p_collective_behaviour_filter, reinterpret_cast<void(*)(void*)>(data_collection_model_collective_behaviour_filter_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_collective_behaviour_filter_refcount(data_collection_model_collective_behaviour_filter_t *obj_collective_behaviour_filter)
{
    if (!obj_collective_behaviour_filter) return 0l;
    std::shared_ptr<CollectiveBehaviourFilter > &obj = *reinterpret_cast<std::shared_ptr<CollectiveBehaviourFilter >*>(obj_collective_behaviour_filter);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

