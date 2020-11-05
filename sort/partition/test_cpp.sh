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

try "13 19 9 5 12 8 7 4 21 2 6 11" "9 5 8 7 4 2 6 [11] 21 13 19 12 "
