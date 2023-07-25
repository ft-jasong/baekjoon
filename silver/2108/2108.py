from sys import stdin

n = int(stdin.readline().rstrip())
li = []
freq = []
for _ in range(n):
	a = int(stdin.readline().rstrip())
	li.append(a)
li.sort()
li.append(5000)
count = 1
for i in range(n):
	if li[i] == li[i + 1]:
		count += 1
	else:
		freq.append([li[i], count])
		count = 1
freq.sort(key=lambda x: (-x[1], x[0]))
print(round((sum(li) - 5000) / n))
print(li[n // 2])
if len(freq) > 1 and freq[0][1] == freq[1][1]:
	print(freq[1][0])
else:
	print(freq[0][0])
print(abs(li[n - 1] - li[0]))