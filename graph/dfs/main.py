# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

UNVISITED = 111
FOUND = 222
FINISHED = 333

if __name__ == '__main__':
    n = int(input())
    mat = [[0 for _ in range(n)] for _ in range(n)]
    color = [UNVISITED for _ in range(n)]
    for i in range(n):
        inputs = list(input().split())
        u = int(inputs[0]) - 1
        k = int(inputs[1])
        for j in range(k):
            v = int(inputs[2 + j]) - 1
            mat[u][v] = 1

    stack = []
    found_time = [0 for _ in range(n)]
    finished_time = [0 for _ in range(n)]

    tstamp = 1
    stack.append(0)
    found_time[0] = 1
    color[0] = FOUND
    while len(stack) is not 0:
        node = stack[len(stack) - 1]
        next_to_find = -1
        for v in range(n):
            if mat[node][v] == 1 and color[v] == UNVISITED:
                next_to_find = v
                break

        tstamp += 1
        if next_to_find == -1:
            color[node] = FINISHED
            finished_time[node] = tstamp
            stack.pop()
        else:
            color[next_to_find] = FOUND
            found_time[next_to_find] = tstamp
            stack.append(next_to_find)

    for i in range(n):
        print("%d %d %d" % (i + 1, found_time[i], finished_time[i]))
