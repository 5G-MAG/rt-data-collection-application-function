/**********************************************************************************************************************************
 * LosNlosMeasureInd - C interface to the LosNlosMeasureInd object
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

/*#include "LosNlosMeasureInd.h" already included by data-collection-sp/data-collection.h */
#include "LosNlosMeasureInd-internal.h"
#include "openapi/model/LosNlosMeasureInd.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_create()
{
    return reinterpret_cast<data_collection_model_los_nlos_measure_ind_t*>(new std::shared_ptr<LosNlosMeasureInd>(new LosNlosMeasureInd()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_create_copy(const data_collection_model_los_nlos_measure_ind_t *other)
{
    return reinterpret_cast<data_collection_model_los_nlos_measure_ind_t*>(new std::shared_ptr<LosNlosMeasureInd >(new LosNlosMeasureInd(**reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_create_move(data_collection_model_los_nlos_measure_ind_t *other)
{
    return reinterpret_cast<data_collection_model_los_nlos_measure_ind_t*>(new std::shared_ptr<LosNlosMeasureInd >(std::move(*reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_copy(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, const data_collection_model_los_nlos_measure_ind_t *other)
{
    std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(los_nlos_measure_ind);
    *obj = **reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(other);
    return los_nlos_measure_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_move(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, data_collection_model_los_nlos_measure_ind_t *other)
{
    std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(los_nlos_measure_ind);
    obj = std::move(*reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(other));
    return los_nlos_measure_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_los_nlos_measure_ind_free(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind)
{
    delete reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(los_nlos_measure_ind);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_los_nlos_measure_ind_toJSON(const data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, bool as_request)
{
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(los_nlos_measure_ind);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_los_nlos_measure_ind_t*>(new std::shared_ptr<LosNlosMeasureInd >(new LosNlosMeasureInd(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_los_nlos_measure_ind_is_equal_to(const data_collection_model_los_nlos_measure_ind_t *first, const data_collection_model_los_nlos_measure_ind_t *second)
{
    const std::shared_ptr<LosNlosMeasureInd > &obj1 = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(first);
    const std::shared_ptr<LosNlosMeasureInd > &obj2 = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_is_not_set(const data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind)
{
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    return obj->getValue() == LosNlosMeasureInd::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_is_non_standard(const data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind)
{
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    return obj->getValue() == LosNlosMeasureInd::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_e data_collection_model_los_nlos_measure_ind_get_enum(const data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind)
{
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    switch (obj->getValue()) {
    case LosNlosMeasureInd::Enum::NO_VAL:
        return DCM_LOS_NLOS_MEASURE_IND_NO_VAL;
    case LosNlosMeasureInd::Enum::VAL_LOS:
        return DCM_LOS_NLOS_MEASURE_IND_VAL_LOS;
    case LosNlosMeasureInd::Enum::VAL_NLOS:
        return DCM_LOS_NLOS_MEASURE_IND_VAL_NLOS;
    default:
        break;
    }
    return DCM_LOS_NLOS_MEASURE_IND_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_los_nlos_measure_ind_get_string(const data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind)
{
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_set_enum(data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind, data_collection_model_los_nlos_measure_ind_e p_value)
{
    std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    switch (p_value) {
    case DCM_LOS_NLOS_MEASURE_IND_NO_VAL:
        *obj = LosNlosMeasureInd::Enum::NO_VAL;
        return true;
    case DCM_LOS_NLOS_MEASURE_IND_VAL_LOS:
        *obj = LosNlosMeasureInd::Enum::VAL_LOS;
        return true;
    case DCM_LOS_NLOS_MEASURE_IND_VAL_NLOS:
        *obj = LosNlosMeasureInd::Enum::VAL_NLOS;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_set_string(data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind, const char *p_value)
{
    std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = LosNlosMeasureInd::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_los_nlos_measure_ind_make_lnode(data_collection_model_los_nlos_measure_ind_t *p_los_nlos_measure_ind)
{
    return data_collection_lnode_create(p_los_nlos_measure_ind, reinterpret_cast<void(*)(void*)>(data_collection_model_los_nlos_measure_ind_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_los_nlos_measure_ind_refcount(data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind)
{
    std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

