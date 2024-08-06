/**********************************************************************************************************************************
 * NetworkAssistanceInvocationEvent_allOf - C interface to the NetworkAssistanceInvocationEvent_allOf object
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

/*#include "NetworkAssistanceInvocationEvent_allOf.h" already included by data-collection-sp/data-collection.h */
#include "NetworkAssistanceInvocationEvent_allOf-internal.h"
#include "openapi/model/NetworkAssistanceInvocationEvent_allOf.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_create(
)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_event_all_of_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent_allOf>(new NetworkAssistanceInvocationEvent_allOf(
)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_create_copy(const data_collection_model_network_assistance_invocation_event_all_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_network_assistance_invocation_event_all_of_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >(new NetworkAssistanceInvocationEvent_allOf(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_create_move(data_collection_model_network_assistance_invocation_event_all_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > *obj = reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_copy(data_collection_model_network_assistance_invocation_event_all_of_t *network_assistance_invocation_event_all_of, const data_collection_model_network_assistance_invocation_event_all_of_t *other)
{
    if (network_assistance_invocation_event_all_of) {
        std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(network_assistance_invocation_event_all_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(other);
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
                const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(other);
                if (other_obj) {
                    obj.reset(new NetworkAssistanceInvocationEvent_allOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        network_assistance_invocation_event_all_of = data_collection_model_network_assistance_invocation_event_all_of_create_copy(other);
    }
    return network_assistance_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_move(data_collection_model_network_assistance_invocation_event_all_of_t *network_assistance_invocation_event_all_of, data_collection_model_network_assistance_invocation_event_all_of_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > *other_ptr = reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(other);

    if (network_assistance_invocation_event_all_of) {
        std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(network_assistance_invocation_event_all_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                network_assistance_invocation_event_all_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return network_assistance_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_invocation_event_all_of_free(data_collection_model_network_assistance_invocation_event_all_of_t *network_assistance_invocation_event_all_of)
{
    if (!network_assistance_invocation_event_all_of) return;
    delete reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(network_assistance_invocation_event_all_of);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_invocation_event_all_of_toJSON(const data_collection_model_network_assistance_invocation_event_all_of_t *network_assistance_invocation_event_all_of, bool as_request)
{
    if (!network_assistance_invocation_event_all_of) return NULL;
    const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(network_assistance_invocation_event_all_of);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_network_assistance_invocation_event_all_of_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >(new NetworkAssistanceInvocationEvent_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_event_all_of_is_equal_to(const data_collection_model_network_assistance_invocation_event_all_of_t *first, const data_collection_model_network_assistance_invocation_event_all_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_network_assistance_type_t* data_collection_model_network_assistance_invocation_event_all_of_get_network_assistance_type(const data_collection_model_network_assistance_invocation_event_all_of_t *obj_network_assistance_invocation_event_all_of)
{
    if (!obj_network_assistance_invocation_event_all_of) {
        const data_collection_model_network_assistance_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(obj_network_assistance_invocation_event_all_of);
    if (!obj) {
        const data_collection_model_network_assistance_type_t *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocationEvent_allOf::NetworkAssistanceTypeType ResultFromType;
    const ResultFromType result_from = obj->getNetworkAssistanceType();
    const data_collection_model_network_assistance_type_t *result = reinterpret_cast<const data_collection_model_network_assistance_type_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_set_network_assistance_type(data_collection_model_network_assistance_invocation_event_all_of_t *obj_network_assistance_invocation_event_all_of, const data_collection_model_network_assistance_type_t* p_network_assistance_type)
{
    if (!obj_network_assistance_invocation_event_all_of) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(obj_network_assistance_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_network_assistance_type;
    typedef typename NetworkAssistanceInvocationEvent_allOf::NetworkAssistanceTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setNetworkAssistanceType(value)) return NULL;

    return obj_network_assistance_invocation_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_set_network_assistance_type_move(data_collection_model_network_assistance_invocation_event_all_of_t *obj_network_assistance_invocation_event_all_of, data_collection_model_network_assistance_type_t* p_network_assistance_type)
{
    if (!obj_network_assistance_invocation_event_all_of) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(obj_network_assistance_invocation_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_network_assistance_type;
    typedef typename NetworkAssistanceInvocationEvent_allOf::NetworkAssistanceTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setNetworkAssistanceType(std::move(value))) return NULL;

    return obj_network_assistance_invocation_event_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_invocation_event_all_of_make_lnode(data_collection_model_network_assistance_invocation_event_all_of_t *p_network_assistance_invocation_event_all_of)
{
    return data_collection_lnode_create(p_network_assistance_invocation_event_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_network_assistance_invocation_event_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_assistance_invocation_event_all_of_refcount(data_collection_model_network_assistance_invocation_event_all_of_t *obj_network_assistance_invocation_event_all_of)
{
    if (!obj_network_assistance_invocation_event_all_of) return 0l;
    std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(obj_network_assistance_invocation_event_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

