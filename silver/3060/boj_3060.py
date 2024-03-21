tc = int(input())
for _ in range(tc):
    daily_meal = int(input())
    *meals, = map(int, input().split())
    new_meals = meals.copy()
    ans = 1
    while True:
        if sum(new_meals) > daily_meal:
            break
        for i in range(6):
            new_meals[i] += meals[(i - 1) % 6] + meals[(i + 1) % 6] + meals[(i + 3) % 6]
        ans += 1
        meals = new_meals.copy()
    print(ans)