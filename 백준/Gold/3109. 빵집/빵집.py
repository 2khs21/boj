import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
ans = 0
r, c = map(int, input().split())
g = []
for _ in range(r):
    g.append(list(input().strip()))

def search(i, j):
    global ans
    if not(0<=i<r): 
        return False
    

    if j == c - 1:
        if g[i][j] == 'x':
            return False
        g[i][j] = 'x'
        ans += 1
        return True
    g[i][j] = 'x'

    for di in [-1, 0, 1]:
        ni = i + di
        nj = j + 1
        if 0 <= ni < r and 0 <= nj < c and g[ni][nj] == '.':
            if search(ni, nj):
                return True
    
    
    return False

for i in range(r):
    search(i, 0)

print(ans)