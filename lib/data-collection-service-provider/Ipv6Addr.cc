/**********************************************************************************************************************************
 * Ipv6Addr - C interface to the Ipv6Addr object
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

/*#include "Ipv6Addr.h" already included by data-collection-sp/data-collection.h */
#include "Ipv6Addr-internal.h"
#include "openapi/model/Ipv6Addr.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_create()
{
    return reinterpret_cast<data_collection_model_ipv6_addr_t*>(new std::shared_ptr<Ipv6Addr>(new Ipv6Addr()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_create_copy(const data_collection_model_ipv6_addr_t *other)
{
    return reinterpret_cast<data_collection_model_ipv6_addr_t*>(new std::shared_ptr<Ipv6Addr >(new Ipv6Addr(**reinterpret_cast<const std::shared_ptr<Ipv6Addr >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_create_move(data_collection_model_ipv6_addr_t *other)
{
    return reinterpret_cast<data_collection_model_ipv6_addr_t*>(new std::shared_ptr<Ipv6Addr >(std::move(*reinterpret_cast<std::shared_ptr<Ipv6Addr >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_copy(data_collection_model_ipv6_addr_t *ipv6_addr, const data_collection_model_ipv6_addr_t *other)
{
    std::shared_ptr<Ipv6Addr > &obj = *reinterpret_cast<std::shared_ptr<Ipv6Addr >*>(ipv6_addr);
    *obj = **reinterpret_cast<const std::shared_ptr<Ipv6Addr >*>(other);
    return ipv6_addr;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_move(data_collection_model_ipv6_addr_t *ipv6_addr, data_collection_model_ipv6_addr_t *other)
{
    std::shared_ptr<Ipv6Addr > &obj = *reinterpret_cast<std::shared_ptr<Ipv6Addr >*>(ipv6_addr);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Ipv6Addr >*>(other));
    return ipv6_addr;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ipv6_addr_free(data_collection_model_ipv6_addr_t *ipv6_addr)
{
    delete reinterpret_cast<std::shared_ptr<Ipv6Addr >*>(ipv6_addr);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ipv6_addr_toJSON(const data_collection_model_ipv6_addr_t *ipv6_addr, bool as_request)
{
    const std::shared_ptr<Ipv6Addr > &obj = *reinterpret_cast<const std::shared_ptr<Ipv6Addr >*>(ipv6_addr);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_addr_t *data_collection_model_ipv6_addr_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ipv6_addr_t*>(new std::shared_ptr<Ipv6Addr >(new Ipv6Addr(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_ipv6_addr_is_equal_to(const data_collection_model_ipv6_addr_t *first, const data_collection_model_ipv6_addr_t *second)
{
    const std::shared_ptr<Ipv6Addr > &obj1 = *reinterpret_cast<const std::shared_ptr<Ipv6Addr >*>(first);
    const std::shared_ptr<Ipv6Addr > &obj2 = *reinterpret_cast<const std::shared_ptr<Ipv6Addr >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ipv6_addr_make_lnode(data_collection_model_ipv6_addr_t *p_ipv6_addr)
{
    return data_collection_lnode_create(p_ipv6_addr, reinterpret_cast<void(*)(void*)>(data_collection_model_ipv6_addr_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ipv6_addr_refcount(data_collection_model_ipv6_addr_t *obj_ipv6_addr)
{
    std::shared_ptr<Ipv6Addr > &obj = *reinterpret_cast<std::shared_ptr<Ipv6Addr >*>(obj_ipv6_addr);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

