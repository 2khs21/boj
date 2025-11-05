import sys
sys.setrecursionlimit(200000)
input = sys.stdin.readline

N, R, Q = map(int, input().split())

edges = [[] for _ in range(N + 1)]

for _ in range(N - 1):
		u, v = map(int, input().split())
		edges[u].append(v)
		edges[v].append(u)

hasEnds = [1] * (N + 1)

def dfs(cur, parent):
		candidList = edges[cur]
		is_end = True
		for candid in candidList:
				if candid == parent:
					continue
				else:
					is_end = False
					dfs(candid, cur)
					hasEnds[cur] += hasEnds[candid]

		if is_end == True:
			hasEnds[cur] = 1

dfs(R, 0)
answer = []
for _ in range(Q):
	node = int(input())
	answer.append(hasEnds[node])

for e in answer:
	print(e)								