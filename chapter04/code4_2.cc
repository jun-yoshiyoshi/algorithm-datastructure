#include <iostream>
using namespace std;

int func(int N)
{
    cout << "func(" << N << ")���Ăяo���܂���" << endl;
    if (N == 0)
        return 0;

    int result = N + func(N - 1);
    cout << N << "�܂ł̘a��" << result << endl;
    return result;
}

int main()
{
    //���͂��󂯎��
    int N;
    cin >> N;
    cout << func(N) << endl;
}