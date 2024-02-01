/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#include "data-collection-service-producer.h"
#include "context.h"
#include "data-collection-process.h"
#include "utils.h"


int data_collection_initialise(const data_collection_configuration_t* const configuration)
{
    return _data_collection_initialise(configuration);

}


bool data_collection_process_event(ogs_event_t *e)
{
    return _data_collection_process_event(e);
}

/******************* Private functions ********************/


/* vim:ts=8:sts=4:sw=4:expandtab:
 */
