//フィボナッチ数列を求める再帰関数
#include <iostream>
using namespace std;

int fibo(int N)
{
    //ベースケース
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;
    //再帰呼び出し
    return fibo(N - 1) + fibo(N - 2);
}

int main()
{
    //入力を受け取る
    int N;
    cin >> N;
    cout << fibo(N) << endl;
}