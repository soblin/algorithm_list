# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

def binary_search(array, size, query):
    left = 0
    right = size
    while left < right:
        mid = int((left + right) / 2)
        if array[mid] == query:
            return 1
        elif query < array[mid]:
            right = mid
        else:
            left = mid + 1

    return 0

if __name__ == '__main__':
    n = int(input())
    T = list(map(int, input().split()))
    q = int(input())
    S = list(map(int, input().split()))

    cnt = 0

    for s in S:
        cnt += binary_search(T, n, s)
    
    print(cnt)
