import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

# 입력
N, E = map(int, input().split())
graph = [[] for _ in range(N + 1)]
for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))  # 양방향

v1, v2 = map(int, input().split())

def dijkstra(start):
    dist = [INF] * (N + 1)
    q = []
    heapq.heappush(q, (0, start))
    dist[start] = 0
    while q:
        cost, now = heapq.heappop(q)
        if dist[now] < cost:
            continue
        for nxt, w in graph[now]:
            nxt_cost = cost + w
            if nxt_cost < dist[nxt]:
                dist[nxt] = nxt_cost
                heapq.heappush(q, (nxt_cost, nxt))
    return dist

# 다익스트라 3번 실행
dist_1 = dijkstra(1)
dist_v1 = dijkstra(v1)
dist_v2 = dijkstra(v2)

# 두 경로 계산
path1 = dist_1[v1] + dist_v1[v2] + dist_v2[N]
path2 = dist_1[v2] + dist_v2[v1] + dist_v1[N]

answer = min(path1, path2)
print(answer if answer < INF else -1)