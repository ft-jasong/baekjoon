import sys

length = int(sys.stdin.readline())
li = list(map(int, sys.stdin.readline().rstrip().split()))
li = list(set(li))
li.sort()
print(*li)