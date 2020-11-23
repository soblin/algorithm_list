#!/bin/bash

output=`./main_cpp <<EOF
4
0 1 2
1 2 1
1 3 3
EOF`

expected=$'5'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi

output=`./main_cpp <<EOF
4
0 1 1
1 2 2
2 3 4
EOF`

expected=$'7'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
