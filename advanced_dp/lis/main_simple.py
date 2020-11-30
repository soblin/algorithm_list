# -*- coding: utf-8 -*-
import sys
input  = sys.stdin.readline

if __name__ == '__main__':
    n = int(input())
    A = []
    for i in range(n):
        A.append(int(input()))

    P = [-1 for _ in range(len(A))]
    LIS = [0 for _ in range(len(A)+1)]
    LIS[1] = 1 # LIS[i+1] is the length of LIS at A[i]

    opt_ind = 0
    for i in range(1, n):
        k = 0 # the index of maximum A[k], subject to [k] < lis[i]
        for j in range(0, i):
            if A[j] < A[i] and LIS[j+1] > LIS[k]:
                k = j + 1

        LIS[i+1] = LIS[k] + 1
        if LIS[i+1] > LIS[opt_ind]:
            opt_ind = i+1
        
        P[i] = P[k-1]

    print(LIS[opt_ind], end="")
