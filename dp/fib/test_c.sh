#!/bin/bash

output=`./main_c <<EOF
3
EOF`

expected=$'3'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi

output=`./main_c <<EOF
44
EOF`

expected=$'1134903170'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
