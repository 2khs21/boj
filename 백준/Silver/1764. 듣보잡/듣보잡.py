
def main():
	n, m = list(map(int, input().split()))
	noSee = []
	noHear = []
	for i in range(n):
		noSee.append(input())
	for i in range(m):
		noHear.append(input())
	ansList = set(noSee) & set(noHear)
	print(len(ansList))
	for e in sorted(ansList):
		print(e)

main()