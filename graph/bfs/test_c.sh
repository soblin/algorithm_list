#!/bin/bash

output=`./main_c <<EOF
4
1 2 2 4
2 1 4
3 0
4 1 3
EOF`

expected=$'1 0
2 1
3 2
4 1'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
