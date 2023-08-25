# def bfs():

import sys

def __main__():
    n = int(sys.stdin.readline())
    board = []
    max_h = 0
    for _ in range(n):
        *line, = map(int, sys.stdin.readline().split())
        board.append(line)
        if max(line) > max_h:
            max_h = max(line)
    

__main__()