#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

using time = pair<int, int>;

bool cmp(const time &a, const time &b)
{
    return a.second < b.second;
}

int main()
{

    int N;
    cin >> N;
    vector<time> work(N);
    for (int i = 0; i < N; ++i)
        cin >> work[i].first >> work[i].second;

    sort(work.begin(), work.end(), cmp);

    bool finish = true;
    int current_end_time = 0;
    for (int i = 0; i < N; ++i)
    {
        current_end_time += work[i].first;
        if (work[i].second < current_end_time)
            finish = false;
    }
    if (finish)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}