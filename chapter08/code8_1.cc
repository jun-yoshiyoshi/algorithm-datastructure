#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    cout << a[0] << endl;
    cout << a[2] << endl;
    cout << a[4] << endl;
    a[2] = -1;
    cout << a[2] << endl;
}