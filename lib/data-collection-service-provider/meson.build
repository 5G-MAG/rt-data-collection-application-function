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

library_name = 'libspdc'
libspdc_version_major = 0
libspdc_version_minor = 1
libspdc_version_micro = 0

libspdc_version = '@0@.@1@.@2@'.format(libspdc_version_major,libspdc_version_minor,libspdc_version_micro)

latest_apis = get_option('latest_apis')
fiveg_api_approval = get_option('fiveg_api_approval')
fiveg_api_release = get_option('fiveg_api_release')

fs = import('fs')

libspdc_dist_sources = files('''
    data-collection.h
    data-collection.c
    context.h
    context.c
    data-collection-nf-service.h
    data-collection-nf-service.c
    data-collection-process.h
    data-collection-process.c
    response-cache-control.h
    response-cache-control.c
    utilities.h
    utilities.c
'''.split())

api_tag = latest_apis?'REL-'+fiveg_api_release:'TSG'+fiveg_api_approval+'-Rel'+fiveg_api_release

gen_5gspdc_sh = find_program('sh')
openapi_dep_file = meson.current_source_dir() / '.openapi.srcs'
message('Generating OpenAPI bindings for version '+api_tag+' of the 5G APIs...')
openapi_gen_result = run_command([gen_5gspdc_sh,'-c','"$MESON_SOURCE_ROOT/$MESON_SUBDIR/generator-libspdc" -M "'+openapi_dep_file+'" -b '+api_tag], capture: true, check: true)
libspdc_gen_sources = files(fs.read(openapi_dep_file).split())

version_conf = configuration_data()
version_conf.set_quoted('DATA_COLLECTION_NAME', library_name)
version_conf.set_quoted('DATA_COLLECTION_VERSION', meson.project_version())
version_conf.set_quoted('FIVEG_API_RELEASE', fiveg_api_release)
version_conf.set('DATA_COLLECTION_MAJOR', libspdc_version_major)
version_conf.set('DATA_COLLECTION_MINOR', libspdc_version_minor)
version_conf.set('DATA_COLLECTION_MICRO', libspdc_version_micro)
libspdc_gen_sources += [configure_file(input:'data-collection-version.h.in',output : 'data-collection-version.h', configuration : version_conf)]

libspdc_sources = libspdc_dist_sources + libspdc_gen_sources

libspdc_inc = include_directories('.')

libspdc = library('spdc',
    sources : libspdc_sources,
    c_args : '-DBUILD_DATA_COLLECTION_LIB',
    include_directories : [libspdc_inc, libinc],
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

