from collections import deque

N = int(input())

arr = [list(input()) for _ in range(N)]

board = [ [0] * N for _ in range(N)]

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]


q = deque()

ans1 = 0
for y in range(N):
	for x in range(N):
		if board[y][x]:
			continue
		q.append((y, x))

		ans1 += 1
		while q:
			cy, cx = q.popleft()
			for i in range(4):
				ny, nx = cy + dy[i], cx + dx[i]
				if ny < 0 or ny >= N or nx < 0 or nx >= N:
					continue
				if board[ny][nx]:
					continue
				if arr[ny][nx] == arr[cy][cx]:
					board[ny][nx] = ans1
					q.append((ny,nx))

ans2 = 0
board = [ [0] * N for _ in range(N)]
for y in range(N):
	for x in range(N):
		if arr[y][x] == 'G':
			arr[y][x] = 'R'

for y in range(N):
	for x in range(N):
		if board[y][x]:
			continue
		q.append((y, x))

		ans2 += 1
		while q:
			cy, cx = q.popleft()
			for i in range(4):
				ny, nx = cy + dy[i], cx + dx[i]
				if ny < 0 or ny >= N or nx < 0 or nx >= N:
					continue
				if board[ny][nx]:
					continue
				if arr[ny][nx] == arr[cy][cx]:
					board[ny][nx] = ans1
					q.append((ny,nx))




print(ans1, ans2)