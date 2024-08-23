/**********************************************************************************************************************************
 * CivicAddress - C interface to the CivicAddress object
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

/*#include "CivicAddress.h" already included by data-collection-sp/data-collection.h */
#include "CivicAddress-internal.h"
#include "openapi/model/CivicAddress.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_create(

































)
{
    return reinterpret_cast<data_collection_model_civic_address_t*>(new std::shared_ptr<CivicAddress>(new CivicAddress(

































)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_create_copy(const data_collection_model_civic_address_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_civic_address_t*>(new std::shared_ptr<CivicAddress >(new CivicAddress(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_create_move(data_collection_model_civic_address_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<CivicAddress > *obj = reinterpret_cast<std::shared_ptr<CivicAddress >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_copy(data_collection_model_civic_address_t *civic_address, const data_collection_model_civic_address_t *other)
{
    if (civic_address) {
        std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(civic_address);
        if (obj) {
            if (other) {
                const std::shared_ptr<CivicAddress > &other_obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(other);
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
                const std::shared_ptr<CivicAddress > &other_obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(other);
                if (other_obj) {
                    obj.reset(new CivicAddress(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        civic_address = data_collection_model_civic_address_create_copy(other);
    }
    return civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_move(data_collection_model_civic_address_t *civic_address, data_collection_model_civic_address_t *other)
{
    std::shared_ptr<CivicAddress > *other_ptr = reinterpret_cast<std::shared_ptr<CivicAddress >*>(other);

    if (civic_address) {
        std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(civic_address);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                civic_address = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_civic_address_free(data_collection_model_civic_address_t *civic_address)
{
    if (!civic_address) return;
    delete reinterpret_cast<std::shared_ptr<CivicAddress >*>(civic_address);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_civic_address_toJSON(const data_collection_model_civic_address_t *civic_address, bool as_request)
{
    if (!civic_address) return NULL;
    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(civic_address);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_civic_address_t*>(new std::shared_ptr<CivicAddress >(new CivicAddress(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_is_equal_to(const data_collection_model_civic_address_t *first, const data_collection_model_civic_address_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<CivicAddress > &obj2 = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<CivicAddress > &obj1 = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_country(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getCountry().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_country(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::CountryType ResultFromType;
    const ResultFromType result_from = obj->getCountry();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_country(data_collection_model_civic_address_t *obj_civic_address, const char* p_country)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_country;
    typedef typename CivicAddress::CountryType ValueType;

    ValueType value(value_from);

    if (!obj->setCountry(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_country_move(data_collection_model_civic_address_t *obj_civic_address, char* p_country)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_country;
    typedef typename CivicAddress::CountryType ValueType;

    ValueType value(value_from);

    
    if (!obj->setCountry(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a1(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getA1().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a1(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::A1Type ResultFromType;
    const ResultFromType result_from = obj->getA1();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a1(data_collection_model_civic_address_t *obj_civic_address, const char* p_a1)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a1;
    typedef typename CivicAddress::A1Type ValueType;

    ValueType value(value_from);

    if (!obj->setA1(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a1_move(data_collection_model_civic_address_t *obj_civic_address, char* p_a1)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a1;
    typedef typename CivicAddress::A1Type ValueType;

    ValueType value(value_from);

    
    if (!obj->setA1(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a2(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getA2().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a2(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::A2Type ResultFromType;
    const ResultFromType result_from = obj->getA2();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a2(data_collection_model_civic_address_t *obj_civic_address, const char* p_a2)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a2;
    typedef typename CivicAddress::A2Type ValueType;

    ValueType value(value_from);

    if (!obj->setA2(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a2_move(data_collection_model_civic_address_t *obj_civic_address, char* p_a2)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a2;
    typedef typename CivicAddress::A2Type ValueType;

    ValueType value(value_from);

    
    if (!obj->setA2(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a3(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getA3().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a3(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::A3Type ResultFromType;
    const ResultFromType result_from = obj->getA3();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a3(data_collection_model_civic_address_t *obj_civic_address, const char* p_a3)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a3;
    typedef typename CivicAddress::A3Type ValueType;

    ValueType value(value_from);

    if (!obj->setA3(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a3_move(data_collection_model_civic_address_t *obj_civic_address, char* p_a3)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a3;
    typedef typename CivicAddress::A3Type ValueType;

    ValueType value(value_from);

    
    if (!obj->setA3(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a4(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getA4().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a4(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::A4Type ResultFromType;
    const ResultFromType result_from = obj->getA4();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a4(data_collection_model_civic_address_t *obj_civic_address, const char* p_a4)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a4;
    typedef typename CivicAddress::A4Type ValueType;

    ValueType value(value_from);

    if (!obj->setA4(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a4_move(data_collection_model_civic_address_t *obj_civic_address, char* p_a4)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a4;
    typedef typename CivicAddress::A4Type ValueType;

    ValueType value(value_from);

    
    if (!obj->setA4(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a5(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getA5().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a5(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::A5Type ResultFromType;
    const ResultFromType result_from = obj->getA5();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a5(data_collection_model_civic_address_t *obj_civic_address, const char* p_a5)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a5;
    typedef typename CivicAddress::A5Type ValueType;

    ValueType value(value_from);

    if (!obj->setA5(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a5_move(data_collection_model_civic_address_t *obj_civic_address, char* p_a5)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a5;
    typedef typename CivicAddress::A5Type ValueType;

    ValueType value(value_from);

    
    if (!obj->setA5(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_a6(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getA6().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a6(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::A6Type ResultFromType;
    const ResultFromType result_from = obj->getA6();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a6(data_collection_model_civic_address_t *obj_civic_address, const char* p_a6)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a6;
    typedef typename CivicAddress::A6Type ValueType;

    ValueType value(value_from);

    if (!obj->setA6(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a6_move(data_collection_model_civic_address_t *obj_civic_address, char* p_a6)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_a6;
    typedef typename CivicAddress::A6Type ValueType;

    ValueType value(value_from);

    
    if (!obj->setA6(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_prd(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getPRD().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_prd(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::PRDType ResultFromType;
    const ResultFromType result_from = obj->getPRD();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prd(data_collection_model_civic_address_t *obj_civic_address, const char* p_prd)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_prd;
    typedef typename CivicAddress::PRDType ValueType;

    ValueType value(value_from);

    if (!obj->setPRD(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prd_move(data_collection_model_civic_address_t *obj_civic_address, char* p_prd)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_prd;
    typedef typename CivicAddress::PRDType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPRD(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_pod(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getPOD().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pod(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::PODType ResultFromType;
    const ResultFromType result_from = obj->getPOD();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pod(data_collection_model_civic_address_t *obj_civic_address, const char* p_pod)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_pod;
    typedef typename CivicAddress::PODType ValueType;

    ValueType value(value_from);

    if (!obj->setPOD(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pod_move(data_collection_model_civic_address_t *obj_civic_address, char* p_pod)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_pod;
    typedef typename CivicAddress::PODType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPOD(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_sts(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getSTS().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_sts(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::STSType ResultFromType;
    const ResultFromType result_from = obj->getSTS();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_sts(data_collection_model_civic_address_t *obj_civic_address, const char* p_sts)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_sts;
    typedef typename CivicAddress::STSType ValueType;

    ValueType value(value_from);

    if (!obj->setSTS(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_sts_move(data_collection_model_civic_address_t *obj_civic_address, char* p_sts)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_sts;
    typedef typename CivicAddress::STSType ValueType;

    ValueType value(value_from);

    
    if (!obj->setSTS(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_hno(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getHNO().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_hno(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::HNOType ResultFromType;
    const ResultFromType result_from = obj->getHNO();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hno(data_collection_model_civic_address_t *obj_civic_address, const char* p_hno)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_hno;
    typedef typename CivicAddress::HNOType ValueType;

    ValueType value(value_from);

    if (!obj->setHNO(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hno_move(data_collection_model_civic_address_t *obj_civic_address, char* p_hno)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_hno;
    typedef typename CivicAddress::HNOType ValueType;

    ValueType value(value_from);

    
    if (!obj->setHNO(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_hns(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getHNS().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_hns(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::HNSType ResultFromType;
    const ResultFromType result_from = obj->getHNS();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hns(data_collection_model_civic_address_t *obj_civic_address, const char* p_hns)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_hns;
    typedef typename CivicAddress::HNSType ValueType;

    ValueType value(value_from);

    if (!obj->setHNS(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hns_move(data_collection_model_civic_address_t *obj_civic_address, char* p_hns)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_hns;
    typedef typename CivicAddress::HNSType ValueType;

    ValueType value(value_from);

    
    if (!obj->setHNS(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_lmk(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getLMK().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_lmk(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::LMKType ResultFromType;
    const ResultFromType result_from = obj->getLMK();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_lmk(data_collection_model_civic_address_t *obj_civic_address, const char* p_lmk)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_lmk;
    typedef typename CivicAddress::LMKType ValueType;

    ValueType value(value_from);

    if (!obj->setLMK(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_lmk_move(data_collection_model_civic_address_t *obj_civic_address, char* p_lmk)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_lmk;
    typedef typename CivicAddress::LMKType ValueType;

    ValueType value(value_from);

    
    if (!obj->setLMK(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_loc(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getLOC().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_loc(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::LOCType ResultFromType;
    const ResultFromType result_from = obj->getLOC();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_loc(data_collection_model_civic_address_t *obj_civic_address, const char* p_loc)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_loc;
    typedef typename CivicAddress::LOCType ValueType;

    ValueType value(value_from);

    if (!obj->setLOC(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_loc_move(data_collection_model_civic_address_t *obj_civic_address, char* p_loc)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_loc;
    typedef typename CivicAddress::LOCType ValueType;

    ValueType value(value_from);

    
    if (!obj->setLOC(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_nam(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getNAM().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_nam(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::NAMType ResultFromType;
    const ResultFromType result_from = obj->getNAM();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_nam(data_collection_model_civic_address_t *obj_civic_address, const char* p_nam)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_nam;
    typedef typename CivicAddress::NAMType ValueType;

    ValueType value(value_from);

    if (!obj->setNAM(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_nam_move(data_collection_model_civic_address_t *obj_civic_address, char* p_nam)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_nam;
    typedef typename CivicAddress::NAMType ValueType;

    ValueType value(value_from);

    
    if (!obj->setNAM(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_pc(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getPC().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pc(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::PCType ResultFromType;
    const ResultFromType result_from = obj->getPC();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pc(data_collection_model_civic_address_t *obj_civic_address, const char* p_pc)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_pc;
    typedef typename CivicAddress::PCType ValueType;

    ValueType value(value_from);

    if (!obj->setPC(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pc_move(data_collection_model_civic_address_t *obj_civic_address, char* p_pc)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_pc;
    typedef typename CivicAddress::PCType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPC(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_bld(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getBLD().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_bld(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::BLDType ResultFromType;
    const ResultFromType result_from = obj->getBLD();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_bld(data_collection_model_civic_address_t *obj_civic_address, const char* p_bld)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_bld;
    typedef typename CivicAddress::BLDType ValueType;

    ValueType value(value_from);

    if (!obj->setBLD(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_bld_move(data_collection_model_civic_address_t *obj_civic_address, char* p_bld)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_bld;
    typedef typename CivicAddress::BLDType ValueType;

    ValueType value(value_from);

    
    if (!obj->setBLD(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_unit(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getUNIT().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_unit(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::UNITType ResultFromType;
    const ResultFromType result_from = obj->getUNIT();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_unit(data_collection_model_civic_address_t *obj_civic_address, const char* p_unit)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_unit;
    typedef typename CivicAddress::UNITType ValueType;

    ValueType value(value_from);

    if (!obj->setUNIT(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_unit_move(data_collection_model_civic_address_t *obj_civic_address, char* p_unit)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_unit;
    typedef typename CivicAddress::UNITType ValueType;

    ValueType value(value_from);

    
    if (!obj->setUNIT(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_flr(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getFLR().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_flr(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::FLRType ResultFromType;
    const ResultFromType result_from = obj->getFLR();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_flr(data_collection_model_civic_address_t *obj_civic_address, const char* p_flr)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_flr;
    typedef typename CivicAddress::FLRType ValueType;

    ValueType value(value_from);

    if (!obj->setFLR(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_flr_move(data_collection_model_civic_address_t *obj_civic_address, char* p_flr)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_flr;
    typedef typename CivicAddress::FLRType ValueType;

    ValueType value(value_from);

    
    if (!obj->setFLR(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_room(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getROOM().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_room(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::ROOMType ResultFromType;
    const ResultFromType result_from = obj->getROOM();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_room(data_collection_model_civic_address_t *obj_civic_address, const char* p_room)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_room;
    typedef typename CivicAddress::ROOMType ValueType;

    ValueType value(value_from);

    if (!obj->setROOM(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_room_move(data_collection_model_civic_address_t *obj_civic_address, char* p_room)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_room;
    typedef typename CivicAddress::ROOMType ValueType;

    ValueType value(value_from);

    
    if (!obj->setROOM(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_plc(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getPLC().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_plc(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::PLCType ResultFromType;
    const ResultFromType result_from = obj->getPLC();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_plc(data_collection_model_civic_address_t *obj_civic_address, const char* p_plc)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_plc;
    typedef typename CivicAddress::PLCType ValueType;

    ValueType value(value_from);

    if (!obj->setPLC(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_plc_move(data_collection_model_civic_address_t *obj_civic_address, char* p_plc)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_plc;
    typedef typename CivicAddress::PLCType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPLC(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_pcn(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getPCN().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pcn(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::PCNType ResultFromType;
    const ResultFromType result_from = obj->getPCN();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pcn(data_collection_model_civic_address_t *obj_civic_address, const char* p_pcn)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_pcn;
    typedef typename CivicAddress::PCNType ValueType;

    ValueType value(value_from);

    if (!obj->setPCN(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pcn_move(data_collection_model_civic_address_t *obj_civic_address, char* p_pcn)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_pcn;
    typedef typename CivicAddress::PCNType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPCN(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_pobox(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getPOBOX().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pobox(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::POBOXType ResultFromType;
    const ResultFromType result_from = obj->getPOBOX();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pobox(data_collection_model_civic_address_t *obj_civic_address, const char* p_pobox)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_pobox;
    typedef typename CivicAddress::POBOXType ValueType;

    ValueType value(value_from);

    if (!obj->setPOBOX(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pobox_move(data_collection_model_civic_address_t *obj_civic_address, char* p_pobox)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_pobox;
    typedef typename CivicAddress::POBOXType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPOBOX(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_addcode(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getADDCODE().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_addcode(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::ADDCODEType ResultFromType;
    const ResultFromType result_from = obj->getADDCODE();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_addcode(data_collection_model_civic_address_t *obj_civic_address, const char* p_addcode)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_addcode;
    typedef typename CivicAddress::ADDCODEType ValueType;

    ValueType value(value_from);

    if (!obj->setADDCODE(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_addcode_move(data_collection_model_civic_address_t *obj_civic_address, char* p_addcode)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_addcode;
    typedef typename CivicAddress::ADDCODEType ValueType;

    ValueType value(value_from);

    
    if (!obj->setADDCODE(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_seat(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getSEAT().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_seat(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::SEATType ResultFromType;
    const ResultFromType result_from = obj->getSEAT();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_seat(data_collection_model_civic_address_t *obj_civic_address, const char* p_seat)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_seat;
    typedef typename CivicAddress::SEATType ValueType;

    ValueType value(value_from);

    if (!obj->setSEAT(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_seat_move(data_collection_model_civic_address_t *obj_civic_address, char* p_seat)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_seat;
    typedef typename CivicAddress::SEATType ValueType;

    ValueType value(value_from);

    
    if (!obj->setSEAT(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_rd(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getRD().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rd(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::RDType ResultFromType;
    const ResultFromType result_from = obj->getRD();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rd(data_collection_model_civic_address_t *obj_civic_address, const char* p_rd)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_rd;
    typedef typename CivicAddress::RDType ValueType;

    ValueType value(value_from);

    if (!obj->setRD(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rd_move(data_collection_model_civic_address_t *obj_civic_address, char* p_rd)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_rd;
    typedef typename CivicAddress::RDType ValueType;

    ValueType value(value_from);

    
    if (!obj->setRD(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_rdsec(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getRDSEC().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rdsec(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::RDSECType ResultFromType;
    const ResultFromType result_from = obj->getRDSEC();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsec(data_collection_model_civic_address_t *obj_civic_address, const char* p_rdsec)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_rdsec;
    typedef typename CivicAddress::RDSECType ValueType;

    ValueType value(value_from);

    if (!obj->setRDSEC(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsec_move(data_collection_model_civic_address_t *obj_civic_address, char* p_rdsec)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_rdsec;
    typedef typename CivicAddress::RDSECType ValueType;

    ValueType value(value_from);

    
    if (!obj->setRDSEC(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_rdbr(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getRDBR().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rdbr(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::RDBRType ResultFromType;
    const ResultFromType result_from = obj->getRDBR();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdbr(data_collection_model_civic_address_t *obj_civic_address, const char* p_rdbr)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_rdbr;
    typedef typename CivicAddress::RDBRType ValueType;

    ValueType value(value_from);

    if (!obj->setRDBR(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdbr_move(data_collection_model_civic_address_t *obj_civic_address, char* p_rdbr)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_rdbr;
    typedef typename CivicAddress::RDBRType ValueType;

    ValueType value(value_from);

    
    if (!obj->setRDBR(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_rdsubbr(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getRDSUBBR().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rdsubbr(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::RDSUBBRType ResultFromType;
    const ResultFromType result_from = obj->getRDSUBBR();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsubbr(data_collection_model_civic_address_t *obj_civic_address, const char* p_rdsubbr)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_rdsubbr;
    typedef typename CivicAddress::RDSUBBRType ValueType;

    ValueType value(value_from);

    if (!obj->setRDSUBBR(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsubbr_move(data_collection_model_civic_address_t *obj_civic_address, char* p_rdsubbr)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_rdsubbr;
    typedef typename CivicAddress::RDSUBBRType ValueType;

    ValueType value(value_from);

    
    if (!obj->setRDSUBBR(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_prm(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getPRM().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_prm(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::PRMType ResultFromType;
    const ResultFromType result_from = obj->getPRM();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prm(data_collection_model_civic_address_t *obj_civic_address, const char* p_prm)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_prm;
    typedef typename CivicAddress::PRMType ValueType;

    ValueType value(value_from);

    if (!obj->setPRM(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prm_move(data_collection_model_civic_address_t *obj_civic_address, char* p_prm)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_prm;
    typedef typename CivicAddress::PRMType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPRM(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_pom(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getPOM().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pom(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::POMType ResultFromType;
    const ResultFromType result_from = obj->getPOM();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pom(data_collection_model_civic_address_t *obj_civic_address, const char* p_pom)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_pom;
    typedef typename CivicAddress::POMType ValueType;

    ValueType value(value_from);

    if (!obj->setPOM(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pom_move(data_collection_model_civic_address_t *obj_civic_address, char* p_pom)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_pom;
    typedef typename CivicAddress::POMType ValueType;

    ValueType value(value_from);

    
    if (!obj->setPOM(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_usage_rules(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getUsageRules().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_usage_rules(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::UsageRulesType ResultFromType;
    const ResultFromType result_from = obj->getUsageRules();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_usage_rules(data_collection_model_civic_address_t *obj_civic_address, const char* p_usage_rules)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_usage_rules;
    typedef typename CivicAddress::UsageRulesType ValueType;

    ValueType value(value_from);

    if (!obj->setUsageRules(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_usage_rules_move(data_collection_model_civic_address_t *obj_civic_address, char* p_usage_rules)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_usage_rules;
    typedef typename CivicAddress::UsageRulesType ValueType;

    ValueType value(value_from);

    
    if (!obj->setUsageRules(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_method(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getMethod().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_method(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::MethodType ResultFromType;
    const ResultFromType result_from = obj->getMethod();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_method(data_collection_model_civic_address_t *obj_civic_address, const char* p_method)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_method;
    typedef typename CivicAddress::MethodType ValueType;

    ValueType value(value_from);

    if (!obj->setMethod(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_method_move(data_collection_model_civic_address_t *obj_civic_address, char* p_method)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_method;
    typedef typename CivicAddress::MethodType ValueType;

    ValueType value(value_from);

    
    if (!obj->setMethod(std::move(value))) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_has_provided_by(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return false;

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return false;

    return obj->getProvidedBy().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_provided_by(const data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<const std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename CivicAddress::ProvidedByType ResultFromType;
    const ResultFromType result_from = obj->getProvidedBy();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_provided_by(data_collection_model_civic_address_t *obj_civic_address, const char* p_provided_by)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_provided_by;
    typedef typename CivicAddress::ProvidedByType ValueType;

    ValueType value(value_from);

    if (!obj->setProvidedBy(value)) return NULL;

    return obj_civic_address;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_provided_by_move(data_collection_model_civic_address_t *obj_civic_address, char* p_provided_by)
{
    if (!obj_civic_address) return NULL;

    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    if (!obj) return NULL;

    const auto &value_from = p_provided_by;
    typedef typename CivicAddress::ProvidedByType ValueType;

    ValueType value(value_from);

    
    if (!obj->setProvidedBy(std::move(value))) return NULL;

    return obj_civic_address;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_civic_address_make_lnode(data_collection_model_civic_address_t *p_civic_address)
{
    return data_collection_lnode_create(p_civic_address, reinterpret_cast<void(*)(void*)>(data_collection_model_civic_address_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_civic_address_refcount(data_collection_model_civic_address_t *obj_civic_address)
{
    if (!obj_civic_address) return 0l;
    std::shared_ptr<CivicAddress > &obj = *reinterpret_cast<std::shared_ptr<CivicAddress >*>(obj_civic_address);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

