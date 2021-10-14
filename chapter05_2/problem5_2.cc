#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

template <class T>
void chmax(T &a, T b)
{
    if (a < b)
        a = b;
}

int main()
{
    int N, W;
    cin >> N, W;
    vector<int> w(N);
    for (int i = 0; i < N; ++i)
        cin >> w[i];

    //DP設定
    vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
    //dp[i][j]最初のi個からいくつか選んで総和をjにできるかどうかを表すbool値
    //[0][0]があるのでN+1,W+1になる。
    dp[0][0] = true;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            if (dp[i][j])
                dp[i + 1][j] = true;
            if (j > w[i] && dp[i][j - w[i]])
                dp[i + 1][j] = true;
        }
    }
    if (dp[N][W])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}