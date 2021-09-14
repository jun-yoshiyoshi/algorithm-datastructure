#include <iostream>
#include <string>
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
const int INF = 1 << 29; //2^29

int main()
{
    //入力
    string S, T;
    cin >> S >> T;
    //DPテーブル定義
    vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, INF));
    //DP初期条件
    dp[0][0] = 0;
    //DPループ
    for (int i = 0; i <= S.size(); ++i)
    {
        for (int j = 0; j <= T.size(); ++j)
        {
            //変換操作
            if (i > 0 && j > 0)
            {
                if (S[i - 1] == T[j - 1])
                {
                    chmin(dp[i][j], dp[i - 1][j - 1]);
                }
                else
                {
                    chmin(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
            //削除操作
            if (i > 0)
                chmin(dp[i][j], dp[i - 1][j] + 1);

            //挿入操作
            if (j > 0)
                chmin(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    //出力
    cout << dp[S.size()][T.size()] << endl;
}