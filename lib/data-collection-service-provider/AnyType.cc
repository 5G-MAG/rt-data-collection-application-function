/**********************************************************************************************************************************
 * AnyType - Public C interface to the AnyType object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#include "utilities.h"
#include "openapi/model/AnyType.hh"
#include "data-collection-sp/data-collection.h"

using namespace fiveg_mag_reftools;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_any_type_t *data_collection_model_any_type_create()
{
    return reinterpret_cast<data_collection_model_any_type_t*>(new std::shared_ptr<AnyType>(new AnyType()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_any_type_t *data_collection_model_any_type_create_copy(const data_collection_model_any_type_t *other)
{
    return reinterpret_cast<data_collection_model_any_type_t*>(new std::shared_ptr<AnyType>(new AnyType(**reinterpret_cast<const std::shared_ptr<AnyType>*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_any_type_t *data_collection_model_any_type_create_move(data_collection_model_any_type_t *other)
{
    return reinterpret_cast<data_collection_model_any_type_t*>(new std::shared_ptr<AnyType>(std::move(*reinterpret_cast<std::shared_ptr<AnyType>*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_any_type_t *data_collection_model_any_type_copy(data_collection_model_any_type_t *any_type, const data_collection_model_any_type_t *other)
{
    std::shared_ptr<AnyType> &obj = *reinterpret_cast<std::shared_ptr<AnyType>*>(any_type);
    *obj = **reinterpret_cast<const std::shared_ptr<AnyType>*>(other);
    return any_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_any_type_t *data_collection_model_any_type_move(data_collection_model_any_type_t *any_type, data_collection_model_any_type_t *other)
{
    std::shared_ptr<AnyType> &obj = *reinterpret_cast<std::shared_ptr<AnyType>*>(any_type);
    obj = std::move(*reinterpret_cast<std::shared_ptr<AnyType>*>(other));
    return any_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_any_type_free(data_collection_model_any_type_t *any_type)
{
    delete reinterpret_cast<std::shared_ptr<AnyType>*>(any_type);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_any_type_toJSON(const data_collection_model_any_type_t *any_type, bool as_request)
{
    const std::shared_ptr<AnyType> &obj = *reinterpret_cast<const std::shared_ptr<AnyType>*>(any_type);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_any_type_t *data_collection_model_any_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_any_type_t*>(new std::shared_ptr<AnyType>(new AnyType(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_any_type_is_equal_to(const data_collection_model_any_type_t *any_type, const data_collection_model_any_type_t *other)
{
    const std::shared_ptr<AnyType> &obj = *reinterpret_cast<const std::shared_ptr<AnyType>*>(any_type);
    const std::shared_ptr<AnyType> &other_obj = *reinterpret_cast<const std::shared_ptr<AnyType>*>(other);
    return obj == other_obj || *obj == *other_obj;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
