#!/bin/bash

output=`python3 main_simple.py <<EOF
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

output=`python3 main_simple.py <<EOF
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
