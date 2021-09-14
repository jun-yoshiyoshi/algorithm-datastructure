#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout << "N,K�����" << endl;
    long long N, K;
    cin >> N >> K;
    vector<long long> a(N), b(N);
    cout << "a(N),b(N)�����" << endl;
    for (int i = 0; i < N; ++i)
        cin >> a[i] >> b[i];

    // b �͂��炩���߃\�[�g���Ă���
    sort(b.begin(), b.end());

    // ������
    auto check = [&](long long x) -> bool
    {
        long long cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            cnt += upper_bound(b.begin(), b.end(), x / a[i]) - b.begin();
        }
        return (cnt >= K);
    };

    // �񕪒T�� (right �͏\���傫�Ȓl�ɐݒ�)
    long long left = 0, right = 1LL << 60;
    while (right - left > 1)
    {
        long long mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid;
    }
    cout << right << endl;
}
