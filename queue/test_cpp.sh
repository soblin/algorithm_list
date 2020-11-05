#!/bin/bash

output=`./main_cpp <<EOF
5 100
p1 150
p2 80
p3 200
p4 350
p5 20
EOF`

expected=$'p2 180
p5 400
p1 450
p3 550
p4 800'

if [ "$expected" = "$output" ]; then
    echo "OK"
else
    echo "NG"
fi
