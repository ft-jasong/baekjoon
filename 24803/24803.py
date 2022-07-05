import sys

def solution():
	input = sys.stdin.readline
	g, s, c = map(int, input().split())
	bp = 3 * g + 2 * s + 1 * c
	vpcard = ['Province', 'Duchy', 'Estate']
	trcard = ['Gold', 'Silver', 'Copper']
	ans = []
	if bp < 2:
		ans.append(trcard[2])
	elif bp < 3:
		ans.append(vpcard[2])
		ans.append(trcard[2])
	elif bp < 5:
		ans.append(vpcard[2])
		ans.append(trcard[1])
	elif bp < 6:
		ans.append(vpcard[1])
		ans.append(trcard[1])
	elif bp < 8:
		ans.append(vpcard[1])
		ans.append(trcard[0])
	else:
		ans.append(vpcard[0])
		ans.append(trcard[0])
	if len(ans) == 1:
		print(ans[0])
	else:
		print(ans[0], 'or', ans[1])

solution()