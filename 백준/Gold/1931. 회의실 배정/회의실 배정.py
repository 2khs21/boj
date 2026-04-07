import sys
from collections import deque

input = sys.stdin.readline

N = int(input())

times = [(list(map(int,input().split()))) for _ in range(N)]

times.sort()

# print(times)

def solution():
	end = times[0][1]
	s = deque()
	s.append(times[0])

	for i in range(1, N):
		if end <= times[i][0]:
			s.append(times[i])
			end = times[i][1]
		elif end > times[i][1]:
			s.popleft()
			s.append(times[i])
			end = times[i][1]

	# print(s)
	return len(s)

print(solution())