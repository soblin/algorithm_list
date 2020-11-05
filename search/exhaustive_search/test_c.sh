#!/bin/bash

output=`./main_c <<EOF
5
1 5 7 10 21
4
2 4 17 8
EOF`

expected=$'no
no
yes
yes'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
fi
