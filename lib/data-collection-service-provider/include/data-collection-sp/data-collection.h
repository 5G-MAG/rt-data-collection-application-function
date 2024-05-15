/*
 * License: 5G-MAG Public License (v1.0)
 * Copyright: (C) 2024 British Broadcasting Corporation
 *
 * For full license terms please see the LICENSE file distributed with this
 * program. If this file is missing then the license can be retrieved from
 * https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#ifndef DATA_COLLECTION_SVC_PRODUCER_H
#define DATA_COLLECTION_SVC_PRODUCER_H

#include <stdint.h>

#ifdef BUILD_DATA_COLLECTION_LIB
    #if defined _WIN32 || defined __CYGWIN__
        #ifdef __GNUC__
            #define DATA_COLLECTION_SVC_PRODUCER_API __attribute__ ((dllexport))
        #else
            #define DATA_COLLECTION_SVC_PRODUCER_API __declspec(dllexport)
        #endif
    #else
        #if __GNUC__ >= 4
            #define DATA_COLLECTION_SVC_PRODUCER_API __attribute__ ((visibility ("default")))
        #else
            #define DATA_COLLECTION_SVC_PRODUCER_API
        #endif
    #endif
#else
    #if defined _WIN32 || defined __CYGWIN__
        #ifdef __GNUC__
            #define DATA_COLLECTION_SVC_PRODUCER_API __attribute__ ((dllimport))
        #else
            #define DATA_COLLECTION_SVC_PRODUCER_API __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
        #endif
    #else
        #define DATA_COLLECTION_SVC_PRODUCER_API
    #endif
#endif

#define DATA_COLLECTION_FEATURE_BIT(N) (UINT64_C(1)<<((N)-1))

#define INCLUDED_FROM_DATA_COLLECTION_H 1

#include "macros.h"
#include "civic-address.h"
#include "event-exposure.h"
#include "data-reporting.h"
#include "data-reporting-configuration.h"
#include "data-reporting-provisioning.h"
#include "data-sampling-rule.h"
#include "data-reporting-rule.h"
#include "data-reporting-condition.h"
#include "data-access-profile.h"
#include "lifecycle.h"

#undef INCLUDED_FROM_DATA_COLLECTION_H

#endif /* DATA_COLLECTION_SVC_PRODUCER_H */
