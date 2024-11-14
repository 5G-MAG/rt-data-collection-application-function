/**********************************************************************************************************************************
 * GNbId - C interface to the GNbId object
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

/*#include "GNbId.h" already included by data-collection-sp/data-collection.h */
#include "GNbId-internal.h"
#include "openapi/model/GNbId.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_create(

)
{
    return reinterpret_cast<data_collection_model_gnb_id_t*>(new std::shared_ptr<GNbId>(new GNbId(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_create_ref(const data_collection_model_gnb_id_t *other)
{
    return reinterpret_cast<data_collection_model_gnb_id_t*>(new std::shared_ptr<GNbId>(*reinterpret_cast<const std::shared_ptr<GNbId >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_create_copy(const data_collection_model_gnb_id_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<GNbId > &obj = *reinterpret_cast<const std::shared_ptr<GNbId >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_gnb_id_t*>(new std::shared_ptr<GNbId >(new GNbId(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_create_move(data_collection_model_gnb_id_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<GNbId > *obj = reinterpret_cast<std::shared_ptr<GNbId >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_copy(data_collection_model_gnb_id_t *gnb_id, const data_collection_model_gnb_id_t *other)
{
    if (gnb_id) {
        std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(gnb_id);
        if (obj) {
            if (other) {
                const std::shared_ptr<GNbId > &other_obj = *reinterpret_cast<const std::shared_ptr<GNbId >*>(other);
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
                const std::shared_ptr<GNbId > &other_obj = *reinterpret_cast<const std::shared_ptr<GNbId >*>(other);
                if (other_obj) {
                    obj.reset(new GNbId(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        gnb_id = data_collection_model_gnb_id_create_copy(other);
    }
    return gnb_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_move(data_collection_model_gnb_id_t *gnb_id, data_collection_model_gnb_id_t *other)
{
    std::shared_ptr<GNbId > *other_ptr = reinterpret_cast<std::shared_ptr<GNbId >*>(other);

    if (gnb_id) {
        std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(gnb_id);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                gnb_id = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return gnb_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnb_id_free(data_collection_model_gnb_id_t *gnb_id)
{
    if (!gnb_id) return;
    delete reinterpret_cast<std::shared_ptr<GNbId >*>(gnb_id);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnb_id_toJSON(const data_collection_model_gnb_id_t *gnb_id, bool as_request)
{
    if (!gnb_id) return NULL;
    const std::shared_ptr<GNbId > &obj = *reinterpret_cast<const std::shared_ptr<GNbId >*>(gnb_id);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_gnb_id_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_gnb_id_t*>(new std::shared_ptr<GNbId >(new GNbId(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnb_id_is_equal_to(const data_collection_model_gnb_id_t *first, const data_collection_model_gnb_id_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<GNbId > &obj2 = *reinterpret_cast<const std::shared_ptr<GNbId >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<GNbId > &obj1 = *reinterpret_cast<const std::shared_ptr<GNbId >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_gnb_id_get_bit_length(const data_collection_model_gnb_id_t *obj_gnb_id)
{
    if (!obj_gnb_id) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<GNbId > &obj = *reinterpret_cast<const std::shared_ptr<GNbId >*>(obj_gnb_id);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename GNbId::BitLengthType ResultFromType;
    const ResultFromType &result_from = obj->getBitLength();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_bit_length(data_collection_model_gnb_id_t *obj_gnb_id, const int32_t p_bit_length)
{
    if (!obj_gnb_id) return NULL;

    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(obj_gnb_id);
    if (!obj) return NULL;

    const auto &value_from = p_bit_length;
    typedef typename GNbId::BitLengthType ValueType;

    ValueType value(value_from);

    if (!obj->setBitLength(value)) return NULL;

    return obj_gnb_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_bit_length_move(data_collection_model_gnb_id_t *obj_gnb_id, int32_t p_bit_length)
{
    if (!obj_gnb_id) return NULL;

    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(obj_gnb_id);
    if (!obj) return NULL;

    const auto &value_from = p_bit_length;
    typedef typename GNbId::BitLengthType ValueType;

    ValueType value(value_from);

    if (!obj->setBitLength(std::move(value))) return NULL;

    return obj_gnb_id;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_gnb_id_get_gnb_value(const data_collection_model_gnb_id_t *obj_gnb_id)
{
    if (!obj_gnb_id) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<GNbId > &obj = *reinterpret_cast<const std::shared_ptr<GNbId >*>(obj_gnb_id);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename GNbId::GNBValueType ResultFromType;
    const ResultFromType &result_from = obj->getGNBValue();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_gnb_value(data_collection_model_gnb_id_t *obj_gnb_id, const char* p_gnb_value)
{
    if (!obj_gnb_id) return NULL;

    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(obj_gnb_id);
    if (!obj) return NULL;

    const auto &value_from = p_gnb_value;
    typedef typename GNbId::GNBValueType ValueType;

    ValueType value(value_from);

    if (!obj->setGNBValue(value)) return NULL;

    return obj_gnb_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnb_id_t *data_collection_model_gnb_id_set_gnb_value_move(data_collection_model_gnb_id_t *obj_gnb_id, char* p_gnb_value)
{
    if (!obj_gnb_id) return NULL;

    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(obj_gnb_id);
    if (!obj) return NULL;

    const auto &value_from = p_gnb_value;
    typedef typename GNbId::GNBValueType ValueType;

    ValueType value(value_from);

    if (!obj->setGNBValue(std::move(value))) return NULL;
    ogs_free
(p_gnb_value);

    return obj_gnb_id;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnb_id_make_lnode(data_collection_model_gnb_id_t *p_gnb_id)
{
    return data_collection_lnode_create(p_gnb_id, reinterpret_cast<void(*)(void*)>(data_collection_model_gnb_id_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_gnb_id_refcount(data_collection_model_gnb_id_t *obj_gnb_id)
{
    if (!obj_gnb_id) return 0l;
    std::shared_ptr<GNbId > &obj = *reinterpret_cast<std::shared_ptr<GNbId >*>(obj_gnb_id);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

