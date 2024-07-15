/**********************************************************************************************************************************
 * Ecgi - C interface to the Ecgi object
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

/*#include "Ecgi.h" already included by data-collection-sp/data-collection.h */
#include "Ecgi-internal.h"
#include "openapi/model/Ecgi.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_create(


)
{
    return reinterpret_cast<data_collection_model_ecgi_t*>(new std::shared_ptr<Ecgi>(new Ecgi(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_create_copy(const data_collection_model_ecgi_t *other)
{
    return reinterpret_cast<data_collection_model_ecgi_t*>(new std::shared_ptr<Ecgi >(new Ecgi(**reinterpret_cast<const std::shared_ptr<Ecgi >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_create_move(data_collection_model_ecgi_t *other)
{
    return reinterpret_cast<data_collection_model_ecgi_t*>(new std::shared_ptr<Ecgi >(std::move(*reinterpret_cast<std::shared_ptr<Ecgi >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_copy(data_collection_model_ecgi_t *ecgi, const data_collection_model_ecgi_t *other)
{
    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(ecgi);
    *obj = **reinterpret_cast<const std::shared_ptr<Ecgi >*>(other);
    return ecgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_move(data_collection_model_ecgi_t *ecgi, data_collection_model_ecgi_t *other)
{
    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(ecgi);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Ecgi >*>(other));
    return ecgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ecgi_free(data_collection_model_ecgi_t *ecgi)
{
    delete reinterpret_cast<std::shared_ptr<Ecgi >*>(ecgi);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ecgi_toJSON(const data_collection_model_ecgi_t *ecgi, bool as_request)
{
    const std::shared_ptr<Ecgi > &obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(ecgi);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ecgi_t*>(new std::shared_ptr<Ecgi >(new Ecgi(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_plmn_id_t* data_collection_model_ecgi_get_plmn_id(const data_collection_model_ecgi_t *obj_ecgi)
{
    const std::shared_ptr<Ecgi > &obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(obj_ecgi);
    typedef typename Ecgi::PlmnIdType ResultFromType;
    const ResultFromType result_from = obj->getPlmnId();
    const data_collection_model_plmn_id_t *result = reinterpret_cast<const data_collection_model_plmn_id_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_set_plmn_id(data_collection_model_ecgi_t *obj_ecgi, const data_collection_model_plmn_id_t* p_plmn_id)
{
    if (obj_ecgi == NULL) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    const auto &value_from = p_plmn_id;
    typedef typename Ecgi::PlmnIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPlmnId(value)) return NULL;
    return obj_ecgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_set_plmn_id_move(data_collection_model_ecgi_t *obj_ecgi, data_collection_model_plmn_id_t* p_plmn_id)
{
    if (obj_ecgi == NULL) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    const auto &value_from = p_plmn_id;
    typedef typename Ecgi::PlmnIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPlmnId(std::move(value))) return NULL;
    return obj_ecgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_ecgi_get_eutra_cell_id(const data_collection_model_ecgi_t *obj_ecgi)
{
    const std::shared_ptr<Ecgi > &obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(obj_ecgi);
    typedef typename Ecgi::EutraCellIdType ResultFromType;
    const ResultFromType result_from = obj->getEutraCellId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_set_eutra_cell_id(data_collection_model_ecgi_t *obj_ecgi, const char* p_eutra_cell_id)
{
    if (obj_ecgi == NULL) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    const auto &value_from = p_eutra_cell_id;
    typedef typename Ecgi::EutraCellIdType ValueType;

    ValueType value(value_from);
    if (!obj->setEutraCellId(value)) return NULL;
    return obj_ecgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_set_eutra_cell_id_move(data_collection_model_ecgi_t *obj_ecgi, char* p_eutra_cell_id)
{
    if (obj_ecgi == NULL) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    const auto &value_from = p_eutra_cell_id;
    typedef typename Ecgi::EutraCellIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setEutraCellId(std::move(value))) return NULL;
    return obj_ecgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_ecgi_get_nid(const data_collection_model_ecgi_t *obj_ecgi)
{
    const std::shared_ptr<Ecgi > &obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(obj_ecgi);
    typedef typename Ecgi::NidType ResultFromType;
    const ResultFromType result_from = obj->getNid();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_set_nid(data_collection_model_ecgi_t *obj_ecgi, const char* p_nid)
{
    if (obj_ecgi == NULL) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    const auto &value_from = p_nid;
    typedef typename Ecgi::NidType ValueType;

    ValueType value(value_from);
    if (!obj->setNid(value)) return NULL;
    return obj_ecgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ecgi_t *data_collection_model_ecgi_set_nid_move(data_collection_model_ecgi_t *obj_ecgi, char* p_nid)
{
    if (obj_ecgi == NULL) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    const auto &value_from = p_nid;
    typedef typename Ecgi::NidType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNid(std::move(value))) return NULL;
    return obj_ecgi;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ecgi_make_lnode(data_collection_model_ecgi_t *p_ecgi)
{
    return data_collection_lnode_create(p_ecgi, reinterpret_cast<void(*)(void*)>(data_collection_model_ecgi_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ecgi_refcount(data_collection_model_ecgi_t *obj_ecgi)
{
    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

