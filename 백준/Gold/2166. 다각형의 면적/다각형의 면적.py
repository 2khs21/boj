import sys

input = sys.stdin.readline

N = int(input())
points = [tuple(map(int, input().split())) for _ in range(N)]

def solution():
	area = 0

	for i in range(N):
			x1, y1 = points[i]
			x2, y2 = points[(i + 1) % N]
			area += x1 * y2
			area -= y1 * x2
    
	return round(abs(area) / 2, 1)

print(solution())