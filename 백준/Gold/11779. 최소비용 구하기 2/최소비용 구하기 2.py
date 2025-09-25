import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

N = int(input())
M = int(input())
graph = [[] for _ in range(N + 1)]
distance = [INF] * (N + 1)
prev = [0] * (N + 1)   # 경로 복원을 위한 배열

for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

start, end = map(int, input().split())

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        cost, now = heapq.heappop(q)
        if distance[now] < cost:
            continue
        for nxt, w in graph[now]:
            nxt_cost = cost + w
            if nxt_cost < distance[nxt]:
                distance[nxt] = nxt_cost
                prev[nxt] = now      # ✅ 경로 추적
                heapq.heappush(q, (nxt_cost, nxt))

# 실행
dijkstra(start)

# 최소 비용 출력
print(distance[end])

# 경로 복원
path = []
node = end
while node:
    path.append(node)
    node = prev[node]
path.reverse()

# 경로 정보 출력
print(len(path))
print(*path)