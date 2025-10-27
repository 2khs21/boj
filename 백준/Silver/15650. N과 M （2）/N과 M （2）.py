N, M = list(map(int, input().strip().split()))
used = [False] * (N + 1)
sequence = []


def dfs(depth):
	if depth == M:
		print(' '.join(map(str, sequence)))
		return
	
	for i in range(1, N+1):
		
		if sequence and sequence[-1] > i: # 추가된 조건문
			continue

		if not used[i]:
			used[i] = True
			sequence.append(i)
			dfs(depth + 1)
			sequence.pop()
			used[i] = False

def solution():
	dfs(0)

solution()