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

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "DatVolTransTimeCollection.h" already included by data-collection-sp/data-collection.h */
#include "DatVolTransTimeCollection-internal.h"
#include "openapi/model/DatVolTransTimeCollection.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create(







)
{
    return reinterpret_cast<data_collection_model_dat_vol_trans_time_collection_t*>(new std::shared_ptr<DatVolTransTimeCollection>(new DatVolTransTimeCollection(







)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create_ref(const data_collection_model_dat_vol_trans_time_collection_t *other)
{
    return reinterpret_cast<data_collection_model_dat_vol_trans_time_collection_t*>(new std::shared_ptr<DatVolTransTimeCollection>(*reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create_copy(const data_collection_model_dat_vol_trans_time_collection_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_dat_vol_trans_time_collection_t*>(new std::shared_ptr<DatVolTransTimeCollection >(new DatVolTransTimeCollection(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create_move(data_collection_model_dat_vol_trans_time_collection_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > *obj = reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_copy(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_dat_vol_trans_time_collection_t *other)
{
    if (dat_vol_trans_time_collection) {
        std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(dat_vol_trans_time_collection);
        if (obj) {
            if (other) {
                const std::shared_ptr<DatVolTransTimeCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(other);
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
                const std::shared_ptr<DatVolTransTimeCollection > &other_obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(other);
                if (other_obj) {
                    obj.reset(new DatVolTransTimeCollection(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        dat_vol_trans_time_collection = data_collection_model_dat_vol_trans_time_collection_create_copy(other);
    }
    return dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, data_collection_model_dat_vol_trans_time_collection_t *other)
{
    std::shared_ptr<DatVolTransTimeCollection > *other_ptr = reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(other);

    if (dat_vol_trans_time_collection) {
        std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(dat_vol_trans_time_collection);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                dat_vol_trans_time_collection = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dat_vol_trans_time_collection_free(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection)
{
    if (!dat_vol_trans_time_collection) return;
    delete reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(dat_vol_trans_time_collection);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dat_vol_trans_time_collection_toJSON(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, bool as_request)
{
    if (!dat_vol_trans_time_collection) return NULL;
    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(dat_vol_trans_time_collection);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_dat_vol_trans_time_collection_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_is_equal_to(const data_collection_model_dat_vol_trans_time_collection_t *first, const data_collection_model_dat_vol_trans_time_collection_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DatVolTransTimeCollection > &obj2 = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DatVolTransTimeCollection > &obj1 = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_app_id(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) return false;

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return false;

    return obj->getAppId().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dat_vol_trans_time_collection_get_app_id(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DatVolTransTimeCollection::AppIdType ResultFromType;
    const ResultFromType &result_from = obj->getAppId();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_id(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const char* p_app_id)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename DatVolTransTimeCollection::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(value)) return NULL;

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_id_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, char* p_app_id)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_app_id;
    typedef typename DatVolTransTimeCollection::AppIdType ValueType;

    ValueType value(value_from);

    if (!obj->setAppId(std::move(value))) return NULL;
    ogs_free
(p_app_id);

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_app_server_inst(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) return false;

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return false;

    return obj->getAppServerInst().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_dat_vol_trans_time_collection_get_app_server_inst(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) {
        const data_collection_model_addr_fqdn_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) {
        const data_collection_model_addr_fqdn_t *result = NULL;
        return result;
    }

    typedef typename DatVolTransTimeCollection::AppServerInstType ResultFromType;
    const ResultFromType &result_from = obj->getAppServerInst();
    const data_collection_model_addr_fqdn_t *result = reinterpret_cast<const data_collection_model_addr_fqdn_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_server_inst(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const data_collection_model_addr_fqdn_t* p_app_server_inst)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_app_server_inst;
    typedef typename DatVolTransTimeCollection::AppServerInstType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setAppServerInst(value)) return NULL;

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_server_inst_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, data_collection_model_addr_fqdn_t* p_app_server_inst)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_app_server_inst;
    typedef typename DatVolTransTimeCollection::AppServerInstType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setAppServerInst(std::move(value))) return NULL;
    data_collection_model_addr_fqdn_free
(p_app_server_inst);

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_gpsi(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) return false;

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return false;

    return obj->getGpsi().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dat_vol_trans_time_collection_get_gpsi(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DatVolTransTimeCollection::GpsiType ResultFromType;
    const ResultFromType &result_from = obj->getGpsi();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_gpsi(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const char* p_gpsi)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_gpsi;
    typedef typename DatVolTransTimeCollection::GpsiType ValueType;

    ValueType value(value_from);

    if (!obj->setGpsi(value)) return NULL;

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_gpsi_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, char* p_gpsi)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_gpsi;
    typedef typename DatVolTransTimeCollection::GpsiType ValueType;

    ValueType value(value_from);

    if (!obj->setGpsi(std::move(value))) return NULL;
    ogs_free
(p_gpsi);

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_supi(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) return false;

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return false;

    return obj->getSupi().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dat_vol_trans_time_collection_get_supi(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename DatVolTransTimeCollection::SupiType ResultFromType;
    const ResultFromType &result_from = obj->getSupi();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_supi(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const char* p_supi)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_supi;
    typedef typename DatVolTransTimeCollection::SupiType ValueType;

    ValueType value(value_from);

    if (!obj->setSupi(value)) return NULL;

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_supi_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, char* p_supi)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_supi;
    typedef typename DatVolTransTimeCollection::SupiType ValueType;

    ValueType value(value_from);

    if (!obj->setSupi(std::move(value))) return NULL;
    ogs_free
(p_supi);

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_ul_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) return false;

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return false;

    return obj->getUlTransVol().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_dat_vol_trans_time_collection_get_ul_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) {
        const int64_t result = 0;
        return result;
    }

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) {
        const int64_t result = 0;
        return result;
    }

    typedef typename DatVolTransTimeCollection::UlTransVolType ResultFromType;
    const ResultFromType &result_from = obj->getUlTransVol();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_vol(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const int64_t p_ul_trans_vol)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ul_trans_vol;
    typedef typename DatVolTransTimeCollection::UlTransVolType ValueType;

    ValueType value(value_from);

    if (!obj->setUlTransVol(value)) return NULL;

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_vol_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, int64_t p_ul_trans_vol)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ul_trans_vol;
    typedef typename DatVolTransTimeCollection::UlTransVolType ValueType;

    ValueType value(value_from);

    if (!obj->setUlTransVol(std::move(value))) return NULL;

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_dl_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) return false;

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return false;

    return obj->getDlTransVol().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_dat_vol_trans_time_collection_get_dl_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) {
        const int64_t result = 0;
        return result;
    }

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) {
        const int64_t result = 0;
        return result;
    }

    typedef typename DatVolTransTimeCollection::DlTransVolType ResultFromType;
    const ResultFromType &result_from = obj->getDlTransVol();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_vol(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const int64_t p_dl_trans_vol)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_dl_trans_vol;
    typedef typename DatVolTransTimeCollection::DlTransVolType ValueType;

    ValueType value(value_from);

    if (!obj->setDlTransVol(value)) return NULL;

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_vol_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, int64_t p_dl_trans_vol)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_dl_trans_vol;
    typedef typename DatVolTransTimeCollection::DlTransVolType ValueType;

    ValueType value(value_from);

    if (!obj->setDlTransVol(std::move(value))) return NULL;

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_ul_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) return false;

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return false;

    return obj->getUlTransTimeDur().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_dat_vol_trans_time_collection_get_ul_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    typedef typename DatVolTransTimeCollection::UlTransTimeDurType ResultFromType;
    const ResultFromType &result_from = obj->getUlTransTimeDur();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_time_dur(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const data_collection_model_time_window_t* p_ul_trans_time_dur)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ul_trans_time_dur;
    typedef typename DatVolTransTimeCollection::UlTransTimeDurType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setUlTransTimeDur(value)) return NULL;

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_time_dur_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, data_collection_model_time_window_t* p_ul_trans_time_dur)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_ul_trans_time_dur;
    typedef typename DatVolTransTimeCollection::UlTransTimeDurType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setUlTransTimeDur(std::move(value))) return NULL;
    data_collection_model_time_window_free
(p_ul_trans_time_dur);

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_dl_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) return false;

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return false;

    return obj->getDlTransTimeDur().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_dat_vol_trans_time_collection_get_dl_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    const std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<const std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) {
        const data_collection_model_time_window_t *result = NULL;
        return result;
    }

    typedef typename DatVolTransTimeCollection::DlTransTimeDurType ResultFromType;
    const ResultFromType &result_from = obj->getDlTransTimeDur();
    const data_collection_model_time_window_t *result = reinterpret_cast<const data_collection_model_time_window_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_time_dur(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, const data_collection_model_time_window_t* p_dl_trans_time_dur)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_dl_trans_time_dur;
    typedef typename DatVolTransTimeCollection::DlTransTimeDurType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setDlTransTimeDur(value)) return NULL;

    return obj_dat_vol_trans_time_collection;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_time_dur_move(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection, data_collection_model_time_window_t* p_dl_trans_time_dur)
{
    if (!obj_dat_vol_trans_time_collection) return NULL;

    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    if (!obj) return NULL;

    const auto &value_from = p_dl_trans_time_dur;
    typedef typename DatVolTransTimeCollection::DlTransTimeDurType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setDlTransTimeDur(std::move(value))) return NULL;
    data_collection_model_time_window_free
(p_dl_trans_time_dur);

    return obj_dat_vol_trans_time_collection;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dat_vol_trans_time_collection_make_lnode(data_collection_model_dat_vol_trans_time_collection_t *p_dat_vol_trans_time_collection)
{
    return data_collection_lnode_create(p_dat_vol_trans_time_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_dat_vol_trans_time_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_dat_vol_trans_time_collection_refcount(data_collection_model_dat_vol_trans_time_collection_t *obj_dat_vol_trans_time_collection)
{
    if (!obj_dat_vol_trans_time_collection) return 0l;
    std::shared_ptr<DatVolTransTimeCollection > &obj = *reinterpret_cast<std::shared_ptr<DatVolTransTimeCollection >*>(obj_dat_vol_trans_time_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

