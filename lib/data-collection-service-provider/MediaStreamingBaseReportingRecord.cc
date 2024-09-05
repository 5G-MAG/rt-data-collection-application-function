/**********************************************************************************************************************************
 * MediaStreamingBaseReportingRecord - C interface to the MediaStreamingBaseReportingRecord object
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

/*#include "MediaStreamingBaseReportingRecord.h" already included by data-collection-sp/data-collection.h */
#include "MediaStreamingBaseReportingRecord-internal.h"
#include "openapi/model/MediaStreamingBaseReportingRecord.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_create(


)
{
    return reinterpret_cast<data_collection_model_media_streaming_base_reporting_record_t*>(new std::shared_ptr<MediaStreamingBaseReportingRecord>(new MediaStreamingBaseReportingRecord(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_create_copy(const data_collection_model_media_streaming_base_reporting_record_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_media_streaming_base_reporting_record_t*>(new std::shared_ptr<MediaStreamingBaseReportingRecord >(new MediaStreamingBaseReportingRecord(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_create_move(data_collection_model_media_streaming_base_reporting_record_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MediaStreamingBaseReportingRecord > *obj = reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_copy(data_collection_model_media_streaming_base_reporting_record_t *media_streaming_base_reporting_record, const data_collection_model_media_streaming_base_reporting_record_t *other)
{
    if (media_streaming_base_reporting_record) {
        std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(media_streaming_base_reporting_record);
        if (obj) {
            if (other) {
                const std::shared_ptr<MediaStreamingBaseReportingRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(other);
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
                const std::shared_ptr<MediaStreamingBaseReportingRecord > &other_obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(other);
                if (other_obj) {
                    obj.reset(new MediaStreamingBaseReportingRecord(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        media_streaming_base_reporting_record = data_collection_model_media_streaming_base_reporting_record_create_copy(other);
    }
    return media_streaming_base_reporting_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_move(data_collection_model_media_streaming_base_reporting_record_t *media_streaming_base_reporting_record, data_collection_model_media_streaming_base_reporting_record_t *other)
{
    std::shared_ptr<MediaStreamingBaseReportingRecord > *other_ptr = reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(other);

    if (media_streaming_base_reporting_record) {
        std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(media_streaming_base_reporting_record);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                media_streaming_base_reporting_record = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return media_streaming_base_reporting_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_media_streaming_base_reporting_record_free(data_collection_model_media_streaming_base_reporting_record_t *media_streaming_base_reporting_record)
{
    if (!media_streaming_base_reporting_record) return;
    delete reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(media_streaming_base_reporting_record);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_media_streaming_base_reporting_record_toJSON(const data_collection_model_media_streaming_base_reporting_record_t *media_streaming_base_reporting_record, bool as_request)
{
    if (!media_streaming_base_reporting_record) return NULL;
    const std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(media_streaming_base_reporting_record);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_media_streaming_base_reporting_record_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_media_streaming_base_reporting_record_t*>(new std::shared_ptr<MediaStreamingBaseReportingRecord >(new MediaStreamingBaseReportingRecord(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_base_reporting_record_is_equal_to(const data_collection_model_media_streaming_base_reporting_record_t *first, const data_collection_model_media_streaming_base_reporting_record_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MediaStreamingBaseReportingRecord > &obj2 = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MediaStreamingBaseReportingRecord > &obj1 = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_base_reporting_record_has_slice_info(const data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record)
{
    if (!obj_media_streaming_base_reporting_record) return false;

    const std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) return false;

    return obj->getSliceInfo().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_snssai_t* data_collection_model_media_streaming_base_reporting_record_get_slice_info(const data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record)
{
    if (!obj_media_streaming_base_reporting_record) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) {
        const data_collection_model_snssai_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingBaseReportingRecord::SliceInfoType ResultFromType;
    const ResultFromType result_from = obj->getSliceInfo();
    const data_collection_model_snssai_t *result = reinterpret_cast<const data_collection_model_snssai_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_set_slice_info(data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record, const data_collection_model_snssai_t* p_slice_info)
{
    if (!obj_media_streaming_base_reporting_record) return NULL;

    std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) return NULL;

    const auto &value_from = p_slice_info;
    typedef typename MediaStreamingBaseReportingRecord::SliceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setSliceInfo(value)) return NULL;

    return obj_media_streaming_base_reporting_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_set_slice_info_move(data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record, data_collection_model_snssai_t* p_slice_info)
{
    if (!obj_media_streaming_base_reporting_record) return NULL;

    std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) return NULL;

    const auto &value_from = p_slice_info;
    typedef typename MediaStreamingBaseReportingRecord::SliceInfoType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setSliceInfo(std::move(value))) return NULL;

    return obj_media_streaming_base_reporting_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_base_reporting_record_has_data_network_name(const data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record)
{
    if (!obj_media_streaming_base_reporting_record) return false;

    const std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) return false;

    return obj->getDataNetworkName().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_media_streaming_base_reporting_record_get_data_network_name(const data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record)
{
    if (!obj_media_streaming_base_reporting_record) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename MediaStreamingBaseReportingRecord::DataNetworkNameType ResultFromType;
    const ResultFromType result_from = obj->getDataNetworkName();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_set_data_network_name(data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record, const char* p_data_network_name)
{
    if (!obj_media_streaming_base_reporting_record) return NULL;

    std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename MediaStreamingBaseReportingRecord::DataNetworkNameType ValueType;

    ValueType value(value_from);

    if (!obj->setDataNetworkName(value)) return NULL;

    return obj_media_streaming_base_reporting_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_set_data_network_name_move(data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record, char* p_data_network_name)
{
    if (!obj_media_streaming_base_reporting_record) return NULL;

    std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) return NULL;

    const auto &value_from = p_data_network_name;
    typedef typename MediaStreamingBaseReportingRecord::DataNetworkNameType ValueType;

    ValueType value(value_from);

    
    if (!obj->setDataNetworkName(std::move(value))) return NULL;

    return obj_media_streaming_base_reporting_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_media_streaming_base_reporting_record_has_location(const data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record)
{
    if (!obj_media_streaming_base_reporting_record) return false;

    const std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) return false;

    return obj->getLocation().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_typed_location_t* data_collection_model_media_streaming_base_reporting_record_get_location(const data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record)
{
    if (!obj_media_streaming_base_reporting_record) {
        const data_collection_model_typed_location_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<const std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) {
        const data_collection_model_typed_location_t *result = NULL;
        return result;
    }

    typedef typename MediaStreamingBaseReportingRecord::LocationType ResultFromType;
    const ResultFromType result_from = obj->getLocation();
    const data_collection_model_typed_location_t *result = reinterpret_cast<const data_collection_model_typed_location_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_set_location(data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record, const data_collection_model_typed_location_t* p_location)
{
    if (!obj_media_streaming_base_reporting_record) return NULL;

    std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename MediaStreamingBaseReportingRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setLocation(value)) return NULL;

    return obj_media_streaming_base_reporting_record;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_media_streaming_base_reporting_record_t *data_collection_model_media_streaming_base_reporting_record_set_location_move(data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record, data_collection_model_typed_location_t* p_location)
{
    if (!obj_media_streaming_base_reporting_record) return NULL;

    std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    if (!obj) return NULL;

    const auto &value_from = p_location;
    typedef typename MediaStreamingBaseReportingRecord::LocationType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    
    if (!obj->setLocation(std::move(value))) return NULL;

    return obj_media_streaming_base_reporting_record;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_media_streaming_base_reporting_record_make_lnode(data_collection_model_media_streaming_base_reporting_record_t *p_media_streaming_base_reporting_record)
{
    return data_collection_lnode_create(p_media_streaming_base_reporting_record, reinterpret_cast<void(*)(void*)>(data_collection_model_media_streaming_base_reporting_record_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_media_streaming_base_reporting_record_refcount(data_collection_model_media_streaming_base_reporting_record_t *obj_media_streaming_base_reporting_record)
{
    if (!obj_media_streaming_base_reporting_record) return 0l;
    std::shared_ptr<MediaStreamingBaseReportingRecord > &obj = *reinterpret_cast<std::shared_ptr<MediaStreamingBaseReportingRecord >*>(obj_media_streaming_base_reporting_record);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

