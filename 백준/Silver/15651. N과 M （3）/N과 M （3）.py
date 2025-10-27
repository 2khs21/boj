N, M = map(int, input().split())
sequence = []

def dfs(depth):
    if depth == M:
        print(' '.join(map(str, sequence)))
        return

    for i in range(1, N + 1):
        sequence.append(i)
        dfs(depth + 1)
        sequence.pop()

def solution():
    dfs(0)

solution()