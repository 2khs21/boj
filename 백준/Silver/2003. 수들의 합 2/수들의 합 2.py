def main():
    n, m = map(int, input().split())
    arr = list(map(int, input().split()))
    ans = 0
    for i in range(n):
            add = 0
            for j in range(i, n):
                  add += arr[j]
                  if (add == m):
                        ans += 1
                  if (add >= m):
                        break
    print(ans)
                  
main()