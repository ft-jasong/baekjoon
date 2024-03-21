sizeCnt, kindCnt = map(int, input().split())
socks = list(map(int, input().split()))
leftSocks = socks[:sizeCnt]
rightSocks = socks[sizeCnt:]
leftSocksCnt = [0] * kindCnt
rightSocksCnt = [0] * kindCnt
for sock in leftSocks:
    leftSocksCnt[sock - 1] += 1
for sock in rightSocks:
    rightSocksCnt[sock - 1] += 1
ans = sizeCnt ** 2
for i in range(1, kindCnt + 1):
    if rightSocksCnt[i - 1] > 0:
        ans -= leftSocksCnt[i - 1] * rightSocksCnt[i - 1]
print(ans)