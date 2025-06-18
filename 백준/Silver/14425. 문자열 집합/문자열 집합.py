def main():
	N, M = map(int, input().split())

	s = set()
	for i in range(N):
		s.add(input())

	ans = 0
	for i in range(M):
		target = input()
		if target in s:
			ans += 1

	print(ans)

main()

