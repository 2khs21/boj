n, k = map(int, input().split())

arr = [ [0 for _ in range(k)] for _ in range(n + 1)]

for i in range(n + 1):
	arr[i][0] = 1

for x in range(k):
	if x == 0:
		continue
	for y in range(n + 1):
		if y == 0:
			arr[y][x] = 1
		else:
			arr[y][x] = (arr[y-1][x] + arr[y][x-1]) % 1000000000

print(arr[n][k-1])