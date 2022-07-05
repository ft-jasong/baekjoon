from sys import stdin

li = [0] * 42
for _ in range(10):
	a = int(stdin.readline().rstrip())
	li[a] += 1
count = 0
for i in range(42):
	if li[i] > 0:
		count += 1
print(count)