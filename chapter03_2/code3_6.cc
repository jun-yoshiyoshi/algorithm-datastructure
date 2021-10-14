#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    bool exist = false;
    for (int bit = 0; bit < (1 << N); ++bit) //N番目のフラグが立っている状態を(1<<N)と表す。
    {
        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            if (bit & (1 << i)) //i番目のフラグが立っている状態を(1<<i) と表す。
            {
                sum += a[i];
            }
        }
        if (sum == W)
            exist = true;
    }
    if (exist)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}