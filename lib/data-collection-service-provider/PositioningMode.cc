/**********************************************************************************************************************************
 * PositioningMode - C interface to the PositioningMode object
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

/*#include "PositioningMode.h" already included by data-collection-sp/data-collection.h */
#include "PositioningMode-internal.h"
#include "openapi/model/PositioningMode.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create()
{
    return reinterpret_cast<data_collection_model_positioning_mode_t*>(new std::shared_ptr<PositioningMode>(new PositioningMode()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create_copy(const data_collection_model_positioning_mode_t *other)
{
    return reinterpret_cast<data_collection_model_positioning_mode_t*>(new std::shared_ptr<PositioningMode >(new PositioningMode(**reinterpret_cast<const std::shared_ptr<PositioningMode >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_create_move(data_collection_model_positioning_mode_t *other)
{
    return reinterpret_cast<data_collection_model_positioning_mode_t*>(new std::shared_ptr<PositioningMode >(std::move(*reinterpret_cast<std::shared_ptr<PositioningMode >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_copy(data_collection_model_positioning_mode_t *positioning_mode, const data_collection_model_positioning_mode_t *other)
{
    std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<std::shared_ptr<PositioningMode >*>(positioning_mode);
    *obj = **reinterpret_cast<const std::shared_ptr<PositioningMode >*>(other);
    return positioning_mode;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_move(data_collection_model_positioning_mode_t *positioning_mode, data_collection_model_positioning_mode_t *other)
{
    std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<std::shared_ptr<PositioningMode >*>(positioning_mode);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PositioningMode >*>(other));
    return positioning_mode;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_positioning_mode_free(data_collection_model_positioning_mode_t *positioning_mode)
{
    delete reinterpret_cast<std::shared_ptr<PositioningMode >*>(positioning_mode);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_positioning_mode_toJSON(const data_collection_model_positioning_mode_t *positioning_mode, bool as_request)
{
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(positioning_mode);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_positioning_mode_t *data_collection_model_positioning_mode_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_positioning_mode_t*>(new std::shared_ptr<PositioningMode >(new PositioningMode(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_is_not_set(const data_collection_model_positioning_mode_t *obj_positioning_mode)
{
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    return obj->getValue() == PositioningMode::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_is_non_standard(const data_collection_model_positioning_mode_t *obj_positioning_mode)
{
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    return obj->getValue() == PositioningMode::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_positioning_mode_e data_collection_model_positioning_mode_get_enum(const data_collection_model_positioning_mode_t *obj_positioning_mode)
{
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    switch (obj->getValue()) {
    case PositioningMode::Enum::NO_VAL:
        return DCM_POSITIONING_MODE_NO_VAL;
    case PositioningMode::Enum::VAL_UE_BASED:
        return DCM_POSITIONING_MODE_VAL_UE_BASED;
    case PositioningMode::Enum::VAL_UE_ASSISTED:
        return DCM_POSITIONING_MODE_VAL_UE_ASSISTED;
    case PositioningMode::Enum::VAL_CONVENTIONAL:
        return DCM_POSITIONING_MODE_VAL_CONVENTIONAL;
    default:
        break;
    }
    return DCM_POSITIONING_MODE_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_positioning_mode_get_string(const data_collection_model_positioning_mode_t *obj_positioning_mode)
{
    const std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<const std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_set_enum(data_collection_model_positioning_mode_t *obj_positioning_mode, data_collection_model_positioning_mode_e p_value)
{
    std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    switch (p_value) {
    case DCM_POSITIONING_MODE_NO_VAL:
        *obj = PositioningMode::Enum::NO_VAL;
        return true;
    case DCM_POSITIONING_MODE_VAL_UE_BASED:
        *obj = PositioningMode::Enum::VAL_UE_BASED;
        return true;
    case DCM_POSITIONING_MODE_VAL_UE_ASSISTED:
        *obj = PositioningMode::Enum::VAL_UE_ASSISTED;
        return true;
    case DCM_POSITIONING_MODE_VAL_CONVENTIONAL:
        *obj = PositioningMode::Enum::VAL_CONVENTIONAL;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_positioning_mode_set_string(data_collection_model_positioning_mode_t *obj_positioning_mode, const char *p_value)
{
    std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = PositioningMode::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_positioning_mode_make_lnode(data_collection_model_positioning_mode_t *p_positioning_mode)
{
    return data_collection_lnode_create(p_positioning_mode, reinterpret_cast<void(*)(void*)>(data_collection_model_positioning_mode_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_positioning_mode_refcount(data_collection_model_positioning_mode_t *obj_positioning_mode)
{
    std::shared_ptr<PositioningMode > &obj = *reinterpret_cast<std::shared_ptr<PositioningMode >*>(obj_positioning_mode);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

