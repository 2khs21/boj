def main():
	src = input()

	val = 1
	state = src[0]
	for e in src[1:]:
		if e == state:
			pass
		else :
			val += 1
			state = e

	print(val // 2)
main()
