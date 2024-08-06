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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create()
{
    return reinterpret_cast<data_collection_model_ipv6_prefix_t*>(new std::shared_ptr<Ipv6Prefix>(new Ipv6Prefix()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create_copy(const data_collection_model_ipv6_prefix_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<Ipv6Prefix > &obj = *reinterpret_cast<const std::shared_ptr<Ipv6Prefix >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_ipv6_prefix_t*>(new std::shared_ptr<Ipv6Prefix >(new Ipv6Prefix(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_create_move(data_collection_model_ipv6_prefix_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<Ipv6Prefix > *obj = reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_copy(data_collection_model_ipv6_prefix_t *ipv6_prefix, const data_collection_model_ipv6_prefix_t *other)
{
    if (ipv6_prefix) {
        std::shared_ptr<Ipv6Prefix > &obj = *reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(ipv6_prefix);
        if (obj) {
            if (other) {
                const std::shared_ptr<Ipv6Prefix > &other_obj = *reinterpret_cast<const std::shared_ptr<Ipv6Prefix >*>(other);
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
                const std::shared_ptr<Ipv6Prefix > &other_obj = *reinterpret_cast<const std::shared_ptr<Ipv6Prefix >*>(other);
                if (other_obj) {
                    obj.reset(new Ipv6Prefix(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        ipv6_prefix = data_collection_model_ipv6_prefix_create_copy(other);
    }
    return ipv6_prefix;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_move(data_collection_model_ipv6_prefix_t *ipv6_prefix, data_collection_model_ipv6_prefix_t *other)
{
    std::shared_ptr<Ipv6Prefix > *other_ptr = reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(other);

    if (ipv6_prefix) {
        std::shared_ptr<Ipv6Prefix > &obj = *reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(ipv6_prefix);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                ipv6_prefix = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return ipv6_prefix;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ipv6_prefix_free(data_collection_model_ipv6_prefix_t *ipv6_prefix)
{
    if (!ipv6_prefix) return;
    delete reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(ipv6_prefix);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ipv6_prefix_toJSON(const data_collection_model_ipv6_prefix_t *ipv6_prefix, bool as_request)
{
    if (!ipv6_prefix) return NULL;
    const std::shared_ptr<Ipv6Prefix > &obj = *reinterpret_cast<const std::shared_ptr<Ipv6Prefix >*>(ipv6_prefix);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ipv6_prefix_t *data_collection_model_ipv6_prefix_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ipv6_prefix_is_equal_to(const data_collection_model_ipv6_prefix_t *first, const data_collection_model_ipv6_prefix_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<Ipv6Prefix > &obj2 = *reinterpret_cast<const std::shared_ptr<Ipv6Prefix >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<Ipv6Prefix > &obj1 = *reinterpret_cast<const std::shared_ptr<Ipv6Prefix >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ipv6_prefix_make_lnode(data_collection_model_ipv6_prefix_t *p_ipv6_prefix)
{
    return data_collection_lnode_create(p_ipv6_prefix, reinterpret_cast<void(*)(void*)>(data_collection_model_ipv6_prefix_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ipv6_prefix_refcount(data_collection_model_ipv6_prefix_t *obj_ipv6_prefix)
{
    if (!obj_ipv6_prefix) return 0l;
    std::shared_ptr<Ipv6Prefix > &obj = *reinterpret_cast<std::shared_ptr<Ipv6Prefix >*>(obj_ipv6_prefix);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

