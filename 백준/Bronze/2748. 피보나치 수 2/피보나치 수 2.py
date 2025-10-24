memo = [0] * 100001

def fib(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    elif memo[n] != 0:
        return memo[n]
    memo[n] = fib(n-1) + fib(n-2)
    return memo[n]

n = int(input())
print(fib(n))