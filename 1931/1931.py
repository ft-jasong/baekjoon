from sys import stdin

input = stdin.readline
n = int(input())
li = []
for _ in range(n):
	s, f = map(int, input().split())
	li.append([s, f])
li = sorted(li, key = lambda x : x[0])
li = sorted(li, key = lambda x : x[1])
time = li[0][1]
count = 1
for i in range(1, n):
	if li[i][0] >= time:
		time = li[i][1]
		count += 1
print(count)