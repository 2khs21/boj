def matrixAdd(X, Y):
		return [[x + y for x, y in zip(row_x, row_y)] for row_x, row_y in zip(X, Y)]

def spin(matrix):
		return [list(row[::-1]) for row in zip(*matrix)]

cnt = [0]

def addOneFish():
	# 가장 적은곳들 한 마리씩 추가
	minValue = min(arr)
	for i in range(N):
		if arr[i] == minValue:
			arr[i] += 1

def folding(tank):
		upperX = len(tank[0])
		upperY = len(tank)
		newTank = [row[:upperX] for row in tank]
		newTank = spin(newTank)
		newTank.append(tank[-1][upperX:])

		return newTank

def arrangeFish():
		# 물고기 추가 할지말지 
	global tank
	addFishGrid = [[0 for _ in row] for row in tank]
	dx = [-1, 0, 1, 0]
	dy = [0, -1, 0, 1]
	
	for cy, row in enumerate(tank):
		
		for cx, e in enumerate(row):
			for dir in range(4):
				ny = cy + dy[dir]
				nx = cx + dx[dir]
				if 0 <= ny < len(tank) and 0 <= nx < len(tank[ny]):
					d = abs(tank[ny][nx] - tank[cy][cx]) // 5
					
					if d == 0:
						continue
					if tank[ny][nx] > tank[cy][cx]: # 주변보다 적어서 추가
						addFishGrid[cy][cx] += d
					elif tank[ny][nx] < tank[cy][cx]:
						addFishGrid[cy][cx] -= d

	tank = matrixAdd(tank, addFishGrid)
	# print(tank)
	return


def isArrangd():
	cnt[0] += 1
	
	# 한마리씩 추가
	addOneFish()
	global tank
	global arr
	tank = [[arr[1], arr[0]], arr[2:]]

	# print(f"here{tank}")

	# print(f"== cut : {cnt[0]} ==")
	# 접기
	
	# print(tank)
	while True:
		nextX = len(tank)
		availableX = len(tank[-1]) - len(tank[0])
		if nextX > availableX:
			break
		tank = folding(tank)
		# print(f"folding\n{tank}")
	
	
	arrangeFish()

	# print(f"arrangeFish\n{tank}")

	tank = [x for row in zip(*tank[::-1]) for x in row] + tank[-1][len(tank[0]):]

	# print(f"flatten\n{tank}")

	tank = [tank[:N // 2][::-1], tank[N//2:]]

	leftSide = [tank[0][:N//4], tank[1][:N//4]]
	rightSide = [tank[0][N//4:], tank[1][N//4:]]

	upSide = spin(spin(leftSide))
	downSide = rightSide
	
	tank = [x for row in (upSide, downSide) for x in row]
	# print(f"refolding\n{tank}")
	arrangeFish()
	# print(f"reArrangeFish\n{tank}")

	tank = [x for row in list(zip(*tank)) for x in row[::-1] ]
	arr = tank
	# print(f"reFlatten{tank}")
	# print("\n")

	# print(f"dif : {max(tank) - min(tank)}")
	
	if (max(tank) - min(tank) <= K):
		return True
	return False
				


			


def solution():
	while isArrangd() == False:
			
			continue
	
	print(cnt[0])
	return cnt[0]


(N, K) = list(map(int, input().strip().split()))
arr = list(map(int, input().strip().split()))
tank = []

solution()
