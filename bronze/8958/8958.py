from sys import stdin

def solution():
	T = stdin.readline().rstrip()
	for _ in range(int(T)):
		line = stdin.readline().rstrip()
		sum = 1
		res = 0
		for j in line:
			if j == 'O':
				res += sum
				sum += 1
			else :
				sum = 1
		print(res)
solution()