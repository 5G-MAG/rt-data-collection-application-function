/**********************************************************************************************************************************
 * Ipv6Prefix - C interface to the Ipv6Prefix object
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

/*#include "Ipv6Prefix.h" already included by data-collection-sp/data-collection.h */
#include "Ipv6Prefix-internal.h"
#include "openapi/model/Ipv6Prefix.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create()
{
    return reinterpret_cast<data_collection_model_ipv6_prefix_t*>(new std::shared_ptr<Ipv6Prefix>(new Ipv6Prefix()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create_copy(const data_collection_model_ipv6_prefix_t *other)
{
    return reinterpret_cast<data_collection_model_ipv6_prefix_t*>(new std::shared_ptr<Ipv6Prefix >(new Ipv6Prefix(**reinterpret_cast<const std::shared_ptr<Ipv6Prefix >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create_move(data_collection_model_ipv6_prefix_t *other)
{
    return reinterpret_cast<data_collection_model_ipv6_prefix_t*>(new std::shared_ptr<Ipv6Prefix >(std::move(*reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_copy(data_collection_model_ipv6_prefix_t *ipv6_prefix, const data_collection_model_ipv6_prefix_t *other)
{
    std::shared_ptr<Ipv6Prefix > &obj = *reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(ipv6_prefix);
    *obj = **reinterpret_cast<const std::shared_ptr<Ipv6Prefix >*>(other);
    return ipv6_prefix;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_move(data_collection_model_ipv6_prefix_t *ipv6_prefix, data_collection_model_ipv6_prefix_t *other)
{
    std::shared_ptr<Ipv6Prefix > &obj = *reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(ipv6_prefix);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(other));
    return ipv6_prefix;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ipv6_prefix_free(data_collection_model_ipv6_prefix_t *ipv6_prefix)
{
    delete reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(ipv6_prefix);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ipv6_prefix_toJSON(const data_collection_model_ipv6_prefix_t *ipv6_prefix, bool as_request)
{
    const std::shared_ptr<Ipv6Prefix > &obj = *reinterpret_cast<const std::shared_ptr<Ipv6Prefix >*>(ipv6_prefix);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ipv6_prefix_t*>(new std::shared_ptr<Ipv6Prefix >(new Ipv6Prefix(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ipv6_prefix_make_lnode(data_collection_model_ipv6_prefix_t *p_ipv6_prefix)
{
    return data_collection_lnode_create(p_ipv6_prefix, reinterpret_cast<void(*)(void*)>(data_collection_model_ipv6_prefix_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ipv6_prefix_refcount(data_collection_model_ipv6_prefix_t *obj_ipv6_prefix)
{
    std::shared_ptr<Ipv6Prefix > &obj = *reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(obj_ipv6_prefix);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

