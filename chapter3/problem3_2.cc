#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //入力を受け取る
    int N, v;
    cin >> N >> v;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    //線形探索
    int found_id = -1; //初期値は-1など、ありえない値に設定
    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (a[i] == v)
        {
            ++ans;
            found_id = i; //見つかったら添え字を記録
        }
    }
    //結果を出力
    cout << ans << endl;
}