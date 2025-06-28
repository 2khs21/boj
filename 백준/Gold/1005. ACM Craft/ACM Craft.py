import sys

from collections import deque
input = sys.stdin.readline


T = int(input())


def fun():
	nodeCnt, ruleCnt = map(int, input().split())
	

	cost = list(map(int, input().split()))
	deg = [0] * nodeCnt
	ans = cost[:]

	arr = [[] for _ in range(nodeCnt)]

	for _ in range(ruleCnt):
		x,y = map(int, input().split())
		arr[x-1].append(y-1)
		deg[y-1] += 1

	q = deque()
	for i in range(nodeCnt):
		if deg[i] == 0:
			q.append(i)
	
	while q:
		i = q.popleft()
		for nxt in arr[i]:
			deg[nxt] -= 1
			ans[nxt] = max(ans[nxt], ans[i] + cost[nxt]) # 비교
			if deg[nxt] == 0:
				q.append(nxt)
	
	target = int(input()) - 1
	print(ans[target])



for _ in range(T):
	fun()
