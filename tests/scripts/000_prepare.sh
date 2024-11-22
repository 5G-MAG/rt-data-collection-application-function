:
#
# 5G-MAG Reference Tools: DCAF regression test 0: Prepare the environment
# =======================================================================
#
# Author(s): David Waring <david.waring2@bbc.co.uk>
# Copyright: ©2024 British Broadcasting Corporation
#   License: 5G-MAG Public License v1.0
#
# For full license terms please see the LICENSE file distributed with this
# program. If this file is missing then the license can be retrieved from
# https://drive.google.com/file/d/1cinCiA778IErENZ3JN52VFW-1ffHpx7Z/view
#
# ============================================================================
# This script prepares the system to run the regression tests.
#
# This will start an Open5GS NRF and the DCAF with the local `local-dcaf.yaml`
# configuration and will remember the started process ids.
# 
# A function is provided to kill off the started NRF and DCAF processes.
#

start_network_functions() {
    export DB_URI="mongodb://localhost/open5gs"
    export http_proxy=
    export https_proxy=
    export HTTP_PROXY=
    export HTTPS_PROXY=

    inc total_count

    local build_dir=
    if [ -n "$MESON_BUILD_ROOT" ]; then
        build_dir="$MESON_BUILD_ROOT"
    else
        build_dir="$script_dir/../build"
    fi
    build_dir="$(realpath -e "$build_dir")"

    if [ -x "$build_dir/subprojects/open5gs/src/nrf/open5gs-nrfd" ]; then
	"$build_dir/subprojects/open5gs/src/nrf/open5gs-nrfd" -c "$script_dir/local-dcaf.yaml" > "nrf.log" 2>&1 &
	open5gs_nrf_pid=$!
    else
        log_error "Failed to find NRF executable, have the sources been built successfully?"
        exit 1
    fi

    if [ -x "$build_dir/src/data-collection-af/open5gs-dcafd" ]; then
	"$build_dir/src/data-collection-af/open5gs-dcafd" -c "$script_dir/local-dcaf.yaml" > "dcaf.log" 2>&1 &
	dcaf_pid=$!
    else
        stop_network_functions
        log_error "Failed to find DCAF executable, have the sources been built successfully?"
	exit 1
    fi

    sleep 3

    inc ok_count
}

stop_network_functions() {
    inc total_count
    if [ -n "$dcaf_pid" ]; then
        kill "$dcaf_pid"
	rm -f "dcaf.log"
    fi
    if [ -n "$open5gs_nrf_pid" ]; then
        kill "$open5gs_nrf_pid"
	rm -f "nrf.log"
    fi
    inc ok_count
}

start_network_functions
