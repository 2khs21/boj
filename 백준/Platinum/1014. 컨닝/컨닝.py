import sys
input = sys.stdin.readline

def solution():
	N, M = map(int, input().split())
	seats = [input().strip() for _ in range(N)]

	# 가능한 행 상태 리스트
	valid_states = []

	for row in range(N):
			mask = 0
			for col in range(M):
					if seats[row][col] == 'x':
							mask |= (1 << col)
			valid_states.append(mask)

	# dp[row][state] = 최대 학생 수
	dp = [{} for _ in range(N)]

	def is_valid(state, forbidden):
			if (state & forbidden) != 0: # 못 앉는 자리 확인
					return False
			if (state & (state >> 1)) != 0: # 좌우 확인
					return False
			return True

	for state in range(1 << M):
			if is_valid(state, valid_states[0]):
					dp[0][state] = bin(state).count('1')

	for r in range(1, N):
			for state in range(1 << M): # 2^(한 줄 의자 길이)
					if not is_valid(state, valid_states[r]):
							continue
					for prev_state, prev_val in dp[r-1].items():
							if (state & (prev_state >> 1)) != 0:
									continue
							if (state & (prev_state << 1)) != 0:
									continue
							dp[r][state] = max(dp[r].get(state, 0), prev_val + bin(state).count('1')) # max(기존값, 이전 상태 학생 수+ 현재 학생 수)

	print(max(dp[N-1].values()))

C = int(input().strip())
for _ in range(C):
	solution()