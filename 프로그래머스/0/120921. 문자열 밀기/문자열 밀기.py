def solution(A, B):
		
		n = len(A)
		for i in range(n):
			tmp = A[n-i:] + A[:n-i]
		
			if tmp == B:
				return i
		return -1
		