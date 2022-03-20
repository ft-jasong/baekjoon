from sys import stdin

def solution():
	a = [0] * 9
	res = 0
	for i in range(0, 9):
		a[i] = int(stdin.readline())
		if res < a[i]:
			idx = i
			res = a[i]
	print(a[idx])
	print(idx + 1)

solution()