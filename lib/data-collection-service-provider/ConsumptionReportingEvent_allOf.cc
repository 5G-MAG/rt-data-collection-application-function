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

#include <memory>
#include <type_traits>

#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "ConsumptionReportingEvent_allOf.h" already included by data-collection-sp/data-collection.h */
#include "ConsumptionReportingEvent_allOf-internal.h"
#include "openapi/model/ConsumptionReportingEvent_allOf.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_create(




)
{
    return reinterpret_cast<data_collection_model_consumption_reporting_event_all_of_t*>(new std::shared_ptr<ConsumptionReportingEvent_allOf>(new ConsumptionReportingEvent_allOf(




)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_create_ref(const data_collection_model_consumption_reporting_event_all_of_t *other)
{
    return reinterpret_cast<data_collection_model_consumption_reporting_event_all_of_t*>(new std::shared_ptr<ConsumptionReportingEvent_allOf>(*reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_create_copy(const data_collection_model_consumption_reporting_event_all_of_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_consumption_reporting_event_all_of_t*>(new std::shared_ptr<ConsumptionReportingEvent_allOf >(new ConsumptionReportingEvent_allOf(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_create_move(data_collection_model_consumption_reporting_event_all_of_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > *obj = reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_copy(data_collection_model_consumption_reporting_event_all_of_t *consumption_reporting_event_all_of, const data_collection_model_consumption_reporting_event_all_of_t *other)
{
    if (consumption_reporting_event_all_of) {
        std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(consumption_reporting_event_all_of);
        if (obj) {
            if (other) {
                const std::shared_ptr<ConsumptionReportingEvent_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(other);
                if (other_obj) {
                    *obj = *other_obj;
                } else {
                    obj.reset();
                }
            } else {
                obj.reset();
            }
        } else {
            if (other) {
                const std::shared_ptr<ConsumptionReportingEvent_allOf > &other_obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(other);
                if (other_obj) {
                    obj.reset(new ConsumptionReportingEvent_allOf(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        consumption_reporting_event_all_of = data_collection_model_consumption_reporting_event_all_of_create_copy(other);
    }
    return consumption_reporting_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_move(data_collection_model_consumption_reporting_event_all_of_t *consumption_reporting_event_all_of, data_collection_model_consumption_reporting_event_all_of_t *other)
{
    std::shared_ptr<ConsumptionReportingEvent_allOf > *other_ptr = reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(other);

    if (consumption_reporting_event_all_of) {
        std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(consumption_reporting_event_all_of);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                consumption_reporting_event_all_of = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return consumption_reporting_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_consumption_reporting_event_all_of_free(data_collection_model_consumption_reporting_event_all_of_t *consumption_reporting_event_all_of)
{
    if (!consumption_reporting_event_all_of) return;
    delete reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(consumption_reporting_event_all_of);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_consumption_reporting_event_all_of_toJSON(const data_collection_model_consumption_reporting_event_all_of_t *consumption_reporting_event_all_of, bool as_request)
{
    if (!consumption_reporting_event_all_of) return NULL;
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(consumption_reporting_event_all_of);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_consumption_reporting_event_all_of_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_all_of_is_equal_to(const data_collection_model_consumption_reporting_event_all_of_t *first, const data_collection_model_consumption_reporting_event_all_of_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj2 = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj1 = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(first);
    if (!second) {
        if (!obj1) return true;
        return false;
    }
    
    /* check what std::shared_ptr objects are pointing to */
    if (obj1 == obj2) return true;
    if (!obj1) return false;
    if (!obj2) return false;

    /* different shared_ptr objects pointing to different instances, so compare instances */
    return (*obj1 == *obj2);
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_all_of_get_unit_duration(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    if (!obj_consumption_reporting_event_all_of) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent_allOf::UnitDurationType ResultFromType;
    const ResultFromType &result_from = obj->getUnitDuration();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_unit_duration(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, const char* p_unit_duration)
{
    if (!obj_consumption_reporting_event_all_of) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_unit_duration;
    typedef typename ConsumptionReportingEvent_allOf::UnitDurationType ValueType;

    ValueType value(value_from);

    if (!obj->setUnitDuration(value)) return NULL;

    return obj_consumption_reporting_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_unit_duration_move(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, char* p_unit_duration)
{
    if (!obj_consumption_reporting_event_all_of) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_unit_duration;
    typedef typename ConsumptionReportingEvent_allOf::UnitDurationType ValueType;

    ValueType value(value_from);

    if (!obj->setUnitDuration(std::move(value))) return NULL;
    ogs_free
(p_unit_duration);

    return obj_consumption_reporting_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_all_of_has_client_endpoint_address(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    if (!obj_consumption_reporting_event_all_of) return false;

    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return false;

    return obj->getClientEndpointAddress().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_consumption_reporting_event_all_of_get_client_endpoint_address(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    if (!obj_consumption_reporting_event_all_of) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent_allOf::ClientEndpointAddressType ResultFromType;
    const ResultFromType &result_from = obj->getClientEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_client_endpoint_address(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, const data_collection_model_endpoint_address_t* p_client_endpoint_address)
{
    if (!obj_consumption_reporting_event_all_of) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_client_endpoint_address;
    typedef typename ConsumptionReportingEvent_allOf::ClientEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setClientEndpointAddress(value)) return NULL;

    return obj_consumption_reporting_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_client_endpoint_address_move(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, data_collection_model_endpoint_address_t* p_client_endpoint_address)
{
    if (!obj_consumption_reporting_event_all_of) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_client_endpoint_address;
    typedef typename ConsumptionReportingEvent_allOf::ClientEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setClientEndpointAddress(std::move(value))) return NULL;
    data_collection_model_endpoint_address_free
(p_client_endpoint_address);

    return obj_consumption_reporting_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_consumption_reporting_event_all_of_has_server_endpoint_address(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    if (!obj_consumption_reporting_event_all_of) return false;

    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return false;

    return obj->getServerEndpointAddress().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_endpoint_address_t* data_collection_model_consumption_reporting_event_all_of_get_server_endpoint_address(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    if (!obj_consumption_reporting_event_all_of) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) {
        const data_collection_model_endpoint_address_t *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent_allOf::ServerEndpointAddressType ResultFromType;
    const ResultFromType &result_from = obj->getServerEndpointAddress();
    const data_collection_model_endpoint_address_t *result = reinterpret_cast<const data_collection_model_endpoint_address_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_server_endpoint_address(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, const data_collection_model_endpoint_address_t* p_server_endpoint_address)
{
    if (!obj_consumption_reporting_event_all_of) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_server_endpoint_address;
    typedef typename ConsumptionReportingEvent_allOf::ServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setServerEndpointAddress(value)) return NULL;

    return obj_consumption_reporting_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_server_endpoint_address_move(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, data_collection_model_endpoint_address_t* p_server_endpoint_address)
{
    if (!obj_consumption_reporting_event_all_of) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_server_endpoint_address;
    typedef typename ConsumptionReportingEvent_allOf::ServerEndpointAddressType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setServerEndpointAddress(std::move(value))) return NULL;
    data_collection_model_endpoint_address_free
(p_server_endpoint_address);

    return obj_consumption_reporting_event_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_all_of_get_media_player_entry_url(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    if (!obj_consumption_reporting_event_all_of) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent_allOf::MediaPlayerEntryUrlType ResultFromType;
    const ResultFromType &result_from = obj->getMediaPlayerEntryUrl();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_media_player_entry_url(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, const char* p_media_player_entry_url)
{
    if (!obj_consumption_reporting_event_all_of) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_media_player_entry_url;
    typedef typename ConsumptionReportingEvent_allOf::MediaPlayerEntryUrlType ValueType;

    ValueType value(value_from);

    if (!obj->setMediaPlayerEntryUrl(value)) return NULL;

    return obj_consumption_reporting_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_media_player_entry_url_move(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, char* p_media_player_entry_url)
{
    if (!obj_consumption_reporting_event_all_of) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_media_player_entry_url;
    typedef typename ConsumptionReportingEvent_allOf::MediaPlayerEntryUrlType ValueType;

    ValueType value(value_from);

    if (!obj->setMediaPlayerEntryUrl(std::move(value))) return NULL;
    ogs_free
(p_media_player_entry_url);

    return obj_consumption_reporting_event_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_consumption_reporting_event_all_of_get_media_component_identifier(const data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    if (!obj_consumption_reporting_event_all_of) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<const std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename ConsumptionReportingEvent_allOf::MediaComponentIdentifierType ResultFromType;
    const ResultFromType &result_from = obj->getMediaComponentIdentifier();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_media_component_identifier(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, const char* p_media_component_identifier)
{
    if (!obj_consumption_reporting_event_all_of) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_media_component_identifier;
    typedef typename ConsumptionReportingEvent_allOf::MediaComponentIdentifierType ValueType;

    ValueType value(value_from);

    if (!obj->setMediaComponentIdentifier(value)) return NULL;

    return obj_consumption_reporting_event_all_of;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_consumption_reporting_event_all_of_t *data_collection_model_consumption_reporting_event_all_of_set_media_component_identifier_move(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of, char* p_media_component_identifier)
{
    if (!obj_consumption_reporting_event_all_of) return NULL;

    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    if (!obj) return NULL;

    const auto &value_from = p_media_component_identifier;
    typedef typename ConsumptionReportingEvent_allOf::MediaComponentIdentifierType ValueType;

    ValueType value(value_from);

    if (!obj->setMediaComponentIdentifier(std::move(value))) return NULL;
    ogs_free
(p_media_component_identifier);

    return obj_consumption_reporting_event_all_of;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_consumption_reporting_event_all_of_make_lnode(data_collection_model_consumption_reporting_event_all_of_t *p_consumption_reporting_event_all_of)
{
    return data_collection_lnode_create(p_consumption_reporting_event_all_of, reinterpret_cast<void(*)(void*)>(data_collection_model_consumption_reporting_event_all_of_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_consumption_reporting_event_all_of_refcount(data_collection_model_consumption_reporting_event_all_of_t *obj_consumption_reporting_event_all_of)
{
    if (!obj_consumption_reporting_event_all_of) return 0l;
    std::shared_ptr<ConsumptionReportingEvent_allOf > &obj = *reinterpret_cast<std::shared_ptr<ConsumptionReportingEvent_allOf >*>(obj_consumption_reporting_event_all_of);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

