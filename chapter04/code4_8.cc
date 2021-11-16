//�t�B�{�i�b�`��������߂�ċA�֐��ƃ�����
#include <iostream>
#include <vector>
using namespace std;

//���������鐔��
vector<long long> memo;

long long fibo(int N)
{
    //�x�[�X�P�[�X
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;
    //�������`�F�b�N
    if (memo[N] != -1)
        return memo[N];
    //���������������Ȃ���ċA�Ăяo��
    return memo[N] = fibo(N - 1) + fibo(N - 2);
}

int main()
{
    int N;
    cin >> N;
    //�������z���������
    memo.assign(N, -1);

    fibo(N - 1);
    for (int i = 2; i < N; ++i)
    {
        cout << i << "����" << memo[i] << endl;
    }
}