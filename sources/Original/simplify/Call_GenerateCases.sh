#!/bin/bash

T=(50000 50000 70000 80000 80000 100000 100000 100000 100000 100000 100000 100000 100000 100000)

i=1;
for t in "${T[@]}"; do
    if [ $i -lt 10 ]; then
        j="0$i"
    else
        j=$i
    fi
    tmpfile=$(mktemp --tmpdir=.)
    echo "2_random_small-$j $t 10 5" > "$tmpfile";
    ./GenerateCases.exe < "$tmpfile";
    rm "$tmpfile"
    i=$((i + 1))
    echo $j;
done

T=(100 100 1000 1000 1000 5000 5000 10000 10000 10000 10000 50000 50000 50000 50000 50000 70000 70000 70000 70000 70000  100000 100000 100000 100000 100000 100000 100000 100000 100000 100000 100000)

i=1;
for t in "${T[@]}"; do
    if [ $i -lt 10 ]; then
        j="0$i"
    else
        j=$i
    fi
    tmpfile=$(mktemp --tmpdir=.)
    echo "2_random_large-$j $t 30 16" > "$tmpfile";
    ./GenerateCases.exe < "$tmpfile";
    rm "$tmpfile"
    i=$((i + 1))
    echo $j;
done
