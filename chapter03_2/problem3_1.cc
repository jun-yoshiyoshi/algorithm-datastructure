#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, v;
    cin >> N >> v;
    int ans = -1;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];

        for (int i = 0; i < N; ++i)
        {
            if (a[i] == v)
            {
                ans = i;
            }
        }
    }
    cout << ans << endl;
}