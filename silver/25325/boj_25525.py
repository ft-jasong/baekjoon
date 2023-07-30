import sys

n = int(sys.stdin.readline())
names = sys.stdin.readline().split()
popular = {}
for name in names:
    popular[name] = 0
for _ in range(n):
    votes = sys.stdin.readline().split()
    for vote in votes:
        popular[vote] += 1
for key, value in sorted(popular.items(), key = lambda x : (-x[1], x[0])):
    print(key, value)