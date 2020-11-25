# -*- coding: utf-8 -*-
import sys
input = sys.stdin.readline


class Fib():
    def __init__(self, size):
        self.vals = [-1 for _ in range(size)]
        self.vals[0] = 1
        self.vals[1] = 1

    def calc(self, n):
        if n == 0 or n == 1:
            return self.vals[n]

        elif self.vals[n] is not -1:
            return self.vals[n]

        else:
            self.vals[n] = self.calc(n - 1) + self.calc(n - 2)
            return self.vals[n]


if __name__ == '__main__':
    n = int(input())
    fib = Fib(n + 1)

    print(fib.calc(n))
