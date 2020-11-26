#!/bin/bash

output=`python3 main.py <<EOF
4 5
4 2
5 2
2 1
8 3
EOF`

expected=$'2 4 13'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi

output=`python3 main.py <<EOF
6 9
3 2
2 1
6 3
1 2
3 1
85 5
EOF`

expected=$'3 5 6 94'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
