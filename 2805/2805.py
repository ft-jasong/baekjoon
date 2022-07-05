import sys

def getSum(n, tree):
	sum = 0
	for l in tree:
		if l - n > 0:
			sum += l - n
	return sum

def solution():
	input = sys.stdin.readline
	n, h = map(int, input().split())
	tree = list(map(int, input().split()))
	mi = 0
	mx = max(tree)
	while True:
		s = getSum((mi + mx) // 2 , tree)
		if s >= h:
			mi = (mi + mx) // 2
			if mi == (mi + mx) // 2:
				break
		else :
			mx = (mi + mx) // 2
	print(mi)
solution()