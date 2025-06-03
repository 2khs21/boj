def main():
	n = int(input())
	ans = []

	for i in range(n):
		s = input()
		stack = []
		for c in s:
			if c == '(':
				stack.append(c)
			elif c == ')':
				if stack and stack[-1] == '(':
					stack.pop()
				else:
					stack.append(c)
		if stack:
			ans.append("NO")
		else:
			ans.append("YES")
	for e in ans:
		print(e)

main()