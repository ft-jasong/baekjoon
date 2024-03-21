n = int(input())
fibo = [1, 1]
for i in range(2, n + 1):
    fibo.append(fibo[i - 1] + fibo[i - 2])
print(fibo[n - 1] * 2 + fibo[n] * 2)
