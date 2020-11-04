# -*- coding: utf-8 -*-

import sys

def print_array(array, size):
    ret = ""
    for i in range(size):
        ret += str(array[i]) + ' '

    print(ret)

def bubble_sort(array, size):
    reverse_num = 0
    upper = size-2
    while upper >= 0:
        for i in range(0, upper+1):
            if array[i] > array[i+1]:
                tmp = array[i]
                array[i] = array[i+1]
                array[i+1] = tmp
                reverse_num += 1
        
        upper -= 1

    return reverse_num

if __name__ == '__main__':
    size = len(sys.argv) - 1
    array = []
    for i in range(size):
        # python3 main.py<0> 1<1> 2<2> 3<3>
        array.append(int(sys.argv[i+1]))

    bubble_sort(array, size)
    print_array(array, size)
