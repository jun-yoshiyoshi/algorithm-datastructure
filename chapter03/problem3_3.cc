//未解決
#include <iostream>
#include <vector>
using namespace std;
const int INF = 20000000; //十分に大きな値

int main()
{
    //入力を受け取る
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    //線形探索
    int min_value = INF;
    int sec_value = 0;
    int s = 0 for (int i = 0; i < N; ++i)
    {
        if (a[i] < min_value)
            sec_value = min_value;
        if (a[i] < min_value)
            min_value = a[i];
    }
    //結果出力

    cout << min_value << sec_value << endl;
}