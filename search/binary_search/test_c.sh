#!/bin/bash

output=`./main_c <<EOF
9
1 2 3 4 5 7 8 10 11
5
3 4 1 8 10
EOF`

if [ "$output" = "5" ]; then
    echo "OK"
else
    echo "NG"
fi
