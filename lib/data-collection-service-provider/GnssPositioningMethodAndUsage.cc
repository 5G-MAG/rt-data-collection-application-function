/**********************************************************************************************************************************
 * GnssPositioningMethodAndUsage - C interface to the GnssPositioningMethodAndUsage object
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

/*#include "GnssPositioningMethodAndUsage.h" already included by data-collection-sp/data-collection.h */
#include "GnssPositioningMethodAndUsage-internal.h"
#include "openapi/model/GnssPositioningMethodAndUsage.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_create(


)
{
    return reinterpret_cast<data_collection_model_gnss_positioning_method_and_usage_t*>(new std::shared_ptr<GnssPositioningMethodAndUsage>(new GnssPositioningMethodAndUsage(


)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_create_copy(const data_collection_model_gnss_positioning_method_and_usage_t *other)
{
    return reinterpret_cast<data_collection_model_gnss_positioning_method_and_usage_t*>(new std::shared_ptr<GnssPositioningMethodAndUsage >(new GnssPositioningMethodAndUsage(**reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_create_move(data_collection_model_gnss_positioning_method_and_usage_t *other)
{
    return reinterpret_cast<data_collection_model_gnss_positioning_method_and_usage_t*>(new std::shared_ptr<GnssPositioningMethodAndUsage >(std::move(*reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_copy(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, const data_collection_model_gnss_positioning_method_and_usage_t *other)
{
    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(gnss_positioning_method_and_usage);
    *obj = **reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(other);
    return gnss_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_move(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, data_collection_model_gnss_positioning_method_and_usage_t *other)
{
    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(gnss_positioning_method_and_usage);
    obj = std::move(*reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(other));
    return gnss_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_gnss_positioning_method_and_usage_free(data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage)
{
    delete reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(gnss_positioning_method_and_usage);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_gnss_positioning_method_and_usage_toJSON(const data_collection_model_gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage, bool as_request)
{
    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(gnss_positioning_method_and_usage);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_gnss_positioning_method_and_usage_t*>(new std::shared_ptr<GnssPositioningMethodAndUsage >(new GnssPositioningMethodAndUsage(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_gnss_positioning_method_and_usage_is_equal_to(const data_collection_model_gnss_positioning_method_and_usage_t *first, const data_collection_model_gnss_positioning_method_and_usage_t *second)
{
    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj1 = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(first);
    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj2 = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_positioning_mode_t* data_collection_model_gnss_positioning_method_and_usage_get_mode(const data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage)
{
    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    typedef typename GnssPositioningMethodAndUsage::ModeType ResultFromType;
    const ResultFromType result_from = obj->getMode();
    const data_collection_model_positioning_mode_t *result = reinterpret_cast<const data_collection_model_positioning_mode_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_mode(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, const data_collection_model_positioning_mode_t* p_mode)
{
    if (obj_gnss_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    const auto &value_from = p_mode;
    typedef typename GnssPositioningMethodAndUsage::ModeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setMode(value)) return NULL;
    return obj_gnss_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_mode_move(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, data_collection_model_positioning_mode_t* p_mode)
{
    if (obj_gnss_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    const auto &value_from = p_mode;
    typedef typename GnssPositioningMethodAndUsage::ModeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setMode(std::move(value))) return NULL;
    return obj_gnss_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_gnss_id_t* data_collection_model_gnss_positioning_method_and_usage_get_gnss(const data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage)
{
    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    typedef typename GnssPositioningMethodAndUsage::GnssType ResultFromType;
    const ResultFromType result_from = obj->getGnss();
    const data_collection_model_gnss_id_t *result = reinterpret_cast<const data_collection_model_gnss_id_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_gnss(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, const data_collection_model_gnss_id_t* p_gnss)
{
    if (obj_gnss_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    const auto &value_from = p_gnss;
    typedef typename GnssPositioningMethodAndUsage::GnssType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setGnss(value)) return NULL;
    return obj_gnss_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_gnss_move(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, data_collection_model_gnss_id_t* p_gnss)
{
    if (obj_gnss_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    const auto &value_from = p_gnss;
    typedef typename GnssPositioningMethodAndUsage::GnssType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setGnss(std::move(value))) return NULL;
    return obj_gnss_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_usage_t* data_collection_model_gnss_positioning_method_and_usage_get_usage(const data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage)
{
    const std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<const std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    typedef typename GnssPositioningMethodAndUsage::UsageType ResultFromType;
    const ResultFromType result_from = obj->getUsage();
    const data_collection_model_usage_t *result = reinterpret_cast<const data_collection_model_usage_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_usage(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, const data_collection_model_usage_t* p_usage)
{
    if (obj_gnss_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    const auto &value_from = p_usage;
    typedef typename GnssPositioningMethodAndUsage::UsageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setUsage(value)) return NULL;
    return obj_gnss_positioning_method_and_usage;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_gnss_positioning_method_and_usage_t *data_collection_model_gnss_positioning_method_and_usage_set_usage_move(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage, data_collection_model_usage_t* p_usage)
{
    if (obj_gnss_positioning_method_and_usage == NULL) return NULL;

    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    const auto &value_from = p_usage;
    typedef typename GnssPositioningMethodAndUsage::UsageType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setUsage(std::move(value))) return NULL;
    return obj_gnss_positioning_method_and_usage;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_gnss_positioning_method_and_usage_make_lnode(data_collection_model_gnss_positioning_method_and_usage_t *p_gnss_positioning_method_and_usage)
{
    return data_collection_lnode_create(p_gnss_positioning_method_and_usage, reinterpret_cast<void(*)(void*)>(data_collection_model_gnss_positioning_method_and_usage_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_gnss_positioning_method_and_usage_refcount(data_collection_model_gnss_positioning_method_and_usage_t *obj_gnss_positioning_method_and_usage)
{
    std::shared_ptr<GnssPositioningMethodAndUsage > &obj = *reinterpret_cast<std::shared_ptr<GnssPositioningMethodAndUsage >*>(obj_gnss_positioning_method_and_usage);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

