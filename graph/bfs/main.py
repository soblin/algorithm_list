# -*- coding: utf-8 -*-
import sys
from collections import deque

input = sys.stdin.readline

UNVISITED = 111
FOUND = 222
FINISHED = 333

if __name__ == '__main__':
    n = int(input())

    adj_list = [[] for _ in range(n)]

    for i in range(n):
        inputs = list(input().split())
        u = int(inputs[0]) - 1
        k = int(inputs[1])
        for j in range(k):
            v = int(inputs[2 + j]) - 1
            adj_list[u].append(v)

    dist = [0 for _ in range(n)]
    color = [UNVISITED for _ in range(n)]
    start = 0
    dist[start] = 0
    color[start] = FOUND
    queue = deque()
    queue.append(start)
    while len(queue) is not 0:
        node = queue.pop()
        for v in adj_list[node]:
            if color[v] == UNVISITED:
                color[v] = FOUND
                dist[v] = dist[node] + 1
                queue.append(v)

        color[node] = FINISHED

    for i in range(n):
        print("%d %d" % (i + 1, dist[i]))
