# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

def set_depth(root, left, right, depth, depths):
    depths[root] = depth
    
    if left[root] == -1:
        return

    l = left[root]
    r = right[root]
    set_depth(l, left, right, depth+1, depths)
    set_depth(r, left, right, depth+1, depths)

    return

def set_and_get_height(root, left, right, height):
    l = left[root]
    r = right[root]
    
    if l == -1:
        height[root] = 0
        return 0

    h1 = set_and_get_height(l, left, right, height) + 1
    h2 = set_and_get_height(r, left, right, height) + 1

    h = max(h1, h2)
    height[root] = h

    return h

if __name__ == '__main__':
    num = int(input())

    parent = [-1 for _ in range(num)]
    sibling = [-1 for _ in range(num)]
    degree = [-1 for _ in range(num)]
    depth = [-1 for _ in range(num)]
    height = [-1 for _ in range(num)]
    left = [-1 for _ in range(num)]
    right = [-1 for _ in range(num)]

    for _ in range(num):
        u, l, r = map(int, input().split())
        left[u] = l
        right[u] = r
        degree[u] = 0
        if l is not -1:
            parent[l] = u
            parent[r] = u
            degree[u] = 2
            sibling[l] = r
            sibling[r] = l

    set_depth(0, left, right, 0, depth)
    root_height = set_and_get_height(0, left, right, height)

    for i in range(num):
        print("node {}: parent = {}, sibling = {}, degree = {}, depth = {}, height = {}".format(i, parent[i], sibling[i], degree[i], depth[i], height[i]), end="")
        if parent[i] == -1:
            node_type = "root"
        elif left[i] == -1:
            node_type = "leaf"
        else:
            node_type = "internal node"
        print(", " + node_type)
