MOD = 10 ** 9 + 7
def factorial(n):
	res = 1
	for i in range(2, n+1):
		res = res * i % MOD
	return res

def modpow(x, e):
	if e == 0:
		return 1
	half = modpow(x, e//2)
	return half * half * (x if e % 2 else 1) % MOD

n, k = map(int,input().split())

top = factorial(n)
bottom = factorial(n - k) * factorial(k) % MOD
inv = modpow(bottom, MOD - 2)
ans = top * inv % MOD
print (ans)



