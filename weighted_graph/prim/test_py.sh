#!/bin/bash

output=`python3 main.py <<EOF
5
-1 2 3 1 -1
2 -1 -1 4 -1
3 -1 -1 1 1
1 4 1 -1 3
-1 -1 1 3 -1
EOF`

if [ "$output" = "5" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi

output=`python3 main.py <<EOF
7
-1 10 3  -1 18 11 -1
10 -1 5   1 -1 -1 -1
 3  5 -1  2 -1  7  5
-1  1 2  -1 -1 -1  2
18 -1 -1 -1 -1  1 -1
11 -1 7  -1  1 -1  2
-1 -1 5   2 -1  2 -1
EOF`

if [ "$output" = "11" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
