#include <iostream>
using namespace std;

int main()
{
    cout << "Start" << endl;
    //候補区間
    int left, right;
    left = 0, right = 100;

    while (right - left > 1)
    {
        int mid = left + (right - left) / 2;
        cout << "is your age less than" << mid << "?(yes/no)" << endl;
        string ans;
        cin >> ans;

        if (ans == "yes")
            right = mid;
        else
            left = mid;
    }
    cout << "your age is" << left << "!" << endl;
}