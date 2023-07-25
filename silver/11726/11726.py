n  = int(input())
arr = [0] * n
if n > 1:
	arr[1] = 1
if n > 2:
	arr[2] = 2
for i in range(3, n + 1):
	arr[i] = arr[i - 2] + arr[i - 1]
print(arr[n] % 10007)
