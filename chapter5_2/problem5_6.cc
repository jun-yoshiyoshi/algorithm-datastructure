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
    int N, W;
    cin >> N >> W;
    vector<int> a(N), m(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i] >> m[i];

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, INF));
    //利用回数参照テーブル a[i]までの数を用いて jを作るときa[i]はdp[i][j]回利用
    dp[0][0] = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= W; ++j)
        { //i個でjを作れる
            if (dp[i][j] < INF)
                chmin(dp[i + 1][j], 0);
            //i+1までのaをつかってa[i]を m[i]-1個でj-a[i]作れる
            if (j >= a[i] && dp[i + 1][j - a[i]] < m[i])
                chmin(dp[i + 1][j], dp[i + 1][j - a[i]] + 1);
        }
    }

    if (dp[N][W] < INF)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
