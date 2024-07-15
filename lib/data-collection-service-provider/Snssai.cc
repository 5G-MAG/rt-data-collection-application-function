/**********************************************************************************************************************************
 * Snssai - C interface to the Snssai object
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

/*#include "Snssai.h" already included by data-collection-sp/data-collection.h */
#include "Snssai-internal.h"
#include "openapi/model/Snssai.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_create(

)
{
    return reinterpret_cast<data_collection_model_snssai_t*>(new std::shared_ptr<Snssai>(new Snssai(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_create_copy(const data_collection_model_snssai_t *other)
{
    return reinterpret_cast<data_collection_model_snssai_t*>(new std::shared_ptr<Snssai >(new Snssai(**reinterpret_cast<const std::shared_ptr<Snssai >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_create_move(data_collection_model_snssai_t *other)
{
    return reinterpret_cast<data_collection_model_snssai_t*>(new std::shared_ptr<Snssai >(std::move(*reinterpret_cast<std::shared_ptr<Snssai >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_copy(data_collection_model_snssai_t *snssai, const data_collection_model_snssai_t *other)
{
    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(snssai);
    *obj = **reinterpret_cast<const std::shared_ptr<Snssai >*>(other);
    return snssai;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_move(data_collection_model_snssai_t *snssai, data_collection_model_snssai_t *other)
{
    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(snssai);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Snssai >*>(other));
    return snssai;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_snssai_free(data_collection_model_snssai_t *snssai)
{
    delete reinterpret_cast<std::shared_ptr<Snssai >*>(snssai);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_snssai_toJSON(const data_collection_model_snssai_t *snssai, bool as_request)
{
    const std::shared_ptr<Snssai > &obj = *reinterpret_cast<const std::shared_ptr<Snssai >*>(snssai);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_snssai_t*>(new std::shared_ptr<Snssai >(new Snssai(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_snssai_get_sst(const data_collection_model_snssai_t *obj_snssai)
{
    const std::shared_ptr<Snssai > &obj = *reinterpret_cast<const std::shared_ptr<Snssai >*>(obj_snssai);
    typedef typename Snssai::SstType ResultFromType;
    const ResultFromType result_from = obj->getSst();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_set_sst(data_collection_model_snssai_t *obj_snssai, const int32_t p_sst)
{
    if (obj_snssai == NULL) return NULL;

    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(obj_snssai);
    const auto &value_from = p_sst;
    typedef typename Snssai::SstType ValueType;

    ValueType value = value_from;
    if (!obj->setSst(value)) return NULL;
    return obj_snssai;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_set_sst_move(data_collection_model_snssai_t *obj_snssai, int32_t p_sst)
{
    if (obj_snssai == NULL) return NULL;

    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(obj_snssai);
    const auto &value_from = p_sst;
    typedef typename Snssai::SstType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSst(std::move(value))) return NULL;
    return obj_snssai;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_snssai_get_sd(const data_collection_model_snssai_t *obj_snssai)
{
    const std::shared_ptr<Snssai > &obj = *reinterpret_cast<const std::shared_ptr<Snssai >*>(obj_snssai);
    typedef typename Snssai::SdType ResultFromType;
    const ResultFromType result_from = obj->getSd();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_set_sd(data_collection_model_snssai_t *obj_snssai, const char* p_sd)
{
    if (obj_snssai == NULL) return NULL;

    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(obj_snssai);
    const auto &value_from = p_sd;
    typedef typename Snssai::SdType ValueType;

    ValueType value(value_from);
    if (!obj->setSd(value)) return NULL;
    return obj_snssai;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_set_sd_move(data_collection_model_snssai_t *obj_snssai, char* p_sd)
{
    if (obj_snssai == NULL) return NULL;

    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(obj_snssai);
    const auto &value_from = p_sd;
    typedef typename Snssai::SdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSd(std::move(value))) return NULL;
    return obj_snssai;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_snssai_make_lnode(data_collection_model_snssai_t *p_snssai)
{
    return data_collection_lnode_create(p_snssai, reinterpret_cast<void(*)(void*)>(data_collection_model_snssai_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_snssai_refcount(data_collection_model_snssai_t *obj_snssai)
{
    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(obj_snssai);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

