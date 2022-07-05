n = input()
i = 1
count = 0
while i <= int(n):
	s = input()
	lst = [0] * 26
	j = 0
	flag = 0
	for j in range(len(s) - 1):
		if s[j] != s[j + 1]:
			lst[ord(s[j]) - ord('a')] += 1
			if lst[ord(s[j + 1]) - ord('a')] != 0:
				flag = 1
	if flag == 0:
		count = count + 1
	i += 1
print(count)
