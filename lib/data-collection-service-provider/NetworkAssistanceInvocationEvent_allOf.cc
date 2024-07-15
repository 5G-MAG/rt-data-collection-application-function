/**********************************************************************************************************************************
 * NetworkAssistanceInvocationEvent_allOf - C interface to the NetworkAssistanceInvocationEvent_allOf object
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

/*#include "NetworkAssistanceInvocationEvent_allOf.h" already included by data-collection-sp/data-collection.h */
#include "NetworkAssistanceInvocationEvent_allOf-internal.h"
#include "openapi/model/NetworkAssistanceInvocationEvent_allOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_create(
)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_event_all_of_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent_allOf>(new NetworkAssistanceInvocationEvent_allOf(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_create_copy(const data_collection_model_network_assistance_invocation_event_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_event_all_of_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >(new NetworkAssistanceInvocationEvent_allOf(**reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_create_move(data_collection_model_network_assistance_invocation_event_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_network_assistance_invocation_event_all_of_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >(std::move(*reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_copy(data_collection_model_network_assistance_invocation_event_all_of_t *network_assistance_invocation_event_all_of, const data_collection_model_network_assistance_invocation_event_all_of_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(network_assistance_invocation_event_all_of);
    *obj = **reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(other);
    return network_assistance_invocation_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_move(data_collection_model_network_assistance_invocation_event_all_of_t *network_assistance_invocation_event_all_of, data_collection_model_network_assistance_invocation_event_all_of_t *other)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(network_assistance_invocation_event_all_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(other));
    return network_assistance_invocation_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_network_assistance_invocation_event_all_of_free(data_collection_model_network_assistance_invocation_event_all_of_t *network_assistance_invocation_event_all_of)
{
    delete reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(network_assistance_invocation_event_all_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_network_assistance_invocation_event_all_of_toJSON(const data_collection_model_network_assistance_invocation_event_all_of_t *network_assistance_invocation_event_all_of, bool as_request)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(network_assistance_invocation_event_all_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_network_assistance_invocation_event_all_of_t*>(new std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >(new NetworkAssistanceInvocationEvent_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_network_assistance_type_t* data_collection_model_network_assistance_invocation_event_all_of_get_network_assistance_type(const data_collection_model_network_assistance_invocation_event_all_of_t *obj_network_assistance_invocation_event_all_of)
{
    const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(obj_network_assistance_invocation_event_all_of);
    typedef typename NetworkAssistanceInvocationEvent_allOf::NetworkAssistanceTypeType ResultFromType;
    const ResultFromType result_from = obj->getNetworkAssistanceType();
    const data_collection_model_network_assistance_type_t *result = reinterpret_cast<const data_collection_model_network_assistance_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_set_network_assistance_type(data_collection_model_network_assistance_invocation_event_all_of_t *obj_network_assistance_invocation_event_all_of, const data_collection_model_network_assistance_type_t* p_network_assistance_type)
{
    if (obj_network_assistance_invocation_event_all_of == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(obj_network_assistance_invocation_event_all_of);
    const auto &value_from = p_network_assistance_type;
    typedef typename NetworkAssistanceInvocationEvent_allOf::NetworkAssistanceTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setNetworkAssistanceType(value)) return NULL;
    return obj_network_assistance_invocation_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_network_assistance_invocation_event_all_of_t *data_collection_model_network_assistance_invocation_event_all_of_set_network_assistance_type_move(data_collection_model_network_assistance_invocation_event_all_of_t *obj_network_assistance_invocation_event_all_of, data_collection_model_network_assistance_type_t* p_network_assistance_type)
{
    if (obj_network_assistance_invocation_event_all_of == NULL) return NULL;

    std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(obj_network_assistance_invocation_event_all_of);
    const auto &value_from = p_network_assistance_type;
    typedef typename NetworkAssistanceInvocationEvent_allOf::NetworkAssistanceTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setNetworkAssistanceType(std::move(value))) return NULL;
    return obj_network_assistance_invocation_event_all_of;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_network_assistance_invocation_event_all_of_make_lnode(data_collection_model_network_assistance_invocation_event_all_of_t *p_network_assistance_invocation_event_all_of)
{
    return data_collection_lnode_create(p_network_assistance_invocation_event_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_network_assistance_invocation_event_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_network_assistance_invocation_event_all_of_refcount(data_collection_model_network_assistance_invocation_event_all_of_t *obj_network_assistance_invocation_event_all_of)
{
    std::shared_ptr<NetworkAssistanceInvocationEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<NetworkAssistanceInvocationEvent_allOf >*>(obj_network_assistance_invocation_event_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

