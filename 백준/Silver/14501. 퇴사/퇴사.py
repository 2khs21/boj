n = 0
pairs = []
ans = 0

def fun(total, idx):
	global ans
	# print(total)
	ans = max(ans, total)
	if (idx >= n):
		return
	elif (idx + pairs[idx][0] <= n) :
		fun(total + pairs[idx][1], idx + pairs[idx][0])
	fun(total, idx + 1)

def main():
	global n
	n = int(input())
	for i in range(n):
		a, b = map(int, input().split())
		pairs.append((a,b))
	fun(0, 0)
	print(ans)

main()