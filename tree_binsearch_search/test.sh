#!/bin/bash

output=`./main <<EOF
18
insert 8
insert 2
insert 3
insert 7
insert 22
insert 1
find 1
find 2
find 3
find 4
find 5
find 6
find 7
find 8
print
delete 3
delete 7
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
