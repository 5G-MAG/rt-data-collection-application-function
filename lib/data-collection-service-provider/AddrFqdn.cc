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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create(

)
{
    return reinterpret_cast<data_collection_model_addr_fqdn_t*>(new std::shared_ptr<AddrFqdn>(new AddrFqdn(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create_copy(const data_collection_model_addr_fqdn_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_addr_fqdn_t*>(new std::shared_ptr<AddrFqdn >(new AddrFqdn(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_create_move(data_collection_model_addr_fqdn_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<AddrFqdn > *obj = reinterpret_cast<std::shared_ptr<AddrFqdn >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_copy(data_collection_model_addr_fqdn_t *addr_fqdn, const data_collection_model_addr_fqdn_t *other)
{
    if (addr_fqdn) {
        std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(addr_fqdn);
        if (obj) {
            if (other) {
                const std::shared_ptr<AddrFqdn > &other_obj = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(other);
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
                const std::shared_ptr<AddrFqdn > &other_obj = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(other);
                if (other_obj) {
                    obj.reset(new AddrFqdn(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        addr_fqdn = data_collection_model_addr_fqdn_create_copy(other);
    }
    return addr_fqdn;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_move(data_collection_model_addr_fqdn_t *addr_fqdn, data_collection_model_addr_fqdn_t *other)
{
    std::shared_ptr<AddrFqdn > *other_ptr = reinterpret_cast<std::shared_ptr<AddrFqdn >*>(other);

    if (addr_fqdn) {
        std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(addr_fqdn);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                addr_fqdn = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return addr_fqdn;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_addr_fqdn_free(data_collection_model_addr_fqdn_t *addr_fqdn)
{
    if (!addr_fqdn) return;
    delete reinterpret_cast<std::shared_ptr<AddrFqdn >*>(addr_fqdn);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_addr_fqdn_toJSON(const data_collection_model_addr_fqdn_t *addr_fqdn, bool as_request)
{
    if (!addr_fqdn) return NULL;
    const std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(addr_fqdn);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_addr_fqdn_is_equal_to(const data_collection_model_addr_fqdn_t *first, const data_collection_model_addr_fqdn_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<AddrFqdn > &obj2 = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<AddrFqdn > &obj1 = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_addr_fqdn_get_ip_addr(const data_collection_model_addr_fqdn_t *obj_addr_fqdn)
{
    if (!obj_addr_fqdn) {
        const data_collection_model_ip_addr_t *result = NULL;
        return result;
    }

    const std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    if (!obj) {
        const data_collection_model_ip_addr_t *result = NULL;
        return result;
    }

    typedef typename AddrFqdn::IpAddrType ResultFromType;
    const ResultFromType result_from = obj->getIpAddr();
    const data_collection_model_ip_addr_t *result = reinterpret_cast<const data_collection_model_ip_addr_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_ip_addr(data_collection_model_addr_fqdn_t *obj_addr_fqdn, const data_collection_model_ip_addr_t* p_ip_addr)
{
    if (!obj_addr_fqdn) return NULL;

    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    if (!obj) return NULL;

    const auto &value_from = p_ip_addr;
    typedef typename AddrFqdn::IpAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setIpAddr(value)) return NULL;

    return obj_addr_fqdn;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_ip_addr_move(data_collection_model_addr_fqdn_t *obj_addr_fqdn, data_collection_model_ip_addr_t* p_ip_addr)
{
    if (!obj_addr_fqdn) return NULL;

    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    if (!obj) return NULL;

    const auto &value_from = p_ip_addr;
    typedef typename AddrFqdn::IpAddrType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setIpAddr(std::move(value))) return NULL;

    return obj_addr_fqdn;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_addr_fqdn_get_fqdn(const data_collection_model_addr_fqdn_t *obj_addr_fqdn)
{
    if (!obj_addr_fqdn) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<const std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename AddrFqdn::FqdnType ResultFromType;
    const ResultFromType result_from = obj->getFqdn();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_fqdn(data_collection_model_addr_fqdn_t *obj_addr_fqdn, const char* p_fqdn)
{
    if (!obj_addr_fqdn) return NULL;

    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    if (!obj) return NULL;

    const auto &value_from = p_fqdn;
    typedef typename AddrFqdn::FqdnType ValueType;

    ValueType value(value_from);
    if (!obj->setFqdn(value)) return NULL;

    return obj_addr_fqdn;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_addr_fqdn_t *data_collection_model_addr_fqdn_set_fqdn_move(data_collection_model_addr_fqdn_t *obj_addr_fqdn, char* p_fqdn)
{
    if (!obj_addr_fqdn) return NULL;

    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    if (!obj) return NULL;

    const auto &value_from = p_fqdn;
    typedef typename AddrFqdn::FqdnType ValueType;

    ValueType value(value_from);
    
    if (!obj->setFqdn(std::move(value))) return NULL;

    return obj_addr_fqdn;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_addr_fqdn_make_lnode(data_collection_model_addr_fqdn_t *p_addr_fqdn)
{
    return data_collection_lnode_create(p_addr_fqdn, reinterpret_cast<void(*)(void*)>(data_collection_model_addr_fqdn_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_addr_fqdn_refcount(data_collection_model_addr_fqdn_t *obj_addr_fqdn)
{
    if (!obj_addr_fqdn) return 0l;
    std::shared_ptr<AddrFqdn > &obj = *reinterpret_cast<std::shared_ptr<AddrFqdn >*>(obj_addr_fqdn);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

