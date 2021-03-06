//一般化した二分探索法の基本形
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2 << 8;
int N, K;
vector<int> a(INF), b(INF);

int solve(int N, int K, vector<int> a, vector<int> b)
{
    int min_value = INF;
    sort(b.begin(), b.end());
    for (int i = 0; i < N; ++i)
    {
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

        int val = *iter;

        if (a[i] + val < min_value)
        {
            min_value = a[i] + val;
        }
    }
    cout << min_value << endl;
    return 0;
}

int main()
{
    cout << "Nを入力してください" << endl;
    cin >> N;
    cout << "Kを入力してください" << endl;
    cin >> K;
    cout << "a(N)を入力してください" << endl;
    a.resize(N), b.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    cout << "b(N)を入力してください" << endl;
    for (int i = 0; i < N; ++i)
        cin >> b[i];

    solve(N, K, a, b);
}