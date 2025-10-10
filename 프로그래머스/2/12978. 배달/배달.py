import heapq

def solution(N, roads, K):
    INF = 10**18
    graph = [[] for _ in range(N + 1)]
    for u, v, w in roads:
        graph[u].append((v, w))
        graph[v].append((u, w))

    dist = [INF] * (N + 1)
    dist[1] = 0
    hq = []
    heapq.heappush(hq, (0, 1))  # (거리, 정점)

    while hq:
        d, u = heapq.heappop(hq)
        if d > dist[u]:
            continue
        for v, w in graph[u]:
            nd = d + w
            if nd < dist[v]:
                dist[v] = nd
                heapq.heappush(hq, (nd, v))

    # dist[i] <= K 인 i 개수 세기 (1번 포함)
    answer = sum(1 for i in range(1, N + 1) if dist[i] <= K)
    return answer