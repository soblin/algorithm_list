#!/bin/bash

output=`python3 main.py <<EOF
3
abcbdab
bdcaba
abc
abc
abc
bc
EOF`

expected=$'4
3
2'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
