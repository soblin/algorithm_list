#!/bin/bash

output=`./main_c <<EOF
9
0 1 2 3 4 5 6 7 8
2 1 4 3 5 0 7 6 8
EOF`

expected=$'2 4 5 3 1 7 8 6 0 '

if [ "$expected" = "$output" ]; then
    echo "OK"
else
    echo "NG"
    exit 1
fi

output=`./main_c <<EOF
5
0 1 2 3 4
2 1 3 0 4
EOF`

expected=$'2 3 1 4 0 '

if [ "$expected" = "$output" ]; then
    echo "OK"
else
    echo "NG"
    exit 1
fi
