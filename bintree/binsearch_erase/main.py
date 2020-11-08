# -*- coding: utf-8 -*-
import sys
from enum import Enum
input = sys.stdin.readline

class Order(Enum):
    Preorder = 0
    Inorder = 1
    Postorder = 2

class Node():
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
        
class Tree():
    def __init__(self):
        self.root = None

    def insert(self, key):
        node = self.root
        if node is None:
            self.root = Node(key)
            return

        parent = None
        while node is not None:
            if key < node.val:
                parent = node
                node = node.left
            else:
                parent = node
                node = node.right
        
        # node is None
        if key < parent.val:
            parent.left = Node(key)
            parent.left.parent = parent
            
        else:
            parent.right = Node(key)
            parent.right.parent = parent
        
        return

    def find(self, key):
        node = self.root
        while node is not None:
            if node.val == key:
                return True

            if key < node.val:
                node = node.left

            else:
                node = node.right

        return False

    def findNode(self, key):
        node = self.root
        while node is not None:
            if node.val == key:
                return node
            if key < node.val:
                node = node.left
            else:
                node = node.right

        return None
    
    def printer(self, order):
        self.printer_(self.root, order)

    def printer_(self, node, order):
        if node is None:
            return

        if order == Order.Preorder:
            print(' ' + str(node.val), end="")
            self.printer_(node.left, order)
            self.printer_(node.right, order)

        elif order == Order.Inorder:
            self.printer_(node.left, order)
            print(' ' + str(node.val), end="")
            self.printer_(node.right, order)

        else:
            self.printer_(node.left, order)
            self.printer_(node.right, order)
            print(' ' + str(node.val), end="")

        return

    def erase(self, key):
        node = self.findNode(key)
        if node is None:
            return

        n_child = 2
        if node.left == None:
            n_child -= 1
        if node.right == None:
            n_child -= 1

        parent = node.parent
        if n_child == 0:
            if key < parent.val:
                parent.left = None
            else:
                parent.right = None

        elif n_child == 1:
            child = node.right if node.left == None else node.left
            if key < parent.val:
                parent.left = child
                child.parent = parent
            else:
                parent.right = child
                child.parent = parent

        else:
            suc = self.successor(node)
            node.val = suc.val
            suc.parent.left = suc.right

    def successor(self, node):
        suc = node.right
        iterator = suc.left
        while iterator is not None:
            suc = iterator
            iterator = iterator.left

        return suc
    
if __name__ == '__main__':
    n_cmd = int(input())
    tree = Tree()
    while n_cmd > 0:
        inputs = list(input().split())
        if len(inputs) == 2:
            if inputs[0] == 'insert':
                tree.insert(int(inputs[1]))
            elif inputs[0] == 'find':
                if tree.find(int(inputs[1])):
                    print("yes")
                else:
                    print("no")
            elif inputs[0] == 'delete':
                tree.erase(int(inputs[1]))
            else:
                raise NotImplementedError("cmd must be either insert or find")
        elif len(inputs) == 1:
            if inputs[0] == 'print':
                tree.printer(Order.Inorder)
                print("")
                tree.printer(Order.Preorder)
                print("")
            else:
                raise NotImplementedError("cmd must be print")
        
        n_cmd -= 1
