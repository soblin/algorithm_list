# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

class UnionFind:
    def __init__(self, sz):
        self.parents = [0 for _ in range(sz)]
        self.heights = [0 for _ in range(sz)]
        for i in range(sz):
            self.parents[i] = i

    def findSet(self, u):
        if u is self.parents[u]:
            return u
        else:
            self.parents[u] = self.findSet(self.parents[u])
            return self.parents[u]
    
    def same(self, u, v):
        return self.findSet(u) == self.findSet(v)

    def unite(self, u_, v_):
        u = self.findSet(u_)
        v = self.findSet(v_)

        if self.parents[u] > self.parents[v]:
            self.parents[v] = u

        elif self.parents[u] == self.parents[v]:
            self.parents[v] = u
            self.height[u] += 1

        else:
            self.parents[u] = v


class Edge:
    def __init__(self, src, dst, cost):
        self.src = src
        self.dst = dst
        self.cost = cost

    def __str__(self):
        return "src: " + str(self.src) + " dst: " + str(self.dst) + " cost: " + str(self.cost)
    
if __name__ == '__main__':
    inputs = list(input().split())
    num_node = int(inputs[0])
    num_edge = int(inputs[1])

    edges = []
    
    for _ in range(num_edge):
        inputs = list(input().split())
        u = int(inputs[0])
        v = int(inputs[1])
        c = int(inputs[2])
        edges.append(Edge(u, v, c))

    edges = sorted(edges, key=lambda edge: edge.cost)

    dset = UnionFind(num_edge+1)
    opt_cost = 0
    
    for i in range(num_edge):
        src = edges[i].src
        dst = edges[i].dst
        cost = edges[i].cost
        if not dset.same(src, dst):
            opt_cost += cost
            dset.unite(src, dst)

    print(opt_cost)
