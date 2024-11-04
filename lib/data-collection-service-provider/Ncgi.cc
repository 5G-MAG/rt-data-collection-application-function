/**********************************************************************************************************************************
 * Ncgi - C interface to the Ncgi object
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

/*#include "Ncgi.h" already included by data-collection-sp/data-collection.h */
#include "Ncgi-internal.h"
#include "openapi/model/Ncgi.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_create(


)
{
    return reinterpret_cast<data_collection_model_ncgi_t*>(new std::shared_ptr<Ncgi>(new Ncgi(


)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_create_copy(const data_collection_model_ncgi_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<Ncgi > &obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_ncgi_t*>(new std::shared_ptr<Ncgi >(new Ncgi(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_create_move(data_collection_model_ncgi_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<Ncgi > *obj = reinterpret_cast<std::shared_ptr<Ncgi >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_copy(data_collection_model_ncgi_t *ncgi, const data_collection_model_ncgi_t *other)
{
    if (ncgi) {
        std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(ncgi);
        if (obj) {
            if (other) {
                const std::shared_ptr<Ncgi > &other_obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(other);
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
                const std::shared_ptr<Ncgi > &other_obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(other);
                if (other_obj) {
                    obj.reset(new Ncgi(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        ncgi = data_collection_model_ncgi_create_copy(other);
    }
    return ncgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_move(data_collection_model_ncgi_t *ncgi, data_collection_model_ncgi_t *other)
{
    std::shared_ptr<Ncgi > *other_ptr = reinterpret_cast<std::shared_ptr<Ncgi >*>(other);

    if (ncgi) {
        std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(ncgi);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                ncgi = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return ncgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ncgi_free(data_collection_model_ncgi_t *ncgi)
{
    if (!ncgi) return;
    delete reinterpret_cast<std::shared_ptr<Ncgi >*>(ncgi);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ncgi_toJSON(const data_collection_model_ncgi_t *ncgi, bool as_request)
{
    if (!ncgi) return NULL;
    const std::shared_ptr<Ncgi > &obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(ncgi);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_ncgi_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_ncgi_t*>(new std::shared_ptr<Ncgi >(new Ncgi(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ncgi_is_equal_to(const data_collection_model_ncgi_t *first, const data_collection_model_ncgi_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<Ncgi > &obj2 = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<Ncgi > &obj1 = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(first);
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



extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_plmn_id_t* data_collection_model_ncgi_get_plmn_id(const data_collection_model_ncgi_t *obj_ncgi)
{
    if (!obj_ncgi) {
        const data_collection_model_plmn_id_t *result = NULL;
        return result;
    }

    const std::shared_ptr<Ncgi > &obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(obj_ncgi);
    if (!obj) {
        const data_collection_model_plmn_id_t *result = NULL;
        return result;
    }

    typedef typename Ncgi::PlmnIdType ResultFromType;
    const ResultFromType &result_from = obj->getPlmnId();
    const data_collection_model_plmn_id_t *result = reinterpret_cast<const data_collection_model_plmn_id_t*>(&result_from);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_set_plmn_id(data_collection_model_ncgi_t *obj_ncgi, const data_collection_model_plmn_id_t* p_plmn_id)
{
    if (!obj_ncgi) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    if (!obj) return NULL;

    const auto &value_from = p_plmn_id;
    typedef typename Ncgi::PlmnIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPlmnId(value)) return NULL;

    return obj_ncgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_set_plmn_id_move(data_collection_model_ncgi_t *obj_ncgi, data_collection_model_plmn_id_t* p_plmn_id)
{
    if (!obj_ncgi) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    if (!obj) return NULL;

    const auto &value_from = p_plmn_id;
    typedef typename Ncgi::PlmnIdType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));

    if (!obj->setPlmnId(std::move(value))) return NULL;
    data_collection_model_plmn_id_free
(p_plmn_id);

    return obj_ncgi;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ncgi_get_nr_cell_id(const data_collection_model_ncgi_t *obj_ncgi)
{
    if (!obj_ncgi) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<Ncgi > &obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(obj_ncgi);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename Ncgi::NrCellIdType ResultFromType;
    const ResultFromType &result_from = obj->getNrCellId();
    const char *result = result_from.c_str();
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_set_nr_cell_id(data_collection_model_ncgi_t *obj_ncgi, const char* p_nr_cell_id)
{
    if (!obj_ncgi) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    if (!obj) return NULL;

    const auto &value_from = p_nr_cell_id;
    typedef typename Ncgi::NrCellIdType ValueType;

    ValueType value(value_from);

    if (!obj->setNrCellId(value)) return NULL;

    return obj_ncgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_set_nr_cell_id_move(data_collection_model_ncgi_t *obj_ncgi, char* p_nr_cell_id)
{
    if (!obj_ncgi) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    if (!obj) return NULL;

    const auto &value_from = p_nr_cell_id;
    typedef typename Ncgi::NrCellIdType ValueType;

    ValueType value(value_from);

    if (!obj->setNrCellId(std::move(value))) return NULL;
    ogs_free
(p_nr_cell_id);

    return obj_ncgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ncgi_has_nid(const data_collection_model_ncgi_t *obj_ncgi)
{
    if (!obj_ncgi) return false;

    const std::shared_ptr<Ncgi > &obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(obj_ncgi);
    if (!obj) return false;

    return obj->getNid().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ncgi_get_nid(const data_collection_model_ncgi_t *obj_ncgi)
{
    if (!obj_ncgi) {
        const char *result = NULL;
        return result;
    }

    const std::shared_ptr<Ncgi > &obj = *reinterpret_cast<const std::shared_ptr<Ncgi >*>(obj_ncgi);
    if (!obj) {
        const char *result = NULL;
        return result;
    }

    typedef typename Ncgi::NidType ResultFromType;
    const ResultFromType &result_from = obj->getNid();
    const char *result = result_from.has_value()?result_from.value().c_str():nullptr;
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_set_nid(data_collection_model_ncgi_t *obj_ncgi, const char* p_nid)
{
    if (!obj_ncgi) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    if (!obj) return NULL;

    const auto &value_from = p_nid;
    typedef typename Ncgi::NidType ValueType;

    ValueType value(value_from);

    if (!obj->setNid(value)) return NULL;

    return obj_ncgi;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ncgi_t *data_collection_model_ncgi_set_nid_move(data_collection_model_ncgi_t *obj_ncgi, char* p_nid)
{
    if (!obj_ncgi) return NULL;

    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    if (!obj) return NULL;

    const auto &value_from = p_nid;
    typedef typename Ncgi::NidType ValueType;

    ValueType value(value_from);

    if (!obj->setNid(std::move(value))) return NULL;
    ogs_free
(p_nid);

    return obj_ncgi;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ncgi_make_lnode(data_collection_model_ncgi_t *p_ncgi)
{
    return data_collection_lnode_create(p_ncgi, reinterpret_cast<void(*)(void*)>(data_collection_model_ncgi_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_ncgi_refcount(data_collection_model_ncgi_t *obj_ncgi)
{
    if (!obj_ncgi) return 0l;
    std::shared_ptr<Ncgi > &obj = *reinterpret_cast<std::shared_ptr<Ncgi >*>(obj_ncgi);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

