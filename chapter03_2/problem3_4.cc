#include <iostream>
#include <vector>
using namespace std;
const int INF = 100000000;

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    {
        int min = INF;
        int max = -1;
        for (int i = 0; i < N; ++i)
        {
            if (a[i] < min)
                min = a[i];
            if (a[i] > max)
                max = a[i];
        }
        ans = max - min;
    }
    cout << ans << endl;
}