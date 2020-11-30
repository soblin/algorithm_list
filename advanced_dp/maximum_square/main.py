# -*- coding: utf-8 -*-
import sys
import copy
input = sys.stdin.readline

if __name__ == '__main__':
    H, W= map(int, input().split())
    board = [[0 for _ in range(W)] for _ in range(H)]
    costs = copy.deepcopy(board)
    
    for i in range(H):
        inputs = list(input().split())
        for j in range(W):
            if int(inputs[j]) == 1:
                board[i][j] = 1

    for i in range(W):
        costs[0][i] =  1 if board[0][i] == 0 else 0
    for j in range(H):
        costs[j][0] =  1 if board[j][0] == 0 else 0

    ret = 0
    for i in range(1, H):
        for j in range(1, W):
            if board[i][j] == 1:
                costs[i][j] = 0
            else:
                costs[i][j] = min(costs[i-1][j], min(costs[i][j-1], costs[i-1][j-1])) + 1
                ret = max(ret, costs[i][j])

    print(ret*ret, end="")               
