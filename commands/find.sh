#! /bin/bash

cd "$PWD" || exit 1
find . -iname "$1.*"
