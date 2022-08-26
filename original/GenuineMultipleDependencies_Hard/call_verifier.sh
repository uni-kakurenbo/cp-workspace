#!/bin/bash

while read -rd $'\0' file; do
    echo "$file"
    ./verifier.exe < "$file" || exit 1
done < <(find testcases/in/ -mindepth 1 -maxdepth 1 -print0)
