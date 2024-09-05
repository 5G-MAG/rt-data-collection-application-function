/**********************************************************************************************************************************
 * CpParameterSet - C interface to the CpParameterSet object
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

/*#include "CpParameterSet.h" already included by data-collection-sp/data-collection.h */
#include "CpParameterSet-internal.h"
#include "openapi/model/CpParameterSet.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_create(
















)
{
    return reinterpret_cast<data_collection_model_cp_parameter_set_t*>(new std::shared_ptr<CpParameterSet>(new CpParameterSet(
















)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_create_copy(const data_collection_model_cp_parameter_set_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_cp_parameter_set_t*>(new std::shared_ptr<CpParameterSet >(new CpParameterSet(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_create_move(data_collection_model_cp_parameter_set_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<CpParameterSet > *obj = reinterpret_cast<std::shared_ptr<CpParameterSet >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_copy(data_collection_model_cp_parameter_set_t *cp_parameter_set, const data_collection_model_cp_parameter_set_t *other)
{
    if (cp_parameter_set) {
        std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(cp_parameter_set);
        if (obj) {
            if (other) {
                const std::shared_ptr<CpParameterSet > &other_obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(other);
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
                const std::shared_ptr<CpParameterSet > &other_obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(other);
                if (other_obj) {
                    obj.reset(new CpParameterSet(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        cp_parameter_set = data_collection_model_cp_parameter_set_create_copy(other);
    }
    return cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_move(data_collection_model_cp_parameter_set_t *cp_parameter_set, data_collection_model_cp_parameter_set_t *other)
{
    std::shared_ptr<CpParameterSet > *other_ptr = reinterpret_cast<std::shared_ptr<CpParameterSet >*>(other);

    if (cp_parameter_set) {
        std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(cp_parameter_set);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                cp_parameter_set = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_cp_parameter_set_free(data_collection_model_cp_parameter_set_t *cp_parameter_set)
{
    if (!cp_parameter_set) return;
    delete reinterpret_cast<std::shared_ptr<CpParameterSet >*>(cp_parameter_set);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_cp_parameter_set_toJSON(const data_collection_model_cp_parameter_set_t *cp_parameter_set, bool as_request)
{
    if (!cp_parameter_set) return NULL;
    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(cp_parameter_set);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_cp_parameter_set_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_cp_parameter_set_t*>(new std::shared_ptr<CpParameterSet >(new CpParameterSet(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_is_equal_to(const data_collection_model_cp_parameter_set_t *first, const data_collection_model_cp_parameter_set_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<CpParameterSet > &obj2 = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<CpParameterSet > &obj1 = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_cp_parameter_set_get_set_id(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::SetIdType ResultFromType;
    const ResultFromType result_from = obj->getSetId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_set_id(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const char* p_set_id)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_set_id;
    typedef typename CpParameterSet::SetIdType ValueType;

    ValueType value(value_from);

    if (!obj->setSetId(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_set_id_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, char* p_set_id)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_set_id;
    typedef typename CpParameterSet::SetIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setSetId(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_self(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getSelf().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_cp_parameter_set_get_self(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::SelfType ResultFromType;
    const ResultFromType result_from = obj->getSelf();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_self(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const char* p_self)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_self;
    typedef typename CpParameterSet::SelfType ValueType;

    ValueType value(value_from);

    if (!obj->setSelf(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_self_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, char* p_self)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_self;
    typedef typename CpParameterSet::SelfType ValueType;

    ValueType value(value_from);

    
    if (!obj->setSelf(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_validity_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getValidityTime().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_cp_parameter_set_get_validity_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::ValidityTimeType ResultFromType;
    const ResultFromType result_from = obj->getValidityTime();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_validity_time(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const char* p_validity_time)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_validity_time;
    typedef typename CpParameterSet::ValidityTimeType ValueType;

    ValueType value(value_from);

    if (!obj->setValidityTime(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_validity_time_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, char* p_validity_time)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_validity_time;
    typedef typename CpParameterSet::ValidityTimeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setValidityTime(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_periodic_communication_indicator(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getPeriodicCommunicationIndicator().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_communication_indicator_t* data_collection_model_cp_parameter_set_get_periodic_communication_indicator(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const data_collection_model_communication_indicator_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const data_collection_model_communication_indicator_t *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::PeriodicCommunicationIndicatorType ResultFromType;
    const ResultFromType result_from = obj->getPeriodicCommunicationIndicator();
    const data_collection_model_communication_indicator_t *result = reinterpret_cast<const data_collection_model_communication_indicator_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_communication_indicator(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_communication_indicator_t* p_periodic_communication_indicator)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_periodic_communication_indicator;
    typedef typename CpParameterSet::PeriodicCommunicationIndicatorType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setPeriodicCommunicationIndicator(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_communication_indicator_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_communication_indicator_t* p_periodic_communication_indicator)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_periodic_communication_indicator;
    typedef typename CpParameterSet::PeriodicCommunicationIndicatorType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setPeriodicCommunicationIndicator(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_communication_duration_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getCommunicationDurationTime().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_cp_parameter_set_get_communication_duration_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename CpParameterSet::CommunicationDurationTimeType ResultFromType;
    const ResultFromType result_from = obj->getCommunicationDurationTime();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_communication_duration_time(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const int32_t p_communication_duration_time)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_communication_duration_time;
    typedef typename CpParameterSet::CommunicationDurationTimeType ValueType;

    ValueType value(value_from);

    if (!obj->setCommunicationDurationTime(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_communication_duration_time_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, int32_t p_communication_duration_time)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_communication_duration_time;
    typedef typename CpParameterSet::CommunicationDurationTimeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setCommunicationDurationTime(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_periodic_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getPeriodicTime().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_cp_parameter_set_get_periodic_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename CpParameterSet::PeriodicTimeType ResultFromType;
    const ResultFromType result_from = obj->getPeriodicTime();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_time(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const int32_t p_periodic_time)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_periodic_time;
    typedef typename CpParameterSet::PeriodicTimeType ValueType;

    ValueType value(value_from);

    if (!obj->setPeriodicTime(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_periodic_time_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, int32_t p_periodic_time)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_periodic_time;
    typedef typename CpParameterSet::PeriodicTimeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPeriodicTime(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_scheduled_communication_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getScheduledCommunicationTime().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_scheduled_communication_time_t* data_collection_model_cp_parameter_set_get_scheduled_communication_time(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const data_collection_model_scheduled_communication_time_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const data_collection_model_scheduled_communication_time_t *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::ScheduledCommunicationTimeType ResultFromType;
    const ResultFromType result_from = obj->getScheduledCommunicationTime();
    const data_collection_model_scheduled_communication_time_t *result = reinterpret_cast<const data_collection_model_scheduled_communication_time_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_time(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_scheduled_communication_time_t* p_scheduled_communication_time)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_scheduled_communication_time;
    typedef typename CpParameterSet::ScheduledCommunicationTimeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setScheduledCommunicationTime(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_time_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_scheduled_communication_time_t* p_scheduled_communication_time)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_scheduled_communication_time;
    typedef typename CpParameterSet::ScheduledCommunicationTimeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setScheduledCommunicationTime(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_scheduled_communication_type(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getScheduledCommunicationType().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_scheduled_communication_type_t* data_collection_model_cp_parameter_set_get_scheduled_communication_type(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const data_collection_model_scheduled_communication_type_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const data_collection_model_scheduled_communication_type_t *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::ScheduledCommunicationTypeType ResultFromType;
    const ResultFromType result_from = obj->getScheduledCommunicationType();
    const data_collection_model_scheduled_communication_type_t *result = reinterpret_cast<const data_collection_model_scheduled_communication_type_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_type(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_scheduled_communication_type_t* p_scheduled_communication_type)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_scheduled_communication_type;
    typedef typename CpParameterSet::ScheduledCommunicationTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setScheduledCommunicationType(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_scheduled_communication_type_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_scheduled_communication_type_t* p_scheduled_communication_type)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_scheduled_communication_type;
    typedef typename CpParameterSet::ScheduledCommunicationTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setScheduledCommunicationType(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_stationary_indication(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getStationaryIndication().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_stationary_indication_t* data_collection_model_cp_parameter_set_get_stationary_indication(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const data_collection_model_stationary_indication_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const data_collection_model_stationary_indication_t *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::StationaryIndicationType ResultFromType;
    const ResultFromType result_from = obj->getStationaryIndication();
    const data_collection_model_stationary_indication_t *result = reinterpret_cast<const data_collection_model_stationary_indication_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_stationary_indication(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_stationary_indication_t* p_stationary_indication)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_stationary_indication;
    typedef typename CpParameterSet::StationaryIndicationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setStationaryIndication(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_stationary_indication_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_stationary_indication_t* p_stationary_indication)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_stationary_indication;
    typedef typename CpParameterSet::StationaryIndicationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setStationaryIndication(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_battery_inds(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getBatteryInds().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_cp_parameter_set_get_battery_inds(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::BatteryIndsType ResultFromType;
    const ResultFromType result_from = obj->getBatteryInds();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_battery_indication_t *item_obj = reinterpret_cast<data_collection_model_battery_indication_t*>(item.has_value()?new std::shared_ptr<BatteryIndication >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_battery_indication_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_battery_inds(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const ogs_list_t* p_battery_inds)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_battery_inds;
    typedef typename CpParameterSet::BatteryIndsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setBatteryInds(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_battery_inds_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, ogs_list_t* p_battery_inds)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_battery_inds;
    typedef typename CpParameterSet::BatteryIndsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_battery_inds);
    if (!obj->setBatteryInds(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_add_battery_inds(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_battery_indication_t* p_battery_inds)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    typedef typename CpParameterSet::BatteryIndsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_battery_inds;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addBatteryInds(value.value());
    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_remove_battery_inds(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_battery_indication_t* p_battery_inds)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    typedef typename CpParameterSet::BatteryIndsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_battery_inds;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeBatteryInds(value);
    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_clear_battery_inds(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    obj->clearBatteryInds();
    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_traffic_profile(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getTrafficProfile().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_traffic_profile_t* data_collection_model_cp_parameter_set_get_traffic_profile(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const data_collection_model_traffic_profile_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const data_collection_model_traffic_profile_t *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::TrafficProfileType ResultFromType;
    const ResultFromType result_from = obj->getTrafficProfile();
    const data_collection_model_traffic_profile_t *result = reinterpret_cast<const data_collection_model_traffic_profile_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_traffic_profile(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_traffic_profile_t* p_traffic_profile)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_traffic_profile;
    typedef typename CpParameterSet::TrafficProfileType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setTrafficProfile(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_traffic_profile_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_traffic_profile_t* p_traffic_profile)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_traffic_profile;
    typedef typename CpParameterSet::TrafficProfileType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setTrafficProfile(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_expected_umts(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getExpectedUmts().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_cp_parameter_set_get_expected_umts(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::ExpectedUmtsType ResultFromType;
    const ResultFromType result_from = obj->getExpectedUmts();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_umt_location_area5_g_t *item_obj = reinterpret_cast<data_collection_model_umt_location_area5_g_t*>(item.has_value()?new std::shared_ptr<UmtLocationArea5G >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_umt_location_area5_g_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umts(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const ogs_list_t* p_expected_umts)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_expected_umts;
    typedef typename CpParameterSet::ExpectedUmtsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setExpectedUmts(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umts_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, ogs_list_t* p_expected_umts)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_expected_umts;
    typedef typename CpParameterSet::ExpectedUmtsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_expected_umts);
    if (!obj->setExpectedUmts(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_add_expected_umts(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_umt_location_area5_g_t* p_expected_umts)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    typedef typename CpParameterSet::ExpectedUmtsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_expected_umts;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addExpectedUmts(value.value());
    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_remove_expected_umts(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_umt_location_area5_g_t* p_expected_umts)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    typedef typename CpParameterSet::ExpectedUmtsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_expected_umts;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeExpectedUmts(value);
    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_clear_expected_umts(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    obj->clearExpectedUmts();
    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_expected_umt_days(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getExpectedUmtDays().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_cp_parameter_set_get_expected_umt_days(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename CpParameterSet::ExpectedUmtDaysType ResultFromType;
    const ResultFromType result_from = obj->getExpectedUmtDays();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const int32_t p_expected_umt_days)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_expected_umt_days;
    typedef typename CpParameterSet::ExpectedUmtDaysType ValueType;

    ValueType value(value_from);

    if (!obj->setExpectedUmtDays(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, int32_t p_expected_umt_days)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_expected_umt_days;
    typedef typename CpParameterSet::ExpectedUmtDaysType ValueType;

    ValueType value(value_from);

    
    if (!obj->setExpectedUmtDays(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_expected_umt_days_add(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getExpectedUmtDaysAdd().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_cp_parameter_set_get_expected_umt_days_add(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::ExpectedUmtDaysAddType ResultFromType;
    const ResultFromType result_from = obj->getExpectedUmtDaysAdd();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        int32_t *item_obj = reinterpret_cast<int32_t*>(item.has_value()?ogs_malloc(sizeof(*item_obj)):nullptr);
        if (item_obj) {
            *item_obj = item.value();
            node = data_collection_lnode_create(item_obj, reinterpret_cast<void(*)(void*)>(_ogs_free));
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days_add(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const ogs_list_t* p_expected_umt_days_add)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_expected_umt_days_add;
    typedef typename CpParameterSet::ExpectedUmtDaysAddType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setExpectedUmtDaysAdd(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_expected_umt_days_add_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, ogs_list_t* p_expected_umt_days_add)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_expected_umt_days_add;
    typedef typename CpParameterSet::ExpectedUmtDaysAddType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    data_collection_list_free(p_expected_umt_days_add);
    if (!obj->setExpectedUmtDaysAdd(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_add_expected_umt_days_add(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, int32_t p_expected_umt_days_add)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    typedef typename CpParameterSet::ExpectedUmtDaysAddType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_expected_umt_days_add;

    ValueType value(value_from);


    if (value) obj->addExpectedUmtDaysAdd(value.value());
    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_remove_expected_umt_days_add(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const int32_t p_expected_umt_days_add)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    typedef typename CpParameterSet::ExpectedUmtDaysAddType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_expected_umt_days_add;
    ValueType value(value_from);

    obj->removeExpectedUmtDaysAdd(value);
    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_clear_expected_umt_days_add(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    obj->clearExpectedUmtDaysAdd();
    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_app_exp_ue_behv(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getAppExpUeBehv().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_app_exp_ue_behaviour_t* data_collection_model_cp_parameter_set_get_app_exp_ue_behv(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const data_collection_model_app_exp_ue_behaviour_t *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const data_collection_model_app_exp_ue_behaviour_t *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::AppExpUeBehvType ResultFromType;
    const ResultFromType result_from = obj->getAppExpUeBehv();
    const data_collection_model_app_exp_ue_behaviour_t *result = reinterpret_cast<const data_collection_model_app_exp_ue_behaviour_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_app_exp_ue_behv(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const data_collection_model_app_exp_ue_behaviour_t* p_app_exp_ue_behv)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_app_exp_ue_behv;
    typedef typename CpParameterSet::AppExpUeBehvType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setAppExpUeBehv(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_app_exp_ue_behv_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, data_collection_model_app_exp_ue_behaviour_t* p_app_exp_ue_behv)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_app_exp_ue_behv;
    typedef typename CpParameterSet::AppExpUeBehvType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setAppExpUeBehv(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_confidence_level(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getConfidenceLevel().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_cp_parameter_set_get_confidence_level(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::ConfidenceLevelType ResultFromType;
    const ResultFromType result_from = obj->getConfidenceLevel();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_confidence_level(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const char* p_confidence_level)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_confidence_level;
    typedef typename CpParameterSet::ConfidenceLevelType ValueType;

    ValueType value(value_from);

    if (!obj->setConfidenceLevel(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_confidence_level_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, char* p_confidence_level)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_confidence_level;
    typedef typename CpParameterSet::ConfidenceLevelType ValueType;

    ValueType value(value_from);

    
    if (!obj->setConfidenceLevel(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cp_parameter_set_has_accuracy_level(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return false;

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return false;

    return obj->getAccuracyLevel().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_cp_parameter_set_get_accuracy_level(const data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<const std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CpParameterSet::AccuracyLevelType ResultFromType;
    const ResultFromType result_from = obj->getAccuracyLevel();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_accuracy_level(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, const char* p_accuracy_level)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_accuracy_level;
    typedef typename CpParameterSet::AccuracyLevelType ValueType;

    ValueType value(value_from);

    if (!obj->setAccuracyLevel(value)) return NULL;

    return obj_cp_parameter_set;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cp_parameter_set_t *data_collection_model_cp_parameter_set_set_accuracy_level_move(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set, char* p_accuracy_level)
{
    if (!obj_cp_parameter_set) return NULL;

    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    if (!obj) return NULL;

    const auto &value_from = p_accuracy_level;
    typedef typename CpParameterSet::AccuracyLevelType ValueType;

    ValueType value(value_from);

    
    if (!obj->setAccuracyLevel(std::move(value))) return NULL;

    return obj_cp_parameter_set;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_cp_parameter_set_make_lnode(data_collection_model_cp_parameter_set_t *p_cp_parameter_set)
{
    return data_collection_lnode_create(p_cp_parameter_set, reinterpret_cast<void(*)(void*)>(data_collection_model_cp_parameter_set_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_cp_parameter_set_refcount(data_collection_model_cp_parameter_set_t *obj_cp_parameter_set)
{
    if (!obj_cp_parameter_set) return 0l;
    std::shared_ptr<CpParameterSet > &obj = *reinterpret_cast<std::shared_ptr<CpParameterSet >*>(obj_cp_parameter_set);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

