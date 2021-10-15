#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int> &a, int l, int r)
{
    if (r - l <= 1)
        return;

    int pivot_idx = (l + r) / 2;
    int pivot = a[pivot_idx];
    swap(a[pivot_idx], a[r - 1]);

    int i = l;
    for (int j = l; j < r - 1; ++j)
    {
        if (a[j] < pivot)
        {
            swap(a[i++], a[j]);
        }
    }
    swap(a[i], a[r - 1]);

    QuickSort(a, l, i);
    QuickSort(a, i + 1, r);
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    QuickSort(a, 0, N);
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << ": ";
    }
    cout << endl;
}