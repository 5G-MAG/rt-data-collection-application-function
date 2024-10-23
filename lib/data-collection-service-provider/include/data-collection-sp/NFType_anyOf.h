#ifndef _DATA_COLLECTION_NF_TYPE_ANY_OF_H_
#define _DATA_COLLECTION_NF_TYPE_ANY_OF_H_

/**********************************************************************************************************************************
 * NFType_anyOf - Public C interface to the NFType_anyOf object
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

/** A 3GPP NFType_anyOf object reference
 */
typedef struct data_collection_model_nf_type_any_of_s
#ifdef DOXYGEN_ONLY
{
    int dummy; /**< \private placeholder */
}
#endif
data_collection_model_nf_type_any_of_t;


/** NFType_anyOf enumerated values */
typedef enum {
    DCM_NF_TYPE_ANY_OF_NO_VAL, /**< No value */
    DCM_NF_TYPE_ANY_OF_VAL_NRF, /**< NRF */
    DCM_NF_TYPE_ANY_OF_VAL_UDM, /**< UDM */
    DCM_NF_TYPE_ANY_OF_VAL_AMF, /**< AMF */
    DCM_NF_TYPE_ANY_OF_VAL_SMF, /**< SMF */
    DCM_NF_TYPE_ANY_OF_VAL_AUSF, /**< AUSF */
    DCM_NF_TYPE_ANY_OF_VAL_NEF, /**< NEF */
    DCM_NF_TYPE_ANY_OF_VAL_PCF, /**< PCF */
    DCM_NF_TYPE_ANY_OF_VAL_SMSF, /**< SMSF */
    DCM_NF_TYPE_ANY_OF_VAL_NSSF, /**< NSSF */
    DCM_NF_TYPE_ANY_OF_VAL_UDR, /**< UDR */
    DCM_NF_TYPE_ANY_OF_VAL_LMF, /**< LMF */
    DCM_NF_TYPE_ANY_OF_VAL_GMLC, /**< GMLC */
    DCM_NF_TYPE_ANY_OF_VAL_5_G_EIR, /**< 5G_EIR */
    DCM_NF_TYPE_ANY_OF_VAL_SEPP, /**< SEPP */
    DCM_NF_TYPE_ANY_OF_VAL_UPF, /**< UPF */
    DCM_NF_TYPE_ANY_OF_VAL_N3_IWF, /**< N3IWF */
    DCM_NF_TYPE_ANY_OF_VAL_AF, /**< AF */
    DCM_NF_TYPE_ANY_OF_VAL_UDSF, /**< UDSF */
    DCM_NF_TYPE_ANY_OF_VAL_BSF, /**< BSF */
    DCM_NF_TYPE_ANY_OF_VAL_CHF, /**< CHF */
    DCM_NF_TYPE_ANY_OF_VAL_NWDAF, /**< NWDAF */
    DCM_NF_TYPE_ANY_OF_VAL_PCSCF, /**< PCSCF */
    DCM_NF_TYPE_ANY_OF_VAL_CBCF, /**< CBCF */
    DCM_NF_TYPE_ANY_OF_VAL_HSS, /**< HSS */
    DCM_NF_TYPE_ANY_OF_VAL_UCMF, /**< UCMF */
    DCM_NF_TYPE_ANY_OF_VAL_SOR_AF, /**< SOR_AF */
    DCM_NF_TYPE_ANY_OF_VAL_SPAF, /**< SPAF */
    DCM_NF_TYPE_ANY_OF_VAL_MME, /**< MME */
    DCM_NF_TYPE_ANY_OF_VAL_SCSAS, /**< SCSAS */
    DCM_NF_TYPE_ANY_OF_VAL_SCEF, /**< SCEF */
    DCM_NF_TYPE_ANY_OF_VAL_SCP, /**< SCP */
    DCM_NF_TYPE_ANY_OF_VAL_NSSAAF, /**< NSSAAF */
    DCM_NF_TYPE_ANY_OF_VAL_ICSCF, /**< ICSCF */
    DCM_NF_TYPE_ANY_OF_VAL_SCSCF, /**< SCSCF */
    DCM_NF_TYPE_ANY_OF_VAL_DRA, /**< DRA */
    DCM_NF_TYPE_ANY_OF_VAL_IMS_AS, /**< IMS_AS */
    DCM_NF_TYPE_ANY_OF_VAL_AANF, /**< AANF */
    DCM_NF_TYPE_ANY_OF_VAL_5_G_DDNMF, /**< 5G_DDNMF */
    DCM_NF_TYPE_ANY_OF_VAL_NSACF, /**< NSACF */
    DCM_NF_TYPE_ANY_OF_VAL_MFAF, /**< MFAF */
    DCM_NF_TYPE_ANY_OF_VAL_EASDF, /**< EASDF */
    DCM_NF_TYPE_ANY_OF_VAL_DCCF, /**< DCCF */
    DCM_NF_TYPE_ANY_OF_VAL_MB_SMF, /**< MB_SMF */
    DCM_NF_TYPE_ANY_OF_VAL_TSCTSF, /**< TSCTSF */
    DCM_NF_TYPE_ANY_OF_VAL_ADRF, /**< ADRF */
    DCM_NF_TYPE_ANY_OF_VAL_GBA_BSF, /**< GBA_BSF */
    DCM_NF_TYPE_ANY_OF_VAL_CEF, /**< CEF */
    DCM_NF_TYPE_ANY_OF_VAL_MB_UPF, /**< MB_UPF */
    DCM_NF_TYPE_ANY_OF_VAL_NSWOF, /**< NSWOF */
    DCM_NF_TYPE_ANY_OF_VAL_PKMF, /**< PKMF */
    DCM_NF_TYPE_ANY_OF_VAL_MNPF, /**< MNPF */
    DCM_NF_TYPE_ANY_OF_VAL_SMS_GMSC, /**< SMS_GMSC */
    DCM_NF_TYPE_ANY_OF_VAL_SMS_IWMSC, /**< SMS_IWMSC */
    DCM_NF_TYPE_ANY_OF_VAL_MBSF, /**< MBSF */
    DCM_NF_TYPE_ANY_OF_VAL_MBSTF, /**< MBSTF */
    DCM_NF_TYPE_ANY_OF_VAL_PANF, /**< PANF */
    DCM_NF_TYPE_ANY_OF_VAL_IP_SM_GW, /**< IP_SM_GW */
    DCM_NF_TYPE_ANY_OF_VAL_SMS_ROUTER, /**< SMS_ROUTER */
    DCM_NF_TYPE_ANY_OF_VAL_DCSF, /**< DCSF */
    DCM_NF_TYPE_ANY_OF_VAL_MRF, /**< MRF */
    DCM_NF_TYPE_ANY_OF_VAL_MRFP, /**< MRFP */
    DCM_NF_TYPE_ANY_OF_VAL_MF, /**< MF */
    DCM_NF_TYPE_ANY_OF_VAL_SLPKMF, /**< SLPKMF */
    DCM_NF_TYPE_ANY_OF_VAL_RH /**< RH */
} data_collection_model_nf_type_any_of_e;


/** Create a new NFType_anyOf
 * \public \memberof data_collection_model_nf_type_any_of_t
 * @return a new NFType_anyOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_create();

/** Create a new copy of a NFType_anyOf object
 * \public \memberof data_collection_model_nf_type_any_of_t
 * Creates a new copy of the given @a other object
 * @param other The NFType_anyOf to copy.
 * @return a new NFType_anyOf object pointer.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_create_copy(const data_collection_model_nf_type_any_of_t *other);

/** Create a new reference of a NFType_anyOf object
 * \public \memberof data_collection_model_nf_type_any_of_t
 * Creates a reference to the same underlying @a other object.
 * @param other The NFType_anyOf to create a new reference to.
 * @return a new NFType_anyOf object pointer reference.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_create_move(data_collection_model_nf_type_any_of_t *other);

/** Copy the value of another NFType_anyOf into this object
 * \public \memberof data_collection_model_nf_type_any_of_t
 * Copies the value of @a other {{classname} object into @a nf_type_any_of.
 * @param nf_type_any_of The NFType_anyOf object to copy @a other into.
 * @param other The NFType_anyOf to copy the value from.
 * @return @a nf_type_any_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_copy(data_collection_model_nf_type_any_of_t *nf_type_any_of, const data_collection_model_nf_type_any_of_t *other);

/** Move the value of another NFType_anyOf into this object
 * \public \memberof data_collection_model_nf_type_any_of_t
 * Discards the current value of @a nf_type_any_of and moves the value of @a other
 * into @a nf_type_any_of. This will leave @a other as an empty reference.
 *
 * @param nf_type_any_of The NFType_anyOf object to move @a other into.
 * @param other The NFType_anyOf to move the value from.
 *
 * @return @a nf_type_any_of.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_move(data_collection_model_nf_type_any_of_t *nf_type_any_of, data_collection_model_nf_type_any_of_t *other);

/** Delete a NFType_anyOf object
 * \public \memberof data_collection_model_nf_type_any_of_t
 * Destroys the reference to the NFType_anyOf object and frees the value of NFType_anyOf if this is the last reference.
 *
 * @param nf_type_any_of The NFType_anyOf to free.
 */
DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_nf_type_any_of_free(data_collection_model_nf_type_any_of_t *nf_type_any_of);

/** Get a cJSON tree representation of a NFType_anyOf
 * \public \memberof data_collection_model_nf_type_any_of_t
 *
 * Create a cJSON tree representation of the NFType_anyOf object as either an API request or response. This respects fields marked
 * as Read-only (only in responses) or Write-only (only in requests) in the OpenAPI model description. The resulting cJSON tree
 * must be freed by the caller using the cJSON_Delete() function.
 *
 * @param nf_type_any_of The NFType_anyOf to represent as a cJSON tree.
 * @param as_request `true` for an API request or `false` for an API response.
 *
 * @return a cJSON tree or `NULL`.
 */
DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_nf_type_any_of_toJSON(const data_collection_model_nf_type_any_of_t *nf_type_any_of, bool as_request);

/** Parse a cJSON tree into a NFType_anyOf object
 * \public \memberof data_collection_model_nf_type_any_of_t
 *
 * Attempts to interpret a cJSON tree as a NFType_anyOf API request or response (dependent on @a as_request value). If successful
 * will return a new referenced NFType_anyOf object containing the value represented by the cJSON tree. On failure will return
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
 * @return a new NFType_anyOf object or `NULL` if the parsing failed.
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

/** Compare two NFType_anyOf objects to see if they are equivalent
 * \public \memberof data_collection_model_nf_type_any_of_t
 *
 * This will return `true` if the two objects are referencing the same object or the two objects have the same value.
 *
 * @param nf_type_any_of The first NFType_anyOf object to compare.
 * @param other_nf_type_any_of The second NFType_anyOf object to compare.
 *
 * @return `true` if the two objects are the same or have equal values, `false` otherwise.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_any_of_is_equal_to(const data_collection_model_nf_type_any_of_t *nf_type_any_of, const data_collection_model_nf_type_any_of_t *other_nf_type_any_of);


/** Check if the NFType_anyOf enumeration object has a value set
 * \public \memberof data_collection_model_nf_type_any_of_t
 *
 * @param nf_type_any_of The NFType_anyOf enumeration object to check.
 * @return `true` if the enumeration object has no value set (i.e. is equivalent to `NULL`)
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_any_of_is_not_set(const data_collection_model_nf_type_any_of_t *nf_type_any_of);

/** Get the enumeration value for a NFType_anyOf object
 * \public \memberof data_collection_model_nf_type_any_of_t
 *
 * @param nf_type_any_of The NFType_anyOf object to extract the enumeration value from.
 *
 * @return the data_collection_model_nf_type_any_of_e value represented by the NFType_anyOf object.
 */ 
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_e data_collection_model_nf_type_any_of_get_enum(const data_collection_model_nf_type_any_of_t *nf_type_any_of);

/** Get the string representation of the enumeration value for a NFType_anyOf object
 * \public \memberof data_collection_model_nf_type_any_of_t 
 *
 * @param nf_type_any_of The NFType_anyOf object to extract the enumeration value from.
 *
 * @return the API string for the enumeration or `NULL` if no value set.
 */
DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_nf_type_any_of_get_string(const data_collection_model_nf_type_any_of_t *nf_type_any_of);

/** Set the enumeration value for a NFType_anyOf object
 * \public \memberof data_collection_model_nf_type_any_of_t
 *
 * @param nf_type_any_of The NFType_anyOf object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was set.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_any_of_set_enum(data_collection_model_nf_type_any_of_t *nf_type_any_of, data_collection_model_nf_type_any_of_e value);

/** Set the enumeration value as a string for a NFType_anyOf object
 * \public \memberof data_collection_model_nf_type_any_of_t
 *
 * @param nf_type_any_of The NFType_anyOf object to set the enumeration value for.
 * @param value The value to set.
 *
 * @return `true` if the value was recognised and set or `false` if the string did not represent a known enumeration value.
 */
DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_any_of_set_string(data_collection_model_nf_type_any_of_t *nf_type_any_of, const char *value);


/** lnode helper for generating ogs_list_t nodes's of type NFType_anyOf
 * \public \memberof data_collection_model_nf_type_any_of_t
 *
 * Creates a new data_collection_lnode_t object containing the @a nf_type_any_of object.
 * The @a nf_type_any_of will be deleted when the data_collection_lnode_t is freed. Use
 * data_collection_lnode_create_ref() if you want an list node that will not delete the object when it is freed.
 *
 * @param nf_type_any_of The NFType_anyOf object to create an data_collection_lnode_t object for.
 *
 * @return a new data_collection_lnode_t object containing the @a nf_type_any_of
 */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_nf_type_any_of_make_lnode(data_collection_model_nf_type_any_of_t *nf_type_any_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/** @} */

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NF_TYPE_ANY_OF_H_ */

