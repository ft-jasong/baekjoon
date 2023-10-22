n, m = map(int, input().split())
comb = [[0] * 101 for _ in range(n + 1)]
comb[1][0] = 1
comb[1][1] = 1
for row in range(2, n + 1):
    for col in range(row + 1):
        if col == 0 or col == row:
            comb[row][col] = 1
        else:
            comb[row][col] = comb[row - 1][col - 1] + comb[row - 1][col]
print(comb[n][m])
