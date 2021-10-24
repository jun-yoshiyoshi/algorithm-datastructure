//始点sから終点tの経路が存在するかの判定問題をDFSで

#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;
vector<bool> seen;

void dfs(const Graph &G, int v)
{
    seen[v] = true;

    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;
        dfs(G, next_v);
    }
}

int main()
{
    //頂点数 N　辺の数 M
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        //有向グラフ
    }
    //seenを初期化
    seen.assign(N, false);
    dfs(G, s);

    if (seen[t])
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
