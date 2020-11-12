# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

INFTY = 9999999
UNVISITED = 111
FOUND = 222
FINISHED = 333


def prim(adj_mat, color, cost, parent):
    start = 0
    cost[start] = 0
    color[start] = FOUND
    finished = 0
    n = len(color)
    while True:
        min_cost_node_id = -1
        min_cost = INFTY
        for i in range(n):
            if color[i] == FOUND and cost[i] < min_cost:
                min_cost = cost[i]
                min_cost_node_id = i

        if min_cost_node_id == -1:
            break

        for v in range(n):
            if adj_mat[min_cost_node_id][v] != INFTY:
                if color[v] == UNVISITED:
                    # initialize
                    cost[v] = adj_mat[min_cost_node_id][v]
                    parent[v] = min_cost_node_id
                    color[v] = FOUND
                elif color[v] == FOUND and cost[v] > adj_mat[min_cost_node_id][v]:
                    # the cost lowers!
                    cost[v] = adj_mat[min_cost_node_id][v]
                    parent[v] = min_cost_node_id

        color[min_cost_node_id] = FINISHED

    return


if __name__ == '__main__':
    n = int(input())
    adj_mat = [[] for _ in range(n)]

    for i in range(n):
        inputs = list(input().split())
        for j in range(n):
            val = int(inputs[j])
            if val == -1:
                val = INFTY
            adj_mat[i].append(val)

    color = [UNVISITED for _ in range(n)]
    cost = [INFTY for _ in range(n)]
    parent = [-1 for _ in range(n)]

    prim(adj_mat, color, cost, parent)

    opt_cost = 0
    for v in range(n):
        if parent[v] != -1:
            opt_cost += adj_mat[parent[v]][v]

    print(opt_cost, end="")
