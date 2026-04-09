import sys

input = sys.stdin.readline

N, S = list(map(int,input().split()))

seq = list(map(int, input().split()))

# print(seq)
def solution():
	st = 0
	en = 0

	val = seq[0]
	answer = N + 1
	while st <= en and en < N:
		if val == S:
			answer = min(answer, en - st + 1)
			val -= seq[st]
			st += 1
			en += 1
			if en < N:
				val += seq[en]
		elif val > S:
			answer = min(answer, en - st + 1)
			val -= seq[st]
			st += 1
		elif val < S:
			en +=1
			if en < N:
				val += seq[en]
	
	if answer == N+1:
		return 0
	return answer
print(solution())
