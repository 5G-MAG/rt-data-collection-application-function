/**********************************************************************************************************************************
 * ConsumptionReportingEvent_allOf - C interface to the ConsumptionReportingEvent_allOf object
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

/*#include "ConsumptionReportingEvent_allOf.h" already included by data-collection-sp/data-collection.h */
#include "ConsumptionReportingEvent_allOf-internal.h"
#include "openapi/model/ConsumptionReportingEvent_allOf.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_create(




)
{
    return reinterpret_cast<data_collection_model_consumption_reporting_event_all_of_t*>(new std::shared_ptr<ConsumptionReportingEvent_allOf>(new ConsumptionReportingEvent_allOf(




)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_create_copy(const data_collection_model_consumption_reporting_event_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_consumption_reporting_event_all_of_t*>(new std::shared_ptr<ConsumptionReportingEvent_allOf >(new ConsumptionReportingEvent_allOf(**reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_create_move(data_collection_model_consumption_reporting_event_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_consumption_reporting_event_all_of_t*>(new std::shared_ptr<ConsumptionReportingEvent_allOf >(std::move(*reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_copy(data_collection_model_consumption_reporting_event_all_of_t *consumption_reporting_event_all_of, const data_collection_model_consumption_reporting_event_all_of_t *other)
{
    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(consumption_reporting_event_all_of);
    *obj = **reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(other);
    return consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_move(data_collection_model_consumption_reporting_event_all_of_t *consumption_reporting_event_all_of, data_collection_model_consumption_reporting_event_all_of_t *other)
{
    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(consumption_reporting_event_all_of);
    obj = std::move(*reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(other));
    return consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_consumption_reporting_event_all_of_free(data_collection_model_consumption_reporting_event_all_of_t *consumption_reporting_event_all_of)
{
    delete reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(consumption_reporting_event_all_of);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_consumption_reporting_event_all_of_toJSON(const data_collection_model_consumption_reporting_event_all_of_t *consumption_reporting_event_all_of, bool as_request)
{
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(consumption_reporting_event_all_of);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_consumption_reporting_event_all_of_t*>(new std::shared_ptr<ConsumptionReportingEvent_allOf >(new ConsumptionReportingEvent_allOf(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_consumption_reporting_event_all_of_is_equal_to(const data_collection_model_consumption_reporting_event_all_of_t *first, const data_collection_model_consumption_reporting_event_all_of_t *second)
{
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(first);
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_consumption_reporting_event_all_of_get_unit_duration(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    typedef typename ConsumptionReportingEvent_allOf::UnitDurationType ResultFromType;
    const ResultFromType result_from = obj->getUnitDuration();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_unit_duration(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, const char* p_unit_duration)
{
    if (obj_consumption_reporting_event_all_of == NULL) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    const auto &value_from = p_unit_duration;
    typedef typename ConsumptionReportingEvent_allOf::UnitDurationType ValueType;

    ValueType value(value_from);
    if (!obj->setUnitDuration(value)) return NULL;
    return obj_consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_unit_duration_move(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, char* p_unit_duration)
{
    if (obj_consumption_reporting_event_all_of == NULL) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    const auto &value_from = p_unit_duration;
    typedef typename ConsumptionReportingEvent_allOf::UnitDurationType ValueType;

    ValueType value(value_from);
    
    if (!obj->setUnitDuration(std::move(value))) return NULL;
    return obj_consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_endpoint_address_t* data_collection_model_consumption_reporting_event_all_of_get_client_endpoint_address(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    typedef typename ConsumptionReportingEvent_allOf::ClientEndpointAddressType ResultFromType;
    const ResultFromType result_from = obj->getClientEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_client_endpoint_address(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, const data_collection_model_endpoint_address_t* p_client_endpoint_address)
{
    if (obj_consumption_reporting_event_all_of == NULL) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    const auto &value_from = p_client_endpoint_address;
    typedef typename ConsumptionReportingEvent_allOf::ClientEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setClientEndpointAddress(value)) return NULL;
    return obj_consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_client_endpoint_address_move(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, data_collection_model_endpoint_address_t* p_client_endpoint_address)
{
    if (obj_consumption_reporting_event_all_of == NULL) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    const auto &value_from = p_client_endpoint_address;
    typedef typename ConsumptionReportingEvent_allOf::ClientEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setClientEndpointAddress(std::move(value))) return NULL;
    return obj_consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_endpoint_address_t* data_collection_model_consumption_reporting_event_all_of_get_server_endpoint_address(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    typedef typename ConsumptionReportingEvent_allOf::ServerEndpointAddressType ResultFromType;
    const ResultFromType result_from = obj->getServerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_server_endpoint_address(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, const data_collection_model_endpoint_address_t* p_server_endpoint_address)
{
    if (obj_consumption_reporting_event_all_of == NULL) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    const auto &value_from = p_server_endpoint_address;
    typedef typename ConsumptionReportingEvent_allOf::ServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setServerEndpointAddress(value)) return NULL;
    return obj_consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_server_endpoint_address_move(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, data_collection_model_endpoint_address_t* p_server_endpoint_address)
{
    if (obj_consumption_reporting_event_all_of == NULL) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    const auto &value_from = p_server_endpoint_address;
    typedef typename ConsumptionReportingEvent_allOf::ServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setServerEndpointAddress(std::move(value))) return NULL;
    return obj_consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_consumption_reporting_event_all_of_get_media_player_entry_url(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    typedef typename ConsumptionReportingEvent_allOf::MediaPlayerEntryUrlType ResultFromType;
    const ResultFromType result_from = obj->getMediaPlayerEntryUrl();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_media_player_entry_url(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, const char* p_media_player_entry_url)
{
    if (obj_consumption_reporting_event_all_of == NULL) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    const auto &value_from = p_media_player_entry_url;
    typedef typename ConsumptionReportingEvent_allOf::MediaPlayerEntryUrlType ValueType;

    ValueType value(value_from);
    if (!obj->setMediaPlayerEntryUrl(value)) return NULL;
    return obj_consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_media_player_entry_url_move(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, char* p_media_player_entry_url)
{
    if (obj_consumption_reporting_event_all_of == NULL) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    const auto &value_from = p_media_player_entry_url;
    typedef typename ConsumptionReportingEvent_allOf::MediaPlayerEntryUrlType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMediaPlayerEntryUrl(std::move(value))) return NULL;
    return obj_consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_consumption_reporting_event_all_of_get_media_component_identifier(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    typedef typename ConsumptionReportingEvent_allOf::MediaComponentIdentifierType ResultFromType;
    const ResultFromType result_from = obj->getMediaComponentIdentifier();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_media_component_identifier(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, const char* p_media_component_identifier)
{
    if (obj_consumption_reporting_event_all_of == NULL) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    const auto &value_from = p_media_component_identifier;
    typedef typename ConsumptionReportingEvent_allOf::MediaComponentIdentifierType ValueType;

    ValueType value(value_from);
    if (!obj->setMediaComponentIdentifier(value)) return NULL;
    return obj_consumption_reporting_event_all_of;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_media_component_identifier_move(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, char* p_media_component_identifier)
{
    if (obj_consumption_reporting_event_all_of == NULL) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    const auto &value_from = p_media_component_identifier;
    typedef typename ConsumptionReportingEvent_allOf::MediaComponentIdentifierType ValueType;

    ValueType value(value_from);
    
    if (!obj->setMediaComponentIdentifier(std::move(value))) return NULL;
    return obj_consumption_reporting_event_all_of;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_consumption_reporting_event_all_of_make_lnode(data_collection_model_consumption_reporting_event_all_of_t *p_consumption_reporting_event_all_of)
{
    return data_collection_lnode_create(p_consumption_reporting_event_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_consumption_reporting_event_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_consumption_reporting_event_all_of_refcount(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

