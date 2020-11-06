#!/bin/bash

try(){
    expected=$2
    input=$1

    output=`./main_cpp $input`

    if [ "$output" = "$expected" ]; then
        echo "OK: ($input) => ($expected)"
    else
        echo "NG: ($output) != ($expected)"
    fi
}

try "6 1 2 3 " "1 2 3 "
try "6 4 3 2 1 " "1 2 3 4 "
try "7 2 5 1 3 2 3 0 " "0 1 2 2 3 3 5 "
try "110 98 76 32 1 43 89 3 2 " "1 2 3 32 43 76 89 98 "
