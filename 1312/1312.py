import sys

boonja, boonmo, num = map(int, sys.stdin.readline().split())
rest = boonja % boonmo
answer = 0
for _ in range(num):
    rest *= 10
    answer = rest // boonmo
    rest %= boonmo
print(answer)
