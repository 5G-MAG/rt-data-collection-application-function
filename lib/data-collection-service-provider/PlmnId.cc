/**********************************************************************************************************************************
 * PlmnId - C interface to the PlmnId object
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

/*#include "PlmnId.h" already included by data-collection-sp/data-collection.h */
#include "PlmnId-internal.h"
#include "openapi/model/PlmnId.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_create(

)
{
    return reinterpret_cast<data_collection_model_plmn_id_t*>(new std::shared_ptr<PlmnId>(new PlmnId(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_create_copy(const data_collection_model_plmn_id_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<PlmnId > &obj = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_plmn_id_t*>(new std::shared_ptr<PlmnId >(new PlmnId(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_create_move(data_collection_model_plmn_id_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<PlmnId > *obj = reinterpret_cast<std::shared_ptr<PlmnId >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_copy(data_collection_model_plmn_id_t *plmn_id, const data_collection_model_plmn_id_t *other)
{
    if (plmn_id) {
        std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(plmn_id);
        if (obj) {
            if (other) {
                const std::shared_ptr<PlmnId > &other_obj = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(other);
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
                const std::shared_ptr<PlmnId > &other_obj = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(other);
                if (other_obj) {
                    obj.reset(new PlmnId(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        plmn_id = data_collection_model_plmn_id_create_copy(other);
    }
    return plmn_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_move(data_collection_model_plmn_id_t *plmn_id, data_collection_model_plmn_id_t *other)
{
    std::shared_ptr<PlmnId > *other_ptr = reinterpret_cast<std::shared_ptr<PlmnId >*>(other);

    if (plmn_id) {
        std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(plmn_id);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                plmn_id = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return plmn_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_plmn_id_free(data_collection_model_plmn_id_t *plmn_id)
{
    if (!plmn_id) return;
    delete reinterpret_cast<std::shared_ptr<PlmnId >*>(plmn_id);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_plmn_id_toJSON(const data_collection_model_plmn_id_t *plmn_id, bool as_request)
{
    if (!plmn_id) return NULL;
    const std::shared_ptr<PlmnId > &obj = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(plmn_id);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_plmn_id_t*>(new std::shared_ptr<PlmnId >(new PlmnId(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_plmn_id_is_equal_to(const data_collection_model_plmn_id_t *first, const data_collection_model_plmn_id_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<PlmnId > &obj2 = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<PlmnId > &obj1 = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_get_mcc(const data_collection_model_plmn_id_t *obj_plmn_id)
{
    if (!obj_plmn_id) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PlmnId > &obj = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(obj_plmn_id);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PlmnId::MccType ResultFromType;
    const ResultFromType result_from = obj->getMcc();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mcc(data_collection_model_plmn_id_t *obj_plmn_id, const char* p_mcc)
{
    if (!obj_plmn_id) return NULL;

    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(obj_plmn_id);
    if (!obj) return NULL;

    const auto &value_from = p_mcc;
    typedef typename PlmnId::MccType ValueType;

    ValueType value(value_from);
    if (!obj->setMcc(value)) return NULL;

    return obj_plmn_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mcc_move(data_collection_model_plmn_id_t *obj_plmn_id, char* p_mcc)
{
    if (!obj_plmn_id) return NULL;

    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(obj_plmn_id);
    if (!obj) return NULL;

    const auto &value_from = p_mcc;
    typedef typename PlmnId::MccType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMcc(std::move(value))) return NULL;

    return obj_plmn_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_plmn_id_get_mnc(const data_collection_model_plmn_id_t *obj_plmn_id)
{
    if (!obj_plmn_id) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<PlmnId > &obj = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(obj_plmn_id);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename PlmnId::MncType ResultFromType;
    const ResultFromType result_from = obj->getMnc();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mnc(data_collection_model_plmn_id_t *obj_plmn_id, const char* p_mnc)
{
    if (!obj_plmn_id) return NULL;

    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(obj_plmn_id);
    if (!obj) return NULL;

    const auto &value_from = p_mnc;
    typedef typename PlmnId::MncType ValueType;

    ValueType value(value_from);
    if (!obj->setMnc(value)) return NULL;

    return obj_plmn_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mnc_move(data_collection_model_plmn_id_t *obj_plmn_id, char* p_mnc)
{
    if (!obj_plmn_id) return NULL;

    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(obj_plmn_id);
    if (!obj) return NULL;

    const auto &value_from = p_mnc;
    typedef typename PlmnId::MncType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMnc(std::move(value))) return NULL;

    return obj_plmn_id;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_plmn_id_make_lnode(data_collection_model_plmn_id_t *p_plmn_id)
{
    return data_collection_lnode_create(p_plmn_id, reinterpret_cast<void(*)(void*)>(data_collection_model_plmn_id_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_plmn_id_refcount(data_collection_model_plmn_id_t *obj_plmn_id)
{
    if (!obj_plmn_id) return 0l;
    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(obj_plmn_id);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

