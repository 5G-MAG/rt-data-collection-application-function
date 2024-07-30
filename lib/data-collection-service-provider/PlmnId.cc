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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_t *data_collection_model_plmn_id_create(

)
{
    return reinterpret_cast<data_collection_model_plmn_id_t*>(new std::shared_ptr<PlmnId>(new PlmnId(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_t *data_collection_model_plmn_id_create_copy(const data_collection_model_plmn_id_t *other)
{
    return reinterpret_cast<data_collection_model_plmn_id_t*>(new std::shared_ptr<PlmnId >(new PlmnId(**reinterpret_cast<const std::shared_ptr<PlmnId >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_t *data_collection_model_plmn_id_create_move(data_collection_model_plmn_id_t *other)
{
    return reinterpret_cast<data_collection_model_plmn_id_t*>(new std::shared_ptr<PlmnId >(std::move(*reinterpret_cast<std::shared_ptr<PlmnId >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_t *data_collection_model_plmn_id_copy(data_collection_model_plmn_id_t *plmn_id, const data_collection_model_plmn_id_t *other)
{
    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(plmn_id);
    *obj = **reinterpret_cast<const std::shared_ptr<PlmnId >*>(other);
    return plmn_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_t *data_collection_model_plmn_id_move(data_collection_model_plmn_id_t *plmn_id, data_collection_model_plmn_id_t *other)
{
    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(plmn_id);
    obj = std::move(*reinterpret_cast<std::shared_ptr<PlmnId >*>(other));
    return plmn_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_plmn_id_free(data_collection_model_plmn_id_t *plmn_id)
{
    delete reinterpret_cast<std::shared_ptr<PlmnId >*>(plmn_id);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_plmn_id_toJSON(const data_collection_model_plmn_id_t *plmn_id, bool as_request)
{
    const std::shared_ptr<PlmnId > &obj = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(plmn_id);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_t *data_collection_model_plmn_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_plmn_id_is_equal_to(const data_collection_model_plmn_id_t *first, const data_collection_model_plmn_id_t *second)
{
    const std::shared_ptr<PlmnId > &obj1 = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(first);
    const std::shared_ptr<PlmnId > &obj2 = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_plmn_id_get_mcc(const data_collection_model_plmn_id_t *obj_plmn_id)
{
    const std::shared_ptr<PlmnId > &obj = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(obj_plmn_id);
    typedef typename PlmnId::MccType ResultFromType;
    const ResultFromType result_from = obj->getMcc();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mcc(data_collection_model_plmn_id_t *obj_plmn_id, const char* p_mcc)
{
    if (obj_plmn_id == NULL) return NULL;

    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(obj_plmn_id);
    const auto &value_from = p_mcc;
    typedef typename PlmnId::MccType ValueType;

    ValueType value(value_from);
    if (!obj->setMcc(value)) return NULL;
    return obj_plmn_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mcc_move(data_collection_model_plmn_id_t *obj_plmn_id, char* p_mcc)
{
    if (obj_plmn_id == NULL) return NULL;

    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(obj_plmn_id);
    const auto &value_from = p_mcc;
    typedef typename PlmnId::MccType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMcc(std::move(value))) return NULL;
    return obj_plmn_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_plmn_id_get_mnc(const data_collection_model_plmn_id_t *obj_plmn_id)
{
    const std::shared_ptr<PlmnId > &obj = *reinterpret_cast<const std::shared_ptr<PlmnId >*>(obj_plmn_id);
    typedef typename PlmnId::MncType ResultFromType;
    const ResultFromType result_from = obj->getMnc();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mnc(data_collection_model_plmn_id_t *obj_plmn_id, const char* p_mnc)
{
    if (obj_plmn_id == NULL) return NULL;

    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(obj_plmn_id);
    const auto &value_from = p_mnc;
    typedef typename PlmnId::MncType ValueType;

    ValueType value(value_from);
    if (!obj->setMnc(value)) return NULL;
    return obj_plmn_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_plmn_id_t *data_collection_model_plmn_id_set_mnc_move(data_collection_model_plmn_id_t *obj_plmn_id, char* p_mnc)
{
    if (obj_plmn_id == NULL) return NULL;

    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(obj_plmn_id);
    const auto &value_from = p_mnc;
    typedef typename PlmnId::MncType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMnc(std::move(value))) return NULL;
    return obj_plmn_id;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_plmn_id_make_lnode(data_collection_model_plmn_id_t *p_plmn_id)
{
    return data_collection_lnode_create(p_plmn_id, reinterpret_cast<void(*)(void*)>(data_collection_model_plmn_id_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_plmn_id_refcount(data_collection_model_plmn_id_t *obj_plmn_id)
{
    std::shared_ptr<PlmnId > &obj = *reinterpret_cast<std::shared_ptr<PlmnId >*>(obj_plmn_id);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

