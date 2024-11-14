/**********************************************************************************************************************************
 * Ecgi - C interface to the Ecgi object
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

/*#include "Ecgi.h" already included by data-collection-sp/data-collection.h */
#include "Ecgi-internal.h"
#include "openapi/model/Ecgi.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_create(


)
{
    return reinterpret_cast<data_collection_model_ecgi_t*>(new std::shared_ptr<Ecgi>(new Ecgi(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_create_ref(const data_collection_model_ecgi_t *other)
{
    return reinterpret_cast<data_collection_model_ecgi_t*>(new std::shared_ptr<Ecgi>(*reinterpret_cast<const std::shared_ptr<Ecgi >*>(other)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_create_copy(const data_collection_model_ecgi_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<Ecgi > &obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_ecgi_t*>(new std::shared_ptr<Ecgi >(new Ecgi(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_create_move(data_collection_model_ecgi_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<Ecgi > *obj = reinterpret_cast<std::shared_ptr<Ecgi >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_copy(data_collection_model_ecgi_t *ecgi, const data_collection_model_ecgi_t *other)
{
    if (ecgi) {
        std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(ecgi);
        if (obj) {
            if (other) {
                const std::shared_ptr<Ecgi > &other_obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(other);
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
                const std::shared_ptr<Ecgi > &other_obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(other);
                if (other_obj) {
                    obj.reset(new Ecgi(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        ecgi = data_collection_model_ecgi_create_copy(other);
    }
    return ecgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_move(data_collection_model_ecgi_t *ecgi, data_collection_model_ecgi_t *other)
{
    std::shared_ptr<Ecgi > *other_ptr = reinterpret_cast<std::shared_ptr<Ecgi >*>(other);

    if (ecgi) {
        std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(ecgi);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                ecgi = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return ecgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ecgi_free(data_collection_model_ecgi_t *ecgi)
{
    if (!ecgi) return;
    delete reinterpret_cast<std::shared_ptr<Ecgi >*>(ecgi);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ecgi_toJSON(const data_collection_model_ecgi_t *ecgi, bool as_request)
{
    if (!ecgi) return NULL;
    const std::shared_ptr<Ecgi > &obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(ecgi);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_ecgi_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ecgi_t*>(new std::shared_ptr<Ecgi >(new Ecgi(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ecgi_is_equal_to(const data_collection_model_ecgi_t *first, const data_collection_model_ecgi_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<Ecgi > &obj2 = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<Ecgi > &obj1 = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_ecgi_get_plmn_id(const data_collection_model_ecgi_t *obj_ecgi)
{
    if (!obj_ecgi) {
        const data_collection_model_plmn_id_t *result = NULL;
        return result;
    }

    const std::shared_ptr<Ecgi > &obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(obj_ecgi);
    if (!obj) {
        const data_collection_model_plmn_id_t *result = NULL;
        return result;
    }

    typedef typename Ecgi::PlmnIdType ResultFromType;
    const ResultFromType &result_from = obj->getPlmnId();
    const data_collection_model_plmn_id_t *result = reinterpret_cast<const data_collection_model_plmn_id_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_plmn_id(data_collection_model_ecgi_t *obj_ecgi, const data_collection_model_plmn_id_t* p_plmn_id)
{
    if (!obj_ecgi) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    if (!obj) return NULL;

    const auto &value_from = p_plmn_id;
    typedef typename Ecgi::PlmnIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPlmnId(value)) return NULL;

    return obj_ecgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_plmn_id_move(data_collection_model_ecgi_t *obj_ecgi, data_collection_model_plmn_id_t* p_plmn_id)
{
    if (!obj_ecgi) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    if (!obj) return NULL;

    const auto &value_from = p_plmn_id;
    typedef typename Ecgi::PlmnIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPlmnId(std::move(value))) return NULL;
    data_collection_model_plmn_id_free
(p_plmn_id);

    return obj_ecgi;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ecgi_get_eutra_cell_id(const data_collection_model_ecgi_t *obj_ecgi)
{
    if (!obj_ecgi) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<Ecgi > &obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(obj_ecgi);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename Ecgi::EutraCellIdType ResultFromType;
    const ResultFromType &result_from = obj->getEutraCellId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_eutra_cell_id(data_collection_model_ecgi_t *obj_ecgi, const char* p_eutra_cell_id)
{
    if (!obj_ecgi) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    if (!obj) return NULL;

    const auto &value_from = p_eutra_cell_id;
    typedef typename Ecgi::EutraCellIdType ValueType;

    ValueType value(value_from);

    if (!obj->setEutraCellId(value)) return NULL;

    return obj_ecgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_eutra_cell_id_move(data_collection_model_ecgi_t *obj_ecgi, char* p_eutra_cell_id)
{
    if (!obj_ecgi) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    if (!obj) return NULL;

    const auto &value_from = p_eutra_cell_id;
    typedef typename Ecgi::EutraCellIdType ValueType;

    ValueType value(value_from);

    if (!obj->setEutraCellId(std::move(value))) return NULL;
    ogs_free
(p_eutra_cell_id);

    return obj_ecgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ecgi_has_nid(const data_collection_model_ecgi_t *obj_ecgi)
{
    if (!obj_ecgi) return false;

    const std::shared_ptr<Ecgi > &obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(obj_ecgi);
    if (!obj) return false;

    return obj->getNid().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ecgi_get_nid(const data_collection_model_ecgi_t *obj_ecgi)
{
    if (!obj_ecgi) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<Ecgi > &obj = *reinterpret_cast<const std::shared_ptr<Ecgi >*>(obj_ecgi);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename Ecgi::NidType ResultFromType;
    const ResultFromType &result_from = obj->getNid();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_nid(data_collection_model_ecgi_t *obj_ecgi, const char* p_nid)
{
    if (!obj_ecgi) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    if (!obj) return NULL;

    const auto &value_from = p_nid;
    typedef typename Ecgi::NidType ValueType;

    ValueType value(value_from);

    if (!obj->setNid(value)) return NULL;

    return obj_ecgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ecgi_t *data_collection_model_ecgi_set_nid_move(data_collection_model_ecgi_t *obj_ecgi, char* p_nid)
{
    if (!obj_ecgi) return NULL;

    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    if (!obj) return NULL;

    const auto &value_from = p_nid;
    typedef typename Ecgi::NidType ValueType;

    ValueType value(value_from);

    if (!obj->setNid(std::move(value))) return NULL;
    ogs_free
(p_nid);

    return obj_ecgi;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ecgi_make_lnode(data_collection_model_ecgi_t *p_ecgi)
{
    return data_collection_lnode_create(p_ecgi, reinterpret_cast<void(*)(void*)>(data_collection_model_ecgi_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ecgi_refcount(data_collection_model_ecgi_t *obj_ecgi)
{
    if (!obj_ecgi) return 0l;
    std::shared_ptr<Ecgi > &obj = *reinterpret_cast<std::shared_ptr<Ecgi >*>(obj_ecgi);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

