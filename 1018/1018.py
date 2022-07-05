import sys

def rePaint(chess, s_y, s_x):
	w_start = 0
	b_start = 0
	for y in range(s_y, s_y + 8):
		if y % 2 == s_y % 2:
			for x in range(s_x, s_x + 8):
				if x % 2 == s_x % 2:
					if chess[y][x] != 'B': # B 시작이어야 하는데 아닌 경우
						b_start += 1
					elif chess[y][x] != 'W': # W 시작이어야 하는데 아닌 경우
						w_start += 1
				else:
					if chess[y][x] != 'W': # B 시작이어야 하는데 아닌 경우
						b_start += 1
					elif chess[y][x] != 'B': # W 시작이어야 하는데 아닌 경우
						w_start += 1
		else:
			for x in range(s_x, s_x + 8):
				if x % 2 == s_x % 2:
					if chess[y][x] != 'W': # B 시작이어야 하는데 아닌 경우
						b_start += 1
					elif chess[y][x] != 'B': # W 시작이어야 하는데 아닌 경우
						w_start += 1
				else:
					if chess[y][x] != 'B': # B 시작이어야 하는데 아닌 경우
						b_start += 1
					elif chess[y][x] != 'W': # W 시작이어야 하는데 아닌 경우
						w_start += 1
	if b_start < w_start:
		return b_start
	else:
		return w_start
	
def solution():
	input = sys.stdin.readline
	N, M = map(int, input().split())
	chess = []
	for _ in range(N):
		chess.append(input().rstrip())
	min = N * M
	for y in range(0, N - 7):
		for x in range(0, M - 7):
			check = rePaint(chess, y, x)
			if min > check:
				min = check
	print(min)
solution()