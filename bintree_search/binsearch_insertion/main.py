# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

class Node:
    def __init__(self, val=0, parent=None, left=None, right=None):
        self.val = val
        self.parent = parent
        self.left = left
        self.right = right

class Tree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        node = self.root
        if node is None:
            self.root = Node()
            self.root.val = key
            return

        parent = None
        while node is not None:
            val = node.val
            if key < val:
                parent = node
                node = node.left
            else:
                # key >= val
                parent = node
                node = node.right

        if key < parent.val:
            parent.left = Node(key, parent=parent)
        else:
            parent.right = Node(key, parent=parent)
        
        return
    
    def print_order(self, node, order):
        if node == None:
            return
        
        if order == "Preorder":
            print(' ' + str(node.val), end="")
            self.print_order(node.left, order)
            self.print_order(node.right, order)

        elif order == "Inorder":
            self.print_order(node.left, order)
            print(' ' + str(node.val), end="")
            self.print_order(node.right, order)

        else:
            self.print_order(node.left, order)
            self.print_order(node.right, order)
            print(' ' + str(node.val), end="")

        return
    
if __name__ == '__main__':
    n = int(input())
    tree = Tree()
    
    for _ in range(n):
        inputs = list(input().split())
        
        if len(inputs) == 2:
            cmd = inputs[0]
            val = int(inputs[1])
        else:
            cmd = inputs[0]
            
        if cmd == "insert":
            tree.insert(val)
        
        elif cmd == "print":
            tree.print_order(tree.root, "Inorder")
            print('')
            tree.print_order(tree.root, "Preorder")
