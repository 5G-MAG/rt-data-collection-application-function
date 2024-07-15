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


#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_collection_model_nf_type_any_of_s data_collection_model_nf_type_any_of_t;

typedef enum {
    DCM_NF_TYPE_ANY_OF_NO_VAL,
    DCM_NF_TYPE_ANY_OF_VAL_NRF,
    DCM_NF_TYPE_ANY_OF_VAL_UDM,
    DCM_NF_TYPE_ANY_OF_VAL_AMF,
    DCM_NF_TYPE_ANY_OF_VAL_SMF,
    DCM_NF_TYPE_ANY_OF_VAL_AUSF,
    DCM_NF_TYPE_ANY_OF_VAL_NEF,
    DCM_NF_TYPE_ANY_OF_VAL_PCF,
    DCM_NF_TYPE_ANY_OF_VAL_SMSF,
    DCM_NF_TYPE_ANY_OF_VAL_NSSF,
    DCM_NF_TYPE_ANY_OF_VAL_UDR,
    DCM_NF_TYPE_ANY_OF_VAL_LMF,
    DCM_NF_TYPE_ANY_OF_VAL_GMLC,
    DCM_NF_TYPE_ANY_OF_VAL_5_G_EIR,
    DCM_NF_TYPE_ANY_OF_VAL_SEPP,
    DCM_NF_TYPE_ANY_OF_VAL_UPF,
    DCM_NF_TYPE_ANY_OF_VAL_N3_IWF,
    DCM_NF_TYPE_ANY_OF_VAL_AF,
    DCM_NF_TYPE_ANY_OF_VAL_UDSF,
    DCM_NF_TYPE_ANY_OF_VAL_BSF,
    DCM_NF_TYPE_ANY_OF_VAL_CHF,
    DCM_NF_TYPE_ANY_OF_VAL_NWDAF,
    DCM_NF_TYPE_ANY_OF_VAL_PCSCF,
    DCM_NF_TYPE_ANY_OF_VAL_CBCF,
    DCM_NF_TYPE_ANY_OF_VAL_HSS,
    DCM_NF_TYPE_ANY_OF_VAL_UCMF,
    DCM_NF_TYPE_ANY_OF_VAL_SOR_AF,
    DCM_NF_TYPE_ANY_OF_VAL_SPAF,
    DCM_NF_TYPE_ANY_OF_VAL_MME,
    DCM_NF_TYPE_ANY_OF_VAL_SCSAS,
    DCM_NF_TYPE_ANY_OF_VAL_SCEF,
    DCM_NF_TYPE_ANY_OF_VAL_SCP,
    DCM_NF_TYPE_ANY_OF_VAL_NSSAAF,
    DCM_NF_TYPE_ANY_OF_VAL_ICSCF,
    DCM_NF_TYPE_ANY_OF_VAL_SCSCF,
    DCM_NF_TYPE_ANY_OF_VAL_DRA,
    DCM_NF_TYPE_ANY_OF_VAL_IMS_AS,
    DCM_NF_TYPE_ANY_OF_VAL_AANF,
    DCM_NF_TYPE_ANY_OF_VAL_5_G_DDNMF,
    DCM_NF_TYPE_ANY_OF_VAL_NSACF,
    DCM_NF_TYPE_ANY_OF_VAL_MFAF,
    DCM_NF_TYPE_ANY_OF_VAL_EASDF,
    DCM_NF_TYPE_ANY_OF_VAL_DCCF,
    DCM_NF_TYPE_ANY_OF_VAL_MB_SMF,
    DCM_NF_TYPE_ANY_OF_VAL_TSCTSF,
    DCM_NF_TYPE_ANY_OF_VAL_ADRF,
    DCM_NF_TYPE_ANY_OF_VAL_GBA_BSF,
    DCM_NF_TYPE_ANY_OF_VAL_CEF,
    DCM_NF_TYPE_ANY_OF_VAL_MB_UPF,
    DCM_NF_TYPE_ANY_OF_VAL_NSWOF,
    DCM_NF_TYPE_ANY_OF_VAL_PKMF,
    DCM_NF_TYPE_ANY_OF_VAL_MNPF,
    DCM_NF_TYPE_ANY_OF_VAL_SMS_GMSC,
    DCM_NF_TYPE_ANY_OF_VAL_SMS_IWMSC,
    DCM_NF_TYPE_ANY_OF_VAL_MBSF,
    DCM_NF_TYPE_ANY_OF_VAL_MBSTF,
    DCM_NF_TYPE_ANY_OF_VAL_PANF,
    DCM_NF_TYPE_ANY_OF_VAL_IP_SM_GW,
    DCM_NF_TYPE_ANY_OF_VAL_SMS_ROUTER,
    DCM_NF_TYPE_ANY_OF_VAL_DCSF,
    DCM_NF_TYPE_ANY_OF_VAL_MRF,
    DCM_NF_TYPE_ANY_OF_VAL_MRFP,
    DCM_NF_TYPE_ANY_OF_VAL_MF,
    DCM_NF_TYPE_ANY_OF_VAL_SLPKMF,
    DCM_NF_TYPE_ANY_OF_VAL_RH
} data_collection_model_nf_type_any_of_e;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_create_copy(const data_collection_model_nf_type_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_create_move(data_collection_model_nf_type_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_copy(data_collection_model_nf_type_any_of_t *nf_type_any_of, const data_collection_model_nf_type_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_move(data_collection_model_nf_type_any_of_t *nf_type_any_of, data_collection_model_nf_type_any_of_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_nf_type_any_of_free(data_collection_model_nf_type_any_of_t *nf_type_any_of);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_nf_type_any_of_toJSON(const data_collection_model_nf_type_any_of_t *nf_type_any_of, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_t *data_collection_model_nf_type_any_of_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);


DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_any_of_is_not_set(const data_collection_model_nf_type_any_of_t *nf_type_any_of);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_any_of_e data_collection_model_nf_type_any_of_get_enum(const data_collection_model_nf_type_any_of_t *nf_type_any_of);

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_nf_type_any_of_get_string(const data_collection_model_nf_type_any_of_t *nf_type_any_of);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_any_of_set_enum(data_collection_model_nf_type_any_of_t *nf_type_any_of, data_collection_model_nf_type_any_of_e value);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_any_of_set_string(data_collection_model_nf_type_any_of_t *nf_type_any_of, const char *value);


/* lnode helper for generating ogs_list_t nodes's of type NFType_anyOf */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_nf_type_any_of_make_lnode(data_collection_model_nf_type_any_of_t *nf_type_any_of);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_NF_TYPE_ANY_OF_H_ */

