#include <iostream>
#include <vector>
using namespace std;

const vector<int> coin = {500, 100, 50, 10, 5, 1};

int main()
{
    int X;
    cin >> X;
    vector<int> a(6);
    for (int i = 0; i < 6; ++i)
        cin >> a[i];

    int res = 0;
    for (int i = 0; i < 6; ++i)
    {
        int add = X / coin[i];

        if (add > a[i])
            add = a[i];
        X -= coin[i] * add;
        res += add;
    }
    cout << res << endl;
}