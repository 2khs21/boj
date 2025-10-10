import sys
from collections import deque
input = sys.stdin.readline

def solve():
    n = int(input().strip())
    board = [list(map(int, input().split())) for _ in range(n)]
    visited = [[False] * n for _ in range(n)]
    q = deque()
    q.append((0, 0))
    visited[0][0] = True

    while q:
        x, y = q.popleft()
        # 만약 board[x][y] 이 -1 이면 도착
        if board[x][y] == -1:
            print("HaruHaru")
            return

        jump = board[x][y]
        for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
            nx, ny = x + dx * jump, y + dy * jump
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                visited[nx][ny] = True
                q.append((nx, ny))

    # 큐 소진했는데 도착 못 함
    print("Hing")

if __name__ == "__main__":
    solve()