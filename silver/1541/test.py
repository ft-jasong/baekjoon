import sys
tc = sys.stdin.read().split("\n")
for line in tc:
    if line == "":
        break
    a, b = map(int, line.split())
    print(a + b)
