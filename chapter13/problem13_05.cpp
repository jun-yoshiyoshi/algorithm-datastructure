#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;

//出次数 deg[v]:頂点vを始点とする辺の数
//シンク :出次数が 0である頂点

vector<int> BFS(const Graph &G, vector<int> deg)
{
    vector<int> order;
    int N = (int)G.size();
    queue<int> que;
    for (int i = 0; i < N; ++i)
        if (deg[i] == 0)
            que.push(i);

    while (!que.empty())
    {
        int v = que.front();
        que.pop();

        order.push_back(v);

        for (auto x : G[v])
        {
            --deg[x];
            if (deg[x] == 0)
                que.push(x);
        }
    }
    reverse(order.begin(), order.end());
    return order;
}

int main()
{
    //頂点数 N　辺の数 M
    int N, M;
    cin >> N >> M;

    Graph G(N);
    //出次数を記録する配列
    vector<int> deg(N, 0);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        //逆向きに辺を張る
        G[b].push_back(a);
        //出次数をそれぞれの点について記録
        deg[a]++;
    }

    vector<int> order = BFS(G, deg);

    for (auto v : order)
        cout << v << endl;
}
