#!/bin/bash

output=`./main_cpp <<EOF
1 2 3 4
6 7 8 0
5 10 11 12
9 13 14 15
EOF`

echo "$output"
