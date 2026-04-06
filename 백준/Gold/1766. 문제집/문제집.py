import sys
from queue import PriorityQueue
from collections import deque 

input = sys.stdin.readline
  
def solution():
	N,M = map(int, input().split())

	graph = [[] for _ in range(N+1)]
	indegree = [0] * (N+1)

	for _ in range(M):
			prv, nxt = map(int, input().split())
			graph[prv].append(nxt)
			indegree[nxt] += 1

	# print(graph)
	pq = PriorityQueue()

	for i in range(1, N+1):
			if indegree[i] == 0:
					pq.put(i)
					
	result = []

	while not pq.empty():
			# print(f"size: {pq.qsize()}")
			cur = pq.get()
			result.append(cur)
			for nxt in graph[cur]:
					indegree[nxt] -= 1
					if indegree[nxt] == 0:
							pq.put(nxt)
	return result

print(*solution())
    