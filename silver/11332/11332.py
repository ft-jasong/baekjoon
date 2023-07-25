from sys import stdin

OP_SEC = 10**8

def factorial(n, max_time):
	if n <= 0:
		return 1
	else:
		fac = 1
		for i in range(n):
			fac *= (i + 1)
			# if (fac > max_time):
			# 	return max_time + 1
		return fac

def solution():
	loop = int(stdin.readline())
	for _ in range(loop):
		s, n, tc_num, limit_time = stdin.readline().split()
		n = int(n)
		limit_time = int(limit_time)
		tc_num = int(tc_num)
		if s == "O(N)":
			print('May Pass.')
		elif s == "O(2^N)":
			if OP_SEC * limit_time >= (2 ** n) * tc_num:
				print('May Pass.')
			else:
				print('TLE!')
		elif s == "O(N^2)":
			if OP_SEC * limit_time >= n ** 2 * tc_num:
				print('May Pass.')
			else:
				print('TLE!')
		elif s == "O(N^3)":
			if OP_SEC * limit_time >= n ** 3 * tc_num:
				print('May Pass.')
			else:
				print('TLE!')
		elif s == "O(N!)":
			if OP_SEC * limit_time >= factorial(n, OP_SEC * limit_time) * tc_num:
				print('May Pass.')
			else:
				print('TLE!')
solution()