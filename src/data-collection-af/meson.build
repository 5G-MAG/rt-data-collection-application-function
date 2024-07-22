# License: 5G-MAG Public License (v1.0)
# Copyright: (C) 2024 British Broadcasting Corporation
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
app_type = 'DCAF'


fs = import('fs')

libdcaf_dist_sources = files('''
    context.c
    context.h
    event.c
    event.h
    init.h
    init.c
    dcaf-sm.h
    dcaf-sm.c
    sbi-path.h
    sbi-path.c
    hash.h
    hash.c
    communication-record.h
    communication-record.c
    event-notification.h
    event-notification.c
    regexpr.h
    regexpr.c
'''.split())

version_conf = configuration_data()
version_conf.set_quoted('DCAF_NAME', meson.project_name())
version_conf.set_quoted('DCAF_VERSION', meson.project_version())
version_conf.set_quoted('DCAF_TYPE', app_type)
libdcaf_gen_sources = [configure_file(output : 'dcaf-version.h', configuration : version_conf)]

api_tag = latest_apis?'REL-'+fiveg_api_release:'TSG'+fiveg_api_approval+'-Rel'+fiveg_api_release

gen_dcaf_sh = find_program('sh')
openapi_dep_file = meson.current_source_dir() / '.openapi.srcs'
message('Generating OpenAPI bindings for version '+api_tag+' of the 5G APIs...')
openapi_gen_result = run_command([gen_dcaf_sh,'-c','"$MESON_SOURCE_ROOT/$MESON_SUBDIR/generator-dcaf" -M "'+openapi_dep_file+'" -b '+api_tag], capture: true, check: true)
libdacf_api_sources = files(fs.read(openapi_dep_file).split())

libdcaf_gen_include = include_directories('openapi/include')

libdcaf_sources = libdcaf_dist_sources + libdcaf_gen_sources + libdacf_api_sources

libdcaf = static_library('dcaf',
    sources : libdcaf_sources,
    include_directories : [libdcaf_gen_include, sbi_openapi_inc, libdc_common_libinc],
    link_whole : [libdccommon],
    dependencies : [libsbi_dep,
                    libsbi_openapi_dep,
                    libapp_dep,
		    libspdc_dep,
                    libcrypt_dep],
    install : false)

libdcaf_dep = declare_dependency(
    link_with : libdcaf,
    dependencies : [libsbi_dep,
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

meson.add_install_script(python3_exe, '-c', mkdir_p.format(open5gs_sysconfdir))
conf_configuration = configuration_data()
conf_configuration.set('data-collection-dir', get_option('prefix') / get_option('localstatedir') / 'log' / 'open5gs' / 'reports')
foreach conf_file : dcaf_config_source
    gen = configure_file(input : conf_file + '.in', configuration : conf_configuration, output : conf_file)
    meson.add_install_script(python3_exe, '-c', install_conf.format(gen, open5gs_sysconfdir))
endforeach
