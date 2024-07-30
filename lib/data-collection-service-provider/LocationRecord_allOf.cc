/**********************************************************************************************************************************
 * LocationRecord_allOf - C interface to the LocationRecord_allOf object
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

/*#include "LocationRecord_allOf.h" already included by data-collection-sp/data-collection.h */
#include "LocationRecord_allOf-internal.h"
#include "openapi/model/LocationRecord_allOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_create(
)
{
    return reinterpret_cast<data_collection_model_location_record_all_of_t*>(new std::shared_ptr<LocationRecord_allOf>(new LocationRecord_allOf(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_create_copy(const data_collection_model_location_record_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_location_record_all_of_t*>(new std::shared_ptr<LocationRecord_allOf >(new LocationRecord_allOf(**reinterpret_cast<const std::shared_ptr<LocationRecord_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_create_move(data_collection_model_location_record_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_location_record_all_of_t*>(new std::shared_ptr<LocationRecord_allOf >(std::move(*reinterpret_cast<std::shared_ptr<LocationRecord_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_copy(data_collection_model_location_record_all_of_t *location_record_all_of, const data_collection_model_location_record_all_of_t *other)
{
    std::shared_ptr<LocationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord_allOf >*>(location_record_all_of);
    *obj = **reinterpret_cast<const std::shared_ptr<LocationRecord_allOf >*>(other);
    return location_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_move(data_collection_model_location_record_all_of_t *location_record_all_of, data_collection_model_location_record_all_of_t *other)
{
    std::shared_ptr<LocationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord_allOf >*>(location_record_all_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<LocationRecord_allOf >*>(other));
    return location_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_location_record_all_of_free(data_collection_model_location_record_all_of_t *location_record_all_of)
{
    delete reinterpret_cast<std::shared_ptr<LocationRecord_allOf >*>(location_record_all_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_location_record_all_of_toJSON(const data_collection_model_location_record_all_of_t *location_record_all_of, bool as_request)
{
    const std::shared_ptr<LocationRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<LocationRecord_allOf >*>(location_record_all_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_location_record_all_of_t*>(new std::shared_ptr<LocationRecord_allOf >(new LocationRecord_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_location_record_all_of_is_equal_to(const data_collection_model_location_record_all_of_t *first, const data_collection_model_location_record_all_of_t *second)
{
    const std::shared_ptr<LocationRecord_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<LocationRecord_allOf >*>(first);
    const std::shared_ptr<LocationRecord_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<LocationRecord_allOf >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_location_data_t* data_collection_model_location_record_all_of_get_location(const data_collection_model_location_record_all_of_t *obj_location_record_all_of)
{
    const std::shared_ptr<LocationRecord_allOf > &obj = *reinterpret_cast<const std::shared_ptr<LocationRecord_allOf >*>(obj_location_record_all_of);
    typedef typename LocationRecord_allOf::LocationType ResultFromType;
    const ResultFromType result_from = obj->getLocation();
    const data_collection_model_location_data_t *result = reinterpret_cast<const data_collection_model_location_data_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_set_location(data_collection_model_location_record_all_of_t *obj_location_record_all_of, const data_collection_model_location_data_t* p_location)
{
    if (obj_location_record_all_of == NULL) return NULL;

    std::shared_ptr<LocationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord_allOf >*>(obj_location_record_all_of);
    const auto &value_from = p_location;
    typedef typename LocationRecord_allOf::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setLocation(value)) return NULL;
    return obj_location_record_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_location_record_all_of_t *data_collection_model_location_record_all_of_set_location_move(data_collection_model_location_record_all_of_t *obj_location_record_all_of, data_collection_model_location_data_t* p_location)
{
    if (obj_location_record_all_of == NULL) return NULL;

    std::shared_ptr<LocationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord_allOf >*>(obj_location_record_all_of);
    const auto &value_from = p_location;
    typedef typename LocationRecord_allOf::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setLocation(std::move(value))) return NULL;
    return obj_location_record_all_of;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_location_record_all_of_make_lnode(data_collection_model_location_record_all_of_t *p_location_record_all_of)
{
    return data_collection_lnode_create(p_location_record_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_location_record_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_location_record_all_of_refcount(data_collection_model_location_record_all_of_t *obj_location_record_all_of)
{
    std::shared_ptr<LocationRecord_allOf > &obj = *reinterpret_cast<std::shared_ptr<LocationRecord_allOf >*>(obj_location_record_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

