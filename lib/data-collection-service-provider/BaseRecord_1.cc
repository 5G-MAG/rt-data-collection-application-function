/**********************************************************************************************************************************
 * BaseRecord_1 - C interface to the BaseRecord_1 object
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

/*#include "BaseRecord_1.h" already included by data-collection-sp/data-collection.h */
#include "BaseRecord_1-internal.h"
#include "openapi/model/BaseRecord_1.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_create(
)
{
    return reinterpret_cast<data_collection_model_base_record_1_t*>(new std::shared_ptr<BaseRecord_1>(new BaseRecord_1(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_create_copy(const data_collection_model_base_record_1_t *other)
{
    return reinterpret_cast<data_collection_model_base_record_1_t*>(new std::shared_ptr<BaseRecord_1 >(new BaseRecord_1(**reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_create_move(data_collection_model_base_record_1_t *other)
{
    return reinterpret_cast<data_collection_model_base_record_1_t*>(new std::shared_ptr<BaseRecord_1 >(std::move(*reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_copy(data_collection_model_base_record_1_t *base_record_1, const data_collection_model_base_record_1_t *other)
{
    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(base_record_1);
    *obj = **reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(other);
    return base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_move(data_collection_model_base_record_1_t *base_record_1, data_collection_model_base_record_1_t *other)
{
    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(base_record_1);
    obj = std::move(*reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(other));
    return base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_base_record_1_free(data_collection_model_base_record_1_t *base_record_1)
{
    delete reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(base_record_1);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_base_record_1_toJSON(const data_collection_model_base_record_1_t *base_record_1, bool as_request)
{
    const std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(base_record_1);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_base_record_1_t*>(new std::shared_ptr<BaseRecord_1 >(new BaseRecord_1(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_base_record_1_get_timestamp(const data_collection_model_base_record_1_t *obj_base_record_1)
{
    const std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    typedef typename BaseRecord_1::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_set_timestamp(data_collection_model_base_record_1_t *obj_base_record_1, const char* p_timestamp)
{
    if (obj_base_record_1 == NULL) return NULL;

    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    const auto &value_from = p_timestamp;
    typedef typename BaseRecord_1::TimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimestamp(value)) return NULL;
    return obj_base_record_1;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_1_t *data_collection_model_base_record_1_set_timestamp_move(data_collection_model_base_record_1_t *obj_base_record_1, char* p_timestamp)
{
    if (obj_base_record_1 == NULL) return NULL;

    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    const auto &value_from = p_timestamp;
    typedef typename BaseRecord_1::TimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimestamp(std::move(value))) return NULL;
    return obj_base_record_1;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_base_record_1_make_lnode(data_collection_model_base_record_1_t *p_base_record_1)
{
    return data_collection_lnode_create(p_base_record_1, reinterpret_cast<void(*)(void*)>(data_collection_model_base_record_1_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_base_record_1_refcount(data_collection_model_base_record_1_t *obj_base_record_1)
{
    std::shared_ptr<BaseRecord_1 > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord_1 >*>(obj_base_record_1);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

