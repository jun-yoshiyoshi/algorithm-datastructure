#include <iostream>
#include <vector>
using namespace std;

template <class T>    //テンプレート関数　すべての型に対して同じ操作
void chmax(T &a, T b) //型T　第一引数aのアドレス、型T 第二引数b
{
    if (a < b)
    {
        a = b;
    }
}

const long long INF = 1LL << 60;

int main()
{
    //入力
    int N;
    cin >> N;
    vector<vector<long long>> a(N, vector<long long>(3));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
    //DPテーブル定義
    vector<vector<long long>> dp(N + 1, vector<long long>(3, 0));
    //DPループ
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (j == k)
                    continue;
                chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
            }
        }
    }
    long long res = 0;
    for (int j = 0; j < 3; ++j)
        chmax(res, dp[N][j]);
    //出力
    cout << res << endl;
}