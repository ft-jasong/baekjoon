import sys

def bin_search(lan, start, end, k):
	mid = (start + end) // 2
	s = 0
	for i in lan:
		s += i // mid
	if s >= k:
		return mid + 1, end
	else :
		return start, mid - 1

def solution():
	input = sys.stdin.readline
	n, k = map(int, input().split())
	lan = [0] * n
	for i in range(n):
		lan[i] = int(input())
	mx = max(lan)
	mi = 1
	while (mx - mi >= 0):
		mi, mx = bin_search(lan, mi, mx, k)
	print(mx)
solution()