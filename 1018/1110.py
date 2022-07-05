import sys

n = int(sys.stdin.readline().rstrip())
new_num  = n % 10 * 10 + n // 10 + n % 10
count = 1
while n != new_num:
	new_num = (new_num % 10 * 10) + (new_num // 10 + new_num % 10) % 10
	count += 1
print(count)