import sys
input = sys.stdin.readline

def solve():
    R, C = map(int, input().split())
    mine = [input().rstrip() for _ in range(R)]
    
    ld = [[0] * C for _ in range(R)]
    rd = [[0] * C for _ in range(R)]
    lu = [[0] * C for _ in range(R)]
    ru = [[0] * C for _ in range(R)]
    
    for i in range(R):
        for j in range(C):
            if mine[i][j] == '1':
                if i == 0:
                    ld[i][j] = rd[i][j] = 1
                else:
                    if j > 0:
                        ld[i][j] = ld[i-1][j-1] + 1
                    else:
                        ld[i][j] = 1
                    if j < C - 1:
                        rd[i][j] = rd[i-1][j+1] + 1
                    else:
                        rd[i][j] = 1
    
    for i in range(R-1, -1, -1):
        for j in range(C):
            if mine[i][j] == '1':
                if i == R - 1:
                    lu[i][j] = ru[i][j] = 1
                else:
                    if j > 0:
                        lu[i][j] = lu[i+1][j-1] + 1
                    else:
                        lu[i][j] = 1
                    
                    if j < C - 1:
                        ru[i][j] = ru[i+1][j+1] + 1
                    else:
                        ru[i][j] = 1
    
    max_size = 0
    

    for i in range(R):
        for j in range(C):
            if mine[i][j] == '1':

                max_possible = min(ru[i][j], lu[i][j])

                for k in range(max_possible, 0, -1):
                    bottom_i = i + 2 * (k - 1)

                    if bottom_i >= R:
                        continue
                    left_j = j - (k - 1)
                    right_j = j + (k - 1)
                    if left_j < 0 or right_j >= C:
                        continue

                    if rd[bottom_i][j] >= k and ld[bottom_i][j] >= k:
                        max_size = max(max_size, k)
                        break
    
    print(max_size)


solve()