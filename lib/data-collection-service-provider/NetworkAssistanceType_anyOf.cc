/**********************************************************************************************************************************
 * NetworkAssistanceType_anyOf - C interface to the NetworkAssistanceType_anyOf object
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

/*#include "NetworkAssistanceType_anyOf.h" already included by data-collection-sp/data-collection.h */
#include "NetworkAssistanceType_anyOf-internal.h"
#include "openapi/model/NetworkAssistanceType_anyOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_type_any_of_t *data_collection_model_network_assistance_type_any_of_create()
{
    return reinterpret_cast<data_collection_model_network_assistance_type_any_of_t*>(new std::shared_ptr<NetworkAssistanceType_anyOf>(new NetworkAssistanceType_anyOf()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_type_any_of_t *data_collection_model_network_assistance_type_any_of_create_copy(const data_collection_model_network_assistance_type_any_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NetworkAssistanceType_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceType_anyOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_network_assistance_type_any_of_t*>(new std::shared_ptr<NetworkAssistanceType_anyOf >(new NetworkAssistanceType_anyOf(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_type_any_of_t *data_collection_model_network_assistance_type_any_of_create_move(data_collection_model_network_assistance_type_any_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NetworkAssistanceType_anyOf > *obj = reinterpret_cast<std::shared_ptr<NetworkAssistanceType_anyOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_type_any_of_t *data_collection_model_network_assistance_type_any_of_copy(data_collection_model_network_assistance_type_any_of_t *network_assistance_type_any_of, const data_collection_model_network_assistance_type_any_of_t *other)
{
    if (network_assistance_type_any_of) {
        std::shared_ptr<NetworkAssistanceType_anyOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceType_anyOf >*>(network_assistance_type_any_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<NetworkAssistanceType_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceType_anyOf >*>(other);
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
                const std::shared_ptr<NetworkAssistanceType_anyOf > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceType_anyOf >*>(other);
                if (other_obj) {
                    obj.reset(new NetworkAssistanceType_anyOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        network_assistance_type_any_of = data_collection_model_network_assistance_type_any_of_create_copy(other);
    }
    return network_assistance_type_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_type_any_of_t *data_collection_model_network_assistance_type_any_of_move(data_collection_model_network_assistance_type_any_of_t *network_assistance_type_any_of, data_collection_model_network_assistance_type_any_of_t *other)
{
    std::shared_ptr<NetworkAssistanceType_anyOf > *other_ptr = reinterpret_cast<std::shared_ptr<NetworkAssistanceType_anyOf >*>(other);

    if (network_assistance_type_any_of) {
        std::shared_ptr<NetworkAssistanceType_anyOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceType_anyOf >*>(network_assistance_type_any_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                network_assistance_type_any_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return network_assistance_type_any_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_network_assistance_type_any_of_free(data_collection_model_network_assistance_type_any_of_t *network_assistance_type_any_of)
{
    if (!network_assistance_type_any_of) return;
    delete reinterpret_cast<std::shared_ptr<NetworkAssistanceType_anyOf >*>(network_assistance_type_any_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_network_assistance_type_any_of_toJSON(const data_collection_model_network_assistance_type_any_of_t *network_assistance_type_any_of, bool as_request)
{
    if (!network_assistance_type_any_of) return NULL;
    const std::shared_ptr<NetworkAssistanceType_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceType_anyOf >*>(network_assistance_type_any_of);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_type_any_of_t *data_collection_model_network_assistance_type_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_network_assistance_type_any_of_t*>(new std::shared_ptr<NetworkAssistanceType_anyOf >(new NetworkAssistanceType_anyOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_network_assistance_type_any_of_is_equal_to(const data_collection_model_network_assistance_type_any_of_t *first, const data_collection_model_network_assistance_type_any_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NetworkAssistanceType_anyOf > &obj2 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceType_anyOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NetworkAssistanceType_anyOf > &obj1 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceType_anyOf >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_type_any_of_is_not_set(const data_collection_model_network_assistance_type_any_of_t *network_assistance_type_any_of)
{
    if (!network_assistance_type_any_of) return true;
    const std::shared_ptr<NetworkAssistanceType_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceType_anyOf >*>(network_assistance_type_any_of);
    if (!obj) return true;
    return obj->getValue() == NetworkAssistanceType_anyOf::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_type_any_of_e data_collection_model_network_assistance_type_any_of_get_enum(const data_collection_model_network_assistance_type_any_of_t *obj_network_assistance_type_any_of)
{
    if (!obj_network_assistance_type_any_of)
        return DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_NO_VAL;
    const std::shared_ptr<NetworkAssistanceType_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceType_anyOf >*>(obj_network_assistance_type_any_of);
    if (!obj) return DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_NO_VAL;
    switch (obj->getValue()) {
    case NetworkAssistanceType_anyOf::Enum::NO_VAL:
        return DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_NO_VAL;
    case NetworkAssistanceType_anyOf::Enum::VAL_AF_THROUGHPUT_ESTIMATION:
        return DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_VAL_AF_THROUGHPUT_ESTIMATION;
    case NetworkAssistanceType_anyOf::Enum::VAL_AF_DELIVERY_BOOST:
        return DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_VAL_AF_DELIVERY_BOOST;
    case NetworkAssistanceType_anyOf::Enum::VAL_ANBR_THROUGHPUT_ESTIMATION:
        return DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_VAL_ANBR_THROUGHPUT_ESTIMATION;
    case NetworkAssistanceType_anyOf::Enum::VAL_ANBR_DELIVERY_BOOST:
        return DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_VAL_ANBR_DELIVERY_BOOST;
    default:
        break;
    }
    return (data_collection_model_network_assistance_type_any_of_e)-1;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_network_assistance_type_any_of_get_string(const data_collection_model_network_assistance_type_any_of_t *obj_network_assistance_type_any_of)
{
    if (!obj_network_assistance_type_any_of) return NULL;
    const std::shared_ptr<NetworkAssistanceType_anyOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceType_anyOf >*>(obj_network_assistance_type_any_of);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_type_any_of_set_enum(data_collection_model_network_assistance_type_any_of_t *obj_network_assistance_type_any_of, data_collection_model_network_assistance_type_any_of_e p_value)
{
    if (!obj_network_assistance_type_any_of) return false;
    std::shared_ptr<NetworkAssistanceType_anyOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceType_anyOf >*>(obj_network_assistance_type_any_of);
    if (!obj) return false;
    switch (p_value) {
    case DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_NO_VAL:
        *obj = NetworkAssistanceType_anyOf::Enum::NO_VAL;
        return true;
    case DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_VAL_AF_THROUGHPUT_ESTIMATION:
        *obj = NetworkAssistanceType_anyOf::Enum::VAL_AF_THROUGHPUT_ESTIMATION;
        return true;
    case DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_VAL_AF_DELIVERY_BOOST:
        *obj = NetworkAssistanceType_anyOf::Enum::VAL_AF_DELIVERY_BOOST;
        return true;
    case DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_VAL_ANBR_THROUGHPUT_ESTIMATION:
        *obj = NetworkAssistanceType_anyOf::Enum::VAL_ANBR_THROUGHPUT_ESTIMATION;
        return true;
    case DCM_NETWORK_ASSISTANCE_TYPE_ANY_OF_VAL_ANBR_DELIVERY_BOOST:
        *obj = NetworkAssistanceType_anyOf::Enum::VAL_ANBR_DELIVERY_BOOST;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_type_any_of_set_string(data_collection_model_network_assistance_type_any_of_t *obj_network_assistance_type_any_of, const char *p_value)
{
    if (!obj_network_assistance_type_any_of) return false;
    std::shared_ptr<NetworkAssistanceType_anyOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceType_anyOf >*>(obj_network_assistance_type_any_of);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = NetworkAssistanceType_anyOf::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_network_assistance_type_any_of_make_lnode(data_collection_model_network_assistance_type_any_of_t *p_network_assistance_type_any_of)
{
    return data_collection_lnode_create(p_network_assistance_type_any_of, reinterpret_cast<void(*)(void*)>(data_collection_model_network_assistance_type_any_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_assistance_type_any_of_refcount(data_collection_model_network_assistance_type_any_of_t *obj_network_assistance_type_any_of)
{
    if (!obj_network_assistance_type_any_of) return 0l;
    std::shared_ptr<NetworkAssistanceType_anyOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceType_anyOf >*>(obj_network_assistance_type_any_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

