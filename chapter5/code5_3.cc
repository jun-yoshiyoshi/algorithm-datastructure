//pull型
#include <iostream>
#include <vector>
using namespace std;

template <class T>    //テンプレート関数　すべての型に対して同じ操作
void chmin(T &a, T b) //型T　第一引数aのアドレス、型T 第二引数b
{
    if (a > b)
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
    vector<long long> h(N);
    for (int i = 0; i < N; ++i)
        cin >> h[i];
    //配列dpを定義（配列の全てを無限大を表す値に初期化)
    vector<long long> dp(N, INF);
    //初期条件
    dp[0] = 0;
    //ループ
    for (int i = 1; i < N; ++i)
    {
        chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 1]));
        if (i > 1)
        {
            chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    //答え
    cout << dp[N - 1] << endl;
}