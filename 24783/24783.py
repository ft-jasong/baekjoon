T = int(input())
ans = []
for _ in range(T):
	a, b, r = map(int, input().split())
	res = 'Impossible'
	if a + b == r:
		res = 'Possible'
	if a - b == r or b - a == r:
		res = 'Possible'
	if a % b == 0:
		if a // b == r:
			res = 'Possible'
	if b % a == 0:
		if b // a == r:
			res = 'Possible'
	if a * b == r:
		res = 'Possible'
	ans.append(res)
for i in range(T):
	print(ans[i])