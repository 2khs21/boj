def main():
	expr = input().strip()
	parts = expr.split('-')

	total = sum(map(int, parts[0].split('+')))

	for part in parts[1:]:
		total -= sum(map(int, part.split('+')))

	print(total)

main()

