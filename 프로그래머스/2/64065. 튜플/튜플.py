def solution(s):
	s = s[2:-2]
	tmp = s.split('},{')
	
	
	lsts = [list(map(int, item.split(','))) for item in tmp]
	
	lsts = sorted(lsts, key=lambda x : len(x))

	# print(lsts)
	
	answer = []
	for lst in lsts:
		diff = set(lst) - set(answer)
		answer.append(list(diff)[0])
		# print(answer)
	return answer