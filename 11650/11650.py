from sys import stdin

n = int(stdin.readline().rstrip())
li = []
for _ in range(n):
	x, y = map(int, stdin.readline().split())
	li.append([x, y])
li.sort(key=lambda x : (x[0], x[1]))

for i in range(n):
	print(li[i][0], li[i][1])