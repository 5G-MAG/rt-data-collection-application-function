/**********************************************************************************************************************************
 * IpAddr - C interface to the IpAddr object
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

/*#include "IpAddr.h" already included by data-collection-sp/data-collection.h */
#include "IpAddr-internal.h"
#include "openapi/model/IpAddr.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_create(


)
{
    return reinterpret_cast<data_collection_model_ip_addr_t*>(new std::shared_ptr<IpAddr>(new IpAddr(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_create_copy(const data_collection_model_ip_addr_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_ip_addr_t*>(new std::shared_ptr<IpAddr >(new IpAddr(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_create_move(data_collection_model_ip_addr_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<IpAddr > *obj = reinterpret_cast<std::shared_ptr<IpAddr >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_copy(data_collection_model_ip_addr_t *ip_addr, const data_collection_model_ip_addr_t *other)
{
    if (ip_addr) {
        std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(ip_addr);
        if (obj) {
            if (other) {
                const std::shared_ptr<IpAddr > &other_obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(other);
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
                const std::shared_ptr<IpAddr > &other_obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(other);
                if (other_obj) {
                    obj.reset(new IpAddr(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        ip_addr = data_collection_model_ip_addr_create_copy(other);
    }
    return ip_addr;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_move(data_collection_model_ip_addr_t *ip_addr, data_collection_model_ip_addr_t *other)
{
    std::shared_ptr<IpAddr > *other_ptr = reinterpret_cast<std::shared_ptr<IpAddr >*>(other);

    if (ip_addr) {
        std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(ip_addr);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                ip_addr = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return ip_addr;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ip_addr_free(data_collection_model_ip_addr_t *ip_addr)
{
    if (!ip_addr) return;
    delete reinterpret_cast<std::shared_ptr<IpAddr >*>(ip_addr);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ip_addr_toJSON(const data_collection_model_ip_addr_t *ip_addr, bool as_request)
{
    if (!ip_addr) return NULL;
    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(ip_addr);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ip_addr_t*>(new std::shared_ptr<IpAddr >(new IpAddr(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_addr_is_equal_to(const data_collection_model_ip_addr_t *first, const data_collection_model_ip_addr_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<IpAddr > &obj2 = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<IpAddr > &obj1 = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_addr_has_ipv4_addr(const data_collection_model_ip_addr_t *obj_ip_addr)
{
    if (!obj_ip_addr) return false;

    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) return false;

    return obj->getIpv4Addr().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ip_addr_get_ipv4_addr(const data_collection_model_ip_addr_t *obj_ip_addr)
{
    if (!obj_ip_addr) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename IpAddr::Ipv4AddrType ResultFromType;
    const ResultFromType result_from = obj->getIpv4Addr();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv4_addr(data_collection_model_ip_addr_t *obj_ip_addr, const char* p_ipv4_addr)
{
    if (!obj_ip_addr) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) return NULL;

    const auto &value_from = p_ipv4_addr;
    typedef typename IpAddr::Ipv4AddrType ValueType;

    ValueType value(value_from);

    if (!obj->setIpv4Addr(value)) return NULL;

    return obj_ip_addr;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv4_addr_move(data_collection_model_ip_addr_t *obj_ip_addr, char* p_ipv4_addr)
{
    if (!obj_ip_addr) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) return NULL;

    const auto &value_from = p_ipv4_addr;
    typedef typename IpAddr::Ipv4AddrType ValueType;

    ValueType value(value_from);

    
    if (!obj->setIpv4Addr(std::move(value))) return NULL;

    return obj_ip_addr;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_addr_has_ipv6_addr(const data_collection_model_ip_addr_t *obj_ip_addr)
{
    if (!obj_ip_addr) return false;

    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) return false;

    return obj->getIpv6Addr().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ipv6_addr_t* data_collection_model_ip_addr_get_ipv6_addr(const data_collection_model_ip_addr_t *obj_ip_addr)
{
    if (!obj_ip_addr) {
        const data_collection_model_ipv6_addr_t *result = NULL;
        return result;
    }

    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) {
        const data_collection_model_ipv6_addr_t *result = NULL;
        return result;
    }

    typedef typename IpAddr::Ipv6AddrType ResultFromType;
    const ResultFromType result_from = obj->getIpv6Addr();
    const data_collection_model_ipv6_addr_t *result = reinterpret_cast<const data_collection_model_ipv6_addr_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_addr(data_collection_model_ip_addr_t *obj_ip_addr, const data_collection_model_ipv6_addr_t* p_ipv6_addr)
{
    if (!obj_ip_addr) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) return NULL;

    const auto &value_from = p_ipv6_addr;
    typedef typename IpAddr::Ipv6AddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setIpv6Addr(value)) return NULL;

    return obj_ip_addr;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_addr_move(data_collection_model_ip_addr_t *obj_ip_addr, data_collection_model_ipv6_addr_t* p_ipv6_addr)
{
    if (!obj_ip_addr) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) return NULL;

    const auto &value_from = p_ipv6_addr;
    typedef typename IpAddr::Ipv6AddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setIpv6Addr(std::move(value))) return NULL;

    return obj_ip_addr;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ip_addr_has_ipv6_prefix(const data_collection_model_ip_addr_t *obj_ip_addr)
{
    if (!obj_ip_addr) return false;

    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) return false;

    return obj->getIpv6Prefix().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ipv6_prefix_t* data_collection_model_ip_addr_get_ipv6_prefix(const data_collection_model_ip_addr_t *obj_ip_addr)
{
    if (!obj_ip_addr) {
        const data_collection_model_ipv6_prefix_t *result = NULL;
        return result;
    }

    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) {
        const data_collection_model_ipv6_prefix_t *result = NULL;
        return result;
    }

    typedef typename IpAddr::Ipv6PrefixType ResultFromType;
    const ResultFromType result_from = obj->getIpv6Prefix();
    const data_collection_model_ipv6_prefix_t *result = reinterpret_cast<const data_collection_model_ipv6_prefix_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_prefix(data_collection_model_ip_addr_t *obj_ip_addr, const data_collection_model_ipv6_prefix_t* p_ipv6_prefix)
{
    if (!obj_ip_addr) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) return NULL;

    const auto &value_from = p_ipv6_prefix;
    typedef typename IpAddr::Ipv6PrefixType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setIpv6Prefix(value)) return NULL;

    return obj_ip_addr;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_prefix_move(data_collection_model_ip_addr_t *obj_ip_addr, data_collection_model_ipv6_prefix_t* p_ipv6_prefix)
{
    if (!obj_ip_addr) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    if (!obj) return NULL;

    const auto &value_from = p_ipv6_prefix;
    typedef typename IpAddr::Ipv6PrefixType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setIpv6Prefix(std::move(value))) return NULL;

    return obj_ip_addr;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ip_addr_make_lnode(data_collection_model_ip_addr_t *p_ip_addr)
{
    return data_collection_lnode_create(p_ip_addr, reinterpret_cast<void(*)(void*)>(data_collection_model_ip_addr_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ip_addr_refcount(data_collection_model_ip_addr_t *obj_ip_addr)
{
    if (!obj_ip_addr) return 0l;
    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

