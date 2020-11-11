#!/bin/bash

output=`./main_cpp <<EOF
6
2 1
2 2
4 2
6 2
3 3
5 4
2
2 4 0 4
4 10 2 5
EOF`

expected=$'0 1 2 4 
2 3 5 '

if [ "$expected" = "$output" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
    exit 1
fi
