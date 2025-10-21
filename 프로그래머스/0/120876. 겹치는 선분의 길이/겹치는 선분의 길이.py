def solution(lines):

	lst = [0] * 201
	# print(lst)

	answer = 0
	for line in lines:
		s,e = line
		s += 100
		e += 100
		for i in range(s, e):
			lst[i] += 1
			if lst[i] == 2:
				answer += 1

	

	return answer