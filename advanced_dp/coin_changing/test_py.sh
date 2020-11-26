#!/bin/bash

output=`python3 main.py <<EOF
15 6
1 2 7 8 12 50
EOF`

expected=$'2'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
