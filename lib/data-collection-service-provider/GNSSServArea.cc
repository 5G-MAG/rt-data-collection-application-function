/**********************************************************************************************************************************
 * GNSSServArea - C interface to the GNSSServArea object
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

/*#include "GNSSServArea.h" already included by data-collection-sp/data-collection.h */
#include "GNSSServArea-internal.h"
#include "openapi/model/GNSSServArea.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_create(

)
{
    return reinterpret_cast<data_collection_model_gnss_serv_area_t*>(new std::shared_ptr<GNSSServArea>(new GNSSServArea(

)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_create_copy(const data_collection_model_gnss_serv_area_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_gnss_serv_area_t*>(new std::shared_ptr<GNSSServArea >(new GNSSServArea(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_create_move(data_collection_model_gnss_serv_area_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<GNSSServArea > *obj = reinterpret_cast<std::shared_ptr<GNSSServArea >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_copy(data_collection_model_gnss_serv_area_t *gnss_serv_area, const data_collection_model_gnss_serv_area_t *other)
{
    if (gnss_serv_area) {
        std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<std::shared_ptr<GNSSServArea >*>(gnss_serv_area);
        if (obj) {
            if (other) {
                const std::shared_ptr<GNSSServArea > &other_obj = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(other);
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
                const std::shared_ptr<GNSSServArea > &other_obj = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(other);
                if (other_obj) {
                    obj.reset(new GNSSServArea(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        gnss_serv_area = data_collection_model_gnss_serv_area_create_copy(other);
    }
    return gnss_serv_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_move(data_collection_model_gnss_serv_area_t *gnss_serv_area, data_collection_model_gnss_serv_area_t *other)
{
    std::shared_ptr<GNSSServArea > *other_ptr = reinterpret_cast<std::shared_ptr<GNSSServArea >*>(other);

    if (gnss_serv_area) {
        std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<std::shared_ptr<GNSSServArea >*>(gnss_serv_area);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                gnss_serv_area = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return gnss_serv_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_gnss_serv_area_free(data_collection_model_gnss_serv_area_t *gnss_serv_area)
{
    if (!gnss_serv_area) return;
    delete reinterpret_cast<std::shared_ptr<GNSSServArea >*>(gnss_serv_area);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_gnss_serv_area_toJSON(const data_collection_model_gnss_serv_area_t *gnss_serv_area, bool as_request)
{
    if (!gnss_serv_area) return NULL;
    const std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(gnss_serv_area);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_gnss_serv_area_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_gnss_serv_area_t*>(new std::shared_ptr<GNSSServArea >(new GNSSServArea(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_serv_area_is_equal_to(const data_collection_model_gnss_serv_area_t *first, const data_collection_model_gnss_serv_area_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<GNSSServArea > &obj2 = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<GNSSServArea > &obj1 = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_serv_area_has_geographical_area(const data_collection_model_gnss_serv_area_t *obj_gnss_serv_area)
{
    if (!obj_gnss_serv_area) return false;

    const std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) return false;

    return obj->getGeographicalArea().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_geographic_area_t* data_collection_model_gnss_serv_area_get_geographical_area(const data_collection_model_gnss_serv_area_t *obj_gnss_serv_area)
{
    if (!obj_gnss_serv_area) {
        const data_collection_model_geographic_area_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) {
        const data_collection_model_geographic_area_t *result = NULL;
        return result;
    }

    typedef typename GNSSServArea::GeographicalAreaType ResultFromType;
    const ResultFromType &result_from = obj->getGeographicalArea();
    const data_collection_model_geographic_area_t *result = reinterpret_cast<const data_collection_model_geographic_area_t*>(result_from.has_value()?&result_from.value():nullptr);
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_geographical_area(data_collection_model_gnss_serv_area_t *obj_gnss_serv_area, const data_collection_model_geographic_area_t* p_geographical_area)
{
    if (!obj_gnss_serv_area) return NULL;

    std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) return NULL;

    const auto &value_from = p_geographical_area;
    typedef typename GNSSServArea::GeographicalAreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setGeographicalArea(value)) return NULL;

    return obj_gnss_serv_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_geographical_area_move(data_collection_model_gnss_serv_area_t *obj_gnss_serv_area, data_collection_model_geographic_area_t* p_geographical_area)
{
    if (!obj_gnss_serv_area) return NULL;

    std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) return NULL;

    const auto &value_from = p_geographical_area;
    typedef typename GNSSServArea::GeographicalAreaType ValueType;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    if (!obj->setGeographicalArea(std::move(value))) return NULL;
    data_collection_model_geographic_area_free
(p_geographical_area);

    return obj_gnss_serv_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_gnss_serv_area_has_tai_list(const data_collection_model_gnss_serv_area_t *obj_gnss_serv_area)
{
    if (!obj_gnss_serv_area) return false;

    const std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) return false;

    return obj->getTaiList().has_value();
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_gnss_serv_area_get_tai_list(const data_collection_model_gnss_serv_area_t *obj_gnss_serv_area)
{
    if (!obj_gnss_serv_area) {
        ogs_list_t *result = NULL;
        return result;
    }

    const std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) {
        ogs_list_t *result = NULL;
        return result;
    }

    typedef typename GNSSServArea::TaiListType ResultFromType;
    const ResultFromType &result_from = obj->getTaiList();
    ogs_list_t *result = reinterpret_cast<ogs_list_t*>(result_from.has_value()?ogs_calloc(1, sizeof(*result)):nullptr);
    if (result_from.has_value()) {

    typedef typename ResultFromType::value_type::value_type ItemType;
    for (const ItemType &item : result_from.value()) {
        data_collection_lnode_t *node = nullptr;
        data_collection_model_tai_t *item_obj = reinterpret_cast<data_collection_model_tai_t*>(item.has_value()?new std::shared_ptr<Tai >(item.value()):nullptr);
        if (item_obj) {
    	node = data_collection_model_tai_make_lnode(item_obj);
        }
        
        if (node) ogs_list_add(result, node);
    }}
    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_tai_list(data_collection_model_gnss_serv_area_t *obj_gnss_serv_area, const ogs_list_t* p_tai_list)
{
    if (!obj_gnss_serv_area) return NULL;

    std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) return NULL;

    const auto &value_from = p_tai_list;
    typedef typename GNSSServArea::TaiListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setTaiList(value)) return NULL;

    return obj_gnss_serv_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_set_tai_list_move(data_collection_model_gnss_serv_area_t *obj_gnss_serv_area, ogs_list_t* p_tai_list)
{
    if (!obj_gnss_serv_area) return NULL;

    std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) return NULL;

    const auto &value_from = p_tai_list;
    typedef typename GNSSServArea::TaiListType ValueType;

    ValueType value;
    if (value_from) {
        data_collection_lnode_t *lnode;
        typedef typename ValueType::value_type::value_type ItemType;
        value = std::move(typename ValueType::value_type());
        auto &container(value.value());
        ogs_list_for_each(value_from, lnode) {
    	container.push_back(ItemType(std::move(*reinterpret_cast<const ItemType::value_type*>(lnode->object))));
    	
        }
    }

    if (!obj->setTaiList(std::move(value))) return NULL;
    data_collection_list_free
(p_tai_list);

    return obj_gnss_serv_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_add_tai_list(data_collection_model_gnss_serv_area_t *obj_gnss_serv_area, data_collection_model_tai_t* p_tai_list)
{
    if (!obj_gnss_serv_area) return NULL;

    std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) return NULL;

    typedef typename GNSSServArea::TaiListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    const auto &value_from = p_tai_list;

    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    data_collection_model_tai_free
(p_tai_list);
    if (value) obj->addTaiList(value.value());
    return obj_gnss_serv_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_remove_tai_list(data_collection_model_gnss_serv_area_t *obj_gnss_serv_area, const data_collection_model_tai_t* p_tai_list)
{
    if (!obj_gnss_serv_area) return NULL;

    std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) return NULL;

    typedef typename GNSSServArea::TaiListType::value_type ContainerType;
    typedef typename ContainerType::value_type ValueType;
    auto &value_from = p_tai_list;
    ValueType value(*reinterpret_cast<const ValueType::value_type*>(value_from));

    obj->removeTaiList(value);
    return obj_gnss_serv_area;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_tai_t* data_collection_model_gnss_serv_area_get_entry_tai_list(const data_collection_model_gnss_serv_area_t *obj_gnss_serv_area, size_t idx)
{
    if (!obj_gnss_serv_area) {
        const data_collection_model_tai_t *result = NULL;

        return result;
    }

    const std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<const std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) {
        const data_collection_model_tai_t *result = NULL;

        return result;
    }

    const GNSSServArea::TaiListType &container = obj->getTaiList();
    if (!container.has_value()) {
        const data_collection_model_tai_t *result = NULL;

        return result;
    }

    auto itr = container.value().cbegin();
    while (idx > 0 && itr != container.value().cend()) {
        ++itr;
        --idx;
    }
    if (itr == container.value().cend()) {
        const data_collection_model_tai_t *result = NULL;

        return result;
    }
    typedef typename GNSSServArea::TaiListItemType ResultFromType;
    const ResultFromType &result_from = *itr;
    const data_collection_model_tai_t *result = reinterpret_cast<const data_collection_model_tai_t*>(result_from.has_value()?&result_from.value():nullptr);

    return result;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_gnss_serv_area_t *data_collection_model_gnss_serv_area_clear_tai_list(data_collection_model_gnss_serv_area_t *obj_gnss_serv_area)
{
    if (!obj_gnss_serv_area) return NULL;

    std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    if (!obj) return NULL;

    obj->clearTaiList();
    return obj_gnss_serv_area;
}


extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_gnss_serv_area_make_lnode(data_collection_model_gnss_serv_area_t *p_gnss_serv_area)
{
    return data_collection_lnode_create(p_gnss_serv_area, reinterpret_cast<void(*)(void*)>(data_collection_model_gnss_serv_area_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_gnss_serv_area_refcount(data_collection_model_gnss_serv_area_t *obj_gnss_serv_area)
{
    if (!obj_gnss_serv_area) return 0l;
    std::shared_ptr<GNSSServArea > &obj = *reinterpret_cast<std::shared_ptr<GNSSServArea >*>(obj_gnss_serv_area);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

