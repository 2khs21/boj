path = [
    [i * 2 for i in range(21)],
    [10, 13, 16, 19, 25, 30, 35, 40],
    [20, 22, 24, 25, 30, 35, 40],
    [30, 28, 27, 26, 25, 30, 35, 40]
]
blockIndex = [
    [i for i in range(21)],
    [5, 21, 22, 23, 29, 30, 31, 20],
    [10, 24, 25, 29, 30, 31, 20],
    [15, 26, 27, 28, 29, 30, 31, 20]
]

dices = list(map(int, input().strip().split()))
curVal = [0]
answer = [0]
positions = [[0,0] for _ in range(4)] # lane, index
reached = [False,False,False,False]

def getVal(piece):
    lane = positions[piece][0]
    index = positions[piece][1]
    return path[lane][index]

def getBlockIndex(piece):
    lane = positions[piece][0]
    index = positions[piece][1]
    return blockIndex[lane][index]

# return T/F
def isReachable(piece, dice):
    curLane = positions[piece][0]
    nextIndex = positions[piece][1] + dice
    lastIndex = len(path[curLane])

    if lastIndex > nextIndex: # 아직 안도착
        return False
    return True # 도착


def isMovable(piece, dice):
    curLane = positions[piece][0]
    nextIndex = positions[piece][1] + dice

    nextBlockIndex = blockIndex[curLane][nextIndex]
    for otherPiece in range(4):
        if otherPiece == piece or reached[otherPiece] == True:
            continue
        other = getBlockIndex(otherPiece)
        if nextBlockIndex == other:
            return False
    return True


def backTracking(diceIndex):
    # print(f"backTracking {diceIndex}")

    if diceIndex == 10:
        return
    dice = dices[diceIndex]
    for i in range(4):

        if reached[i] == True:
            continue # 이미 도착한 친구
        elif isReachable(i, dice) == True: # 이동하면 도착 ,점수 추가 x
            # print("Reachable True")
            reached[i] = True
            backTracking(diceIndex + 1)
            reached[i] = False
            continue
        elif isMovable(i, dice) == False: # 이동 불가
            # print("movable False")
            continue
        # 이동 가능, 점수추가, 이동
        curLane = positions[i][0]
        curIndex = positions[i][1]
        nextLane = curLane
        nextIndex = curIndex + dice

        if curLane == 0 and nextIndex in (5,10,15):
            nextLane = nextIndex // 5
            nextIndex = 0
            positions[i][0] = nextLane
            positions[i][1] = 0
        else:
            positions[i][0] = nextLane
            positions[i][1] = nextIndex
        
        addVal = getVal(i)
        curVal[0] += addVal
        # if (answer[0] < curVal[0]):
        #     print(f"addVal : {addVal}")
        answer[0] = max(answer[0], curVal[0])

        backTracking(diceIndex + 1)

        curVal[0] -= addVal
        positions[i][0] = curLane
        positions[i][1] = curIndex

    return

def solution():
    backTracking(0)
    print(answer[0])
    return

solution()