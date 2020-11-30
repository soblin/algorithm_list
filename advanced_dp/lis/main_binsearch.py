# -*- coding: utf-8 -*-
import sys
input  = sys.stdin.readline

# 3 3 4 5 7 7 9
def lower_bound(array, start_, stop_, val):
    # return the first index in [start, stop] such that array[ret] becomes > val for the first time from 0
    start = start_;
    stop = stop_;
    while stop - start > 1:
        mid = int((start + stop) / 2)
        if array[mid] > val:
            stop = mid
        else:
            start = mid

    while array[start] <= val:
        start += 1

    for i in range(start, stop+1):
        if array[i] > val:
            return i
    
    return stop+1

if __name__ == '__main__':
    n = int(input())
    A = []
    for i in range(n):
        A.append(int(input()))
    
    LIS = [0 for _ in range(n)]
    LIS[0] = A[0]
    lis_len = 1
    
    for i in range(1, n):
        if A[i] > LIS[lis_len-1]:
            lis_len += 1
            LIS[lis_len-1] = A[i]
        elif A[i] < LIS[lis_len-1]:
            pos = lower_bound(LIS, 0, lis_len-1, A[i])
            LIS[pos] = A[i]


    print(lis_len, end="")
