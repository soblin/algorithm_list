#!/bin/bash

output=`python3 main.py <<EOF
4 5
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 0 0 1 0
EOF`

expected=$'4'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
