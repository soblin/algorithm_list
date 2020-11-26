#!/bin/bash

output=`./main_c <<EOF
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 7
EOF`

expected=$'0 1 3 4
INF 0 2 3
INF INF 0 1
INF INF 7 0'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi

output=`./main_c <<EOF
4 6
0 1 1
0 2 -5
1 2 2
1 3 4
2 3 1
3 2 7
EOF`

expected=$'0 1 -5 -4
INF 0 2 3
INF INF 0 1
INF INF 7 0'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi

output=`./main_c <<EOF
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 -7
EOF`

expected=$'NEGATIVE CYCLE'

if [ "$output" = "$expected" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
fi
