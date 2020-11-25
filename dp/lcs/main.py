# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline


def lcs(str1_, str2_):
    str1 = ' ' + str1_
    str2 = ' ' + str2_
    costs = [[0 for _ in range(len(str2))] for _ in range(len(str1))]

    for i in range(1, len(str1)):
        for j in range(1, len(str2)):
            if str1[i] == str2[j]:
                costs[i][j] = costs[i - 1][j - 1] + 1
            else:
                costs[i][j] = max(costs[i][j - 1], costs[i - 1][j])

    return costs[len(str1) - 1][len(str2) - 1]


if __name__ == '__main__':
    num_q = int(input())
    for _ in range(num_q):
        str1 = str(list(input().split())[0])
        str2 = str(list(input().split())[0])
        print(lcs(str1, str2))
