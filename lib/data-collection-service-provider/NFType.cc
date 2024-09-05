/**********************************************************************************************************************************
 * NFType - C interface to the NFType object
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

/*#include "NFType.h" already included by data-collection-sp/data-collection.h */
#include "NFType-internal.h"
#include "openapi/model/NFType.h"

using namespace reftools::data_collection_sp;

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_t *data_collection_model_nf_type_create()
{
    return reinterpret_cast<data_collection_model_nf_type_t*>(new std::shared_ptr<NFType>(new NFType()));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_t *data_collection_model_nf_type_create_copy(const data_collection_model_nf_type_t *other)
{
    if (!other) return NULL;
    const std::shared_ptr<NFType > &obj = *reinterpret_cast<const std::shared_ptr<NFType >*>(other);
    if (!obj) return NULL;
    return reinterpret_cast<data_collection_model_nf_type_t*>(new std::shared_ptr<NFType >(new NFType(*obj)));
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_t *data_collection_model_nf_type_create_move(data_collection_model_nf_type_t *other)
{
    if (!other) return NULL;

    std::shared_ptr<NFType > *obj = reinterpret_cast<std::shared_ptr<NFType >*>(other);
    if (!*obj) {
        delete obj;
        return NULL;
    }

    return other;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_t *data_collection_model_nf_type_copy(data_collection_model_nf_type_t *nf_type, const data_collection_model_nf_type_t *other)
{
    if (nf_type) {
        std::shared_ptr<NFType > &obj = *reinterpret_cast<std::shared_ptr<NFType >*>(nf_type);
        if (obj) {
            if (other) {
                const std::shared_ptr<NFType > &other_obj = *reinterpret_cast<const std::shared_ptr<NFType >*>(other);
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
                const std::shared_ptr<NFType > &other_obj = *reinterpret_cast<const std::shared_ptr<NFType >*>(other);
                if (other_obj) {
                    obj.reset(new NFType(*other_obj));
                } /* else already null shared pointer */
            } /* else already null shared pointer */
        }
    } else {
        nf_type = data_collection_model_nf_type_create_copy(other);
    }
    return nf_type;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_t *data_collection_model_nf_type_move(data_collection_model_nf_type_t *nf_type, data_collection_model_nf_type_t *other)
{
    std::shared_ptr<NFType > *other_ptr = reinterpret_cast<std::shared_ptr<NFType >*>(other);

    if (nf_type) {
        std::shared_ptr<NFType > &obj = *reinterpret_cast<std::shared_ptr<NFType >*>(nf_type);
        if (other_ptr) {
            obj = std::move(*other_ptr);
            delete other_ptr;
        } else {
            obj.reset();
        }
    } else {
        if (other_ptr) {
            if (*other_ptr) {
                nf_type = other;
            } else {
                delete other_ptr;
            }
        }
    }
    return nf_type;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_nf_type_free(data_collection_model_nf_type_t *nf_type)
{
    if (!nf_type) return;
    delete reinterpret_cast<std::shared_ptr<NFType >*>(nf_type);
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_nf_type_toJSON(const data_collection_model_nf_type_t *nf_type, bool as_request)
{
    if (!nf_type) return NULL;
    const std::shared_ptr<NFType > &obj = *reinterpret_cast<const std::shared_ptr<NFType >*>(nf_type);
    if (obj) {
        try {
            fiveg_mag_reftools::CJson json(obj->toJSON(as_request));
            return json.exportCJSON();
        } catch (const fiveg_mag_reftools::ModelException &err) {
            ogs_error("Failed to convert data_collection_model_nf_type_t to cJSON [%s.%s]: %s", err.classname.c_str(), err.parameter.c_str(), err.what());
        }
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_t *data_collection_model_nf_type_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter)
{
    fiveg_mag_reftools::CJson objjson(json, false);
    try {
        return reinterpret_cast<data_collection_model_nf_type_t*>(new std::shared_ptr<NFType >(new NFType(objjson, as_request)));
    } catch (const fiveg_mag_reftools::ModelException &ex) {
        if (error_reason) *error_reason = data_collection_strdup(ex.what());
        if (error_class) *error_class = data_collection_strdup(ex.classname.c_str());
        if (error_parameter) *error_parameter = data_collection_strdup(ex.parameter.c_str());
    }
    return NULL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_is_equal_to(const data_collection_model_nf_type_t *first, const data_collection_model_nf_type_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<NFType > &obj2 = *reinterpret_cast<const std::shared_ptr<NFType >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<NFType > &obj1 = *reinterpret_cast<const std::shared_ptr<NFType >*>(first);
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


extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_is_not_set(const data_collection_model_nf_type_t *obj_nf_type)
{
    if (!obj_nf_type) return true;
    const std::shared_ptr<NFType > &obj = *reinterpret_cast<const std::shared_ptr<NFType >*>(obj_nf_type);
    if (!obj) return true;
    return obj->getValue() == NFType::Enum::NO_VAL;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_is_non_standard(const data_collection_model_nf_type_t *obj_nf_type)
{
    if (!obj_nf_type) return false;
    const std::shared_ptr<NFType > &obj = *reinterpret_cast<const std::shared_ptr<NFType >*>(obj_nf_type);
    if (!obj) return false;
    return obj->getValue() == NFType::Enum::OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_nf_type_e data_collection_model_nf_type_get_enum(const data_collection_model_nf_type_t *obj_nf_type)
{
    if (!obj_nf_type)
        return DCM_NF_TYPE_NO_VAL;
    const std::shared_ptr<NFType > &obj = *reinterpret_cast<const std::shared_ptr<NFType >*>(obj_nf_type);
    if (!obj) return DCM_NF_TYPE_NO_VAL;
    switch (obj->getValue()) {
    case NFType::Enum::NO_VAL:
        return DCM_NF_TYPE_NO_VAL;
    case NFType::Enum::VAL_NRF:
        return DCM_NF_TYPE_VAL_NRF;
    case NFType::Enum::VAL_UDM:
        return DCM_NF_TYPE_VAL_UDM;
    case NFType::Enum::VAL_AMF:
        return DCM_NF_TYPE_VAL_AMF;
    case NFType::Enum::VAL_SMF:
        return DCM_NF_TYPE_VAL_SMF;
    case NFType::Enum::VAL_AUSF:
        return DCM_NF_TYPE_VAL_AUSF;
    case NFType::Enum::VAL_NEF:
        return DCM_NF_TYPE_VAL_NEF;
    case NFType::Enum::VAL_PCF:
        return DCM_NF_TYPE_VAL_PCF;
    case NFType::Enum::VAL_SMSF:
        return DCM_NF_TYPE_VAL_SMSF;
    case NFType::Enum::VAL_NSSF:
        return DCM_NF_TYPE_VAL_NSSF;
    case NFType::Enum::VAL_UDR:
        return DCM_NF_TYPE_VAL_UDR;
    case NFType::Enum::VAL_LMF:
        return DCM_NF_TYPE_VAL_LMF;
    case NFType::Enum::VAL_GMLC:
        return DCM_NF_TYPE_VAL_GMLC;
    case NFType::Enum::VAL_5_G_EIR:
        return DCM_NF_TYPE_VAL_5_G_EIR;
    case NFType::Enum::VAL_SEPP:
        return DCM_NF_TYPE_VAL_SEPP;
    case NFType::Enum::VAL_UPF:
        return DCM_NF_TYPE_VAL_UPF;
    case NFType::Enum::VAL_N3_IWF:
        return DCM_NF_TYPE_VAL_N3_IWF;
    case NFType::Enum::VAL_AF:
        return DCM_NF_TYPE_VAL_AF;
    case NFType::Enum::VAL_UDSF:
        return DCM_NF_TYPE_VAL_UDSF;
    case NFType::Enum::VAL_BSF:
        return DCM_NF_TYPE_VAL_BSF;
    case NFType::Enum::VAL_CHF:
        return DCM_NF_TYPE_VAL_CHF;
    case NFType::Enum::VAL_NWDAF:
        return DCM_NF_TYPE_VAL_NWDAF;
    case NFType::Enum::VAL_PCSCF:
        return DCM_NF_TYPE_VAL_PCSCF;
    case NFType::Enum::VAL_CBCF:
        return DCM_NF_TYPE_VAL_CBCF;
    case NFType::Enum::VAL_HSS:
        return DCM_NF_TYPE_VAL_HSS;
    case NFType::Enum::VAL_UCMF:
        return DCM_NF_TYPE_VAL_UCMF;
    case NFType::Enum::VAL_SOR_AF:
        return DCM_NF_TYPE_VAL_SOR_AF;
    case NFType::Enum::VAL_SPAF:
        return DCM_NF_TYPE_VAL_SPAF;
    case NFType::Enum::VAL_MME:
        return DCM_NF_TYPE_VAL_MME;
    case NFType::Enum::VAL_SCSAS:
        return DCM_NF_TYPE_VAL_SCSAS;
    case NFType::Enum::VAL_SCEF:
        return DCM_NF_TYPE_VAL_SCEF;
    case NFType::Enum::VAL_SCP:
        return DCM_NF_TYPE_VAL_SCP;
    case NFType::Enum::VAL_NSSAAF:
        return DCM_NF_TYPE_VAL_NSSAAF;
    case NFType::Enum::VAL_ICSCF:
        return DCM_NF_TYPE_VAL_ICSCF;
    case NFType::Enum::VAL_SCSCF:
        return DCM_NF_TYPE_VAL_SCSCF;
    case NFType::Enum::VAL_DRA:
        return DCM_NF_TYPE_VAL_DRA;
    case NFType::Enum::VAL_IMS_AS:
        return DCM_NF_TYPE_VAL_IMS_AS;
    case NFType::Enum::VAL_AANF:
        return DCM_NF_TYPE_VAL_AANF;
    case NFType::Enum::VAL_5_G_DDNMF:
        return DCM_NF_TYPE_VAL_5_G_DDNMF;
    case NFType::Enum::VAL_NSACF:
        return DCM_NF_TYPE_VAL_NSACF;
    case NFType::Enum::VAL_MFAF:
        return DCM_NF_TYPE_VAL_MFAF;
    case NFType::Enum::VAL_EASDF:
        return DCM_NF_TYPE_VAL_EASDF;
    case NFType::Enum::VAL_DCCF:
        return DCM_NF_TYPE_VAL_DCCF;
    case NFType::Enum::VAL_MB_SMF:
        return DCM_NF_TYPE_VAL_MB_SMF;
    case NFType::Enum::VAL_TSCTSF:
        return DCM_NF_TYPE_VAL_TSCTSF;
    case NFType::Enum::VAL_ADRF:
        return DCM_NF_TYPE_VAL_ADRF;
    case NFType::Enum::VAL_GBA_BSF:
        return DCM_NF_TYPE_VAL_GBA_BSF;
    case NFType::Enum::VAL_CEF:
        return DCM_NF_TYPE_VAL_CEF;
    case NFType::Enum::VAL_MB_UPF:
        return DCM_NF_TYPE_VAL_MB_UPF;
    case NFType::Enum::VAL_NSWOF:
        return DCM_NF_TYPE_VAL_NSWOF;
    case NFType::Enum::VAL_PKMF:
        return DCM_NF_TYPE_VAL_PKMF;
    case NFType::Enum::VAL_MNPF:
        return DCM_NF_TYPE_VAL_MNPF;
    case NFType::Enum::VAL_SMS_GMSC:
        return DCM_NF_TYPE_VAL_SMS_GMSC;
    case NFType::Enum::VAL_SMS_IWMSC:
        return DCM_NF_TYPE_VAL_SMS_IWMSC;
    case NFType::Enum::VAL_MBSF:
        return DCM_NF_TYPE_VAL_MBSF;
    case NFType::Enum::VAL_MBSTF:
        return DCM_NF_TYPE_VAL_MBSTF;
    case NFType::Enum::VAL_PANF:
        return DCM_NF_TYPE_VAL_PANF;
    case NFType::Enum::VAL_IP_SM_GW:
        return DCM_NF_TYPE_VAL_IP_SM_GW;
    case NFType::Enum::VAL_SMS_ROUTER:
        return DCM_NF_TYPE_VAL_SMS_ROUTER;
    case NFType::Enum::VAL_DCSF:
        return DCM_NF_TYPE_VAL_DCSF;
    case NFType::Enum::VAL_MRF:
        return DCM_NF_TYPE_VAL_MRF;
    case NFType::Enum::VAL_MRFP:
        return DCM_NF_TYPE_VAL_MRFP;
    case NFType::Enum::VAL_MF:
        return DCM_NF_TYPE_VAL_MF;
    case NFType::Enum::VAL_SLPKMF:
        return DCM_NF_TYPE_VAL_SLPKMF;
    case NFType::Enum::VAL_RH:
        return DCM_NF_TYPE_VAL_RH;
    default:
        break;
    }
    return DCM_NF_TYPE_OTHER;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_model_nf_type_get_string(const data_collection_model_nf_type_t *obj_nf_type)
{
    if (!obj_nf_type) return NULL;
    const std::shared_ptr<NFType > &obj = *reinterpret_cast<const std::shared_ptr<NFType >*>(obj_nf_type);
    if (!obj) return NULL;
    return obj->getString().c_str();
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_set_enum(data_collection_model_nf_type_t *obj_nf_type, data_collection_model_nf_type_e p_value)
{
    if (!obj_nf_type) return false;
    std::shared_ptr<NFType > &obj = *reinterpret_cast<std::shared_ptr<NFType >*>(obj_nf_type);
    if (!obj) return false;
    switch (p_value) {
    case DCM_NF_TYPE_NO_VAL:
        *obj = NFType::Enum::NO_VAL;
        return true;
    case DCM_NF_TYPE_VAL_NRF:
        *obj = NFType::Enum::VAL_NRF;
        return true;
    case DCM_NF_TYPE_VAL_UDM:
        *obj = NFType::Enum::VAL_UDM;
        return true;
    case DCM_NF_TYPE_VAL_AMF:
        *obj = NFType::Enum::VAL_AMF;
        return true;
    case DCM_NF_TYPE_VAL_SMF:
        *obj = NFType::Enum::VAL_SMF;
        return true;
    case DCM_NF_TYPE_VAL_AUSF:
        *obj = NFType::Enum::VAL_AUSF;
        return true;
    case DCM_NF_TYPE_VAL_NEF:
        *obj = NFType::Enum::VAL_NEF;
        return true;
    case DCM_NF_TYPE_VAL_PCF:
        *obj = NFType::Enum::VAL_PCF;
        return true;
    case DCM_NF_TYPE_VAL_SMSF:
        *obj = NFType::Enum::VAL_SMSF;
        return true;
    case DCM_NF_TYPE_VAL_NSSF:
        *obj = NFType::Enum::VAL_NSSF;
        return true;
    case DCM_NF_TYPE_VAL_UDR:
        *obj = NFType::Enum::VAL_UDR;
        return true;
    case DCM_NF_TYPE_VAL_LMF:
        *obj = NFType::Enum::VAL_LMF;
        return true;
    case DCM_NF_TYPE_VAL_GMLC:
        *obj = NFType::Enum::VAL_GMLC;
        return true;
    case DCM_NF_TYPE_VAL_5_G_EIR:
        *obj = NFType::Enum::VAL_5_G_EIR;
        return true;
    case DCM_NF_TYPE_VAL_SEPP:
        *obj = NFType::Enum::VAL_SEPP;
        return true;
    case DCM_NF_TYPE_VAL_UPF:
        *obj = NFType::Enum::VAL_UPF;
        return true;
    case DCM_NF_TYPE_VAL_N3_IWF:
        *obj = NFType::Enum::VAL_N3_IWF;
        return true;
    case DCM_NF_TYPE_VAL_AF:
        *obj = NFType::Enum::VAL_AF;
        return true;
    case DCM_NF_TYPE_VAL_UDSF:
        *obj = NFType::Enum::VAL_UDSF;
        return true;
    case DCM_NF_TYPE_VAL_BSF:
        *obj = NFType::Enum::VAL_BSF;
        return true;
    case DCM_NF_TYPE_VAL_CHF:
        *obj = NFType::Enum::VAL_CHF;
        return true;
    case DCM_NF_TYPE_VAL_NWDAF:
        *obj = NFType::Enum::VAL_NWDAF;
        return true;
    case DCM_NF_TYPE_VAL_PCSCF:
        *obj = NFType::Enum::VAL_PCSCF;
        return true;
    case DCM_NF_TYPE_VAL_CBCF:
        *obj = NFType::Enum::VAL_CBCF;
        return true;
    case DCM_NF_TYPE_VAL_HSS:
        *obj = NFType::Enum::VAL_HSS;
        return true;
    case DCM_NF_TYPE_VAL_UCMF:
        *obj = NFType::Enum::VAL_UCMF;
        return true;
    case DCM_NF_TYPE_VAL_SOR_AF:
        *obj = NFType::Enum::VAL_SOR_AF;
        return true;
    case DCM_NF_TYPE_VAL_SPAF:
        *obj = NFType::Enum::VAL_SPAF;
        return true;
    case DCM_NF_TYPE_VAL_MME:
        *obj = NFType::Enum::VAL_MME;
        return true;
    case DCM_NF_TYPE_VAL_SCSAS:
        *obj = NFType::Enum::VAL_SCSAS;
        return true;
    case DCM_NF_TYPE_VAL_SCEF:
        *obj = NFType::Enum::VAL_SCEF;
        return true;
    case DCM_NF_TYPE_VAL_SCP:
        *obj = NFType::Enum::VAL_SCP;
        return true;
    case DCM_NF_TYPE_VAL_NSSAAF:
        *obj = NFType::Enum::VAL_NSSAAF;
        return true;
    case DCM_NF_TYPE_VAL_ICSCF:
        *obj = NFType::Enum::VAL_ICSCF;
        return true;
    case DCM_NF_TYPE_VAL_SCSCF:
        *obj = NFType::Enum::VAL_SCSCF;
        return true;
    case DCM_NF_TYPE_VAL_DRA:
        *obj = NFType::Enum::VAL_DRA;
        return true;
    case DCM_NF_TYPE_VAL_IMS_AS:
        *obj = NFType::Enum::VAL_IMS_AS;
        return true;
    case DCM_NF_TYPE_VAL_AANF:
        *obj = NFType::Enum::VAL_AANF;
        return true;
    case DCM_NF_TYPE_VAL_5_G_DDNMF:
        *obj = NFType::Enum::VAL_5_G_DDNMF;
        return true;
    case DCM_NF_TYPE_VAL_NSACF:
        *obj = NFType::Enum::VAL_NSACF;
        return true;
    case DCM_NF_TYPE_VAL_MFAF:
        *obj = NFType::Enum::VAL_MFAF;
        return true;
    case DCM_NF_TYPE_VAL_EASDF:
        *obj = NFType::Enum::VAL_EASDF;
        return true;
    case DCM_NF_TYPE_VAL_DCCF:
        *obj = NFType::Enum::VAL_DCCF;
        return true;
    case DCM_NF_TYPE_VAL_MB_SMF:
        *obj = NFType::Enum::VAL_MB_SMF;
        return true;
    case DCM_NF_TYPE_VAL_TSCTSF:
        *obj = NFType::Enum::VAL_TSCTSF;
        return true;
    case DCM_NF_TYPE_VAL_ADRF:
        *obj = NFType::Enum::VAL_ADRF;
        return true;
    case DCM_NF_TYPE_VAL_GBA_BSF:
        *obj = NFType::Enum::VAL_GBA_BSF;
        return true;
    case DCM_NF_TYPE_VAL_CEF:
        *obj = NFType::Enum::VAL_CEF;
        return true;
    case DCM_NF_TYPE_VAL_MB_UPF:
        *obj = NFType::Enum::VAL_MB_UPF;
        return true;
    case DCM_NF_TYPE_VAL_NSWOF:
        *obj = NFType::Enum::VAL_NSWOF;
        return true;
    case DCM_NF_TYPE_VAL_PKMF:
        *obj = NFType::Enum::VAL_PKMF;
        return true;
    case DCM_NF_TYPE_VAL_MNPF:
        *obj = NFType::Enum::VAL_MNPF;
        return true;
    case DCM_NF_TYPE_VAL_SMS_GMSC:
        *obj = NFType::Enum::VAL_SMS_GMSC;
        return true;
    case DCM_NF_TYPE_VAL_SMS_IWMSC:
        *obj = NFType::Enum::VAL_SMS_IWMSC;
        return true;
    case DCM_NF_TYPE_VAL_MBSF:
        *obj = NFType::Enum::VAL_MBSF;
        return true;
    case DCM_NF_TYPE_VAL_MBSTF:
        *obj = NFType::Enum::VAL_MBSTF;
        return true;
    case DCM_NF_TYPE_VAL_PANF:
        *obj = NFType::Enum::VAL_PANF;
        return true;
    case DCM_NF_TYPE_VAL_IP_SM_GW:
        *obj = NFType::Enum::VAL_IP_SM_GW;
        return true;
    case DCM_NF_TYPE_VAL_SMS_ROUTER:
        *obj = NFType::Enum::VAL_SMS_ROUTER;
        return true;
    case DCM_NF_TYPE_VAL_DCSF:
        *obj = NFType::Enum::VAL_DCSF;
        return true;
    case DCM_NF_TYPE_VAL_MRF:
        *obj = NFType::Enum::VAL_MRF;
        return true;
    case DCM_NF_TYPE_VAL_MRFP:
        *obj = NFType::Enum::VAL_MRFP;
        return true;
    case DCM_NF_TYPE_VAL_MF:
        *obj = NFType::Enum::VAL_MF;
        return true;
    case DCM_NF_TYPE_VAL_SLPKMF:
        *obj = NFType::Enum::VAL_SLPKMF;
        return true;
    case DCM_NF_TYPE_VAL_RH:
        *obj = NFType::Enum::VAL_RH;
        return true;
    default:
        break;
    }
    return false;
}

extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_nf_type_set_string(data_collection_model_nf_type_t *obj_nf_type, const char *p_value)
{
    if (!obj_nf_type) return false;
    std::shared_ptr<NFType > &obj = *reinterpret_cast<std::shared_ptr<NFType >*>(obj_nf_type);
    if (!obj) return false;
    if (p_value) {
        *obj = std::string(p_value);
    } else {
        *obj = NFType::Enum::NO_VAL;
    }
    return true;
}



extern "C" DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_nf_type_make_lnode(data_collection_model_nf_type_t *p_nf_type)
{
    return data_collection_lnode_create(p_nf_type, reinterpret_cast<void(*)(void*)>(data_collection_model_nf_type_free));
}

/***** Internal library protected functions *****/

extern "C" long _model_nf_type_refcount(data_collection_model_nf_type_t *obj_nf_type)
{
    if (!obj_nf_type) return 0l;
    std::shared_ptr<NFType > &obj = *reinterpret_cast<std::shared_ptr<NFType >*>(obj_nf_type);
    return obj.use_count();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

