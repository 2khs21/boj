import sys
import math
input = sys.stdin.readline

N = int(input())
arr = [int(input()) for _ in range(N)]
arr.sort()

diffs = [arr[i] - arr[i-1] for i in range(1, N)]

g = diffs[0]
for d in diffs[1:]:
    g = math.gcd(g, d)

ans = []
for i in range(2, int(g**0.5) + 1):
    if g % i == 0:
        ans.append(i)
        if i != g // i:
            ans.append(g // i)
            
ans.append(g)

ans.sort()
print(*ans)
