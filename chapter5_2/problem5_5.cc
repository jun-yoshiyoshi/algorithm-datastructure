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
    int N;
    long long W;
    cin >> N >> W;
    vector<long long> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    vector<vector<bool>> dp(N + 1, vector<bool>(W + 1, false));
    //組み合わせ数参照用テーブル N個選ぶとき総和 W　i個まで選ぶとき総和 j
    dp[0][0] = true;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            if (dp[i][j])
                dp[i + 1][j] = true;

            if (j >= a[i] && dp[i + 1][j - a[i]])
                dp[i + 1][j] = true;
        }
    }

    if (dp[N][W])
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
