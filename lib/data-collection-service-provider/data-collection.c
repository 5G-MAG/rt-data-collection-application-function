/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "data-collection-sp/data-collection-version.h"
#include "context.h"
#include "data-collection-process.h"
#include "data-collection-nf-service.h"
#include "utils.h"

#include "data-collection-sp/data-collection.h"

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_version_full_string()
{
    static const char version_full_string[] = DATA_COLLECTION_NAME "-" DATA_COLLECTION_VERSION;
    return version_full_string;
}

DATA_COLLECTION_SVC_PRODUCER_API const char *data_collection_version_string()
{
    return DATA_COLLECTION_VERSION;
}

DATA_COLLECTION_SVC_PRODUCER_API unsigned int data_collection_version_major()
{
    return DATA_COLLECTION_MAJOR;
}

DATA_COLLECTION_SVC_PRODUCER_API unsigned int data_collection_version_minor()
{
    return DATA_COLLECTION_MINOR;
}


DATA_COLLECTION_SVC_PRODUCER_API unsigned int data_collection_version_micro()
{
    return DATA_COLLECTION_MICRO;
}

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_initialise(const data_collection_configuration_t* const configuration)
{
    return _data_collection_initialise(configuration);

}

DATA_COLLECTION_SVC_PRODUCER_API int data_collection_set_nf_services(){
    return _data_collection_set_nf_services();
}

DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_process_event(ogs_event_t *e)
{
    return _data_collection_process_event(e);
}

DATA_COLLECTION_SVC_PRODUCER_API void data_collection_finalise(){
    data_collection_context_final();
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
