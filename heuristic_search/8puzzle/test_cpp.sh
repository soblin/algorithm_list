#!/bin/bash

output=`./main_cpp <<EOF
1 3 0
4 2 5
7 8 6
EOF`

expected=$'ldrd'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "$output"
    echo "NG"
fi
