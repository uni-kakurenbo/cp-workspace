#! /bin/bash

LIBRARY_PATH=$1

TARGET=$2
OUTPUT_PATH=$3

shift 3

ccache g++ -std=gnu++17 -fdiagnostics-color=always -Wall -Wextra -O2 -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -I"$LIBRARY_PATH/ac-library" -I"$LIBRARY_PATH/debug" -o "$OUTPUT_PATH" "$@" "$TARGET"
