//ユークリッド互除法
#include <iostream>
using namespace std;

int GCD(int m, int n)
{
    //ベースケース
    if (n == 0)
        return m;
    //再帰呼び出し
    return GCD(n, m % n);
}

int main()
{
    int m;
    int n;
    cin >> m >> n;
    cout << GCD(m, n) << endl;
}