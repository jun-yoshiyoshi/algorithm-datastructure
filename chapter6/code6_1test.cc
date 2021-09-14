#include <iostream>
#include <vector>
using namespace std;

int binary_search(int key, vector<int> a)
{
    int left = 0, right = (int)a.size() - 1;
    while (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            right = mid - 1;
        else if (a[mid] < key)
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int N, key;
    cin >> N >> key;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    cout << binary_search(key, a) << endl;
}