# License: 5G-MAG Public License (v1.0)
# Copyright: (C) 2024 British Broadcasting Corporation
#
# For full license terms please see the LICENSE file distributed with this
# program. If this file is missing then the license can be retrieved from
# https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view

# Meson module fs and its functions like fs.hash_file require atleast meson 0.59.0 

project('rt-data-collection-application-function', 'c', 'cpp', 
    version : '0.1.0',
    license : '5G-MAG Public',
    meson_version : '>= 0.63.0',
    default_options : [
        'c_std=gnu89',
        'cpp_std=c++11',
    ],
)

open5gs_project=subproject('open5gs', required: true)

subdir('lib')
subdir('src')

systemd_path_cmd = find_program('systemd-path', required: false)
if systemd_path_cmd.found()
  subdir('systemd')
endif
