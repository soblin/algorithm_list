#!/bin/bash

output=`python3 main.py <<EOF
5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3
EOF`

expected=$'0 0
1 2
2 2
3 1
4 3'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi

output=`python3 main.py <<EOF
7
0 4 1 10 2 3 4 18 5 11
1 3 0 10 2 5 3 1
2 5 0 3 1 5 3 2 5 7 6 5
3 3 1 1 2 2 6 2
4 2 0 18 5 1
5 4 0 11 2 7 4 1 6 2
6 3 2 5 3 2 5 2
EOF`

expected=$'0 0
1 6
2 3
3 5
4 10
5 9
6 7'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
