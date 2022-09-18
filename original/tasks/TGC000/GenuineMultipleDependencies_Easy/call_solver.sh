#!/bin/bash

while read -rd $'\0' file; do
    echo "$file"
    # shellcheck disable=SC2094
    $1 < "$file" > "testcases/out/$(basename "$file")" || exit 1
done < <(find testcases/in/ -mindepth 1 -maxdepth 1 -print0)
