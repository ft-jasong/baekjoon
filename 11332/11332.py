from sys import stdin

def factorial(n):
	if n <= 0:
		return 1
	else:
		fac = 1
		for i in range(n):
			fac *= i
		return fac

def solution():
	input = stdin.readline()
	loop = int(input())
	for _ in range(loop):
		time_max = 10**8
		s, n, t, l = map(str, input().split())
		if s is 'O(N)':
			if time_max * int(l) >= int(n):
				print('May Pass')
			else:
				print('TLE!')
		elif s is 'O(2^N)':
			if time_max * int(l) >= 2 ** int(n):
				print('May Pass')
			else:
				print('TLE!')
		elif s is 'O(N^2)':
			if time_max * int(l) >= int(n) ** 2:
				print('May Pass')
			else:
				print('TLE!')
		elif s is 'O(N^3)':
			if time_max * int(l) >= int(n) ** 3:
				print('May Pass')
			else:
				print('TLE!')
		elif s is 'O(N!)':
			if time_max * int(l) >= int(n) ** 2:
				print('May Pass')
			else:
				print('TLE!')