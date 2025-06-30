import sys

from collections import deque
input = sys.stdin.readline


def solution():
	N, M = map(int, input().split())
	grid = [input().strip() for _ in range(N)]

	dist = [[[-1]*2 for _ in range(M) ] for _ in range(N)]

	q = deque()
	dist[0][0][0] = 1
	q.append((0,0,0))
	
	while q:
		x,y,used = q.popleft()
		for dx,dy in ((1,0), (-1,0), (0,1), (0,-1)):
			nx, ny = x + dx, y + dy

			if not (0 <= nx < M and 0 <= ny < N):
				continue

			if grid[ny][nx] == '0' and dist[ny][nx][used] == -1:
				dist[ny][nx][used] = dist[y][x][used] + 1
				q.append((nx,ny,used))

			elif grid[ny][nx] == '1' and used == 0 and dist[ny][nx][1] == -1:
				dist[ny][nx][1] = dist[y][x][0] + 1
				q.append((nx,ny,1))

	res0 = dist[N-1][M-1][0]
	res1 = dist[N-1][M-1][1]
	ans = min([v for v in (res0, res1) if v != -1], default= -1)
	print(ans)

solution()