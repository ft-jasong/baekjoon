from sys import stdin

def make_board():
	a = []
	for i in range(14)

	


t = int(stdin.readline().rstrip())
def dp(k, n):
	if k == 0 or n == 1:
		return n
	else:
		return dp(k - 1, n) + dp(k, n - 1)

def solution():
	k = int(stdin.readline().rstrip())
	n = int(stdin.readline().rstrip())
	print(dp(k, n))

make_board()
while t > 0:
	t -= 1