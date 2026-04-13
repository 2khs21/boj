import sys
from collections import deque 

input = sys.stdin.readline
N, K = map(int, input().split())

def solution():
	answer = 0

	baby = [-1] * 500001
	visited = [[-1] * 500001 for _ in range(2)]

	bi = K
	cnt = 0
	while bi + cnt <= 500000:
		bi = bi + cnt
		baby[bi] = cnt
		cnt += 1
	
	visited[0][N] = 0
	q = deque([N])

	day = 1
	
	nxt = deque()		
	while q:
		cur = q.popleft()
		steps = [cur - 1, cur + 1, cur * 2]

		for step in steps:
			if 0 <= step <= 500000 and visited[day % 2][step] == -1:
				visited[day % 2][step] = day
				nxt.append(step)

		if not q:
			q = nxt
			nxt = deque()
			day += 1

	answer = 500001
	for i in range(500001):
		if baby[i] != -1 and visited[baby[i] % 2][i] != -1 and baby[i] >= visited[baby[i] % 2][i]: # encounter
				answer = min(answer, baby[i])
	
	
	return answer if answer < 500001 else -1

print(solution())
