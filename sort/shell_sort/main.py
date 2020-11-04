# -*- coding: utf-8 -*-
import sys

def print_array(array):
    size = len(array)
    ret = ""
    for elem in array:
        ret += str(elem) + ' '

    print(ret)
    return

def insertion_sort_step(array, step):
    size = len(array)
    for i in range(step, size):
        val = array[i]
        j = i - step
        while array[j] > val and j >= 0:
            array[j + step] = array[j]
            j -= step

        array[j + step] = val

    return

def shell_sort(array):
    size = len(array)
    # gen steps
    steps = []
    g = 1
    while g < size:
        steps.append(g)
        g = 3 * g + 1

    for step in reversed(steps):
        insertion_sort_step(array, step)

    return

if __name__ == '__main__':
    argc = len(sys.argv)
    size = argc-1
    array = [int(sys.argv[i+1]) for i in range(0, size)]

    shell_sort(array)
    print_array(array)
