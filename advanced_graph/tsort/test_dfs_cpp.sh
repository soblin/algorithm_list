#!/bin/bash

output=`./main_dfs_cpp <<EOF
6 6
0 1
1 2
3 1
3 4
4 5
5 2
EOF`

echo "$output"
