import sys

input = sys.stdin.readline

n, m = map(int, input().split())
my_map = []
next_dest = []
ans = [[-1] * m] * n
print(ans)
# start = -1
# for y in range(n):
# 	line = list(map(int, input().split()))
# 	if 2 in line:
# 		next_dest.append([y, line.index(2)])
# 	my_map.append(line)
# while len(next_dest) != 0:
