#include <iostream>
using namespace std;

int GCD(int m, int n)
{
    if (n == 0)
        return m;
    return GCD(n, m % n);
}

int main()
{
    int M, N;
    cin >> M >> N;

    cout << GCD(M, N) << endl;
}
