from sys import stdin

def solution():
	n = int(stdin.readline().rstrip())
	res = 0
	for i in range(1, n):
		if i & 1:
			res = res * 2 + 1
		else:
			res = res * 2 - 1
	print(res % 1000000007)

solution()