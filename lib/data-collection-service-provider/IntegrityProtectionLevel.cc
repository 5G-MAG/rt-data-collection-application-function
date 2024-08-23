/**********************************************************************************************************************************
 * IntegrityProtectionLevel - C interface to the IntegrityProtectionLevel object
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

/*#include "IntegrityProtectionLevel.h" already included by data-collection-sp/data-collection.h */
#include "IntegrityProtectionLevel-internal.h"
#include "openapi/model/IntegrityProtectionLevel.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_create(

)
{
    return reinterpret_cast<data_collection_model_integrity_protection_level_t*>(new std::shared_ptr<IntegrityProtectionLevel>(new IntegrityProtectionLevel(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_create_copy(const data_collection_model_integrity_protection_level_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityProtectionLevel >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_integrity_protection_level_t*>(new std::shared_ptr<IntegrityProtectionLevel >(new IntegrityProtectionLevel(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_create_move(data_collection_model_integrity_protection_level_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<IntegrityProtectionLevel > *obj = reinterpret_cast<std::shared_ptr<IntegrityProtectionLevel >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_copy(data_collection_model_integrity_protection_level_t *integrity_protection_level, const data_collection_model_integrity_protection_level_t *other)
{
    if (integrity_protection_level) {
        std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<std::shared_ptr<IntegrityProtectionLevel >*>(integrity_protection_level);
        if (obj) {
            if (other) {
                const std::shared_ptr<IntegrityProtectionLevel > &other_obj = *reinterpret_cast<const std::shared_ptr<IntegrityProtectionLevel >*>(other);
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
                const std::shared_ptr<IntegrityProtectionLevel > &other_obj = *reinterpret_cast<const std::shared_ptr<IntegrityProtectionLevel >*>(other);
                if (other_obj) {
                    obj.reset(new IntegrityProtectionLevel(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        integrity_protection_level = data_collection_model_integrity_protection_level_create_copy(other);
    }
    return integrity_protection_level;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_move(data_collection_model_integrity_protection_level_t *integrity_protection_level, data_collection_model_integrity_protection_level_t *other)
{
    std::shared_ptr<IntegrityProtectionLevel > *other_ptr = reinterpret_cast<std::shared_ptr<IntegrityProtectionLevel >*>(other);

    if (integrity_protection_level) {
        std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<std::shared_ptr<IntegrityProtectionLevel >*>(integrity_protection_level);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                integrity_protection_level = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return integrity_protection_level;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_integrity_protection_level_free(data_collection_model_integrity_protection_level_t *integrity_protection_level)
{
    if (!integrity_protection_level) return;
    delete reinterpret_cast<std::shared_ptr<IntegrityProtectionLevel >*>(integrity_protection_level);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_integrity_protection_level_toJSON(const data_collection_model_integrity_protection_level_t *integrity_protection_level, bool as_request)
{
    if (!integrity_protection_level) return NULL;
    const std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityProtectionLevel >*>(integrity_protection_level);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_integrity_protection_level_t*>(new std::shared_ptr<IntegrityProtectionLevel >(new IntegrityProtectionLevel(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_protection_level_is_equal_to(const data_collection_model_integrity_protection_level_t *first, const data_collection_model_integrity_protection_level_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<IntegrityProtectionLevel > &obj2 = *reinterpret_cast<const std::shared_ptr<IntegrityProtectionLevel >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<IntegrityProtectionLevel > &obj1 = *reinterpret_cast<const std::shared_ptr<IntegrityProtectionLevel >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_integrity_protection_level_get_horizontal_protection_level(const data_collection_model_integrity_protection_level_t *obj_integrity_protection_level)
{
    if (!obj_integrity_protection_level) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityProtectionLevel >*>(obj_integrity_protection_level);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename IntegrityProtectionLevel::HorizontalProtectionLevelType ResultFromType;
    const ResultFromType result_from = obj->getHorizontalProtectionLevel();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_horizontal_protection_level(data_collection_model_integrity_protection_level_t *obj_integrity_protection_level, const int32_t p_horizontal_protection_level)
{
    if (!obj_integrity_protection_level) return NULL;

    std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<std::shared_ptr<IntegrityProtectionLevel >*>(obj_integrity_protection_level);
    if (!obj) return NULL;

    const auto &value_from = p_horizontal_protection_level;
    typedef typename IntegrityProtectionLevel::HorizontalProtectionLevelType ValueType;

    ValueType value(value_from);

    if (!obj->setHorizontalProtectionLevel(value)) return NULL;

    return obj_integrity_protection_level;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_horizontal_protection_level_move(data_collection_model_integrity_protection_level_t *obj_integrity_protection_level, int32_t p_horizontal_protection_level)
{
    if (!obj_integrity_protection_level) return NULL;

    std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<std::shared_ptr<IntegrityProtectionLevel >*>(obj_integrity_protection_level);
    if (!obj) return NULL;

    const auto &value_from = p_horizontal_protection_level;
    typedef typename IntegrityProtectionLevel::HorizontalProtectionLevelType ValueType;

    ValueType value(value_from);

    
    if (!obj->setHorizontalProtectionLevel(std::move(value))) return NULL;

    return obj_integrity_protection_level;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_integrity_protection_level_has_vertical_protection_level(const data_collection_model_integrity_protection_level_t *obj_integrity_protection_level)
{
    if (!obj_integrity_protection_level) return false;

    const std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityProtectionLevel >*>(obj_integrity_protection_level);
    if (!obj) return false;

    return obj->getVerticalProtectionLevel().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_integrity_protection_level_get_vertical_protection_level(const data_collection_model_integrity_protection_level_t *obj_integrity_protection_level)
{
    if (!obj_integrity_protection_level) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<const std::shared_ptr<IntegrityProtectionLevel >*>(obj_integrity_protection_level);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename IntegrityProtectionLevel::VerticalProtectionLevelType ResultFromType;
    const ResultFromType result_from = obj->getVerticalProtectionLevel();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_vertical_protection_level(data_collection_model_integrity_protection_level_t *obj_integrity_protection_level, const int32_t p_vertical_protection_level)
{
    if (!obj_integrity_protection_level) return NULL;

    std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<std::shared_ptr<IntegrityProtectionLevel >*>(obj_integrity_protection_level);
    if (!obj) return NULL;

    const auto &value_from = p_vertical_protection_level;
    typedef typename IntegrityProtectionLevel::VerticalProtectionLevelType ValueType;

    ValueType value(value_from);

    if (!obj->setVerticalProtectionLevel(value)) return NULL;

    return obj_integrity_protection_level;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_integrity_protection_level_t *data_collection_model_integrity_protection_level_set_vertical_protection_level_move(data_collection_model_integrity_protection_level_t *obj_integrity_protection_level, int32_t p_vertical_protection_level)
{
    if (!obj_integrity_protection_level) return NULL;

    std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<std::shared_ptr<IntegrityProtectionLevel >*>(obj_integrity_protection_level);
    if (!obj) return NULL;

    const auto &value_from = p_vertical_protection_level;
    typedef typename IntegrityProtectionLevel::VerticalProtectionLevelType ValueType;

    ValueType value(value_from);

    
    if (!obj->setVerticalProtectionLevel(std::move(value))) return NULL;

    return obj_integrity_protection_level;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_integrity_protection_level_make_lnode(data_collection_model_integrity_protection_level_t *p_integrity_protection_level)
{
    return data_collection_lnode_create(p_integrity_protection_level, reinterpret_cast<void(*)(void*)>(data_collection_model_integrity_protection_level_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_integrity_protection_level_refcount(data_collection_model_integrity_protection_level_t *obj_integrity_protection_level)
{
    if (!obj_integrity_protection_level) return 0l;
    std::shared_ptr<IntegrityProtectionLevel > &obj = *reinterpret_cast<std::shared_ptr<IntegrityProtectionLevel >*>(obj_integrity_protection_level);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

