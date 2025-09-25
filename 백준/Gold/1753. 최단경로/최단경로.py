import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)  # 무한대 값 (도달 불가를 표시)

# 입력
V, E = map(int, input().split())
K = int(input())
graph = [[] for _ in range(V + 1)]   # 인접 리스트
distance = [INF] * (V + 1)           # 최단 거리 테이블

# 간선 입력
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))  # (도착 노드, 가중치)

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))  # (거리, 노드)
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        # 이미 처리된 노드라면 무시
        if distance[now] < dist:
            continue
        # 인접 노드 확인
        for next_node, w in graph[now]:
            cost = dist + w
            if cost < distance[next_node]:
                distance[next_node] = cost
                heapq.heappush(q, (cost, next_node))

# 실행
dijkstra(K)

# 출력
for i in range(1, V + 1):
    print(distance[i] if distance[i] != INF else "INF")