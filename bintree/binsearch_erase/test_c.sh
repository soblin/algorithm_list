#!/bin/bash

output=`./main_c <<EOF
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
EOF
`

expected=$'yes
yes
yes
no
no
no
yes
yes
 1 2 3 7 8 22
 8 2 1 3 7 22
 1 2 8 22
 8 2 1 22'

if [ "$expected" = "$output" ]; then
    echo "OK"
else
    echo "NG"
    echo "$output"
    exit 1
fi
