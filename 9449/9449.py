from sys import stdin

def solution():
	W, H, w, h = map(int, stdin.readline().split())
	r = (W - w) // (w * 2)
	c = (H - h) // (h * 2)
	print(r * c)
solution()