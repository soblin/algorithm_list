# -*- coding: utf-8 -*-
import sys
from queue import PriorityQueue

input = sys.stdin.readline

INFTY = float('inf')
UNVISITED = 111
FOUND = 222
FINISHED = 333

class Edge(object):
    def __init__(self, dst_vertex, edge_cost):
        self.dst_vertex = dst_vertex
        self.edge_cost = edge_cost

    @property
    def v(self):
        return self.dst_vertex

    @property
    def  c(self):
        return self.edge_cost
    
if __name__ == '__main__':
    num_node = int(input())
    adj_list = [[] for _ in range(num_node)]
    cost = [INFTY for _ in range(num_node)]
    color = [UNVISITED for _ in range(num_node)]
    parent = [-1 for _ in range(num_node)]

    for _ in range(num_node):
        inputs = list(input().split())
        u = int(inputs[0])
        k = int(inputs[1])
        for j in range(k):
            v = int(inputs[2*j+2])
            c = int(inputs[2*j+3])
            adj_list[u].append(Edge(v, c))

    queue = PriorityQueue()
    cost[0] = 0
    color[0] = FOUND
    queue.put((0, 0)) # in order (cost, vertex_id)
    while queue.qsize() is not 0:
        min_cost_found_node = queue.get()
        u = min_cost_found_node[1]
        c = min_cost_found_node[0]
        if cost[u] <  c:
            # this node is not treated
            continue

        color[u] = FINISHED
        for edge in adj_list[u]:
            v = edge.v
            if color[v] != FINISHED:
                # the cost of each node must be decrescent
                new_cost = c + edge.c
                if new_cost < cost[v]:
                    # cost lowers
                    cost[v] = new_cost
                    color[v] = FOUND
                    parent[v] = u
                    queue.put((cost[v], v))

    for i in range(num_node):
        print("{} {}".format(i, cost[i]))
