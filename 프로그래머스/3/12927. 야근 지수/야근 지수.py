import heapq

def solution(n, works):
		answer = 0
		
		works = [-w for w in works]
		heapq.heapify(works)
		
		for _ in range(n):
			
			largest = heapq.heappop(works)
			if largest == 0:
				break
			
			heapq.heappush(works, largest + 1)


		return sum(w ** 2 for w in works)

n = 3