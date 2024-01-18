# License: 5G-MAG Public License (v1.0)
# Copyright: (C) 2022-2024 British Broadcasting Corporation
#
# For full license terms please see the LICENSE file distributed with this
# program. If this file is missing then the license can be retrieved from
# https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view


libapp_dep = open5gs_project.get_variable('libapp_dep')
libcrypt_dep = open5gs_project.get_variable('libcrypt_dep')
libsbi_dep = open5gs_project.get_variable('libsbi_dep')
libsbi_openapi_dep = open5gs_project.get_variable('libsbi_openapi_dep')
open5gs_sysconfdir = open5gs_project.get_variable('open5gs_sysconfdir')
srcinc = open5gs_project.get_variable('srcinc')
libdir = open5gs_project.get_variable('libdir')
python3_exe = open5gs_project.get_variable('python3_exe')
mkdir_p = open5gs_project.get_variable('mkdir_p')
install_conf = open5gs_project.get_variable('install_conf')
sbi_openapi_inc = open5gs_project.get_variable('libsbi_openapi_model_inc')

fs = import('fs')

libdcaf_dist_sources = files('''
    init.h
    init.c
    event.c
    event.h
    dcaf-sm.h
    dcaf-sm.c
    sbi-path.h
    sbi-path.c
'''.split())


version_conf = configuration_data()
version_conf.set_quoted('DCAF_NAME', meson.project_name())
version_conf.set_quoted('DCAF_VERSION', meson.project_version())
version_conf.set_quoted('FIVEG_API_RELEASE', fiveg_api_release)
libdcaf_gen_sources = [configure_file(output : 'dcaf-version.h', configuration : version_conf)]

libdcaf_sources = libdcaf_dist_sources + libdcaf_gen_sources

libdcaf = static_library('dcaf',
    sources : libdcaf_sources,
    include_directories : sbi_openapi_inc,
    dependencies : [libsbi_dep,
                    libsbi_openapi_dep,
                    libapp_dep,
                    libspdc_dep,
                    libcrypt_dep],
    install : false)

libdcaf_dep = declare_dependency(
    link_with : libdcaf,
    dependencies : [libsbi_dep,
                    libcore_dep,
                    libsbi_openapi_dep,
                    libapp_dep,
                    libspdc_dep,
                    libcrypt_dep])

dcaf_sources = files('''
    app.c
'''.split()) + open5gs_project.get_variable('app_main_c')

dcaf_config_source = '''
    dcaf.yaml
'''.split()

dcaf_include = include_directories('.')

executable('open5gs-dcafd',
    sources : dcaf_sources,
    c_args : '-DDEFAULT_CONFIG_FILENAME="@0@/dcaf.yaml"'.format(open5gs_sysconfdir),
    include_directories : [srcinc, libspdc_inc],
    dependencies : [libdcaf_dep],
    install_rpath : libdir,
    install : true)

