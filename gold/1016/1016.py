from sys import stdin
from math import sqrt

mi, mx = map(int, stdin.readline().split())
l = []
for x in range(2,int(sqrt(mx))+1):
	if mi // x**2 < 1:
		for i in range(1, mx // x**2 + 1):
				if i * x ** 2 <= mx and i * x ** 2 >= mi:
					l.append(i * x ** 2)
	else:
		for i in range(mi // x**2, mx // x**2 +1):
				if i * x ** 2 <= mx and i * x ** 2 >= mi:
					l.append(i * x ** 2)
l = sorted(list(set(l)))
print(mx - mi + 1 - len(l))