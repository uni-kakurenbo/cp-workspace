#!/bin/bash

# rm -fr ./testcases/in
# rm -fr ./testcases/out
# mkdir ./testcases/in
# mkdir ./testcases/out

M=(10 10 10 50 50 50 100 100 100 300 500 1000 1000 1000 5000 5000 5000 10000 10000 10000 10000 10000 50000 50000 50000 100000 100000 100000 200000 200000 200000 200000 200000 200000 200000 200000 200000)

i=1;
for m in "${M[@]}"; do
    if [ $i -lt 10 ]; then
        j="0$i"
    else
        j=$i
    fi
    tmpfile=$(mktemp --tmpdir=.)
    echo "2_random-$j $m" > "$tmpfile";
    ./generator.exe < "$tmpfile";
    rm "$tmpfile"
    i=$((i + 1))
    echo $j;
done
