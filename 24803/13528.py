from sys import stdin

def solution():
	input = stdin.readline
	cost = float(input())
	T = int(input())
	ans = 0.0
	for _ in range(T):
		w, h = map(float, input().split())
		ans += w * h * cost
	print("{:.7f}".format(ans))
solution()