#!/bin/bash

output=`python3 main.py <<EOF
3
EOF`

expected=$'3'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi

output=`python3 main.py <<EOF
44
EOF`

expected=$'1134903170'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
