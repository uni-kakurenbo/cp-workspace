#!/bin/bash

# rm -fr ./testcases/in
# rm -fr ./testcases/out
# mkdir ./testcases/in
# mkdir ./testcases/out

M=(10 50 100 300 500 1000 5000 10000 50000 100000 200000 200000 300000 400000 400000 400000 400000 400000)
N=${#M[@]};

i=1;
for m in "${M[@]}"; do
    # if [ $i -lt 10 ]; then
    #     j="0$i"
    # fi
    tmpfile1=$(mktemp --tmpdir=.)
    tmpfile2=$(mktemp --tmpdir=.)
    tmpfile3=$(mktemp --tmpdir=.)
    tmpfile4=$(mktemp --tmpdir=.)
    # echo "2_random_killer_float-$j $m" > "$tmpfile1";
    # echo "2_random_killer_double-$j $m" > "$tmpfile2";
    # echo "2_random-small$j $m 100 100" > "$tmpfile3";
    # echo "2_random-large$j $m 1000000000 1000" > "$tmpfile4";
    j=$((N*2+i));
    if [ $j -lt 10 ]; then
        j="0$j"
    fi
    echo "testcase-$j $m" > "$tmpfile1";

    j=$((N*3+i));
    if [ $j -lt 10 ]; then
        j="0$j"
    fi
    echo "testcase-$j $m" > "$tmpfile2";

    j=$((N*0+i));
    if [ $j -lt 10 ]; then
        j="0$j"
    fi
    echo "testcase-$j $m 100 100" > "$tmpfile3";

    j=$((N*1+i));
    if [ $j -lt 10 ]; then
        j="0$j"
    fi
    echo "testcase-$j $m 1000000000 1000" > "$tmpfile4";

    ./generator-killer-float.exe < "$tmpfile1";
    ./generator-killer-double.exe < "$tmpfile2";
    ./generator-normal.exe < "$tmpfile3";
    ./generator-normal.exe < "$tmpfile4";

    rm "$tmpfile1"
    rm "$tmpfile2"
    rm "$tmpfile3"
    rm "$tmpfile4"
    i=$((i + 1))
    echo $j;
done

./call_verifier.sh
