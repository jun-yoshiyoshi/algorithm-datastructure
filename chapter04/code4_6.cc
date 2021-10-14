//フィボナッチ数列を求める再帰関数2
#include <iostream>
using namespace std;

int fibo(int N)
{
    //再帰関数を呼び出したことを報告
    cout << "fibo(" << N << ")を呼び出しました" << endl;
    //ベースケース
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;
    //再帰呼び出し
    int result = fibo(N - 1) + fibo(N - 2);
    cout << N << "項目=" << result << endl;
    return result;
}

int main()
{
    //入力を受け取る
    int N;
    cin >> N;
    cout << fibo(N) << endl;
}