#!/bin/bash

output=`./main <<EOF
10
insert 30
insert 88
insert 12
insert 1
insert 20
find 12
insert 17
insert 25
find 16
print
EOF`

expected=$'yes
no
 1 12 17 20 25 30 88
 30 12 1 20 17 25 88'

if [ "$expected" = "$output" ]; then
    echo "OK"
else
    echo "$output"
    exit 1
fi
