/**********************************************************************************************************************************
 * MsConsumptionCollection - C interface to the MsConsumptionCollection object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "MsConsumptionCollection.h" already included by data-collection-sp/data-collection.h */
#include "MsConsumptionCollection-internal.h"
#include "openapi/model/MsConsumptionCollection.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_create(
)
{
    return reinterpret_cast<data_collection_model_ms_consumption_collection_t*>(new std::shared_ptr<MsConsumptionCollection>(new MsConsumptionCollection(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_create_copy(const data_collection_model_ms_consumption_collection_t *other)
{
    return reinterpret_cast<data_collection_model_ms_consumption_collection_t*>(new std::shared_ptr<MsConsumptionCollection >(new MsConsumptionCollection(**reinterpret_cast<const std::shared_ptr<MsConsumptionCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_create_move(data_collection_model_ms_consumption_collection_t *other)
{
    return reinterpret_cast<data_collection_model_ms_consumption_collection_t*>(new std::shared_ptr<MsConsumptionCollection >(std::move(*reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_copy(data_collection_model_ms_consumption_collection_t *ms_consumption_collection, const data_collection_model_ms_consumption_collection_t *other)
{
    std::shared_ptr<MsConsumptionCollection > &obj = *reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(ms_consumption_collection);
    *obj = **reinterpret_cast<const std::shared_ptr<MsConsumptionCollection >*>(other);
    return ms_consumption_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_move(data_collection_model_ms_consumption_collection_t *ms_consumption_collection, data_collection_model_ms_consumption_collection_t *other)
{
    std::shared_ptr<MsConsumptionCollection > &obj = *reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(ms_consumption_collection);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(other));
    return ms_consumption_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ms_consumption_collection_free(data_collection_model_ms_consumption_collection_t *ms_consumption_collection)
{
    delete reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(ms_consumption_collection);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ms_consumption_collection_toJSON(const data_collection_model_ms_consumption_collection_t *ms_consumption_collection, bool as_request)
{
    const std::shared_ptr<MsConsumptionCollection > &obj = *reinterpret_cast<const std::shared_ptr<MsConsumptionCollection >*>(ms_consumption_collection);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ms_consumption_collection_t*>(new std::shared_ptr<MsConsumptionCollection >(new MsConsumptionCollection(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_ms_consumption_collection_get_ms_consumps(const data_collection_model_ms_consumption_collection_t *obj_ms_consumption_collection)
{
    const std::shared_ptr<MsConsumptionCollection > &obj = *reinterpret_cast<const std::shared_ptr<MsConsumptionCollection >*>(obj_ms_consumption_collection);
    typedef typename MsConsumptionCollection::MsConsumpsType ResultFromType;
    const ResultFromType result_from = obj->getMsConsumps();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_set_ms_consumps(data_collection_model_ms_consumption_collection_t *obj_ms_consumption_collection, const ogs_list_t* p_ms_consumps)
{
    if (obj_ms_consumption_collection == NULL) return NULL;

    std::shared_ptr<MsConsumptionCollection > &obj = *reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(obj_ms_consumption_collection);
    const auto &value_from = p_ms_consumps;
    typedef typename MsConsumptionCollection::MsConsumpsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setMsConsumps(value)) return NULL;
    return obj_ms_consumption_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_set_ms_consumps_move(data_collection_model_ms_consumption_collection_t *obj_ms_consumption_collection, ogs_list_t* p_ms_consumps)
{
    if (obj_ms_consumption_collection == NULL) return NULL;

    std::shared_ptr<MsConsumptionCollection > &obj = *reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(obj_ms_consumption_collection);
    const auto &value_from = p_ms_consumps;
    typedef typename MsConsumptionCollection::MsConsumpsType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_ms_consumps);
    if (!obj->setMsConsumps(std::move(value))) return NULL;
    return obj_ms_consumption_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_add_ms_consumps(data_collection_model_ms_consumption_collection_t *obj_ms_consumption_collection, char* p_ms_consumps)
{
    std::shared_ptr<MsConsumptionCollection > &obj = *reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(obj_ms_consumption_collection);
    typedef typename MsConsumptionCollection::MsConsumpsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_ms_consumps;

    ValueType value(value_from);

    obj->addMsConsumps(value);
    return obj_ms_consumption_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_remove_ms_consumps(data_collection_model_ms_consumption_collection_t *obj_ms_consumption_collection, const char* p_ms_consumps)
{
    std::shared_ptr<MsConsumptionCollection > &obj = *reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(obj_ms_consumption_collection);
    typedef typename MsConsumptionCollection::MsConsumpsType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_ms_consumps;
    ValueType value(value_from);
    obj->removeMsConsumps(value);
    return obj_ms_consumption_collection;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ms_consumption_collection_t *data_collection_model_ms_consumption_collection_clear_ms_consumps(data_collection_model_ms_consumption_collection_t *obj_ms_consumption_collection)
{   
    std::shared_ptr<MsConsumptionCollection > &obj = *reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(obj_ms_consumption_collection);
    obj->clearMsConsumps();
    return obj_ms_consumption_collection;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ms_consumption_collection_make_lnode(data_collection_model_ms_consumption_collection_t *p_ms_consumption_collection)
{
    return data_collection_lnode_create(p_ms_consumption_collection, reinterpret_cast<void(*)(void*)>(data_collection_model_ms_consumption_collection_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ms_consumption_collection_refcount(data_collection_model_ms_consumption_collection_t *obj_ms_consumption_collection)
{
    std::shared_ptr<MsConsumptionCollection > &obj = *reinterpret_cast<std::shared_ptr<MsConsumptionCollection >*>(obj_ms_consumption_collection);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

