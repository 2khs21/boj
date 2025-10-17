def createGrid(n):
    size = 4 * n - 3
    grid = [[' ' for _ in range(size)] for _ in range(size)]
    return grid

def getCenter(n):
    size = 4 * n - 3
    cx = cy = size // 2
    return cx, cy

def drawR(grid, center_x, center_y, n):
    length = 4 * n - 3

    start = center_x - (length // 2)
    end = center_x + (length // 2)
    
    for x in range(start, end + 1):
        grid[start][x] = '*'
        grid[end][x] = '*'
    
    for y in range(start + 1, end):
        grid[y][start] = '*'
        grid[y][end] = '*'
        
def printGrid(grid):
    for row in grid:
        print(''.join(row))
        

n = int(input())
grid = createGrid(n)
cx, cy = getCenter(n)

while(n):
    drawR(grid, cx, cy, n)
    n -= 1

printGrid(grid)