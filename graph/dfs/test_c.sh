#!/bin/bash

output=`./main_c <<EOF
6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0
EOF`

expected=$'1 1 12
2 2 11
3 3 8
4 9 10
5 4 7
6 5 6'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
