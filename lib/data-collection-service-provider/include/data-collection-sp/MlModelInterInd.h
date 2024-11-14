#ifndef _DATA_COLLECTION_ML_MODEL_INTER_IND_H_
#define _DATA_COLLECTION_ML_MODEL_INTER_IND_H_

/**********************************************************************************************************************************
 * MlModelInterInd - Public C interface to the MlModelInterInd object
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

#include "NwdafEvent.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP MlModelInterInd object reference
 */
typedef struct data_collection_model_ml_model_inter_ind_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_ml_model_inter_ind_t;



/** Create a new MlModelInterInd.
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 * @return a new MlModelInterInd object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_create();

/** Create a new MlModelInterInd reference.
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The MlModelInterInd to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_create_ref(const data_collection_model_ml_model_inter_ind_t *other);

/** Create a new copy of a MlModelInterInd object.
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 * Creates a new copy of the given @a other object
 * @param other The MlModelInterInd to copy.
 * @return a new MlModelInterInd object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_create_copy(const data_collection_model_ml_model_inter_ind_t *other);

/** Create a new reference of a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 * Creates a reference to the same underlying @a other object.
 * @param other The MlModelInterInd to create a new reference to.
 * @return a new MlModelInterInd object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_create_move(data_collection_model_ml_model_inter_ind_t *other);

/** Copy the value of another MlModelInterInd into this object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 * Copies the value of @a other {{classname} object into @a ml_model_inter_ind.
 * @param ml_model_inter_ind The MlModelInterInd object to copy @a other into.
 * @param other The MlModelInterInd to copy the value from.
 * @return @a ml_model_inter_ind.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_copy(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const data_collection_model_ml_model_inter_ind_t *other);

/** Move the value of another MlModelInterInd into this object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 * Discards the current value of @a ml_model_inter_ind and moves the value of @a other
 * into @a ml_model_inter_ind. This will leave @a other as an empty reference.
 *
 * @param ml_model_inter_ind The MlModelInterInd object to move @a other into.
 * @param other The MlModelInterInd to move the value from.
 *
 * @return @a ml_model_inter_ind.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_move(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, data_collection_model_ml_model_inter_ind_t *other);

/** Delete a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 * Destroys the reference to the MlModelInterInd object and frees the value of MlModelInterInd if this is the last reference.
 *
 * @param ml_model_inter_ind The MlModelInterInd to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_ml_model_inter_ind_free(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind);

/** Get a cJSON tree representation of a MlModelInterInd
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * Create a cJSON tree representation of the MlModelInterInd object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param ml_model_inter_ind The MlModelInterInd to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_ml_model_inter_ind_toJSON(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, bool as_request);

/** Parse a cJSON tree into a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * Attempts to interpret a cJSON tree as a MlModelInterInd API request or response (dependent on @a as_request value). If successful
 * will return a new referenced MlModelInterInd object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new MlModelInterInd object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two MlModelInterInd objects to see if they are equivalent
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param ml_model_inter_ind The first MlModelInterInd object to compare.
 * @param other_ml_model_inter_ind The second MlModelInterInd object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_ml_model_inter_ind_is_equal_to(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const data_collection_model_ml_model_inter_ind_t *other_ml_model_inter_ind);



/** Get the value of the analyticsId field of a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * @param ml_model_inter_ind The MlModelInterInd object to examine.
 *
 * @return the value current set for the analyticsId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_nwdaf_event_t* data_collection_model_ml_model_inter_ind_get_analytics_id(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind);

/** Set the value of the analyticsId field in a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * @param ml_model_inter_ind The MlModelInterInd object to set the field in.
 * @param p_analytics_id The value to copy into the MlModelInterInd object.
 *
 * @return @a ml_model_inter_ind.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_analytics_id(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const data_collection_model_nwdaf_event_t* p_analytics_id);

/** Move a value to the analyticsId field in a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * @param ml_model_inter_ind The MlModelInterInd object to set the field in.
 * @param p_analytics_id The value to move into the MlModelInterInd object.
 *
 * @return @a ml_model_inter_ind.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_analytics_id_move(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, data_collection_model_nwdaf_event_t* p_analytics_id);


/** Get the value of the vendorList field of a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * @param ml_model_inter_ind The MlModelInterInd object to examine.
 *
 * @return the value current set for the vendorList field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_ml_model_inter_ind_get_vendor_list(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind);

/** Set the value of the vendorList field in a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * @param ml_model_inter_ind The MlModelInterInd object to set the field in.
 * @param p_vendor_list The value to copy into the MlModelInterInd object.
 *
 * @return @a ml_model_inter_ind.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_vendor_list(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const ogs_list_t* p_vendor_list);

/** Move a value to the vendorList field in a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * @param ml_model_inter_ind The MlModelInterInd object to set the field in.
 * @param p_vendor_list The value to move into the MlModelInterInd object.
 *
 * @return @a ml_model_inter_ind.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_set_vendor_list_move(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, ogs_list_t* p_vendor_list);

/** Add a new item to the vendorList array in a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * @param ml_model_inter_ind The MlModelInterInd object to add the array item to.
 * @param vendor_list The value to add.
 *
 * @return @a ml_model_inter_ind.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_add_vendor_list(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, char* vendor_list);

/** Remove an item from the vendorList array in a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * @param ml_model_inter_ind The MlModelInterInd object to remove the array value from.
 * @param vendor_list The value to remove.
 *
 * @return @a ml_model_inter_ind.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_remove_vendor_list(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, const char* vendor_list);

/** Get an item from the vendorList array in a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * @param ml_model_inter_ind The MlModelInterInd object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_ml_model_inter_ind_get_entry_vendor_list(const data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind, size_t idx);

/** Remove all entries from the vendorList array in a MlModelInterInd object
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * @param ml_model_inter_ind The MlModelInterInd object to empty vendorList for.
 *
 * @return @a ml_model_inter_ind
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_ml_model_inter_ind_t *data_collection_model_ml_model_inter_ind_clear_vendor_list(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind);

/** lnode helper for generating ogs_list_t nodes's of type MlModelInterInd
 * \public \memberof data_collection_model_ml_model_inter_ind_t
 *
 * Creates a new data_collection_lnode_t object containing the @a ml_model_inter_ind object.
 * The @a ml_model_inter_ind will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param ml_model_inter_ind The MlModelInterInd object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a ml_model_inter_ind
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_ml_model_inter_ind_make_lnode(data_collection_model_ml_model_inter_ind_t *ml_model_inter_ind);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_ML_MODEL_INTER_IND_H_ */

