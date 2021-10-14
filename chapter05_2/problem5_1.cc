#include <iostream>
#include <vector>
using namespace std;

template <class T>
void chmax(T &a, T b)
{
    if (a < b)
        a = b;
}

const long long INF = 1LL << 60;

int main()
{
    int N;
    cin >> N;
    vector<vector<long long>> v(N, vector<long long>(3));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> v[i][j];

    vector<vector<long long>> dp(N + 1, vector<long long>(3, 0)); //メモ用テーブル

    for (int i = 0; i < N; ++i)
    {
        for (int j; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (j == k)
                    continue;

                chmax(dp[i + 1][k], dp[i][j] + v[i][k]);
            }
        }
    }
    long long res = 0;
    for (int j = 0; j < 3; ++j)
        chmax(res, dp[N][j]);
    cout << res << endl;
}