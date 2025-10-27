N, M = list(map(int, input().strip().split()))
sequence = []

def dfs(start):
    if len(sequence) == M:
        print(' '.join(map(str, sequence)))
        return
    
    for i in range(start, N + 1):
        sequence.append(i)
        dfs(i + 1)
        sequence.pop()

def solution():
    dfs(1)

solution()