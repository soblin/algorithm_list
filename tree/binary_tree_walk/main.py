# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

def print_tree(root, left, right, order):
    if root == -1:
        return

    l = left[root];
    r = right[root];
    
    if order == "Preorder":
        print(' ' + str(root), end="")
        if l != -1:
            print_tree(l, left, right, order)
        if r != -1:
            print_tree(r, left, right, order)
    elif order == "Inorder":
        if l != -1:
            print_tree(l, left, right, order)
        print(' ' + str(root), end="")
        if r != -1:
            print_tree(r, left, right, order)
    else:
        if l != -1:
            print_tree(l, left, right, order)
        if r != -1:
            print_tree(r, left, right, order)

        print(' ' + str(root), end="")

    return
    
if __name__ == '__main__':
    n = int(input())

    left = [-1 for _ in range(n)]
    right = [-1 for _ in range(n)]
    
    for i in range(n):
        n, l, r = map(int, input().split())
        left[n] = l
        right[n] = r

    print("Preorder")
    print_tree(0, left, right, "Preorder")
    print("\nInorder")
    print_tree(0, left, right, "Inorder")
    print("\nPostorder")
    print_tree(0, left, right, "Postorder")

    
