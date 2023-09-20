import sys

test_case = int(sys.stdin.readline().strip())
cnt = 0
while True:
    if cnt == test_case:
        break ;
    numStr = sys.stdin.readline().strip()
    numStr = sorted(numStr, reverse=True)
    numStr = ''.join(numStr)
    length = len(numStr)
    if length > 0:
        print((int(numStr[:length - 1]) + int(numStr[-1])))
        cnt += 1