#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2000000;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    for (int i = 0; i < N; ++i)
        cin >> b[i];
    int min_value = INF;

    sort(b.begin(), b.end());

    for (int i = 0; i < N; ++i)
    {
        //ベクターbの中で K-a[i]以上のイテレータ
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);
        //イテレータの示す値を取り出す
        int val = *iter;
        //min_valueと比較する
        if (a[i] + val < min_value)
        {
            min_value = a[i] + val;
        }
    }
    cout << min_value << endl;
}