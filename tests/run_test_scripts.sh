#!/bin/sh

dcaf_sbi_address="127.0.0.32:7777"
dcaf_provisioning_address="127.0.0.33:7777"
dcaf_applicationServerDataReporting_address="127.0.0.34:7777"
dcaf_directDataReporting_address="127.0.0.35:7777"
dcaf_indirectDataReporting_address="127.0.0.36:7777"
dcaf_eventConsumerApplicationFunctionEventExposure_address="127.0.0.37:7777"
dcaf_networkDataAnalyticsFunctionEventExposure_address="127.0.0.38:7777"

script_dir=`dirname "$0"`
script_dir=`realpath "$script_dir"`

data_dir="$script_dir/data"
tests_dir="$script_dir/scripts"

total_ok=0
total_total=0
total_fail=0
total_skip=0

colour_red=
colour_green=
colour_reset=

tmp_headers_file=`mktemp -p /tmp dcaf_tests_hdrs.XXXXXXXX`

case $TERM in
*color)
    colour_red="\\e[31m"
    colour_green="\\e[32m"
    colour_reset="\\e[0m"
    ;;
esac

inc() {
   declare -n vname="$1"
   incre="${2:-1}"
   vname=$((vname + incre))
}

log_error() {
    echo -e "(${colour_red}E${colour_reset}): $@" >&2
}

log_info() {
    echo -e "(${colour_green}I${colour_reset}): $@" >&2
}

http_get() {
    response=`curl -s --http2-prior-knowledge --fail-with-body -w "%output{$tmp_headers_file}resp_statuscode=%{response_code}\n" "http://${1}${2}"`
    . "$tmp_headers_file"
    rm -f "$tmp_headers_file"
}

http_post_file() {
    response=`curl -s --http2-prior-knowledge --fail-with-body -w "%output{$tmp_headers_file}resp_location=\"%header{location}\"\nresp_content_type=\"%header{content-type}\"\nresp_statuscode=%{response_code}\n" -H 'Content-Type: application/json' --data-binary=@"$3" "http://${1}${2}"`
    . "$tmp_headers_file"
    rm -f "$tmp_headers_file"
}

http_post_json() {
    response=`curl -s --http2-prior-knowledge --fail-with-body -w "%output{$tmp_headers_file}resp_location=\"%header{location}\"\nresp_content_type=\"%header{content-type}\"\nresp_statuscode=%{response_code}\n" -H 'Content-Type: application/json' --data "$3" "http://${1}${2}"`
    . "$tmp_headers_file"
    rm -f "$tmp_headers_file"
}

http_delete() {
    response=`curl -s --http2-prior-knowledge --fail-with-body -X DELETE -w "%output{$tmp_headers_file}resp_content_type=\"%header{content-type}\"\nresp_statuscode=%{response_code}\n" "http://${1}${2}"`
    . "$tmp_headers_file"
    rm -f "$tmp_headers_file"
}

for t in "${tests_dir}"/*.sh; do
    testname=`basename "$t" .sh`
    ok_count=0
    fail_count=0
    total_count=0
    skip_count=0
    . $t
    if [ "$fail_count" -gt 0 ]; then
        log_error "${testname}: $fail_count/$total_count failed"
    fi
    if [ "$skip_count" -gt 0 ]; then
        log_info "${testname}: $skip_count skipped, $ok_count/$total_count passed"
    else
        log_info "${testname}: $ok_count/$total_count passed"
    fi
    inc total_ok $ok_count
    inc total_fail $fail_count
    inc total_total $total_count
    inc total_skip $skip_count
done

if [ "$total_fail" -gt 0 ]; then
    log_error "Overall ${colour_green}$total_ok passed${colour_reset}, ${colour_red}$total_fail failed${colour_reset}, $total_skip skipped out of $total_total tests"
    exit 1
else
    log_info "Overall ${colour_green}$total_ok passed${colour_reset} with no failures ($total_skip tests skipped)"
fi

exit 0
