import sys

input = sys.stdin.readline

s1 = input().strip()
s2 = input().strip()
    
def solution():
	grid = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]

	for i in range(1, len(s1) + 1):
			for j in range(1, len(s2) + 1):
					if s1[i - 1] == s2[j - 1]:
							grid[i][j] = grid[i - 1][j - 1] + 1
					else:
							grid[i][j] = max(grid[i - 1][j], grid[i][j - 1])

	answer = []

	i = len(s1)
	j = len(s2)

	while i > 0 and j > 0:
			if s1[i - 1] == s2[j - 1]:
					answer.append(s1[i - 1])
					i -= 1
					j -= 1
			elif grid[i - 1][j] > grid[i][j - 1]:
					i -= 1
			else:
					j -= 1

	answer.reverse()

	# print(grid[len(s1)][len(s2)])
	print(len(answer))
	if answer:
			print(''.join(answer))

solution()