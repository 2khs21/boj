def main():
	s = list(input())

	s.sort(reverse=True)
	s = ''.join(s)
	print(s)

main()