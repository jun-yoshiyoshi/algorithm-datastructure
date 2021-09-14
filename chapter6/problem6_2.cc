#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    cout << "N‚ð“ü—Í" << endl;
    int N;
    cin >> N;
    vector<int> a(N), b(N), c(N);
    cout << "a(N)‚ð“ü—Í" << endl;
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    cout << "b(N)‚ð“ü—Í" << endl;
    for (int i = 0; i < N; ++i)
        cin >> b[i];
    cout << "c(N)‚ð“ü—Í" << endl;
    for (int i = 0; i < N; ++i)
        cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long res = 0;
    for (int i = 0; i < N; ++i)
    {
        long long Ai = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        long long Ci = N - (upper_bound(c.begin(), c.end(), b[i]) - c.begin());
        res += Ai * Ci;
    }
    cout << res << endl;
}