from collections import deque

def solve():
    A, K = map(int, input().split())
    # visited[x] = True 면 x 값은 이미 최소 연산으로 도달한 상태
    visited = [False] * (K + 1)
    q = deque()
    q.append((A, 0))
    visited[A] = True

    while q:
        x, steps = q.popleft()
        if x == K:
            print(steps)
            return

        # 연산 1: +1
        nx = x + 1
        if nx <= K and not visited[nx]:
            visited[nx] = True
            q.append((nx, steps + 1))
        # 연산 2: *2
        nx = x * 2
        if nx <= K and not visited[nx]:
            visited[nx] = True
            q.append((nx, steps + 1))

if __name__ == "__main__":
    solve()