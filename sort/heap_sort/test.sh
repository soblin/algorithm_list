#!/bin/bash

try(){
    input=$1
    expected=$2

    output=`./main $input`

    if [ "$output" = "$expected" ]; then
        echo "OK: input($input) => expected($expected)"
    else
        echo "NG: output($output) != expected($expected)"
    fi
}

try "1 2 3" "1 2 3 "
try "4 3 2 1 " "1 2 3 4 "
try "98 76 32 1 43 89 3 2 " "1 2 3 32 43 76 89 98 "
