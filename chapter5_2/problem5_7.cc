#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
void chmax(T &a, T b)
{
    if (a < b)
        a = b;
}

const int INF = 1 << 29;

int main()
{
    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    // 文字列 S の最初の i 文字と、文字列 T の最初の j 文字分との間の LCS の長さ

    dp[0][0] = 0;

    for (int i; i <= N; ++i)
    {
        for (int j = 0; j <= M; ++j)
        {
            if (i > 0 && j > 0)
            {
                if (S[i - 1] == T[j - 1])
                {
                    chmax(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                else
                {
                    chmax(dp[i][j], dp[i - 1][j - 1]);
                }
            }
            if (i > 0)
                chmax(dp[i][j], dp[i - 1][j]);
            if (j > 0)
                chmax(dp[i][j], dp[i][j - 1]);
        }
    }
    cout << dp[N][M] << endl;
}