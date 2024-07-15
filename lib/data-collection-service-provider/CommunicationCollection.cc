/**********************************************************************************************************************************
 * CommunicationCollection - C interface to the CommunicationCollection object
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

/*#include "CommunicationCollection.h" already included by data-collection-sp/data-collection.h */
#include "CommunicationCollection-internal.h"
#include "openapi/model/CommunicationCollection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_create(



)
{
    return reinterpret_cast<data_collection_model_communication_collection_t*>(new std::shared_ptr<CommunicationCollection>(new CommunicationCollection(



)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_create_copy(const data_collection_model_communication_collection_t *other)
{
    return reinterpret_cast<data_collection_model_communication_collection_t*>(new std::shared_ptr<CommunicationCollection >(new CommunicationCollection(**reinterpret_cast<const std::shared_ptr<CommunicationCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_create_move(data_collection_model_communication_collection_t *other)
{
    return reinterpret_cast<data_collection_model_communication_collection_t*>(new std::shared_ptr<CommunicationCollection >(std::move(*reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_copy(data_collection_model_communication_collection_t *communication_collection, const data_collection_model_communication_collection_t *other)
{
    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(communication_collection);
    *obj = **reinterpret_cast<const std::shared_ptr<CommunicationCollection >*>(other);
    return communication_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_move(data_collection_model_communication_collection_t *communication_collection, data_collection_model_communication_collection_t *other)
{
    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(communication_collection);
    obj = std::move(*reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(other));
    return communication_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_communication_collection_free(data_collection_model_communication_collection_t *communication_collection)
{
    delete reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(communication_collection);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_communication_collection_toJSON(const data_collection_model_communication_collection_t *communication_collection, bool as_request)
{
    const std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationCollection >*>(communication_collection);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_communication_collection_t*>(new std::shared_ptr<CommunicationCollection >(new CommunicationCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_communication_collection_get_start_time(const data_collection_model_communication_collection_t *obj_communication_collection)
{
    const std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    typedef typename CommunicationCollection::StartTimeType ResultFromType;
    const ResultFromType result_from = obj->getStartTime();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_start_time(data_collection_model_communication_collection_t *obj_communication_collection, const char* p_start_time)
{
    if (obj_communication_collection == NULL) return NULL;

    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    const auto &value_from = p_start_time;
    typedef typename CommunicationCollection::StartTimeType ValueType;

    ValueType value(value_from);
    if (!obj->setStartTime(value)) return NULL;
    return obj_communication_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_start_time_move(data_collection_model_communication_collection_t *obj_communication_collection, char* p_start_time)
{
    if (obj_communication_collection == NULL) return NULL;

    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    const auto &value_from = p_start_time;
    typedef typename CommunicationCollection::StartTimeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setStartTime(std::move(value))) return NULL;
    return obj_communication_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_communication_collection_get_end_time(const data_collection_model_communication_collection_t *obj_communication_collection)
{
    const std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    typedef typename CommunicationCollection::EndTimeType ResultFromType;
    const ResultFromType result_from = obj->getEndTime();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_end_time(data_collection_model_communication_collection_t *obj_communication_collection, const char* p_end_time)
{
    if (obj_communication_collection == NULL) return NULL;

    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    const auto &value_from = p_end_time;
    typedef typename CommunicationCollection::EndTimeType ValueType;

    ValueType value(value_from);
    if (!obj->setEndTime(value)) return NULL;
    return obj_communication_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_end_time_move(data_collection_model_communication_collection_t *obj_communication_collection, char* p_end_time)
{
    if (obj_communication_collection == NULL) return NULL;

    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    const auto &value_from = p_end_time;
    typedef typename CommunicationCollection::EndTimeType ValueType;

    ValueType value(value_from);
    
    if (!obj->setEndTime(std::move(value))) return NULL;
    return obj_communication_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int64_t data_collection_model_communication_collection_get_ul_vol(const data_collection_model_communication_collection_t *obj_communication_collection)
{
    const std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    typedef typename CommunicationCollection::UlVolType ResultFromType;
    const ResultFromType result_from = obj->getUlVol();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_ul_vol(data_collection_model_communication_collection_t *obj_communication_collection, const int64_t p_ul_vol)
{
    if (obj_communication_collection == NULL) return NULL;

    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    const auto &value_from = p_ul_vol;
    typedef typename CommunicationCollection::UlVolType ValueType;

    ValueType value = value_from;
    if (!obj->setUlVol(value)) return NULL;
    return obj_communication_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_ul_vol_move(data_collection_model_communication_collection_t *obj_communication_collection, int64_t p_ul_vol)
{
    if (obj_communication_collection == NULL) return NULL;

    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    const auto &value_from = p_ul_vol;
    typedef typename CommunicationCollection::UlVolType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUlVol(std::move(value))) return NULL;
    return obj_communication_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int64_t data_collection_model_communication_collection_get_dl_vol(const data_collection_model_communication_collection_t *obj_communication_collection)
{
    const std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<const std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    typedef typename CommunicationCollection::DlVolType ResultFromType;
    const ResultFromType result_from = obj->getDlVol();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_dl_vol(data_collection_model_communication_collection_t *obj_communication_collection, const int64_t p_dl_vol)
{
    if (obj_communication_collection == NULL) return NULL;

    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    const auto &value_from = p_dl_vol;
    typedef typename CommunicationCollection::DlVolType ValueType;

    ValueType value = value_from;
    if (!obj->setDlVol(value)) return NULL;
    return obj_communication_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_communication_collection_t *data_collection_model_communication_collection_set_dl_vol_move(data_collection_model_communication_collection_t *obj_communication_collection, int64_t p_dl_vol)
{
    if (obj_communication_collection == NULL) return NULL;

    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    const auto &value_from = p_dl_vol;
    typedef typename CommunicationCollection::DlVolType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDlVol(std::move(value))) return NULL;
    return obj_communication_collection;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_communication_collection_make_lnode(data_collection_model_communication_collection_t *p_communication_collection)
{
    return data_collection_lnode_create(p_communication_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_communication_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_communication_collection_refcount(data_collection_model_communication_collection_t *obj_communication_collection)
{
    std::shared_ptr<CommunicationCollection > &obj = *reinterpret_cast<std::shared_ptr<CommunicationCollection >*>(obj_communication_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

