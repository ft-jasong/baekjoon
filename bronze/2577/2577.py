from sys import stdin

def printNum(num):
	for i in range(0, 10):
		print(num[i])

def solution():
	num = [0] * 10
	a = int(stdin.readline().rstrip())
	b = int(stdin.readline().rstrip())
	c = int(stdin.readline().rstrip())
	s = str(a * b * c)
	for i in s:
		num[int(i)] += 1
	printNum(num)
solution() 