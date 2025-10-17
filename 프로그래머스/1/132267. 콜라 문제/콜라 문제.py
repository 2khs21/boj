def solution(a, b, n):
    total = 0
    while n >= a:
        exchanged = (n // a) * b
        total += exchanged
        n = (n % a) + exchanged
    return total

# print(solution(3, 1, 20))