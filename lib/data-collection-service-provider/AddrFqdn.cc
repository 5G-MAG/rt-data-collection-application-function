/**********************************************************************************************************************************
 * AddrFqdn - C interface to the AddrFqdn object
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

/*#include "AddrFqdn.h" already included by data-collection-sp/data-collection.h */
#include "AddrFqdn-internal.h"
#include "openapi/model/AddrFqdn.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create(

)
{
    return reinterpret_cast<data_collection_model_addr_fqdn_t*>(new std::shared_ptr<AddrFqdn>(new AddrFqdn(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create_copy(const data_collection_model_addr_fqdn_t *other)
{
    return reinterpret_cast<data_collection_model_addr_fqdn_t*>(new std::shared_ptr<AddrFqdn >(new AddrFqdn(**reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create_move(data_collection_model_addr_fqdn_t *other)
{
    return reinterpret_cast<data_collection_model_addr_fqdn_t*>(new std::shared_ptr<AddrFqdn >(std::move(*reinterpret_cast<std::shared_ptr<AddrFqdn >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_copy(data_collection_model_addr_fqdn_t *addr_fqdn, const data_collection_model_addr_fqdn_t *other)
{
    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(addr_fqdn);
    *obj = **reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(other);
    return addr_fqdn;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_move(data_collection_model_addr_fqdn_t *addr_fqdn, data_collection_model_addr_fqdn_t *other)
{
    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(addr_fqdn);
    obj = std::move(*reinterpret_cast<std::shared_ptr<AddrFqdn >*>(other));
    return addr_fqdn;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_addr_fqdn_free(data_collection_model_addr_fqdn_t *addr_fqdn)
{
    delete reinterpret_cast<std::shared_ptr<AddrFqdn >*>(addr_fqdn);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_addr_fqdn_toJSON(const data_collection_model_addr_fqdn_t *addr_fqdn, bool as_request)
{
    const std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(addr_fqdn);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_addr_fqdn_t*>(new std::shared_ptr<AddrFqdn >(new AddrFqdn(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_addr_fqdn_is_equal_to(const data_collection_model_addr_fqdn_t *first, const data_collection_model_addr_fqdn_t *second)
{
    const std::shared_ptr<AddrFqdn > &obj1 = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(first);
    const std::shared_ptr<AddrFqdn > &obj2 = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ip_addr_t* data_collection_model_addr_fqdn_get_ip_addr(const data_collection_model_addr_fqdn_t *obj_addr_fqdn)
{
    const std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    typedef typename AddrFqdn::IpAddrType ResultFromType;
    const ResultFromType result_from = obj->getIpAddr();
    const data_collection_model_ip_addr_t *result = reinterpret_cast<const data_collection_model_ip_addr_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_ip_addr(data_collection_model_addr_fqdn_t *obj_addr_fqdn, const data_collection_model_ip_addr_t* p_ip_addr)
{
    if (obj_addr_fqdn == NULL) return NULL;

    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    const auto &value_from = p_ip_addr;
    typedef typename AddrFqdn::IpAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setIpAddr(value)) return NULL;
    return obj_addr_fqdn;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_ip_addr_move(data_collection_model_addr_fqdn_t *obj_addr_fqdn, data_collection_model_ip_addr_t* p_ip_addr)
{
    if (obj_addr_fqdn == NULL) return NULL;

    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    const auto &value_from = p_ip_addr;
    typedef typename AddrFqdn::IpAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setIpAddr(std::move(value))) return NULL;
    return obj_addr_fqdn;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_addr_fqdn_get_fqdn(const data_collection_model_addr_fqdn_t *obj_addr_fqdn)
{
    const std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    typedef typename AddrFqdn::FqdnType ResultFromType;
    const ResultFromType result_from = obj->getFqdn();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_fqdn(data_collection_model_addr_fqdn_t *obj_addr_fqdn, const char* p_fqdn)
{
    if (obj_addr_fqdn == NULL) return NULL;

    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    const auto &value_from = p_fqdn;
    typedef typename AddrFqdn::FqdnType ValueType;

    ValueType value(value_from);
    if (!obj->setFqdn(value)) return NULL;
    return obj_addr_fqdn;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_fqdn_move(data_collection_model_addr_fqdn_t *obj_addr_fqdn, char* p_fqdn)
{
    if (obj_addr_fqdn == NULL) return NULL;

    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    const auto &value_from = p_fqdn;
    typedef typename AddrFqdn::FqdnType ValueType;

    ValueType value(value_from);
    
    if (!obj->setFqdn(std::move(value))) return NULL;
    return obj_addr_fqdn;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_addr_fqdn_make_lnode(data_collection_model_addr_fqdn_t *p_addr_fqdn)
{
    return data_collection_lnode_create(p_addr_fqdn, reinterpret_cast<void(*)(void*)>(data_collection_model_addr_fqdn_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_addr_fqdn_refcount(data_collection_model_addr_fqdn_t *obj_addr_fqdn)
{
    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

