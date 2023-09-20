import sys

tc = int(sys.stdin.readline().rstrip())
for t in range(1, tc + 1):
    grades = list(map(int, sys.stdin.readline().rstrip().split()))
    grades = grades[1:]
    grades.sort(reverse=True)
    lg = 0
    for g in range(len(grades) - 1):
        lg = max(lg, grades[g] - grades[g + 1])
    print(f"Class {t}")
    print(f"Max {grades[0]}, Min {grades[-1]}, Largest gap {lg}")
