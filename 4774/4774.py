sum_ = 0
for _ in range(12):
	money = float(input())
	sum_ += money
average = sum_ / 12
average = round(average, 2)
print(f"${average}")