/**********************************************************************************************************************************
 * ServiceExperienceInfoPerApp - C interface to the ServiceExperienceInfoPerApp object
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

/*#include "ServiceExperienceInfoPerApp.h" already included by data-collection-sp/data-collection.h */
#include "ServiceExperienceInfoPerApp-internal.h"
#include "openapi/model/ServiceExperienceInfoPerApp.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_create(





)
{
    return reinterpret_cast<data_collection_model_service_experience_info_per_app_t*>(new std::shared_ptr<ServiceExperienceInfoPerApp>(new ServiceExperienceInfoPerApp(





)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_create_copy(const data_collection_model_service_experience_info_per_app_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_service_experience_info_per_app_t*>(new std::shared_ptr<ServiceExperienceInfoPerApp >(new ServiceExperienceInfoPerApp(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_create_move(data_collection_model_service_experience_info_per_app_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > *obj = reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_copy(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const data_collection_model_service_experience_info_per_app_t *other)
{
    if (service_experience_info_per_app) {
        std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(service_experience_info_per_app);
        if (obj) {
            if (other) {
                const std::shared_ptr<ServiceExperienceInfoPerApp > &other_obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(other);
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
                const std::shared_ptr<ServiceExperienceInfoPerApp > &other_obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(other);
                if (other_obj) {
                    obj.reset(new ServiceExperienceInfoPerApp(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        service_experience_info_per_app = data_collection_model_service_experience_info_per_app_create_copy(other);
    }
    return service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_move(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, data_collection_model_service_experience_info_per_app_t *other)
{
    std::shared_ptr<ServiceExperienceInfoPerApp > *other_ptr = reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(other);

    if (service_experience_info_per_app) {
        std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(service_experience_info_per_app);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                service_experience_info_per_app = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_service_experience_info_per_app_free(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app)
{
    if (!service_experience_info_per_app) return;
    delete reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(service_experience_info_per_app);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_service_experience_info_per_app_toJSON(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, bool as_request)
{
    if (!service_experience_info_per_app) return NULL;
    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(service_experience_info_per_app);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_service_experience_info_per_app_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_service_experience_info_per_app_t*>(new std::shared_ptr<ServiceExperienceInfoPerApp >(new ServiceExperienceInfoPerApp(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_is_equal_to(const data_collection_model_service_experience_info_per_app_t *first, const data_collection_model_service_experience_info_per_app_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj2 = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj1 = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_has_app_id(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return false;

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return false;

    return obj->getAppId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_service_experience_info_per_app_get_app_id(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerApp::AppIdType ResultFromType;
    const ResultFromType &result_from = obj->getAppId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_id(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const char* p_app_id)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename ServiceExperienceInfoPerApp::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(value)) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_id_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, char* p_app_id)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename ServiceExperienceInfoPerApp::AppIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setAppId(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_has_app_server_ins(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return false;

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return false;

    return obj->getAppServerIns().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_service_experience_info_per_app_get_app_server_ins(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) {
        const data_collection_model_addr_fqdn_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) {
        const data_collection_model_addr_fqdn_t *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerApp::AppServerInsType ResultFromType;
    const ResultFromType &result_from = obj->getAppServerIns();
    const data_collection_model_addr_fqdn_t *result = reinterpret_cast<const data_collection_model_addr_fqdn_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_server_ins(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const data_collection_model_addr_fqdn_t* p_app_server_ins)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_app_server_ins;
    typedef typename ServiceExperienceInfoPerApp::AppServerInsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setAppServerIns(value)) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_server_ins_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, data_collection_model_addr_fqdn_t* p_app_server_ins)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_app_server_ins;
    typedef typename ServiceExperienceInfoPerApp::AppServerInsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setAppServerIns(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_info_per_app_get_svc_exp_per_flows(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerApp::SvcExpPerFlowsType ResultFromType;
    const ResultFromType &result_from = obj->getSvcExpPerFlows();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_service_experience_info_per_flow_t *item_obj = reinterpret_cast<data_collection_model_service_experience_info_per_flow_t*>(item.has_value()?new std::shared_ptr<ServiceExperienceInfoPerFlow >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_service_experience_info_per_flow_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const ogs_list_t* p_svc_exp_per_flows)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_svc_exp_per_flows;
    typedef typename ServiceExperienceInfoPerApp::SvcExpPerFlowsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setSvcExpPerFlows(value)) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_svc_exp_per_flows_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, ogs_list_t* p_svc_exp_per_flows)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_svc_exp_per_flows;
    typedef typename ServiceExperienceInfoPerApp::SvcExpPerFlowsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        
        auto &container(value);
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_svc_exp_per_flows);
    if (!obj->setSvcExpPerFlows(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, data_collection_model_service_experience_info_per_flow_t* p_svc_exp_per_flows)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::SvcExpPerFlowsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_svc_exp_per_flows;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_service_experience_info_per_flow_free(p_svc_exp_per_flows);
    obj->addSvcExpPerFlows(value);
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const data_collection_model_service_experience_info_per_flow_t* p_svc_exp_per_flows)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::SvcExpPerFlowsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_svc_exp_per_flows;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeSvcExpPerFlows(value);
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_service_experience_info_per_flow_t* data_collection_model_service_experience_info_per_app_get_entry_svc_exp_per_flows(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, size_t idx)
{
    if (!obj_service_experience_info_per_app) {
        const data_collection_model_service_experience_info_per_flow_t *result = NULL;

        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) {
        const data_collection_model_service_experience_info_per_flow_t *result = NULL;

        return result;
    }

    const ServiceExperienceInfoPerApp::SvcExpPerFlowsType &container = obj->getSvcExpPerFlows();
    

    auto itr = container.cbegin();
    while (idx > 0 && itr != container.cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.cend()) {
        const data_collection_model_service_experience_info_per_flow_t *result = NULL;

        return result;
    }
    typedef typename ServiceExperienceInfoPerApp::SvcExpPerFlowsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_service_experience_info_per_flow_t *result = reinterpret_cast<const data_collection_model_service_experience_info_per_flow_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    obj->clearSvcExpPerFlows();
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_has_gpsis(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return false;

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return false;

    return obj->getGpsis().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_info_per_app_get_gpsis(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerApp::GpsisType ResultFromType;
    const ResultFromType &result_from = obj->getGpsis();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_gpsis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const ogs_list_t* p_gpsis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_gpsis;
    typedef typename ServiceExperienceInfoPerApp::GpsisType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setGpsis(value)) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_gpsis_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, ogs_list_t* p_gpsis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_gpsis;
    typedef typename ServiceExperienceInfoPerApp::GpsisType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_gpsis);
    if (!obj->setGpsis(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_gpsis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, char* p_gpsis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::GpsisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_gpsis;

    ValueType value(value_from);

    ogs_free(p_gpsis);
    if (value) obj->addGpsis(value.value());
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_gpsis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const char* p_gpsis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::GpsisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_gpsis;
    ValueType value(value_from);

    obj->removeGpsis(value);
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_service_experience_info_per_app_get_entry_gpsis(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, size_t idx)
{
    if (!obj_service_experience_info_per_app) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    const ServiceExperienceInfoPerApp::GpsisType &container = obj->getGpsis();
    if (!container.has_value()) {
        const char *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const char *result = NULL;

        return result;
    }
    typedef typename ServiceExperienceInfoPerApp::GpsisItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_gpsis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    obj->clearGpsis();
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_has_supis(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return false;

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return false;

    return obj->getSupis().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_info_per_app_get_supis(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerApp::SupisType ResultFromType;
    const ResultFromType &result_from = obj->getSupis();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_supis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const ogs_list_t* p_supis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_supis;
    typedef typename ServiceExperienceInfoPerApp::SupisType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setSupis(value)) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_supis_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, ogs_list_t* p_supis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_supis;
    typedef typename ServiceExperienceInfoPerApp::SupisType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_supis);
    if (!obj->setSupis(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_supis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, char* p_supis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::SupisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_supis;

    ValueType value(value_from);

    ogs_free(p_supis);
    if (value) obj->addSupis(value.value());
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_supis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const char* p_supis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::SupisType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_supis;
    ValueType value(value_from);

    obj->removeSupis(value);
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_service_experience_info_per_app_get_entry_supis(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, size_t idx)
{
    if (!obj_service_experience_info_per_app) {
        const char *result = NULL;

        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) {
        const char *result = NULL;

        return result;
    }

    const ServiceExperienceInfoPerApp::SupisType &container = obj->getSupis();
    if (!container.has_value()) {
        const char *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const char *result = NULL;

        return result;
    }
    typedef typename ServiceExperienceInfoPerApp::SupisItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_supis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    obj->clearSupis();
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_service_experience_info_per_app_has_contr_weights(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return false;

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return false;

    return obj->getContrWeights().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_service_experience_info_per_app_get_contr_weights(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ServiceExperienceInfoPerApp::ContrWeightsType ResultFromType;
    const ResultFromType &result_from = obj->getContrWeights();
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_contr_weights(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const ogs_list_t* p_contr_weights)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_contr_weights;
    typedef typename ServiceExperienceInfoPerApp::ContrWeightsType ValueType;

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

    if (!obj->setContrWeights(value)) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_contr_weights_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, ogs_list_t* p_contr_weights)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_contr_weights;
    typedef typename ServiceExperienceInfoPerApp::ContrWeightsType ValueType;

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

    data_collection_list_free(p_contr_weights);
    if (!obj->setContrWeights(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_contr_weights(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, int32_t p_contr_weights)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::ContrWeightsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_contr_weights;

    ValueType value(value_from);

    (p_contr_weights);
    if (value) obj->addContrWeights(value.value());
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_contr_weights(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const int32_t p_contr_weights)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::ContrWeightsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_contr_weights;
    ValueType value(value_from);

    obj->removeContrWeights(value);
    return obj_service_experience_info_per_app;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_service_experience_info_per_app_get_entry_contr_weights(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, size_t idx)
{
    if (!obj_service_experience_info_per_app) {
        const int32_t result = 0;

        return result;
    }

    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) {
        const int32_t result = 0;

        return result;
    }

    const ServiceExperienceInfoPerApp::ContrWeightsType &container = obj->getContrWeights();
    if (!container.has_value()) {
        const int32_t result = 0;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const int32_t result = 0;

        return result;
    }
    typedef typename ServiceExperienceInfoPerApp::ContrWeightsItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_contr_weights(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    obj->clearContrWeights();
    return obj_service_experience_info_per_app;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_service_experience_info_per_app_make_lnode(data_collection_model_service_experience_info_per_app_t *p_service_experience_info_per_app)
{
    return data_collection_lnode_create(p_service_experience_info_per_app, reinterpret_cast<void(*)(void*)>(data_collection_model_service_experience_info_per_app_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_service_experience_info_per_app_refcount(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return 0l;
    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

