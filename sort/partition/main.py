# -*- coding: utf-8 -*-
import sys

if __name__ == '__main__':
    argc = len(sys.argv)
    size = argc - 1
    array = [int(sys.argv[i+1]) for i in range(size)]

    pivot = array[size-1]
    insert_pos = 0
    for i in range(0, size):
        if array[i] <= pivot:
            tmp = array[i]
            array[i] = array[insert_pos]
            array[insert_pos] = tmp
            insert_pos += 1;
    
    ret = ""
    for i in range(size):
        if i == (insert_pos-1):
            ret += '[' + str(array[i]) + '] '
        else:
            ret += str(array[i]) + ' '
    
    print(ret)
