import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline


def dfs(u, d):
    
    global ans
    visited[u] = True
    ans = max(ans, d)

    for v, w in tree[u]:
        if not visited[v]:
            dfs(v, d + w)


def main():
    global tree, visited, ans

    N = int(input())

    tree = [[] for _ in range(N + 1)]

    for _ in range(N - 1):
        A, B, C = map(int, input().split())
        tree[A].append((B,C))
        tree[B].append((A,C))
    visited = [False] * (N + 1)
    ans = 0
    dfs(1, 0)



    print(ans)



main()