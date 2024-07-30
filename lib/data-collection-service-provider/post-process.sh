#!/bin/sh

scriptdir=`dirname "$0"`
scriptdir=`realpath "$scriptdir"`

file="$1"

case "$file" in
*.cc|*.cpp)
	sed -i '/StringValidator[^(]*("[^"]*", nullptr, "[^\/]/ {h;s/.*StringValidator[^(]*("[^"]*", nullptr, "//;s/\([^\\]\)".*/\1/;s/\\/\\\\/;s/^/\//;s/$/\//;H;x;s/\(StringValidator[^(]*("[^"]*", nullptr, "\)[^\n]*\("[^\n]*\)\n\(.*\)/\1\3\2/}' "$file"
	;;
esac
