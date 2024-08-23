/**********************************************************************************************************************************
 * UeAreaIndication - C interface to the UeAreaIndication object
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

/*#include "UeAreaIndication.h" already included by data-collection-sp/data-collection.h */
#include "UeAreaIndication-internal.h"
#include "openapi/model/UeAreaIndication.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create(

)
{
    return reinterpret_cast<data_collection_model_ue_area_indication_t*>(new std::shared_ptr<UeAreaIndication>(new UeAreaIndication(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create_copy(const data_collection_model_ue_area_indication_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_ue_area_indication_t*>(new std::shared_ptr<UeAreaIndication >(new UeAreaIndication(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create_move(data_collection_model_ue_area_indication_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<UeAreaIndication > *obj = reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_copy(data_collection_model_ue_area_indication_t *ue_area_indication, const data_collection_model_ue_area_indication_t *other)
{
    if (ue_area_indication) {
        std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(ue_area_indication);
        if (obj) {
            if (other) {
                const std::shared_ptr<UeAreaIndication > &other_obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(other);
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
                const std::shared_ptr<UeAreaIndication > &other_obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(other);
                if (other_obj) {
                    obj.reset(new UeAreaIndication(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        ue_area_indication = data_collection_model_ue_area_indication_create_copy(other);
    }
    return ue_area_indication;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_move(data_collection_model_ue_area_indication_t *ue_area_indication, data_collection_model_ue_area_indication_t *other)
{
    std::shared_ptr<UeAreaIndication > *other_ptr = reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(other);

    if (ue_area_indication) {
        std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(ue_area_indication);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                ue_area_indication = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return ue_area_indication;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ue_area_indication_free(data_collection_model_ue_area_indication_t *ue_area_indication)
{
    if (!ue_area_indication) return;
    delete reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(ue_area_indication);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ue_area_indication_toJSON(const data_collection_model_ue_area_indication_t *ue_area_indication, bool as_request)
{
    if (!ue_area_indication) return NULL;
    const std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(ue_area_indication);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ue_area_indication_t*>(new std::shared_ptr<UeAreaIndication >(new UeAreaIndication(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_area_indication_is_equal_to(const data_collection_model_ue_area_indication_t *first, const data_collection_model_ue_area_indication_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<UeAreaIndication > &obj2 = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<UeAreaIndication > &obj1 = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_area_indication_has_country(const data_collection_model_ue_area_indication_t *obj_ue_area_indication)
{
    if (!obj_ue_area_indication) return false;

    const std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    if (!obj) return false;

    return obj->getCountry().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ue_area_indication_get_country(const data_collection_model_ue_area_indication_t *obj_ue_area_indication)
{
    if (!obj_ue_area_indication) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename UeAreaIndication::CountryType ResultFromType;
    const ResultFromType result_from = obj->getCountry();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_country(data_collection_model_ue_area_indication_t *obj_ue_area_indication, const char* p_country)
{
    if (!obj_ue_area_indication) return NULL;

    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    if (!obj) return NULL;

    const auto &value_from = p_country;
    typedef typename UeAreaIndication::CountryType ValueType;

    ValueType value(value_from);

    if (!obj->setCountry(value)) return NULL;

    return obj_ue_area_indication;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_country_move(data_collection_model_ue_area_indication_t *obj_ue_area_indication, char* p_country)
{
    if (!obj_ue_area_indication) return NULL;

    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    if (!obj) return NULL;

    const auto &value_from = p_country;
    typedef typename UeAreaIndication::CountryType ValueType;

    ValueType value(value_from);

    
    if (!obj->setCountry(std::move(value))) return NULL;

    return obj_ue_area_indication;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ue_area_indication_has_international_area_ind(const data_collection_model_ue_area_indication_t *obj_ue_area_indication)
{
    if (!obj_ue_area_indication) return false;

    const std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    if (!obj) return false;

    return obj->isInternationalAreaInd().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_ue_area_indication_is_international_area_ind(const data_collection_model_ue_area_indication_t *obj_ue_area_indication)
{
    if (!obj_ue_area_indication) {
        const bool result = 0;
        return result;
    }

    const std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    if (!obj) {
        const bool result = 0;
        return result;
    }

    typedef typename UeAreaIndication::InternationalAreaIndType ResultFromType;
    const ResultFromType result_from = obj->isInternationalAreaInd();
    const ResultFromType::value_type result = result_from.has_value()?result_from.value():ResultFromType::value_type();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_international_area_ind(data_collection_model_ue_area_indication_t *obj_ue_area_indication, const bool p_international_area_ind)
{
    if (!obj_ue_area_indication) return NULL;

    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    if (!obj) return NULL;

    const auto &value_from = p_international_area_ind;
    typedef typename UeAreaIndication::InternationalAreaIndType ValueType;

    ValueType value(value_from);

    if (!obj->setInternationalAreaInd(value)) return NULL;

    return obj_ue_area_indication;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_international_area_ind_move(data_collection_model_ue_area_indication_t *obj_ue_area_indication, bool p_international_area_ind)
{
    if (!obj_ue_area_indication) return NULL;

    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    if (!obj) return NULL;

    const auto &value_from = p_international_area_ind;
    typedef typename UeAreaIndication::InternationalAreaIndType ValueType;

    ValueType value(value_from);

    
    if (!obj->setInternationalAreaInd(std::move(value))) return NULL;

    return obj_ue_area_indication;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ue_area_indication_make_lnode(data_collection_model_ue_area_indication_t *p_ue_area_indication)
{
    return data_collection_lnode_create(p_ue_area_indication, reinterpret_cast<void(*)(void*)>(data_collection_model_ue_area_indication_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ue_area_indication_refcount(data_collection_model_ue_area_indication_t *obj_ue_area_indication)
{
    if (!obj_ue_area_indication) return 0l;
    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

