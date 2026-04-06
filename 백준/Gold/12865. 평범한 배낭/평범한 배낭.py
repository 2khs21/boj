import sys
input = sys.stdin.readline

N, K = map(int, input().split())

items = [tuple(map(int,input().split())) for _ in range(N)]

def solution():
	dp = [[0] * 100001 for _ in range(101)]
	for i in range(1, N + 1):
		for j in range(K + 1):
			w = items[i-1][0]
			v = items[i-1][1]
			if j < w:
				dp[i][j] = dp[i-1][j]
			else:
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v)
	return dp[N][K]

print(solution())
	