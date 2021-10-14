#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10 << 8;
int N, M;
vector<int> a(MAX);

int binary_search(int key)
{
    int l = 0, r = (int)a.size() - 1;
    while (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            r = mid - 1;
        else if (a[mid] < key)
            l = mid + 1;
    }
    return -1;
}

int main()
{
    cin >> N >> M;
    a.resize(M);
    for (int i = 0; i < M; ++i)
        cin >> a[i];

    cout << binary_search(N) << endl;
}