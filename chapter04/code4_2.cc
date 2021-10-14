#include <iostream>
using namespace std;

int func(int N)
{
    cout << "func(" << N << ")‚ðŒÄ‚Ño‚µ‚Ü‚µ‚½" << endl;
    if (N == 0)
        return 0;

    int result = N + func(N - 1);
    cout << N << "‚Ü‚Å‚Ì˜a" << result << endl;
    return result;
}

int main()
{
    //“ü—Í‚ðŽó‚¯Žæ‚é
    int N;
    cin >> N;
    cout << func(N) << endl;
}