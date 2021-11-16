//////////////////////////////////////////////////////
//bitの表す部分集合にi番目の要素が含まれる場合
//1<<iは右からi桁目のみが1である二進数の値を表す。
//if (bit & (1 << i))
//{
//}

//含まれない場合
//else
//{
//}
/////////////////////////////////////////////////////////
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    //N個の中からいくつか選んで W になる組み合わせは何通りあるか
    int N, W;
    cin >> N >> W;
    vector<int> A(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int ans = 0;

    for (int bit = 0; bit < (1 << N); ++bit)
    {
        int S = 0;
        for (int i = 0; i < N; ++i)
        {
            if (bit & (1 << i))
            {
                S += A[i];
            }
        }
        if (S == W)
        {
            ans++;
        }
    }
