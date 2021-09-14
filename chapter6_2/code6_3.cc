//N‚ğ“ñ•ª’Tõ‚·‚é
#include <iostream>
using namespace std;

int L, R;
const int N = 37;

bool P(int x)
{
    if (x >= N)
        return true;
    else
        return false;
}

int binary_search(int left, int right)
{
    int l = left, r = right;

    while (r - l > 1)
    {
        int mid = l + (r - l) / 2;
        if (P(mid))
            r = mid;
        else
            l = mid;
        cout << l << " " << r << endl;
    }
    return r;
}

int main()
{
    cout << "‰ºŒÀ’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
    cin >> L;
    cout << "ãŒÀ’l‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
    cin >> R;
    cout << binary_search(L, R) << endl;
}