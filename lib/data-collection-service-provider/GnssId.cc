/**********************************************************************************************************************************
 * GnssId - C interface to the GnssId object
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

/*#include "GnssId.h" already included by data-collection-sp/data-collection.h */
#include "GnssId-internal.h"
#include "openapi/model/GnssId.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_create()
{
    return reinterpret_cast<data_collection_model_gnss_id_t*>(new std::shared_ptr<GnssId>(new GnssId()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_create_ref(const data_collection_model_gnss_id_t *other)
{
    return reinterpret_cast<data_collection_model_gnss_id_t*>(new std::shared_ptr<GnssId>(*reinterpret_cast<const std::shared_ptr<GnssId >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_create_copy(const data_collection_model_gnss_id_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<GnssId > &obj = *reinterpret_cast<const std::shared_ptr<GnssId >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_gnss_id_t*>(new std::shared_ptr<GnssId >(new GnssId(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_create_move(data_collection_model_gnss_id_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<GnssId > *obj = reinterpret_cast<std::shared_ptr<GnssId >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_copy(data_collection_model_gnss_id_t *gnss_id, const data_collection_model_gnss_id_t *other)
{
    if (gnss_id) {
        std::shared_ptr<GnssId > &obj = *reinterpret_cast<std::shared_ptr<GnssId >*>(gnss_id);
        if (obj) {
            if (other) {
                const std::shared_ptr<GnssId > &other_obj = *reinterpret_cast<const std::shared_ptr<GnssId >*>(other);
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
                const std::shared_ptr<GnssId > &other_obj = *reinterpret_cast<const std::shared_ptr<GnssId >*>(other);
                if (other_obj) {
                    obj.reset(new GnssId(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        gnss_id = data_collection_model_gnss_id_create_copy(other);
    }
    return gnss_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_move(data_collection_model_gnss_id_t *gnss_id, data_collection_model_gnss_id_t *other)
{
    std::shared_ptr<GnssId > *other_ptr = reinterpret_cast<std::shared_ptr<GnssId >*>(other);

    if (gnss_id) {
        std::shared_ptr<GnssId > &obj = *reinterpret_cast<std::shared_ptr<GnssId >*>(gnss_id);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                gnss_id = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return gnss_id;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnss_id_free(data_collection_model_gnss_id_t *gnss_id)
{
    if (!gnss_id) return;
    delete reinterpret_cast<std::shared_ptr<GnssId >*>(gnss_id);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnss_id_toJSON(const data_collection_model_gnss_id_t *gnss_id, bool as_request)
{
    if (!gnss_id) return NULL;
    const std::shared_ptr<GnssId > &obj = *reinterpret_cast<const std::shared_ptr<GnssId >*>(gnss_id);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_gnss_id_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_t *data_collection_model_gnss_id_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_gnss_id_t*>(new std::shared_ptr<GnssId >(new GnssId(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_id_is_equal_to(const data_collection_model_gnss_id_t *first, const data_collection_model_gnss_id_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<GnssId > &obj2 = *reinterpret_cast<const std::shared_ptr<GnssId >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<GnssId > &obj1 = *reinterpret_cast<const std::shared_ptr<GnssId >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_id_is_not_set(const data_collection_model_gnss_id_t *obj_gnss_id)
{
    if (!obj_gnss_id) return true;
    const std::shared_ptr<GnssId > &obj = *reinterpret_cast<const std::shared_ptr<GnssId >*>(obj_gnss_id);
    if (!obj) return true;
    return obj->getValue() == GnssId::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_id_is_non_standard(const data_collection_model_gnss_id_t *obj_gnss_id)
{
    if (!obj_gnss_id) return false;
    const std::shared_ptr<GnssId > &obj = *reinterpret_cast<const std::shared_ptr<GnssId >*>(obj_gnss_id);
    if (!obj) return false;
    return obj->getValue() == GnssId::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_id_e data_collection_model_gnss_id_get_enum(const data_collection_model_gnss_id_t *obj_gnss_id)
{
    if (!obj_gnss_id)
        return DCM_GNSS_ID_NO_VAL;
    const std::shared_ptr<GnssId > &obj = *reinterpret_cast<const std::shared_ptr<GnssId >*>(obj_gnss_id);
    if (!obj) return DCM_GNSS_ID_NO_VAL;
    switch (obj->getValue()) {
    case GnssId::Enum::NO_VAL:
        return DCM_GNSS_ID_NO_VAL;
    case GnssId::Enum::VAL_GPS:
        return DCM_GNSS_ID_VAL_GPS;
    case GnssId::Enum::VAL_GALILEO:
        return DCM_GNSS_ID_VAL_GALILEO;
    case GnssId::Enum::VAL_SBAS:
        return DCM_GNSS_ID_VAL_SBAS;
    case GnssId::Enum::VAL_MODERNIZED_GPS:
        return DCM_GNSS_ID_VAL_MODERNIZED_GPS;
    case GnssId::Enum::VAL_QZSS:
        return DCM_GNSS_ID_VAL_QZSS;
    case GnssId::Enum::VAL_GLONASS:
        return DCM_GNSS_ID_VAL_GLONASS;
    case GnssId::Enum::VAL_BDS:
        return DCM_GNSS_ID_VAL_BDS;
    case GnssId::Enum::VAL_NAVIC:
        return DCM_GNSS_ID_VAL_NAVIC;
    default:
        break;
    }
    return DCM_GNSS_ID_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_gnss_id_get_string(const data_collection_model_gnss_id_t *obj_gnss_id)
{
    if (!obj_gnss_id) return NULL;
    const std::shared_ptr<GnssId > &obj = *reinterpret_cast<const std::shared_ptr<GnssId >*>(obj_gnss_id);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_id_set_enum(data_collection_model_gnss_id_t *obj_gnss_id, data_collection_model_gnss_id_e p_value)
{
    if (!obj_gnss_id) return false;
    std::shared_ptr<GnssId > &obj = *reinterpret_cast<std::shared_ptr<GnssId >*>(obj_gnss_id);
    if (!obj) return false;
    switch (p_value) {
    case DCM_GNSS_ID_NO_VAL:
        *obj = GnssId::Enum::NO_VAL;
        return true;
    case DCM_GNSS_ID_VAL_GPS:
        *obj = GnssId::Enum::VAL_GPS;
        return true;
    case DCM_GNSS_ID_VAL_GALILEO:
        *obj = GnssId::Enum::VAL_GALILEO;
        return true;
    case DCM_GNSS_ID_VAL_SBAS:
        *obj = GnssId::Enum::VAL_SBAS;
        return true;
    case DCM_GNSS_ID_VAL_MODERNIZED_GPS:
        *obj = GnssId::Enum::VAL_MODERNIZED_GPS;
        return true;
    case DCM_GNSS_ID_VAL_QZSS:
        *obj = GnssId::Enum::VAL_QZSS;
        return true;
    case DCM_GNSS_ID_VAL_GLONASS:
        *obj = GnssId::Enum::VAL_GLONASS;
        return true;
    case DCM_GNSS_ID_VAL_BDS:
        *obj = GnssId::Enum::VAL_BDS;
        return true;
    case DCM_GNSS_ID_VAL_NAVIC:
        *obj = GnssId::Enum::VAL_NAVIC;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_id_set_string(data_collection_model_gnss_id_t *obj_gnss_id, const char *p_value)
{
    if (!obj_gnss_id) return false;
    std::shared_ptr<GnssId > &obj = *reinterpret_cast<std::shared_ptr<GnssId >*>(obj_gnss_id);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = GnssId::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnss_id_make_lnode(data_collection_model_gnss_id_t *p_gnss_id)
{
    return data_collection_lnode_create(p_gnss_id, reinterpret_cast<void(*)(void*)>(data_collection_model_gnss_id_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_gnss_id_refcount(data_collection_model_gnss_id_t *obj_gnss_id)
{
    if (!obj_gnss_id) return 0l;
    std::shared_ptr<GnssId > &obj = *reinterpret_cast<std::shared_ptr<GnssId >*>(obj_gnss_id);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

