# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline


def warshall_floyd(num_node, adj_mat):
    costs = [[float('inf') for _ in range(num_node)] for _ in range(num_node)]

    for u in range(num_node):
        costs[u][u] = 0
        for edge in adj_mat[u]:
            v = edge[0]
            c = edge[1]
            costs[u][v] = c

    for k in range(num_node):
        for i in range(num_node):
            if costs[i][k] == float('inf'):
                continue
            for j in range(num_node):
                if costs[k][j] == float('inf'):
                    continue
                tmp_cost = costs[i][k] + costs[k][j]
                if tmp_cost < costs[i][j]:
                    costs[i][j] = tmp_cost

    negative_cycle = False
    for i in range(num_node):
        if costs[i][i] < 0:
            negative_cycle = True
            break

    if negative_cycle:
        print("NEGATIVE CYCLE")
        return

    for i in range(num_node):
        for j in range(num_node):
            cost = costs[i][j]
            if cost == float('inf'):
                print("INF", end="")
            else:
                print(cost, end="")
            if j != (num_node - 1):
                print(' ', end="")
        print('')

    return


if __name__ == '__main__':
    num_node, num_q = map(int, input().split())
    adj_mat = [[] for _ in range(num_node)]

    for _ in range(num_q):
        u, v, c = map(int, input().split())
        adj_mat[u].append([v, c])

    warshall_floyd(num_node, adj_mat)
