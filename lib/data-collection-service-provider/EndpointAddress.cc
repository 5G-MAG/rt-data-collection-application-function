/**********************************************************************************************************************************
 * EndpointAddress - C interface to the EndpointAddress object
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

/*#include "EndpointAddress.h" already included by data-collection-sp/data-collection.h */
#include "EndpointAddress-internal.h"
#include "openapi/model/EndpointAddress.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_create(

)
{
    return reinterpret_cast<data_collection_model_endpoint_address_t*>(new std::shared_ptr<EndpointAddress>(new EndpointAddress(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_create_copy(const data_collection_model_endpoint_address_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<const std::shared_ptr<EndpointAddress >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_endpoint_address_t*>(new std::shared_ptr<EndpointAddress >(new EndpointAddress(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_create_move(data_collection_model_endpoint_address_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<EndpointAddress > *obj = reinterpret_cast<std::shared_ptr<EndpointAddress >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_copy(data_collection_model_endpoint_address_t *endpoint_address, const data_collection_model_endpoint_address_t *other)
{
    if (endpoint_address) {
        std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<std::shared_ptr<EndpointAddress >*>(endpoint_address);
        if (obj) {
            if (other) {
                const std::shared_ptr<EndpointAddress > &other_obj = *reinterpret_cast<const std::shared_ptr<EndpointAddress >*>(other);
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
                const std::shared_ptr<EndpointAddress > &other_obj = *reinterpret_cast<const std::shared_ptr<EndpointAddress >*>(other);
                if (other_obj) {
                    obj.reset(new EndpointAddress(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        endpoint_address = data_collection_model_endpoint_address_create_copy(other);
    }
    return endpoint_address;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_move(data_collection_model_endpoint_address_t *endpoint_address, data_collection_model_endpoint_address_t *other)
{
    std::shared_ptr<EndpointAddress > *other_ptr = reinterpret_cast<std::shared_ptr<EndpointAddress >*>(other);

    if (endpoint_address) {
        std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<std::shared_ptr<EndpointAddress >*>(endpoint_address);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                endpoint_address = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return endpoint_address;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_endpoint_address_free(data_collection_model_endpoint_address_t *endpoint_address)
{
    if (!endpoint_address) return;
    delete reinterpret_cast<std::shared_ptr<EndpointAddress >*>(endpoint_address);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_endpoint_address_toJSON(const data_collection_model_endpoint_address_t *endpoint_address, bool as_request)
{
    if (!endpoint_address) return NULL;
    const std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<const std::shared_ptr<EndpointAddress >*>(endpoint_address);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_endpoint_address_t*>(new std::shared_ptr<EndpointAddress >(new EndpointAddress(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_endpoint_address_is_equal_to(const data_collection_model_endpoint_address_t *first, const data_collection_model_endpoint_address_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<EndpointAddress > &obj2 = *reinterpret_cast<const std::shared_ptr<EndpointAddress >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<EndpointAddress > &obj1 = *reinterpret_cast<const std::shared_ptr<EndpointAddress >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_endpoint_address_get_domain_name(const data_collection_model_endpoint_address_t *obj_endpoint_address)
{
    if (!obj_endpoint_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<const std::shared_ptr<EndpointAddress >*>(obj_endpoint_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename EndpointAddress::DomainNameType ResultFromType;
    const ResultFromType result_from = obj->getDomainName();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_domain_name(data_collection_model_endpoint_address_t *obj_endpoint_address, const char* p_domain_name)
{
    if (!obj_endpoint_address) return NULL;

    std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<std::shared_ptr<EndpointAddress >*>(obj_endpoint_address);
    if (!obj) return NULL;

    const auto &value_from = p_domain_name;
    typedef typename EndpointAddress::DomainNameType ValueType;

    ValueType value(value_from);
    if (!obj->setDomainName(value)) return NULL;

    return obj_endpoint_address;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_domain_name_move(data_collection_model_endpoint_address_t *obj_endpoint_address, char* p_domain_name)
{
    if (!obj_endpoint_address) return NULL;

    std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<std::shared_ptr<EndpointAddress >*>(obj_endpoint_address);
    if (!obj) return NULL;

    const auto &value_from = p_domain_name;
    typedef typename EndpointAddress::DomainNameType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDomainName(std::move(value))) return NULL;

    return obj_endpoint_address;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_endpoint_address_get_port_numbers(const data_collection_model_endpoint_address_t *obj_endpoint_address)
{
    if (!obj_endpoint_address) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<const std::shared_ptr<EndpointAddress >*>(obj_endpoint_address);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename EndpointAddress::PortNumbersType ResultFromType;
    const ResultFromType result_from = obj->getPortNumbers();
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_port_numbers(data_collection_model_endpoint_address_t *obj_endpoint_address, const ogs_list_t* p_port_numbers)
{
    if (!obj_endpoint_address) return NULL;

    std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<std::shared_ptr<EndpointAddress >*>(obj_endpoint_address);
    if (!obj) return NULL;

    const auto &value_from = p_port_numbers;
    typedef typename EndpointAddress::PortNumbersType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    if (!obj->setPortNumbers(value)) return NULL;

    return obj_endpoint_address;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_set_port_numbers_move(data_collection_model_endpoint_address_t *obj_endpoint_address, ogs_list_t* p_port_numbers)
{
    if (!obj_endpoint_address) return NULL;

    std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<std::shared_ptr<EndpointAddress >*>(obj_endpoint_address);
    if (!obj) return NULL;

    const auto &value_from = p_port_numbers;
    typedef typename EndpointAddress::PortNumbersType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(*reinterpret_cast<const ItemType*>(lnode->object));
    	
        }
    }
    data_collection_list_free(p_port_numbers);
    if (!obj->setPortNumbers(std::move(value))) return NULL;

    return obj_endpoint_address;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_add_port_numbers(data_collection_model_endpoint_address_t *obj_endpoint_address, int32_t p_port_numbers)
{
    if (!obj_endpoint_address) return NULL;

    std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<std::shared_ptr<EndpointAddress >*>(obj_endpoint_address);
    if (!obj) return NULL;

    typedef typename EndpointAddress::PortNumbersType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_port_numbers;

    ValueType value = value_from;

    obj->addPortNumbers(value);
    return obj_endpoint_address;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_remove_port_numbers(data_collection_model_endpoint_address_t *obj_endpoint_address, const int32_t p_port_numbers)
{
    if (!obj_endpoint_address) return NULL;

    std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<std::shared_ptr<EndpointAddress >*>(obj_endpoint_address);
    if (!obj) return NULL;

    typedef typename EndpointAddress::PortNumbersType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_port_numbers;
    ValueType value = value_from;
    obj->removePortNumbers(value);
    return obj_endpoint_address;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_endpoint_address_t *data_collection_model_endpoint_address_clear_port_numbers(data_collection_model_endpoint_address_t *obj_endpoint_address)
{
    if (!obj_endpoint_address) return NULL;

    std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<std::shared_ptr<EndpointAddress >*>(obj_endpoint_address);
    if (!obj) return NULL;

    obj->clearPortNumbers();
    return obj_endpoint_address;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_endpoint_address_make_lnode(data_collection_model_endpoint_address_t *p_endpoint_address)
{
    return data_collection_lnode_create(p_endpoint_address, reinterpret_cast<void(*)(void*)>(data_collection_model_endpoint_address_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_endpoint_address_refcount(data_collection_model_endpoint_address_t *obj_endpoint_address)
{
    if (!obj_endpoint_address) return 0l;
    std::shared_ptr<EndpointAddress > &obj = *reinterpret_cast<std::shared_ptr<EndpointAddress >*>(obj_endpoint_address);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

