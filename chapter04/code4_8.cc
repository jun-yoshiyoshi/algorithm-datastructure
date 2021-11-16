//フィボナッチ数列を求める再帰関数とメモ化
#include <iostream>
#include <vector>
using namespace std;

//メモ化する数列
vector<long long> memo;

long long fibo(int N)
{
    //ベースケース
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;
    //メモをチェック
    if (memo[N] != -1)
        return memo[N];
    //答えをメモ化しながら再帰呼び出し
    return memo[N] = fibo(N - 1) + fibo(N - 2);
}

int main()
{
    int N;
    cin >> N;
    //メモ化配列を初期化
    memo.assign(N, -1);

    fibo(N - 1);
    for (int i = 2; i < N; ++i)
    {
        cout << i << "項目" << memo[i] << endl;
    }
}