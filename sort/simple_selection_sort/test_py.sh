#!/bin/bash

try(){
    expected=$2
    input=$1

    output=`python3 main.py $input`

    if [ "$output" = "$expected" ]; then
        echo "OK: ($input) => ($expected)"
    else
        echo "NG: ($output) != ($expected)"
    fi
}

try "1 2 3 " "1 2 3 "
try "4 3 2 1 " "1 2 3 4 "
try "98 76 32 1 43 89 3 2 " "1 2 3 32 43 76 89 98 "