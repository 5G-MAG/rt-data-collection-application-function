# License: 5G-MAG Public License (v1.0)
# Copyright: (C) 2024 British Broadcasting Corporation
#
# For full license terms please see the LICENSE file distributed with this
# program. If this file is missing then the license can be retrieved from
# https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view

libspdc_name = 'spdc'
libspdc_version_major = 0
libspdc_version_minor = 1
libspdc_version_micro = 0

libspdc_version = '@0@.@1@.@2@'.format(libspdc_version_major,libspdc_version_minor,libspdc_version_micro)

libspdc_inst_includes = files('''
    data-collection-sp/data-collection.h
    data-collection-sp/data-collection-lifecycle.h
    data-collection-sp/data-collection-data-reporting.h
    data-collection-sp/data-collection-data-reporting-provisioning.h
    data-collection-sp/data-collection-event-exposure.h
'''.split())

subdir('data-collection-sp')

libspdc_inc = include_directories('.')

libspdc_includes = install_headers(libspdc_inst_includes, preserve_path: true)
