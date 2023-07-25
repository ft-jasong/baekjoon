# import sys

# input = sys.stdin.readline
# n = int(input())
# li = list(map(int, input().split()))
# m = 1
# mi = [[li[0]]]
# for i in li:
# 	if i > min(mi[-1]):
# 		mi.append([i])
# 	else:
# 		for j in range(len(mi)):
# 			if i <= min(mi[j]):
# 				mi[j].append(i)
# 				break
# print(len(mi))
# for i in mi:
# 	print(min(i), end=' ')

import sys

def bin_search(start, end, arg, li):
	mid = (start + end) // 2
	if arg < li[mid]:
		return start, mid - 1
	else:
		return mid + 1, end

def solution():
	input = sys.stdin.readline
	n = int(input())
	li = list(map(int, input().split()))
	m = 1
	mi = [li[0]]
	for i in li:
		if i > mi[-1]:
			mi.append(i)
		else:
			start = 0
			end = len(mi) - 1
			while end - start >= 0:
				start, end = bin_search(start, end, i, mi)
			if end < 0:
				end = 0
			if mi[end] < i:
				mi[end + 1] = i
			else:
				mi[end] = i
	print(len(mi))
solution()