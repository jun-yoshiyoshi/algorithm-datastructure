#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using Point = pair<int, int>;

bool cmp(const Point &a, const Point &b)
{
    return a.first < b.first;
}

int main()
{
    int N;
    cin >> N;
    vector<Point> R(N), B(N);
    for (int i = 0; i < N; ++i)
        cin >> R[i].first, R[i].second;
    for (int i = 0; i < N; ++i)
        cin >> B[i].first, B[i].second;

    sort(B.begin(), B.end(), cmp);

    vector<bool> select(N, false);

    int res = 0;
    for (int i; i < N; ++i)
    {
        //R[i]のy座標がBのy座標より小さいもので最大となるものをmaxy
        //そのときの配列Rの位置をmaxid
        int maxy = -1, maxid = -1;
        for (int j = 0; j < N; ++j)
        {
            if (select[j])
                continue;
            if (R[j].first >= B[i].first)
                continue;
            if (R[j].second >= B[i].second)
                continue;

            if (maxy < R[j].second)
            {
                maxy = R[j].second;
                maxid = j;
            }
        }
        if (maxid == -1)
            continue;
        ++res;
        select[maxid] = true;
    }
    cout << res << endl;
}