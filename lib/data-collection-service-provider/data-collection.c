/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "data-collection-version.h"
#include "data-collection.h"
#include "context.h"
#include "data-collection-process.h"
#include "data-collection-nf-service.h"
#include "utils.h"

const char * const data_collection_version_full_string()
{
    const char *version_full_string = ogs_msprintf("%s-%s", DATA_COLLECTION_NAME, DATA_COLLECTION_VERSION);
    return version_full_string;
}

const char * const data_collection_version_string()
{
 return (const char *)DATA_COLLECTION_VERSION;
}

unsigned int data_collection_version_major()
{
    return DATA_COLLECTION_MAJOR;
}

unsigned int data_collection_version_minor()
{
    return DATA_COLLECTION_MINOR;	
}


unsigned int data_collection_version_micro()
{
    return DATA_COLLECTION_MICRO;	
}



int data_collection_initialise(const data_collection_configuration_t* const configuration)
{
    return _data_collection_initialise(configuration);

}

int data_collection_set_nf_services(){
    return _data_collection_set_nf_services();
}

bool data_collection_process_event(ogs_event_t *e)
{
    return _data_collection_process_event(e);
}

void data_collection_finalise(){
    data_collection_context_final();
}

/******************* Private functions ********************/


/* vim:ts=8:sts=4:sw=4:expandtab:
 */
