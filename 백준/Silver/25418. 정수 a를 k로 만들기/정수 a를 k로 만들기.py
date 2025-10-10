def solve():
    A, K = map(int, input().split())
    cnt = 0
    current = K
    while current > A:
        # 짝수이고 나눴을 때 여전히 >= A 라면 나누기
        if current % 2 == 0 and current // 2 >= A:
            current //= 2
        else:
            current -= 1
        cnt += 1
    print(cnt)

if __name__ == "__main__":
    solve()