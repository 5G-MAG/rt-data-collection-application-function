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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_create(


)
{
    return reinterpret_cast<data_collection_model_ip_addr_t*>(new std::shared_ptr<IpAddr>(new IpAddr(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_create_copy(const data_collection_model_ip_addr_t *other)
{
    return reinterpret_cast<data_collection_model_ip_addr_t*>(new std::shared_ptr<IpAddr >(new IpAddr(**reinterpret_cast<const std::shared_ptr<IpAddr >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_create_move(data_collection_model_ip_addr_t *other)
{
    return reinterpret_cast<data_collection_model_ip_addr_t*>(new std::shared_ptr<IpAddr >(std::move(*reinterpret_cast<std::shared_ptr<IpAddr >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_copy(data_collection_model_ip_addr_t *ip_addr, const data_collection_model_ip_addr_t *other)
{
    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(ip_addr);
    *obj = **reinterpret_cast<const std::shared_ptr<IpAddr >*>(other);
    return ip_addr;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_move(data_collection_model_ip_addr_t *ip_addr, data_collection_model_ip_addr_t *other)
{
    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(ip_addr);
    obj = std::move(*reinterpret_cast<std::shared_ptr<IpAddr >*>(other));
    return ip_addr;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ip_addr_free(data_collection_model_ip_addr_t *ip_addr)
{
    delete reinterpret_cast<std::shared_ptr<IpAddr >*>(ip_addr);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ip_addr_toJSON(const data_collection_model_ip_addr_t *ip_addr, bool as_request)
{
    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(ip_addr);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_ip_addr_get_ipv4_addr(const data_collection_model_ip_addr_t *obj_ip_addr)
{
    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(obj_ip_addr);
    typedef typename IpAddr::Ipv4AddrType ResultFromType;
    const ResultFromType result_from = obj->getIpv4Addr();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv4_addr(data_collection_model_ip_addr_t *obj_ip_addr, const char* p_ipv4_addr)
{
    if (obj_ip_addr == NULL) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    const auto &value_from = p_ipv4_addr;
    typedef typename IpAddr::Ipv4AddrType ValueType;

    ValueType value(value_from);
    if (!obj->setIpv4Addr(value)) return NULL;
    return obj_ip_addr;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv4_addr_move(data_collection_model_ip_addr_t *obj_ip_addr, char* p_ipv4_addr)
{
    if (obj_ip_addr == NULL) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    const auto &value_from = p_ipv4_addr;
    typedef typename IpAddr::Ipv4AddrType ValueType;

    ValueType value(value_from);
    
    if (!obj->setIpv4Addr(std::move(value))) return NULL;
    return obj_ip_addr;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ipv6_addr_t* data_collection_model_ip_addr_get_ipv6_addr(const data_collection_model_ip_addr_t *obj_ip_addr)
{
    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(obj_ip_addr);
    typedef typename IpAddr::Ipv6AddrType ResultFromType;
    const ResultFromType result_from = obj->getIpv6Addr();
    const data_collection_model_ipv6_addr_t *result = reinterpret_cast<const data_collection_model_ipv6_addr_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_addr(data_collection_model_ip_addr_t *obj_ip_addr, const data_collection_model_ipv6_addr_t* p_ipv6_addr)
{
    if (obj_ip_addr == NULL) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    const auto &value_from = p_ipv6_addr;
    typedef typename IpAddr::Ipv6AddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setIpv6Addr(value)) return NULL;
    return obj_ip_addr;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_addr_move(data_collection_model_ip_addr_t *obj_ip_addr, data_collection_model_ipv6_addr_t* p_ipv6_addr)
{
    if (obj_ip_addr == NULL) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    const auto &value_from = p_ipv6_addr;
    typedef typename IpAddr::Ipv6AddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setIpv6Addr(std::move(value))) return NULL;
    return obj_ip_addr;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ipv6_prefix_t* data_collection_model_ip_addr_get_ipv6_prefix(const data_collection_model_ip_addr_t *obj_ip_addr)
{
    const std::shared_ptr<IpAddr > &obj = *reinterpret_cast<const std::shared_ptr<IpAddr >*>(obj_ip_addr);
    typedef typename IpAddr::Ipv6PrefixType ResultFromType;
    const ResultFromType result_from = obj->getIpv6Prefix();
    const data_collection_model_ipv6_prefix_t *result = reinterpret_cast<const data_collection_model_ipv6_prefix_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_prefix(data_collection_model_ip_addr_t *obj_ip_addr, const data_collection_model_ipv6_prefix_t* p_ipv6_prefix)
{
    if (obj_ip_addr == NULL) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    const auto &value_from = p_ipv6_prefix;
    typedef typename IpAddr::Ipv6PrefixType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setIpv6Prefix(value)) return NULL;
    return obj_ip_addr;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ip_addr_t *data_collection_model_ip_addr_set_ipv6_prefix_move(data_collection_model_ip_addr_t *obj_ip_addr, data_collection_model_ipv6_prefix_t* p_ipv6_prefix)
{
    if (obj_ip_addr == NULL) return NULL;

    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    const auto &value_from = p_ipv6_prefix;
    typedef typename IpAddr::Ipv6PrefixType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setIpv6Prefix(std::move(value))) return NULL;
    return obj_ip_addr;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ip_addr_make_lnode(data_collection_model_ip_addr_t *p_ip_addr)
{
    return data_collection_lnode_create(p_ip_addr, reinterpret_cast<void(*)(void*)>(data_collection_model_ip_addr_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ip_addr_refcount(data_collection_model_ip_addr_t *obj_ip_addr)
{
    std::shared_ptr<IpAddr > &obj = *reinterpret_cast<std::shared_ptr<IpAddr >*>(obj_ip_addr);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

