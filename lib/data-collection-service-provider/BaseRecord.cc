/**********************************************************************************************************************************
 * BaseRecord - C interface to the BaseRecord object
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

/*#include "BaseRecord.h" already included by data-collection-sp/data-collection.h */
#include "BaseRecord-internal.h"
#include "openapi/model/BaseRecord.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_t *data_collection_model_base_record_create(
)
{
    return reinterpret_cast<data_collection_model_base_record_t*>(new std::shared_ptr<BaseRecord>(new BaseRecord(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_t *data_collection_model_base_record_create_copy(const data_collection_model_base_record_t *other)
{
    return reinterpret_cast<data_collection_model_base_record_t*>(new std::shared_ptr<BaseRecord >(new BaseRecord(**reinterpret_cast<const std::shared_ptr<BaseRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_t *data_collection_model_base_record_create_move(data_collection_model_base_record_t *other)
{
    return reinterpret_cast<data_collection_model_base_record_t*>(new std::shared_ptr<BaseRecord >(std::move(*reinterpret_cast<std::shared_ptr<BaseRecord >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_t *data_collection_model_base_record_copy(data_collection_model_base_record_t *base_record, const data_collection_model_base_record_t *other)
{
    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(base_record);
    *obj = **reinterpret_cast<const std::shared_ptr<BaseRecord >*>(other);
    return base_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_t *data_collection_model_base_record_move(data_collection_model_base_record_t *base_record, data_collection_model_base_record_t *other)
{
    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(base_record);
    obj = std::move(*reinterpret_cast<std::shared_ptr<BaseRecord >*>(other));
    return base_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_base_record_free(data_collection_model_base_record_t *base_record)
{
    delete reinterpret_cast<std::shared_ptr<BaseRecord >*>(base_record);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_base_record_toJSON(const data_collection_model_base_record_t *base_record, bool as_request)
{
    const std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(base_record);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_t *data_collection_model_base_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_base_record_t*>(new std::shared_ptr<BaseRecord >(new BaseRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_base_record_get_timestamp(const data_collection_model_base_record_t *obj_base_record)
{
    const std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<const std::shared_ptr<BaseRecord >*>(obj_base_record);
    typedef typename BaseRecord::TimestampType ResultFromType;
    const ResultFromType result_from = obj->getTimestamp();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_t *data_collection_model_base_record_set_timestamp(data_collection_model_base_record_t *obj_base_record, const char* p_timestamp)
{
    if (obj_base_record == NULL) return NULL;

    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    const auto &value_from = p_timestamp;
    typedef typename BaseRecord::TimestampType ValueType;

    ValueType value(value_from);
    if (!obj->setTimestamp(value)) return NULL;
    return obj_base_record;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_base_record_t *data_collection_model_base_record_set_timestamp_move(data_collection_model_base_record_t *obj_base_record, char* p_timestamp)
{
    if (obj_base_record == NULL) return NULL;

    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    const auto &value_from = p_timestamp;
    typedef typename BaseRecord::TimestampType ValueType;

    ValueType value(value_from);
    
    if (!obj->setTimestamp(std::move(value))) return NULL;
    return obj_base_record;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_base_record_make_lnode(data_collection_model_base_record_t *p_base_record)
{
    return data_collection_lnode_create(p_base_record, reinterpret_cast<void(*)(void*)>(data_collection_model_base_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_base_record_refcount(data_collection_model_base_record_t *obj_base_record)
{
    std::shared_ptr<BaseRecord > &obj = *reinterpret_cast<std::shared_ptr<BaseRecord >*>(obj_base_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

