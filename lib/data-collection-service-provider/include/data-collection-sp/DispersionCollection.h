#ifndef _DATA_COLLECTION_DISPERSION_COLLECTION_H_
#define _DATA_COLLECTION_DISPERSION_COLLECTION_H_

/**********************************************************************************************************************************
 * DispersionCollection - Public C interface to the DispersionCollection object
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

#include "IpAddr.h"
#include "UsageThreshold.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DispersionCollection object reference
 */
typedef struct data_collection_model_dispersion_collection_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_dispersion_collection_t;



/** Create a new DispersionCollection.
 * \public \memberof data_collection_model_dispersion_collection_t
 * @return a new DispersionCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_create();

/** Create a new DispersionCollection reference.
 * \public \memberof data_collection_model_dispersion_collection_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The DispersionCollection to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_create_ref(const data_collection_model_dispersion_collection_t *other);

/** Create a new copy of a DispersionCollection object.
 * \public \memberof data_collection_model_dispersion_collection_t
 * Creates a new copy of the given @a other object
 * @param other The DispersionCollection to copy.
 * @return a new DispersionCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_create_copy(const data_collection_model_dispersion_collection_t *other);

/** Create a new reference of a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DispersionCollection to create a new reference to.
 * @return a new DispersionCollection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_create_move(data_collection_model_dispersion_collection_t *other);

/** Copy the value of another DispersionCollection into this object
 * \public \memberof data_collection_model_dispersion_collection_t
 * Copies the value of @a other {{classname} object into @a dispersion_collection.
 * @param dispersion_collection The DispersionCollection object to copy @a other into.
 * @param other The DispersionCollection to copy the value from.
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_copy(data_collection_model_dispersion_collection_t *dispersion_collection, const data_collection_model_dispersion_collection_t *other);

/** Move the value of another DispersionCollection into this object
 * \public \memberof data_collection_model_dispersion_collection_t
 * Discards the current value of @a dispersion_collection and moves the value of @a other
 * into @a dispersion_collection. This will leave @a other as an empty reference.
 *
 * @param dispersion_collection The DispersionCollection object to move @a other into.
 * @param other The DispersionCollection to move the value from.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_move(data_collection_model_dispersion_collection_t *dispersion_collection, data_collection_model_dispersion_collection_t *other);

/** Delete a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 * Destroys the reference to the DispersionCollection object and frees the value of DispersionCollection if this is the last reference.
 *
 * @param dispersion_collection The DispersionCollection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dispersion_collection_free(data_collection_model_dispersion_collection_t *dispersion_collection);

/** Get a cJSON tree representation of a DispersionCollection
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * Create a cJSON tree representation of the DispersionCollection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param dispersion_collection The DispersionCollection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dispersion_collection_toJSON(const data_collection_model_dispersion_collection_t *dispersion_collection, bool as_request);

/** Parse a cJSON tree into a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * Attempts to interpret a cJSON tree as a DispersionCollection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DispersionCollection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DispersionCollection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DispersionCollection objects to see if they are equivalent
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param dispersion_collection The first DispersionCollection object to compare.
 * @param other_dispersion_collection The second DispersionCollection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dispersion_collection_is_equal_to(const data_collection_model_dispersion_collection_t *dispersion_collection, const data_collection_model_dispersion_collection_t *other_dispersion_collection);


/** Check if the gpsi field of a DispersionCollection object is set
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return `true` if the optional gpsi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dispersion_collection_has_gpsi(const data_collection_model_dispersion_collection_t *dispersion_collection);


/** Get the value of the gpsi field of a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return the value current set for the gpsi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_gpsi(const data_collection_model_dispersion_collection_t *dispersion_collection);

/** Set the value of the gpsi field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_gpsi The value to copy into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_gpsi(data_collection_model_dispersion_collection_t *dispersion_collection, const char* p_gpsi);

/** Move a value to the gpsi field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_gpsi The value to move into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_gpsi_move(data_collection_model_dispersion_collection_t *dispersion_collection, char* p_gpsi);

/** Check if the supi field of a DispersionCollection object is set
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return `true` if the optional supi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dispersion_collection_has_supi(const data_collection_model_dispersion_collection_t *dispersion_collection);


/** Get the value of the supi field of a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return the value current set for the supi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_supi(const data_collection_model_dispersion_collection_t *dispersion_collection);

/** Set the value of the supi field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_supi The value to copy into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_supi(data_collection_model_dispersion_collection_t *dispersion_collection, const char* p_supi);

/** Move a value to the supi field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_supi The value to move into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_supi_move(data_collection_model_dispersion_collection_t *dispersion_collection, char* p_supi);

/** Check if the ueAddr field of a DispersionCollection object is set
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return `true` if the optional ueAddr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dispersion_collection_has_ue_addr(const data_collection_model_dispersion_collection_t *dispersion_collection);


/** Get the value of the ueAddr field of a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return the value current set for the ueAddr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_ip_addr_t* data_collection_model_dispersion_collection_get_ue_addr(const data_collection_model_dispersion_collection_t *dispersion_collection);

/** Set the value of the ueAddr field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_ue_addr The value to copy into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_ue_addr(data_collection_model_dispersion_collection_t *dispersion_collection, const data_collection_model_ip_addr_t* p_ue_addr);

/** Move a value to the ueAddr field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_ue_addr The value to move into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_ue_addr_move(data_collection_model_dispersion_collection_t *dispersion_collection, data_collection_model_ip_addr_t* p_ue_addr);

/** Check if the timeStamp field of a DispersionCollection object is set
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return `true` if the optional timeStamp field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dispersion_collection_has_time_stamp(const data_collection_model_dispersion_collection_t *dispersion_collection);


/** Get the value of the timeStamp field of a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return the value current set for the timeStamp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_time_stamp(const data_collection_model_dispersion_collection_t *dispersion_collection);

/** Set the value of the timeStamp field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_time_stamp The value to copy into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_time_stamp(data_collection_model_dispersion_collection_t *dispersion_collection, const char* p_time_stamp);

/** Move a value to the timeStamp field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_time_stamp The value to move into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_time_stamp_move(data_collection_model_dispersion_collection_t *dispersion_collection, char* p_time_stamp);


/** Get the value of the dataUsage field of a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return the value current set for the dataUsage field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_usage_threshold_t* data_collection_model_dispersion_collection_get_data_usage(const data_collection_model_dispersion_collection_t *dispersion_collection);

/** Set the value of the dataUsage field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_data_usage The value to copy into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_data_usage(data_collection_model_dispersion_collection_t *dispersion_collection, const data_collection_model_usage_threshold_t* p_data_usage);

/** Move a value to the dataUsage field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_data_usage The value to move into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_data_usage_move(data_collection_model_dispersion_collection_t *dispersion_collection, data_collection_model_usage_threshold_t* p_data_usage);

/** Check if the flowDesp field of a DispersionCollection object is set
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return `true` if the optional flowDesp field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dispersion_collection_has_flow_desp(const data_collection_model_dispersion_collection_t *dispersion_collection);


/** Get the value of the flowDesp field of a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return the value current set for the flowDesp field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_flow_desp(const data_collection_model_dispersion_collection_t *dispersion_collection);

/** Set the value of the flowDesp field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_flow_desp The value to copy into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_flow_desp(data_collection_model_dispersion_collection_t *dispersion_collection, const char* p_flow_desp);

/** Move a value to the flowDesp field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_flow_desp The value to move into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_flow_desp_move(data_collection_model_dispersion_collection_t *dispersion_collection, char* p_flow_desp);

/** Check if the appId field of a DispersionCollection object is set
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return `true` if the optional appId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dispersion_collection_has_app_id(const data_collection_model_dispersion_collection_t *dispersion_collection);


/** Get the value of the appId field of a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return the value current set for the appId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_app_id(const data_collection_model_dispersion_collection_t *dispersion_collection);

/** Set the value of the appId field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_app_id The value to copy into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_id(data_collection_model_dispersion_collection_t *dispersion_collection, const char* p_app_id);

/** Move a value to the appId field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_app_id The value to move into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_id_move(data_collection_model_dispersion_collection_t *dispersion_collection, char* p_app_id);

/** Check if the dnais field of a DispersionCollection object is set
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return `true` if the optional dnais field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dispersion_collection_has_dnais(const data_collection_model_dispersion_collection_t *dispersion_collection);


/** Get the value of the dnais field of a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return the value current set for the dnais field.
 */
DATA_COLLECTION_SVC_PRODUCER_API ogs_list_t* data_collection_model_dispersion_collection_get_dnais(const data_collection_model_dispersion_collection_t *dispersion_collection);

/** Set the value of the dnais field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_dnais The value to copy into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_dnais(data_collection_model_dispersion_collection_t *dispersion_collection, const ogs_list_t* p_dnais);

/** Move a value to the dnais field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_dnais The value to move into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_dnais_move(data_collection_model_dispersion_collection_t *dispersion_collection, ogs_list_t* p_dnais);

/** Add a new item to the dnais array in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to add the array item to.
 * @param dnais The value to add.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_add_dnais(data_collection_model_dispersion_collection_t *dispersion_collection, char* dnais);

/** Remove an item from the dnais array in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to remove the array value from.
 * @param dnais The value to remove.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_remove_dnais(data_collection_model_dispersion_collection_t *dispersion_collection, const char* dnais);

/** Get an item from the dnais array in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 * @param idx The index of the value to retrieve.
 *
 * @return The value found at the @a idx entry.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dispersion_collection_get_entry_dnais(const data_collection_model_dispersion_collection_t *dispersion_collection, size_t idx);

/** Remove all entries from the dnais array in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to empty dnais for.
 *
 * @return @a dispersion_collection
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_clear_dnais(data_collection_model_dispersion_collection_t *dispersion_collection);

/** Check if the appDur field of a DispersionCollection object is set
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return `true` if the optional appDur field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dispersion_collection_has_app_dur(const data_collection_model_dispersion_collection_t *dispersion_collection);


/** Get the value of the appDur field of a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to examine.
 *
 * @return the value current set for the appDur field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_dispersion_collection_get_app_dur(const data_collection_model_dispersion_collection_t *dispersion_collection);

/** Set the value of the appDur field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_app_dur The value to copy into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_dur(data_collection_model_dispersion_collection_t *dispersion_collection, const int32_t p_app_dur);

/** Move a value to the appDur field in a DispersionCollection object
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * @param dispersion_collection The DispersionCollection object to set the field in.
 * @param p_app_dur The value to move into the DispersionCollection object.
 *
 * @return @a dispersion_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dispersion_collection_t *data_collection_model_dispersion_collection_set_app_dur_move(data_collection_model_dispersion_collection_t *dispersion_collection, int32_t p_app_dur);

/** lnode helper for generating ogs_list_t nodes's of type DispersionCollection
 * \public \memberof data_collection_model_dispersion_collection_t
 *
 * Creates a new data_collection_lnode_t object containing the @a dispersion_collection object.
 * The @a dispersion_collection will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param dispersion_collection The DispersionCollection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a dispersion_collection
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dispersion_collection_make_lnode(data_collection_model_dispersion_collection_t *dispersion_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DISPERSION_COLLECTION_H_ */

