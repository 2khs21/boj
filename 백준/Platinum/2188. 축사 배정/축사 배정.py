import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

N, M = map(int, input().split())
adj = [[] for _ in range(N + 1)]
for i in range(1, N + 1):
		data = list(map(int, input().split()))
		s = data[0]
		for j in data[1:]:
				adj[i].append(j)

match = [0] * (M + 1)  # 축사 번호 → 어떤 소가 배정되었는지

def dfs(u, visited):
		for v in adj[u]: # 가능한 축사 번호
			if visited[v]: # 이번 DFS에서 방문한것이라면 continue
					continue
			visited[v] = True
			if match[v] == 0: # 비어있으면 바로 배정
					match[v] = u
					return True
			else: # 이미 소가 배정되어 있더라도
					if dfs(match[v], visited): # 그 소를 다른 축사로 갈 수 있는지 보자
							match[v] = u
							return True
		return False # 모든 축사를 확인했지만 넣지 못함

result = 0
for i in range(1, N + 1):
		visited = [False] * (M + 1)
		if dfs(i, visited): # i번 소 넣어보자
				result += 1

print(result)