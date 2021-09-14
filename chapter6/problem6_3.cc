#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //a(N)から４個以下の要素を組み合わせ、ＭかＭに最も近似する最小の総和を求める。
    cout << "N,Mを入力" << endl;
    long long N, M;
    cin >> N >> M;
    vector<long long> a(N);
    cout << "a(N)を入力" << endl;
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    //a(N)に要素０を足す
    a.push_back(0);
    //a[i]とa[j]の和の集合配列Ｓを考える
    vector<long long> S;
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < a.size(); j)
            S.push_back(a[i] + a[j]);
    //Sを小さい順に並び替え
    sort(S.begin(), S.end());

    //候補となる数res
    long long res = 0;
    //Sに含まれる要素を一つずつ
    for (long long i : S)
    {
        //Sの中で M-i「より」大きいイテレータ
        auto L = upper_bound(S.begin(), S.end(), M - i);
        if (L == S.begin())
            continue;
        //デクリメントなぜ？
        --L;
        res = max(res, i + *L);
    }
    cout << res << endl;
}