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


#include "ogs-memory-helper.h"
#include "utilities.h"
#include "openapi/model/ModelException.hh"
#include "data-collection-sp/data-collection.h"

/*#include "UeAreaIndication.h" already included by data-collection-sp/data-collection.h */
#include "UeAreaIndication-internal.h"
#include "openapi/model/UeAreaIndication.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create(

)
{
    return reinterpret_cast<data_collection_model_ue_area_indication_t*>(new std::shared_ptr<UeAreaIndication>(new UeAreaIndication(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create_copy(const data_collection_model_ue_area_indication_t *other)
{
    return reinterpret_cast<data_collection_model_ue_area_indication_t*>(new std::shared_ptr<UeAreaIndication >(new UeAreaIndication(**reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_create_move(data_collection_model_ue_area_indication_t *other)
{
    return reinterpret_cast<data_collection_model_ue_area_indication_t*>(new std::shared_ptr<UeAreaIndication >(std::move(*reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(other))));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_copy(data_collection_model_ue_area_indication_t *ue_area_indication, const data_collection_model_ue_area_indication_t *other)
{
    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(ue_area_indication);
    *obj = **reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(other);
    return ue_area_indication;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_move(data_collection_model_ue_area_indication_t *ue_area_indication, data_collection_model_ue_area_indication_t *other)
{
    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(ue_area_indication);
    obj = std::move(*reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(other));
    return ue_area_indication;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_ue_area_indication_free(data_collection_model_ue_area_indication_t *ue_area_indication)
{
    delete reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(ue_area_indication);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_ue_area_indication_toJSON(const data_collection_model_ue_area_indication_t *ue_area_indication, bool as_request)
{
    const std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(ue_area_indication);
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const char* data_collection_model_ue_area_indication_get_country(const data_collection_model_ue_area_indication_t *obj_ue_area_indication)
{
    const std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    typedef typename UeAreaIndication::CountryType ResultFromType;
    const ResultFromType result_from = obj->getCountry();
    const char *result = result_from.c_str();
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_country(data_collection_model_ue_area_indication_t *obj_ue_area_indication, const char* p_country)
{
    if (obj_ue_area_indication == NULL) return NULL;

    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    const auto &value_from = p_country;
    typedef typename UeAreaIndication::CountryType ValueType;

    ValueType value(value_from);
    if (!obj->setCountry(value)) return NULL;
    return obj_ue_area_indication;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_country_move(data_collection_model_ue_area_indication_t *obj_ue_area_indication, char* p_country)
{
    if (obj_ue_area_indication == NULL) return NULL;

    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    const auto &value_from = p_country;
    typedef typename UeAreaIndication::CountryType ValueType;

    ValueType value(value_from);
    
    if (!obj->setCountry(std::move(value))) return NULL;
    return obj_ue_area_indication;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const bool data_collection_model_ue_area_indication_is_international_area_ind(const data_collection_model_ue_area_indication_t *obj_ue_area_indication)
{
    const std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<const std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    typedef typename UeAreaIndication::InternationalAreaIndType ResultFromType;
    const ResultFromType result_from = obj->isInternationalAreaInd();
    const ResultFromType result = result_from;
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_international_area_ind(data_collection_model_ue_area_indication_t *obj_ue_area_indication, const bool p_international_area_ind)
{
    if (obj_ue_area_indication == NULL) return NULL;

    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    const auto &value_from = p_international_area_ind;
    typedef typename UeAreaIndication::InternationalAreaIndType ValueType;

    ValueType value = value_from;
    if (!obj->setInternationalAreaInd(value)) return NULL;
    return obj_ue_area_indication;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_ue_area_indication_t *data_collection_model_ue_area_indication_set_international_area_ind_move(data_collection_model_ue_area_indication_t *obj_ue_area_indication, bool p_international_area_ind)
{
    if (obj_ue_area_indication == NULL) return NULL;

    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    const auto &value_from = p_international_area_ind;
    typedef typename UeAreaIndication::InternationalAreaIndType ValueType;

    ValueType value = value_from;
    
    if (!obj->setInternationalAreaInd(std::move(value))) return NULL;
    return obj_ue_area_indication;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_ue_area_indication_make_lnode(data_collection_model_ue_area_indication_t *p_ue_area_indication)
{
    return data_collection_lnode_create(p_ue_area_indication, reinterpret_cast<void(*)(void*)>(data_collection_model_ue_area_indication_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ue_area_indication_refcount(data_collection_model_ue_area_indication_t *obj_ue_area_indication)
{
    std::shared_ptr<UeAreaIndication > &obj = *reinterpret_cast<std::shared_ptr<UeAreaIndication >*>(obj_ue_area_indication);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

