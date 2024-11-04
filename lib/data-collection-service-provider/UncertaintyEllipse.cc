/**********************************************************************************************************************************
 * UncertaintyEllipse - C interface to the UncertaintyEllipse object
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

/*#include "UncertaintyEllipse.h" already included by data-collection-sp/data-collection.h */
#include "UncertaintyEllipse-internal.h"
#include "openapi/model/UncertaintyEllipse.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_create(


)
{
    return reinterpret_cast<data_collection_model_uncertainty_ellipse_t*>(new std::shared_ptr<UncertaintyEllipse>(new UncertaintyEllipse(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_create_copy(const data_collection_model_uncertainty_ellipse_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_uncertainty_ellipse_t*>(new std::shared_ptr<UncertaintyEllipse >(new UncertaintyEllipse(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_create_move(data_collection_model_uncertainty_ellipse_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<UncertaintyEllipse > *obj = reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_copy(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, const data_collection_model_uncertainty_ellipse_t *other)
{
    if (uncertainty_ellipse) {
        std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(uncertainty_ellipse);
        if (obj) {
            if (other) {
                const std::shared_ptr<UncertaintyEllipse > &other_obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(other);
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
                const std::shared_ptr<UncertaintyEllipse > &other_obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(other);
                if (other_obj) {
                    obj.reset(new UncertaintyEllipse(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        uncertainty_ellipse = data_collection_model_uncertainty_ellipse_create_copy(other);
    }
    return uncertainty_ellipse;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_move(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, data_collection_model_uncertainty_ellipse_t *other)
{
    std::shared_ptr<UncertaintyEllipse > *other_ptr = reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(other);

    if (uncertainty_ellipse) {
        std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(uncertainty_ellipse);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                uncertainty_ellipse = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return uncertainty_ellipse;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_uncertainty_ellipse_free(data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse)
{
    if (!uncertainty_ellipse) return;
    delete reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(uncertainty_ellipse);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_uncertainty_ellipse_toJSON(const data_collection_model_uncertainty_ellipse_t *uncertainty_ellipse, bool as_request)
{
    if (!uncertainty_ellipse) return NULL;
    const std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(uncertainty_ellipse);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_uncertainty_ellipse_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_uncertainty_ellipse_t*>(new std::shared_ptr<UncertaintyEllipse >(new UncertaintyEllipse(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_uncertainty_ellipse_is_equal_to(const data_collection_model_uncertainty_ellipse_t *first, const data_collection_model_uncertainty_ellipse_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<UncertaintyEllipse > &obj2 = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<UncertaintyEllipse > &obj1 = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_uncertainty_ellipse_get_semi_major(const data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse)
{
    if (!obj_uncertainty_ellipse) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename UncertaintyEllipse::SemiMajorType ResultFromType;
    const ResultFromType &result_from = obj->getSemiMajor();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_major(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, const float p_semi_major)
{
    if (!obj_uncertainty_ellipse) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_semi_major;
    typedef typename UncertaintyEllipse::SemiMajorType ValueType;

    ValueType value(value_from);

    if (!obj->setSemiMajor(value)) return NULL;

    return obj_uncertainty_ellipse;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_major_move(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, float p_semi_major)
{
    if (!obj_uncertainty_ellipse) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_semi_major;
    typedef typename UncertaintyEllipse::SemiMajorType ValueType;

    ValueType value(value_from);

    if (!obj->setSemiMajor(std::move(value))) return NULL;

    return obj_uncertainty_ellipse;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const float data_collection_model_uncertainty_ellipse_get_semi_minor(const data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse)
{
    if (!obj_uncertainty_ellipse) {
        const float result = 0;
        return result;
    }

    const std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    if (!obj) {
        const float result = 0;
        return result;
    }

    typedef typename UncertaintyEllipse::SemiMinorType ResultFromType;
    const ResultFromType &result_from = obj->getSemiMinor();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_minor(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, const float p_semi_minor)
{
    if (!obj_uncertainty_ellipse) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_semi_minor;
    typedef typename UncertaintyEllipse::SemiMinorType ValueType;

    ValueType value(value_from);

    if (!obj->setSemiMinor(value)) return NULL;

    return obj_uncertainty_ellipse;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_semi_minor_move(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, float p_semi_minor)
{
    if (!obj_uncertainty_ellipse) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_semi_minor;
    typedef typename UncertaintyEllipse::SemiMinorType ValueType;

    ValueType value(value_from);

    if (!obj->setSemiMinor(std::move(value))) return NULL;

    return obj_uncertainty_ellipse;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_uncertainty_ellipse_get_orientation_major(const data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse)
{
    if (!obj_uncertainty_ellipse) {
        const int32_t result = 0;
        return result;
    }

    const std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<const std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    if (!obj) {
        const int32_t result = 0;
        return result;
    }

    typedef typename UncertaintyEllipse::OrientationMajorType ResultFromType;
    const ResultFromType &result_from = obj->getOrientationMajor();
    const ResultFromType result = result_from;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_orientation_major(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, const int32_t p_orientation_major)
{
    if (!obj_uncertainty_ellipse) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_orientation_major;
    typedef typename UncertaintyEllipse::OrientationMajorType ValueType;

    ValueType value(value_from);

    if (!obj->setOrientationMajor(value)) return NULL;

    return obj_uncertainty_ellipse;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_uncertainty_ellipse_t *data_collection_model_uncertainty_ellipse_set_orientation_major_move(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse, int32_t p_orientation_major)
{
    if (!obj_uncertainty_ellipse) return NULL;

    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    if (!obj) return NULL;

    const auto &value_from = p_orientation_major;
    typedef typename UncertaintyEllipse::OrientationMajorType ValueType;

    ValueType value(value_from);

    if (!obj->setOrientationMajor(std::move(value))) return NULL;

    return obj_uncertainty_ellipse;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_uncertainty_ellipse_make_lnode(data_collection_model_uncertainty_ellipse_t *p_uncertainty_ellipse)
{
    return data_collection_lnode_create(p_uncertainty_ellipse, reinterpret_cast<void(*)(void*)>(data_collection_model_uncertainty_ellipse_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_uncertainty_ellipse_refcount(data_collection_model_uncertainty_ellipse_t *obj_uncertainty_ellipse)
{
    if (!obj_uncertainty_ellipse) return 0l;
    std::shared_ptr<UncertaintyEllipse > &obj = *reinterpret_cast<std::shared_ptr<UncertaintyEllipse >*>(obj_uncertainty_ellipse);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

