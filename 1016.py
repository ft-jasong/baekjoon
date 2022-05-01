from sys import stdin
from math import sqrt

mi, mx = map(int, stdin.readline().split())

def is_prime(num):
	for i in range(1, int(sqrt(num))):
		if num % i == 0:
			return (1)
	return (0)

l = [num for num in range(mi, mx + 1)]
d = {key:key for key in range(mi, mx + 1)}
