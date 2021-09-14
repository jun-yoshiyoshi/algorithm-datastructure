//任意の一回だけの更新に着目して関数を作ると

long long rec(int i)
{
    if (i == 0)
        return 0;

    long long res = INF;

    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

    if (i > 1)
        chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));
    return res;
}
