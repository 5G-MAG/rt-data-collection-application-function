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

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "LosNlosMeasureInd.h" already included by data-collection-sp/data-collection.h */
#include "LosNlosMeasureInd-internal.h"
#include "openapi/model/LosNlosMeasureInd.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_create()
{
    return reinterpret_cast<data_collection_model_los_nlos_measure_ind_t*>(new std::shared_ptr<LosNlosMeasureInd>(new LosNlosMeasureInd()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_create_copy(const data_collection_model_los_nlos_measure_ind_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_los_nlos_measure_ind_t*>(new std::shared_ptr<LosNlosMeasureInd >(new LosNlosMeasureInd(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_create_move(data_collection_model_los_nlos_measure_ind_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<LosNlosMeasureInd > *obj = reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_copy(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, const data_collection_model_los_nlos_measure_ind_t *other)
{
    if (los_nlos_measure_ind) {
        std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(los_nlos_measure_ind);
        if (obj) {
            if (other) {
                const std::shared_ptr<LosNlosMeasureInd > &other_obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(other);
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
                const std::shared_ptr<LosNlosMeasureInd > &other_obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(other);
                if (other_obj) {
                    obj.reset(new LosNlosMeasureInd(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        los_nlos_measure_ind = data_collection_model_los_nlos_measure_ind_create_copy(other);
    }
    return los_nlos_measure_ind;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_move(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, data_collection_model_los_nlos_measure_ind_t *other)
{
    std::shared_ptr<LosNlosMeasureInd > *other_ptr = reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(other);

    if (los_nlos_measure_ind) {
        std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(los_nlos_measure_ind);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                los_nlos_measure_ind = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return los_nlos_measure_ind;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_los_nlos_measure_ind_free(data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind)
{
    if (!los_nlos_measure_ind) return;
    delete reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(los_nlos_measure_ind);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_los_nlos_measure_ind_toJSON(const data_collection_model_los_nlos_measure_ind_t *los_nlos_measure_ind, bool as_request)
{
    if (!los_nlos_measure_ind) return NULL;
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(los_nlos_measure_ind);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_los_nlos_measure_ind_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_t *data_collection_model_los_nlos_measure_ind_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_is_equal_to(const data_collection_model_los_nlos_measure_ind_t *first, const data_collection_model_los_nlos_measure_ind_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<LosNlosMeasureInd > &obj2 = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<LosNlosMeasureInd > &obj1 = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_is_not_set(const data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind)
{
    if (!obj_los_nlos_measure_ind) return true;
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    if (!obj) return true;
    return obj->getValue() == LosNlosMeasureInd::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_is_non_standard(const data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind)
{
    if (!obj_los_nlos_measure_ind) return false;
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    if (!obj) return false;
    return obj->getValue() == LosNlosMeasureInd::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_los_nlos_measure_ind_e data_collection_model_los_nlos_measure_ind_get_enum(const data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind)
{
    if (!obj_los_nlos_measure_ind)
        return DCM_LOS_NLOS_MEASURE_IND_NO_VAL;
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    if (!obj) return DCM_LOS_NLOS_MEASURE_IND_NO_VAL;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_los_nlos_measure_ind_get_string(const data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind)
{
    if (!obj_los_nlos_measure_ind) return NULL;
    const std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<const std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_set_enum(data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind, data_collection_model_los_nlos_measure_ind_e p_value)
{
    if (!obj_los_nlos_measure_ind) return false;
    std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    if (!obj) return false;
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_los_nlos_measure_ind_set_string(data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind, const char *p_value)
{
    if (!obj_los_nlos_measure_ind) return false;
    std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = LosNlosMeasureInd::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_los_nlos_measure_ind_make_lnode(data_collection_model_los_nlos_measure_ind_t *p_los_nlos_measure_ind)
{
    return data_collection_lnode_create(p_los_nlos_measure_ind, reinterpret_cast<void(*)(void*)>(data_collection_model_los_nlos_measure_ind_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_los_nlos_measure_ind_refcount(data_collection_model_los_nlos_measure_ind_t *obj_los_nlos_measure_ind)
{
    if (!obj_los_nlos_measure_ind) return 0l;
    std::shared_ptr<LosNlosMeasureInd > &obj = *reinterpret_cast<std::shared_ptr<LosNlosMeasureInd >*>(obj_los_nlos_measure_ind);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

