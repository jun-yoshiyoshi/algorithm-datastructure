#include <iostream>
using namespace std;

int fibo(int N)
{
    cout << "fibo(" << N << ")���Ăяo���܂���" << endl;
    //�x�[�X�P�[�X
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;
    //�ċA�I�ɓ��������߂ďo��
    int result = fibo(N - 1) + fibo(N - 2);
    cout << N << "���ڂ�" << result << endl;
    return result;
}

int main()
{
    int N;
    cin >> N;

    cout << fibo(N) << endl;
}
