import sys
input = sys.stdin.readline

N = int(input())
cost = [list(map(int, input().split())) for _ in range(N)]
state_str = input().strip()
P = int(input())

# 초기 상태 bitmask
state = 0
for i, ch in enumerate(state_str):
    if ch == 'Y':
        state |= (1 << i)

INF = int(1e9)
dp = [INF] * (1 << N)
dp[state] = 0

for s in range(1 << N): # 모든 상태 보기 시도.
    if dp[s] == INF: # s 상태가 불가능한 경우 스킵
        continue    
    cnt = bin(s).count('1') # 켜진 발전소 수
    if cnt >= P:
        continue
    for i in range(N): # 발전소 i
        if not (s & (1 << i)): # 꺼져있으면 continue
            continue
        # 꺼진 발전소 j를 켬 
        for j in range(N): # 다른 발전소 중에
            if s & (1 << j): # 발전소 j가 이미 켜져있으면 건너뜀
                continue
            ns = s | (1 << j) # 발전소 j 켠 새로운 상태
            dp[ns] = min(dp[ns], dp[s] + cost[i][j]) # min(이전값, 현재값 , cost[i][j])

# 목표 발전소 수 이상인 최소 비용
res = INF
for s in range(1 << N):
    if bin(s).count('1') >= P:
        res = min(res, dp[s])

print(res if res != INF else -1)