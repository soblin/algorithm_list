# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

if __name__ == '__main__':
    n = int(input())
    T = list(map(int, input().split()))
    q = int(input())
    S = list(map(int, input().split()))

    cnt = 0
    for s in S:
        for t in T:
            if t == s:
                cnt += 1

    print(cnt)
