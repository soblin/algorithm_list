# -*- coding: utf-8 -*-
import sys
from collections import deque
input = sys.stdin.readline


def assignColor(adj_list, ids, con_id):
    queue = deque()
    queue.append(con_id)
    ids[con_id] = con_id
    while len(queue) is not 0:
        node = queue.pop()
        for v in adj_list[node]:
            if ids[v] == -1:
                ids[v] = con_id
                queue.append(v)


if __name__ == '__main__':
    n, m = map(int, input().split())

    adj_list = [[] for _ in range(n)]
    for _ in range(m):
        s, t = map(int, input().split())
        adj_list[s].append(t)
        adj_list[t].append(s)

    ids = [-1 for _ in range(n)]
    for i in range(n):
        if ids[i] == -1:
            assignColor(adj_list, ids, i)

    q = int(input())
    for _ in range(q):
        s, t = map(int, input().split())
        if ids[s] == ids[t]:
            print("yes")
        else:
            print("no")
