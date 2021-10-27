//トポロジカルソートの実装
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> order; //トポロジカルソートの順序を記録

//トポロジカルソートする関数
void rec(const Graph &G, int v)
{
    seen[v] = true;
    //Gの中からvを先頭に持つベクターの要素を全てループ (next_v_test.cpp参照)
    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;
        rec(G, next_v);
    }
    order.push_back(v);
}

int main()
{
    //頂点数 N　辺の数 M
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    seen.assign(N, false);
    order.clear();
    for (int v = 0; v < N; ++v)
    {
        if (seen[v])
            continue;
        rec(G, v);
    }
    reverse(order.begin(), order.end());

    for (auto v : order)
        cout << v << "->";
    cout << endl;
}

// 8 12
// 0 5
// 1 3
// 1 6
// 2 5
// 2 7
// 3 0
// 3 7
// 4 1
// 4 2
// 4 6
// 6 7
// 7 0
