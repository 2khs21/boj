import sys

input = sys.stdin.readline
# sys.setrecursionlimit(10**6)

R, C = map(int, input().split())

grid = [input() for _ in range(R)]
steps = [[0] * C for _ in range(R)]

answer = 0
visited = [[False] * C for _ in range(R)]
alphabet = [False] * 26

def backtracking(pos,cnt):
	cy, cx = pos
	steps[cy][cx] = cnt
	global answer
	answer = max(answer, cnt)
	# print(steps)
	# print(visited)
	# print("\n")
	for dy, dx in [(0,1),(0,-1),(1,0),(-1,0)]:
		ny = cy + dy
		nx = cx + dx
		if 0 <= ny < R and 0 <= nx < C and not visited[ny][nx] and not alphabet[ord(grid[ny][nx]) - ord('A')]:
			visited[ny][nx] = True
			alphabet[ord(grid[ny][nx]) - ord('A')] = True
			backtracking((ny,nx),cnt+1)
			visited[ny][nx] = False
			alphabet[ord(grid[ny][nx]) - ord('A')] = False
			steps[ny][nx] = 0


def solution():
	global answer
	visited[0][0] = True
	alphabet[ord(grid[0][0]) - ord('A')] = True
	# print(f"{ord(grid[0][0])} - {ord('A')}")
	backtracking((0,0),1)
	return answer

print(solution())