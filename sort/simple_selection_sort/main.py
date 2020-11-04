# -*- coding: utf-8 -*-
import sys

def print_array(array):
    ret = ""
    for elem in array:
        ret += str(elem) + ' '

    print(ret)
    return

def find_minimum(array, from_id, to_id):
    min_id = from_id
    for i in range(from_id, to_id+1):
        if array[i] < array[min_id]:
            min_id = i

    return min_id

def selection_sort(array):
    size = len(array)
    for i in range(1, size):
        min_id = find_minimum(array, i, size-1)
        if array[i-1] > array[min_id]:
            tmp = array[i-1]
            array[i-1] = array[min_id]
            array[min_id] = tmp

    return

if __name__ == '__main__':
    argc = len(sys.argv)
    size = argc - 1
    array = [int(sys.argv[i+1]) for i in range(0, size)]

    selection_sort(array)
    print_array(array)
