#ifndef _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_FILTER_H_
#define _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_FILTER_H_

/**********************************************************************************************************************************
 * CollectiveBehaviourFilter - Public C interface to the CollectiveBehaviourFilter object
 **********************************************************************************************************************************
 * License: 5G-MAG Public License (v1.0)
 * Authors: David Waring <david.waring2@bbc.co.uk>
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 **********************************************************************************************************************************/

#ifndef INCLUDED_FROM_DATA_COLLECTION_H
#error "This file can only be included from data-collection.h"
#endif

#include "PerUeAttribute.h"
#include "CollectiveBehaviourFilterType.h"
#include "DataProcessingType.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP CollectiveBehaviourFilter object reference
 */
typedef struct data_collection_model_collective_behaviour_filter_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_collective_behaviour_filter_t;



/** Create a new CollectiveBehaviourFilter.
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 * @return a new CollectiveBehaviourFilter object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_create();

/** Create a new CollectiveBehaviourFilter reference.
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The CollectiveBehaviourFilter to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_create_ref(const data_collection_model_collective_behaviour_filter_t *other);

/** Create a new copy of a CollectiveBehaviourFilter object.
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 * Creates a new copy of the given @a other object
 * @param other The CollectiveBehaviourFilter to copy.
 * @return a new CollectiveBehaviourFilter object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_create_copy(const data_collection_model_collective_behaviour_filter_t *other);

/** Create a new reference of a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 * Creates a reference to the same underlying @a other object.
 * @param other The CollectiveBehaviourFilter to create a new reference to.
 * @return a new CollectiveBehaviourFilter object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_create_move(data_collection_model_collective_behaviour_filter_t *other);

/** Copy the value of another CollectiveBehaviourFilter into this object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 * Copies the value of @a other {{classname} object into @a collective_behaviour_filter.
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to copy @a other into.
 * @param other The CollectiveBehaviourFilter to copy the value from.
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_copy(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_collective_behaviour_filter_t *other);

/** Move the value of another CollectiveBehaviourFilter into this object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 * Discards the current value of @a collective_behaviour_filter and moves the value of @a other
 * into @a collective_behaviour_filter. This will leave @a other as an empty reference.
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to move @a other into.
 * @param other The CollectiveBehaviourFilter to move the value from.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, data_collection_model_collective_behaviour_filter_t *other);

/** Delete a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 * Destroys the reference to the CollectiveBehaviourFilter object and frees the value of CollectiveBehaviourFilter if this is the last reference.
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_collective_behaviour_filter_free(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

/** Get a cJSON tree representation of a CollectiveBehaviourFilter
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * Create a cJSON tree representation of the CollectiveBehaviourFilter object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_collective_behaviour_filter_toJSON(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, bool as_request);

/** Parse a cJSON tree into a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * Attempts to interpret a cJSON tree as a CollectiveBehaviourFilter API request or response (dependent on @a as_request value). If successful
 * will return a new referenced CollectiveBehaviourFilter object containing the value represented by the cJSON tree. On failure will return
 * `NULL` and will set @a error_reason, @a error_class and @a error_parameter output parameters to indicate the reason for the
 * failure. The @a error_reason, @a error_class and @a error_parameter strings must be freed using ogs_free().
 *
 * @param json The cJSON tree object to interpret.
 * @param as_request `true` to interpret the @a json as an API request or `false` for interpretation as an API response.
 * @param[out] error_reason On failure will be set to a new nul terminated string indicating the reason for the failure.
 * @param[out] error_class On failure will be set to the class name of the object where the failure happened if available or `NULL`.
 * @param[out] error_parameter On failure will be set to the JSON path of the field where the failure happened if available or
                               `NULL`.
 *
 * @return a new CollectiveBehaviourFilter object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two CollectiveBehaviourFilter objects to see if they are equivalent
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param collective_behaviour_filter The first CollectiveBehaviourFilter object to compare.
 * @param other_collective_behaviour_filter The second CollectiveBehaviourFilter object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_is_equal_to(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_collective_behaviour_filter_t *other_collective_behaviour_filter);



/** Get the value of the type field of a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to examine.
 *
 * @return the value current set for the type field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_collective_behaviour_filter_type_t* data_collection_model_collective_behaviour_filter_get_type(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

/** Set the value of the type field in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to set the field in.
 * @param p_type The value to copy into the CollectiveBehaviourFilter object.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_type(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_collective_behaviour_filter_type_t* p_type);

/** Move a value to the type field in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to set the field in.
 * @param p_type The value to move into the CollectiveBehaviourFilter object.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_type_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, data_collection_model_collective_behaviour_filter_type_t* p_type);


/** Get the value of the value field of a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to examine.
 *
 * @return the value current set for the value field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_collective_behaviour_filter_get_value(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

/** Set the value of the value field in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to set the field in.
 * @param p_value The value to copy into the CollectiveBehaviourFilter object.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_value(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const char* p_value);

/** Move a value to the value field in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to set the field in.
 * @param p_value The value to move into the CollectiveBehaviourFilter object.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_value_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, char* p_value);

/** Check if the collBehAttr field of a CollectiveBehaviourFilter object is set
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to examine.
 *
 * @return `true` if the optional collBehAttr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_has_coll_beh_attr(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);


/** Get the value of the collBehAttr field of a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to examine.
 *
 * @return the value current set for the collBehAttr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_collective_behaviour_filter_get_coll_beh_attr(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

/** Set the value of the collBehAttr field in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to set the field in.
 * @param p_coll_beh_attr The value to copy into the CollectiveBehaviourFilter object.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const ogs_list_t* p_coll_beh_attr);

/** Move a value to the collBehAttr field in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to set the field in.
 * @param p_coll_beh_attr The value to move into the CollectiveBehaviourFilter object.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_coll_beh_attr_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, ogs_list_t* p_coll_beh_attr);

/** Add a new item to the collBehAttr array in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to add the array item to.
 * @param coll_beh_attr The value to add.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_add_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, data_collection_model_per_ue_attribute_t* coll_beh_attr);

/** Remove an item from the collBehAttr array in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to remove the array value from.
 * @param coll_beh_attr The value to remove.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_remove_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_per_ue_attribute_t* coll_beh_attr);

/** Get an item from the collBehAttr array in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_per_ue_attribute_t* data_collection_model_collective_behaviour_filter_get_entry_coll_beh_attr(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, size_t idx);

/** Remove all entries from the collBehAttr array in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to empty collBehAttr for.
 *
 * @return @a collective_behaviour_filter
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_clear_coll_beh_attr(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

/** Check if the dataProcType field of a CollectiveBehaviourFilter object is set
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to examine.
 *
 * @return `true` if the optional dataProcType field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_has_data_proc_type(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);


/** Get the value of the dataProcType field of a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to examine.
 *
 * @return the value current set for the dataProcType field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_data_processing_type_t* data_collection_model_collective_behaviour_filter_get_data_proc_type(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

/** Set the value of the dataProcType field in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to set the field in.
 * @param p_data_proc_type The value to copy into the CollectiveBehaviourFilter object.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_data_proc_type(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const data_collection_model_data_processing_type_t* p_data_proc_type);

/** Move a value to the dataProcType field in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to set the field in.
 * @param p_data_proc_type The value to move into the CollectiveBehaviourFilter object.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_data_proc_type_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, data_collection_model_data_processing_type_t* p_data_proc_type);

/** Check if the listOfUeInd field of a CollectiveBehaviourFilter object is set
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to examine.
 *
 * @return `true` if the optional listOfUeInd field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_collective_behaviour_filter_has_list_of_ue_ind(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);


/** Get the value of the listOfUeInd field of a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to examine.
 *
 * @return the value current set for the listOfUeInd field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const bool data_collection_model_collective_behaviour_filter_is_list_of_ue_ind(const data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

/** Set the value of the listOfUeInd field in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to set the field in.
 * @param p_list_of_ue_ind The value to copy into the CollectiveBehaviourFilter object.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_list_of_ue_ind(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, const bool p_list_of_ue_ind);

/** Move a value to the listOfUeInd field in a CollectiveBehaviourFilter object
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to set the field in.
 * @param p_list_of_ue_ind The value to move into the CollectiveBehaviourFilter object.
 *
 * @return @a collective_behaviour_filter.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_collective_behaviour_filter_t *data_collection_model_collective_behaviour_filter_set_list_of_ue_ind_move(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter, bool p_list_of_ue_ind);

/** lnode helper for generating ogs_list_t nodes's of type CollectiveBehaviourFilter
 * \public \memberof data_collection_model_collective_behaviour_filter_t
 *
 * Creates a new data_collection_lnode_t object containing the @a collective_behaviour_filter object.
 * The @a collective_behaviour_filter will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param collective_behaviour_filter The CollectiveBehaviourFilter object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a collective_behaviour_filter
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_collective_behaviour_filter_make_lnode(data_collection_model_collective_behaviour_filter_t *collective_behaviour_filter);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_COLLECTIVE_BEHAVIOUR_FILTER_H_ */

