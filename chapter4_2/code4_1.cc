#include <iostream>
using namespace std;

int fanc(int N)
{
    if (N == 0)
        return 0;
    return N + fanc(N - 1);
}

int main()
{
    int N;
    cin >> N;

    cout << fanc(N) << endl;
}
