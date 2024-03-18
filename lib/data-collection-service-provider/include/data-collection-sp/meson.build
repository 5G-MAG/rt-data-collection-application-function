# License: 5G-MAG Public License (v1.0)
# Copyright: (C) 2024 British Broadcasting Corporation
#
# For full license terms please see the LICENSE file distributed with this
# program. If this file is missing then the license can be retrieved from
# https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view

libspdc_version_conf = configuration_data()
libspdc_version_conf.set_quoted('DATA_COLLECTION_NAME', 'lib' + libspdc_name)
libspdc_version_conf.set_quoted('DATA_COLLECTION_VERSION', meson.project_version())
libspdc_version_conf.set_quoted('FIVEG_API_RELEASE', fiveg_api_release)
libspdc_version_conf.set('DATA_COLLECTION_MAJOR', libspdc_version_major)
libspdc_version_conf.set('DATA_COLLECTION_MINOR', libspdc_version_minor)
libspdc_version_conf.set('DATA_COLLECTION_MICRO', libspdc_version_micro)
libspdc_version_conf_source = configure_file(input: 'data-collection-version.h.in',
                                     output: 'data-collection-version.h',
                                     install: true, install_dir: get_option('prefix') / 'include' / 'data-collection-sp',
                                     configuration: libspdc_version_conf)
