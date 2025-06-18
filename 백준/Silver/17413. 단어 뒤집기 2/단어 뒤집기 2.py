def main():
	src = input()
	result = ''
	word = ''
	in_tag = False

	for ch in src:
		if ch == '<':
			in_tag = True
			result += word[::-1]
			word = ''
			result += ch
		elif ch == '>':
			in_tag = False
			result += ch
		elif in_tag:
			result += ch
		elif ch == ' ':
			result += word[::-1] + ' '
			word = ''
		else:
			word += ch
	result += word[::-1]
	print(result)

main()
