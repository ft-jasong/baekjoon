n = int(input())
i = n - 54
flag = 0
for i in range(int(n)):
	res = 0
	tmp = i
	for j in range(7):
		if tmp // (10 ** (6 - j)) > 0:
			k = tmp // (10 ** (6 - j))
#			print('k is', k, sep=' ')
			res += k
#			print('res is ', )
			tmp -= k * (10 ** (6 - j))
	if (n == i + res):
		flag = 1
		break
if flag == 0:
	print(0)
else:
	print(i)