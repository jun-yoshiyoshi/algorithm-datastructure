#include <iostream>
#include <vector>
using namespace std;

template <class T>    //テンプレート関数　すべての型に対して同じ操作
void chmin(T &a, T b) //全ての型　第一引数aのアドレス、全ての型 第二引数b
{
    if (a > b)
    {
        a = b;
    }
}
const long long INF = 1LL << 60; //2^60

int main()
{
    //入力
    int N;
    cin >> N;
    vector<vector<long long>> c(N + 1, vector<long long>(N + 1));
    for (int i = 0; i < N + 1; ++i)
    {
        for (int j = 0; j < N + 1; ++j)
        {
            cin >> c[i][j];
        }
    }
    //DPテーブル定義
    vector<long long> dp(N + 1, INF);
    //DP初期条件
    dp[0] = 0;
    //DPループ
    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            chmin(dp[i], dp[j] + c[j][i]);
        }
    }
    //出力
    cout << dp[N] << endl;
}