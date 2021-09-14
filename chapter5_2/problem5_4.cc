#include <iostream>
#include <vector>
using namespace std;
const int INF = 1 << 29;
template <class T>
void chmin(T &a, T b)
{
    if (a > b)
        a = b;
}

int main()
{
    int N, k;
    long long W;
    cin >> N >> k >> W;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, INF));
    //組み合わせ数参照用テーブル N個選ぶとき総和 W　i個まで選ぶとき総和 j
    dp[0][0] = 0;
    bool res = false;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            chmin(dp[i + 1][j], dp[i][j]);
            if (j >= a[i])
                chmin(dp[i + 1][j], dp[i][j - a[i]] + 1);
        }
    }

    if (dp[N][W] <= k)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
