/**********************************************************************************************************************************
 * GNbId - C interface to the GNbId object
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

/*#include "GNbId.h" already included by data-collection-sp/data-collection.h */
#include "GNbId-internal.h"
#include "openapi/model/GNbId.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnb_id_t *data_collection_model_gnb_id_create(

)
{
    return reinterpret_cast<data_collection_model_gnb_id_t*>(new std::shared_ptr<GNbId>(new GNbId(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnb_id_t *data_collection_model_gnb_id_create_copy(const data_collection_model_gnb_id_t *other)
{
    return reinterpret_cast<data_collection_model_gnb_id_t*>(new std::shared_ptr<GNbId >(new GNbId(**reinterpret_cast<const std::shared_ptr<GNbId >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnb_id_t *data_collection_model_gnb_id_create_move(data_collection_model_gnb_id_t *other)
{
    return reinterpret_cast<data_collection_model_gnb_id_t*>(new std::shared_ptr<GNbId >(std::move(*reinterpret_cast<std::shared_ptr<GNbId >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnb_id_t *data_collection_model_gnb_id_copy(data_collection_model_gnb_id_t *gnb_id, const data_collection_model_gnb_id_t *other)
{
    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(gnb_id);
    *obj = **reinterpret_cast<const std::shared_ptr<GNbId >*>(other);
    return gnb_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnb_id_t *data_collection_model_gnb_id_move(data_collection_model_gnb_id_t *gnb_id, data_collection_model_gnb_id_t *other)
{
    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(gnb_id);
    obj = std::move(*reinterpret_cast<std::shared_ptr<GNbId >*>(other));
    return gnb_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_gnb_id_free(data_collection_model_gnb_id_t *gnb_id)
{
    delete reinterpret_cast<std::shared_ptr<GNbId >*>(gnb_id);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_gnb_id_toJSON(const data_collection_model_gnb_id_t *gnb_id, bool as_request)
{
    const std::shared_ptr<GNbId > &obj = *reinterpret_cast<const std::shared_ptr<GNbId >*>(gnb_id);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnb_id_t *data_collection_model_gnb_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_gnb_id_t*>(new std::shared_ptr<GNbId >(new GNbId(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const int32_t data_collection_model_gnb_id_get_bit_length(const data_collection_model_gnb_id_t *obj_gnb_id)
{
    const std::shared_ptr<GNbId > &obj = *reinterpret_cast<const std::shared_ptr<GNbId >*>(obj_gnb_id);
    typedef typename GNbId::BitLengthType ResultFromType;
    const ResultFromType result_from = obj->getBitLength();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_bit_length(data_collection_model_gnb_id_t *obj_gnb_id, const int32_t p_bit_length)
{
    if (obj_gnb_id == NULL) return NULL;

    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(obj_gnb_id);
    const auto &value_from = p_bit_length;
    typedef typename GNbId::BitLengthType ValueType;

    ValueType value = value_from;
    if (!obj->setBitLength(value)) return NULL;
    return obj_gnb_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_bit_length_move(data_collection_model_gnb_id_t *obj_gnb_id, int32_t p_bit_length)
{
    if (obj_gnb_id == NULL) return NULL;

    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(obj_gnb_id);
    const auto &value_from = p_bit_length;
    typedef typename GNbId::BitLengthType ValueType;

    ValueType value = value_from;
    
    if (!obj->setBitLength(std::move(value))) return NULL;
    return obj_gnb_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_gnb_id_get_gnb_value(const data_collection_model_gnb_id_t *obj_gnb_id)
{
    const std::shared_ptr<GNbId > &obj = *reinterpret_cast<const std::shared_ptr<GNbId >*>(obj_gnb_id);
    typedef typename GNbId::GNBValueType ResultFromType;
    const ResultFromType result_from = obj->getGNBValue();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_gnb_value(data_collection_model_gnb_id_t *obj_gnb_id, const char* p_gnb_value)
{
    if (obj_gnb_id == NULL) return NULL;

    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(obj_gnb_id);
    const auto &value_from = p_gnb_value;
    typedef typename GNbId::GNBValueType ValueType;

    ValueType value(value_from);
    if (!obj->setGNBValue(value)) return NULL;
    return obj_gnb_id;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_gnb_value_move(data_collection_model_gnb_id_t *obj_gnb_id, char* p_gnb_value)
{
    if (obj_gnb_id == NULL) return NULL;

    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(obj_gnb_id);
    const auto &value_from = p_gnb_value;
    typedef typename GNbId::GNBValueType ValueType;

    ValueType value(value_from);
    
    if (!obj->setGNBValue(std::move(value))) return NULL;
    return obj_gnb_id;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_gnb_id_make_lnode(data_collection_model_gnb_id_t *p_gnb_id)
{
    return data_collection_lnode_create(p_gnb_id, reinterpret_cast<void(*)(void*)>(data_collection_model_gnb_id_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_gnb_id_refcount(data_collection_model_gnb_id_t *obj_gnb_id)
{
    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(obj_gnb_id);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

