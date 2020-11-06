#!/bin/bash

output=`./main <<EOF
8
insert 30
insert 88
insert 12
insert 1
insert 20
insert 17
insert 25
print
EOF
`

expected=$' 1 12 17 20 25 30 88
 30 12 1 20 17 25 88'

if [ "$expected" = "$output" ]; then
    echo "OK"
else
    echo "$output"
    exit 1
fi
