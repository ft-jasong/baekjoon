from sys import stdin

n = int(stdin.readline().rstrip())
li = [] * n
for _ in range(n):
	a = stdin.readline().rstrip()
	li.append([a, len(a)])
li.sort(key = lambda x : (x[1], x))
print(li[0][0])
for i in range(1, n):
	if (li[i - 1][0] != li[i][0]):
		print(li[i][0])