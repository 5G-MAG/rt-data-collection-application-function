/**********************************************************************************************************************************
 * ProblemDetails - C interface to the ProblemDetails object
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

/*#include "ProblemDetails.h" already included by data-collection-sp/data-collection.h */
#include "ProblemDetails-internal.h"
#include "openapi/model/ProblemDetails.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_create(












)
{
    return reinterpret_cast<data_collection_model_problem_details_t*>(new std::shared_ptr<ProblemDetails>(new ProblemDetails(












)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_create_copy(const data_collection_model_problem_details_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_problem_details_t*>(new std::shared_ptr<ProblemDetails >(new ProblemDetails(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_create_move(data_collection_model_problem_details_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ProblemDetails > *obj = reinterpret_cast<std::shared_ptr<ProblemDetails >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_copy(data_collection_model_problem_details_t *problem_details, const data_collection_model_problem_details_t *other)
{
    if (problem_details) {
        std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(problem_details);
        if (obj) {
            if (other) {
                const std::shared_ptr<ProblemDetails > &other_obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(other);
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
                const std::shared_ptr<ProblemDetails > &other_obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(other);
                if (other_obj) {
                    obj.reset(new ProblemDetails(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        problem_details = data_collection_model_problem_details_create_copy(other);
    }
    return problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_move(data_collection_model_problem_details_t *problem_details, data_collection_model_problem_details_t *other)
{
    std::shared_ptr<ProblemDetails > *other_ptr = reinterpret_cast<std::shared_ptr<ProblemDetails >*>(other);

    if (problem_details) {
        std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(problem_details);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                problem_details = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_problem_details_free(data_collection_model_problem_details_t *problem_details)
{
    if (!problem_details) return;
    delete reinterpret_cast<std::shared_ptr<ProblemDetails >*>(problem_details);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_problem_details_toJSON(const data_collection_model_problem_details_t *problem_details, bool as_request)
{
    if (!problem_details) return NULL;
    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(problem_details);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_problem_details_t*>(new std::shared_ptr<ProblemDetails >(new ProblemDetails(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_is_equal_to(const data_collection_model_problem_details_t *first, const data_collection_model_problem_details_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ProblemDetails > &obj2 = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ProblemDetails > &obj1 = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_type(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getType().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_type(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::TypeType ResultFromType;
    const ResultFromType result_from = obj->getType();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_type(data_collection_model_problem_details_t *obj_problem_details, const char* p_type)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_type;
    typedef typename ProblemDetails::TypeType ValueType;

    ValueType value(value_from);

    if (!obj->setType(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_type_move(data_collection_model_problem_details_t *obj_problem_details, char* p_type)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_type;
    typedef typename ProblemDetails::TypeType ValueType;

    ValueType value(value_from);

    
    if (!obj->setType(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_title(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getTitle().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_title(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::TitleType ResultFromType;
    const ResultFromType result_from = obj->getTitle();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_title(data_collection_model_problem_details_t *obj_problem_details, const char* p_title)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_title;
    typedef typename ProblemDetails::TitleType ValueType;

    ValueType value(value_from);

    if (!obj->setTitle(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_title_move(data_collection_model_problem_details_t *obj_problem_details, char* p_title)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_title;
    typedef typename ProblemDetails::TitleType ValueType;

    ValueType value(value_from);

    
    if (!obj->setTitle(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_status(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getStatus().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_problem_details_get_status(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename ProblemDetails::StatusType ResultFromType;
    const ResultFromType result_from = obj->getStatus();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_status(data_collection_model_problem_details_t *obj_problem_details, const int32_t p_status)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_status;
    typedef typename ProblemDetails::StatusType ValueType;

    ValueType value(value_from);

    if (!obj->setStatus(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_status_move(data_collection_model_problem_details_t *obj_problem_details, int32_t p_status)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_status;
    typedef typename ProblemDetails::StatusType ValueType;

    ValueType value(value_from);

    
    if (!obj->setStatus(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_detail(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getDetail().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_detail(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::DetailType ResultFromType;
    const ResultFromType result_from = obj->getDetail();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_detail(data_collection_model_problem_details_t *obj_problem_details, const char* p_detail)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_detail;
    typedef typename ProblemDetails::DetailType ValueType;

    ValueType value(value_from);

    if (!obj->setDetail(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_detail_move(data_collection_model_problem_details_t *obj_problem_details, char* p_detail)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_detail;
    typedef typename ProblemDetails::DetailType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDetail(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_instance(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getInstance().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_instance(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::InstanceType ResultFromType;
    const ResultFromType result_from = obj->getInstance();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_instance(data_collection_model_problem_details_t *obj_problem_details, const char* p_instance)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_instance;
    typedef typename ProblemDetails::InstanceType ValueType;

    ValueType value(value_from);

    if (!obj->setInstance(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_instance_move(data_collection_model_problem_details_t *obj_problem_details, char* p_instance)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_instance;
    typedef typename ProblemDetails::InstanceType ValueType;

    ValueType value(value_from);

    
    if (!obj->setInstance(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_cause(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getCause().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_cause(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::CauseType ResultFromType;
    const ResultFromType result_from = obj->getCause();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_cause(data_collection_model_problem_details_t *obj_problem_details, const char* p_cause)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_cause;
    typedef typename ProblemDetails::CauseType ValueType;

    ValueType value(value_from);

    if (!obj->setCause(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_cause_move(data_collection_model_problem_details_t *obj_problem_details, char* p_cause)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_cause;
    typedef typename ProblemDetails::CauseType ValueType;

    ValueType value(value_from);

    
    if (!obj->setCause(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_invalid_params(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getInvalidParams().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_problem_details_get_invalid_params(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::InvalidParamsType ResultFromType;
    const ResultFromType result_from = obj->getInvalidParams();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_invalid_param_t *item_obj = reinterpret_cast<data_collection_model_invalid_param_t*>(item.has_value()?new std::shared_ptr<InvalidParam >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_invalid_param_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_invalid_params(data_collection_model_problem_details_t *obj_problem_details, const ogs_list_t* p_invalid_params)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_invalid_params;
    typedef typename ProblemDetails::InvalidParamsType ValueType;

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

    if (!obj->setInvalidParams(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_invalid_params_move(data_collection_model_problem_details_t *obj_problem_details, ogs_list_t* p_invalid_params)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_invalid_params;
    typedef typename ProblemDetails::InvalidParamsType ValueType;

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

    data_collection_list_free(p_invalid_params);
    if (!obj->setInvalidParams(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_add_invalid_params(data_collection_model_problem_details_t *obj_problem_details, data_collection_model_invalid_param_t* p_invalid_params)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    typedef typename ProblemDetails::InvalidParamsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_invalid_params;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));


    if (value) obj->addInvalidParams(value.value());
    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_remove_invalid_params(data_collection_model_problem_details_t *obj_problem_details, const data_collection_model_invalid_param_t* p_invalid_params)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    typedef typename ProblemDetails::InvalidParamsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_invalid_params;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeInvalidParams(value);
    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_clear_invalid_params(data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    obj->clearInvalidParams();
    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_supported_features(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getSupportedFeatures().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_supported_features(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::SupportedFeaturesType ResultFromType;
    const ResultFromType result_from = obj->getSupportedFeatures();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_features(data_collection_model_problem_details_t *obj_problem_details, const char* p_supported_features)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_supported_features;
    typedef typename ProblemDetails::SupportedFeaturesType ValueType;

    ValueType value(value_from);

    if (!obj->setSupportedFeatures(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_features_move(data_collection_model_problem_details_t *obj_problem_details, char* p_supported_features)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_supported_features;
    typedef typename ProblemDetails::SupportedFeaturesType ValueType;

    ValueType value(value_from);

    
    if (!obj->setSupportedFeatures(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_access_token_error(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getAccessTokenError().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_access_token_err_t* data_collection_model_problem_details_get_access_token_error(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const data_collection_model_access_token_err_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const data_collection_model_access_token_err_t *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::AccessTokenErrorType ResultFromType;
    const ResultFromType result_from = obj->getAccessTokenError();
    const data_collection_model_access_token_err_t *result = reinterpret_cast<const data_collection_model_access_token_err_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_error(data_collection_model_problem_details_t *obj_problem_details, const data_collection_model_access_token_err_t* p_access_token_error)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_access_token_error;
    typedef typename ProblemDetails::AccessTokenErrorType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setAccessTokenError(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_error_move(data_collection_model_problem_details_t *obj_problem_details, data_collection_model_access_token_err_t* p_access_token_error)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_access_token_error;
    typedef typename ProblemDetails::AccessTokenErrorType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setAccessTokenError(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_access_token_request(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getAccessTokenRequest().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_access_token_req_t* data_collection_model_problem_details_get_access_token_request(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const data_collection_model_access_token_req_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const data_collection_model_access_token_req_t *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::AccessTokenRequestType ResultFromType;
    const ResultFromType result_from = obj->getAccessTokenRequest();
    const data_collection_model_access_token_req_t *result = reinterpret_cast<const data_collection_model_access_token_req_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_request(data_collection_model_problem_details_t *obj_problem_details, const data_collection_model_access_token_req_t* p_access_token_request)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_access_token_request;
    typedef typename ProblemDetails::AccessTokenRequestType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setAccessTokenRequest(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_access_token_request_move(data_collection_model_problem_details_t *obj_problem_details, data_collection_model_access_token_req_t* p_access_token_request)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_access_token_request;
    typedef typename ProblemDetails::AccessTokenRequestType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setAccessTokenRequest(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_nrf_id(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getNrfId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_problem_details_get_nrf_id(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::NrfIdType ResultFromType;
    const ResultFromType result_from = obj->getNrfId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_nrf_id(data_collection_model_problem_details_t *obj_problem_details, const char* p_nrf_id)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_nrf_id;
    typedef typename ProblemDetails::NrfIdType ValueType;

    ValueType value(value_from);

    if (!obj->setNrfId(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_nrf_id_move(data_collection_model_problem_details_t *obj_problem_details, char* p_nrf_id)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_nrf_id;
    typedef typename ProblemDetails::NrfIdType ValueType;

    ValueType value(value_from);

    
    if (!obj->setNrfId(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_supported_api_versions(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getSupportedApiVersions().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_problem_details_get_supported_api_versions(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::SupportedApiVersionsType ResultFromType;
    const ResultFromType result_from = obj->getSupportedApiVersions();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        node = item.has_value()?data_collection_lnode_create(data_collection_strdup(item.value().c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free)):nullptr;
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_api_versions(data_collection_model_problem_details_t *obj_problem_details, const ogs_list_t* p_supported_api_versions)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_supported_api_versions;
    typedef typename ProblemDetails::SupportedApiVersionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    if (!obj->setSupportedApiVersions(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_supported_api_versions_move(data_collection_model_problem_details_t *obj_problem_details, ogs_list_t* p_supported_api_versions)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_supported_api_versions;
    typedef typename ProblemDetails::SupportedApiVersionsType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(typename ItemType::value_type((const char *)lnode->object))));
            
        }
    }

    data_collection_list_free(p_supported_api_versions);
    if (!obj->setSupportedApiVersions(std::move(value))) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_add_supported_api_versions(data_collection_model_problem_details_t *obj_problem_details, char* p_supported_api_versions)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    typedef typename ProblemDetails::SupportedApiVersionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_supported_api_versions;

    ValueType value(value_from);


    if (value) obj->addSupportedApiVersions(value.value());
    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_remove_supported_api_versions(data_collection_model_problem_details_t *obj_problem_details, const char* p_supported_api_versions)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    typedef typename ProblemDetails::SupportedApiVersionsType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_supported_api_versions;
    ValueType value(value_from);

    obj->removeSupportedApiVersions(value);
    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_clear_supported_api_versions(data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    obj->clearSupportedApiVersions();
    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_problem_details_has_no_profile_match_info(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return false;

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return false;

    return obj->getNoProfileMatchInfo().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_no_profile_match_info_t* data_collection_model_problem_details_get_no_profile_match_info(const data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) {
        const data_collection_model_no_profile_match_info_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<const std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) {
        const data_collection_model_no_profile_match_info_t *result = NULL;
        return result;
    }

    typedef typename ProblemDetails::NoProfileMatchInfoType ResultFromType;
    const ResultFromType result_from = obj->getNoProfileMatchInfo();
    const data_collection_model_no_profile_match_info_t *result = reinterpret_cast<const data_collection_model_no_profile_match_info_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_no_profile_match_info(data_collection_model_problem_details_t *obj_problem_details, const data_collection_model_no_profile_match_info_t* p_no_profile_match_info)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_no_profile_match_info;
    typedef typename ProblemDetails::NoProfileMatchInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setNoProfileMatchInfo(value)) return NULL;

    return obj_problem_details;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_problem_details_t *data_collection_model_problem_details_set_no_profile_match_info_move(data_collection_model_problem_details_t *obj_problem_details, data_collection_model_no_profile_match_info_t* p_no_profile_match_info)
{
    if (!obj_problem_details) return NULL;

    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    if (!obj) return NULL;

    const auto &value_from = p_no_profile_match_info;
    typedef typename ProblemDetails::NoProfileMatchInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setNoProfileMatchInfo(std::move(value))) return NULL;

    return obj_problem_details;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_problem_details_make_lnode(data_collection_model_problem_details_t *p_problem_details)
{
    return data_collection_lnode_create(p_problem_details, reinterpret_cast<void(*)(void*)>(data_collection_model_problem_details_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_problem_details_refcount(data_collection_model_problem_details_t *obj_problem_details)
{
    if (!obj_problem_details) return 0l;
    std::shared_ptr<ProblemDetails > &obj = *reinterpret_cast<std::shared_ptr<ProblemDetails >*>(obj_problem_details);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

