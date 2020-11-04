# -*- coding: utf-8 -*-
import sys

def print_array(array):
    ret = ""
    for elem in array:
        ret += str(elem) + ' '

    print(ret)
    return

def insertion_sort(array):
    size = len(array)
    for i in range(1, size):
        j = i-1
        val = array[i]
        while val < array[j] and j >= 0:
            array[j+1] = array[j]
            j -= 1
        
        array[j+1] = val
    
    return

if __name__ == '__main__':
    argc = len(sys.argv)
    size = argc - 1
    array = [int(sys.argv[i+1]) for i in range(0, size)]

    insertion_sort(array)
    print_array(array)
