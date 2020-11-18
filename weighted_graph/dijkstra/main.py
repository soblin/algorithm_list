# -*- coding: utf-8 -*-
import sys
import numpy as np
input = sys.stdin.readline

INFTY = float('inf')
UNVISITED = 111
FOUND = 222
FINISHED = 333

if __name__ == '__main__':
    num_node = int(input())
    adj_mat = [[INFTY for _ in range(num_node)] for _ in range(num_node)]
    
    for i in range (num_node):
        inputs = list(input().split())
        u = int(inputs[0])
        k = int(inputs[1])
        for j in range(k):
            v = int(inputs[2*j+2])
            c = int(inputs[2*j+3])
            adj_mat[u][v] = c

    adj_mat = np.asarray(adj_mat)

    cost = [float('inf') for _ in range(num_node)]
    color = [UNVISITED for _ in range(num_node)]
    parent = [-1 for _ in range(num_node)]
    
    start = 0
    cost[start] = 0
    color[start] = FOUND
    while True:
        # find a FOUND node with minimum cost
        min_cost_node_ind = -1
        min_cost = INFTY
        for i in range(num_node):
            if cost[i] < min_cost and color[i] == FOUND:
                min_cost = cost[i]
                min_cost_node_ind = i

        if min_cost_node_ind == -1:
            break

        color[min_cost_node_ind] = FINISHED
        
        for i in range(num_node):
            if adj_mat[min_cost_node_ind][i] != INFTY and color[i] != FINISHED:
                new_cost = cost[min_cost_node_ind] + adj_mat[min_cost_node_ind][i]
                # if cost lowers
                if new_cost < cost[i]:
                    cost[i] = new_cost
                    color[i] = FOUND
                    parent[i] = min_cost_node_ind

    for i in range(num_node):
        print('{} {}'.format(i, int(cost[i])))
    
