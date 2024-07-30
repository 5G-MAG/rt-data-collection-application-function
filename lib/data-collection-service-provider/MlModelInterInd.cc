/**********************************************************************************************************************************
 * MlModelInterInd - C interface to the MlModelInterInd object
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

/*#include "MlModelInterInd.h" already included by data-collection-sp/data-collection.h */
#include "MlModelInterInd-internal.h"
#include "openapi/model/MlModelInterInd.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_create(

)
{
    return reinterpret_cast<data_collection_model_ml_model_inter_ind_t*>(new std::shared_ptr<MlModelInterInd>(new MlModelInterInd(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_create_copy(const data_collection_model_ml_model_inter_ind_t *other)
{
    return reinterpret_cast<data_collection_model_ml_model_inter_ind_t*>(new std::shared_ptr<MlModelInterInd >(new MlModelInterInd(**reinterpret_cast<const std::shared_ptr<MlModelInterInd >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_create_move(data_collection_model_ml_model_inter_ind_t *other)
{
    return reinterpret_cast<data_collection_model_ml_model_inter_ind_t*>(new std::shared_ptr<MlModelInterInd >(std::move(*reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_copy(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const data_collection_model_ml_model_inter_ind_t *other)
{
    std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(ml_model_inter_ind);
    *obj = **reinterpret_cast<const std::shared_ptr<MlModelInterInd >*>(other);
    return ml_model_inter_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_move(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, data_collection_model_ml_model_inter_ind_t *other)
{
    std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(ml_model_inter_ind);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(other));
    return ml_model_inter_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ml_model_inter_ind_free(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind)
{
    delete reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(ml_model_inter_ind);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ml_model_inter_ind_toJSON(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, bool as_request)
{
    const std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<const std::shared_ptr<MlModelInterInd >*>(ml_model_inter_ind);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ml_model_inter_ind_t*>(new std::shared_ptr<MlModelInterInd >(new MlModelInterInd(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_ml_model_inter_ind_is_equal_to(const data_collection_model_ml_model_inter_ind_t *first, const data_collection_model_ml_model_inter_ind_t *second)
{
    const std::shared_ptr<MlModelInterInd > &obj1 = *reinterpret_cast<const std::shared_ptr<MlModelInterInd >*>(first);
    const std::shared_ptr<MlModelInterInd > &obj2 = *reinterpret_cast<const std::shared_ptr<MlModelInterInd >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_nwdaf_event_t* data_collection_model_ml_model_inter_ind_get_analytics_id(const data_collection_model_ml_model_inter_ind_t *obj_ml_model_inter_ind)
{
    const std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<const std::shared_ptr<MlModelInterInd >*>(obj_ml_model_inter_ind);
    typedef typename MlModelInterInd::AnalyticsIdType ResultFromType;
    const ResultFromType result_from = obj->getAnalyticsId();
    const data_collection_model_nwdaf_event_t *result = reinterpret_cast<const data_collection_model_nwdaf_event_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_analytics_id(data_collection_model_ml_model_inter_ind_t *obj_ml_model_inter_ind, const data_collection_model_nwdaf_event_t* p_analytics_id)
{
    if (obj_ml_model_inter_ind == NULL) return NULL;

    std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(obj_ml_model_inter_ind);
    const auto &value_from = p_analytics_id;
    typedef typename MlModelInterInd::AnalyticsIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setAnalyticsId(value)) return NULL;
    return obj_ml_model_inter_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_analytics_id_move(data_collection_model_ml_model_inter_ind_t *obj_ml_model_inter_ind, data_collection_model_nwdaf_event_t* p_analytics_id)
{
    if (obj_ml_model_inter_ind == NULL) return NULL;

    std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(obj_ml_model_inter_ind);
    const auto &value_from = p_analytics_id;
    typedef typename MlModelInterInd::AnalyticsIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setAnalyticsId(std::move(value))) return NULL;
    return obj_ml_model_inter_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" ogs_list_t* data_collection_model_ml_model_inter_ind_get_vendor_list(const data_collection_model_ml_model_inter_ind_t *obj_ml_model_inter_ind)
{
    const std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<const std::shared_ptr<MlModelInterInd >*>(obj_ml_model_inter_ind);
    typedef typename MlModelInterInd::VendorListType ResultFromType;
    const ResultFromType result_from = obj->getVendorList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(ogs_calloc(1, sizeof(*result)));
    typedef typename ResultFromType::value_type ItemType;
    for (const ItemType &item : result_from) {
        data_collection_lnode_t *node;
        node = data_collection_lnode_create(data_collection_strdup(item.c_str()), reinterpret_cast<void(*)(void*)>(_ogs_free));
        
        ogs_list_add(result, node);
    }
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_vendor_list(data_collection_model_ml_model_inter_ind_t *obj_ml_model_inter_ind, const ogs_list_t* p_vendor_list)
{
    if (obj_ml_model_inter_ind == NULL) return NULL;

    std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(obj_ml_model_inter_ind);
    const auto &value_from = p_vendor_list;
    typedef typename MlModelInterInd::VendorListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    if (!obj->setVendorList(value)) return NULL;
    return obj_ml_model_inter_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_vendor_list_move(data_collection_model_ml_model_inter_ind_t *obj_ml_model_inter_ind, ogs_list_t* p_vendor_list)
{
    if (obj_ml_model_inter_ind == NULL) return NULL;

    std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(obj_ml_model_inter_ind);
    const auto &value_from = p_vendor_list;
    typedef typename MlModelInterInd::VendorListType ValueType;

    ValueType value;
    {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type ItemType;
        ogs_list_for_each(value_from, lnode) {
    	value.push_back(ItemType((const char *)lnode->object));
            
        }
    }
    data_collection_list_free(p_vendor_list);
    if (!obj->setVendorList(std::move(value))) return NULL;
    return obj_ml_model_inter_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_add_vendor_list(data_collection_model_ml_model_inter_ind_t *obj_ml_model_inter_ind, char* p_vendor_list)
{
    std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(obj_ml_model_inter_ind);
    typedef typename MlModelInterInd::VendorListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_vendor_list;

    ValueType value(value_from);

    obj->addVendorList(value);
    return obj_ml_model_inter_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_remove_vendor_list(data_collection_model_ml_model_inter_ind_t *obj_ml_model_inter_ind, const char* p_vendor_list)
{
    std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(obj_ml_model_inter_ind);
    typedef typename MlModelInterInd::VendorListType ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_vendor_list;
    ValueType value(value_from);
    obj->removeVendorList(value);
    return obj_ml_model_inter_ind;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_clear_vendor_list(data_collection_model_ml_model_inter_ind_t *obj_ml_model_inter_ind)
{   
    std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(obj_ml_model_inter_ind);
    obj->clearVendorList();
    return obj_ml_model_inter_ind;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ml_model_inter_ind_make_lnode(data_collection_model_ml_model_inter_ind_t *p_ml_model_inter_ind)
{
    return data_collection_lnode_create(p_ml_model_inter_ind, reinterpret_cast<void(*)(void*)>(data_collection_model_ml_model_inter_ind_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ml_model_inter_ind_refcount(data_collection_model_ml_model_inter_ind_t *obj_ml_model_inter_ind)
{
    std::shared_ptr<MlModelInterInd > &obj = *reinterpret_cast<std::shared_ptr<MlModelInterInd >*>(obj_ml_model_inter_ind);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

