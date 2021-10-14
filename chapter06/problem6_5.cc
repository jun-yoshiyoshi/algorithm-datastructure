#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout << "N,Kを入力" << endl;
    long long N, K;
    cin >> N >> K;
    vector<long long> a(N), b(N);
    cout << "a(N),b(N)を入力" << endl;
    for (int i = 0; i < N; ++i)
        cin >> a[i] >> b[i];

    // b はあらかじめソートしておく
    sort(b.begin(), b.end());

    // 判定問題
    auto check = [&](long long x) -> bool
    {
        long long cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            cnt += upper_bound(b.begin(), b.end(), x / a[i]) - b.begin();
        }
        return (cnt >= K);
    };

    // 二分探索 (right は十分大きな値に設定)
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
