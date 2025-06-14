def main():
	s = input()

	subs = set()
	for i in range(len(s)):
		for j in range(i + 1, len(s) + 1):
			subs.add(s[i:j])

	print(len(subs))

main()