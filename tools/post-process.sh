#!/bin/sh

scriptdir=`dirname "$0"`
scriptdir=`realpath "$scriptdir"`

file="$1"

bnfile=`basename "$file"`
internal_fns="$scriptdir/snippets/internal/${bnfile}"
public_fns="$scriptdir/snippets/public/${bnfile}"

sed -i '/#include </ d' "$file"

if [ -f "$internal_fns" ]; then
    internal_line=`grep -nF 'Internal library protected functions' "$file"|sed 's/:.*//'`
    tfile="$file.tmp"
    head -n "$internal_line" "$file" > "$tfile"
    echo '' >> "$tfile"
    cat "$internal_fns" >> "$tfile"
    tail -n +"$((internal_line+1))" "$file" >> "$tfile"
    chmod --reference="$file" "$tfile"
    mv -f "$tfile" "$file"
fi

if [ -f "$public_fns" ]; then
    internal_line=`grep -nF 'Internal library protected functions' "$file"|sed 's/:.*//'`
    tfile="$file.tmp"
    head -n "$((internal_line-1))" "$file" > "$tfile"
    cat "$public_fns" >> "$tfile"
    echo '' >> "$tfile"
    tail -n +"$internal_line" "$file" >> "$tfile"
    chmod --reference="$file" "$tfile"
    mv -f "$tfile" "$file"
fi

if [ "${file##*.}" = "cpp" ]; then
    ln "$file" "${file%.cpp}.cc"
fi
