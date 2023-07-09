import sys
input = sys.stdin.readline

N = int(input())
items = [list(map(int, input().split())) for _ in range(N)]
dividend = [i[0] for i in items]

divisor = 1
for _, divider in items:
    divisor *= divider

for i in range(len(dividend)):
    dividend[i] *= divisor // items[i][1]

def findGCD(a, b):
    if a < b:
        a, b = b, a
    
    rest = a % b
    while rest != 0:
        a = b
        b = rest
        rest = a % b
    
    return b

GCD = dividend[0]
for i in range(1, len(dividend)):
    GCD = findGCD(GCD, dividend[i])

GCD_result = findGCD(GCD, divisor)
print(f'{GCD//GCD_result} {divisor//GCD_result}')