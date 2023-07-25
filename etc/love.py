def solve():
	N = 1
	M = 3
	if N > M:
		return (0)
	S = "IOI"
	flag = 0
	n = 0
	result = 0
	for c in S:
		if (flag == 0) and (c == 'I'):
			flag = 1
			n = 1
			continue
		if c == 'O':
			if (flag == 1) and (n % 2 == 1):
				n += 1
			else:
				flag = 0
				n = (n // 2 + 1 - N)
				if n > 0:
					result += 1                                                                                                               
		else:
			if (flag == 1) and (n % 2 == 0):
				n += 1
			else:
				flag = 0
				n = (n // 2 + 1 - N)
				if n > 0:
					result += n
		if (flag == 0) and (c == 'I'):
			flag = 1
			n = 1
	return (result)
print(solve())