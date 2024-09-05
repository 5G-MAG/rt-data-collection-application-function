/**********************************************************************************************************************************
 * GNSSAssistDataInfo - C interface to the GNSSAssistDataInfo object
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

/*#include "GNSSAssistDataInfo.h" already included by data-collection-sp/data-collection.h */
#include "GNSSAssistDataInfo-internal.h"
#include "openapi/model/GNSSAssistDataInfo.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create(


)
{
    return reinterpret_cast<data_collection_model_gnss_assist_data_info_t*>(new std::shared_ptr<GNSSAssistDataInfo>(new GNSSAssistDataInfo(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create_copy(const data_collection_model_gnss_assist_data_info_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_gnss_assist_data_info_t*>(new std::shared_ptr<GNSSAssistDataInfo >(new GNSSAssistDataInfo(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create_move(data_collection_model_gnss_assist_data_info_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > *obj = reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_copy(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const data_collection_model_gnss_assist_data_info_t *other)
{
    if (gnss_assist_data_info) {
        std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(gnss_assist_data_info);
        if (obj) {
            if (other) {
                const std::shared_ptr<GNSSAssistDataInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(other);
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
                const std::shared_ptr<GNSSAssistDataInfo > &other_obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(other);
                if (other_obj) {
                    obj.reset(new GNSSAssistDataInfo(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        gnss_assist_data_info = data_collection_model_gnss_assist_data_info_create_copy(other);
    }
    return gnss_assist_data_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_move(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, data_collection_model_gnss_assist_data_info_t *other)
{
    std::shared_ptr<GNSSAssistDataInfo > *other_ptr = reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(other);

    if (gnss_assist_data_info) {
        std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(gnss_assist_data_info);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                gnss_assist_data_info = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return gnss_assist_data_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnss_assist_data_info_free(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info)
{
    if (!gnss_assist_data_info) return;
    delete reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(gnss_assist_data_info);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnss_assist_data_info_toJSON(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, bool as_request)
{
    if (!gnss_assist_data_info) return NULL;
    const std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(gnss_assist_data_info);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_gnss_assist_data_info_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_gnss_assist_data_info_t*>(new std::shared_ptr<GNSSAssistDataInfo >(new GNSSAssistDataInfo(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_assist_data_info_is_equal_to(const data_collection_model_gnss_assist_data_info_t *first, const data_collection_model_gnss_assist_data_info_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<GNSSAssistDataInfo > &obj2 = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<GNSSAssistDataInfo > &obj1 = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_gnss_assist_data_info_get_gnss_assist_data(const data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info)
{
    if (!obj_gnss_assist_data_info) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename GNSSAssistDataInfo::GnssAssistDataType ResultFromType;
    const ResultFromType result_from = obj->getGnssAssistData();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_gnss_assist_data(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, const char* p_gnss_assist_data)
{
    if (!obj_gnss_assist_data_info) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    if (!obj) return NULL;

    const auto &value_from = p_gnss_assist_data;
    typedef typename GNSSAssistDataInfo::GnssAssistDataType ValueType;

    ValueType value(value_from);

    if (!obj->setGnssAssistData(value)) return NULL;

    return obj_gnss_assist_data_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_gnss_assist_data_move(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, char* p_gnss_assist_data)
{
    if (!obj_gnss_assist_data_info) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    if (!obj) return NULL;

    const auto &value_from = p_gnss_assist_data;
    typedef typename GNSSAssistDataInfo::GnssAssistDataType ValueType;

    ValueType value(value_from);

    
    if (!obj->setGnssAssistData(std::move(value))) return NULL;

    return obj_gnss_assist_data_info;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_gnss_serv_area_t* data_collection_model_gnss_assist_data_info_get_serv_area(const data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info)
{
    if (!obj_gnss_assist_data_info) {
        const data_collection_model_gnss_serv_area_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    if (!obj) {
        const data_collection_model_gnss_serv_area_t *result = NULL;
        return result;
    }

    typedef typename GNSSAssistDataInfo::ServAreaType ResultFromType;
    const ResultFromType result_from = obj->getServArea();
    const data_collection_model_gnss_serv_area_t *result = reinterpret_cast<const data_collection_model_gnss_serv_area_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_serv_area(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, const data_collection_model_gnss_serv_area_t* p_serv_area)
{
    if (!obj_gnss_assist_data_info) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    if (!obj) return NULL;

    const auto &value_from = p_serv_area;
    typedef typename GNSSAssistDataInfo::ServAreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setServArea(value)) return NULL;

    return obj_gnss_assist_data_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_serv_area_move(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, data_collection_model_gnss_serv_area_t* p_serv_area)
{
    if (!obj_gnss_assist_data_info) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    if (!obj) return NULL;

    const auto &value_from = p_serv_area;
    typedef typename GNSSAssistDataInfo::ServAreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    
    if (!obj->setServArea(std::move(value))) return NULL;

    return obj_gnss_assist_data_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_assist_data_info_has_source_info(const data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info)
{
    if (!obj_gnss_assist_data_info) return false;

    const std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    if (!obj) return false;

    return obj->getSourceInfo().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographical_coordinates_t* data_collection_model_gnss_assist_data_info_get_source_info(const data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info)
{
    if (!obj_gnss_assist_data_info) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    if (!obj) {
        const data_collection_model_geographical_coordinates_t *result = NULL;
        return result;
    }

    typedef typename GNSSAssistDataInfo::SourceInfoType ResultFromType;
    const ResultFromType result_from = obj->getSourceInfo();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_source_info(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, const data_collection_model_geographical_coordinates_t* p_source_info)
{
    if (!obj_gnss_assist_data_info) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    if (!obj) return NULL;

    const auto &value_from = p_source_info;
    typedef typename GNSSAssistDataInfo::SourceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setSourceInfo(value)) return NULL;

    return obj_gnss_assist_data_info;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_source_info_move(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, data_collection_model_geographical_coordinates_t* p_source_info)
{
    if (!obj_gnss_assist_data_info) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    if (!obj) return NULL;

    const auto &value_from = p_source_info;
    typedef typename GNSSAssistDataInfo::SourceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setSourceInfo(std::move(value))) return NULL;

    return obj_gnss_assist_data_info;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnss_assist_data_info_make_lnode(data_collection_model_gnss_assist_data_info_t *p_gnss_assist_data_info)
{
    return data_collection_lnode_create(p_gnss_assist_data_info, reinterpret_cast<void(*)(void*)>(data_collection_model_gnss_assist_data_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_gnss_assist_data_info_refcount(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info)
{
    if (!obj_gnss_assist_data_info) return 0l;
    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

