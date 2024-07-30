/**********************************************************************************************************************************
 * ApplicationFlowDescription - C interface to the ApplicationFlowDescription object
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

/*#include "ApplicationFlowDescription.h" already included by data-collection-sp/data-collection.h */
#include "ApplicationFlowDescription-internal.h"
#include "openapi/model/ApplicationFlowDescription.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_create(




)
{
    return reinterpret_cast<data_collection_model_application_flow_description_t*>(new std::shared_ptr<ApplicationFlowDescription>(new ApplicationFlowDescription(




)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_create_copy(const data_collection_model_application_flow_description_t *other)
{
    return reinterpret_cast<data_collection_model_application_flow_description_t*>(new std::shared_ptr<ApplicationFlowDescription >(new ApplicationFlowDescription(**reinterpret_cast<const std::shared_ptr<ApplicationFlowDescription >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_create_move(data_collection_model_application_flow_description_t *other)
{
    return reinterpret_cast<data_collection_model_application_flow_description_t*>(new std::shared_ptr<ApplicationFlowDescription >(std::move(*reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_copy(data_collection_model_application_flow_description_t *application_flow_description, const data_collection_model_application_flow_description_t *other)
{
    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(application_flow_description);
    *obj = **reinterpret_cast<const std::shared_ptr<ApplicationFlowDescription >*>(other);
    return application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_move(data_collection_model_application_flow_description_t *application_flow_description, data_collection_model_application_flow_description_t *other)
{
    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(application_flow_description);
    obj = std::move(*reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(other));
    return application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_application_flow_description_free(data_collection_model_application_flow_description_t *application_flow_description)
{
    delete reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(application_flow_description);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_application_flow_description_toJSON(const data_collection_model_application_flow_description_t *application_flow_description, bool as_request)
{
    const std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationFlowDescription >*>(application_flow_description);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_application_flow_description_t*>(new std::shared_ptr<ApplicationFlowDescription >(new ApplicationFlowDescription(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_application_flow_description_is_equal_to(const data_collection_model_application_flow_description_t *first, const data_collection_model_application_flow_description_t *second)
{
    const std::shared_ptr<ApplicationFlowDescription > &obj1 = *reinterpret_cast<const std::shared_ptr<ApplicationFlowDescription >*>(first);
    const std::shared_ptr<ApplicationFlowDescription > &obj2 = *reinterpret_cast<const std::shared_ptr<ApplicationFlowDescription >*>(second);
    return (obj1 == obj2 || *obj1 == *obj2);
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_sdf_method_t* data_collection_model_application_flow_description_get_filter_method(const data_collection_model_application_flow_description_t *obj_application_flow_description)
{
    const std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    typedef typename ApplicationFlowDescription::FilterMethodType ResultFromType;
    const ResultFromType result_from = obj->getFilterMethod();
    const data_collection_model_sdf_method_t *result = reinterpret_cast<const data_collection_model_sdf_method_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_filter_method(data_collection_model_application_flow_description_t *obj_application_flow_description, const data_collection_model_sdf_method_t* p_filter_method)
{
    if (obj_application_flow_description == NULL) return NULL;

    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    const auto &value_from = p_filter_method;
    typedef typename ApplicationFlowDescription::FilterMethodType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setFilterMethod(value)) return NULL;
    return obj_application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_filter_method_move(data_collection_model_application_flow_description_t *obj_application_flow_description, data_collection_model_sdf_method_t* p_filter_method)
{
    if (obj_application_flow_description == NULL) return NULL;

    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    const auto &value_from = p_filter_method;
    typedef typename ApplicationFlowDescription::FilterMethodType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setFilterMethod(std::move(value))) return NULL;
    return obj_application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_ip_packet_filter_set_t* data_collection_model_application_flow_description_get_packet_filter(const data_collection_model_application_flow_description_t *obj_application_flow_description)
{
    const std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    typedef typename ApplicationFlowDescription::PacketFilterType ResultFromType;
    const ResultFromType result_from = obj->getPacketFilter();
    const data_collection_model_ip_packet_filter_set_t *result = reinterpret_cast<const data_collection_model_ip_packet_filter_set_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_packet_filter(data_collection_model_application_flow_description_t *obj_application_flow_description, const data_collection_model_ip_packet_filter_set_t* p_packet_filter)
{
    if (obj_application_flow_description == NULL) return NULL;

    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    const auto &value_from = p_packet_filter;
    typedef typename ApplicationFlowDescription::PacketFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setPacketFilter(value)) return NULL;
    return obj_application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_packet_filter_move(data_collection_model_application_flow_description_t *obj_application_flow_description, data_collection_model_ip_packet_filter_set_t* p_packet_filter)
{
    if (obj_application_flow_description == NULL) return NULL;

    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    const auto &value_from = p_packet_filter;
    typedef typename ApplicationFlowDescription::PacketFilterType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setPacketFilter(std::move(value))) return NULL;
    return obj_application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_application_flow_description_get_domain_name(const data_collection_model_application_flow_description_t *obj_application_flow_description)
{
    const std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    typedef typename ApplicationFlowDescription::DomainNameType ResultFromType;
    const ResultFromType result_from = obj->getDomainName();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_domain_name(data_collection_model_application_flow_description_t *obj_application_flow_description, const char* p_domain_name)
{
    if (obj_application_flow_description == NULL) return NULL;

    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    const auto &value_from = p_domain_name;
    typedef typename ApplicationFlowDescription::DomainNameType ValueType;

    ValueType value(value_from);
    if (!obj->setDomainName(value)) return NULL;
    return obj_application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_domain_name_move(data_collection_model_application_flow_description_t *obj_application_flow_description, char* p_domain_name)
{
    if (obj_application_flow_description == NULL) return NULL;

    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    const auto &value_from = p_domain_name;
    typedef typename ApplicationFlowDescription::DomainNameType ValueType;

    ValueType value(value_from);
    
    if (!obj->setDomainName(std::move(value))) return NULL;
    return obj_application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_media_type_t* data_collection_model_application_flow_description_get_media_type(const data_collection_model_application_flow_description_t *obj_application_flow_description)
{
    const std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    typedef typename ApplicationFlowDescription::MediaTypeType ResultFromType;
    const ResultFromType result_from = obj->getMediaType();
    const data_collection_model_media_type_t *result = reinterpret_cast<const data_collection_model_media_type_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_type(data_collection_model_application_flow_description_t *obj_application_flow_description, const data_collection_model_media_type_t* p_media_type)
{
    if (obj_application_flow_description == NULL) return NULL;

    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    const auto &value_from = p_media_type;
    typedef typename ApplicationFlowDescription::MediaTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setMediaType(value)) return NULL;
    return obj_application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_type_move(data_collection_model_application_flow_description_t *obj_application_flow_description, data_collection_model_media_type_t* p_media_type)
{
    if (obj_application_flow_description == NULL) return NULL;

    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    const auto &value_from = p_media_type;
    typedef typename ApplicationFlowDescription::MediaTypeType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setMediaType(std::move(value))) return NULL;
    return obj_application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_protocol_description_t* data_collection_model_application_flow_description_get_media_transport_parameters(const data_collection_model_application_flow_description_t *obj_application_flow_description)
{
    const std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<const std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    typedef typename ApplicationFlowDescription::MediaTransportParametersType ResultFromType;
    const ResultFromType result_from = obj->getMediaTransportParameters();
    const data_collection_model_protocol_description_t *result = reinterpret_cast<const data_collection_model_protocol_description_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_transport_parameters(data_collection_model_application_flow_description_t *obj_application_flow_description, const data_collection_model_protocol_description_t* p_media_transport_parameters)
{
    if (obj_application_flow_description == NULL) return NULL;

    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    const auto &value_from = p_media_transport_parameters;
    typedef typename ApplicationFlowDescription::MediaTransportParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setMediaTransportParameters(value)) return NULL;
    return obj_application_flow_description;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_application_flow_description_t *data_collection_model_application_flow_description_set_media_transport_parameters_move(data_collection_model_application_flow_description_t *obj_application_flow_description, data_collection_model_protocol_description_t* p_media_transport_parameters)
{
    if (obj_application_flow_description == NULL) return NULL;

    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    const auto &value_from = p_media_transport_parameters;
    typedef typename ApplicationFlowDescription::MediaTransportParametersType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setMediaTransportParameters(std::move(value))) return NULL;
    return obj_application_flow_description;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_application_flow_description_make_lnode(data_collection_model_application_flow_description_t *p_application_flow_description)
{
    return data_collection_lnode_create(p_application_flow_description, reinterpret_cast<void(*)(void*)>(data_collection_model_application_flow_description_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_application_flow_description_refcount(data_collection_model_application_flow_description_t *obj_application_flow_description)
{
    std::shared_ptr<ApplicationFlowDescription > &obj = *reinterpret_cast<std::shared_ptr<ApplicationFlowDescription >*>(obj_application_flow_description);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

