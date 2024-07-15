/**********************************************************************************************************************************
 * CellIdentifierType - C interface to the CellIdentifierType object
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

/*#include "CellIdentifierType.h" already included by data-collection-sp/data-collection.h */
#include "CellIdentifierType-internal.h"
#include "openapi/model/CellIdentifierType.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cell_identifier_type_t *data_collection_model_cell_identifier_type_create()
{
    return reinterpret_cast<data_collection_model_cell_identifier_type_t*>(new std::shared_ptr<CellIdentifierType>(new CellIdentifierType()));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cell_identifier_type_t *data_collection_model_cell_identifier_type_create_copy(const data_collection_model_cell_identifier_type_t *other)
{
    return reinterpret_cast<data_collection_model_cell_identifier_type_t*>(new std::shared_ptr<CellIdentifierType >(new CellIdentifierType(**reinterpret_cast<const std::shared_ptr<CellIdentifierType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cell_identifier_type_t *data_collection_model_cell_identifier_type_create_move(data_collection_model_cell_identifier_type_t *other)
{
    return reinterpret_cast<data_collection_model_cell_identifier_type_t*>(new std::shared_ptr<CellIdentifierType >(std::move(*reinterpret_cast<std::shared_ptr<CellIdentifierType >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cell_identifier_type_t *data_collection_model_cell_identifier_type_copy(data_collection_model_cell_identifier_type_t *cell_identifier_type, const data_collection_model_cell_identifier_type_t *other)
{
    std::shared_ptr<CellIdentifierType > &obj = *reinterpret_cast<std::shared_ptr<CellIdentifierType >*>(cell_identifier_type);
    *obj = **reinterpret_cast<const std::shared_ptr<CellIdentifierType >*>(other);
    return cell_identifier_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cell_identifier_type_t *data_collection_model_cell_identifier_type_move(data_collection_model_cell_identifier_type_t *cell_identifier_type, data_collection_model_cell_identifier_type_t *other)
{
    std::shared_ptr<CellIdentifierType > &obj = *reinterpret_cast<std::shared_ptr<CellIdentifierType >*>(cell_identifier_type);
    obj = std::move(*reinterpret_cast<std::shared_ptr<CellIdentifierType >*>(other));
    return cell_identifier_type;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_cell_identifier_type_free(data_collection_model_cell_identifier_type_t *cell_identifier_type)
{
    delete reinterpret_cast<std::shared_ptr<CellIdentifierType >*>(cell_identifier_type);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_cell_identifier_type_toJSON(const data_collection_model_cell_identifier_type_t *cell_identifier_type, bool as_request)
{
    const std::shared_ptr<CellIdentifierType > &obj = *reinterpret_cast<const std::shared_ptr<CellIdentifierType >*>(cell_identifier_type);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_cell_identifier_type_t *data_collection_model_cell_identifier_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_cell_identifier_type_t*>(new std::shared_ptr<CellIdentifierType >(new CellIdentifierType(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cell_identifier_type_is_not_set(const data_collection_model_cell_identifier_type_t *obj_cell_identifier_type)
{
    const std::shared_ptr<CellIdentifierType > &obj = *reinterpret_cast<const std::shared_ptr<CellIdentifierType >*>(obj_cell_identifier_type);
    return obj->getValue() == CellIdentifierType::Enum::NO_VAL;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cell_identifier_type_is_non_standard(const data_collection_model_cell_identifier_type_t *obj_cell_identifier_type)
{
    const std::shared_ptr<CellIdentifierType > &obj = *reinterpret_cast<const std::shared_ptr<CellIdentifierType >*>(obj_cell_identifier_type);
    return obj->getValue() == CellIdentifierType::Enum::OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_cell_identifier_type_e data_collection_model_cell_identifier_type_get_enum(const data_collection_model_cell_identifier_type_t *obj_cell_identifier_type)
{
    const std::shared_ptr<CellIdentifierType > &obj = *reinterpret_cast<const std::shared_ptr<CellIdentifierType >*>(obj_cell_identifier_type);
    switch (obj->getValue()) {
    case CellIdentifierType::Enum::NO_VAL:
        return DCM_CELL_IDENTIFIER_TYPE_NO_VAL;
    case CellIdentifierType::Enum::VAL_CGI:
        return DCM_CELL_IDENTIFIER_TYPE_VAL_CGI;
    case CellIdentifierType::Enum::VAL_ECGI:
        return DCM_CELL_IDENTIFIER_TYPE_VAL_ECGI;
    case CellIdentifierType::Enum::VAL_NCGI:
        return DCM_CELL_IDENTIFIER_TYPE_VAL_NCGI;
    default:
        break;
    }
    return DCM_CELL_IDENTIFIER_TYPE_OTHER;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_cell_identifier_type_get_string(const data_collection_model_cell_identifier_type_t *obj_cell_identifier_type)
{
    const std::shared_ptr<CellIdentifierType > &obj = *reinterpret_cast<const std::shared_ptr<CellIdentifierType >*>(obj_cell_identifier_type);
    return obj->getString().c_str();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cell_identifier_type_set_enum(data_collection_model_cell_identifier_type_t *obj_cell_identifier_type, data_collection_model_cell_identifier_type_e p_value)
{
    std::shared_ptr<CellIdentifierType > &obj = *reinterpret_cast<std::shared_ptr<CellIdentifierType >*>(obj_cell_identifier_type);
    switch (p_value) {
    case DCM_CELL_IDENTIFIER_TYPE_NO_VAL:
        *obj = CellIdentifierType::Enum::NO_VAL;
        return true;
    case DCM_CELL_IDENTIFIER_TYPE_VAL_CGI:
        *obj = CellIdentifierType::Enum::VAL_CGI;
        return true;
    case DCM_CELL_IDENTIFIER_TYPE_VAL_ECGI:
        *obj = CellIdentifierType::Enum::VAL_ECGI;
        return true;
    case DCM_CELL_IDENTIFIER_TYPE_VAL_NCGI:
        *obj = CellIdentifierType::Enum::VAL_NCGI;
        return true;
    default:
        break;
    }
    return false;
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_cell_identifier_type_set_string(data_collection_model_cell_identifier_type_t *obj_cell_identifier_type, const char *p_value)
{
    std::shared_ptr<CellIdentifierType > &obj = *reinterpret_cast<std::shared_ptr<CellIdentifierType >*>(obj_cell_identifier_type);
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = CellIdentifierType::Enum::NO_VAL;
    }
    return true;
}



DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_cell_identifier_type_make_lnode(data_collection_model_cell_identifier_type_t *p_cell_identifier_type)
{
    return data_collection_lnode_create(p_cell_identifier_type, reinterpret_cast<void(*)(void*)>(data_collection_model_cell_identifier_type_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_cell_identifier_type_refcount(data_collection_model_cell_identifier_type_t *obj_cell_identifier_type)
{
    std::shared_ptr<CellIdentifierType > &obj = *reinterpret_cast<std::shared_ptr<CellIdentifierType >*>(obj_cell_identifier_type);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

