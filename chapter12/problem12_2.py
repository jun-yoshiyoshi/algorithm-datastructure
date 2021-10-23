
def solve():
    n, m = map(int, input().split())

    v = [tuple(map(int, input().split())) for _ in range(n)]

    v = sorted(v, key=lambda v: v[0])

    pay = 0

    for i in range(n):
        if m > 0:
            buy = min(m, v[i][1])
            pay += v[i][0]*buy
            m -= buy
    return pay


print(solve())
