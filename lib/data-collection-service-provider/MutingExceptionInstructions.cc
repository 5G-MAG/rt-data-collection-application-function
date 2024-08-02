/**********************************************************************************************************************************
 * MutingExceptionInstructions - C interface to the MutingExceptionInstructions object
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

/*#include "MutingExceptionInstructions.h" already included by data-collection-sp/data-collection.h */
#include "MutingExceptionInstructions-internal.h"
#include "openapi/model/MutingExceptionInstructions.h"

using namespace reftools::data_collection_sp;

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_create(

)
{
    return reinterpret_cast<data_collection_model_muting_exception_instructions_t*>(new std::shared_ptr<MutingExceptionInstructions>(new MutingExceptionInstructions(

)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_create_copy(const data_collection_model_muting_exception_instructions_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<const std::shared_ptr<MutingExceptionInstructions >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_muting_exception_instructions_t*>(new std::shared_ptr<MutingExceptionInstructions >(new MutingExceptionInstructions(*obj)));
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_create_move(data_collection_model_muting_exception_instructions_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<MutingExceptionInstructions > *obj = reinterpret_cast<std::shared_ptr<MutingExceptionInstructions >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_copy(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, const data_collection_model_muting_exception_instructions_t *other)
{
    if (muting_exception_instructions) {
        std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<std::shared_ptr<MutingExceptionInstructions >*>(muting_exception_instructions);
        if (obj) {
            if (other) {
                const std::shared_ptr<MutingExceptionInstructions > &other_obj = *reinterpret_cast<const std::shared_ptr<MutingExceptionInstructions >*>(other);
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
                const std::shared_ptr<MutingExceptionInstructions > &other_obj = *reinterpret_cast<const std::shared_ptr<MutingExceptionInstructions >*>(other);
                if (other_obj) {
                    obj.reset(new MutingExceptionInstructions(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        muting_exception_instructions = data_collection_model_muting_exception_instructions_create_copy(other);
    }
    return muting_exception_instructions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_move(data_collection_model_muting_exception_instructions_t *muting_exception_instructions, data_collection_model_muting_exception_instructions_t *other)
{
    std::shared_ptr<MutingExceptionInstructions > *other_ptr = reinterpret_cast<std::shared_ptr<MutingExceptionInstructions >*>(other);

    if (muting_exception_instructions) {
        std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<std::shared_ptr<MutingExceptionInstructions >*>(muting_exception_instructions);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                muting_exception_instructions = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return muting_exception_instructions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" void data_collection_model_muting_exception_instructions_free(data_collection_model_muting_exception_instructions_t *muting_exception_instructions)
{
    if (!muting_exception_instructions) return;
    delete reinterpret_cast<std::shared_ptr<MutingExceptionInstructions >*>(muting_exception_instructions);
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" cJSON *data_collection_model_muting_exception_instructions_toJSON(const data_collection_model_muting_exception_instructions_t *muting_exception_instructions, bool as_request)
{
    if (!muting_exception_instructions) return NULL;
    const std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<const std::shared_ptr<MutingExceptionInstructions >*>(muting_exception_instructions);
    if (!obj) return NULL;
    fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
    return json.exportCJSON();
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_muting_exception_instructions_t*>(new std::shared_ptr<MutingExceptionInstructions >(new MutingExceptionInstructions(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" bool data_collection_model_muting_exception_instructions_is_equal_to(const data_collection_model_muting_exception_instructions_t *first, const data_collection_model_muting_exception_instructions_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<MutingExceptionInstructions > &obj2 = *reinterpret_cast<const std::shared_ptr<MutingExceptionInstructions >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<MutingExceptionInstructions > &obj1 = *reinterpret_cast<const std::shared_ptr<MutingExceptionInstructions >*>(first);
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


DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_buffered_notifications_action_t* data_collection_model_muting_exception_instructions_get_buffered_notifs(const data_collection_model_muting_exception_instructions_t *obj_muting_exception_instructions)
{
    if (!obj_muting_exception_instructions) {
        const data_collection_model_buffered_notifications_action_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<const std::shared_ptr<MutingExceptionInstructions >*>(obj_muting_exception_instructions);
    if (!obj) {
        const data_collection_model_buffered_notifications_action_t *result = NULL;
        return result;
    }

    typedef typename MutingExceptionInstructions::BufferedNotifsType ResultFromType;
    const ResultFromType result_from = obj->getBufferedNotifs();
    const data_collection_model_buffered_notifications_action_t *result = reinterpret_cast<const data_collection_model_buffered_notifications_action_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_buffered_notifs(data_collection_model_muting_exception_instructions_t *obj_muting_exception_instructions, const data_collection_model_buffered_notifications_action_t* p_buffered_notifs)
{
    if (!obj_muting_exception_instructions) return NULL;

    std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<std::shared_ptr<MutingExceptionInstructions >*>(obj_muting_exception_instructions);
    if (!obj) return NULL;

    const auto &value_from = p_buffered_notifs;
    typedef typename MutingExceptionInstructions::BufferedNotifsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setBufferedNotifs(value)) return NULL;

    return obj_muting_exception_instructions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_buffered_notifs_move(data_collection_model_muting_exception_instructions_t *obj_muting_exception_instructions, data_collection_model_buffered_notifications_action_t* p_buffered_notifs)
{
    if (!obj_muting_exception_instructions) return NULL;

    std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<std::shared_ptr<MutingExceptionInstructions >*>(obj_muting_exception_instructions);
    if (!obj) return NULL;

    const auto &value_from = p_buffered_notifs;
    typedef typename MutingExceptionInstructions::BufferedNotifsType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setBufferedNotifs(std::move(value))) return NULL;

    return obj_muting_exception_instructions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" const data_collection_model_subscription_action_t* data_collection_model_muting_exception_instructions_get_subscription(const data_collection_model_muting_exception_instructions_t *obj_muting_exception_instructions)
{
    if (!obj_muting_exception_instructions) {
        const data_collection_model_subscription_action_t *result = NULL;
        return result;
    }

    const std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<const std::shared_ptr<MutingExceptionInstructions >*>(obj_muting_exception_instructions);
    if (!obj) {
        const data_collection_model_subscription_action_t *result = NULL;
        return result;
    }

    typedef typename MutingExceptionInstructions::SubscriptionType ResultFromType;
    const ResultFromType result_from = obj->getSubscription();
    const data_collection_model_subscription_action_t *result = reinterpret_cast<const data_collection_model_subscription_action_t*>(&result_from);
    return result;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_subscription(data_collection_model_muting_exception_instructions_t *obj_muting_exception_instructions, const data_collection_model_subscription_action_t* p_subscription)
{
    if (!obj_muting_exception_instructions) return NULL;

    std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<std::shared_ptr<MutingExceptionInstructions >*>(obj_muting_exception_instructions);
    if (!obj) return NULL;

    const auto &value_from = p_subscription;
    typedef typename MutingExceptionInstructions::SubscriptionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    if (!obj->setSubscription(value)) return NULL;

    return obj_muting_exception_instructions;
}

DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_model_muting_exception_instructions_t *data_collection_model_muting_exception_instructions_set_subscription_move(data_collection_model_muting_exception_instructions_t *obj_muting_exception_instructions, data_collection_model_subscription_action_t* p_subscription)
{
    if (!obj_muting_exception_instructions) return NULL;

    std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<std::shared_ptr<MutingExceptionInstructions >*>(obj_muting_exception_instructions);
    if (!obj) return NULL;

    const auto &value_from = p_subscription;
    typedef typename MutingExceptionInstructions::SubscriptionType ValueType;

    ValueType value(*reinterpret_cast<const ValueType*>(value_from));
    
    if (!obj->setSubscription(std::move(value))) return NULL;

    return obj_muting_exception_instructions;
}


DATA_COLLECTION_SVC_PRODUCER_API extern "C" data_collection_lnode_t *data_collection_model_muting_exception_instructions_make_lnode(data_collection_model_muting_exception_instructions_t *p_muting_exception_instructions)
{
    return data_collection_lnode_create(p_muting_exception_instructions, reinterpret_cast<void(*)(void*)>(data_collection_model_muting_exception_instructions_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_muting_exception_instructions_refcount(data_collection_model_muting_exception_instructions_t *obj_muting_exception_instructions)
{
    if (!obj_muting_exception_instructions) return 0l;
    std::shared_ptr<MutingExceptionInstructions > &obj = *reinterpret_cast<std::shared_ptr<MutingExceptionInstructions >*>(obj_muting_exception_instructions);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

