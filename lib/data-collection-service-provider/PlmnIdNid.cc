/**********************************************************************************************************************************
 * PlmnIdNid - C interface to the PlmnIdNid object
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

/*#include "PlmnIdNid.h" already included by data-collection-sp/data-collection.h */
#include "PlmnIdNid-internal.h"
#include "openapi/model/PlmnIdNid.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_create(


)
{
    return reinterpret_cast<data_collection_model_plmn_id_nid_t*>(new std::shared_ptr<PlmnIdNid>(new PlmnIdNid(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_create_copy(const data_collection_model_plmn_id_nid_t *other)
{
    return reinterpret_cast<data_collection_model_plmn_id_nid_t*>(new std::shared_ptr<PlmnIdNid >(new PlmnIdNid(**reinterpret_cast<const std::shared_ptr<PlmnIdNid >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_create_move(data_collection_model_plmn_id_nid_t *other)
{
    return reinterpret_cast<data_collection_model_plmn_id_nid_t*>(new std::shared_ptr<PlmnIdNid >(std::move(*reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_copy(data_collection_model_plmn_id_nid_t *plmn_id_nid, const data_collection_model_plmn_id_nid_t *other)
{
    std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(plmn_id_nid);
    *obj = **reinterpret_cast<const std::shared_ptr<PlmnIdNid >*>(other);
    return plmn_id_nid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_move(data_collection_model_plmn_id_nid_t *plmn_id_nid, data_collection_model_plmn_id_nid_t *other)
{
    std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(plmn_id_nid);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(other));
    return plmn_id_nid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_plmn_id_nid_free(data_collection_model_plmn_id_nid_t *plmn_id_nid)
{
    delete reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(plmn_id_nid);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_plmn_id_nid_toJSON(const data_collection_model_plmn_id_nid_t *plmn_id_nid, bool as_request)
{
    const std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<const std::shared_ptr<PlmnIdNid >*>(plmn_id_nid);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_plmn_id_nid_t*>(new std::shared_ptr<PlmnIdNid >(new PlmnIdNid(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_plmn_id_nid_get_mcc(const data_collection_model_plmn_id_nid_t *obj_plmn_id_nid)
{
    const std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<const std::shared_ptr<PlmnIdNid >*>(obj_plmn_id_nid);
    typedef typename PlmnIdNid::MccType ResultFromType;
    const ResultFromType result_from = obj->getMcc();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mcc(data_collection_model_plmn_id_nid_t *obj_plmn_id_nid, const char* p_mcc)
{
    if (obj_plmn_id_nid == NULL) return NULL;

    std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(obj_plmn_id_nid);
    const auto &value_from = p_mcc;
    typedef typename PlmnIdNid::MccType ValueType;

    ValueType value(value_from);
    if (!obj->setMcc(value)) return NULL;
    return obj_plmn_id_nid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mcc_move(data_collection_model_plmn_id_nid_t *obj_plmn_id_nid, char* p_mcc)
{
    if (obj_plmn_id_nid == NULL) return NULL;

    std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(obj_plmn_id_nid);
    const auto &value_from = p_mcc;
    typedef typename PlmnIdNid::MccType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMcc(std::move(value))) return NULL;
    return obj_plmn_id_nid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_plmn_id_nid_get_mnc(const data_collection_model_plmn_id_nid_t *obj_plmn_id_nid)
{
    const std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<const std::shared_ptr<PlmnIdNid >*>(obj_plmn_id_nid);
    typedef typename PlmnIdNid::MncType ResultFromType;
    const ResultFromType result_from = obj->getMnc();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mnc(data_collection_model_plmn_id_nid_t *obj_plmn_id_nid, const char* p_mnc)
{
    if (obj_plmn_id_nid == NULL) return NULL;

    std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(obj_plmn_id_nid);
    const auto &value_from = p_mnc;
    typedef typename PlmnIdNid::MncType ValueType;

    ValueType value(value_from);
    if (!obj->setMnc(value)) return NULL;
    return obj_plmn_id_nid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_mnc_move(data_collection_model_plmn_id_nid_t *obj_plmn_id_nid, char* p_mnc)
{
    if (obj_plmn_id_nid == NULL) return NULL;

    std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(obj_plmn_id_nid);
    const auto &value_from = p_mnc;
    typedef typename PlmnIdNid::MncType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMnc(std::move(value))) return NULL;
    return obj_plmn_id_nid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_plmn_id_nid_get_nid(const data_collection_model_plmn_id_nid_t *obj_plmn_id_nid)
{
    const std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<const std::shared_ptr<PlmnIdNid >*>(obj_plmn_id_nid);
    typedef typename PlmnIdNid::NidType ResultFromType;
    const ResultFromType result_from = obj->getNid();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_nid(data_collection_model_plmn_id_nid_t *obj_plmn_id_nid, const char* p_nid)
{
    if (obj_plmn_id_nid == NULL) return NULL;

    std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(obj_plmn_id_nid);
    const auto &value_from = p_nid;
    typedef typename PlmnIdNid::NidType ValueType;

    ValueType value(value_from);
    if (!obj->setNid(value)) return NULL;
    return obj_plmn_id_nid;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_nid_t *data_collection_model_plmn_id_nid_set_nid_move(data_collection_model_plmn_id_nid_t *obj_plmn_id_nid, char* p_nid)
{
    if (obj_plmn_id_nid == NULL) return NULL;

    std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(obj_plmn_id_nid);
    const auto &value_from = p_nid;
    typedef typename PlmnIdNid::NidType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNid(std::move(value))) return NULL;
    return obj_plmn_id_nid;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_plmn_id_nid_make_lnode(data_collection_model_plmn_id_nid_t *p_plmn_id_nid)
{
    return data_collection_lnode_create(p_plmn_id_nid, reinterpret_cast<void(*)(void*)>(data_collection_model_plmn_id_nid_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_plmn_id_nid_refcount(data_collection_model_plmn_id_nid_t *obj_plmn_id_nid)
{
    std::shared_ptr<PlmnIdNid > &obj = *reinterpret_cast<std::shared_ptr<PlmnIdNid >*>(obj_plmn_id_nid);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

