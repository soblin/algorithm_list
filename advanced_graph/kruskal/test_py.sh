#!/bin/bash

output=`python3 main.py <<EOF
6 9
0 1 1
0 2 3
1 2 1
1 3 7
2 4 1
1 4 3
3 4 1
3 5 1
4 5 6
EOF`

if [ "$output" = "5" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
