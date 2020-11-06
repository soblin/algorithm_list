#!/bin/bash

output=`./main_c <<EOF
4
1 2 2 4
2 1 4
3 0
4 1 3
EOF`

expected=$' 0 1 0 1
 0 0 0 1
 0 0 0 0
 0 0 1 0'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
