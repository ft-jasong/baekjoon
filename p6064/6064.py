def calc_gcd(a, b):
	while b > 0:
		a, b = b, a % b
	return a

def solution():
	n, m, n_r, m_r = map(int, input().split())

	if m < n:
		n, m, n_r, m_r = m, n, m_r, n_r

	gcd = calc_gcd(n, m)
	lcm = n * m // gcd
	if n == n_r and m == m_r:
		print(lcm)
		return
	n_u, m_u = n // gcd, m // gcd

	i = 0
	for n_i in range(0, n_u):
		a = m * n_i + m_r
		for m_i in range (i, m_u):
			b = n * m_i + n_r
			if a < b:
				break
			if a == b:
				print(a)
				return
			i += 1
	print("-1")
	return

T = int(input())
for _ in range(T):
	solution()