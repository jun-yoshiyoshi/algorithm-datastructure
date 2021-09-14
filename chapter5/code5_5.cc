//再帰関数を用いる単純な全探索
#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60;

template <class T>   //テンプレート関数　すべての型に対して同じ操作
void chmin(T a, T b) //型T　第一引数a、型T 第二引数b
{
    if (a > b)
    {
        a = b;
    }
}

int main()
{
    //入力
    int N;
    cin >> N;
    vector<long long> h(N);
    int res = 0;

    long long rec(int i)
    {
        //足場０のコストは０
        if (i == 0)
            return 0;

        //答えを格納する変数をINFに初期化する
        long long res = INF;

        //頂点i-1から来た場合
        chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

        //頂点i-2から来た場合
        if (i > 1)
            chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));

        //答えを返す
        return res;
    }
    cout << rec(N) << endl;
}