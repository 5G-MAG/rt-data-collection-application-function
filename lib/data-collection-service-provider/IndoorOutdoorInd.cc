/**********************************************************************************************************************************
 * IndoorOutdoorInd - C interface to the IndoorOutdoorInd object
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

/*#include "IndoorOutdoorInd.h" already included by data-collection-sp/data-collection.h */
#include "IndoorOutdoorInd-internal.h"
#include "openapi/model/IndoorOutdoorInd.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_create()
{
    return reinterpret_cast<data_collection_model_indoor_outdoor_ind_t*>(new std::shared_ptr<IndoorOutdoorInd>(new IndoorOutdoorInd()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_create_copy(const data_collection_model_indoor_outdoor_ind_t *other)
{
    return reinterpret_cast<data_collection_model_indoor_outdoor_ind_t*>(new std::shared_ptr<IndoorOutdoorInd >(new IndoorOutdoorInd(**reinterpret_cast<const std::shared_ptr<IndoorOutdoorInd >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_create_move(data_collection_model_indoor_outdoor_ind_t *other)
{
    return reinterpret_cast<data_collection_model_indoor_outdoor_ind_t*>(new std::shared_ptr<IndoorOutdoorInd >(std::move(*reinterpret_cast<std::shared_ptr<IndoorOutdoorInd >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_copy(data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind, const data_collection_model_indoor_outdoor_ind_t *other)
{
    std::shared_ptr<IndoorOutdoorInd > &obj = *reinterpret_cast<std::shared_ptr<IndoorOutdoorInd >*>(indoor_outdoor_ind);
    *obj = **reinterpret_cast<const std::shared_ptr<IndoorOutdoorInd >*>(other);
    return indoor_outdoor_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_move(data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind, data_collection_model_indoor_outdoor_ind_t *other)
{
    std::shared_ptr<IndoorOutdoorInd > &obj = *reinterpret_cast<std::shared_ptr<IndoorOutdoorInd >*>(indoor_outdoor_ind);
    obj = std::move(*reinterpret_cast<std::shared_ptr<IndoorOutdoorInd >*>(other));
    return indoor_outdoor_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_indoor_outdoor_ind_free(data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind)
{
    delete reinterpret_cast<std::shared_ptr<IndoorOutdoorInd >*>(indoor_outdoor_ind);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_indoor_outdoor_ind_toJSON(const data_collection_model_indoor_outdoor_ind_t *indoor_outdoor_ind, bool as_request)
{
    const std::shared_ptr<IndoorOutdoorInd > &obj = *reinterpret_cast<const std::shared_ptr<IndoorOutdoorInd >*>(indoor_outdoor_ind);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_indoor_outdoor_ind_t *data_collection_model_indoor_outdoor_ind_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_indoor_outdoor_ind_t*>(new std::shared_ptr<IndoorOutdoorInd >(new IndoorOutdoorInd(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_indoor_outdoor_ind_is_equal_to(const data_collection_model_indoor_outdoor_ind_t *first, const data_collection_model_indoor_outdoor_ind_t *second)
{
    const std::shared_ptr<IndoorOutdoorInd > &obj1 = *reinterpret_cast<const std::shared_ptr<IndoorOutdoorInd >*>(first);
    const std::shared_ptr<IndoorOutdoorInd > &obj2 = *reinterpret_cast<const std::shared_ptr<IndoorOutdoorInd >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_indoor_outdoor_ind_is_not_set(const data_collection_model_indoor_outdoor_ind_t *obj_indoor_outdoor_ind)
{
    const std::shared_ptr<IndoorOutdoorInd > &obj = *reinterpret_cast<const std::shared_ptr<IndoorOutdoorInd >*>(obj_indoor_outdoor_ind);
    return obj->getValue() == IndoorOutdoorInd::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_indoor_outdoor_ind_is_non_standard(const data_collection_model_indoor_outdoor_ind_t *obj_indoor_outdoor_ind)
{
    const std::shared_ptr<IndoorOutdoorInd > &obj = *reinterpret_cast<const std::shared_ptr<IndoorOutdoorInd >*>(obj_indoor_outdoor_ind);
    return obj->getValue() == IndoorOutdoorInd::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_indoor_outdoor_ind_e data_collection_model_indoor_outdoor_ind_get_enum(const data_collection_model_indoor_outdoor_ind_t *obj_indoor_outdoor_ind)
{
    const std::shared_ptr<IndoorOutdoorInd > &obj = *reinterpret_cast<const std::shared_ptr<IndoorOutdoorInd >*>(obj_indoor_outdoor_ind);
    switch (obj->getValue()) {
    case IndoorOutdoorInd::Enum::NO_VAL:
        return DCM_INDOOR_OUTDOOR_IND_NO_VAL;
    case IndoorOutdoorInd::Enum::VAL_INDOOR:
        return DCM_INDOOR_OUTDOOR_IND_VAL_INDOOR;
    case IndoorOutdoorInd::Enum::VAL_OUTDOOR:
        return DCM_INDOOR_OUTDOOR_IND_VAL_OUTDOOR;
    default:
        break;
    }
    return DCM_INDOOR_OUTDOOR_IND_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_indoor_outdoor_ind_get_string(const data_collection_model_indoor_outdoor_ind_t *obj_indoor_outdoor_ind)
{
    const std::shared_ptr<IndoorOutdoorInd > &obj = *reinterpret_cast<const std::shared_ptr<IndoorOutdoorInd >*>(obj_indoor_outdoor_ind);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_indoor_outdoor_ind_set_enum(data_collection_model_indoor_outdoor_ind_t *obj_indoor_outdoor_ind, data_collection_model_indoor_outdoor_ind_e p_value)
{
    std::shared_ptr<IndoorOutdoorInd > &obj = *reinterpret_cast<std::shared_ptr<IndoorOutdoorInd >*>(obj_indoor_outdoor_ind);
    switch (p_value) {
    case DCM_INDOOR_OUTDOOR_IND_NO_VAL:
        *obj = IndoorOutdoorInd::Enum::NO_VAL;
        return true;
    case DCM_INDOOR_OUTDOOR_IND_VAL_INDOOR:
        *obj = IndoorOutdoorInd::Enum::VAL_INDOOR;
        return true;
    case DCM_INDOOR_OUTDOOR_IND_VAL_OUTDOOR:
        *obj = IndoorOutdoorInd::Enum::VAL_OUTDOOR;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_indoor_outdoor_ind_set_string(data_collection_model_indoor_outdoor_ind_t *obj_indoor_outdoor_ind, const char *p_value)
{
    std::shared_ptr<IndoorOutdoorInd > &obj = *reinterpret_cast<std::shared_ptr<IndoorOutdoorInd >*>(obj_indoor_outdoor_ind);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = IndoorOutdoorInd::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_indoor_outdoor_ind_make_lnode(data_collection_model_indoor_outdoor_ind_t *p_indoor_outdoor_ind)
{
    return data_collection_lnode_create(p_indoor_outdoor_ind, reinterpret_cast<void(*)(void*)>(data_collection_model_indoor_outdoor_ind_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_indoor_outdoor_ind_refcount(data_collection_model_indoor_outdoor_ind_t *obj_indoor_outdoor_ind)
{
    std::shared_ptr<IndoorOutdoorInd > &obj = *reinterpret_cast<std::shared_ptr<IndoorOutdoorInd >*>(obj_indoor_outdoor_ind);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

