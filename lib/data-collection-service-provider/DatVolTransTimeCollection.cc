/**********************************************************************************************************************************
 * DatVolTransTimeCollection - C interface to the DatVolTransTimeCollection object
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

/*#include "DatVolTransTimeCollection.h" already included by data-collection-sp/data-collection.h */
#include "DatVolTransTimeCollection-internal.h"
#include "openapi/model/DatVolTransTimeCollection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create(







)
{
    return reinterpret_cast<data_collection_model_dat_vol_trans_time_collection_t*>(new std::shared_ptr<DatVolTransTimeCollection>(new DatVolTransTimeCollection(







)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create_copy(const data_collection_model_dat_vol_trans_time_collection_t *other)
{
    return reinterpret_cast<data_collection_model_dat_vol_trans_time_collection_t*>(new std::shared_ptr<DatVolTransTimeCollection >(new DatVolTransTimeCollection(**reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create_move(data_collection_model_dat_vol_trans_time_collection_t *other)
{
    return reinterpret_cast<data_collection_model_dat_vol_trans_time_collection_t*>(new std::shared_ptr<DatVolTransTimeCollection >(std::move(*reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_copy(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_dat_vol_trans_time_collection_t *other)
{
    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(dat_vol_trans_time_collection);
    *obj = **reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(other);
    return dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, data_collection_model_dat_vol_trans_time_collection_t *other)
{
    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(dat_vol_trans_time_collection);
    obj = std::move(*reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(other));
    return dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_dat_vol_trans_time_collection_free(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection)
{
    delete reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(dat_vol_trans_time_collection);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_dat_vol_trans_time_collection_toJSON(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, bool as_request)
{
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(dat_vol_trans_time_collection);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_dat_vol_trans_time_collection_t*>(new std::shared_ptr<DatVolTransTimeCollection >(new DatVolTransTimeCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_dat_vol_trans_time_collection_is_equal_to(const data_collection_model_dat_vol_trans_time_collection_t *first, const data_collection_model_dat_vol_trans_time_collection_t *second)
{
    const std::shared_ptr<DatVolTransTimeCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(first);
    const std::shared_ptr<DatVolTransTimeCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_dat_vol_trans_time_collection_get_app_id(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    typedef typename DatVolTransTimeCollection::AppIdType ResultFromType;
    const ResultFromType result_from = obj->getAppId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_id(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const char* p_app_id)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_app_id;
    typedef typename DatVolTransTimeCollection::AppIdType ValueType;

    ValueType value(value_from);
    if (!obj->setAppId(value)) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_id_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, char* p_app_id)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_app_id;
    typedef typename DatVolTransTimeCollection::AppIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setAppId(std::move(value))) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_addr_fqdn_t* data_collection_model_dat_vol_trans_time_collection_get_app_server_inst(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    typedef typename DatVolTransTimeCollection::AppServerInstType ResultFromType;
    const ResultFromType result_from = obj->getAppServerInst();
    const data_collection_model_addr_fqdn_t *result = reinterpret_cast<const data_collection_model_addr_fqdn_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_server_inst(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const data_collection_model_addr_fqdn_t* p_app_server_inst)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_app_server_inst;
    typedef typename DatVolTransTimeCollection::AppServerInstType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setAppServerInst(value)) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_server_inst_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, data_collection_model_addr_fqdn_t* p_app_server_inst)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_app_server_inst;
    typedef typename DatVolTransTimeCollection::AppServerInstType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setAppServerInst(std::move(value))) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_dat_vol_trans_time_collection_get_gpsi(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    typedef typename DatVolTransTimeCollection::GpsiType ResultFromType;
    const ResultFromType result_from = obj->getGpsi();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_gpsi(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const char* p_gpsi)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_gpsi;
    typedef typename DatVolTransTimeCollection::GpsiType ValueType;

    ValueType value(value_from);
    if (!obj->setGpsi(value)) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_gpsi_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, char* p_gpsi)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_gpsi;
    typedef typename DatVolTransTimeCollection::GpsiType ValueType;

    ValueType value(value_from);
    
    if (!obj->setGpsi(std::move(value))) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_dat_vol_trans_time_collection_get_supi(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    typedef typename DatVolTransTimeCollection::SupiType ResultFromType;
    const ResultFromType result_from = obj->getSupi();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_supi(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const char* p_supi)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_supi;
    typedef typename DatVolTransTimeCollection::SupiType ValueType;

    ValueType value(value_from);
    if (!obj->setSupi(value)) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_supi_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, char* p_supi)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_supi;
    typedef typename DatVolTransTimeCollection::SupiType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSupi(std::move(value))) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int64_t data_collection_model_dat_vol_trans_time_collection_get_ul_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    typedef typename DatVolTransTimeCollection::UlTransVolType ResultFromType;
    const ResultFromType result_from = obj->getUlTransVol();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_vol(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const int64_t p_ul_trans_vol)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_ul_trans_vol;
    typedef typename DatVolTransTimeCollection::UlTransVolType ValueType;

    ValueType value = value_from;
    if (!obj->setUlTransVol(value)) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_vol_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, int64_t p_ul_trans_vol)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_ul_trans_vol;
    typedef typename DatVolTransTimeCollection::UlTransVolType ValueType;

    ValueType value = value_from;
    
    if (!obj->setUlTransVol(std::move(value))) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int64_t data_collection_model_dat_vol_trans_time_collection_get_dl_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    typedef typename DatVolTransTimeCollection::DlTransVolType ResultFromType;
    const ResultFromType result_from = obj->getDlTransVol();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_vol(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const int64_t p_dl_trans_vol)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_dl_trans_vol;
    typedef typename DatVolTransTimeCollection::DlTransVolType ValueType;

    ValueType value = value_from;
    if (!obj->setDlTransVol(value)) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_vol_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, int64_t p_dl_trans_vol)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_dl_trans_vol;
    typedef typename DatVolTransTimeCollection::DlTransVolType ValueType;

    ValueType value = value_from;
    
    if (!obj->setDlTransVol(std::move(value))) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_time_window_t* data_collection_model_dat_vol_trans_time_collection_get_ul_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    typedef typename DatVolTransTimeCollection::UlTransTimeDurType ResultFromType;
    const ResultFromType result_from = obj->getUlTransTimeDur();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_time_dur(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const data_collection_model_time_window_t* p_ul_trans_time_dur)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_ul_trans_time_dur;
    typedef typename DatVolTransTimeCollection::UlTransTimeDurType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUlTransTimeDur(value)) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_time_dur_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, data_collection_model_time_window_t* p_ul_trans_time_dur)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_ul_trans_time_dur;
    typedef typename DatVolTransTimeCollection::UlTransTimeDurType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUlTransTimeDur(std::move(value))) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_time_window_t* data_collection_model_dat_vol_trans_time_collection_get_dl_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    typedef typename DatVolTransTimeCollection::DlTransTimeDurType ResultFromType;
    const ResultFromType result_from = obj->getDlTransTimeDur();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_time_dur(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const data_collection_model_time_window_t* p_dl_trans_time_dur)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_dl_trans_time_dur;
    typedef typename DatVolTransTimeCollection::DlTransTimeDurType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setDlTransTimeDur(value)) return NULL;
    return obj_dat_vol_trans_time_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_time_dur_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, data_collection_model_time_window_t* p_dl_trans_time_dur)
{
    if (obj_dat_vol_trans_time_collection == NULL) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    const auto &value_from = p_dl_trans_time_dur;
    typedef typename DatVolTransTimeCollection::DlTransTimeDurType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setDlTransTimeDur(std::move(value))) return NULL;
    return obj_dat_vol_trans_time_collection;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_dat_vol_trans_time_collection_make_lnode(data_collection_model_dat_vol_trans_time_collection_t *p_dat_vol_trans_time_collection)
{
    return data_collection_lnode_create(p_dat_vol_trans_time_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_dat_vol_trans_time_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_dat_vol_trans_time_collection_refcount(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

