from sys import stdin

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
sum = 0
a = sorted(a)
b = sorted(b, reverse=True)
for i in range(n):
	sum += a[i] * b[i]
print(sum)