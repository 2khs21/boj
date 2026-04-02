from collections import deque

n = int(input())

grid = [list(map(int, input().split())) for _ in range(n)]
# print(grid)
min_val = min(min(row) for row in grid)
max_val = max(max(row) for row in grid)

def bfs(low, high):

	visited = [[False] * n for _ in range(n)]
	dir = ((-1,0),(0,-1),(1,0),(0,1))

	queue = deque([(0,0)])
	visited[0][0] = True

	while queue:
		cy, cx = queue.popleft()

		for dy, dx in dir:
			ny = cy + dy
			nx = cx + dx
			if 0 <= ny < n and 0 <= nx < n and not visited[ny][nx] and low <= grid[ny][nx] <= high:
				visited[ny][nx] = True
				# print(f"ny,nx : val {ny},{nx},{visited[ny][nx]}")
				queue.append((ny,nx))
	return visited[n-1][n-1]

def can(diff):
	# print(f"diff {diff}")
	for i in range(max_val - (min_val + diff) + 1):
		low = min_val + i
		high = low + diff
		if low <= grid[0][0] <= high and bfs(low, high):
			# print("True")
			return True
	return False
	

def solution():

	left = 0
	right = max_val - min_val
	answer = right
	while left <= right:
		# print(f"l {left} r {right}")
		mid = (left + right) // 2 # 1,4   2
		if can(mid):
			answer = mid
			right = mid - 1
		else:
			left = mid + 1
	return answer


print(solution())
