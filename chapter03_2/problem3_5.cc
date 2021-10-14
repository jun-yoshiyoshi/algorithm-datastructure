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

    int min_count = INF;
    for (int i = 0; i < N; ++i)
    {
        int count = 0;
        while (a[i] % 2 == 0)
            a[i] /= 2, ++count;
        if (min_count > count)
            min_count = count;
    }
    cout << min_count << endl;
}