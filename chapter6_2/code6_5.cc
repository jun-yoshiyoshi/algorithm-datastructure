#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 10;
int N;
vector<long long> H(INF), S(INF);

int solve(int N, vector<long long> H, vector<long long> S)
{
    long long l = 0, r = INF;
    while (r - l > 1)
    {
        long long mid = (l + r) / 2;
        vector<long long> t(N, -1);
        bool time_over = false;
        for (int i = 0; i < N; ++i)
        {
            if (mid >= H[i])
                t[i] = (mid - H[i]) / S[i];
            else
                time_over = true;
        }

        sort(t.begin(), t.end());
        for (int i = 0; i < N; ++i)
        {
            if (t[i] < i)
                time_over = true;
        }

        if (time_over)
            l = mid;
        else
            r = mid;
    }
    return r;
}

int main()
{
    cout << "N‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
    cin >> N;
    H.resize(N), S.resize(N);
    cout << "H(N)‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
    for (int i = 0; i < N; ++i)
        cin >> H[i];
    cout << "S(N)‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
    for (int i = 0; i < N; ++i)
        cin >> S[i];

    cout << solve(N, H, S) << endl;
}