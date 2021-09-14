//座標圧縮
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int order(int N, vector<int> a)
{
    auto b = a;
    sort(b.begin(), b.end());

    //resは各aについてbの中で何番目かを表す
    vector<int> res(N);
    for (int i = 0; i < N; ++i)
    {
        res[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    for_each(res.begin(), res.end(),
             [](const int &n)
             { cout << n << ";"; });
    cout << endl;
    return 0;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    order(N, a);
}