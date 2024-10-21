# License: 5G-MAG Public License (v1.0)
# Copyright: (C) 2024 British Broadcasting Corporation
#
# For full license terms please see the LICENSE file distributed with this
# program. If this file is missing then the license can be retrieved from
# https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view

libapp_dep = open5gs_project.get_variable('libapp_dep')
libcore_dep = open5gs_project.get_variable('libcore_dep')
libcrypt_dep = open5gs_project.get_variable('libcrypt_dep')
libsbi_dep = open5gs_project.get_variable('libsbi_dep')
libinc = open5gs_project.get_variable('libinc')

latest_apis = get_option('latest_apis')
fiveg_api_approval = get_option('fiveg_api_approval')
fiveg_api_release = get_option('fiveg_api_release')

fs = import('fs')

libdc_common_dist_sources = files('''
    utilities.h
    utilities.c
'''.split())


libdc_common_sources = libdc_common_dist_sources

libdc_common_libinc = include_directories('.')

libdccommon = static_library('common',
    sources : libdc_common_sources,
    include_directories : [libdc_common_libinc, libinc],
    dependencies : [libapp_dep.partial_dependency(compile_args: true, includes: true),
                    libcore_dep.partial_dependency(compile_args: true, includes: true),
                    libcrypt_dep.partial_dependency(compile_args: true, includes: true),
                    libsbi_dep.partial_dependency(compile_args: true, includes: true)],
    gnu_symbol_visibility : 'hidden',
    install : false)

libdccommon_dep = declare_dependency(
    link_with : libdccommon,
    include_directories : [libdc_common_libinc, libinc],
    dependencies : [libapp_dep,
                    libcore_dep,
                    libcrypt_dep,
		    libsbi_dep]
    )

