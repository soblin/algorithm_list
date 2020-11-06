# -*- coding: utf-8 -*-
import sys

def counting_sort(array, dst, size, k):
    counter = [0 for _ in range(k)]

    for i in range(size):
        counter[array[i]] += 1

    for i in range(k-1):
        counter[i+1] += counter[i]

    for i in range(size):
        dst[counter[array[i]]-1] = array[i]
        counter[array[i]] -= 1
    
if __name__ == '__main__':
    argc = len(sys.argv)
    k = int(sys.argv[1])
    size = argc - 2

    array = [int(sys.argv[i+2]) for i in range(size)]
    dst = [0 for _ in range(size)]
    
    counting_sort(array, dst, size, k)
    
    ret = ""
    for elem in dst:
        ret += str(elem) + ' '

    print(ret)
