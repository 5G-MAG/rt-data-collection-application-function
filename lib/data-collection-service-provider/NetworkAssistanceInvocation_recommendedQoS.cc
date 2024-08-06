/**********************************************************************************************************************************
 * NetworkAssistanceInvocation_recommendedQoS - C interface to the NetworkAssistanceInvocation_recommendedQoS object
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

/*#include "NetworkAssistanceInvocation_recommendedQoS.h" already included by data-collection-sp/data-collection.h */
#include "NetworkAssistanceInvocation_recommendedQoS-internal.h"
#include "openapi/model/NetworkAssistanceInvocation_recommendedQoS.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_create(

)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_recommended_qo_s_t*>(new std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS>(new NetworkAssistanceInvocation_recommendedQoS(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_create_copy(const data_collection_model_network_assistance_invocation_recommended_qo_s_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_network_assistance_invocation_recommended_qo_s_t*>(new std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >(new NetworkAssistanceInvocation_recommendedQoS(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_create_move(data_collection_model_network_assistance_invocation_recommended_qo_s_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > *obj = reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_copy(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, const data_collection_model_network_assistance_invocation_recommended_qo_s_t *other)
{
    if (network_assistance_invocation_recommended_qo_s) {
        std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(network_assistance_invocation_recommended_qo_s);
        if (obj) {
            if (other) {
                const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(other);
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
                const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &other_obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(other);
                if (other_obj) {
                    obj.reset(new NetworkAssistanceInvocation_recommendedQoS(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        network_assistance_invocation_recommended_qo_s = data_collection_model_network_assistance_invocation_recommended_qo_s_create_copy(other);
    }
    return network_assistance_invocation_recommended_qo_s;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_move(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, data_collection_model_network_assistance_invocation_recommended_qo_s_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > *other_ptr = reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(other);

    if (network_assistance_invocation_recommended_qo_s) {
        std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(network_assistance_invocation_recommended_qo_s);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                network_assistance_invocation_recommended_qo_s = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return network_assistance_invocation_recommended_qo_s;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_network_assistance_invocation_recommended_qo_s_free(data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s)
{
    if (!network_assistance_invocation_recommended_qo_s) return;
    delete reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(network_assistance_invocation_recommended_qo_s);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_network_assistance_invocation_recommended_qo_s_toJSON(const data_collection_model_network_assistance_invocation_recommended_qo_s_t *network_assistance_invocation_recommended_qo_s, bool as_request)
{
    if (!network_assistance_invocation_recommended_qo_s) return NULL;
    const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(network_assistance_invocation_recommended_qo_s);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_network_assistance_invocation_recommended_qo_s_t*>(new std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >(new NetworkAssistanceInvocation_recommendedQoS(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_network_assistance_invocation_recommended_qo_s_is_equal_to(const data_collection_model_network_assistance_invocation_recommended_qo_s_t *first, const data_collection_model_network_assistance_invocation_recommended_qo_s_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj2 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj1 = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_recommended_qo_s_get_maximum_bit_rate(const data_collection_model_network_assistance_invocation_recommended_qo_s_t *obj_network_assistance_invocation_recommended_qo_s)
{
    if (!obj_network_assistance_invocation_recommended_qo_s) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(obj_network_assistance_invocation_recommended_qo_s);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocation_recommendedQoS::MaximumBitRateType ResultFromType;
    const ResultFromType result_from = obj->getMaximumBitRate();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_set_maximum_bit_rate(data_collection_model_network_assistance_invocation_recommended_qo_s_t *obj_network_assistance_invocation_recommended_qo_s, const char* p_maximum_bit_rate)
{
    if (!obj_network_assistance_invocation_recommended_qo_s) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(obj_network_assistance_invocation_recommended_qo_s);
    if (!obj) return NULL;

    const auto &value_from = p_maximum_bit_rate;
    typedef typename NetworkAssistanceInvocation_recommendedQoS::MaximumBitRateType ValueType;

    ValueType value(value_from);
    if (!obj->setMaximumBitRate(value)) return NULL;

    return obj_network_assistance_invocation_recommended_qo_s;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_set_maximum_bit_rate_move(data_collection_model_network_assistance_invocation_recommended_qo_s_t *obj_network_assistance_invocation_recommended_qo_s, char* p_maximum_bit_rate)
{
    if (!obj_network_assistance_invocation_recommended_qo_s) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(obj_network_assistance_invocation_recommended_qo_s);
    if (!obj) return NULL;

    const auto &value_from = p_maximum_bit_rate;
    typedef typename NetworkAssistanceInvocation_recommendedQoS::MaximumBitRateType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMaximumBitRate(std::move(value))) return NULL;

    return obj_network_assistance_invocation_recommended_qo_s;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_network_assistance_invocation_recommended_qo_s_get_minimum_bit_rate(const data_collection_model_network_assistance_invocation_recommended_qo_s_t *obj_network_assistance_invocation_recommended_qo_s)
{
    if (!obj_network_assistance_invocation_recommended_qo_s) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(obj_network_assistance_invocation_recommended_qo_s);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename NetworkAssistanceInvocation_recommendedQoS::MinimumBitRateType ResultFromType;
    const ResultFromType result_from = obj->getMinimumBitRate();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_set_minimum_bit_rate(data_collection_model_network_assistance_invocation_recommended_qo_s_t *obj_network_assistance_invocation_recommended_qo_s, const char* p_minimum_bit_rate)
{
    if (!obj_network_assistance_invocation_recommended_qo_s) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(obj_network_assistance_invocation_recommended_qo_s);
    if (!obj) return NULL;

    const auto &value_from = p_minimum_bit_rate;
    typedef typename NetworkAssistanceInvocation_recommendedQoS::MinimumBitRateType ValueType;

    ValueType value(value_from);
    if (!obj->setMinimumBitRate(value)) return NULL;

    return obj_network_assistance_invocation_recommended_qo_s;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_network_assistance_invocation_recommended_qo_s_t *data_collection_model_network_assistance_invocation_recommended_qo_s_set_minimum_bit_rate_move(data_collection_model_network_assistance_invocation_recommended_qo_s_t *obj_network_assistance_invocation_recommended_qo_s, char* p_minimum_bit_rate)
{
    if (!obj_network_assistance_invocation_recommended_qo_s) return NULL;

    std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(obj_network_assistance_invocation_recommended_qo_s);
    if (!obj) return NULL;

    const auto &value_from = p_minimum_bit_rate;
    typedef typename NetworkAssistanceInvocation_recommendedQoS::MinimumBitRateType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMinimumBitRate(std::move(value))) return NULL;

    return obj_network_assistance_invocation_recommended_qo_s;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_network_assistance_invocation_recommended_qo_s_make_lnode(data_collection_model_network_assistance_invocation_recommended_qo_s_t *p_network_assistance_invocation_recommended_qo_s)
{
    return data_collection_lnode_create(p_network_assistance_invocation_recommended_qo_s, reinterpret_cast<void(*)(void*)>(data_collection_model_network_assistance_invocation_recommended_qo_s_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_assistance_invocation_recommended_qo_s_refcount(data_collection_model_network_assistance_invocation_recommended_qo_s_t *obj_network_assistance_invocation_recommended_qo_s)
{
    if (!obj_network_assistance_invocation_recommended_qo_s) return 0l;
    std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocation_recommendedQoS >*>(obj_network_assistance_invocation_recommended_qo_s);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

