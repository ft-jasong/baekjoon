from sys import stdin

def solution():
	input = stdin.readline
	ans = [0] * 101
	a, b = map(int, input().split())
	for i in range(a + 1, b + 1):
		ans[i] = 1
	a, b = map(int, input().split())
	for i in range(a + 1, b + 1):
		ans[i] = 1
	print(ans.count(1))
solution()