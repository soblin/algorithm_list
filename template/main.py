# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline

class Process:
    def __init__(self, name, proc_time):
        self.name = name
        self.proc_time = proc_time

class Queue:
    def __init__(self):
        self.head = 0
        self.tail = 0
        self.queue = [Process("", 0) for _ in range(100)]

    def enqueue(self, name, proc_time):
        self.queue[self.tail].name = name
        self.queue[self.tail].proc_time = proc_time
        self.tail += 1

    def dequeue(self):
        self.head += 1

    def empty(self):
        return self.head == self.tail

    def __getitem__(self, key):
        return self.queue[key]
    
if __name__ == '__main__':
    n, quantum = map(int, input().split())

    queue = Queue()

    acc_time = 0
    
    for _ in range(n):
        name, proc_time_str = input().split()
        proc_time = int(proc_time_str)
        queue.enqueue(name, proc_time)

    while not queue.empty():
        name = queue[queue.head].name
        proc_time = queue[queue.head].proc_time
        if proc_time <= quantum:
            acc_time += proc_time
            queue.dequeue()
            print(str(name) + ' ' + str(acc_time))
        else:
            acc_time += quantum
            queue.dequeue()
            queue.enqueue(name, proc_time - quantum)
