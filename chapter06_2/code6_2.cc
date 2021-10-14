//一般化した二分探索法の基本形
#include <iostream>
using namespace std;

bool P(int x) {}

int binary_search()
{
    int l, r;
    while (r - l > 1)
    {
        int mid = l + (r - l) / 2;
        if (P(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}
