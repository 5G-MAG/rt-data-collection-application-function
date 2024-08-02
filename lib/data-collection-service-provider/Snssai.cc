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
    if (!other) return NULL;
    const std::shared_ptr<Snssai > &obj = *reinterpret_cast<const std::shared_ptr<Snssai >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_snssai_t*>(new std::shared_ptr<Snssai >(new Snssai(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_create_move(data_collection_model_snssai_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<Snssai > *obj = reinterpret_cast<std::shared_ptr<Snssai >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_copy(data_collection_model_snssai_t *snssai, const data_collection_model_snssai_t *other)
{
    if (snssai) {
        std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(snssai);
        if (obj) {
            if (other) {
                const std::shared_ptr<Snssai > &other_obj = *reinterpret_cast<const std::shared_ptr<Snssai >*>(other);
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
                const std::shared_ptr<Snssai > &other_obj = *reinterpret_cast<const std::shared_ptr<Snssai >*>(other);
                if (other_obj) {
                    obj.reset(new Snssai(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        snssai = data_collection_model_snssai_create_copy(other);
    }
    return snssai;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_move(data_collection_model_snssai_t *snssai, data_collection_model_snssai_t *other)
{
    std::shared_ptr<Snssai > *other_ptr = reinterpret_cast<std::shared_ptr<Snssai >*>(other);

    if (snssai) {
        std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(snssai);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                snssai = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return snssai;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_snssai_free(data_collection_model_snssai_t *snssai)
{
    if (!snssai) return;
    delete reinterpret_cast<std::shared_ptr<Snssai >*>(snssai);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_snssai_toJSON(const data_collection_model_snssai_t *snssai, bool as_request)
{
    if (!snssai) return NULL;
    const std::shared_ptr<Snssai > &obj = *reinterpret_cast<const std::shared_ptr<Snssai >*>(snssai);
    if (!obj) return NULL;
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_snssai_is_equal_to(const data_collection_model_snssai_t *first, const data_collection_model_snssai_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<Snssai > &obj2 = *reinterpret_cast<const std::shared_ptr<Snssai >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<Snssai > &obj1 = *reinterpret_cast<const std::shared_ptr<Snssai >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_snssai_get_sst(const data_collection_model_snssai_t *obj_snssai)
{
    if (!obj_snssai) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<Snssai > &obj = *reinterpret_cast<const std::shared_ptr<Snssai >*>(obj_snssai);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename Snssai::SstType ResultFromType;
    const ResultFromType result_from = obj->getSst();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_set_sst(data_collection_model_snssai_t *obj_snssai, const int32_t p_sst)
{
    if (!obj_snssai) return NULL;

    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(obj_snssai);
    if (!obj) return NULL;

    const auto &value_from = p_sst;
    typedef typename Snssai::SstType ValueType;

    ValueType value = value_from;
    if (!obj->setSst(value)) return NULL;

    return obj_snssai;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_set_sst_move(data_collection_model_snssai_t *obj_snssai, int32_t p_sst)
{
    if (!obj_snssai) return NULL;

    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(obj_snssai);
    if (!obj) return NULL;

    const auto &value_from = p_sst;
    typedef typename Snssai::SstType ValueType;

    ValueType value = value_from;
    
    if (!obj->setSst(std::move(value))) return NULL;

    return obj_snssai;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_snssai_get_sd(const data_collection_model_snssai_t *obj_snssai)
{
    if (!obj_snssai) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<Snssai > &obj = *reinterpret_cast<const std::shared_ptr<Snssai >*>(obj_snssai);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename Snssai::SdType ResultFromType;
    const ResultFromType result_from = obj->getSd();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_set_sd(data_collection_model_snssai_t *obj_snssai, const char* p_sd)
{
    if (!obj_snssai) return NULL;

    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(obj_snssai);
    if (!obj) return NULL;

    const auto &value_from = p_sd;
    typedef typename Snssai::SdType ValueType;

    ValueType value(value_from);
    if (!obj->setSd(value)) return NULL;

    return obj_snssai;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_snssai_t *data_collection_model_snssai_set_sd_move(data_collection_model_snssai_t *obj_snssai, char* p_sd)
{
    if (!obj_snssai) return NULL;

    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(obj_snssai);
    if (!obj) return NULL;

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
    if (!obj_snssai) return 0l;
    std::shared_ptr<Snssai > &obj = *reinterpret_cast<std::shared_ptr<Snssai >*>(obj_snssai);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

