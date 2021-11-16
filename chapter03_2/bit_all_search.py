# AtCoder ABC 167 C問題
INF = 10**19
n, m, x = map(int, input().split())
log = [list(map(int, input().split())) for i in range(n)]

ans = INF

for i in range(2**n):
    tmp = [0]*(m+1)

    for j in range(n):
        # 2のn乗までの数 i を変数 j に代入していき、1の位が1のとき、ifを実行
        if i >> j & 1:
            for k in range(m+1):
                tmp[k] = tmp[k]+log[j][k]
        # tmpをチェックして、条件をクリアしていたら価格を比較する
    flag = True

    for l in range(1, m+1):
        if x > tmp[l]:
            flag = False
    if flag == True:
        ans = min(ans, tmp[0])
if ans == INF:
    ans = -1
print(ans)
