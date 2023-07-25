import sys

input = sys.stdin.readline
n = int(input())
li = list(map(int, input().split()))
m = 1
mi = [[li[0]]]
for i in li:
	if i > min(mi[-1]):
		mi.append([i])
	else:
		for j in range(len(mi)):
			if i <= min(mi[j]):
				mi[j].append(i)
				break
print(len(mi))
for i in mi:
	print(min(i), end=' ')