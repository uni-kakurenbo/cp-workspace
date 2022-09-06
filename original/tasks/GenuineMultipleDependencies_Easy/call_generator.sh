#!/bin/bash

rm -fr ./testcases/in
rm -fr ./testcases/out
mkdir ./testcases/in
mkdir ./testcases/out

M=(
    # T MAX_N MAX_X

    "1 10 10"
    "1 10 10"
    "1 10 10"

    "1 50 50"
    "1 50 50"
    "1 50 50"

    "10 50 50"
    "10 50 50"
    "10 50 50"

    "100 50 50"
    "100 50 50"

    "300 50 50"
    "300 50 50"

    "500 50 50"
    "500 50 50"

    "1 100 100"
    "1 100 100"
    "1 100 100"
    "1 300 300"
    "1 300 300"
    "1 300 300"

    "10 10 10"
    "10 10 10"
    "10 10 10"
    "10 100 100"
    "10 100 100"
    "10 100 100"
    "10 300 300"
    "10 300 300"
    "10 300 300"

    "50 300 300"
    "50 300 300"

    "100 300 300"
    "100 300 300"

    "300 300 300"
    "300 300 300"

    "500 300 300"
    "500 300 300"
    "500 300 300"
    "500 300 300"
    "500 300 300"

)
# N=${#M[@]};

i=1;
for m in "${M[@]}"; do
    j="$i"
    if [ $j -lt 10 ]; then
        j="0$j"
    fi

    tmpfile1=$(mktemp --tmpdir=.)
    echo "testcase-$j $m" > "$tmpfile1";
    ./generator.exe < "$tmpfile1";
    rm "$tmpfile1"

    i=$((i + 1))
    echo $j;
done

./call_verifier.sh
./call_solver.sh ./solver.exe
