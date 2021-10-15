#include <iostream>
#include <vector>
using namespace std;

void Heap(vector<int> &a, int i, int N)
{
    int child1 = i * 2 + 1;
    if (child1 >= N)
        return;

    if (child1 + 1 < N && a[child1 + 1] > a[child1])
        ++child1;

    if (a[child1] <= a[i])
        return;
    swap(a[i], a[child1]);

    Heap(a, child1, N);
}

void HeapSort(vector<int> &a)
{
    int N = (int)a.size();

    for (int i = N / 2 - 1; i >= 0; --i)
    {
        Heap(a, i, N);
    }
    for (int i = N - 1; i > 0; --i)
    {
        swap(a[0], a[i]);
        Heap(a, 0, i);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    HeapSort(a);
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << ": ";
    }
    cout << endl;
}