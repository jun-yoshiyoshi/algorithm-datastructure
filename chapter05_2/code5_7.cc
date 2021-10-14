#include <iostream>
#include <vector>
using namespace std;

template <class T>
void chmax(T &a, T b)
{
    if (a < b)
        a = b;
}

int main()
{
    int N;
    long long W;
    cin >> N >> W;
    vector<long long> w(N), v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i] >> w[i];

    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));
    //最大価値参照メモ用テーブル N個まで選ぶとき重量総和 W　i個まで選ぶとき重量総和 j
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            if (j >= w[i])
            {
                chmax(dp[i + 1][j], dp[i][j - w[i]] + v[i]);
            }
            chmax(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << dp[N][W] << endl;
}