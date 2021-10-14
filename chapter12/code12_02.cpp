#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int> &a, int left, int right)
{
    if (right - left == 1)
        return;
    int mid = left + (right - left) / 2;

    MergeSort(a, left, mid);

    MergeSort(a, mid, right);

    vector<int> buf;
    for (int i = left; i < mid; ++i)
        buf.push_back(a[i]);
    for (int i = right - 1; i >= mid; --i)
        buf.push_back(a[i]);

    int index_l = 0;
    int index_r = (int)buf.size() - 1;
    for (int i = left; i < right; ++i)
    {
        if (buf[index_l] <= buf[index_r])
        {
            a[i] = buf[index_l++];
        }
        else
        {
            a[i] = buf[index_r--];
        }
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    MergeSort(a, 0, N);
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << ": ";
    }
    cout << endl;
}