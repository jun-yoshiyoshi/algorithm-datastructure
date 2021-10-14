#include <iostream>
using namespace std;

int fibo(int N)
{
    cout << "fibo(" << N << ")を呼び出しました" << endl;
    //ベースケース
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;
    //再帰的に答えを求めて出力
    int result = fibo(N - 1) + fibo(N - 2);
    cout << N << "項目は" << result << endl;
    return result;
}

int main()
{
    int N;
    cin >> N;

    cout << fibo(N) << endl;
}
