#!/bin/bash

output=`./main_binsearch_cpp <<EOF
5
5
1
3
2
4
EOF`

expected=$'3'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi

output=`./main_binsearch_cpp <<EOF
8
4
1
6
2
8
5
7
3
EOF`

expected=$'4'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
