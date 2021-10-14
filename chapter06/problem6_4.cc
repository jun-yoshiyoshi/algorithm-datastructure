#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //。
    cout << "N,Mを入力" << endl;
    long long N, M;
    cin >> N >> M;
    vector<long long> a(N);
    cout << "a(N)を入力" << endl;
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    const long long INF = 2 << 60;
    // 「すべての間隔を x 以上にして M 個の小屋を選べるか？」という判定問題を解く
    // Yes であるような最大の x を求める
    long long left = 0, right = INF;
    while (right - left > 1)
    {
        long long x = (left + right) / 2;

        int cnt = 1;  // 何個の小屋が取れたか (最初の小屋は選ぶ)
        int prev = 0; // 前回の小屋の index
        for (int i = 0; i < N; ++i)
        {
            // x 以上の間隔が空いたら採用する
            if (a[i] - a[prev] >= x)
            {
                ++cnt;
                prev = i;
            }
        }

        // 判定問題が Yes か No か
        if (cnt >= M)
            left = x;
        else
            right = x;
    }
    cout << left << endl;
}
