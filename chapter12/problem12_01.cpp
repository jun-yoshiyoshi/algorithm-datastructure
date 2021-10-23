#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    auto b = a;

    for (int i = 0; i < N; ++i)
    {
        int index = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        cout << index << ":";
    }
    cout << endl;
}
