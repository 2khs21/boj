import heapq

def main():
	n = int(input())
	m = int(input())

	arr = [[] for _ in range(n+1)]
	dis = [1e8] * (n + 1)

	for i in range(m):
		u, v, w = map(int, input().split())
		arr[u].append((w, v))

	start, dest = map(int, input().split())

	dis[start] = 0
	q = []
	heapq.heappush(q, (0, start))
	
	while q:
		weight, curr = heapq.heappop(q)

		if weight > dis[curr]:
			continue
	
		for cw, next in arr[curr]:
			
			nw = dis[curr] + cw

			if nw < dis[next]:
				dis[next] = nw
				heapq.heappush(q, (nw, next))

		
	print(dis[dest])


main()