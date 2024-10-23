#ifndef _DATA_COLLECTION_DAT_VOL_TRANS_TIME_COLLECTION_H_
#define _DATA_COLLECTION_DAT_VOL_TRANS_TIME_COLLECTION_H_

/**********************************************************************************************************************************
 * DatVolTransTimeCollection - Public C interface to the DatVolTransTimeCollection object
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

#include "AddrFqdn.h"
#include "TimeWindow.h"

/** \addtogroup dcsp_model
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/** A 3GPP DatVolTransTimeCollection object reference
 */
typedef struct data_collection_model_dat_vol_trans_time_collection_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_dat_vol_trans_time_collection_t;



/** Create a new DatVolTransTimeCollection
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 * @return a new DatVolTransTimeCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create();

/** Create a new copy of a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 * Creates a new copy of the given @a other object
 * @param other The DatVolTransTimeCollection to copy.
 * @return a new DatVolTransTimeCollection object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create_copy(const data_collection_model_dat_vol_trans_time_collection_t *other);

/** Create a new reference of a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 * Creates a reference to the same underlying @a other object.
 * @param other The DatVolTransTimeCollection to create a new reference to.
 * @return a new DatVolTransTimeCollection object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_create_move(data_collection_model_dat_vol_trans_time_collection_t *other);

/** Copy the value of another DatVolTransTimeCollection into this object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 * Copies the value of @a other {{classname} object into @a dat_vol_trans_time_collection.
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to copy @a other into.
 * @param other The DatVolTransTimeCollection to copy the value from.
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_copy(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_dat_vol_trans_time_collection_t *other);

/** Move the value of another DatVolTransTimeCollection into this object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 * Discards the current value of @a dat_vol_trans_time_collection and moves the value of @a other
 * into @a dat_vol_trans_time_collection. This will leave @a other as an empty reference.
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to move @a other into.
 * @param other The DatVolTransTimeCollection to move the value from.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, data_collection_model_dat_vol_trans_time_collection_t *other);

/** Delete a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 * Destroys the reference to the DatVolTransTimeCollection object and frees the value of DatVolTransTimeCollection if this is the last reference.
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_dat_vol_trans_time_collection_free(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/** Get a cJSON tree representation of a DatVolTransTimeCollection
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * Create a cJSON tree representation of the DatVolTransTimeCollection object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_dat_vol_trans_time_collection_toJSON(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, bool as_request);

/** Parse a cJSON tree into a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * Attempts to interpret a cJSON tree as a DatVolTransTimeCollection API request or response (dependent on @a as_request value). If successful
 * will return a new referenced DatVolTransTimeCollection object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new DatVolTransTimeCollection object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two DatVolTransTimeCollection objects to see if they are equivalent
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param dat_vol_trans_time_collection The first DatVolTransTimeCollection object to compare.
 * @param other_dat_vol_trans_time_collection The second DatVolTransTimeCollection object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_is_equal_to(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_dat_vol_trans_time_collection_t *other_dat_vol_trans_time_collection);


/** Check if the appId field of a DatVolTransTimeCollection object is set
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return `true` if the optional appId field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_app_id(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);


/** Get the value of the appId field of a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return the value current set for the appId field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dat_vol_trans_time_collection_get_app_id(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/** Set the value of the appId field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_app_id The value to copy into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_id(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const char* p_app_id);

/** Move a value to the appId field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_app_id The value to move into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_id_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, char* p_app_id);

/** Check if the appServerInst field of a DatVolTransTimeCollection object is set
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return `true` if the optional appServerInst field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_app_server_inst(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);


/** Get the value of the appServerInst field of a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return the value current set for the appServerInst field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_addr_fqdn_t* data_collection_model_dat_vol_trans_time_collection_get_app_server_inst(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/** Set the value of the appServerInst field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_app_server_inst The value to copy into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_server_inst(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_addr_fqdn_t* p_app_server_inst);

/** Move a value to the appServerInst field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_app_server_inst The value to move into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_app_server_inst_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, data_collection_model_addr_fqdn_t* p_app_server_inst);

/** Check if the gpsi field of a DatVolTransTimeCollection object is set
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return `true` if the optional gpsi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_gpsi(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);


/** Get the value of the gpsi field of a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return the value current set for the gpsi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dat_vol_trans_time_collection_get_gpsi(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/** Set the value of the gpsi field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_gpsi The value to copy into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_gpsi(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const char* p_gpsi);

/** Move a value to the gpsi field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_gpsi The value to move into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_gpsi_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, char* p_gpsi);

/** Check if the supi field of a DatVolTransTimeCollection object is set
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return `true` if the optional supi field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_supi(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);


/** Get the value of the supi field of a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return the value current set for the supi field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_dat_vol_trans_time_collection_get_supi(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/** Set the value of the supi field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_supi The value to copy into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_supi(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const char* p_supi);

/** Move a value to the supi field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_supi The value to move into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_supi_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, char* p_supi);

/** Check if the ulTransVol field of a DatVolTransTimeCollection object is set
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return `true` if the optional ulTransVol field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_ul_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);


/** Get the value of the ulTransVol field of a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return the value current set for the ulTransVol field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_dat_vol_trans_time_collection_get_ul_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/** Set the value of the ulTransVol field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_ul_trans_vol The value to copy into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_vol(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const int64_t p_ul_trans_vol);

/** Move a value to the ulTransVol field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_ul_trans_vol The value to move into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_vol_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, int64_t p_ul_trans_vol);

/** Check if the dlTransVol field of a DatVolTransTimeCollection object is set
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return `true` if the optional dlTransVol field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_dl_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);


/** Get the value of the dlTransVol field of a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return the value current set for the dlTransVol field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const int64_t data_collection_model_dat_vol_trans_time_collection_get_dl_trans_vol(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/** Set the value of the dlTransVol field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_dl_trans_vol The value to copy into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_vol(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const int64_t p_dl_trans_vol);

/** Move a value to the dlTransVol field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_dl_trans_vol The value to move into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_vol_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, int64_t p_dl_trans_vol);

/** Check if the ulTransTimeDur field of a DatVolTransTimeCollection object is set
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return `true` if the optional ulTransTimeDur field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_ul_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);


/** Get the value of the ulTransTimeDur field of a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return the value current set for the ulTransTimeDur field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_dat_vol_trans_time_collection_get_ul_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/** Set the value of the ulTransTimeDur field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_ul_trans_time_dur The value to copy into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_time_dur(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_time_window_t* p_ul_trans_time_dur);

/** Move a value to the ulTransTimeDur field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_ul_trans_time_dur The value to move into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_ul_trans_time_dur_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, data_collection_model_time_window_t* p_ul_trans_time_dur);

/** Check if the dlTransTimeDur field of a DatVolTransTimeCollection object is set
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return `true` if the optional dlTransTimeDur field is set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_dat_vol_trans_time_collection_has_dl_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);


/** Get the value of the dlTransTimeDur field of a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to examine.
 *
 * @return the value current set for the dlTransTimeDur field.
 */
DATA_COLLECTION_SVC_PRODUCER_API const data_collection_model_time_window_t* data_collection_model_dat_vol_trans_time_collection_get_dl_trans_time_dur(const data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/** Set the value of the dlTransTimeDur field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_dl_trans_time_dur The value to copy into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_time_dur(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, const data_collection_model_time_window_t* p_dl_trans_time_dur);

/** Move a value to the dlTransTimeDur field in a DatVolTransTimeCollection object
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to set the field in.
 * @param p_dl_trans_time_dur The value to move into the DatVolTransTimeCollection object.
 *
 * @return @a dat_vol_trans_time_collection.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_dat_vol_trans_time_collection_t *data_collection_model_dat_vol_trans_time_collection_set_dl_trans_time_dur_move(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection, data_collection_model_time_window_t* p_dl_trans_time_dur);

/** lnode helper for generating ogs_list_t nodes's of type DatVolTransTimeCollection
 * \public \memberof data_collection_model_dat_vol_trans_time_collection_t
 *
 * Creates a new data_collection_lnode_t object containing the @a dat_vol_trans_time_collection object.
 * The @a dat_vol_trans_time_collection will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param dat_vol_trans_time_collection The DatVolTransTimeCollection object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a dat_vol_trans_time_collection
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_dat_vol_trans_time_collection_make_lnode(data_collection_model_dat_vol_trans_time_collection_t *dat_vol_trans_time_collection);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_DAT_VOL_TRANS_TIME_COLLECTION_H_ */

