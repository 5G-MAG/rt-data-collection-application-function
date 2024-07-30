/**********************************************************************************************************************************
 * CommunicationIndicator - C interface to the CommunicationIndicator object
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

/*#include "CommunicationIndicator.h" already included by data-collection-sp/data-collection.h */
#include "CommunicationIndicator-internal.h"
#include "openapi/model/CommunicationIndicator.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_indicator_t *data_collection_model_communication_indicator_create()
{
    return reinterpret_cast<data_collection_model_communication_indicator_t*>(new std::shared_ptr<CommunicationIndicator>(new CommunicationIndicator()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_indicator_t *data_collection_model_communication_indicator_create_copy(const data_collection_model_communication_indicator_t *other)
{
    return reinterpret_cast<data_collection_model_communication_indicator_t*>(new std::shared_ptr<CommunicationIndicator >(new CommunicationIndicator(**reinterpret_cast<const std::shared_ptr<CommunicationIndicator >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_indicator_t *data_collection_model_communication_indicator_create_move(data_collection_model_communication_indicator_t *other)
{
    return reinterpret_cast<data_collection_model_communication_indicator_t*>(new std::shared_ptr<CommunicationIndicator >(std::move(*reinterpret_cast<std::shared_ptr<CommunicationIndicator >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_indicator_t *data_collection_model_communication_indicator_copy(data_collection_model_communication_indicator_t *communication_indicator, const data_collection_model_communication_indicator_t *other)
{
    std::shared_ptr<CommunicationIndicator > &obj = *reinterpret_cast<std::shared_ptr<CommunicationIndicator >*>(communication_indicator);
    *obj = **reinterpret_cast<const std::shared_ptr<CommunicationIndicator >*>(other);
    return communication_indicator;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_indicator_t *data_collection_model_communication_indicator_move(data_collection_model_communication_indicator_t *communication_indicator, data_collection_model_communication_indicator_t *other)
{
    std::shared_ptr<CommunicationIndicator > &obj = *reinterpret_cast<std::shared_ptr<CommunicationIndicator >*>(communication_indicator);
    obj = std::move(*reinterpret_cast<std::shared_ptr<CommunicationIndicator >*>(other));
    return communication_indicator;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_communication_indicator_free(data_collection_model_communication_indicator_t *communication_indicator)
{
    delete reinterpret_cast<std::shared_ptr<CommunicationIndicator >*>(communication_indicator);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_communication_indicator_toJSON(const data_collection_model_communication_indicator_t *communication_indicator, bool as_request)
{
    const std::shared_ptr<CommunicationIndicator > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationIndicator >*>(communication_indicator);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_indicator_t *data_collection_model_communication_indicator_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_communication_indicator_t*>(new std::shared_ptr<CommunicationIndicator >(new CommunicationIndicator(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_communication_indicator_is_equal_to(const data_collection_model_communication_indicator_t *first, const data_collection_model_communication_indicator_t *second)
{
    const std::shared_ptr<CommunicationIndicator > &obj1 = *reinterpret_cast<const std::shared_ptr<CommunicationIndicator >*>(first);
    const std::shared_ptr<CommunicationIndicator > &obj2 = *reinterpret_cast<const std::shared_ptr<CommunicationIndicator >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_indicator_is_not_set(const data_collection_model_communication_indicator_t *obj_communication_indicator)
{
    const std::shared_ptr<CommunicationIndicator > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationIndicator >*>(obj_communication_indicator);
    return obj->getValue() == CommunicationIndicator::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_indicator_is_non_standard(const data_collection_model_communication_indicator_t *obj_communication_indicator)
{
    const std::shared_ptr<CommunicationIndicator > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationIndicator >*>(obj_communication_indicator);
    return obj->getValue() == CommunicationIndicator::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_communication_indicator_e data_collection_model_communication_indicator_get_enum(const data_collection_model_communication_indicator_t *obj_communication_indicator)
{
    const std::shared_ptr<CommunicationIndicator > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationIndicator >*>(obj_communication_indicator);
    switch (obj->getValue()) {
    case CommunicationIndicator::Enum::NO_VAL:
        return DCM_COMMUNICATION_INDICATOR_NO_VAL;
    case CommunicationIndicator::Enum::VAL_PERIODICALLY:
        return DCM_COMMUNICATION_INDICATOR_VAL_PERIODICALLY;
    case CommunicationIndicator::Enum::VAL_ON_DEMAND:
        return DCM_COMMUNICATION_INDICATOR_VAL_ON_DEMAND;
    default:
        break;
    }
    return DCM_COMMUNICATION_INDICATOR_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_communication_indicator_get_string(const data_collection_model_communication_indicator_t *obj_communication_indicator)
{
    const std::shared_ptr<CommunicationIndicator > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationIndicator >*>(obj_communication_indicator);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_indicator_set_enum(data_collection_model_communication_indicator_t *obj_communication_indicator, data_collection_model_communication_indicator_e p_value)
{
    std::shared_ptr<CommunicationIndicator > &obj = *reinterpret_cast<std::shared_ptr<CommunicationIndicator >*>(obj_communication_indicator);
    switch (p_value) {
    case DCM_COMMUNICATION_INDICATOR_NO_VAL:
        *obj = CommunicationIndicator::Enum::NO_VAL;
        return true;
    case DCM_COMMUNICATION_INDICATOR_VAL_PERIODICALLY:
        *obj = CommunicationIndicator::Enum::VAL_PERIODICALLY;
        return true;
    case DCM_COMMUNICATION_INDICATOR_VAL_ON_DEMAND:
        *obj = CommunicationIndicator::Enum::VAL_ON_DEMAND;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_communication_indicator_set_string(data_collection_model_communication_indicator_t *obj_communication_indicator, const char *p_value)
{
    std::shared_ptr<CommunicationIndicator > &obj = *reinterpret_cast<std::shared_ptr<CommunicationIndicator >*>(obj_communication_indicator);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = CommunicationIndicator::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_communication_indicator_make_lnode(data_collection_model_communication_indicator_t *p_communication_indicator)
{
    return data_collection_lnode_create(p_communication_indicator, reinterpret_cast<void(*)(void*)>(data_collection_model_communication_indicator_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_communication_indicator_refcount(data_collection_model_communication_indicator_t *obj_communication_indicator)
{
    std::shared_ptr<CommunicationIndicator > &obj = *reinterpret_cast<std::shared_ptr<CommunicationIndicator >*>(obj_communication_indicator);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

