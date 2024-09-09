/**********************************************************************************************************************************
 * NetworkAssistanceInvocationsCollection_allOf - C interface to the NetworkAssistanceInvocationsCollection_allOf object
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

/*#include "NetworkAssistanceInvocationsCollection_allOf.h" already included by data-collection-sp/data-collection.h */
#include "NetworkAssistanceInvocationsCollection_allOf-internal.h"
#include "openapi/model/NetworkAssistanceInvocationsCollection_allOf.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_create(
)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocations_collection_all_of_t*>(new std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf>(new NetworkAssistanceInvocationsCollection_allOf(
)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_create_copy(const data_collection_model_network_assistance_invocations_collection_all_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_network_assistance_invocations_collection_all_of_t*>(new std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >(new NetworkAssistanceInvocationsCollection_allOf(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_create_move(data_collection_model_network_assistance_invocations_collection_all_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > *obj = reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_copy(data_collection_model_network_assistance_invocations_collection_all_of_t *network_assistance_invocations_collection_all_of, const data_collection_model_network_assistance_invocations_collection_all_of_t *other)
{
    if (network_assistance_invocations_collection_all_of) {
        std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(network_assistance_invocations_collection_all_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(other);
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
                const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(other);
                if (other_obj) {
                    obj.reset(new NetworkAssistanceInvocationsCollection_allOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        network_assistance_invocations_collection_all_of = data_collection_model_network_assistance_invocations_collection_all_of_create_copy(other);
    }
    return network_assistance_invocations_collection_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_move(data_collection_model_network_assistance_invocations_collection_all_of_t *network_assistance_invocations_collection_all_of, data_collection_model_network_assistance_invocations_collection_all_of_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > *other_ptr = reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(other);

    if (network_assistance_invocations_collection_all_of) {
        std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(network_assistance_invocations_collection_all_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                network_assistance_invocations_collection_all_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return network_assistance_invocations_collection_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_invocations_collection_all_of_free(data_collection_model_network_assistance_invocations_collection_all_of_t *network_assistance_invocations_collection_all_of)
{
    if (!network_assistance_invocations_collection_all_of) return;
    delete reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(network_assistance_invocations_collection_all_of);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_invocations_collection_all_of_toJSON(const data_collection_model_network_assistance_invocations_collection_all_of_t *network_assistance_invocations_collection_all_of, bool as_request)
{
    if (!network_assistance_invocations_collection_all_of) return NULL;
    const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(network_assistance_invocations_collection_all_of);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_network_assistance_invocations_collection_all_of_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_network_assistance_invocations_collection_all_of_t*>(new std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >(new NetworkAssistanceInvocationsCollection_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocations_collection_all_of_is_equal_to(const data_collection_model_network_assistance_invocations_collection_all_of_t *first, const data_collection_model_network_assistance_invocations_collection_all_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_network_assistance_invocations_collection_all_of_get_records(const data_collection_model_network_assistance_invocations_collection_all_of_t *obj_network_assistance_invocations_collection_all_of)
{
    if (!obj_network_assistance_invocations_collection_all_of) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(obj_network_assistance_invocations_collection_all_of);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationsCollection_allOf::RecordsType ResultFromType;
    const ResultFromType &result_from = obj->getRecords();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_network_assistance_invocation_event_t *item_obj = reinterpret_cast<data_collection_model_network_assistance_invocation_event_t*>(item.has_value()?new std::shared_ptr<NetworkAssistanceInvocationEvent >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_network_assistance_invocation_event_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_set_records(data_collection_model_network_assistance_invocations_collection_all_of_t *obj_network_assistance_invocations_collection_all_of, const ogs_list_t* p_records)
{
    if (!obj_network_assistance_invocations_collection_all_of) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(obj_network_assistance_invocations_collection_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_records;
    typedef typename NetworkAssistanceInvocationsCollection_allOf::RecordsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setRecords(value)) return NULL;

    return obj_network_assistance_invocations_collection_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_set_records_move(data_collection_model_network_assistance_invocations_collection_all_of_t *obj_network_assistance_invocations_collection_all_of, ogs_list_t* p_records)
{
    if (!obj_network_assistance_invocations_collection_all_of) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(obj_network_assistance_invocations_collection_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_records;
    typedef typename NetworkAssistanceInvocationsCollection_allOf::RecordsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_records);
    if (!obj->setRecords(std::move(value))) return NULL;

    return obj_network_assistance_invocations_collection_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_add_records(data_collection_model_network_assistance_invocations_collection_all_of_t *obj_network_assistance_invocations_collection_all_of, data_collection_model_network_assistance_invocation_event_t* p_records)
{
    if (!obj_network_assistance_invocations_collection_all_of) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(obj_network_assistance_invocations_collection_all_of);
    if (!obj) return NULL;

    typedef typename NetworkAssistanceInvocationsCollection_allOf::RecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_records;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    obj->addRecords(value);
    return obj_network_assistance_invocations_collection_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_remove_records(data_collection_model_network_assistance_invocations_collection_all_of_t *obj_network_assistance_invocations_collection_all_of, const data_collection_model_network_assistance_invocation_event_t* p_records)
{
    if (!obj_network_assistance_invocations_collection_all_of) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(obj_network_assistance_invocations_collection_all_of);
    if (!obj) return NULL;

    typedef typename NetworkAssistanceInvocationsCollection_allOf::RecordsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_records;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeRecords(value);
    return obj_network_assistance_invocations_collection_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocations_collection_all_of_t *data_collection_model_network_assistance_invocations_collection_all_of_clear_records(data_collection_model_network_assistance_invocations_collection_all_of_t *obj_network_assistance_invocations_collection_all_of)
{
    if (!obj_network_assistance_invocations_collection_all_of) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(obj_network_assistance_invocations_collection_all_of);
    if (!obj) return NULL;

    obj->clearRecords();
    return obj_network_assistance_invocations_collection_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_invocations_collection_all_of_make_lnode(data_collection_model_network_assistance_invocations_collection_all_of_t *p_network_assistance_invocations_collection_all_of)
{
    return data_collection_lnode_create(p_network_assistance_invocations_collection_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_network_assistance_invocations_collection_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_assistance_invocations_collection_all_of_refcount(data_collection_model_network_assistance_invocations_collection_all_of_t *obj_network_assistance_invocations_collection_all_of)
{
    if (!obj_network_assistance_invocations_collection_all_of) return 0l;
    std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationsCollection_allOf >*>(obj_network_assistance_invocations_collection_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

