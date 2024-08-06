/**********************************************************************************************************************************
 * UeTrajectoryCollection - C interface to the UeTrajectoryCollection object
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

/*#include "UeTrajectoryCollection.h" already included by data-collection-sp/data-collection.h */
#include "UeTrajectoryCollection-internal.h"
#include "openapi/model/UeTrajectoryCollection.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_create(

)
{
    return reinterpret_cast<data_collection_model_ue_trajectory_collection_t*>(new std::shared_ptr<UeTrajectoryCollection>(new UeTrajectoryCollection(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_create_copy(const data_collection_model_ue_trajectory_collection_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeTrajectoryCollection >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_ue_trajectory_collection_t*>(new std::shared_ptr<UeTrajectoryCollection >(new UeTrajectoryCollection(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_create_move(data_collection_model_ue_trajectory_collection_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<UeTrajectoryCollection > *obj = reinterpret_cast<std::shared_ptr<UeTrajectoryCollection >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_copy(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, const data_collection_model_ue_trajectory_collection_t *other)
{
    if (ue_trajectory_collection) {
        std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<std::shared_ptr<UeTrajectoryCollection >*>(ue_trajectory_collection);
        if (obj) {
            if (other) {
                const std::shared_ptr<UeTrajectoryCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<UeTrajectoryCollection >*>(other);
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
                const std::shared_ptr<UeTrajectoryCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<UeTrajectoryCollection >*>(other);
                if (other_obj) {
                    obj.reset(new UeTrajectoryCollection(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        ue_trajectory_collection = data_collection_model_ue_trajectory_collection_create_copy(other);
    }
    return ue_trajectory_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_move(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, data_collection_model_ue_trajectory_collection_t *other)
{
    std::shared_ptr<UeTrajectoryCollection > *other_ptr = reinterpret_cast<std::shared_ptr<UeTrajectoryCollection >*>(other);

    if (ue_trajectory_collection) {
        std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<std::shared_ptr<UeTrajectoryCollection >*>(ue_trajectory_collection);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                ue_trajectory_collection = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return ue_trajectory_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_trajectory_collection_free(data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection)
{
    if (!ue_trajectory_collection) return;
    delete reinterpret_cast<std::shared_ptr<UeTrajectoryCollection >*>(ue_trajectory_collection);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_trajectory_collection_toJSON(const data_collection_model_ue_trajectory_collection_t *ue_trajectory_collection, bool as_request)
{
    if (!ue_trajectory_collection) return NULL;
    const std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeTrajectoryCollection >*>(ue_trajectory_collection);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ue_trajectory_collection_t*>(new std::shared_ptr<UeTrajectoryCollection >(new UeTrajectoryCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_trajectory_collection_is_equal_to(const data_collection_model_ue_trajectory_collection_t *first, const data_collection_model_ue_trajectory_collection_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<UeTrajectoryCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<UeTrajectoryCollection >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<UeTrajectoryCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<UeTrajectoryCollection >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_trajectory_collection_get_ts(const data_collection_model_ue_trajectory_collection_t *obj_ue_trajectory_collection)
{
    if (!obj_ue_trajectory_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeTrajectoryCollection >*>(obj_ue_trajectory_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UeTrajectoryCollection::TsType ResultFromType;
    const ResultFromType result_from = obj->getTs();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_ts(data_collection_model_ue_trajectory_collection_t *obj_ue_trajectory_collection, const char* p_ts)
{
    if (!obj_ue_trajectory_collection) return NULL;

    std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<std::shared_ptr<UeTrajectoryCollection >*>(obj_ue_trajectory_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ts;
    typedef typename UeTrajectoryCollection::TsType ValueType;

    ValueType value(value_from);
    if (!obj->setTs(value)) return NULL;

    return obj_ue_trajectory_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_ts_move(data_collection_model_ue_trajectory_collection_t *obj_ue_trajectory_collection, char* p_ts)
{
    if (!obj_ue_trajectory_collection) return NULL;

    std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<std::shared_ptr<UeTrajectoryCollection >*>(obj_ue_trajectory_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ts;
    typedef typename UeTrajectoryCollection::TsType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTs(std::move(value))) return NULL;

    return obj_ue_trajectory_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_location_area5_g_t* data_collection_model_ue_trajectory_collection_get_loc_area(const data_collection_model_ue_trajectory_collection_t *obj_ue_trajectory_collection)
{
    if (!obj_ue_trajectory_collection) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    const std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<const std::shared_ptr<UeTrajectoryCollection >*>(obj_ue_trajectory_collection);
    if (!obj) {
        const data_collection_model_location_area5_g_t *result = NULL;
        return result;
    }

    typedef typename UeTrajectoryCollection::LocAreaType ResultFromType;
    const ResultFromType result_from = obj->getLocArea();
    const data_collection_model_location_area5_g_t *result = reinterpret_cast<const data_collection_model_location_area5_g_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_loc_area(data_collection_model_ue_trajectory_collection_t *obj_ue_trajectory_collection, const data_collection_model_location_area5_g_t* p_loc_area)
{
    if (!obj_ue_trajectory_collection) return NULL;

    std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<std::shared_ptr<UeTrajectoryCollection >*>(obj_ue_trajectory_collection);
    if (!obj) return NULL;

    const auto &value_from = p_loc_area;
    typedef typename UeTrajectoryCollection::LocAreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocArea(value)) return NULL;

    return obj_ue_trajectory_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_trajectory_collection_t *data_collection_model_ue_trajectory_collection_set_loc_area_move(data_collection_model_ue_trajectory_collection_t *obj_ue_trajectory_collection, data_collection_model_location_area5_g_t* p_loc_area)
{
    if (!obj_ue_trajectory_collection) return NULL;

    std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<std::shared_ptr<UeTrajectoryCollection >*>(obj_ue_trajectory_collection);
    if (!obj) return NULL;

    const auto &value_from = p_loc_area;
    typedef typename UeTrajectoryCollection::LocAreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocArea(std::move(value))) return NULL;

    return obj_ue_trajectory_collection;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_trajectory_collection_make_lnode(data_collection_model_ue_trajectory_collection_t *p_ue_trajectory_collection)
{
    return data_collection_lnode_create(p_ue_trajectory_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_ue_trajectory_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ue_trajectory_collection_refcount(data_collection_model_ue_trajectory_collection_t *obj_ue_trajectory_collection)
{
    if (!obj_ue_trajectory_collection) return 0l;
    std::shared_ptr<UeTrajectoryCollection > &obj = *reinterpret_cast<std::shared_ptr<UeTrajectoryCollection >*>(obj_ue_trajectory_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

