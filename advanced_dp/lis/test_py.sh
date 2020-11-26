#!/bin/bash

output=`python3 main.py <<EOF
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
