answer = [0]

def dfs(idx, cur):
		
		if idx == n:
				return
		

		if cur + arr[idx] == S:
				answer[0] += 1
		dfs(idx + 1, cur + arr[idx])
		dfs(idx + 1, cur)

n, S = map(int, input().split())
arr = list(map(int, input().split()))

dfs(0, 0)

print(answer[0])