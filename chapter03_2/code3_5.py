# bitを使った全探索
from itertools import product


N, W = map(int, input().split())
L = list(map(int, input().split()))

ans = []

for bit in range(1 << N):  # range(1 << N) は range(2 ** N)と同じ
    s = []
    for i in range(N):
        # bitにi番目のフラグが立っているかどうかを調べるときは if(bit & (0 << i))
        if bit & (1 << i):
            s.append(L[i])
    ans.append(s)

print(ans)
