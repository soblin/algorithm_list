# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

if __name__ == '__main__':
    num_node, num_q = map(int, input().split())
    adj_mat = [[] for _ in range(num_node)]

    for i in range(num_node):
        u, v = map(int, input().split())
        adj_mat[u].append(v)

    visited = [False for _ in range(num_node)]
    tsort = []

    for i in range(num_node):
        if not visited[i]:
            stack = []
            start = i
            stack.append(start)
            visited[start] = True
            while len(stack) is not 0:
                u = stack[len(stack) - 1]  # last elem
                closed = True
                for v in adj_mat[u]:
                    if not visited[v]:
                        visited[v] = True
                        stack.append(v)
                        closed = False
                        break

                if closed:
                    u = stack.pop()  # delete u
                    tsort.insert(0, u)

    for u in tsort:
        print(u)
