from sys import stdin

a, b = stdin.readline().split()
count = 0
while int(b) > int(a):
	if int(b[-1]) == 1:
		b = b[:len(b) - 1]
		count += 1
	elif int(b[-1]) % 2 == 0:
		b = str(int(b) // 2)
		count += 1
	else:
		break
if (b == a):
	print(count + 1)
else:
	print(-1)