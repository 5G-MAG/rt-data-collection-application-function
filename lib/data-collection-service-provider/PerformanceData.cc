/**********************************************************************************************************************************
 * PerformanceData - C interface to the PerformanceData object
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

/*#include "PerformanceData.h" already included by data-collection-sp/data-collection.h */
#include "PerformanceData-internal.h"
#include "openapi/model/PerformanceData.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_create(













)
{
    return reinterpret_cast<data_collection_model_performance_data_t*>(new std::shared_ptr<PerformanceData>(new PerformanceData(













)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_create_copy(const data_collection_model_performance_data_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_performance_data_t*>(new std::shared_ptr<PerformanceData >(new PerformanceData(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_create_move(data_collection_model_performance_data_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PerformanceData > *obj = reinterpret_cast<std::shared_ptr<PerformanceData >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_copy(data_collection_model_performance_data_t *performance_data, const data_collection_model_performance_data_t *other)
{
    if (performance_data) {
        std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(performance_data);
        if (obj) {
            if (other) {
                const std::shared_ptr<PerformanceData > &other_obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(other);
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
                const std::shared_ptr<PerformanceData > &other_obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(other);
                if (other_obj) {
                    obj.reset(new PerformanceData(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        performance_data = data_collection_model_performance_data_create_copy(other);
    }
    return performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_move(data_collection_model_performance_data_t *performance_data, data_collection_model_performance_data_t *other)
{
    std::shared_ptr<PerformanceData > *other_ptr = reinterpret_cast<std::shared_ptr<PerformanceData >*>(other);

    if (performance_data) {
        std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(performance_data);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                performance_data = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_free(data_collection_model_performance_data_t *performance_data)
{
    if (!performance_data) return;
    delete reinterpret_cast<std::shared_ptr<PerformanceData >*>(performance_data);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_toJSON(const data_collection_model_performance_data_t *performance_data, bool as_request)
{
    if (!performance_data) return NULL;
    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(performance_data);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_performance_data_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_performance_data_t*>(new std::shared_ptr<PerformanceData >(new PerformanceData(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_is_equal_to(const data_collection_model_performance_data_t *first, const data_collection_model_performance_data_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PerformanceData > &obj2 = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PerformanceData > &obj1 = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_pdb(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getPdb().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_pdb(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceData::PdbType ResultFromType;
    const ResultFromType result_from = obj->getPdb();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb(data_collection_model_performance_data_t *obj_performance_data, const int32_t p_pdb)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_pdb;
    typedef typename PerformanceData::PdbType ValueType;

    ValueType value(value_from);

    if (!obj->setPdb(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb_move(data_collection_model_performance_data_t *obj_performance_data, int32_t p_pdb)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_pdb;
    typedef typename PerformanceData::PdbType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPdb(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_pdb_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getPdbDl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_pdb_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceData::PdbDlType ResultFromType;
    const ResultFromType result_from = obj->getPdbDl();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb_dl(data_collection_model_performance_data_t *obj_performance_data, const int32_t p_pdb_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_pdb_dl;
    typedef typename PerformanceData::PdbDlType ValueType;

    ValueType value(value_from);

    if (!obj->setPdbDl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb_dl_move(data_collection_model_performance_data_t *obj_performance_data, int32_t p_pdb_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_pdb_dl;
    typedef typename PerformanceData::PdbDlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPdbDl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_pdb_ul(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getMaxPdbUl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_pdb_ul(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceData::MaxPdbUlType ResultFromType;
    const ResultFromType result_from = obj->getMaxPdbUl();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_ul(data_collection_model_performance_data_t *obj_performance_data, const int32_t p_max_pdb_ul)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_pdb_ul;
    typedef typename PerformanceData::MaxPdbUlType ValueType;

    ValueType value(value_from);

    if (!obj->setMaxPdbUl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_ul_move(data_collection_model_performance_data_t *obj_performance_data, int32_t p_max_pdb_ul)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_pdb_ul;
    typedef typename PerformanceData::MaxPdbUlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMaxPdbUl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_pdb_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getMaxPdbDl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_pdb_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceData::MaxPdbDlType ResultFromType;
    const ResultFromType result_from = obj->getMaxPdbDl();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_dl(data_collection_model_performance_data_t *obj_performance_data, const int32_t p_max_pdb_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_pdb_dl;
    typedef typename PerformanceData::MaxPdbDlType ValueType;

    ValueType value(value_from);

    if (!obj->setMaxPdbDl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_dl_move(data_collection_model_performance_data_t *obj_performance_data, int32_t p_max_pdb_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_pdb_dl;
    typedef typename PerformanceData::MaxPdbDlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMaxPdbDl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_plr(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getPlr().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_plr(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceData::PlrType ResultFromType;
    const ResultFromType result_from = obj->getPlr();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr(data_collection_model_performance_data_t *obj_performance_data, const int32_t p_plr)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_plr;
    typedef typename PerformanceData::PlrType ValueType;

    ValueType value(value_from);

    if (!obj->setPlr(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr_move(data_collection_model_performance_data_t *obj_performance_data, int32_t p_plr)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_plr;
    typedef typename PerformanceData::PlrType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPlr(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_plr_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getPlrDl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_plr_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceData::PlrDlType ResultFromType;
    const ResultFromType result_from = obj->getPlrDl();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr_dl(data_collection_model_performance_data_t *obj_performance_data, const int32_t p_plr_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_plr_dl;
    typedef typename PerformanceData::PlrDlType ValueType;

    ValueType value(value_from);

    if (!obj->setPlrDl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr_dl_move(data_collection_model_performance_data_t *obj_performance_data, int32_t p_plr_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_plr_dl;
    typedef typename PerformanceData::PlrDlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPlrDl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_plr_ul(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getMaxPlrUl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_plr_ul(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceData::MaxPlrUlType ResultFromType;
    const ResultFromType result_from = obj->getMaxPlrUl();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_ul(data_collection_model_performance_data_t *obj_performance_data, const int32_t p_max_plr_ul)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_plr_ul;
    typedef typename PerformanceData::MaxPlrUlType ValueType;

    ValueType value(value_from);

    if (!obj->setMaxPlrUl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_ul_move(data_collection_model_performance_data_t *obj_performance_data, int32_t p_max_plr_ul)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_plr_ul;
    typedef typename PerformanceData::MaxPlrUlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMaxPlrUl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_plr_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getMaxPlrDl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_plr_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename PerformanceData::MaxPlrDlType ResultFromType;
    const ResultFromType result_from = obj->getMaxPlrDl();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_dl(data_collection_model_performance_data_t *obj_performance_data, const int32_t p_max_plr_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_plr_dl;
    typedef typename PerformanceData::MaxPlrDlType ValueType;

    ValueType value(value_from);

    if (!obj->setMaxPlrDl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_dl_move(data_collection_model_performance_data_t *obj_performance_data, int32_t p_max_plr_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_plr_dl;
    typedef typename PerformanceData::MaxPlrDlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMaxPlrDl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_thrput_ul(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getThrputUl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_thrput_ul(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceData::ThrputUlType ResultFromType;
    const ResultFromType result_from = obj->getThrputUl();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_ul(data_collection_model_performance_data_t *obj_performance_data, const char* p_thrput_ul)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_thrput_ul;
    typedef typename PerformanceData::ThrputUlType ValueType;

    ValueType value(value_from);

    if (!obj->setThrputUl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_ul_move(data_collection_model_performance_data_t *obj_performance_data, char* p_thrput_ul)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_thrput_ul;
    typedef typename PerformanceData::ThrputUlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setThrputUl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_thrput_ul(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getMaxThrputUl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_max_thrput_ul(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceData::MaxThrputUlType ResultFromType;
    const ResultFromType result_from = obj->getMaxThrputUl();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_ul(data_collection_model_performance_data_t *obj_performance_data, const char* p_max_thrput_ul)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_thrput_ul;
    typedef typename PerformanceData::MaxThrputUlType ValueType;

    ValueType value(value_from);

    if (!obj->setMaxThrputUl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_ul_move(data_collection_model_performance_data_t *obj_performance_data, char* p_max_thrput_ul)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_thrput_ul;
    typedef typename PerformanceData::MaxThrputUlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMaxThrputUl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_min_thrput_ul(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getMinThrputUl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_min_thrput_ul(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceData::MinThrputUlType ResultFromType;
    const ResultFromType result_from = obj->getMinThrputUl();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_ul(data_collection_model_performance_data_t *obj_performance_data, const char* p_min_thrput_ul)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_min_thrput_ul;
    typedef typename PerformanceData::MinThrputUlType ValueType;

    ValueType value(value_from);

    if (!obj->setMinThrputUl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_ul_move(data_collection_model_performance_data_t *obj_performance_data, char* p_min_thrput_ul)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_min_thrput_ul;
    typedef typename PerformanceData::MinThrputUlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMinThrputUl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_thrput_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getThrputDl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_thrput_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceData::ThrputDlType ResultFromType;
    const ResultFromType result_from = obj->getThrputDl();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_dl(data_collection_model_performance_data_t *obj_performance_data, const char* p_thrput_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_thrput_dl;
    typedef typename PerformanceData::ThrputDlType ValueType;

    ValueType value(value_from);

    if (!obj->setThrputDl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_dl_move(data_collection_model_performance_data_t *obj_performance_data, char* p_thrput_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_thrput_dl;
    typedef typename PerformanceData::ThrputDlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setThrputDl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_thrput_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getMaxThrputDl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_max_thrput_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceData::MaxThrputDlType ResultFromType;
    const ResultFromType result_from = obj->getMaxThrputDl();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_dl(data_collection_model_performance_data_t *obj_performance_data, const char* p_max_thrput_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_thrput_dl;
    typedef typename PerformanceData::MaxThrputDlType ValueType;

    ValueType value(value_from);

    if (!obj->setMaxThrputDl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_dl_move(data_collection_model_performance_data_t *obj_performance_data, char* p_max_thrput_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_max_thrput_dl;
    typedef typename PerformanceData::MaxThrputDlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMaxThrputDl(std::move(value))) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_min_thrput_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return false;

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return false;

    return obj->getMinThrputDl().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_min_thrput_dl(const data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<const std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PerformanceData::MinThrputDlType ResultFromType;
    const ResultFromType result_from = obj->getMinThrputDl();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_dl(data_collection_model_performance_data_t *obj_performance_data, const char* p_min_thrput_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_min_thrput_dl;
    typedef typename PerformanceData::MinThrputDlType ValueType;

    ValueType value(value_from);

    if (!obj->setMinThrputDl(value)) return NULL;

    return obj_performance_data;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_dl_move(data_collection_model_performance_data_t *obj_performance_data, char* p_min_thrput_dl)
{
    if (!obj_performance_data) return NULL;

    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    if (!obj) return NULL;

    const auto &value_from = p_min_thrput_dl;
    typedef typename PerformanceData::MinThrputDlType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMinThrputDl(std::move(value))) return NULL;

    return obj_performance_data;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_make_lnode(data_collection_model_performance_data_t *p_performance_data)
{
    return data_collection_lnode_create(p_performance_data, reinterpret_cast<void(*)(void*)>(data_collection_model_performance_data_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_performance_data_refcount(data_collection_model_performance_data_t *obj_performance_data)
{
    if (!obj_performance_data) return 0l;
    std::shared_ptr<PerformanceData > &obj = *reinterpret_cast<std::shared_ptr<PerformanceData >*>(obj_performance_data);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

