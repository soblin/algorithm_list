#!/bin/bash

output=`./main_cpp <<EOF
6
30 35
35 15
15 5
5 10
10 20
20 25
EOF`

expected=$'15125'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
