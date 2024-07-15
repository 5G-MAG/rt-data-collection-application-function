/**********************************************************************************************************************************
 * MediaStreamingSessionIdentification - C interface to the MediaStreamingSessionIdentification object
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

/*#include "MediaStreamingSessionIdentification.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingSessionIdentification-internal.h"
#include "openapi/model/MediaStreamingSessionIdentification.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create(
)
{
    return reinterpret_cast<data_collection_model_media_streaming_session_identification_t*>(new std::shared_ptr<MediaStreamingSessionIdentification>(new MediaStreamingSessionIdentification(
)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create_copy(const data_collection_model_media_streaming_session_identification_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_session_identification_t*>(new std::shared_ptr<MediaStreamingSessionIdentification >(new MediaStreamingSessionIdentification(**reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_create_move(data_collection_model_media_streaming_session_identification_t *other)
{
    return reinterpret_cast<data_collection_model_media_streaming_session_identification_t*>(new std::shared_ptr<MediaStreamingSessionIdentification >(std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_copy(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, const data_collection_model_media_streaming_session_identification_t *other)
{
    std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(media_streaming_session_identification);
    *obj = **reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(other);
    return media_streaming_session_identification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_move(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, data_collection_model_media_streaming_session_identification_t *other)
{
    std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(media_streaming_session_identification);
    obj = std::move(*reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(other));
    return media_streaming_session_identification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_media_streaming_session_identification_free(data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification)
{
    delete reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(media_streaming_session_identification);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_media_streaming_session_identification_toJSON(const data_collection_model_media_streaming_session_identification_t *media_streaming_session_identification, bool as_request)
{
    const std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(media_streaming_session_identification);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_session_identification_t*>(new std::shared_ptr<MediaStreamingSessionIdentification >(new MediaStreamingSessionIdentification(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_media_streaming_session_identification_get_session_id(const data_collection_model_media_streaming_session_identification_t *obj_media_streaming_session_identification)
{
    const std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingSessionIdentification >*>(obj_media_streaming_session_identification);
    typedef typename MediaStreamingSessionIdentification::SessionIdType ResultFromType;
    const ResultFromType result_from = obj->getSessionId();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_set_session_id(data_collection_model_media_streaming_session_identification_t *obj_media_streaming_session_identification, const char* p_session_id)
{
    if (obj_media_streaming_session_identification == NULL) return NULL;

    std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(obj_media_streaming_session_identification);
    const auto &value_from = p_session_id;
    typedef typename MediaStreamingSessionIdentification::SessionIdType ValueType;

    ValueType value(value_from);
    if (!obj->setSessionId(value)) return NULL;
    return obj_media_streaming_session_identification;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_media_streaming_session_identification_t *data_collection_model_media_streaming_session_identification_set_session_id_move(data_collection_model_media_streaming_session_identification_t *obj_media_streaming_session_identification, char* p_session_id)
{
    if (obj_media_streaming_session_identification == NULL) return NULL;

    std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(obj_media_streaming_session_identification);
    const auto &value_from = p_session_id;
    typedef typename MediaStreamingSessionIdentification::SessionIdType ValueType;

    ValueType value(value_from);
    
    if (!obj->setSessionId(std::move(value))) return NULL;
    return obj_media_streaming_session_identification;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_media_streaming_session_identification_make_lnode(data_collection_model_media_streaming_session_identification_t *p_media_streaming_session_identification)
{
    return data_collection_lnode_create(p_media_streaming_session_identification, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_session_identification_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_session_identification_refcount(data_collection_model_media_streaming_session_identification_t *obj_media_streaming_session_identification)
{
    std::shared_ptr<MediaStreamingSessionIdentification > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingSessionIdentification >*>(obj_media_streaming_session_identification);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

