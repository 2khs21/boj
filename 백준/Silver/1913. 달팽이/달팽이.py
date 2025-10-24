def fillGrid(n, grid):
    y, x = n // 2, n // 2
    grid[y][x] = 1

    # 상우하좌
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    num = 2
    step = 1
    dir_idx = 0

    while num <= n * n:
        for _ in range(2):
            for _ in range(step):
                if num > n * n:
                    break
                y += dy[dir_idx]
                x += dx[dir_idx]
                grid[y][x] = num
                num += 1
            dir_idx = (dir_idx + 1) % 4
        step += 1

def findTarget(n, grid, target):
    for i in range(n):
        for j in range(n):
            if grid[i][j] == target:
                return (i + 1, j + 1)
    return None

def printGrid(n, grid):
    for i in range(n):
        print(' '.join(map(str, grid[i])))

def printAnswer(answer):
    print(answer[0], answer[1])

def solution(n, target):
    grid = [[0] * n for _ in range(n)]
    fillGrid(n, grid)
    answer = findTarget(n, grid, target)
    printGrid(n, grid)
    printAnswer(answer)

n = int(input())
target = int(input())
solution(n, target)