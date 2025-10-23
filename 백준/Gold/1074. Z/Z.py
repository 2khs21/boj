def solution(N, r, c):
    if N == 0:
        return 0

    half = 2 ** (N - 1)
    area = 0

    if r < half and c < half:
        area = 0
    elif r < half and c >= half:
        area = 1
        c -= half
    elif r >= half and c < half:
        area = 2
        r -= half
    else:
        area = 3
        r -= half
        c -= half

    return area * (half ** 2) + solution(N - 1, r, c)


N, r, c = map(int, input().split())
print(solution(N, r, c))