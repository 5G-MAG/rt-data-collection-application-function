/*
License: 5G-MAG Public License (v1.0)
Author: David Waring
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
 */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "ogs-core.h"

#include "context.h"

#include "data-report-store.h"

/*****************************************************
 ***** Local declarations
 *****************************************************/
static bool ensure_directory(const char *path);
static int open_data_store_file(const char *data_reporting_session_id, const char *data_domain, const char *report_time, const char *format);
static bool file_exists(const char *filename);
/*****************************************************
 ***** Public functions
 *****************************************************/

bool data_collection_report_store(const char *data_reporting_session_id, const char *data_domain, const char *report_time, const char *format, const char *report_body)
{
    int fd;
    size_t body_len;

    fd = open_data_store_file(data_reporting_session_id, data_domain, report_time, format);
    
    if (fd < 0) {
        return false;
    }

    body_len = strlen(report_body);

    if (write(fd, report_body, body_len) != body_len) {
        ogs_error("Failed to write Data Report [%s] for Data Domain [%s]: %s", data_reporting_session_id?data_reporting_session_id:"", data_domain, strerror(errno));
        return false;
    }

    return true;
}

/*****************************************************
 ***** Private functions
 *****************************************************/

static bool ensure_directory(const char *path)
{
    struct stat statbuf;
    bool ret = false;

    if ((path[0] == '/' || path[0] == '.') && path[1] == '\0') return true;

    if (!stat(path, &statbuf)) {
        if ((statbuf.st_mode & S_IFMT) == S_IFDIR) {
            ret = true;
        }
    } else {
        /* path doesn't exist so ensure parent directory is present and try to create wanted directory */
        char *path_copy = ogs_strdup(path); 
        if (ensure_directory(dirname(path_copy)) && !mkdir(path, 0755)) {
            ret = true;
        }
        ogs_free(path_copy);
    }

    return ret;
}

static bool file_exists(const char *filename)
{
    struct stat buffer;
    return stat(filename, &buffer) == 0 ? true : false;
}

static int open_data_store_file(const char *data_reporting_session_id, const char *data_domain, const char *report_time, const char *format)
{
    int fd = -1;
    char *filepath = NULL;
    char *reportdir = NULL;
    const char *report_root = NULL;
    int counter = 0;

    report_root = data_collection_self()->config.data_collection_dir;
    if (!report_root) return -1;

    // {dataReportsDirectory}/reporting-session_{sessionId}/{dataDomain}_{reportProcessingTimestamp}.{counter}.json

    reportdir = ogs_msprintf("%s/reporting-session%s%s", report_root, data_reporting_session_id?"_":"", data_reporting_session_id?data_reporting_session_id:"");

    if (!ensure_directory(reportdir)) {
        ogs_error("Unable to create report directory %s", reportdir);
        ogs_free(reportdir);
        return -1;
    }

    do {

	if(filepath) ogs_free(filepath);     
        filepath = ogs_msprintf("%s/%s%s%s_%s.%d.%s", reportdir, data_domain, data_reporting_session_id?"_":"", data_reporting_session_id?data_reporting_session_id:"", report_time, counter, format);
        counter++;
    } while(file_exists(filepath));

    ogs_free(reportdir);

    fd = open(filepath, O_CREAT|O_WRONLY|O_EXCL, 0664);

    if (fd < 0) {
        ogs_error("Unable to create %s for writing: %s", filepath, strerror(errno));
    }

    ogs_free(filepath);

    return fd;
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
