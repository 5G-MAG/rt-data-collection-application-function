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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "GNSSAssistDataInfo.h" already included by data-collection-sp/data-collection.h */
#include "GNSSAssistDataInfo-internal.h"
#include "openapi/model/GNSSAssistDataInfo.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create(


)
{
    return reinterpret_cast<data_collection_model_gnss_assist_data_info_t*>(new std::shared_ptr<GNSSAssistDataInfo>(new GNSSAssistDataInfo(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create_copy(const data_collection_model_gnss_assist_data_info_t *other)
{
    return reinterpret_cast<data_collection_model_gnss_assist_data_info_t*>(new std::shared_ptr<GNSSAssistDataInfo >(new GNSSAssistDataInfo(**reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_create_move(data_collection_model_gnss_assist_data_info_t *other)
{
    return reinterpret_cast<data_collection_model_gnss_assist_data_info_t*>(new std::shared_ptr<GNSSAssistDataInfo >(std::move(*reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_copy(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, const data_collection_model_gnss_assist_data_info_t *other)
{
    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(gnss_assist_data_info);
    *obj = **reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(other);
    return gnss_assist_data_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_move(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, data_collection_model_gnss_assist_data_info_t *other)
{
    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(gnss_assist_data_info);
    obj = std::move(*reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(other));
    return gnss_assist_data_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_gnss_assist_data_info_free(data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info)
{
    delete reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(gnss_assist_data_info);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_gnss_assist_data_info_toJSON(const data_collection_model_gnss_assist_data_info_t *gnss_assist_data_info, bool as_request)
{
    const std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(gnss_assist_data_info);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_gnss_assist_data_info_get_gnss_assist_data(const data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info)
{
    const std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    typedef typename GNSSAssistDataInfo::GnssAssistDataType ResultFromType;
    const ResultFromType result_from = obj->getGnssAssistData();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_gnss_assist_data(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, const char* p_gnss_assist_data)
{
    if (obj_gnss_assist_data_info == NULL) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    const auto &value_from = p_gnss_assist_data;
    typedef typename GNSSAssistDataInfo::GnssAssistDataType ValueType;

    ValueType value(value_from);
    if (!obj->setGnssAssistData(value)) return NULL;
    return obj_gnss_assist_data_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_gnss_assist_data_move(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, char* p_gnss_assist_data)
{
    if (obj_gnss_assist_data_info == NULL) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    const auto &value_from = p_gnss_assist_data;
    typedef typename GNSSAssistDataInfo::GnssAssistDataType ValueType;

    ValueType value(value_from);
    
    if (!obj->setGnssAssistData(std::move(value))) return NULL;
    return obj_gnss_assist_data_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_gnss_serv_area_t* data_collection_model_gnss_assist_data_info_get_serv_area(const data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info)
{
    const std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    typedef typename GNSSAssistDataInfo::ServAreaType ResultFromType;
    const ResultFromType result_from = obj->getServArea();
    const data_collection_model_gnss_serv_area_t *result = reinterpret_cast<const data_collection_model_gnss_serv_area_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_serv_area(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, const data_collection_model_gnss_serv_area_t* p_serv_area)
{
    if (obj_gnss_assist_data_info == NULL) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    const auto &value_from = p_serv_area;
    typedef typename GNSSAssistDataInfo::ServAreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setServArea(value)) return NULL;
    return obj_gnss_assist_data_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_serv_area_move(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, data_collection_model_gnss_serv_area_t* p_serv_area)
{
    if (obj_gnss_assist_data_info == NULL) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    const auto &value_from = p_serv_area;
    typedef typename GNSSAssistDataInfo::ServAreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setServArea(std::move(value))) return NULL;
    return obj_gnss_assist_data_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_geographical_coordinates_t* data_collection_model_gnss_assist_data_info_get_source_info(const data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info)
{
    const std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<const std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    typedef typename GNSSAssistDataInfo::SourceInfoType ResultFromType;
    const ResultFromType result_from = obj->getSourceInfo();
    const data_collection_model_geographical_coordinates_t *result = reinterpret_cast<const data_collection_model_geographical_coordinates_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_source_info(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, const data_collection_model_geographical_coordinates_t* p_source_info)
{
    if (obj_gnss_assist_data_info == NULL) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    const auto &value_from = p_source_info;
    typedef typename GNSSAssistDataInfo::SourceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setSourceInfo(value)) return NULL;
    return obj_gnss_assist_data_info;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_assist_data_info_t *data_collection_model_gnss_assist_data_info_set_source_info_move(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info, data_collection_model_geographical_coordinates_t* p_source_info)
{
    if (obj_gnss_assist_data_info == NULL) return NULL;

    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    const auto &value_from = p_source_info;
    typedef typename GNSSAssistDataInfo::SourceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setSourceInfo(std::move(value))) return NULL;
    return obj_gnss_assist_data_info;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_gnss_assist_data_info_make_lnode(data_collection_model_gnss_assist_data_info_t *p_gnss_assist_data_info)
{
    return data_collection_lnode_create(p_gnss_assist_data_info, reinterpret_cast<void(*)(void*)>(data_collection_model_gnss_assist_data_info_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_gnss_assist_data_info_refcount(data_collection_model_gnss_assist_data_info_t *obj_gnss_assist_data_info)
{
    std::shared_ptr<GNSSAssistDataInfo > &obj = *reinterpret_cast<std::shared_ptr<GNSSAssistDataInfo >*>(obj_gnss_assist_data_info);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

