def main():
	n = int(input())
	arr = set(map(int, input().split()))
	m = int(input())

	target = list(map(int, input().split()))
	for e in target:
		if e in arr:
			print(1)
		else:
			print(0)

main()