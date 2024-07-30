/**********************************************************************************************************************************
 * GlobalRanNodeId - C interface to the GlobalRanNodeId object
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

/*#include "GlobalRanNodeId.h" already included by data-collection-sp/data-collection.h */
#include "GlobalRanNodeId-internal.h"
#include "openapi/model/GlobalRanNodeId.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_create(







)
{
    return reinterpret_cast<data_collection_model_global_ran_node_id_t*>(new std::shared_ptr<GlobalRanNodeId>(new GlobalRanNodeId(







)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_create_copy(const data_collection_model_global_ran_node_id_t *other)
{
    return reinterpret_cast<data_collection_model_global_ran_node_id_t*>(new std::shared_ptr<GlobalRanNodeId >(new GlobalRanNodeId(**reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_create_move(data_collection_model_global_ran_node_id_t *other)
{
    return reinterpret_cast<data_collection_model_global_ran_node_id_t*>(new std::shared_ptr<GlobalRanNodeId >(std::move(*reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_copy(data_collection_model_global_ran_node_id_t *global_ran_node_id, const data_collection_model_global_ran_node_id_t *other)
{
    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(global_ran_node_id);
    *obj = **reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(other);
    return global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_move(data_collection_model_global_ran_node_id_t *global_ran_node_id, data_collection_model_global_ran_node_id_t *other)
{
    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(global_ran_node_id);
    obj = std::move(*reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(other));
    return global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_global_ran_node_id_free(data_collection_model_global_ran_node_id_t *global_ran_node_id)
{
    delete reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(global_ran_node_id);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_global_ran_node_id_toJSON(const data_collection_model_global_ran_node_id_t *global_ran_node_id, bool as_request)
{
    const std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(global_ran_node_id);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_global_ran_node_id_t*>(new std::shared_ptr<GlobalRanNodeId >(new GlobalRanNodeId(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_global_ran_node_id_is_equal_to(const data_collection_model_global_ran_node_id_t *first, const data_collection_model_global_ran_node_id_t *second)
{
    const std::shared_ptr<GlobalRanNodeId > &obj1 = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(first);
    const std::shared_ptr<GlobalRanNodeId > &obj2 = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_plmn_id_t* data_collection_model_global_ran_node_id_get_plmn_id(const data_collection_model_global_ran_node_id_t *obj_global_ran_node_id)
{
    const std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    typedef typename GlobalRanNodeId::PlmnIdType ResultFromType;
    const ResultFromType result_from = obj->getPlmnId();
    const data_collection_model_plmn_id_t *result = reinterpret_cast<const data_collection_model_plmn_id_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_plmn_id(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, const data_collection_model_plmn_id_t* p_plmn_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_plmn_id;
    typedef typename GlobalRanNodeId::PlmnIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPlmnId(value)) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_plmn_id_move(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, data_collection_model_plmn_id_t* p_plmn_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_plmn_id;
    typedef typename GlobalRanNodeId::PlmnIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPlmnId(std::move(value))) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_global_ran_node_id_get_n3_iwf_id(const data_collection_model_global_ran_node_id_t *obj_global_ran_node_id)
{
    const std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    typedef typename GlobalRanNodeId::N3IwfIdType ResultFromType;
    const ResultFromType result_from = obj->getN3IwfId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_n3_iwf_id(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, const char* p_n3_iwf_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_n3_iwf_id;
    typedef typename GlobalRanNodeId::N3IwfIdType ValueType;

    ValueType value(value_from);
    if (!obj->setN3IwfId(value)) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_n3_iwf_id_move(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, char* p_n3_iwf_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_n3_iwf_id;
    typedef typename GlobalRanNodeId::N3IwfIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setN3IwfId(std::move(value))) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_gnb_id_t* data_collection_model_global_ran_node_id_get_gnb_id(const data_collection_model_global_ran_node_id_t *obj_global_ran_node_id)
{
    const std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    typedef typename GlobalRanNodeId::GNbIdType ResultFromType;
    const ResultFromType result_from = obj->getGNbId();
    const data_collection_model_gnb_id_t *result = reinterpret_cast<const data_collection_model_gnb_id_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_gnb_id(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, const data_collection_model_gnb_id_t* p_gnb_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_gnb_id;
    typedef typename GlobalRanNodeId::GNbIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setGNbId(value)) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_gnb_id_move(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, data_collection_model_gnb_id_t* p_gnb_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_gnb_id;
    typedef typename GlobalRanNodeId::GNbIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setGNbId(std::move(value))) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_global_ran_node_id_get_nge_nb_id(const data_collection_model_global_ran_node_id_t *obj_global_ran_node_id)
{
    const std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    typedef typename GlobalRanNodeId::NgeNbIdType ResultFromType;
    const ResultFromType result_from = obj->getNgeNbId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nge_nb_id(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, const char* p_nge_nb_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_nge_nb_id;
    typedef typename GlobalRanNodeId::NgeNbIdType ValueType;

    ValueType value(value_from);
    if (!obj->setNgeNbId(value)) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nge_nb_id_move(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, char* p_nge_nb_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_nge_nb_id;
    typedef typename GlobalRanNodeId::NgeNbIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNgeNbId(std::move(value))) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_global_ran_node_id_get_wagf_id(const data_collection_model_global_ran_node_id_t *obj_global_ran_node_id)
{
    const std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    typedef typename GlobalRanNodeId::WagfIdType ResultFromType;
    const ResultFromType result_from = obj->getWagfId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_wagf_id(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, const char* p_wagf_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_wagf_id;
    typedef typename GlobalRanNodeId::WagfIdType ValueType;

    ValueType value(value_from);
    if (!obj->setWagfId(value)) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_wagf_id_move(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, char* p_wagf_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_wagf_id;
    typedef typename GlobalRanNodeId::WagfIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setWagfId(std::move(value))) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_global_ran_node_id_get_tngf_id(const data_collection_model_global_ran_node_id_t *obj_global_ran_node_id)
{
    const std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    typedef typename GlobalRanNodeId::TngfIdType ResultFromType;
    const ResultFromType result_from = obj->getTngfId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_tngf_id(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, const char* p_tngf_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_tngf_id;
    typedef typename GlobalRanNodeId::TngfIdType ValueType;

    ValueType value(value_from);
    if (!obj->setTngfId(value)) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_tngf_id_move(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, char* p_tngf_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_tngf_id;
    typedef typename GlobalRanNodeId::TngfIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTngfId(std::move(value))) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_global_ran_node_id_get_nid(const data_collection_model_global_ran_node_id_t *obj_global_ran_node_id)
{
    const std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    typedef typename GlobalRanNodeId::NidType ResultFromType;
    const ResultFromType result_from = obj->getNid();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nid(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, const char* p_nid)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_nid;
    typedef typename GlobalRanNodeId::NidType ValueType;

    ValueType value(value_from);
    if (!obj->setNid(value)) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_nid_move(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, char* p_nid)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_nid;
    typedef typename GlobalRanNodeId::NidType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNid(std::move(value))) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_global_ran_node_id_get_enb_id(const data_collection_model_global_ran_node_id_t *obj_global_ran_node_id)
{
    const std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<const std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    typedef typename GlobalRanNodeId::ENbIdType ResultFromType;
    const ResultFromType result_from = obj->getENbId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_enb_id(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, const char* p_enb_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_enb_id;
    typedef typename GlobalRanNodeId::ENbIdType ValueType;

    ValueType value(value_from);
    if (!obj->setENbId(value)) return NULL;
    return obj_global_ran_node_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_global_ran_node_id_t *data_collection_model_global_ran_node_id_set_enb_id_move(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id, char* p_enb_id)
{
    if (obj_global_ran_node_id == NULL) return NULL;

    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    const auto &value_from = p_enb_id;
    typedef typename GlobalRanNodeId::ENbIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setENbId(std::move(value))) return NULL;
    return obj_global_ran_node_id;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_global_ran_node_id_make_lnode(data_collection_model_global_ran_node_id_t *p_global_ran_node_id)
{
    return data_collection_lnode_create(p_global_ran_node_id, reinterpret_cast<void(*)(void*)>(data_collection_model_global_ran_node_id_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_global_ran_node_id_refcount(data_collection_model_global_ran_node_id_t *obj_global_ran_node_id)
{
    std::shared_ptr<GlobalRanNodeId > &obj = *reinterpret_cast<std::shared_ptr<GlobalRanNodeId >*>(obj_global_ran_node_id);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

