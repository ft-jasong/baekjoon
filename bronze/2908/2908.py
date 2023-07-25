from sys import stdin

input = stdin.readline

a, b = input().split()
a = "".join(str(s) for s in list(reversed(a)))
b = "".join(str(s) for s in list(reversed(b)))
if (a > b):
	print(a)
else:
	print(b)