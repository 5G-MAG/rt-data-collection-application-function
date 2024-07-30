#ifndef _DATA_COLLECTION_CIVIC_ADDRESS_H_
#define _DATA_COLLECTION_CIVIC_ADDRESS_H_

/**********************************************************************************************************************************
 * CivicAddress - Public C interface to the CivicAddress object
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

typedef struct data_collection_model_civic_address_s data_collection_model_civic_address_t;

    
DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_create();

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_create_copy(const data_collection_model_civic_address_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_create_move(data_collection_model_civic_address_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_copy(data_collection_model_civic_address_t *civic_address, const data_collection_model_civic_address_t *other);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_move(data_collection_model_civic_address_t *civic_address, data_collection_model_civic_address_t *other);

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_model_civic_address_free(data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API cJSON *data_collection_model_civic_address_toJSON(const data_collection_model_civic_address_t *civic_address, bool as_request);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_fromJSON(cJSON *json, bool as_request, char **error_reason, char **error_class, char **error_parameter);

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_civic_address_is_equal_to(const data_collection_model_civic_address_t *civic_address, const data_collection_model_civic_address_t *other_civic_address);


DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_country(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_country(data_collection_model_civic_address_t *civic_address, const char* p_country);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_country_move(data_collection_model_civic_address_t *civic_address, char* p_country);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a1(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a1(data_collection_model_civic_address_t *civic_address, const char* p_a1);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a1_move(data_collection_model_civic_address_t *civic_address, char* p_a1);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a2(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a2(data_collection_model_civic_address_t *civic_address, const char* p_a2);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a2_move(data_collection_model_civic_address_t *civic_address, char* p_a2);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a3(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a3(data_collection_model_civic_address_t *civic_address, const char* p_a3);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a3_move(data_collection_model_civic_address_t *civic_address, char* p_a3);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a4(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a4(data_collection_model_civic_address_t *civic_address, const char* p_a4);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a4_move(data_collection_model_civic_address_t *civic_address, char* p_a4);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a5(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a5(data_collection_model_civic_address_t *civic_address, const char* p_a5);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a5_move(data_collection_model_civic_address_t *civic_address, char* p_a5);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_a6(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a6(data_collection_model_civic_address_t *civic_address, const char* p_a6);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_a6_move(data_collection_model_civic_address_t *civic_address, char* p_a6);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_prd(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prd(data_collection_model_civic_address_t *civic_address, const char* p_prd);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prd_move(data_collection_model_civic_address_t *civic_address, char* p_prd);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pod(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pod(data_collection_model_civic_address_t *civic_address, const char* p_pod);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pod_move(data_collection_model_civic_address_t *civic_address, char* p_pod);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_sts(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_sts(data_collection_model_civic_address_t *civic_address, const char* p_sts);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_sts_move(data_collection_model_civic_address_t *civic_address, char* p_sts);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_hno(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hno(data_collection_model_civic_address_t *civic_address, const char* p_hno);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hno_move(data_collection_model_civic_address_t *civic_address, char* p_hno);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_hns(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hns(data_collection_model_civic_address_t *civic_address, const char* p_hns);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_hns_move(data_collection_model_civic_address_t *civic_address, char* p_hns);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_lmk(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_lmk(data_collection_model_civic_address_t *civic_address, const char* p_lmk);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_lmk_move(data_collection_model_civic_address_t *civic_address, char* p_lmk);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_loc(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_loc(data_collection_model_civic_address_t *civic_address, const char* p_loc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_loc_move(data_collection_model_civic_address_t *civic_address, char* p_loc);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_nam(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_nam(data_collection_model_civic_address_t *civic_address, const char* p_nam);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_nam_move(data_collection_model_civic_address_t *civic_address, char* p_nam);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pc(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pc(data_collection_model_civic_address_t *civic_address, const char* p_pc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pc_move(data_collection_model_civic_address_t *civic_address, char* p_pc);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_bld(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_bld(data_collection_model_civic_address_t *civic_address, const char* p_bld);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_bld_move(data_collection_model_civic_address_t *civic_address, char* p_bld);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_unit(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_unit(data_collection_model_civic_address_t *civic_address, const char* p_unit);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_unit_move(data_collection_model_civic_address_t *civic_address, char* p_unit);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_flr(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_flr(data_collection_model_civic_address_t *civic_address, const char* p_flr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_flr_move(data_collection_model_civic_address_t *civic_address, char* p_flr);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_room(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_room(data_collection_model_civic_address_t *civic_address, const char* p_room);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_room_move(data_collection_model_civic_address_t *civic_address, char* p_room);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_plc(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_plc(data_collection_model_civic_address_t *civic_address, const char* p_plc);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_plc_move(data_collection_model_civic_address_t *civic_address, char* p_plc);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pcn(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pcn(data_collection_model_civic_address_t *civic_address, const char* p_pcn);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pcn_move(data_collection_model_civic_address_t *civic_address, char* p_pcn);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pobox(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pobox(data_collection_model_civic_address_t *civic_address, const char* p_pobox);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pobox_move(data_collection_model_civic_address_t *civic_address, char* p_pobox);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_addcode(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_addcode(data_collection_model_civic_address_t *civic_address, const char* p_addcode);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_addcode_move(data_collection_model_civic_address_t *civic_address, char* p_addcode);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_seat(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_seat(data_collection_model_civic_address_t *civic_address, const char* p_seat);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_seat_move(data_collection_model_civic_address_t *civic_address, char* p_seat);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rd(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rd(data_collection_model_civic_address_t *civic_address, const char* p_rd);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rd_move(data_collection_model_civic_address_t *civic_address, char* p_rd);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rdsec(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsec(data_collection_model_civic_address_t *civic_address, const char* p_rdsec);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsec_move(data_collection_model_civic_address_t *civic_address, char* p_rdsec);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rdbr(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdbr(data_collection_model_civic_address_t *civic_address, const char* p_rdbr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdbr_move(data_collection_model_civic_address_t *civic_address, char* p_rdbr);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_rdsubbr(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsubbr(data_collection_model_civic_address_t *civic_address, const char* p_rdsubbr);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_rdsubbr_move(data_collection_model_civic_address_t *civic_address, char* p_rdsubbr);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_prm(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prm(data_collection_model_civic_address_t *civic_address, const char* p_prm);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_prm_move(data_collection_model_civic_address_t *civic_address, char* p_prm);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_pom(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pom(data_collection_model_civic_address_t *civic_address, const char* p_pom);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_pom_move(data_collection_model_civic_address_t *civic_address, char* p_pom);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_usage_rules(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_usage_rules(data_collection_model_civic_address_t *civic_address, const char* p_usage_rules);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_usage_rules_move(data_collection_model_civic_address_t *civic_address, char* p_usage_rules);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_method(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_method(data_collection_model_civic_address_t *civic_address, const char* p_method);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_method_move(data_collection_model_civic_address_t *civic_address, char* p_method);

DATA_COLLECTION_SVC_PRODUCER_API const char* data_collection_model_civic_address_get_provided_by(const data_collection_model_civic_address_t *civic_address);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_provided_by(data_collection_model_civic_address_t *civic_address, const char* p_provided_by);

DATA_COLLECTION_SVC_PRODUCER_API data_collection_model_civic_address_t *data_collection_model_civic_address_set_provided_by_move(data_collection_model_civic_address_t *civic_address, char* p_provided_by);

/* lnode helper for generating ogs_list_t nodes's of type CivicAddress */
DATA_COLLECTION_SVC_PRODUCER_API data_collection_lnode_t *data_collection_model_civic_address_make_lnode(data_collection_model_civic_address_t *civic_address);

/***** Internal library protected functions *****/

#ifdef __cplusplus
}
#endif

/* vim:ts=8:sts=4:sw=4:expandtab:
 */

#endif /* ifndef _DATA_COLLECTION_CIVIC_ADDRESS_H_ */

