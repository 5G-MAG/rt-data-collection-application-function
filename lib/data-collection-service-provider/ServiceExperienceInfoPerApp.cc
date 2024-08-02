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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "ServiceExperienceInfoPerApp.h" already included by data-collection-sp/data-collection.h */
#include "ServiceExperienceInfoPerApp-internal.h"
#include "openapi/model/ServiceExperienceInfoPerApp.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_create(





)
{
    return reinterpret_cast<data_collection_model_service_experience_info_per_app_t*>(new std::shared_ptr<ServiceExperienceInfoPerApp>(new ServiceExperienceInfoPerApp(





)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_create_copy(const data_collection_model_service_experience_info_per_app_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_service_experience_info_per_app_t*>(new std::shared_ptr<ServiceExperienceInfoPerApp >(new ServiceExperienceInfoPerApp(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_create_move(data_collection_model_service_experience_info_per_app_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > *obj = reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_copy(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, const data_collection_model_service_experience_info_per_app_t *other)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_move(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, data_collection_model_service_experience_info_per_app_t *other)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_service_experience_info_per_app_free(data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app)
{
    if (!service_experience_info_per_app) return;
    delete reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(service_experience_info_per_app);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_service_experience_info_per_app_toJSON(const data_collection_model_service_experience_info_per_app_t *service_experience_info_per_app, bool as_request)
{
    if (!service_experience_info_per_app) return NULL;
    const std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<const std::shared_ptr<ServiceExperienceInfoPerApp >*>(service_experience_info_per_app);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_service_experience_info_per_app_is_equal_to(const data_collection_model_service_experience_info_per_app_t *first, const data_collection_model_service_experience_info_per_app_t *second)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_service_experience_info_per_app_get_app_id(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
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
    const ResultFromType result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_id(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const char* p_app_id)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_id_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, char* p_app_id)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_addr_fqdn_t* data_collection_model_service_experience_info_per_app_get_app_server_ins(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
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
    const ResultFromType result_from = obj->getAppServerIns();
    const data_collection_model_addr_fqdn_t *result = reinterpret_cast<const data_collection_model_addr_fqdn_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_server_ins(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const data_collection_model_addr_fqdn_t* p_app_server_ins)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_app_server_ins;
    typedef typename ServiceExperienceInfoPerApp::AppServerInsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setAppServerIns(value)) return NULL;

    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_app_server_ins_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, data_collection_model_addr_fqdn_t* p_app_server_ins)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_app_server_ins;
    typedef typename ServiceExperienceInfoPerApp::AppServerInsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setAppServerIns(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_service_experience_info_per_app_get_svc_exp_per_flows(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
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
    const ResultFromType result_from = obj->getSvcExpPerFlows();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        data_collection_model_service_experience_info_per_flow_t *item_obj = reinterpret_cast<data_collection_model_service_experience_info_per_flow_t*>(new std::shared_ptr<ServiceExperienceInfoPerFlow >(item));
        node = data_collection_model_service_experience_info_per_flow_make_lnode(item_obj);
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const ogs_list_t* p_svc_exp_per_flows)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_svc_exp_per_flows;
    typedef typename ServiceExperienceInfoPerApp::SvcExpPerFlowsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setSvcExpPerFlows(value)) return NULL;

    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_svc_exp_per_flows_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, ogs_list_t* p_svc_exp_per_flows)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_svc_exp_per_flows;
    typedef typename ServiceExperienceInfoPerApp::SvcExpPerFlowsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_svc_exp_per_flows);
    if (!obj->setSvcExpPerFlows(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, data_collection_model_service_experience_info_per_flow_t* p_svc_exp_per_flows)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::SvcExpPerFlowsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_svc_exp_per_flows;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    obj->addSvcExpPerFlows(value);
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const data_collection_model_service_experience_info_per_flow_t* p_svc_exp_per_flows)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::SvcExpPerFlowsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_svc_exp_per_flows;
    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    obj->removeSvcExpPerFlows(value);
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_svc_exp_per_flows(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    obj->clearSvcExpPerFlows();
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_service_experience_info_per_app_get_gpsis(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
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
    const ResultFromType result_from = obj->getGpsis();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_gpsis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const ogs_list_t* p_gpsis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_gpsis;
    typedef typename ServiceExperienceInfoPerApp::GpsisType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setGpsis(value)) return NULL;

    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_gpsis_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, ogs_list_t* p_gpsis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_gpsis;
    typedef typename ServiceExperienceInfoPerApp::GpsisType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_gpsis);
    if (!obj->setGpsis(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_gpsis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, char* p_gpsis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::GpsisType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_gpsis;

    ValueType value(value_from);

    obj->addGpsis(value);
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_gpsis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const char* p_gpsis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::GpsisType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_gpsis;
    ValueType value(value_from);
    obj->removeGpsis(value);
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_gpsis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    obj->clearGpsis();
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_service_experience_info_per_app_get_supis(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
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
    const ResultFromType result_from = obj->getSupis();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_supis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const ogs_list_t* p_supis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_supis;
    typedef typename ServiceExperienceInfoPerApp::SupisType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setSupis(value)) return NULL;

    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_supis_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, ogs_list_t* p_supis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_supis;
    typedef typename ServiceExperienceInfoPerApp::SupisType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_supis);
    if (!obj->setSupis(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_supis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, char* p_supis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::SupisType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_supis;

    ValueType value(value_from);

    obj->addSupis(value);
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_supis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const char* p_supis)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::SupisType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_supis;
    ValueType value(value_from);
    obj->removeSupis(value);
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_supis(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    obj->clearSupis();
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_service_experience_info_per_app_get_contr_weights(const data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
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
    const ResultFromType result_from = obj->getContrWeights();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        int32_t *item_obj = reinterpret_cast<int32_t*>(ogs_malloc(sizeof(*item_obj)));
        *item_obj = item;
        node = data_collection_lnode_create(item_obj, reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_contr_weights(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const ogs_list_t* p_contr_weights)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_contr_weights;
    typedef typename ServiceExperienceInfoPerApp::ContrWeightsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setContrWeights(value)) return NULL;

    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_set_contr_weights_move(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, ogs_list_t* p_contr_weights)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    const auto &value_from = p_contr_weights;
    typedef typename ServiceExperienceInfoPerApp::ContrWeightsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_contr_weights);
    if (!obj->setContrWeights(std::move(value))) return NULL;

    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_add_contr_weights(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, int32_t p_contr_weights)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::ContrWeightsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_contr_weights;

    ValueType value = value_from;

    obj->addContrWeights(value);
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_remove_contr_weights(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app, const int32_t p_contr_weights)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    typedef typename ServiceExperienceInfoPerApp::ContrWeightsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_contr_weights;
    ValueType value = value_from;
    obj->removeContrWeights(value);
    return obj_service_experience_info_per_app;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_service_experience_info_per_app_t *data_collection_model_service_experience_info_per_app_clear_contr_weights(data_collection_model_service_experience_info_per_app_t *obj_service_experience_info_per_app)
{
    if (!obj_service_experience_info_per_app) return NULL;

    std::shared_ptr<ServiceExperienceInfoPerApp > &obj = *reinterpret_cast<std::shared_ptr<ServiceExperienceInfoPerApp >*>(obj_service_experience_info_per_app);
    if (!obj) return NULL;

    obj->clearContrWeights();
    return obj_service_experience_info_per_app;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_service_experience_info_per_app_make_lnode(data_collection_model_service_experience_info_per_app_t *p_service_experience_info_per_app)
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

