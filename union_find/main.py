# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline


class UnionFind():
    def __init__(self, size):
        self.parents = [i for i in range(size)]

    def findSet(self, u):
        if self.parents[u] == u:
            return u
        else:
            self.parents[u] = self.findSet(self.parents[u])
            return self.parents[u]

    def unite(self, u_, v_):
        u = self.findSet(u_)
        v = self.findSet(v_)
        self.parents[v] = u

    def same(self, u, v):
        return self.findSet(u) == self.findSet(v)


if __name__ == '__main__':
    inputs = list(input().split())
    n = int(inputs[0])
    q = int(inputs[1])

    dset = UnionFind(n)

    for _ in range(q):
        inputs = list(input().split())
        com, x, y = int(inputs[0]), int(inputs[1]), int(inputs[2])
        if com == 0:
            # unite
            dset.unite(x, y)
        else:
            # same
            if dset.same(x, y):
                print("1")
            else:
                print("0")
