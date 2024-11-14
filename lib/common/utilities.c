/*
License: 5G-MAG Public License (v1.0)
Copyright: (C) 2024 British Broadcasting Corporation

For full license terms please see the LICENSE file distributed with this
program. If this file is missing then the license can be retrieved from
https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
*/

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ctype.h>
#include <time.h>

#include "utilities.h"

time_t str_to_time(const char *str_time)
{
    static time_t time;
    struct tm tm = {0};
    strptime(str_time, "%a, %d %b %Y %H:%M:%S %Z", &tm);
    time = mktime(&tm);
    return time;
}

const char *get_time(time_t time_epoch)
{
    struct tm *ts;
    static char buf[80];

    /* Format and print the time, "ddd yyyy-mm-dd hh:mm:ss zzz" */
    ts = localtime(&time_epoch);
    strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S %Z", ts);

    return buf;
}

time_t str_to_rfc3339_time(const char *str_time, struct timespec *to_fill)
{
    static struct timespec shared_ts;
    struct timespec *ts = &shared_ts;
    struct tm tm = {0};
    const char *rest;

    if (to_fill) ts = to_fill;

    if (str_time[0] == 'P') str_time++;
    rest = strptime(str_time, "%Y-%m-%dT%H:%M:%S", &tm);

    if (!rest) {
        if (to_fill) to_fill->tv_sec = to_fill->tv_nsec = 0;
        return 0;
    }

    ts->tv_nsec = 0;

    if (rest[0] == '.') {
        int i;
        rest++;
        /* take up to the first 9 digits of the fraction */
        for (i=0; i<9 && rest[0] >= '0' && rest[0] <= '9'; i++,rest++) {
            ts->tv_nsec = ts->tv_nsec * 10 + rest[0] - '0';
        }
        /* if we read 9 digits, but there's more, ignore them */
        while (i==9 && rest[0] >= '0' && rest[0] <= '9') rest++;
        /* pad to nanoseconds if we had less than 9 digits */
        for (; i<9; i++) {
            ts->tv_nsec = ts->tv_nsec * 10;
        }
    }
    
    if (rest[0] && rest[0] != 'Z') {
        if (to_fill) to_fill->tv_sec = to_fill->tv_nsec = 0;
        return 0;
    }

    ts->tv_sec = mktime(&tm);

    return ts->tv_sec;
}


const char *get_current_time(const char *format) {

    time_t rawtime;
    struct tm * ts;
    static char buf[80];
    
    time (&rawtime);
    ts = localtime (&rawtime);

   // strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S %Z", ts);

    strftime(buf, sizeof(buf), format, ts);
    return buf;
}

char *ogs_time_to_string(ogs_time_t timestamp, const char *format)
{
    struct tm tm;
    char datetime[128];

    ogs_localtime(ogs_time_sec(timestamp), &tm);
    ogs_strftime(datetime, sizeof(datetime), format, &tm);

    return ogs_msprintf("%s", datetime);
}

char *read_file(const char *filename)
{
    FILE *f = NULL;
    long len = 0;
    char *data_json = NULL;

    /* open in read binary mode */
    f = fopen(filename, "rb");
    if (f == NULL) {
        ogs_error("Unable to open file with name [%s]: %s", filename, strerror(errno));
        return NULL;
    }
    /* get the length */
    fseek(f, 0, SEEK_END);
    len = ftell(f);
    fseek(f, 0, SEEK_SET);
    data_json = (char*)malloc(len + 1);

    fread(data_json, 1, len, f);
    data_json[len] = '\0';
    fclose(f);
    return data_json;

}

char *epoch_to_datetime(char *epoch) {
    struct tm tm;
    static char buf[255];
    char *epoch_to_convert;

    memset(&tm, 0, sizeof(struct tm));
    epoch_to_convert = ogs_msprintf("%.10s", epoch);

    strptime(epoch_to_convert, "%s", &tm);
    strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S %Z", &tm);
    ogs_free(epoch_to_convert);
    return buf;
}

ogs_time_t get_time_from_timespec(struct timespec *ts)
{
    return ogs_time_from_sec(ts->tv_sec) + ts->tv_nsec / 1000UL;
}


int str_match(const char *line, const char *word_to_find) {

    char* p = strstr(line,word_to_find);
    if ((p==line) || (p!=NULL && !isalnum((unsigned char)p[-1])))
    {
        p += strlen(word_to_find);
        if (!isalnum((unsigned char)*p))
        {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

char *get_path(const char *file)
{
    char *path = NULL;
    char *file_dir = NULL;

    path = realpath(file, NULL);
    if(path == NULL){
        ogs_error("cannot find file with name[%s]: %s", file, strerror(errno));
        return NULL;
    }
    file_dir = data_collection_strdup(dirname(path));
    return file_dir;
}

char *rebase_path(const char *base, const char *file)
{
    ogs_debug("rebase_path(\"%s\", \"%s\")", base, file);
    if (file[0] != '/') {
        /* relative path - prefix with the directory of the base filename */
        char *base_path, *path;
        base_path = get_path(base);
        path = ogs_msprintf("%s/%s", base_path, file);
        ogs_free(base_path);
        return path;
    }
    /* absolute path - return a copy */
    return data_collection_strdup(file);
}

long int ascii_to_long(const char *str)
{
    char *endp = NULL;
    long int ret;

    ret = strtol(str, &endp, 10);
    if (endp == NULL || *endp != 0) {
        ogs_error("Failed to convert '%s' to an integer", str);
        ret = 0;
    }
    return ret;
}

uint16_t ascii_to_uint16(const char *str)
{
    long int ret;
    ret = ascii_to_long(str);
    if (ret > UINT16_MAX)
    {
        ogs_error("[%s] cannot be greater than [%d]", str, UINT16_MAX);
        ret = 0;
    }
    return ret;
}

char *check_http_content_type(ogs_sbi_http_message_t http, char *content_type)
{
    ogs_hash_index_t *hi;
    for (hi = ogs_hash_first(http.headers);
            hi; hi = ogs_hash_next(hi)) {
        if (!ogs_strcasecmp(ogs_hash_this_key(hi), OGS_SBI_CONTENT_TYPE)) {
            if (!ogs_strcasecmp(ogs_hash_this_val(hi), content_type)) {
                    return content_type;
            } else {
                const char *type;
                type = (const char *)ogs_hash_this_val(hi);
                ogs_error( "Unsupported Media Type: received type: %s, should have been %s", type, content_type);
                return NULL;
            }
        }
    }
    return NULL;
}


char *traceable_strdup(const char *str, const char *location)
{
    char *ptr = NULL;

    if (str) {
        ogs_thread_mutex_lock(ogs_mem_get_mutex());

        ptr = talloc_strdup(__ogs_talloc_core, str);
        ogs_expect(ptr);
        talloc_set_name_const(ptr, location);

        ogs_thread_mutex_unlock(ogs_mem_get_mutex());
    }

    return ptr;
}

ogs_lnode_t *list_node_create(void)
{
    ogs_lnode_t *node = NULL;

    node = ogs_calloc(1, sizeof(ogs_lnode_t));
    ogs_assert(node);

    if (node == NULL) {
        ogs_assert_if_reached();
        return NULL;
    }
    return node;
}

ogs_list_t *list_create(void)
{
    ogs_list_t *list;

    list = ogs_calloc(1, sizeof(ogs_list_t));
    ogs_assert(list);

    if (list == NULL) {
        ogs_assert_if_reached();
        return NULL;
    }
    ogs_list_init(list);
    return list;
}

ogs_list_t *list_clone(const ogs_list_t *to_copy, ogs_lnode_t *(*node_copy_fn)(const ogs_lnode_t *to_copy))
{
    if (!to_copy) return NULL;

    ogs_list_t *new_list = ogs_calloc(1, sizeof(ogs_list_t));
    ogs_assert(new_list);

    const ogs_lnode_t *existing_node;
    for (existing_node = ogs_list_first(to_copy); existing_node; existing_node = ogs_list_next((void*)existing_node)) {
        ogs_list_add(new_list, node_copy_fn(existing_node));
    }

    return new_list;
}

static void __timespec_normalise(struct timespec *ts)
{
    bool neg_time = ts->tv_sec < 0;
    while (ts->tv_nsec > 1000000000) {
        ts->tv_nsec -= 1000000000;
        if (neg_time) {
            ts->tv_sec--;
        } else {
            ts->tv_sec++;
        }
    }
    while (ts->tv_nsec < 0) {
        ts->tv_nsec += 1000000000;
        if (neg_time) {
            ts->tv_sec++;
        } else {
            ts->tv_sec--;
        }   
    }
}

void timespec_add(const struct timespec *a, const struct timespec *b, struct timespec *result /* [not-null, out] */)
{
    result->tv_sec = a->tv_sec + b->tv_sec;
    if (b->tv_sec < 0) {
        result->tv_nsec = a->tv_nsec - b->tv_nsec;
    } else {
        result->tv_nsec = a->tv_nsec + b->tv_nsec;
    }
    __timespec_normalise(result);
}

void timespec_sub(const struct timespec *a, const struct timespec *b, struct timespec *result /* [not-null, out] */)
{
    result->tv_sec = a->tv_sec - b->tv_sec;
    if (b->tv_sec < 0) {
        result->tv_nsec = a->tv_nsec + b->tv_nsec;
    } else {
        result->tv_nsec = a->tv_nsec - b->tv_nsec;
    }
    __timespec_normalise(result);
}

int timespec_cmp(const struct timespec *a, const struct timespec *b)
{
    if (a->tv_sec > b->tv_sec) return 1;
    if (a->tv_sec < b->tv_sec) return -1;
    if (a->tv_sec < 0) {
        if (a->tv_nsec > b->tv_nsec) return -1;
        if (a->tv_nsec < b->tv_nsec) return 1;
    } else {
        if (a->tv_nsec > b->tv_nsec) return 1;
        if (a->tv_nsec < b->tv_nsec) return -1;
    }
    return 0;
}

char *timespec_to_rfc3339_str(const struct timespec *wallclock_time)
{
    if (!wallclock_time) return data_collection_strdup("<null>");
    struct tm tm;
    char buf[128];
    gmtime_r(&wallclock_time->tv_sec, &tm);
    strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%S", &tm);
    char *next = buf + strlen(buf);
    if (wallclock_time->tv_nsec != 0) {
        next += sprintf(next, ".%09li", wallclock_time->tv_nsec);
        while (*--next == '0') *next='\0';
        next++;
    }
    *next++ = 'Z';
    *next++ = '\0';
    return data_collection_strdup(buf);
}

/* vim:ts=8:sts=4:sw=4:expandtab:
 */
