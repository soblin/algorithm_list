#!/bin/bash

output=`python3 main.py <<EOF
5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
EOF
`

expected=$'0
0
1
1
1
0
1
1'

if [ "$expected" = "$output" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
    exit 1
fi
