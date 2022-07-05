T = int(input())
for test_case in range(1, T + 1):
	l = input().split()
	num = []
	if l.count('.') != 1 and l[-1] != '.':
		answer = 'error'
		break
	for c in l:
		if c.isdigit():
			num.append(int(c))
		elif len(num) >= 2 and (c == '+' or c == '-' or c == '*' or c == '/'):
			if c == '+':
				num.append(num.pop(-2) + num.pop())
			elif c == '-':
				num.append(num.pop(-2) - num.pop())
			elif c == '*':
				num.append(num.pop(-2) * num.pop())
			elif c == '/':
				num.append(num.pop(-2) // num.pop())
		elif c == '.' and len(num) == 1:
			answer = num.pop()
			break
		else:
			answer = 'error'
			break
	print(f"#{test_case} {answer}")