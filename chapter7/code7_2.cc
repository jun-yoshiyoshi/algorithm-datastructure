#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//区間 pairについてはググること
using Interval = pair<int, int>;
//区間の終端時間を大小比較する関数　second は pairについてググること
bool cmp(const Interval &a, const Interval &b)
{
    return a.second < b.second;
}

int main()
{
    int N;
    cin >> N;
    vector<Interval> inter(N);
    for (int i = 0; i < N; ++i)
        cin >> inter[i].first >> inter[i].second;

    //終了時間でソート
    sort(inter.begin(), inter.end(), cmp);

    int res = 0;
    int current_end_time = 0;
    for (int i = 0; i < N; ++i)
    {
        //最後に選んだ区間と重なる場合は除く
        if (inter[i].first < current_end_time)
            continue;
        ++res;
        current_end_time = inter[i].second;
    }

    cout << res << endl;
}