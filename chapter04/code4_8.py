def fibo(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    if memo[n] != -1:
        return memo[n]
    else:
        memo[n] = fibo(n-1) + fibo(n-2)
        return memo[n]


n = int(input())

memo = [-1]*n

for i in range(2, n):
    memo[i] = fibo(i)

    print(f"{i}項目{memo[i]}")
