import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())

grid = [list(map(int,input().split())) for _ in range(N)]
diff = [[0] * M for _ in range(N)]

totalCnt = 0
for i in range(N):
	for j in range(M):
		if grid[i][j] != 0: #ice
			totalCnt += 1

def bfs():

	found = False
	for i in range(N):
		for j in range(M):
			if grid[i][j] != 0: # first ice
				(sy, sx) = (i, j)
				found = True
				break
		if found:
			break

	q = deque([(sy,sx)])
	visited = [[False] * M for _ in range(N)]
	visited[sy][sx] = True
	visitedCnt = 1

	while q:
		(cy, cx) = q.popleft()
		for dy, dx in [(0,1),(1,0),(-1,0),(0,-1)]:
			ny = cy + dy
			nx = cx + dx
			if 0 <= ny < N and 0 <= nx < M and not visited[ny][nx]:
				if grid[ny][nx] == 0: # ocean
					diff[cy][cx] += 1
				else: # ice
					visitedCnt += 1
					visited[ny][nx] = True
					q.append((ny,nx))
	return visitedCnt


def melt():
	global totalCnt
	# print(f"diff\n{diff}\n")
	for i in range(N):
		for j in range(M):
			if grid[i][j] == 0:
				continue
			grid[i][j] = max(grid[i][j] - diff[i][j], 0)
			diff[i][j] = 0
			if grid[i][j] == 0:
				totalCnt -= 1
	# print(grid)
	return
	
def solution():

	day = 0
	while totalCnt:
		diff = [[0] * M for _ in range(N)]
		oneCnt = bfs()
		# print(f"total: {totalCnt} oneCnt:{oneCnt}")
		if totalCnt != oneCnt:
			return day
		day += 1
		melt()

	return 0

print(solution())