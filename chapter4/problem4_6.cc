#include <iostream>
#include <vector>
using namespace std;

//func(i,w,a)をメモ化する配列
vector<vector<int>> memo;

bool func(int n, int w, const vector<int> &a)
{
    //ベースケース
    if (n == 0)
    {
        if (w == 0)
            return true;
        else
            return false;
    }
    //メモ(キャッシュ)をチェック
    if (memo[n][w] != -1)
        return memo[n][w];
    //a[i-1]を選ばない場合
    if (func(n - 1, w, a))
        return memo[n][w] = 1;
    //a[i-1]を選ぶ場合
    if (func(n - 1, w - a[n - 1], a))
        return memo[n][w] = 1;

    //どちらもfalseの場合はfalse
    return memo[n][w] = 0;
}

int main()
{
    //入力
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    //メモ化配列を-1で初期化する
    memo.assign(N + 1, vector<int>(W + 1, -1));
    //再帰的に解く
    if (func(N, W, a))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}