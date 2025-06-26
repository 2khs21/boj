gears = [list(input().strip()) for _ in range(4)]
states = [0,0,0,0]

N = 0
S = 1
L = 0
R = 1


def getLR(i):
	Li = gears[i][(6 - states[i]) % 8]
	Ri = gears[i][(2 - states[i]) % 8]
	return Li, Ri

def rotateGear(i, dir):
	rotateDir = [0,0,0,0]
	rotateDir[i] = dir
	ValueLR = [getLR(i) for i in range(4)]

	curr = i
	while curr < 3:
		next = curr + 1
		if ValueLR[curr][R] == ValueLR[next][L]:
			pass
		else:
			rotateDir[next] = rotateDir[curr] * -1
		curr += 1

	curr = i
	while curr > 0:
		prev = curr -1
		if ValueLR[curr][L] == ValueLR[prev][R]:
			pass
		else:
			rotateDir[prev] = rotateDir[curr] * -1
		curr -= 1

	for i in range(4):
		states[i] += rotateDir[i]

for num in range(int(input())):
	i, dir = map(int, input().split())
	rotateGear(i - 1, dir)

ans = 0
for i in reversed(range(4)):
	ans = (ans << 1)
	ans += int(gears[i][-states[i] % 8])

print(ans)