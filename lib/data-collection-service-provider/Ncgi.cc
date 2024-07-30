/**********************************************************************************************************************************
 * Ncgi - C interface to the Ncgi object
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

/*#include "Ncgi.h" already included by data-collection-sp/data-collection.h */
#include "Ncgi-internal.h"
#include "openapi/model/Ncgi.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_create(


)
{
    return reinterpret_cast<data_collection_model_ncgi_t*>(new std::shared_ptr<Ncgi>(new Ncgi(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_create_copy(const data_collection_model_ncgi_t *other)
{
    return reinterpret_cast<data_collection_model_ncgi_t*>(new std::shared_ptr<Ncgi >(new Ncgi(**reinterpret_cast<const std::shared_ptr<Ncgi >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_create_move(data_collection_model_ncgi_t *other)
{
    return reinterpret_cast<data_collection_model_ncgi_t*>(new std::shared_ptr<Ncgi >(std::move(*reinterpret_cast<std::shared_ptr<Ncgi >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_copy(data_collection_model_ncgi_t *ncgi, const data_collection_model_ncgi_t *other)
{
    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(ncgi);
    *obj = **reinterpret_cast<const std::shared_ptr<Ncgi >*>(other);
    return ncgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_move(data_collection_model_ncgi_t *ncgi, data_collection_model_ncgi_t *other)
{
    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(ncgi);
    obj = std::move(*reinterpret_cast<std::shared_ptr<Ncgi >*>(other));
    return ncgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ncgi_free(data_collection_model_ncgi_t *ncgi)
{
    delete reinterpret_cast<std::shared_ptr<Ncgi >*>(ncgi);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ncgi_toJSON(const data_collection_model_ncgi_t *ncgi, bool as_request)
{
    const std::shared_ptr<Ncgi > &obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(ncgi);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ncgi_t*>(new std::shared_ptr<Ncgi >(new Ncgi(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_ncgi_is_equal_to(const data_collection_model_ncgi_t *first, const data_collection_model_ncgi_t *second)
{
    const std::shared_ptr<Ncgi > &obj1 = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(first);
    const std::shared_ptr<Ncgi > &obj2 = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_plmn_id_t* data_collection_model_ncgi_get_plmn_id(const data_collection_model_ncgi_t *obj_ncgi)
{
    const std::shared_ptr<Ncgi > &obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(obj_ncgi);
    typedef typename Ncgi::PlmnIdType ResultFromType;
    const ResultFromType result_from = obj->getPlmnId();
    const data_collection_model_plmn_id_t *result = reinterpret_cast<const data_collection_model_plmn_id_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_set_plmn_id(data_collection_model_ncgi_t *obj_ncgi, const data_collection_model_plmn_id_t* p_plmn_id)
{
    if (obj_ncgi == NULL) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    const auto &value_from = p_plmn_id;
    typedef typename Ncgi::PlmnIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPlmnId(value)) return NULL;
    return obj_ncgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_set_plmn_id_move(data_collection_model_ncgi_t *obj_ncgi, data_collection_model_plmn_id_t* p_plmn_id)
{
    if (obj_ncgi == NULL) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    const auto &value_from = p_plmn_id;
    typedef typename Ncgi::PlmnIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPlmnId(std::move(value))) return NULL;
    return obj_ncgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_ncgi_get_nr_cell_id(const data_collection_model_ncgi_t *obj_ncgi)
{
    const std::shared_ptr<Ncgi > &obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(obj_ncgi);
    typedef typename Ncgi::NrCellIdType ResultFromType;
    const ResultFromType result_from = obj->getNrCellId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_set_nr_cell_id(data_collection_model_ncgi_t *obj_ncgi, const char* p_nr_cell_id)
{
    if (obj_ncgi == NULL) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    const auto &value_from = p_nr_cell_id;
    typedef typename Ncgi::NrCellIdType ValueType;

    ValueType value(value_from);
    if (!obj->setNrCellId(value)) return NULL;
    return obj_ncgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_set_nr_cell_id_move(data_collection_model_ncgi_t *obj_ncgi, char* p_nr_cell_id)
{
    if (obj_ncgi == NULL) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    const auto &value_from = p_nr_cell_id;
    typedef typename Ncgi::NrCellIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNrCellId(std::move(value))) return NULL;
    return obj_ncgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_ncgi_get_nid(const data_collection_model_ncgi_t *obj_ncgi)
{
    const std::shared_ptr<Ncgi > &obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(obj_ncgi);
    typedef typename Ncgi::NidType ResultFromType;
    const ResultFromType result_from = obj->getNid();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_set_nid(data_collection_model_ncgi_t *obj_ncgi, const char* p_nid)
{
    if (obj_ncgi == NULL) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    const auto &value_from = p_nid;
    typedef typename Ncgi::NidType ValueType;

    ValueType value(value_from);
    if (!obj->setNid(value)) return NULL;
    return obj_ncgi;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ncgi_t *data_collection_model_ncgi_set_nid_move(data_collection_model_ncgi_t *obj_ncgi, char* p_nid)
{
    if (obj_ncgi == NULL) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    const auto &value_from = p_nid;
    typedef typename Ncgi::NidType ValueType;

    ValueType value(value_from);
    
    if (!obj->setNid(std::move(value))) return NULL;
    return obj_ncgi;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ncgi_make_lnode(data_collection_model_ncgi_t *p_ncgi)
{
    return data_collection_lnode_create(p_ncgi, reinterpret_cast<void(*)(void*)>(data_collection_model_ncgi_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ncgi_refcount(data_collection_model_ncgi_t *obj_ncgi)
{
    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

