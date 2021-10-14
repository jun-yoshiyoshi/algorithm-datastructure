//メモ化再帰関数を用いる全探索
#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

template <class T>    //テンプレート関数　すべての型に対して同じ操作
void chmin(T &a, T b) //型T　第一引数aのアドレス、型T 第二引数b
{
    if (a > b)
    {
        a = b;
    }
}

int N;
vector<long long> h;
vector<long long> dp;

long long rec(int i)
{
    //DPの値が更新されていたらそのままリターン
    if (dp[i] < INF)
        return dp[i];
    //ベースケース
    if (i == 0)
        return 0;
    //答えの初期値
    long long res = INF;
    //i-1から来た場合
    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));
    //i-2から来た場合
    if (i > 1)
        chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));
    //結果をメモ化しながら返す
    return dp[i] = res;
}

int main()
{
    //入力
    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> h[i];

    dp.assign(N, INF);

    cout << rec(N - 1) << endl;
}