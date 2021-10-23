#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int>>;

void search(const Graph &G, int s)
{
    int N = (int)G.size();
    vector<bool> seen(N, false);
    queue<int> todo;

    seen[s] = true;
    todo.push(s);

    while (!todo.empty())
    {
        int v = todo.front();
        todo.pop();

        //for(要素変数の宣言 : 範囲))

        for (int x : G[v])
        {
            if (seen[x])
                continue;

            seen[x] = true;
            todo.push(x);
        }
    }
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
        //無向グラフの場合、以下を追加
        //G[b].push_back(a);
    }

    search(G, 0);
}