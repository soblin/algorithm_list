# -*- coding: utf-8 -*-
import sys

def partition(array, start, end):
    pivot = array[end]
    insert_pos = start
    
    for i in range(start, end+1):
        if array[i] <= pivot:
            tmp = array[i]
            array[i] = array[insert_pos]
            array[insert_pos] = tmp
            insert_pos += 1

    return insert_pos - 1

def quick_sort(array, start, end):
    if start < end:
        pivot_pos = partition(array, start, end)
        quick_sort(array, start, pivot_pos-1)
        quick_sort(array, pivot_pos+1, end)

if __name__ == '__main__':
    argc = len(sys.argv)
    size = argc - 1
    array = [int(sys.argv[i+1]) for i in range(size)]

    quick_sort(array, 0, size-1)

    ret = ""
    for elem in array:
        ret += str(elem) + ' '

    print(ret)
