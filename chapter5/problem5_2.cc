#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //入力
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    //DPテーブル定義
    vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
    //DPループ
    dp[0][0] = true;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            //a[i]を選ばない場合
            if (dp[i][j])
                dp[i + 1][j] = true;
            //a[i]を選ぶ場合
            if (j >= a[i] && dp[i][j - a[i]])
                dp[i + 1][j] = true;
        }
    }
    //出力
    if (dp[N][W])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}