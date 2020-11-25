# -*- coding: utf-8 -*-
import sys
from collections import deque
input = sys.stdin.readline


def getDistBFS(start, adj_mat, dist):
    visited = [False for _ in range(len(dist))]
    dist[start] = 0
    visited[start] = True
    queue = deque()
    queue.append(start)
    while len(queue) is not 0:
        u = queue.pop()
        for edge in adj_mat[u]:
            v = edge[0]
            d = edge[1]
            if not visited[v]:
                visited[v] = True
                dist[v] = dist[u] + d
                queue.append(v)

    return


if __name__ == '__main__':
    num_node = int(input())
    adj_mat = [[] for _ in range(num_node)]

    for _ in range(num_node - 1):
        inputs = list(input().split())
        u, v, d = int(inputs[0]), int(inputs[1]), int(inputs[2])
        adj_mat[u].append([v, d])
        adj_mat[v].append([u, d])

    dist = [0 for _ in range(num_node)]
    start = 0
    getDistBFS(start, adj_mat, dist)
    src = dist.index(max(dist))

    getDistBFS(src, adj_mat, dist)
    dst = dist.index(max(dist))
    print(max(dist))
