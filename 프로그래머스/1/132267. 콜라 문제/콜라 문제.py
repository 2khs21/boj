import sys
sys.setrecursionlimit(1000000)

def solution(a, b, n):
    if n < a:
        return 0
    
    new_coke = (n // a) * b
    next_n = (n % a) + new_coke

    return new_coke + solution(a, b, next_n)

# print(solution(2, 1, 20))
# print(solution(3, 1, 20))