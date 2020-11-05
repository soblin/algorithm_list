# -*- coding: utf-8 -*-
import sys
sentinel = 1000000

def merge(array, left_buf, right_buf, frm, mid, to):
    # 1 1 2
    # 3 6 9
    for i in range(0, (mid-frm)+1):
        left_buf[i] = array[frm+i]
    left_buf[(mid-frm)+1] = sentinel
    
    for j in range(0, (to-mid)):
        right_buf[j] = array[mid+1+j]
    right_buf[(to-mid)] = sentinel

    i = 0
    j = 0
    for k in range(frm, to+1):
        if left_buf[i] < right_buf[j]:
            array[k] = left_buf[i]
            i += 1
        else:
            array[k] = right_buf[j]
            j += 1

    return

def merge_sort(array, left_buf, right_buf, frm, to):
    if frm == to:
        return
    
    mid = int((frm + to) / 2)
    # [frm, mid], [mid+1, to]
    merge_sort(array, left_buf, right_buf, frm, mid)
    merge_sort(array, left_buf, right_buf, mid+1, to)
    merge(array, left_buf, right_buf, frm, mid, to)

    return

if __name__ == '__main__':
    argc = len(sys.argv)
    size = argc - 1
    array = [int(sys.argv[i+1]) for i in range(size)]
    left_buf = [0 for _ in range(size)]
    right_buf = [0 for _ in range(size)]

    merge_sort(array, left_buf, right_buf, 0, size-1)
    ret = ""
    for elem in array:
        ret += str(elem) + ' '
    print(ret)
    
