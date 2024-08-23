/**********************************************************************************************************************************
 * AccuracyFulfilmentIndicator - C interface to the AccuracyFulfilmentIndicator object
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

/*#include "AccuracyFulfilmentIndicator.h" already included by data-collection-sp/data-collection.h */
#include "AccuracyFulfilmentIndicator-internal.h"
#include "openapi/model/AccuracyFulfilmentIndicator.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_create()
{
    return reinterpret_cast<data_collection_model_accuracy_fulfilment_indicator_t*>(new std::shared_ptr<AccuracyFulfilmentIndicator>(new AccuracyFulfilmentIndicator()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_create_copy(const data_collection_model_accuracy_fulfilment_indicator_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<const std::shared_ptr<AccuracyFulfilmentIndicator >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_accuracy_fulfilment_indicator_t*>(new std::shared_ptr<AccuracyFulfilmentIndicator >(new AccuracyFulfilmentIndicator(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_create_move(data_collection_model_accuracy_fulfilment_indicator_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<AccuracyFulfilmentIndicator > *obj = reinterpret_cast<std::shared_ptr<AccuracyFulfilmentIndicator >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_copy(data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator, const data_collection_model_accuracy_fulfilment_indicator_t *other)
{
    if (accuracy_fulfilment_indicator) {
        std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<std::shared_ptr<AccuracyFulfilmentIndicator >*>(accuracy_fulfilment_indicator);
        if (obj) {
            if (other) {
                const std::shared_ptr<AccuracyFulfilmentIndicator > &other_obj = *reinterpret_cast<const std::shared_ptr<AccuracyFulfilmentIndicator >*>(other);
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
                const std::shared_ptr<AccuracyFulfilmentIndicator > &other_obj = *reinterpret_cast<const std::shared_ptr<AccuracyFulfilmentIndicator >*>(other);
                if (other_obj) {
                    obj.reset(new AccuracyFulfilmentIndicator(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        accuracy_fulfilment_indicator = data_collection_model_accuracy_fulfilment_indicator_create_copy(other);
    }
    return accuracy_fulfilment_indicator;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_move(data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator, data_collection_model_accuracy_fulfilment_indicator_t *other)
{
    std::shared_ptr<AccuracyFulfilmentIndicator > *other_ptr = reinterpret_cast<std::shared_ptr<AccuracyFulfilmentIndicator >*>(other);

    if (accuracy_fulfilment_indicator) {
        std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<std::shared_ptr<AccuracyFulfilmentIndicator >*>(accuracy_fulfilment_indicator);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                accuracy_fulfilment_indicator = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return accuracy_fulfilment_indicator;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_accuracy_fulfilment_indicator_free(data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator)
{
    if (!accuracy_fulfilment_indicator) return;
    delete reinterpret_cast<std::shared_ptr<AccuracyFulfilmentIndicator >*>(accuracy_fulfilment_indicator);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_accuracy_fulfilment_indicator_toJSON(const data_collection_model_accuracy_fulfilment_indicator_t *accuracy_fulfilment_indicator, bool as_request)
{
    if (!accuracy_fulfilment_indicator) return NULL;
    const std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<const std::shared_ptr<AccuracyFulfilmentIndicator >*>(accuracy_fulfilment_indicator);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_t *data_collection_model_accuracy_fulfilment_indicator_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_accuracy_fulfilment_indicator_t*>(new std::shared_ptr<AccuracyFulfilmentIndicator >(new AccuracyFulfilmentIndicator(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_accuracy_fulfilment_indicator_is_equal_to(const data_collection_model_accuracy_fulfilment_indicator_t *first, const data_collection_model_accuracy_fulfilment_indicator_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<AccuracyFulfilmentIndicator > &obj2 = *reinterpret_cast<const std::shared_ptr<AccuracyFulfilmentIndicator >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<AccuracyFulfilmentIndicator > &obj1 = *reinterpret_cast<const std::shared_ptr<AccuracyFulfilmentIndicator >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_accuracy_fulfilment_indicator_is_not_set(const data_collection_model_accuracy_fulfilment_indicator_t *obj_accuracy_fulfilment_indicator)
{
    if (!obj_accuracy_fulfilment_indicator) return true;
    const std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<const std::shared_ptr<AccuracyFulfilmentIndicator >*>(obj_accuracy_fulfilment_indicator);
    if (!obj) return true;
    return obj->getValue() == AccuracyFulfilmentIndicator::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_accuracy_fulfilment_indicator_is_non_standard(const data_collection_model_accuracy_fulfilment_indicator_t *obj_accuracy_fulfilment_indicator)
{
    if (!obj_accuracy_fulfilment_indicator) return false;
    const std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<const std::shared_ptr<AccuracyFulfilmentIndicator >*>(obj_accuracy_fulfilment_indicator);
    if (!obj) return false;
    return obj->getValue() == AccuracyFulfilmentIndicator::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_accuracy_fulfilment_indicator_e data_collection_model_accuracy_fulfilment_indicator_get_enum(const data_collection_model_accuracy_fulfilment_indicator_t *obj_accuracy_fulfilment_indicator)
{
    if (!obj_accuracy_fulfilment_indicator)
        return DCM_ACCURACY_FULFILMENT_INDICATOR_NO_VAL;
    const std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<const std::shared_ptr<AccuracyFulfilmentIndicator >*>(obj_accuracy_fulfilment_indicator);
    if (!obj) return DCM_ACCURACY_FULFILMENT_INDICATOR_NO_VAL;
    switch (obj->getValue()) {
    case AccuracyFulfilmentIndicator::Enum::NO_VAL:
        return DCM_ACCURACY_FULFILMENT_INDICATOR_NO_VAL;
    case AccuracyFulfilmentIndicator::Enum::VAL_REQUESTED_ACCURACY_FULFILLED:
        return DCM_ACCURACY_FULFILMENT_INDICATOR_VAL_REQUESTED_ACCURACY_FULFILLED;
    case AccuracyFulfilmentIndicator::Enum::VAL_REQUESTED_ACCURACY_NOT_FULFILLED:
        return DCM_ACCURACY_FULFILMENT_INDICATOR_VAL_REQUESTED_ACCURACY_NOT_FULFILLED;
    default:
        break;
    }
    return DCM_ACCURACY_FULFILMENT_INDICATOR_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_accuracy_fulfilment_indicator_get_string(const data_collection_model_accuracy_fulfilment_indicator_t *obj_accuracy_fulfilment_indicator)
{
    if (!obj_accuracy_fulfilment_indicator) return NULL;
    const std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<const std::shared_ptr<AccuracyFulfilmentIndicator >*>(obj_accuracy_fulfilment_indicator);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_accuracy_fulfilment_indicator_set_enum(data_collection_model_accuracy_fulfilment_indicator_t *obj_accuracy_fulfilment_indicator, data_collection_model_accuracy_fulfilment_indicator_e p_value)
{
    if (!obj_accuracy_fulfilment_indicator) return false;
    std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<std::shared_ptr<AccuracyFulfilmentIndicator >*>(obj_accuracy_fulfilment_indicator);
    if (!obj) return false;
    switch (p_value) {
    case DCM_ACCURACY_FULFILMENT_INDICATOR_NO_VAL:
        *obj = AccuracyFulfilmentIndicator::Enum::NO_VAL;
        return true;
    case DCM_ACCURACY_FULFILMENT_INDICATOR_VAL_REQUESTED_ACCURACY_FULFILLED:
        *obj = AccuracyFulfilmentIndicator::Enum::VAL_REQUESTED_ACCURACY_FULFILLED;
        return true;
    case DCM_ACCURACY_FULFILMENT_INDICATOR_VAL_REQUESTED_ACCURACY_NOT_FULFILLED:
        *obj = AccuracyFulfilmentIndicator::Enum::VAL_REQUESTED_ACCURACY_NOT_FULFILLED;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_accuracy_fulfilment_indicator_set_string(data_collection_model_accuracy_fulfilment_indicator_t *obj_accuracy_fulfilment_indicator, const char *p_value)
{
    if (!obj_accuracy_fulfilment_indicator) return false;
    std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<std::shared_ptr<AccuracyFulfilmentIndicator >*>(obj_accuracy_fulfilment_indicator);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = AccuracyFulfilmentIndicator::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_accuracy_fulfilment_indicator_make_lnode(data_collection_model_accuracy_fulfilment_indicator_t *p_accuracy_fulfilment_indicator)
{
    return data_collection_lnode_create(p_accuracy_fulfilment_indicator, reinterpret_cast<void(*)(void*)>(data_collection_model_accuracy_fulfilment_indicator_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_accuracy_fulfilment_indicator_refcount(data_collection_model_accuracy_fulfilment_indicator_t *obj_accuracy_fulfilment_indicator)
{
    if (!obj_accuracy_fulfilment_indicator) return 0l;
    std::shared_ptr<AccuracyFulfilmentIndicator > &obj = *reinterpret_cast<std::shared_ptr<AccuracyFulfilmentIndicator >*>(obj_accuracy_fulfilment_indicator);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

