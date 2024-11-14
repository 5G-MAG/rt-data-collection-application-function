#ifndef _DATA_COLLECTION_PERFORMANCE_DATA_H_
#define _DATA_COLLECTION_PERFORMANCE_DATA_H_

/**********************************************************************************************************************************
 * PerformanceData - Public C interface to the PerformanceData object
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


/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP PerformanceData object reference
 */
typedef struct data_collection_model_performance_data_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_performance_data_t;



/** Create a new PerformanceData.
 * \public \memberof data_collection_model_performance_data_t
 * @return a new PerformanceData object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_create();

/** Create a new PerformanceData reference.
 * \public \memberof data_collection_model_performance_data_t
 * Creates a new reference to the same underlying object as \a other.
 * @param other The PerformanceData to create a new reference to.
 * @return a new reference to the underlying object of \a other.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_create_ref(const data_collection_model_performance_data_t *other);

/** Create a new copy of a PerformanceData object.
 * \public \memberof data_collection_model_performance_data_t
 * Creates a new copy of the given @a other object
 * @param other The PerformanceData to copy.
 * @return a new PerformanceData object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_create_copy(const data_collection_model_performance_data_t *other);

/** Create a new reference of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 * Creates a reference to the same underlying @a other object.
 * @param other The PerformanceData to create a new reference to.
 * @return a new PerformanceData object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_create_move(data_collection_model_performance_data_t *other);

/** Copy the value of another PerformanceData into this object
 * \public \memberof data_collection_model_performance_data_t
 * Copies the value of @a other {{classname} object into @a performance_data.
 * @param performance_data The PerformanceData object to copy @a other into.
 * @param other The PerformanceData to copy the value from.
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_copy(data_collection_model_performance_data_t *performance_data, const data_collection_model_performance_data_t *other);

/** Move the value of another PerformanceData into this object
 * \public \memberof data_collection_model_performance_data_t
 * Discards the current value of @a performance_data and moves the value of @a other
 * into @a performance_data. This will leave @a other as an empty reference.
 *
 * @param performance_data The PerformanceData object to move @a other into.
 * @param other The PerformanceData to move the value from.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_move(data_collection_model_performance_data_t *performance_data, data_collection_model_performance_data_t *other);

/** Delete a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 * Destroys the reference to the PerformanceData object and frees the value of PerformanceData if this is the last reference.
 *
 * @param performance_data The PerformanceData to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_performance_data_free(data_collection_model_performance_data_t *performance_data);

/** Get a cJSON tree representation of a PerformanceData
 * \public \memberof data_collection_model_performance_data_t
 *
 * Create a cJSON tree representation of the PerformanceData object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param performance_data The PerformanceData to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_performance_data_toJSON(const data_collection_model_performance_data_t *performance_data, bool as_request);

/** Parse a cJSON tree into a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * Attempts to interpret a cJSON tree as a PerformanceData API request or response (dependent on @a as_request value). If successful
 * will return a new referenced PerformanceData object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new PerformanceData object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two PerformanceData objects to see if they are equivalent
 * \public \memberof data_collection_model_performance_data_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param performance_data The first PerformanceData object to compare.
 * @param other_performance_data The second PerformanceData object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_is_equal_to(const data_collection_model_performance_data_t *performance_data, const data_collection_model_performance_data_t *other_performance_data);


/** Check if the pdb field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional pdb field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_pdb(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the pdb field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the pdb field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_pdb(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the pdb field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_pdb The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb(data_collection_model_performance_data_t *performance_data, const int32_t p_pdb);

/** Move a value to the pdb field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_pdb The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb_move(data_collection_model_performance_data_t *performance_data, int32_t p_pdb);

/** Check if the pdbDl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional pdbDl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_pdb_dl(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the pdbDl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the pdbDl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_pdb_dl(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the pdbDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_pdb_dl The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb_dl(data_collection_model_performance_data_t *performance_data, const int32_t p_pdb_dl);

/** Move a value to the pdbDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_pdb_dl The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_pdb_dl_move(data_collection_model_performance_data_t *performance_data, int32_t p_pdb_dl);

/** Check if the maxPdbUl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional maxPdbUl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_pdb_ul(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the maxPdbUl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the maxPdbUl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_pdb_ul(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the maxPdbUl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_pdb_ul The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_ul(data_collection_model_performance_data_t *performance_data, const int32_t p_max_pdb_ul);

/** Move a value to the maxPdbUl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_pdb_ul The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_ul_move(data_collection_model_performance_data_t *performance_data, int32_t p_max_pdb_ul);

/** Check if the maxPdbDl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional maxPdbDl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_pdb_dl(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the maxPdbDl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the maxPdbDl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_pdb_dl(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the maxPdbDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_pdb_dl The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_dl(data_collection_model_performance_data_t *performance_data, const int32_t p_max_pdb_dl);

/** Move a value to the maxPdbDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_pdb_dl The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_pdb_dl_move(data_collection_model_performance_data_t *performance_data, int32_t p_max_pdb_dl);

/** Check if the plr field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional plr field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_plr(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the plr field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the plr field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_plr(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the plr field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_plr The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr(data_collection_model_performance_data_t *performance_data, const int32_t p_plr);

/** Move a value to the plr field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_plr The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr_move(data_collection_model_performance_data_t *performance_data, int32_t p_plr);

/** Check if the plrDl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional plrDl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_plr_dl(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the plrDl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the plrDl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_plr_dl(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the plrDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_plr_dl The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr_dl(data_collection_model_performance_data_t *performance_data, const int32_t p_plr_dl);

/** Move a value to the plrDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_plr_dl The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_plr_dl_move(data_collection_model_performance_data_t *performance_data, int32_t p_plr_dl);

/** Check if the maxPlrUl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional maxPlrUl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_plr_ul(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the maxPlrUl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the maxPlrUl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_plr_ul(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the maxPlrUl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_plr_ul The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_ul(data_collection_model_performance_data_t *performance_data, const int32_t p_max_plr_ul);

/** Move a value to the maxPlrUl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_plr_ul The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_ul_move(data_collection_model_performance_data_t *performance_data, int32_t p_max_plr_ul);

/** Check if the maxPlrDl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional maxPlrDl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_plr_dl(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the maxPlrDl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the maxPlrDl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int32_t data_collection_model_performance_data_get_max_plr_dl(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the maxPlrDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_plr_dl The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_dl(data_collection_model_performance_data_t *performance_data, const int32_t p_max_plr_dl);

/** Move a value to the maxPlrDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_plr_dl The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_plr_dl_move(data_collection_model_performance_data_t *performance_data, int32_t p_max_plr_dl);

/** Check if the thrputUl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional thrputUl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_thrput_ul(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the thrputUl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the thrputUl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_thrput_ul(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the thrputUl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_thrput_ul The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_ul(data_collection_model_performance_data_t *performance_data, const char* p_thrput_ul);

/** Move a value to the thrputUl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_thrput_ul The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_ul_move(data_collection_model_performance_data_t *performance_data, char* p_thrput_ul);

/** Check if the maxThrputUl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional maxThrputUl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_thrput_ul(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the maxThrputUl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the maxThrputUl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_max_thrput_ul(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the maxThrputUl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_thrput_ul The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_ul(data_collection_model_performance_data_t *performance_data, const char* p_max_thrput_ul);

/** Move a value to the maxThrputUl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_thrput_ul The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_ul_move(data_collection_model_performance_data_t *performance_data, char* p_max_thrput_ul);

/** Check if the minThrputUl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional minThrputUl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_min_thrput_ul(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the minThrputUl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the minThrputUl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_min_thrput_ul(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the minThrputUl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_min_thrput_ul The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_ul(data_collection_model_performance_data_t *performance_data, const char* p_min_thrput_ul);

/** Move a value to the minThrputUl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_min_thrput_ul The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_ul_move(data_collection_model_performance_data_t *performance_data, char* p_min_thrput_ul);

/** Check if the thrputDl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional thrputDl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_thrput_dl(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the thrputDl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the thrputDl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_thrput_dl(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the thrputDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_thrput_dl The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_dl(data_collection_model_performance_data_t *performance_data, const char* p_thrput_dl);

/** Move a value to the thrputDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_thrput_dl The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_thrput_dl_move(data_collection_model_performance_data_t *performance_data, char* p_thrput_dl);

/** Check if the maxThrputDl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional maxThrputDl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_max_thrput_dl(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the maxThrputDl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the maxThrputDl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_max_thrput_dl(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the maxThrputDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_thrput_dl The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_dl(data_collection_model_performance_data_t *performance_data, const char* p_max_thrput_dl);

/** Move a value to the maxThrputDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_max_thrput_dl The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_max_thrput_dl_move(data_collection_model_performance_data_t *performance_data, char* p_max_thrput_dl);

/** Check if the minThrputDl field of a PerformanceData object is set
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return `true` if the optional minThrputDl field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_performance_data_has_min_thrput_dl(const data_collection_model_performance_data_t *performance_data);


/** Get the value of the minThrputDl field of a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to examine.
 *
 * @return the value current set for the minThrputDl field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_performance_data_get_min_thrput_dl(const data_collection_model_performance_data_t *performance_data);

/** Set the value of the minThrputDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_min_thrput_dl The value to copy into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_dl(data_collection_model_performance_data_t *performance_data, const char* p_min_thrput_dl);

/** Move a value to the minThrputDl field in a PerformanceData object
 * \public \memberof data_collection_model_performance_data_t
 *
 * @param performance_data The PerformanceData object to set the field in.
 * @param p_min_thrput_dl The value to move into the PerformanceData object.
 *
 * @return @a performance_data.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_performance_data_t *data_collection_model_performance_data_set_min_thrput_dl_move(data_collection_model_performance_data_t *performance_data, char* p_min_thrput_dl);

/** lnode helper for generating ogs_list_t nodes's of type PerformanceData
 * \public \memberof data_collection_model_performance_data_t
 *
 * Creates a new data_collection_lnode_t object containing the @a performance_data object.
 * The @a performance_data will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param performance_data The PerformanceData object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a performance_data
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_performance_data_make_lnode(data_collection_model_performance_data_t *performance_data);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_PERFORMANCE_DATA_H_ */

