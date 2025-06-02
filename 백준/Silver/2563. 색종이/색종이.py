def main():
	n = int(input())

	ans = 0
	white = [[0] * 100 for i in range(100)]


	for _ in range(n):
			x, y = map(int, input().split())
			for i in range(10):
					for j in range(10):
							if white[y + i][x + j] == 0:
									ans += 1
									white[y + i][x + j] = 1
							
	print(ans)

main()