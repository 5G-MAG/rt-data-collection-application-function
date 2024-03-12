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

subdir('include')

fs = import('fs')

libspdc_dist_sources = files('''
    data-collection.c
    data-access-profile.c
    data-reporting-condition.c
    data-reporting-rule.c
    data-sampling-rule.c

    context.h
    context.c
    data-collection-nf-service.h
    data-collection-nf-service.c
    data-collection-process.h
    data-collection-process.c
    data-reporting.h
    data-reporting.c
    data-reporting-configuration.h
    data-reporting-configuration.c
    data-reporting-process.h
    data-reporting-process.c
    data-reporting-provisioning.h
    data-reporting-provisioning.c
    hash.h
    hash.c
    lib-metadata.h
    lib-metadata.c
    response-cache-control.h
    response-cache-control.c
    server.h
    server.c
    utilities.h
    utilities.c
'''.split())

api_tag = latest_apis?'REL-'+fiveg_api_release:'TSG'+fiveg_api_approval+'-Rel'+fiveg_api_release

gen_5gspdc_sh = find_program('sh')
openapi_dep_file = meson.current_source_dir() / '.openapi.srcs'
message('Generating OpenAPI bindings for version '+api_tag+' of the 5G APIs...')
openapi_gen_result = run_command([gen_5gspdc_sh,'-c','"$MESON_SOURCE_ROOT/$MESON_SUBDIR/generator-libspdc" -M "'+openapi_dep_file+'" -b '+api_tag], capture: true, check: true)
libspdc_gen_sources = files(fs.read(openapi_dep_file).split())

libspdc_sources = libspdc_dist_sources + libspdc_gen_sources

libspdc_libinc = include_directories('.')

libspdc = library(libspdc_name,
    sources : libspdc_sources,
    c_args : '-DBUILD_DATA_COLLECTION_LIB',
    include_directories : [libspdc_libinc, libspdc_inc, libinc],
    gnu_symbol_visibility : 'hidden',
    dependencies : [libapp_dep,
                    libcore_dep,
                    libcrypt_dep,
		    libsbi_dep],
    version : libspdc_version,
    install : true)

libspdc_dep = declare_dependency(
    link_with : libspdc,
    include_directories : [libspdc_inc, libinc],
    dependencies : [libapp_dep,
                    libcore_dep,
                    libcrypt_dep,
		    libsbi_dep]
    )

