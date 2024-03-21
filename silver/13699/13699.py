def recurrence(n: int) -> list:
    li = [1]
    for i in range(1, n + 1):
        sum_ = 0
        for j in range(i):
            sum_ += li[i - j - 1] * li[j]
        li.append(sum_)
    print(li[n])

if __name__ == '__main__':
    n = int(input())
    recurrence(n)