# -*- coding: utf-8 -*-
import sys
from collections import deque

input = sys.stdin.readline

if __name__ == '__main__':
    num_node, num_q = map(int, input().split())
    adj_mat = [[] for _ in range(num_node)]
    indeg = [0 for _ in range(num_node)]

    for i in range(num_node):
        u, v = map(int, input().split())
        adj_mat[u].append(v)
        indeg[v] += 1

    tsort = []
    visited = [False for _ in range(num_node)]

    for i in range(num_node):
        if indeg[i] == 0 and visited[i] == False:
            queue = deque()
            queue.append(i)
            visited[i] = True
            while len(queue) is not 0:
                u = queue.pop()
                tsort.append(u)
                for v in adj_mat[u]:
                    indeg[v] -= 1
                    if indeg[v] == 0 and visited[v] == False:
                        visited[v] = True
                        queue.append(v)
    for u in tsort:
        print(u)
