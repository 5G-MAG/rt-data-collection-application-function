/**********************************************************************************************************************************
 * StationaryIndication - C interface to the StationaryIndication object
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

/*#include "StationaryIndication.h" already included by data-collection-sp/data-collection.h */
#include "StationaryIndication-internal.h"
#include "openapi/model/StationaryIndication.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_stationary_indication_t *data_collection_model_stationary_indication_create()
{
    return reinterpret_cast<data_collection_model_stationary_indication_t*>(new std::shared_ptr<StationaryIndication>(new StationaryIndication()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_stationary_indication_t *data_collection_model_stationary_indication_create_copy(const data_collection_model_stationary_indication_t *other)
{
    return reinterpret_cast<data_collection_model_stationary_indication_t*>(new std::shared_ptr<StationaryIndication >(new StationaryIndication(**reinterpret_cast<const std::shared_ptr<StationaryIndication >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_stationary_indication_t *data_collection_model_stationary_indication_create_move(data_collection_model_stationary_indication_t *other)
{
    return reinterpret_cast<data_collection_model_stationary_indication_t*>(new std::shared_ptr<StationaryIndication >(std::move(*reinterpret_cast<std::shared_ptr<StationaryIndication >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_stationary_indication_t *data_collection_model_stationary_indication_copy(data_collection_model_stationary_indication_t *stationary_indication, const data_collection_model_stationary_indication_t *other)
{
    std::shared_ptr<StationaryIndication > &obj = *reinterpret_cast<std::shared_ptr<StationaryIndication >*>(stationary_indication);
    *obj = **reinterpret_cast<const std::shared_ptr<StationaryIndication >*>(other);
    return stationary_indication;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_stationary_indication_t *data_collection_model_stationary_indication_move(data_collection_model_stationary_indication_t *stationary_indication, data_collection_model_stationary_indication_t *other)
{
    std::shared_ptr<StationaryIndication > &obj = *reinterpret_cast<std::shared_ptr<StationaryIndication >*>(stationary_indication);
    obj = std::move(*reinterpret_cast<std::shared_ptr<StationaryIndication >*>(other));
    return stationary_indication;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_stationary_indication_free(data_collection_model_stationary_indication_t *stationary_indication)
{
    delete reinterpret_cast<std::shared_ptr<StationaryIndication >*>(stationary_indication);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_stationary_indication_toJSON(const data_collection_model_stationary_indication_t *stationary_indication, bool as_request)
{
    const std::shared_ptr<StationaryIndication > &obj = *reinterpret_cast<const std::shared_ptr<StationaryIndication >*>(stationary_indication);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_stationary_indication_t *data_collection_model_stationary_indication_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_stationary_indication_t*>(new std::shared_ptr<StationaryIndication >(new StationaryIndication(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_stationary_indication_is_not_set(const data_collection_model_stationary_indication_t *obj_stationary_indication)
{
    const std::shared_ptr<StationaryIndication > &obj = *reinterpret_cast<const std::shared_ptr<StationaryIndication >*>(obj_stationary_indication);
    return obj->getValue() == StationaryIndication::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_stationary_indication_is_non_standard(const data_collection_model_stationary_indication_t *obj_stationary_indication)
{
    const std::shared_ptr<StationaryIndication > &obj = *reinterpret_cast<const std::shared_ptr<StationaryIndication >*>(obj_stationary_indication);
    return obj->getValue() == StationaryIndication::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_stationary_indication_e data_collection_model_stationary_indication_get_enum(const data_collection_model_stationary_indication_t *obj_stationary_indication)
{
    const std::shared_ptr<StationaryIndication > &obj = *reinterpret_cast<const std::shared_ptr<StationaryIndication >*>(obj_stationary_indication);
    switch (obj->getValue()) {
    case StationaryIndication::Enum::NO_VAL:
        return DCM_STATIONARY_INDICATION_NO_VAL;
    case StationaryIndication::Enum::VAL_STATIONARY:
        return DCM_STATIONARY_INDICATION_VAL_STATIONARY;
    case StationaryIndication::Enum::VAL_MOBILE:
        return DCM_STATIONARY_INDICATION_VAL_MOBILE;
    default:
        break;
    }
    return DCM_STATIONARY_INDICATION_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_stationary_indication_get_string(const data_collection_model_stationary_indication_t *obj_stationary_indication)
{
    const std::shared_ptr<StationaryIndication > &obj = *reinterpret_cast<const std::shared_ptr<StationaryIndication >*>(obj_stationary_indication);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_stationary_indication_set_enum(data_collection_model_stationary_indication_t *obj_stationary_indication, data_collection_model_stationary_indication_e p_value)
{
    std::shared_ptr<StationaryIndication > &obj = *reinterpret_cast<std::shared_ptr<StationaryIndication >*>(obj_stationary_indication);
    switch (p_value) {
    case DCM_STATIONARY_INDICATION_NO_VAL:
        *obj = StationaryIndication::Enum::NO_VAL;
        return true;
    case DCM_STATIONARY_INDICATION_VAL_STATIONARY:
        *obj = StationaryIndication::Enum::VAL_STATIONARY;
        return true;
    case DCM_STATIONARY_INDICATION_VAL_MOBILE:
        *obj = StationaryIndication::Enum::VAL_MOBILE;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_stationary_indication_set_string(data_collection_model_stationary_indication_t *obj_stationary_indication, const char *p_value)
{
    std::shared_ptr<StationaryIndication > &obj = *reinterpret_cast<std::shared_ptr<StationaryIndication >*>(obj_stationary_indication);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = StationaryIndication::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_stationary_indication_make_lnode(data_collection_model_stationary_indication_t *p_stationary_indication)
{
    return data_collection_lnode_create(p_stationary_indication, reinterpret_cast<void(*)(void*)>(data_collection_model_stationary_indication_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_stationary_indication_refcount(data_collection_model_stationary_indication_t *obj_stationary_indication)
{
    std::shared_ptr<StationaryIndication > &obj = *reinterpret_cast<std::shared_ptr<StationaryIndication >*>(obj_stationary_indication);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

