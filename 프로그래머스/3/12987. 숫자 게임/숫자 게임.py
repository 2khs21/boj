def solution(A, B):
		answer = 0
		
		A = sorted(A)
		B = sorted(B)

		i = 0
		for e in A:

			while i < len(B):
				if e < B[i]:
					answer += 1
					i = i + 1
					break
				else:
					i = i + 1
			

		return answer