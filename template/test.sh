#!/bin/bash

try(){
    expected=$2
    input=$1

    output=`./main $input`

    if [ "$output" = "$expected" ]; then
        echo "OK: ($input) => ($expected)"
    else
        echo "NG: ($output) != ($expected)"
    fi
}

try "1 2 3 " "1 2 3 "
