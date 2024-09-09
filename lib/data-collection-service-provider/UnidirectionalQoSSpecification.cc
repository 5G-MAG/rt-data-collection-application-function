/**********************************************************************************************************************************
 * UnidirectionalQoSSpecification - C interface to the UnidirectionalQoSSpecification object
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

/*#include "UnidirectionalQoSSpecification.h" already included by data-collection-sp/data-collection.h */
#include "UnidirectionalQoSSpecification-internal.h"
#include "openapi/model/UnidirectionalQoSSpecification.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_create(




)
{
    return reinterpret_cast<data_collection_model_unidirectional_qo_s_specification_t*>(new std::shared_ptr<UnidirectionalQoSSpecification>(new UnidirectionalQoSSpecification(




)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_create_copy(const data_collection_model_unidirectional_qo_s_specification_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_unidirectional_qo_s_specification_t*>(new std::shared_ptr<UnidirectionalQoSSpecification >(new UnidirectionalQoSSpecification(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_create_move(data_collection_model_unidirectional_qo_s_specification_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > *obj = reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_copy(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, const data_collection_model_unidirectional_qo_s_specification_t *other)
{
    if (unidirectional_qo_s_specification) {
        std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(unidirectional_qo_s_specification);
        if (obj) {
            if (other) {
                const std::shared_ptr<UnidirectionalQoSSpecification > &other_obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(other);
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
                const std::shared_ptr<UnidirectionalQoSSpecification > &other_obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(other);
                if (other_obj) {
                    obj.reset(new UnidirectionalQoSSpecification(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        unidirectional_qo_s_specification = data_collection_model_unidirectional_qo_s_specification_create_copy(other);
    }
    return unidirectional_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_move(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, data_collection_model_unidirectional_qo_s_specification_t *other)
{
    std::shared_ptr<UnidirectionalQoSSpecification > *other_ptr = reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(other);

    if (unidirectional_qo_s_specification) {
        std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(unidirectional_qo_s_specification);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                unidirectional_qo_s_specification = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return unidirectional_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_unidirectional_qo_s_specification_free(data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification)
{
    if (!unidirectional_qo_s_specification) return;
    delete reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(unidirectional_qo_s_specification);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_unidirectional_qo_s_specification_toJSON(const data_collection_model_unidirectional_qo_s_specification_t *unidirectional_qo_s_specification, bool as_request)
{
    if (!unidirectional_qo_s_specification) return NULL;
    const std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(unidirectional_qo_s_specification);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_unidirectional_qo_s_specification_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_unidirectional_qo_s_specification_t*>(new std::shared_ptr<UnidirectionalQoSSpecification >(new UnidirectionalQoSSpecification(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_is_equal_to(const data_collection_model_unidirectional_qo_s_specification_t *first, const data_collection_model_unidirectional_qo_s_specification_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<UnidirectionalQoSSpecification > &obj2 = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<UnidirectionalQoSSpecification > &obj1 = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_unidirectional_qo_s_specification_get_maximum_requested_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification)
{
    if (!obj_unidirectional_qo_s_specification) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UnidirectionalQoSSpecification::MaximumRequestedBitRateType ResultFromType;
    const ResultFromType &result_from = obj->getMaximumRequestedBitRate();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_maximum_requested_bit_rate(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification, const char* p_maximum_requested_bit_rate)
{
    if (!obj_unidirectional_qo_s_specification) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_maximum_requested_bit_rate;
    typedef typename UnidirectionalQoSSpecification::MaximumRequestedBitRateType ValueType;

    ValueType value(value_from);

    if (!obj->setMaximumRequestedBitRate(value)) return NULL;

    return obj_unidirectional_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_maximum_requested_bit_rate_move(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification, char* p_maximum_requested_bit_rate)
{
    if (!obj_unidirectional_qo_s_specification) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_maximum_requested_bit_rate;
    typedef typename UnidirectionalQoSSpecification::MaximumRequestedBitRateType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMaximumRequestedBitRate(std::move(value))) return NULL;

    return obj_unidirectional_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_has_minimum_desired_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification)
{
    if (!obj_unidirectional_qo_s_specification) return false;

    const std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return false;

    return obj->getMinimumDesiredBitRate().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_unidirectional_qo_s_specification_get_minimum_desired_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification)
{
    if (!obj_unidirectional_qo_s_specification) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UnidirectionalQoSSpecification::MinimumDesiredBitRateType ResultFromType;
    const ResultFromType &result_from = obj->getMinimumDesiredBitRate();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_minimum_desired_bit_rate(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification, const char* p_minimum_desired_bit_rate)
{
    if (!obj_unidirectional_qo_s_specification) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_minimum_desired_bit_rate;
    typedef typename UnidirectionalQoSSpecification::MinimumDesiredBitRateType ValueType;

    ValueType value(value_from);

    if (!obj->setMinimumDesiredBitRate(value)) return NULL;

    return obj_unidirectional_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_minimum_desired_bit_rate_move(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification, char* p_minimum_desired_bit_rate)
{
    if (!obj_unidirectional_qo_s_specification) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_minimum_desired_bit_rate;
    typedef typename UnidirectionalQoSSpecification::MinimumDesiredBitRateType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMinimumDesiredBitRate(std::move(value))) return NULL;

    return obj_unidirectional_qo_s_specification;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_unidirectional_qo_s_specification_get_minimum_requested_bit_rate(const data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification)
{
    if (!obj_unidirectional_qo_s_specification) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UnidirectionalQoSSpecification::MinimumRequestedBitRateType ResultFromType;
    const ResultFromType &result_from = obj->getMinimumRequestedBitRate();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_minimum_requested_bit_rate(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification, const char* p_minimum_requested_bit_rate)
{
    if (!obj_unidirectional_qo_s_specification) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_minimum_requested_bit_rate;
    typedef typename UnidirectionalQoSSpecification::MinimumRequestedBitRateType ValueType;

    ValueType value(value_from);

    if (!obj->setMinimumRequestedBitRate(value)) return NULL;

    return obj_unidirectional_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_minimum_requested_bit_rate_move(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification, char* p_minimum_requested_bit_rate)
{
    if (!obj_unidirectional_qo_s_specification) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_minimum_requested_bit_rate;
    typedef typename UnidirectionalQoSSpecification::MinimumRequestedBitRateType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMinimumRequestedBitRate(std::move(value))) return NULL;

    return obj_unidirectional_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_has_desired_packet_latency(const data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification)
{
    if (!obj_unidirectional_qo_s_specification) return false;

    const std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return false;

    return obj->getDesiredPacketLatency().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_unidirectional_qo_s_specification_get_desired_packet_latency(const data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification)
{
    if (!obj_unidirectional_qo_s_specification) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename UnidirectionalQoSSpecification::DesiredPacketLatencyType ResultFromType;
    const ResultFromType &result_from = obj->getDesiredPacketLatency();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_desired_packet_latency(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification, const int32_t p_desired_packet_latency)
{
    if (!obj_unidirectional_qo_s_specification) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_latency;
    typedef typename UnidirectionalQoSSpecification::DesiredPacketLatencyType ValueType;

    ValueType value(value_from);

    if (!obj->setDesiredPacketLatency(value)) return NULL;

    return obj_unidirectional_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_desired_packet_latency_move(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification, int32_t p_desired_packet_latency)
{
    if (!obj_unidirectional_qo_s_specification) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_latency;
    typedef typename UnidirectionalQoSSpecification::DesiredPacketLatencyType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDesiredPacketLatency(std::move(value))) return NULL;

    return obj_unidirectional_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_unidirectional_qo_s_specification_has_desired_packet_loss_rate(const data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification)
{
    if (!obj_unidirectional_qo_s_specification) return false;

    const std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return false;

    return obj->getDesiredPacketLossRate().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_unidirectional_qo_s_specification_get_desired_packet_loss_rate(const data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification)
{
    if (!obj_unidirectional_qo_s_specification) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<const std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename UnidirectionalQoSSpecification::DesiredPacketLossRateType ResultFromType;
    const ResultFromType &result_from = obj->getDesiredPacketLossRate();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_desired_packet_loss_rate(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification, const int32_t p_desired_packet_loss_rate)
{
    if (!obj_unidirectional_qo_s_specification) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_loss_rate;
    typedef typename UnidirectionalQoSSpecification::DesiredPacketLossRateType ValueType;

    ValueType value(value_from);

    if (!obj->setDesiredPacketLossRate(value)) return NULL;

    return obj_unidirectional_qo_s_specification;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_unidirectional_qo_s_specification_t *data_collection_model_unidirectional_qo_s_specification_set_desired_packet_loss_rate_move(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification, int32_t p_desired_packet_loss_rate)
{
    if (!obj_unidirectional_qo_s_specification) return NULL;

    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    if (!obj) return NULL;

    const auto &value_from = p_desired_packet_loss_rate;
    typedef typename UnidirectionalQoSSpecification::DesiredPacketLossRateType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDesiredPacketLossRate(std::move(value))) return NULL;

    return obj_unidirectional_qo_s_specification;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_unidirectional_qo_s_specification_make_lnode(data_collection_model_unidirectional_qo_s_specification_t *p_unidirectional_qo_s_specification)
{
    return data_collection_lnode_create(p_unidirectional_qo_s_specification, reinterpret_cast<void(*)(void*)>(data_collection_model_unidirectional_qo_s_specification_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_unidirectional_qo_s_specification_refcount(data_collection_model_unidirectional_qo_s_specification_t *obj_unidirectional_qo_s_specification)
{
    if (!obj_unidirectional_qo_s_specification) return 0l;
    std::shared_ptr<UnidirectionalQoSSpecification > &obj = *reinterpret_cast<std::shared_ptr<UnidirectionalQoSSpecification >*>(obj_unidirectional_qo_s_specification);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

