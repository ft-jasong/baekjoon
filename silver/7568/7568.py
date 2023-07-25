import sys

input = sys.stdin.readline
n = int(input())
man = []
lose = [1] * n
for _ in range(n):
	w, h = map(int, input().split())
	man.append([w, h])
for i in range(n):
	for j in range(n):
		if man[i][0] < man[j][0] and man[i][1] < man[j][1]:
			lose[i] += 1
for i in range(n):
	print(lose[i])